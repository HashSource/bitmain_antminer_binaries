
void * OBJ_bsearch_ex_(void *key,void *base,int num,int size,cmp *cmp,int flags)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  
  if (num != 0) {
    if (num < 1) {
      if ((flags & 2U) == 0) {
        return (void *)0x0;
      }
      return base;
    }
    iVar4 = 0;
    do {
      while( true ) {
        iVar2 = iVar4 + num >> 1;
        pvVar3 = (void *)(size * iVar2 + (int)base);
        iVar1 = (*cmp)(key,pvVar3);
        if (-1 < iVar1) break;
        num = iVar2;
        if (iVar2 <= iVar4) goto LAB_0008ccda;
      }
      iVar4 = iVar2 + 1;
      if (iVar1 == 0) goto LAB_0008ccec;
    } while (iVar4 < num);
LAB_0008ccda:
    if (iVar1 == 0) {
LAB_0008ccec:
      if (-1 < flags << 0x1e) {
        return pvVar3;
      }
      if (iVar2 == 0) {
        return pvVar3;
      }
      pvVar3 = (void *)(size * (iVar2 + -1) + (int)base);
      do {
        iVar4 = (*cmp)(key,pvVar3);
        if (iVar4 != 0) {
          return (void *)(size * iVar2 + (int)base);
        }
        iVar2 = iVar2 + -1;
        pvVar3 = (void *)((int)pvVar3 - size);
      } while (iVar2 != 0);
      return base;
    }
    if (flags << 0x1f < 0) {
      return pvVar3;
    }
  }
  return (void *)0x0;
}


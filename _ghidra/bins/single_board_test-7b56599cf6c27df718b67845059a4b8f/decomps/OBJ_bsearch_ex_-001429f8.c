
void * OBJ_bsearch_ex_(void *key,void *base,int num,int size,cmp *cmp,int flags)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if (num == 0) {
    return (void *)0x0;
  }
  if (num < 1) {
    pvVar4 = (void *)(flags & 2U);
    if ((void *)(flags & 2U) != (void *)0x0) {
      pvVar4 = base;
    }
  }
  else {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = (num + iVar3) / 2;
        pvVar4 = (void *)(size * iVar2 + (int)base);
        iVar1 = (*cmp)(key,pvVar4);
        if (-1 < iVar1) break;
        num = iVar2;
        if (iVar2 <= iVar3) goto LAB_00142a3a;
      }
      if (iVar1 == 0) goto LAB_00142a48;
      iVar3 = iVar2 + 1;
    } while (iVar3 < num);
LAB_00142a3a:
    if (iVar1 == 0) {
LAB_00142a48:
      if ((flags << 0x1e < 0) && (0 < iVar2)) {
        iVar3 = iVar2 + -1;
        pvVar4 = (void *)(size * (iVar2 + -1) + (int)base);
        while( true ) {
          iVar1 = (*cmp)(key,pvVar4);
          if (iVar1 != 0) {
            return (void *)(iVar2 * size + (int)base);
          }
          if (iVar3 == 0) break;
          iVar2 = iVar3;
          iVar3 = iVar3 + -1;
          pvVar4 = (void *)((int)pvVar4 - size);
        }
      }
    }
    else if (-1 < flags << 0x1f) {
      return (void *)0x0;
    }
  }
  return pvVar4;
}


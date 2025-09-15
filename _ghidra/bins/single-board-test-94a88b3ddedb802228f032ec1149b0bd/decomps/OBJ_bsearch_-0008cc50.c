
void * OBJ_bsearch_(void *key,void *base,int num,int size,cmp *cmp)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  if ((num != 0) && (0 < num)) {
    iVar3 = 0;
    do {
      while( true ) {
        iVar2 = (iVar3 + num) / 2;
        pvVar4 = (void *)(iVar2 * size + (int)base);
        iVar1 = (*cmp)(key,pvVar4);
        if (-1 < iVar1) break;
        num = iVar2;
        if (iVar2 <= iVar3) goto LAB_0008cc8e;
      }
      iVar3 = iVar2 + 1;
      if (iVar1 == 0) {
        return pvVar4;
      }
    } while (iVar3 < num);
LAB_0008cc8e:
    if (iVar1 == 0) {
      return pvVar4;
    }
  }
  return (void *)0x0;
}


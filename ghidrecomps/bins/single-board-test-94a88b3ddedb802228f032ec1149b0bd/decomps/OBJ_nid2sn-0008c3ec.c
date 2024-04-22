
char * OBJ_nid2sn(int n)

{
  void *pvVar1;
  int iVar2;
  undefined4 local_28;
  undefined *local_24;
  undefined auStack_20 [8];
  int local_18;
  
  if ((uint)n < 0x3be) {
    iVar2 = n;
    if ((n == 0) || (iVar2 = n * 2, *(int *)(DAT_0008c454 + n * 0x18 + 8) != 0)) {
      return *(char **)(DAT_0008c454 + (iVar2 + n) * 8);
    }
    iVar2 = 0x15b;
  }
  else {
    if (*(_LHASH **)(DAT_0008c458 + 4) == (_LHASH *)0x0) {
      return (char *)0x0;
    }
    local_24 = auStack_20;
    local_28 = 3;
    local_18 = n;
    pvVar1 = lh_retrieve(*(_LHASH **)(DAT_0008c458 + 4),&local_28);
    if (pvVar1 != (void *)0x0) {
      return **(char ***)((int)pvVar1 + 4);
    }
    iVar2 = 0x169;
  }
  ERR_put_error(8,0x68,0x65,DAT_0008c45c,iVar2);
  return (char *)0x0;
}


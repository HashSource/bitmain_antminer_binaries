
char * OBJ_nid2ln(int n)

{
  void *pvVar1;
  int iVar2;
  undefined4 local_28;
  undefined *local_24;
  undefined auStack_20 [8];
  int local_18;
  
  if ((uint)n < 0x3be) {
    iVar2 = n;
    if ((n == 0) || (iVar2 = n * 2, *(int *)(DAT_0008c4cc + n * 0x18 + 8) != 0)) {
      return *(char **)(DAT_0008c4cc + (iVar2 + n) * 8 + 4);
    }
    iVar2 = 0x176;
  }
  else {
    if (*(_LHASH **)(DAT_0008c4d0 + 4) == (_LHASH *)0x0) {
      return (char *)0x0;
    }
    local_24 = auStack_20;
    local_28 = 3;
    local_18 = n;
    pvVar1 = lh_retrieve(*(_LHASH **)(DAT_0008c4d0 + 4),&local_28);
    if (pvVar1 != (void *)0x0) {
      return *(char **)(*(int *)((int)pvVar1 + 4) + 4);
    }
    iVar2 = 0x184;
  }
  ERR_put_error(8,0x66,0x65,DAT_0008c4d4,iVar2);
  return (char *)0x0;
}



ASN1_OBJECT * OBJ_nid2obj(int n)

{
  int iVar1;
  void *pvVar2;
  undefined4 local_28;
  undefined *local_24;
  undefined auStack_20 [8];
  int local_18;
  
  if ((uint)n < 0x3be) {
    iVar1 = n;
    if ((n == 0) || (iVar1 = n * 2, *(int *)(DAT_0008c3e0 + n * 0x18 + 8) != 0)) {
      return (ASN1_OBJECT *)(DAT_0008c3e0 + (iVar1 + n) * 8);
    }
    iVar1 = 0x140;
  }
  else {
    if (*(_LHASH **)(DAT_0008c3e4 + 4) == (_LHASH *)0x0) {
      return (ASN1_OBJECT *)0x0;
    }
    local_24 = auStack_20;
    local_28 = 3;
    local_18 = n;
    pvVar2 = lh_retrieve(*(_LHASH **)(DAT_0008c3e4 + 4),&local_28);
    if (pvVar2 != (void *)0x0) {
      return *(ASN1_OBJECT **)((int)pvVar2 + 4);
    }
    iVar1 = 0x14e;
  }
  ERR_put_error(8,0x67,0x65,DAT_0008c3e8,iVar1);
  return (ASN1_OBJECT *)0x0;
}


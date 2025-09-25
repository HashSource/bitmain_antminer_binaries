
ASN1_OBJECT * OBJ_nid2obj(int n)

{
  int iVar1;
  undefined4 local_28;
  undefined1 *local_24;
  undefined1 auStack_20 [8];
  int local_18;
  
  if ((uint)n < 0x4ab) {
    iVar1 = n;
    if ((n == 0) || (iVar1 = n * 2, *(int *)(&DAT_0025c14c + n * 0x18) != 0)) {
      return (ASN1_OBJECT *)(&nid_objs + (n + iVar1) * 8);
    }
    iVar1 = 0xe3;
  }
  else if (added == 0) {
    iVar1 = 0xe8;
  }
  else {
    local_24 = auStack_20;
    local_28 = 3;
    local_18 = n;
    iVar1 = OPENSSL_LH_retrieve(added,&local_28);
    if (iVar1 != 0) {
      return *(ASN1_OBJECT **)(iVar1 + 4);
    }
    iVar1 = 0xf2;
  }
  ERR_put_error(8,0x67,0x65,"crypto/objects/obj_dat.c",iVar1);
  return (ASN1_OBJECT *)0x0;
}


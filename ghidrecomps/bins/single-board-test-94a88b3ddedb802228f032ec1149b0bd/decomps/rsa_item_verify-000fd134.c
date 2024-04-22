
undefined4
rsa_item_verify(undefined4 param_1,undefined4 param_2,undefined4 param_3,ASN1_OBJECT **param_4,
               undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = OBJ_obj2nid(*param_4);
  if (iVar1 == 0x390) {
    iVar1 = rsa_pss_to_ctx(param_1,0,param_4,param_6);
    if (iVar1 < 1) {
      uVar2 = 0xffffffff;
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    ERR_put_error(4,0x9c,0x9b,DAT_000fd17c,0x2ba);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


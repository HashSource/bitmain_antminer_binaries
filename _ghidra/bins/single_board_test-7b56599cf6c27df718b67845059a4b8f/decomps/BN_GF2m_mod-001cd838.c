
undefined4 BN_GF2m_mod(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [24];
  
  iVar1 = BN_GF2m_poly2arr(param_3,auStack_28,6);
  if (iVar1 == 0 || 6 < iVar1) {
    ERR_put_error(3,0x83,0x6a,"crypto/bn/bn_gf2m.c",0x18e);
    return 0;
  }
  uVar2 = BN_GF2m_mod_arr(param_1,param_2,auStack_28);
  return uVar2;
}


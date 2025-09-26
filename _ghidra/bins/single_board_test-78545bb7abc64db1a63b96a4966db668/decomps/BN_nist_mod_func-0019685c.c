
undefined4 BN_nist_mod_func(BIGNUM *param_1)

{
  int iVar1;
  
  iVar1 = BN_ucmp((BIGNUM *)&_bignum_nist_p_192,param_1);
  if (iVar1 == 0) {
    return 0x195ae9;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_224,param_1);
  if (iVar1 == 0) {
    return 0x195cf1;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_256,param_1);
  if (iVar1 == 0) {
    return 0x195ea1;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_384,param_1);
  if (iVar1 == 0) {
    return 0x196209;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_521,param_1);
  if (iVar1 == 0) {
    return 0x1965f1;
  }
  return 0;
}



undefined4 BN_nist_mod_func(BIGNUM *param_1)

{
  int iVar1;
  
  iVar1 = BN_ucmp((BIGNUM *)&_bignum_nist_p_192,param_1);
  if (iVar1 == 0) {
    return 0x187cc1;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_224,param_1);
  if (iVar1 == 0) {
    return 0x187ec9;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_256,param_1);
  if (iVar1 == 0) {
    return 0x188079;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_384,param_1);
  if (iVar1 == 0) {
    return 0x1883e1;
  }
  iVar1 = BN_ucmp((BIGNUM *)_bignum_nist_p_521,param_1);
  if (iVar1 == 0) {
    return 0x1887c9;
  }
  return 0;
}


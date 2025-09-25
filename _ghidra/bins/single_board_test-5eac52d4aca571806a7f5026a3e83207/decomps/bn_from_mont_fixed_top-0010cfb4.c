
undefined4
bn_from_mont_fixed_top(undefined4 param_1,BIGNUM *param_2,undefined4 param_3,BN_CTX *param_4)

{
  BIGNUM *a;
  BIGNUM *pBVar1;
  undefined4 uVar2;
  
  BN_CTX_start(param_4);
  a = BN_CTX_get(param_4);
  if ((a != (BIGNUM *)0x0) && (pBVar1 = BN_copy(a,param_2), pBVar1 != (BIGNUM *)0x0)) {
    uVar2 = bn_from_montgomery_word(param_1,a,param_3);
    BN_CTX_end(param_4);
    return uVar2;
  }
  BN_CTX_end(param_4);
  return 0;
}


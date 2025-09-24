
undefined4 ec_GF2m_simple_point_init(int param_1)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 8) = pBVar1;
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0xc) = pBVar1;
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0x10) = pBVar1;
  if ((*(BIGNUM **)(param_1 + 8) != (BIGNUM *)0x0) &&
     (pBVar1 != (BIGNUM *)0x0 && *(int *)(param_1 + 0xc) != 0)) {
    return 1;
  }
  BN_free(*(BIGNUM **)(param_1 + 8));
  BN_free(*(BIGNUM **)(param_1 + 0xc));
  BN_free(*(BIGNUM **)(param_1 + 0x10));
  return 0;
}


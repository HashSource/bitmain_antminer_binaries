
undefined4 ec_GFp_simple_group_init(int param_1)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0x28) = pBVar1;
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0x44) = pBVar1;
  pBVar1 = BN_new();
  *(BIGNUM **)(param_1 + 0x48) = pBVar1;
  if ((*(BIGNUM **)(param_1 + 0x28) != (BIGNUM *)0x0) &&
     (pBVar1 != (BIGNUM *)0x0 && *(int *)(param_1 + 0x44) != 0)) {
    *(undefined4 *)(param_1 + 0x4c) = 0;
    return 1;
  }
  BN_free(*(BIGNUM **)(param_1 + 0x28));
  BN_free(*(BIGNUM **)(param_1 + 0x44));
  BN_free(*(BIGNUM **)(param_1 + 0x48));
  return 0;
}


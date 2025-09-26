
undefined4 ec_GFp_simple_group_copy(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  
  pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x28),*(BIGNUM **)(param_2 + 0x28));
  if (((pBVar1 != (BIGNUM *)0x0) &&
      (pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x44),*(BIGNUM **)(param_2 + 0x44)),
      pBVar1 != (BIGNUM *)0x0)) &&
     (pBVar1 = BN_copy(*(BIGNUM **)(param_1 + 0x48),*(BIGNUM **)(param_2 + 0x48)),
     pBVar1 != (BIGNUM *)0x0)) {
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
    return 1;
  }
  return 0;
}


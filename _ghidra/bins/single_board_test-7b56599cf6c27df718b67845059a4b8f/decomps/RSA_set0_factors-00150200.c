
undefined4 RSA_set0_factors(int param_1,int param_2,int param_3)

{
  if ((*(BIGNUM **)(param_1 + 0x1c) == (BIGNUM *)0x0 && param_2 == 0) ||
     (*(int *)(param_1 + 0x20) == 0 && param_3 == 0)) {
    return 0;
  }
  if (param_2 != 0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0x1c));
    *(int *)(param_1 + 0x1c) = param_2;
    BN_set_flags(param_2,4);
  }
  if (param_3 != 0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0x20));
    *(int *)(param_1 + 0x20) = param_3;
    BN_set_flags(param_3,4);
    return 1;
  }
  return 1;
}


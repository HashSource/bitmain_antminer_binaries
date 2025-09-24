
undefined4 RSA_set0_crt_params(int param_1,int param_2,int param_3,int param_4)

{
  if (((*(BIGNUM **)(param_1 + 0x24) == (BIGNUM *)0x0 && param_2 == 0) ||
      (*(int *)(param_1 + 0x28) == 0 && param_3 == 0)) ||
     (*(int *)(param_1 + 0x2c) == 0 && param_4 == 0)) {
    return 0;
  }
  if (param_2 != 0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0x24));
    *(int *)(param_1 + 0x24) = param_2;
    BN_set_flags(param_2,4);
  }
  if (param_3 != 0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0x28));
    *(int *)(param_1 + 0x28) = param_3;
    BN_set_flags(param_3,4);
  }
  if (param_4 != 0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0x2c));
    *(int *)(param_1 + 0x2c) = param_4;
    BN_set_flags(param_4,4);
    return 1;
  }
  return 1;
}



undefined4 RSA_set0_key(int param_1,int param_2,int param_3,int param_4)

{
  if ((*(BIGNUM **)(param_1 + 0x10) == (BIGNUM *)0x0 && param_2 == 0) ||
     (*(int *)(param_1 + 0x14) == 0 && param_3 == 0)) {
    return 0;
  }
  if (param_2 != 0) {
    BN_free(*(BIGNUM **)(param_1 + 0x10));
    *(int *)(param_1 + 0x10) = param_2;
  }
  if (param_3 != 0) {
    BN_free(*(BIGNUM **)(param_1 + 0x14));
    *(int *)(param_1 + 0x14) = param_3;
  }
  if (param_4 != 0) {
    BN_clear_free(*(BIGNUM **)(param_1 + 0x18));
    *(int *)(param_1 + 0x18) = param_4;
    BN_set_flags(param_4,4);
    return 1;
  }
  return 1;
}



undefined4 DSA_set0_pqg(int param_1,int param_2,int param_3,int param_4)

{
  if (((*(BIGNUM **)(param_1 + 8) == (BIGNUM *)0x0 && param_2 == 0) ||
      (*(int *)(param_1 + 0xc) == 0 && param_3 == 0)) ||
     (*(int *)(param_1 + 0x10) == 0 && param_4 == 0)) {
    return 0;
  }
  if (param_2 != 0) {
    BN_free(*(BIGNUM **)(param_1 + 8));
    *(int *)(param_1 + 8) = param_2;
  }
  if (param_3 != 0) {
    BN_free(*(BIGNUM **)(param_1 + 0xc));
    *(int *)(param_1 + 0xc) = param_3;
  }
  if (param_4 != 0) {
    BN_free(*(BIGNUM **)(param_1 + 0x10));
    *(int *)(param_1 + 0x10) = param_4;
    return 1;
  }
  return 1;
}


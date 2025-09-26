
undefined4 DSA_set0_key(int param_1,int param_2,int param_3)

{
  if (*(BIGNUM **)(param_1 + 0x14) == (BIGNUM *)0x0) {
    if (param_2 == 0) {
      return 0;
    }
  }
  else if (param_2 == 0) goto LAB_001227a4;
  BN_free(*(BIGNUM **)(param_1 + 0x14));
  *(int *)(param_1 + 0x14) = param_2;
LAB_001227a4:
  if (param_3 != 0) {
    BN_free(*(BIGNUM **)(param_1 + 0x18));
    *(int *)(param_1 + 0x18) = param_3;
    return 1;
  }
  return 1;
}


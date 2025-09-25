
undefined4 dsa_copy_parameters(int param_1,int param_2)

{
  BIGNUM *pBVar1;
  DSA *pDVar2;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    pDVar2 = DSA_new();
    *(DSA **)(param_1 + 0x18) = pDVar2;
    if (pDVar2 == (DSA *)0x0) {
      return 0;
    }
  }
  pBVar1 = BN_dup(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 8));
  if (pBVar1 != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(*(int *)(param_1 + 0x18) + 8));
    *(BIGNUM **)(*(int *)(param_1 + 0x18) + 8) = pBVar1;
    pBVar1 = BN_dup(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0xc));
    if (pBVar1 != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(*(int *)(param_1 + 0x18) + 0xc));
      *(BIGNUM **)(*(int *)(param_1 + 0x18) + 0xc) = pBVar1;
      pBVar1 = BN_dup(*(BIGNUM **)(*(int *)(param_2 + 0x18) + 0x10));
      if (pBVar1 != (BIGNUM *)0x0) {
        BN_free(*(BIGNUM **)(*(int *)(param_1 + 0x18) + 0x10));
        *(BIGNUM **)(*(int *)(param_1 + 0x18) + 0x10) = pBVar1;
        return 1;
      }
    }
  }
  return 0;
}


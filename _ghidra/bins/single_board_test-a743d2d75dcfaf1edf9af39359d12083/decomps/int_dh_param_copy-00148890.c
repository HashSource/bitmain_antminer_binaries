
undefined4 int_dh_param_copy(int param_1,int param_2,int param_3)

{
  BIGNUM *pBVar1;
  void *pvVar2;
  
  if ((param_3 == -1) && (param_3 = *(int *)(param_2 + 0x24), param_3 != 0)) {
    param_3 = 1;
  }
  if (*(BIGNUM **)(param_2 + 8) == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x0;
  }
  else {
    pBVar1 = BN_dup(*(BIGNUM **)(param_2 + 8));
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  if (*(BIGNUM **)(param_1 + 8) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 8));
  }
  *(BIGNUM **)(param_1 + 8) = pBVar1;
  if (*(BIGNUM **)(param_2 + 0xc) == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x0;
  }
  else {
    pBVar1 = BN_dup(*(BIGNUM **)(param_2 + 0xc));
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  if (*(BIGNUM **)(param_1 + 0xc) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0xc));
  }
  *(BIGNUM **)(param_1 + 0xc) = pBVar1;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_2 + 0x10);
    return 1;
  }
  if (*(BIGNUM **)(param_2 + 0x24) == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x0;
  }
  else {
    pBVar1 = BN_dup(*(BIGNUM **)(param_2 + 0x24));
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  if (*(BIGNUM **)(param_1 + 0x24) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x24));
  }
  *(BIGNUM **)(param_1 + 0x24) = pBVar1;
  if (*(BIGNUM **)(param_2 + 0x28) == (BIGNUM *)0x0) {
    pBVar1 = (BIGNUM *)0x0;
  }
  else {
    pBVar1 = BN_dup(*(BIGNUM **)(param_2 + 0x28));
    if (pBVar1 == (BIGNUM *)0x0) {
      return 0;
    }
  }
  if (*(BIGNUM **)(param_1 + 0x28) != (BIGNUM *)0x0) {
    BN_free(*(BIGNUM **)(param_1 + 0x28));
  }
  *(BIGNUM **)(param_1 + 0x28) = pBVar1;
  if (*(void **)(param_1 + 0x2c) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1 + 0x2c));
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  if (*(void **)(param_2 + 0x2c) != (void *)0x0) {
    pvVar2 = BUF_memdup(*(void **)(param_2 + 0x2c),*(size_t *)(param_2 + 0x30));
    *(void **)(param_1 + 0x2c) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
    return 1;
  }
  return 1;
}


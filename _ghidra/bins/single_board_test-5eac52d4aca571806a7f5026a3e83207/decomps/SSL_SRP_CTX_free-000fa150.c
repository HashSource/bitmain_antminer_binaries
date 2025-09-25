
undefined4 SSL_SRP_CTX_free(int param_1)

{
  if (param_1 != 0) {
    CRYPTO_free(*(void **)(param_1 + 0x61c));
    CRYPTO_free(*(void **)(param_1 + 0x640));
    BN_free(*(BIGNUM **)(param_1 + 0x620));
    BN_free(*(BIGNUM **)(param_1 + 0x624));
    BN_free(*(BIGNUM **)(param_1 + 0x628));
    BN_free(*(BIGNUM **)(param_1 + 0x62c));
    BN_free(*(BIGNUM **)(param_1 + 0x630));
    BN_free(*(BIGNUM **)(param_1 + 0x634));
    BN_free(*(BIGNUM **)(param_1 + 0x638));
    BN_free(*(BIGNUM **)(param_1 + 0x63c));
    memset((void *)(param_1 + 0x60c),0,0x40);
    *(undefined4 *)(param_1 + 0x644) = 0x400;
    return 1;
  }
  return 0;
}


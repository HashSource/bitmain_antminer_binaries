
undefined4 SSL_CTX_SRP_CTX_free(int param_1)

{
  if (param_1 != 0) {
    CRYPTO_free(*(void **)(param_1 + 0x1d0));
    CRYPTO_free(*(void **)(param_1 + 500));
    BN_free(*(BIGNUM **)(param_1 + 0x1d4));
    BN_free(*(BIGNUM **)(param_1 + 0x1d8));
    BN_free(*(BIGNUM **)(param_1 + 0x1dc));
    BN_free(*(BIGNUM **)(param_1 + 0x1e0));
    BN_free(*(BIGNUM **)(param_1 + 0x1e4));
    BN_free(*(BIGNUM **)(param_1 + 0x1e8));
    BN_free(*(BIGNUM **)(param_1 + 0x1ec));
    BN_free(*(BIGNUM **)(param_1 + 0x1f0));
    memset((void *)(param_1 + 0x1c0),0,0x40);
    *(undefined4 *)(param_1 + 0x1f8) = 0x400;
    return 1;
  }
  return 0;
}


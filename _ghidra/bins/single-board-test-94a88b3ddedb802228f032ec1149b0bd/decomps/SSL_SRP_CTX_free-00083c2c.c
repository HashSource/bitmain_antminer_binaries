
undefined4 SSL_SRP_CTX_free(int param_1)

{
  if (param_1 != 0) {
    CRYPTO_free(*(void **)(param_1 + 0x1a4));
    BN_free(*(BIGNUM **)(param_1 + 0x1a8));
    BN_free(*(BIGNUM **)(param_1 + 0x1ac));
    BN_free(*(BIGNUM **)(param_1 + 0x1b0));
    BN_free(*(BIGNUM **)(param_1 + 0x1b4));
    BN_free(*(BIGNUM **)(param_1 + 0x1b8));
    BN_free(*(BIGNUM **)(param_1 + 0x1bc));
    BN_free(*(BIGNUM **)(param_1 + 0x1c0));
    BN_free(*(BIGNUM **)(param_1 + 0x1c4));
    *(undefined4 *)(param_1 + 0x198) = 0;
    *(undefined4 *)(param_1 + 0x194) = 0;
    *(undefined4 *)(param_1 + 0x19c) = 0;
    *(undefined4 *)(param_1 + 0x1a0) = 0;
    *(undefined4 *)(param_1 + 0x1a8) = 0;
    *(undefined4 *)(param_1 + 0x1ac) = 0;
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    *(undefined4 *)(param_1 + 0x1b4) = 0;
    *(undefined4 *)(param_1 + 0x1b8) = 0;
    *(undefined4 *)(param_1 + 0x1bc) = 0;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    *(undefined4 *)(param_1 + 0x1c4) = 0;
    *(undefined4 *)(param_1 + 0x1a4) = 0;
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x1d0) = 0;
    *(undefined4 *)(param_1 + 0x1cc) = 0x400;
    return 1;
  }
  return 0;
}


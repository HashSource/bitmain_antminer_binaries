
undefined4 SSL_CTX_SRP_CTX_free(int param_1)

{
  if (param_1 != 0) {
    CRYPTO_free(*(void **)(param_1 + 0x174));
    BN_free(*(BIGNUM **)(param_1 + 0x178));
    BN_free(*(BIGNUM **)(param_1 + 0x17c));
    BN_free(*(BIGNUM **)(param_1 + 0x180));
    BN_free(*(BIGNUM **)(param_1 + 0x184));
    BN_free(*(BIGNUM **)(param_1 + 0x188));
    BN_free(*(BIGNUM **)(param_1 + 0x18c));
    BN_free(*(BIGNUM **)(param_1 + 400));
    BN_free(*(BIGNUM **)(param_1 + 0x194));
    *(undefined4 *)(param_1 + 0x168) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
    *(undefined4 *)(param_1 + 0x170) = 0;
    *(undefined4 *)(param_1 + 0x178) = 0;
    *(undefined4 *)(param_1 + 0x17c) = 0;
    *(undefined4 *)(param_1 + 0x180) = 0;
    *(undefined4 *)(param_1 + 0x184) = 0;
    *(undefined4 *)(param_1 + 0x188) = 0;
    *(undefined4 *)(param_1 + 0x18c) = 0;
    *(undefined4 *)(param_1 + 400) = 0;
    *(undefined4 *)(param_1 + 0x194) = 0;
    *(undefined4 *)(param_1 + 0x174) = 0;
    *(undefined4 *)(param_1 + 0x198) = 0;
    *(undefined4 *)(param_1 + 0x1a0) = 0;
    *(undefined4 *)(param_1 + 0x19c) = 0x400;
    return 1;
  }
  return 0;
}


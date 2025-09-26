
void BN_BLINDING_free(BN_BLINDING *b)

{
  if (b != (BN_BLINDING *)0x0) {
    if (*(BIGNUM **)b != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)b);
    }
    if (*(BIGNUM **)(b + 4) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(b + 4));
    }
    if (*(BIGNUM **)(b + 8) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(b + 8));
    }
    if (*(BIGNUM **)(b + 0xc) != (BIGNUM *)0x0) {
      BN_free(*(BIGNUM **)(b + 0xc));
    }
    CRYPTO_free(b);
    return;
  }
  return;
}


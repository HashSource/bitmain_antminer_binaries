
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  sk_pop_free(xptable,(func *)0x16b9d9);
  if (DAT_00251ddc << 0x1f < 0) {
    if (DAT_00251ddc << 0x1e < 0) {
      CRYPTO_free(DAT_00251de4);
      CRYPTO_free(DAT_00251de8);
    }
    CRYPTO_free(&xstandard);
  }
  if (DAT_00251df8 << 0x1f < 0) {
    if (DAT_00251df8 << 0x1e < 0) {
      CRYPTO_free(DAT_00251e00);
      CRYPTO_free(DAT_00251e04);
    }
    CRYPTO_free(&DAT_00251df0);
  }
  if (DAT_00251e14 << 0x1f < 0) {
    if (DAT_00251e14 << 0x1e < 0) {
      CRYPTO_free(DAT_00251e1c);
      CRYPTO_free(DAT_00251e20);
    }
    CRYPTO_free(&DAT_00251e0c);
  }
  if (DAT_00251e30 << 0x1f < 0) {
    if (DAT_00251e30 << 0x1e < 0) {
      CRYPTO_free(DAT_00251e38);
      CRYPTO_free(DAT_00251e3c);
    }
    CRYPTO_free(&DAT_00251e28);
  }
  if (DAT_00251e4c << 0x1f < 0) {
    if (DAT_00251e4c << 0x1e < 0) {
      CRYPTO_free(DAT_00251e54);
      CRYPTO_free(DAT_00251e58);
    }
    CRYPTO_free(&DAT_00251e44);
  }
  if (DAT_00251e68 << 0x1f < 0) {
    if (DAT_00251e68 << 0x1e < 0) {
      CRYPTO_free(DAT_00251e70);
      CRYPTO_free(DAT_00251e74);
    }
    CRYPTO_free(&DAT_00251e60);
  }
  if (DAT_00251e84 << 0x1f < 0) {
    if (DAT_00251e84 << 0x1e < 0) {
      CRYPTO_free(DAT_00251e8c);
      CRYPTO_free(DAT_00251e90);
    }
    CRYPTO_free(&DAT_00251e7c);
  }
  if (DAT_00251ea0 << 0x1f < 0) {
    if (DAT_00251ea0 << 0x1e < 0) {
      CRYPTO_free(DAT_00251ea8);
      CRYPTO_free(DAT_00251eac);
    }
    CRYPTO_free(&DAT_00251e98);
  }
  if (DAT_00251ebc << 0x1f < 0) {
    if (DAT_00251ebc << 0x1e < 0) {
      CRYPTO_free(DAT_00251ec4);
      CRYPTO_free(DAT_00251ec8);
    }
    CRYPTO_free(&DAT_00251eb4);
  }
  xptable = (_STACK *)0x0;
  return;
}


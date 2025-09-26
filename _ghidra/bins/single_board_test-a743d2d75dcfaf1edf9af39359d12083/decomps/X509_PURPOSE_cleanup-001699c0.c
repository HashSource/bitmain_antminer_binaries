
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  sk_pop_free(xptable,(func *)0x168e99);
  if (DAT_0024cdec << 0x1f < 0) {
    if (DAT_0024cdec << 0x1e < 0) {
      CRYPTO_free(DAT_0024cdf4);
      CRYPTO_free(DAT_0024cdf8);
    }
    CRYPTO_free(&xstandard);
  }
  if (DAT_0024ce08 << 0x1f < 0) {
    if (DAT_0024ce08 << 0x1e < 0) {
      CRYPTO_free(DAT_0024ce10);
      CRYPTO_free(DAT_0024ce14);
    }
    CRYPTO_free(&DAT_0024ce00);
  }
  if (DAT_0024ce24 << 0x1f < 0) {
    if (DAT_0024ce24 << 0x1e < 0) {
      CRYPTO_free(DAT_0024ce2c);
      CRYPTO_free(DAT_0024ce30);
    }
    CRYPTO_free(&DAT_0024ce1c);
  }
  if (DAT_0024ce40 << 0x1f < 0) {
    if (DAT_0024ce40 << 0x1e < 0) {
      CRYPTO_free(DAT_0024ce48);
      CRYPTO_free(DAT_0024ce4c);
    }
    CRYPTO_free(&DAT_0024ce38);
  }
  if (DAT_0024ce5c << 0x1f < 0) {
    if (DAT_0024ce5c << 0x1e < 0) {
      CRYPTO_free(DAT_0024ce64);
      CRYPTO_free(DAT_0024ce68);
    }
    CRYPTO_free(&DAT_0024ce54);
  }
  if (DAT_0024ce78 << 0x1f < 0) {
    if (DAT_0024ce78 << 0x1e < 0) {
      CRYPTO_free(DAT_0024ce80);
      CRYPTO_free(DAT_0024ce84);
    }
    CRYPTO_free(&DAT_0024ce70);
  }
  if (DAT_0024ce94 << 0x1f < 0) {
    if (DAT_0024ce94 << 0x1e < 0) {
      CRYPTO_free(DAT_0024ce9c);
      CRYPTO_free(DAT_0024cea0);
    }
    CRYPTO_free(&DAT_0024ce8c);
  }
  if (DAT_0024ceb0 << 0x1f < 0) {
    if (DAT_0024ceb0 << 0x1e < 0) {
      CRYPTO_free(DAT_0024ceb8);
      CRYPTO_free(DAT_0024cebc);
    }
    CRYPTO_free(&DAT_0024cea8);
  }
  if (DAT_0024cecc << 0x1f < 0) {
    if (DAT_0024cecc << 0x1e < 0) {
      CRYPTO_free(DAT_0024ced4);
      CRYPTO_free(DAT_0024ced8);
    }
    CRYPTO_free(&DAT_0024cec4);
  }
  xptable = (_STACK *)0x0;
  return;
}


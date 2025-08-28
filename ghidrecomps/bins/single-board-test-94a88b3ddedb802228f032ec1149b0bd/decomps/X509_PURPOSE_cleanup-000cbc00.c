
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_PURPOSE_cleanup(void)

{
  sk_pop_free(xptable,(func *)0xcb0d9);
  if (DAT_00199628 << 0x1f < 0) {
    if (DAT_00199628 << 0x1e < 0) {
      CRYPTO_free(DAT_00199630);
      CRYPTO_free(DAT_00199634);
    }
    CRYPTO_free(&xstandard);
  }
  if (DAT_00199644 << 0x1f < 0) {
    if (DAT_00199644 << 0x1e < 0) {
      CRYPTO_free(DAT_0019964c);
      CRYPTO_free(DAT_00199650);
    }
    CRYPTO_free(&DAT_0019963c);
  }
  if (DAT_00199660 << 0x1f < 0) {
    if (DAT_00199660 << 0x1e < 0) {
      CRYPTO_free(DAT_00199668);
      CRYPTO_free(DAT_0019966c);
    }
    CRYPTO_free(&DAT_00199658);
  }
  if (DAT_0019967c << 0x1f < 0) {
    if (DAT_0019967c << 0x1e < 0) {
      CRYPTO_free(DAT_00199684);
      CRYPTO_free(DAT_00199688);
    }
    CRYPTO_free(&DAT_00199674);
  }
  if (DAT_00199698 << 0x1f < 0) {
    if (DAT_00199698 << 0x1e < 0) {
      CRYPTO_free(DAT_001996a0);
      CRYPTO_free(DAT_001996a4);
    }
    CRYPTO_free(&DAT_00199690);
  }
  if (DAT_001996b4 << 0x1f < 0) {
    if (DAT_001996b4 << 0x1e < 0) {
      CRYPTO_free(DAT_001996bc);
      CRYPTO_free(DAT_001996c0);
    }
    CRYPTO_free(&DAT_001996ac);
  }
  if (DAT_001996d0 << 0x1f < 0) {
    if (DAT_001996d0 << 0x1e < 0) {
      CRYPTO_free(DAT_001996d8);
      CRYPTO_free(DAT_001996dc);
    }
    CRYPTO_free(&DAT_001996c8);
  }
  if (DAT_001996ec << 0x1f < 0) {
    if (DAT_001996ec << 0x1e < 0) {
      CRYPTO_free(DAT_001996f4);
      CRYPTO_free(DAT_001996f8);
    }
    CRYPTO_free(&DAT_001996e4);
  }
  if (DAT_00199708 << 0x1f < 0) {
    if (DAT_00199708 << 0x1e < 0) {
      CRYPTO_free(DAT_00199710);
      CRYPTO_free(DAT_00199714);
    }
    CRYPTO_free(&DAT_00199700);
  }
  xptable = (_STACK *)0x0;
  return;
}


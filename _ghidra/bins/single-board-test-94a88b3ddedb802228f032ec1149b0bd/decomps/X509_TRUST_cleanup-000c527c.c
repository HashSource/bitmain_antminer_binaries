
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void X509_TRUST_cleanup(void)

{
  if ((int)(trstandard._4_4_ << 0x1f) < 0) {
    if ((int)(trstandard._4_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._12_4_);
    }
    CRYPTO_free(trstandard);
  }
  if ((int)(trstandard._28_4_ << 0x1f) < 0) {
    if ((int)(trstandard._28_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._36_4_);
    }
    CRYPTO_free(trstandard + 0x18);
  }
  if ((int)(trstandard._52_4_ << 0x1f) < 0) {
    if ((int)(trstandard._52_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._60_4_);
    }
    CRYPTO_free(trstandard + 0x30);
  }
  if ((int)(trstandard._76_4_ << 0x1f) < 0) {
    if ((int)(trstandard._76_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._84_4_);
    }
    CRYPTO_free(trstandard + 0x48);
  }
  if ((int)(trstandard._100_4_ << 0x1f) < 0) {
    if ((int)(trstandard._100_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._108_4_);
    }
    CRYPTO_free(trstandard + 0x60);
  }
  if ((int)(trstandard._124_4_ << 0x1f) < 0) {
    if ((int)(trstandard._124_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._132_4_);
    }
    CRYPTO_free(trstandard + 0x78);
  }
  if ((int)(trstandard._148_4_ << 0x1f) < 0) {
    if ((int)(trstandard._148_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._156_4_);
    }
    CRYPTO_free(trstandard + 0x90);
  }
  if ((int)(trstandard._172_4_ << 0x1f) < 0) {
    if ((int)(trstandard._172_4_ << 0x1e) < 0) {
      CRYPTO_free((void *)trstandard._180_4_);
    }
    CRYPTO_free(trstandard + 0xa8);
  }
  sk_pop_free(trtable,(func *)0xc4e95);
  trtable = (_STACK *)0x0;
  return;
}


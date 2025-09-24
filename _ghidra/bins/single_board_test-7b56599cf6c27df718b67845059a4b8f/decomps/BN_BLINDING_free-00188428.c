
void BN_BLINDING_free(BN_BLINDING *b)

{
  if (b != (BN_BLINDING *)0x0) {
    BN_free(*(BIGNUM **)b);
    BN_free(*(BIGNUM **)(b + 4));
    BN_free(*(BIGNUM **)(b + 8));
    BN_free(*(BIGNUM **)(b + 0xc));
    CRYPTO_THREAD_lock_free(*(undefined4 *)(b + 0x24));
    CRYPTO_free(b);
    return;
  }
  return;
}



void DSA_SIG_free(DSA_SIG *a)

{
  if (a != (DSA_SIG *)0x0) {
    if (a->r != (BIGNUM *)0x0) {
      BN_free(a->r);
    }
    if (a->s != (BIGNUM *)0x0) {
      BN_free(a->s);
    }
    CRYPTO_free(a);
    return;
  }
  return;
}



void DSA_SIG_free(DSA_SIG *a)

{
  if (a != (DSA_SIG *)0x0) {
    BN_clear_free(a->r);
    BN_clear_free(a->s);
    CRYPTO_free(a);
    return;
  }
  return;
}


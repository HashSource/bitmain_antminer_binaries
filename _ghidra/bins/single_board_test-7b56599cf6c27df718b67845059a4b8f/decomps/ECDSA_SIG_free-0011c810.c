
void ECDSA_SIG_free(ECDSA_SIG *sig)

{
  if (sig != (ECDSA_SIG *)0x0) {
    BN_clear_free(sig->r);
    BN_clear_free(sig->s);
    CRYPTO_free(sig);
    return;
  }
  return;
}



void BN_MONT_CTX_free(BN_MONT_CTX *mont)

{
  if (mont == (BN_MONT_CTX *)0x0) {
    return;
  }
  BN_clear_free(&mont->RR);
  BN_clear_free(&mont->N);
  BN_clear_free(&mont->Ni);
  if (-1 < mont->flags << 0x1f) {
    return;
  }
  CRYPTO_free(mont);
  return;
}



void X509_INFO_free(X509_INFO *a)

{
  int iVar1;
  
  if (a != (X509_INFO *)0x0) {
    iVar1 = CRYPTO_add_lock(&a->references,-1,4,DAT_00107f38,0x5d);
    if (iVar1 < 1) {
      if (a->x509 != (X509 *)0x0) {
        X509_free(a->x509);
      }
      if (a->crl != (X509_CRL *)0x0) {
        X509_CRL_free(a->crl);
      }
      if (a->x_pkey != (X509_PKEY *)0x0) {
        X509_PKEY_free(a->x_pkey);
      }
      if (a->enc_data != (char *)0x0) {
        CRYPTO_free(a->enc_data);
      }
      CRYPTO_free(a);
      return;
    }
  }
  return;
}


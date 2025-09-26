
void X509_INFO_free(X509_INFO *a)

{
  if (a != (X509_INFO *)0x0) {
    X509_free(a->x509);
    X509_CRL_free(a->crl);
    X509_PKEY_free(a->x_pkey);
    CRYPTO_free(a->enc_data);
    CRYPTO_free(a);
    return;
  }
  return;
}


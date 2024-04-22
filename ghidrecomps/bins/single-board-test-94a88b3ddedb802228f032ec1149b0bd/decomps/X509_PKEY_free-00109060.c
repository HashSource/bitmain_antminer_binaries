
void X509_PKEY_free(X509_PKEY *a)

{
  int iVar1;
  
  if (a != (X509_PKEY *)0x0) {
    iVar1 = CRYPTO_add_lock(&a->references,-1,5,DAT_001090b4,0x83);
    if (iVar1 < 1) {
      if (a->enc_algor != (X509_ALGOR *)0x0) {
        X509_ALGOR_free(a->enc_algor);
      }
      if (a->enc_pkey != (ASN1_STRING *)0x0) {
        ASN1_STRING_free(a->enc_pkey);
      }
      if (a->dec_pkey != (EVP_PKEY *)0x0) {
        EVP_PKEY_free(a->dec_pkey);
      }
      if ((a->key_data != (char *)0x0) && (a->key_free != 0)) {
        CRYPTO_free(a->key_data);
      }
      CRYPTO_free(a);
      return;
    }
  }
  return;
}


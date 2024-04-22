
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_INFO * X509_INFO_new(void)

{
  X509_INFO *pXVar1;
  
  pXVar1 = (X509_INFO *)CRYPTO_malloc(0x2c,DAT_00107ee4,0x45);
  if (pXVar1 == (X509_INFO *)0x0) {
    ERR_put_error(0xd,0xaa,0x41,DAT_00107ee4,0x47);
  }
  else {
    (pXVar1->enc_cipher).cipher = (EVP_CIPHER *)0x0;
    pXVar1->enc_len = 0;
    pXVar1->enc_data = (char *)0x0;
    pXVar1->x509 = (X509 *)0x0;
    pXVar1->crl = (X509_CRL *)0x0;
    pXVar1->x_pkey = (X509_PKEY *)0x0;
    pXVar1->references = 1;
  }
  return pXVar1;
}



/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_PKEY * X509_PKEY_new(void)

{
  X509_PKEY *pXVar1;
  X509_ALGOR *pXVar2;
  ASN1_STRING *pAVar3;
  
  pXVar1 = (X509_PKEY *)CRYPTO_malloc(0x34,DAT_0010905c,0x6d);
  if (pXVar1 == (X509_PKEY *)0x0) {
    ERR_put_error(0xd,0xad,0x41,DAT_0010905c,0x6d);
  }
  else {
    pXVar1->version = 0;
    pXVar2 = X509_ALGOR_new();
    pXVar1->enc_algor = pXVar2;
    if (pXVar2 != (X509_ALGOR *)0x0) {
      pAVar3 = ASN1_STRING_type_new(4);
      pXVar1->enc_pkey = pAVar3;
      if (pAVar3 != (ASN1_STRING *)0x0) {
        pXVar1->dec_pkey = (EVP_PKEY *)0x0;
        pXVar1->key_length = 0;
        pXVar1->key_data = (char *)0x0;
        pXVar1->key_free = 0;
        (pXVar1->cipher).cipher = (EVP_CIPHER *)0x0;
        memset((pXVar1->cipher).iv,0,0x10);
        pXVar1->references = 1;
        return pXVar1;
      }
    }
  }
  return (X509_PKEY *)0x0;
}


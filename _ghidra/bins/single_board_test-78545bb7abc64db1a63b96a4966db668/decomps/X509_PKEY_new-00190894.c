
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_PKEY * X509_PKEY_new(void)

{
  X509_PKEY *a;
  X509_ALGOR *pXVar1;
  ASN1_OCTET_STRING *pAVar2;
  
  a = (X509_PKEY *)CRYPTO_zalloc(0x30,"crypto/asn1/x_pkey.c",0x14);
  if (a != (X509_PKEY *)0x0) {
    pXVar1 = X509_ALGOR_new();
    a->enc_algor = pXVar1;
    pAVar2 = ASN1_OCTET_STRING_new();
    a->enc_pkey = pAVar2;
    if (pAVar2 != (ASN1_OCTET_STRING *)0x0 && a->enc_algor != (X509_ALGOR *)0x0) {
      return a;
    }
  }
  X509_PKEY_free(a);
  ERR_put_error(0xd,0xad,0x41,"crypto/asn1/x_pkey.c",0x20);
  return (X509_PKEY *)0x0;
}


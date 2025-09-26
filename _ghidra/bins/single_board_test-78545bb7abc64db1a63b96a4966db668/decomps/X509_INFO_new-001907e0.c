
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_INFO * X509_INFO_new(void)

{
  X509_INFO *pXVar1;
  
  pXVar1 = (X509_INFO *)CRYPTO_zalloc(0x28,"crypto/asn1/x_info.c",0x14);
  if (pXVar1 == (X509_INFO *)0x0) {
    ERR_put_error(0xd,0xaa,0x41,"crypto/asn1/x_info.c",0x16);
  }
  return pXVar1;
}


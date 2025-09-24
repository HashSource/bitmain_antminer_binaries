
int X509_check_private_key(X509 *x509,EVP_PKEY *pkey)

{
  EVP_PKEY *a;
  int iVar1;
  
  a = (EVP_PKEY *)X509_get0_pubkey(x509);
  if (a != (EVP_PKEY *)0x0) {
    iVar1 = EVP_PKEY_cmp(a,pkey);
    if (iVar1 == -1) {
      ERR_put_error(0xb,0x80,0x73,"crypto/x509/x509_cmp.c",0x132);
      return 0;
    }
    if (iVar1 == 0) {
      ERR_put_error(0xb,0x80,0x74,"crypto/x509/x509_cmp.c",0x12f);
      return 0;
    }
    if (iVar1 != -2) {
      return (uint)(0 < iVar1);
    }
  }
  ERR_put_error(0xb,0x80,0x75,"crypto/x509/x509_cmp.c",0x135);
  return 0;
}



int SSL_use_RSAPrivateKey_ASN1(SSL *ssl,uchar *d,long len)

{
  RSA *r;
  int iVar1;
  EVP_PKEY *pkey;
  uchar *local_14;
  
  local_14 = d;
  r = d2i_RSAPrivateKey((RSA **)0x0,&local_14,len);
  if (r == (RSA *)0x0) {
    ERR_put_error(0x14,0xcd,0xd,DAT_00081948,0x118);
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xcc,0x41,DAT_00081948,0x9a);
      iVar1 = 0;
    }
    else {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xcc,6,DAT_00081948,0x9e);
        iVar1 = 0;
      }
      else {
        RSA_up_ref(r);
        EVP_PKEY_assign(pkey,6,r);
        iVar1 = ssl_set_pkey(ssl->cert,pkey);
        EVP_PKEY_free(pkey);
      }
    }
    RSA_free(r);
  }
  return iVar1;
}


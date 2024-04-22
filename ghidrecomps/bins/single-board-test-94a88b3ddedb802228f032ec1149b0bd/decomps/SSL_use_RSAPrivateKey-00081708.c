
int SSL_use_RSAPrivateKey(SSL *ssl,RSA *rsa)

{
  int iVar1;
  EVP_PKEY *pkey;
  
  if (rsa == (RSA *)0x0) {
    ERR_put_error(0x14,0xcc,0x43,DAT_00081788,0x96);
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xcc,0x41,DAT_00081788,0x9a);
      iVar1 = 0;
    }
    else {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xcc,6,DAT_00081788,0x9e);
        iVar1 = 0;
      }
      else {
        RSA_up_ref(rsa);
        EVP_PKEY_assign(pkey,6,rsa);
        iVar1 = ssl_set_pkey(ssl->cert,pkey);
        EVP_PKEY_free(pkey);
      }
    }
  }
  return iVar1;
}



EVP_PKEY * d2i_PKCS8PrivateKey_bio(BIO *bp,EVP_PKEY **x,undefined1 *cb,void *u)

{
  X509_SIG *a;
  size_t len;
  PKCS8_PRIV_KEY_INFO *p8;
  EVP_PKEY *pEVar1;
  char acStack_418 [1024];
  
  a = d2i_PKCS8_bio(bp,(X509_SIG **)0x0);
  if (a != (X509_SIG *)0x0) {
    if (cb == (undefined1 *)0x0) {
      len = PEM_def_callback(acStack_418,0x400,0,u);
    }
    else {
      len = (*(code *)cb)(acStack_418,0x400,0);
    }
    if ((int)len < 0) {
      ERR_put_error(9,0x78,0x68,"crypto/pem/pem_pk8.c",0x80);
      X509_SIG_free(a);
    }
    else {
      p8 = PKCS8_decrypt(a,acStack_418,len);
      X509_SIG_free(a);
      OPENSSL_cleanse(acStack_418,len);
      if (p8 != (PKCS8_PRIV_KEY_INFO *)0x0) {
        pEVar1 = EVP_PKCS82PKEY(p8);
        PKCS8_PRIV_KEY_INFO_free(p8);
        if (pEVar1 != (EVP_PKEY *)0x0) {
          if (x != (EVP_PKEY **)0x0) {
            EVP_PKEY_free(*x);
            *x = pEVar1;
          }
          return pEVar1;
        }
      }
    }
  }
  return (EVP_PKEY *)0x0;
}


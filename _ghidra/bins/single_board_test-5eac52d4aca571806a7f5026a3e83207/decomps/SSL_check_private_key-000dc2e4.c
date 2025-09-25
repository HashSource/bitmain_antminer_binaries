
int SSL_check_private_key(SSL *ctx)

{
  X509 *x509;
  int iVar1;
  EVP_PKEY *pkey;
  
  if (ctx == (SSL *)0x0) {
    ERR_put_error(0x14,0xa3,0x43,"ssl/ssl_lib.c",0x658);
  }
  else {
    x509 = (X509 *)**(undefined4 **)ctx[2].error;
    if (x509 == (X509 *)0x0) {
      ERR_put_error(0x14,0xa3,0xb1,"ssl/ssl_lib.c",0x65c);
    }
    else {
      pkey = (EVP_PKEY *)(*(undefined4 **)ctx[2].error)[1];
      if (pkey != (EVP_PKEY *)0x0) {
        iVar1 = X509_check_private_key(x509,pkey);
        return iVar1;
      }
      ERR_put_error(0x14,0xa3,0xbe,"ssl/ssl_lib.c",0x660);
    }
  }
  return 0;
}


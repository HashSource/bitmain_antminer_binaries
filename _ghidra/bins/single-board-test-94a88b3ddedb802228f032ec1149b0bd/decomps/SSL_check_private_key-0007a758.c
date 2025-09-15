
int SSL_check_private_key(SSL *ctx)

{
  X509 *x509;
  int iVar1;
  EVP_PKEY *pkey;
  undefined4 *puVar2;
  
  if (ctx == (SSL *)0x0) {
    ERR_put_error(0x14,0xa3,0x43,"ssl_lib.c",0x3c5);
  }
  else {
    if (ctx->cert == (cert_st *)0x0) {
      iVar1 = 0x3c9;
    }
    else {
      puVar2 = *(undefined4 **)ctx->cert;
      x509 = (X509 *)*puVar2;
      if (x509 != (X509 *)0x0) {
        pkey = (EVP_PKEY *)puVar2[1];
        if (pkey == (EVP_PKEY *)0x0) {
          ERR_put_error(0x14,0xa3,0xbe,"ssl_lib.c",0x3d1);
          return 0;
        }
        iVar1 = X509_check_private_key(x509,pkey);
        return iVar1;
      }
      iVar1 = 0x3cd;
    }
    ERR_put_error(0x14,0xa3,0xb1,"ssl_lib.c",iVar1);
  }
  return 0;
}



int SSL_CTX_check_private_key(SSL_CTX *ctx)

{
  X509 *x509;
  int iVar1;
  EVP_PKEY *pkey;
  
  if (ctx != (SSL_CTX *)0x0) {
    x509 = (X509 *)**(undefined4 **)ctx->verify_mode;
    if (x509 != (X509 *)0x0) {
      pkey = (EVP_PKEY *)(*(undefined4 **)ctx->verify_mode)[1];
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xa8,0xbe,"ssl/ssl_lib.c",0x64d);
        return 0;
      }
      iVar1 = X509_check_private_key(x509,pkey);
      return iVar1;
    }
  }
  ERR_put_error(0x14,0xa8,0xb1,"ssl/ssl_lib.c",0x649);
  return 0;
}



int SSL_CTX_check_private_key(SSL_CTX *ctx)

{
  X509 *x509;
  int iVar1;
  EVP_PKEY *pkey;
  undefined4 *puVar2;
  
  if ((ctx != (SSL_CTX *)0x0) && (ctx->cert != (cert_st *)0x0)) {
    puVar2 = *(undefined4 **)ctx->cert;
    x509 = (X509 *)*puVar2;
    if (x509 != (X509 *)0x0) {
      pkey = (EVP_PKEY *)puVar2[1];
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xa8,0xbe,"ssl_lib.c",0x3ba);
        return 0;
      }
      iVar1 = X509_check_private_key(x509,pkey);
      return iVar1;
    }
  }
  ERR_put_error(0x14,0xa8,0xb1,"ssl_lib.c",0x3b5);
  return 0;
}


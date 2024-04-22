
int SSL_CTX_check_private_key(SSL_CTX *ctx)

{
  X509 *x509;
  int iVar1;
  X509 *pkey;
  X509 **ppXVar2;
  
  if ((ctx != (SSL_CTX *)0x0) && ((undefined4 *)ctx->cert != (undefined4 *)0x0)) {
    ppXVar2 = *(X509 ***)ctx->cert;
    x509 = *ppXVar2;
    if (x509 != (X509 *)0x0) {
      pkey = ppXVar2[1];
      if (pkey == (X509 *)0x0) {
        ERR_put_error(0x14,0xa8,0xbe,DAT_0007a754,0x3ba);
        return 0;
      }
      iVar1 = X509_check_private_key(x509,(EVP_PKEY *)pkey);
      return iVar1;
    }
  }
  ERR_put_error(0x14,0xa8,0xb1,DAT_0007a754,0x3b5);
  return 0;
}


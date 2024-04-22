
int SSL_check_private_key(SSL *ctx)

{
  X509 *x509;
  int iVar1;
  X509 *pkey;
  X509 **ppXVar2;
  
  if (ctx == (SSL *)0x0) {
    ERR_put_error(0x14,0xa3,0x43,DAT_0007a7c4,0x3c5);
  }
  else {
    if ((undefined4 *)ctx->cert == (undefined4 *)0x0) {
      iVar1 = 0x3c9;
    }
    else {
      ppXVar2 = *(X509 ***)ctx->cert;
      x509 = *ppXVar2;
      if (x509 != (X509 *)0x0) {
        pkey = ppXVar2[1];
        if (pkey == (X509 *)0x0) {
          ERR_put_error(0x14,0xa3,0xbe,DAT_0007a7c4,0x3d1);
          return 0;
        }
        iVar1 = X509_check_private_key(x509,(EVP_PKEY *)pkey);
        return iVar1;
      }
      iVar1 = 0x3cd;
    }
    ERR_put_error(0x14,0xa3,0xb1,DAT_0007a7c4,iVar1);
  }
  return 0;
}


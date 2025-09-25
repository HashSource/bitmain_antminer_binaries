
int SSL_CTX_use_RSAPrivateKey(SSL_CTX *ctx,RSA *rsa)

{
  EVP_PKEY *pkey;
  int iVar1;
  
  if (rsa == (RSA *)0x0) {
    ERR_put_error(0x14,0xb1,0x43,"ssl/ssl_rsa.c",0x1a5);
    return 0;
  }
  pkey = EVP_PKEY_new();
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xb1,6,"ssl/ssl_rsa.c",0x1a9);
    iVar1 = 0;
  }
  else {
    RSA_up_ref(rsa);
    iVar1 = EVP_PKEY_assign(pkey,6,rsa);
    if (iVar1 < 1) {
      RSA_free(rsa);
      EVP_PKEY_free(pkey);
      return 0;
    }
    iVar1 = ssl_set_pkey(ctx->verify_mode,pkey);
    EVP_PKEY_free(pkey);
  }
  return iVar1;
}


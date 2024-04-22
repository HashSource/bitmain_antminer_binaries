
int SSL_CTX_use_RSAPrivateKey(SSL_CTX *ctx,RSA *rsa)

{
  int iVar1;
  EVP_PKEY *pkey;
  
  if (rsa == (RSA *)0x0) {
    ERR_put_error(0x14,0xb1,0x43,DAT_00081d24,0x1fa);
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xb1,0x41,DAT_00081d24,0x1fe);
      iVar1 = 0;
    }
    else {
      pkey = EVP_PKEY_new();
      if (pkey == (EVP_PKEY *)0x0) {
        ERR_put_error(0x14,0xb1,6,DAT_00081d24,0x202);
        iVar1 = 0;
      }
      else {
        RSA_up_ref(rsa);
        EVP_PKEY_assign(pkey,6,rsa);
        iVar1 = ssl_set_pkey(ctx->cert,pkey);
        EVP_PKEY_free(pkey);
      }
    }
  }
  return iVar1;
}


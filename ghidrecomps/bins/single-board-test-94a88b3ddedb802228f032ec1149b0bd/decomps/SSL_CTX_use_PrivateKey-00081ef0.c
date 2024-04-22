
int SSL_CTX_use_PrivateKey(SSL_CTX *ctx,EVP_PKEY *pkey)

{
  int iVar1;
  
  if (pkey == (EVP_PKEY *)0x0) {
    ERR_put_error(0x14,0xae,0x43,DAT_00081f40,0x24e);
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 != 0) {
      iVar1 = ssl_set_pkey(ctx->cert,pkey);
      return iVar1;
    }
    ERR_put_error(0x14,0xae,0x41,DAT_00081f40,0x252);
  }
  return 0;
}



int SSL_CTX_use_certificate(SSL_CTX *ctx,X509 *x)

{
  int iVar1;
  
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0xab,0x43,DAT_00081b48,0x172);
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 != 0) {
      iVar1 = ssl_set_cert(ctx->cert,x);
      return iVar1;
    }
    ERR_put_error(0x14,0xab,0x41,DAT_00081b48,0x176);
  }
  return 0;
}


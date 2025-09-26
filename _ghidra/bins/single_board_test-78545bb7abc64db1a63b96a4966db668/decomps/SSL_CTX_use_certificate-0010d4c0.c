
int SSL_CTX_use_certificate(SSL_CTX *ctx,X509 *x)

{
  int iVar1;
  
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0xab,0x43,"ssl/ssl_rsa.c",0x128);
    return 0;
  }
  iVar1 = ssl_security_cert(0,ctx,x,0,1);
  if (iVar1 != 1) {
    ERR_put_error(0x14,0xab,iVar1,"ssl/ssl_rsa.c",0x12d);
    return 0;
  }
  iVar1 = ssl_set_cert(ctx->verify_mode,x);
  return iVar1;
}


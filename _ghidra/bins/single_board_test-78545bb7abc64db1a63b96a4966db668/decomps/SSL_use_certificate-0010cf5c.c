
int SSL_use_certificate(SSL *ssl,X509 *x)

{
  int iVar1;
  
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0xc6,0x43,"ssl/ssl_rsa.c",0x1f);
    return 0;
  }
  iVar1 = ssl_security_cert(ssl,0,x,0,1);
  if (iVar1 != 1) {
    ERR_put_error(0x14,0xc6,iVar1,"ssl/ssl_rsa.c",0x24);
    return 0;
  }
  iVar1 = ssl_set_cert(ssl[2].error,x);
  return iVar1;
}


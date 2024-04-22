
int SSL_use_certificate(SSL *ssl,X509 *x)

{
  int iVar1;
  
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0xc6,0x43,DAT_000815c0,0x48);
  }
  else {
    iVar1 = ssl_cert_inst(&ssl->cert);
    if (iVar1 != 0) {
      iVar1 = ssl_set_cert(ssl->cert,x);
      return iVar1;
    }
    ERR_put_error(0x14,0xc6,0x41,DAT_000815c0,0x4c);
  }
  return 0;
}


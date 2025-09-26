
int SSL_use_certificate_ASN1(SSL *ssl,uchar *d,int len)

{
  X509 *x;
  int iVar1;
  uchar *local_14 [2];
  
  local_14[0] = d;
  x = d2i_X509((X509 **)0x0,local_14,len);
  if (x != (X509 *)0x0) {
    iVar1 = SSL_use_certificate(ssl,x);
    X509_free(x);
    return iVar1;
  }
  ERR_put_error(0x14,199,0xd,"ssl/ssl_rsa.c",0x5b);
  return 0;
}


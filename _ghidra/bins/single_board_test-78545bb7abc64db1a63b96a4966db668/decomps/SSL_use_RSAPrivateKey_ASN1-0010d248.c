
int SSL_use_RSAPrivateKey_ASN1(SSL *ssl,uchar *d,long len)

{
  RSA *rsa;
  int iVar1;
  uchar *local_14 [2];
  
  local_14[0] = d;
  rsa = d2i_RSAPrivateKey((RSA **)0x0,local_14,len);
  if (rsa != (RSA *)0x0) {
    iVar1 = SSL_use_RSAPrivateKey(ssl,rsa);
    RSA_free(rsa);
    return iVar1;
  }
  ERR_put_error(0x14,0xcd,0xd,"ssl/ssl_rsa.c",0xd5);
  return 0;
}


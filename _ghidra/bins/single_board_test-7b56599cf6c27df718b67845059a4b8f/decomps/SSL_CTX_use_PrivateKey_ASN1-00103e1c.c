
int SSL_CTX_use_PrivateKey_ASN1(int pk,SSL_CTX *ctx,uchar *d,long len)

{
  EVP_PKEY *pkey;
  int iVar1;
  uchar *local_14 [2];
  
  local_14[0] = d;
  pkey = d2i_PrivateKey(pk,(EVP_PKEY **)0x0,local_14,len);
  if (pkey != (EVP_PKEY *)0x0) {
    iVar1 = SSL_CTX_use_PrivateKey(ctx,pkey);
    EVP_PKEY_free(pkey);
    return iVar1;
  }
  ERR_put_error(0x14,0xaf,0xd,"ssl/ssl_rsa.c",0x22c);
  return 0;
}


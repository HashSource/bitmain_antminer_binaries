
int SSL_CTX_set_ex_data(SSL_CTX *ssl,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)&ssl->md5,idx,data);
  return iVar1;
}


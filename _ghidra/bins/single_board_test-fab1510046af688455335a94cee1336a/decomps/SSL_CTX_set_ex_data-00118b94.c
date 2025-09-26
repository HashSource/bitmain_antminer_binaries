
int SSL_CTX_set_ex_data(SSL_CTX *ssl,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data(&ssl->ex_data,idx,data);
  return iVar1;
}


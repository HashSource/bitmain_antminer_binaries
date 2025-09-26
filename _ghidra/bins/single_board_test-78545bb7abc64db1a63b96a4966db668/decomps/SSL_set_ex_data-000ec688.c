
int SSL_set_ex_data(SSL *ssl,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)&ssl[3].bbio,idx,data);
  return iVar1;
}


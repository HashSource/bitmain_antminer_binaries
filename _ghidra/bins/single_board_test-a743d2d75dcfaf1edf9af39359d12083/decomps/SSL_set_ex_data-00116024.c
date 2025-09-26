
int SSL_set_ex_data(SSL *ssl,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)&ssl->verify_result,idx,data);
  return iVar1;
}


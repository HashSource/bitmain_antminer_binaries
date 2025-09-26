
int SSL_SESSION_set_ex_data(SSL_SESSION *ss,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)&ss->ciphers,idx,data);
  return iVar1;
}



void * SSL_SESSION_get_ex_data(SSL_SESSION *ss,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)&ss->ciphers,idx);
  return pvVar1;
}


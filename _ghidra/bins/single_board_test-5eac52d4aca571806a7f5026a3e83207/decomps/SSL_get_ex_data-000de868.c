
void * SSL_get_ex_data(SSL *ssl,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)&ssl[3].bbio,idx);
  return pvVar1;
}



void * SSL_CTX_get_ex_data(SSL_CTX *ssl,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data(&ssl->ex_data,idx);
  return pvVar1;
}


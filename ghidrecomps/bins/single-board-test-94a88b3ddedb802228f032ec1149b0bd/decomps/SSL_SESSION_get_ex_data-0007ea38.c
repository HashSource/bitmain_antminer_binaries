
void * SSL_SESSION_get_ex_data(SSL_SESSION *ss,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)(ss->krb5_client_princ + 0x30),idx);
  return pvVar1;
}


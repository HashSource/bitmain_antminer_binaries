
int SSL_SESSION_set_ex_data(SSL_SESSION *ss,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)(ss->krb5_client_princ + 0x30),idx,data);
  return iVar1;
}


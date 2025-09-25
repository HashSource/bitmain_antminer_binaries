
void * RSA_get_ex_data(RSA *r,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)&r->references,idx);
  return pvVar1;
}



void * X509_get_ex_data(X509 *r,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)&r[1].sig_alg,idx);
  return pvVar1;
}


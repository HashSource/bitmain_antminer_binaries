
void * X509_get_ex_data(X509 *r,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data(&r->ex_data,idx);
  return pvVar1;
}


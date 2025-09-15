
void * DSA_get_ex_data(DSA *d,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data(&d->ex_data,idx);
  return pvVar1;
}



void * BIO_get_ex_data(BIO *bio,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data((CRYPTO_EX_DATA *)&bio[1].cb_arg,idx);
  return pvVar1;
}


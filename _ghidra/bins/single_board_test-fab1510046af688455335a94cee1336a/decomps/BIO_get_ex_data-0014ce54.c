
void * BIO_get_ex_data(BIO *bio,int idx)

{
  void *pvVar1;
  
  pvVar1 = CRYPTO_get_ex_data(&bio->ex_data,idx);
  return pvVar1;
}


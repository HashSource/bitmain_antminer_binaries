
int BIO_set_ex_data(BIO *bio,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data(&bio->ex_data,idx,data);
  return iVar1;
}


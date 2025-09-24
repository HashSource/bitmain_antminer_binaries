
int BIO_set_ex_data(BIO *bio,int idx,void *data)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)&bio[1].cb_arg,idx,data);
  return iVar1;
}


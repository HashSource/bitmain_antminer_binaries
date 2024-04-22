
int RSA_set_ex_data(RSA *r,int idx,void *arg)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data(&r->ex_data,idx,arg);
  return iVar1;
}



int ENGINE_set_ex_data(ENGINE *e,int idx,void *arg)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)(e + 0x60),idx,arg);
  return iVar1;
}



int UI_set_ex_data(UI *r,int idx,void *arg)

{
  int iVar1;
  
  iVar1 = CRYPTO_set_ex_data((CRYPTO_EX_DATA *)(r + 0xc),idx,arg);
  return iVar1;
}


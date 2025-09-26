
int int_new_class(void)

{
  int iVar1;
  
  CRYPTO_lock(9,2,"ex_data.c",0x181);
  iVar1 = ex_class;
  ex_class = ex_class + 1;
  CRYPTO_lock(10,2,"ex_data.c",0x183);
  return iVar1;
}


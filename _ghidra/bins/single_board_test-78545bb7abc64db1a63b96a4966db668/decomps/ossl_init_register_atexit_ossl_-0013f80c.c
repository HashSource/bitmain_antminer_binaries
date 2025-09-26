
void ossl_init_register_atexit_ossl_(void)

{
  int iVar1;
  
  iVar1 = atexit((__func *)0x13f895);
  ossl_init_register_atexit_ossl_ret_ = (uint)(iVar1 == 0);
  return;
}


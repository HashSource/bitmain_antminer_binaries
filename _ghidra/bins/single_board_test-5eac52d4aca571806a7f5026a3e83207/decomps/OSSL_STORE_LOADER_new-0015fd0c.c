
int * OSSL_STORE_LOADER_new(int param_1,int param_2)

{
  int *piVar1;
  
  if (param_2 == 0) {
    ERR_put_error(0x2c,0x71,0x6a,"crypto/store/store_register.c",0x2b);
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)CRYPTO_zalloc(0x28,"crypto/store/store_register.c",0x2f);
    if (piVar1 == (int *)0x0) {
      ERR_put_error(0x2c,0x71,0x41,"crypto/store/store_register.c",0x30);
    }
    else {
      *piVar1 = param_2;
      piVar1[1] = param_1;
    }
  }
  return piVar1;
}


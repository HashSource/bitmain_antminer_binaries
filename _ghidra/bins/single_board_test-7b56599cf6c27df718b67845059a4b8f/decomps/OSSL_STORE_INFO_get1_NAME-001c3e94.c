
char * OSSL_STORE_INFO_get1_NAME(int *param_1)

{
  char *pcVar1;
  
  if (*param_1 == 1) {
    pcVar1 = CRYPTO_strdup((char *)param_1[1],"crypto/store/store_lib.c",0x150);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x2c,0x67,0x41,"crypto/store/store_lib.c",0x154);
    }
    return pcVar1;
  }
  ERR_put_error(0x2c,0x67,0x67,"crypto/store/store_lib.c",0x158);
  return (char *)0x0;
}


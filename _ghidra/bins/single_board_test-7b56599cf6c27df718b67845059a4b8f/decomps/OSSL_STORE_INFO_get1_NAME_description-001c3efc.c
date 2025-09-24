
char * OSSL_STORE_INFO_get1_NAME_description(int *param_1)

{
  char *pcVar1;
  
  if (*param_1 == 1) {
    pcVar1 = (char *)param_1[2];
    if (pcVar1 == (char *)0x0) {
      pcVar1 = "";
    }
    pcVar1 = CRYPTO_strdup(pcVar1,"crypto/store/store_lib.c",0x167);
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x2c,0x87,0x41,"crypto/store/store_lib.c",0x16b);
    }
    return pcVar1;
  }
  ERR_put_error(0x2c,0x87,0x67,"crypto/store/store_lib.c",0x16f);
  return (char *)0x0;
}


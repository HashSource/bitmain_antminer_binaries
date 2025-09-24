
undefined4 * ossl_store_info_new_EMBEDDED(char *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0xc,"crypto/store/store_lib.c",0xf0);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2c,0x7b,0x41,"crypto/store/store_lib.c",0x264);
  }
  else {
    *puVar1 = 0xffffffff;
    puVar1[1] = param_2;
    if (param_1 == (char *)0x0) {
      puVar1[2] = 0;
      return puVar1;
    }
    pcVar2 = CRYPTO_strdup(param_1,"crypto/store/store_lib.c",0x26a);
    puVar1[2] = pcVar2;
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(0x2c,0x7b,0x41,"crypto/store/store_lib.c",0x26e);
      OSSL_STORE_INFO_free(puVar1);
      puVar1 = (undefined4 *)0x0;
    }
  }
  return puVar1;
}


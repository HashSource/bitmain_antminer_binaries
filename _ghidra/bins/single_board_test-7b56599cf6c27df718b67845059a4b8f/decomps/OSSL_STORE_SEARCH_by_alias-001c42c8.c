
undefined4 * OSSL_STORE_SEARCH_by_alias(char *param_1)

{
  undefined4 *puVar1;
  size_t sVar2;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x18,"crypto/store/store_lib.c",0x226);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2c,0x84,0x41,"crypto/store/store_lib.c",0x22a);
  }
  else {
    puVar1[4] = param_1;
    *puVar1 = 4;
    sVar2 = strlen(param_1);
    puVar1[5] = sVar2;
  }
  return puVar1;
}


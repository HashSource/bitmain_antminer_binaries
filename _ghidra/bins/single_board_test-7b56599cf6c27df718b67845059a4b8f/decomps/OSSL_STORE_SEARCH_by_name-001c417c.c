
undefined4 * OSSL_STORE_SEARCH_by_name(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x18,"crypto/store/store_lib.c",0x1e8);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2c,0x89,0x41,"crypto/store/store_lib.c",0x1ec);
  }
  else {
    *puVar1 = 1;
    puVar1[1] = param_1;
  }
  return puVar1;
}


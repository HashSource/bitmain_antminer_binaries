
undefined4 * OSSL_STORE_SEARCH_by_issuer_serial(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x18,"crypto/store/store_lib.c",0x1f8);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x2c,0x85,0x41,"crypto/store/store_lib.c",0x1fc);
  }
  else {
    puVar1[1] = param_1;
    puVar1[2] = param_2;
    *puVar1 = 2;
  }
  return puVar1;
}


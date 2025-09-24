
undefined4 * OSSL_STORE_INFO_new_PKEY(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0xc,"crypto/store/store_lib.c",0xf0);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 3;
    puVar1[1] = param_1;
    return puVar1;
  }
  ERR_put_error(0x2c,0x6f,0x41,"crypto/store/store_lib.c",0x126);
  return (undefined4 *)0x0;
}


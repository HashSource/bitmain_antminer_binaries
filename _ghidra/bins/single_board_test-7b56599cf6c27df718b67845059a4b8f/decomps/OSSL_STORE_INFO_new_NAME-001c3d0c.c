
undefined4 * OSSL_STORE_INFO_new_NAME(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0xc,"crypto/store/store_lib.c",0xf0);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 1;
    puVar1[1] = param_1;
    puVar1[2] = 0;
    return puVar1;
  }
  ERR_put_error(0x2c,0x6d,0x41,"crypto/store/store_lib.c",0x100);
  return (undefined4 *)0x0;
}


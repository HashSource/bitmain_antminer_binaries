
undefined4 * rand_pool_attach(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)CRYPTO_zalloc(0x24,"crypto/rand/rand_lib.c",0x1e7);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x24,0x7c,0x41,"crypto/rand/rand_lib.c",0x1ea);
  }
  else {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[6] = param_2;
    puVar1[5] = param_2;
    puVar1[4] = param_2;
    puVar1[7] = param_3;
    puVar1[2] = 1;
  }
  return puVar1;
}


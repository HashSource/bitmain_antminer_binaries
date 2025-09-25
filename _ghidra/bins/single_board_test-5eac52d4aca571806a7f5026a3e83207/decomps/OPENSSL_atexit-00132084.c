
bool OPENSSL_atexit(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)CRYPTO_malloc(8,"crypto/init.c",0x327);
  if (puVar2 == (undefined4 *)0x0) {
    ERR_put_error(0xf,0x72,0x41,"crypto/init.c",0x328);
  }
  else {
    *puVar2 = param_1;
    puVar1 = puVar2;
    puVar2[1] = stop_handlers;
    stop_handlers = puVar1;
  }
  return puVar2 != (undefined4 *)0x0;
}


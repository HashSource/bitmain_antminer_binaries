
void engine_cleanup_add_first(undefined4 param_1)

{
  undefined4 *puVar1;
  
  if ((cleanup_stack == 0) && (cleanup_stack = OPENSSL_sk_new_null(), cleanup_stack == 0)) {
    return;
  }
  puVar1 = (undefined4 *)CRYPTO_malloc(4,"crypto/engine/eng_lib.c",0x82);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x26,199,0x41,"crypto/engine/eng_lib.c",0x83);
    return;
  }
  *puVar1 = param_1;
  OPENSSL_sk_insert(cleanup_stack,puVar1,0);
  return;
}


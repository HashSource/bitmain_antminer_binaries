
void engine_cleanup_add_last(undefined4 param_1)

{
  undefined4 *ptr;
  int iVar1;
  
  if ((cleanup_stack != 0) || (cleanup_stack = OPENSSL_sk_new_null(), cleanup_stack != 0)) {
    ptr = (undefined4 *)CRYPTO_malloc(4,"crypto/engine/eng_lib.c",0x82);
    if (ptr == (undefined4 *)0x0) {
      ERR_put_error(0x26,199,0x41,"crypto/engine/eng_lib.c",0x83);
    }
    else {
      *ptr = param_1;
      iVar1 = OPENSSL_sk_push(cleanup_stack,ptr);
      if (iVar1 < 1) {
        CRYPTO_free(ptr);
        return;
      }
    }
  }
  return;
}



void engine_cleanup_add_last(undefined4 param_1)

{
  undefined4 *data;
  
  if (cleanup_stack == (_STACK *)0x0) {
    cleanup_stack = sk_new_null();
    if (cleanup_stack == (_STACK *)0x0) {
      return;
    }
  }
  data = (undefined4 *)CRYPTO_malloc(4,"eng_lib.c",0xa8);
  if (data != (undefined4 *)0x0) {
    *data = param_1;
    sk_push(cleanup_stack,data);
    return;
  }
  return;
}


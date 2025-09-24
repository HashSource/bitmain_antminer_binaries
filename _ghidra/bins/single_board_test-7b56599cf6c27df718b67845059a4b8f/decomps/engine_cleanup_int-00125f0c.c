
void engine_cleanup_int(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (cleanup_stack != 0) {
    OPENSSL_sk_pop_free(cleanup_stack,0x125cb1,param_3,param_4,param_4);
    cleanup_stack = 0;
  }
  CRYPTO_THREAD_lock_free(global_engine_lock);
  global_engine_lock = 0;
  return;
}


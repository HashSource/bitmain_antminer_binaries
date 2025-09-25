
void engine_table_unregister(int *param_1,undefined4 param_2)

{
  CRYPTO_THREAD_write_lock(global_engine_lock);
  if (*param_1 != 0) {
    OPENSSL_LH_doall_arg(*param_1,0x1aef0d,param_2);
  }
  CRYPTO_THREAD_unlock(global_engine_lock);
  return;
}


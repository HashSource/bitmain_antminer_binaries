
void engine_table_cleanup(int *param_1)

{
  CRYPTO_THREAD_write_lock(global_engine_lock);
  if (*param_1 != 0) {
    OPENSSL_LH_doall(*param_1,0x1bcd09);
    OPENSSL_LH_free(*param_1);
    *param_1 = 0;
  }
  CRYPTO_THREAD_unlock(global_engine_lock);
  return;
}


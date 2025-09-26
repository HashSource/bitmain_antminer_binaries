
void err_cleanup(void)

{
  if (set_err_thread_local != 0) {
    CRYPTO_THREAD_cleanup_local(&err_thread_local);
  }
  CRYPTO_THREAD_lock_free(err_string_lock);
  err_string_lock = 0;
  OPENSSL_LH_free(int_error_hash);
  int_error_hash = 0;
  return;
}


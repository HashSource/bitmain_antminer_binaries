
void err_do_init_ossl_(void)

{
  set_err_thread_local = 1;
  err_do_init_ossl_ret_ = CRYPTO_THREAD_init_local(&err_thread_local,0);
  return;
}


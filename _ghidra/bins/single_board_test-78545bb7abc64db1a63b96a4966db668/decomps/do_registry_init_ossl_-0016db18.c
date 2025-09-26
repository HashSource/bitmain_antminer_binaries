
void do_registry_init_ossl_(void)

{
  registry_lock = CRYPTO_THREAD_lock_new();
  do_registry_init_ossl_ret_ = registry_lock;
  if (registry_lock != 0) {
    do_registry_init_ossl_ret_ = 1;
  }
  return;
}


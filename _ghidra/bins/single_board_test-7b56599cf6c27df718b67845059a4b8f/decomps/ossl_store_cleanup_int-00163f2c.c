
void ossl_store_cleanup_int(void)

{
  OPENSSL_LH_free(loader_register);
  loader_register = 0;
  CRYPTO_THREAD_lock_free(registry_lock);
  registry_lock = 0;
  return;
}


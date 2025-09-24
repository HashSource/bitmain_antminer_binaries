
void bio_cleanup(void)

{
  bio_sock_cleanup_int();
  CRYPTO_THREAD_lock_free(bio_lookup_lock);
  bio_lookup_lock = 0;
  CRYPTO_THREAD_lock_free(bio_type_lock);
  bio_type_lock = 0;
  return;
}


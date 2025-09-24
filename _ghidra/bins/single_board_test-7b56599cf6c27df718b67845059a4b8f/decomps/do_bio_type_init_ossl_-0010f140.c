
void do_bio_type_init_ossl_(void)

{
  bio_type_lock = CRYPTO_THREAD_lock_new();
  do_bio_type_init_ossl_ret_ = bio_type_lock;
  if (bio_type_lock != 0) {
    do_bio_type_init_ossl_ret_ = 1;
  }
  return;
}



void rand_drbg_cleanup_int(void)

{
  if (master_drbg != 0) {
    RAND_DRBG_free();
    master_drbg = 0;
    CRYPTO_THREAD_cleanup_local(&private_drbg);
    CRYPTO_THREAD_cleanup_local(&public_drbg);
    return;
  }
  return;
}



void CRYPTO_THREAD_lock_free(pthread_rwlock_t *param_1)

{
  if (param_1 != (pthread_rwlock_t *)0x0) {
    pthread_rwlock_destroy(param_1);
    CRYPTO_free(param_1);
    return;
  }
  return;
}



pthread_rwlock_t * CRYPTO_THREAD_lock_new(void)

{
  pthread_rwlock_t *__rwlock;
  int iVar1;
  undefined4 in_r3;
  
  __rwlock = (pthread_rwlock_t *)CRYPTO_zalloc(0x20,"crypto/threads_pthread.c",0x1d,in_r3,in_r3);
  if (__rwlock != (pthread_rwlock_t *)0x0) {
    iVar1 = pthread_rwlock_init(__rwlock,(pthread_rwlockattr_t *)0x0);
    if (iVar1 == 0) {
      return __rwlock;
    }
    CRYPTO_free(__rwlock);
  }
  return (pthread_rwlock_t *)0x0;
}


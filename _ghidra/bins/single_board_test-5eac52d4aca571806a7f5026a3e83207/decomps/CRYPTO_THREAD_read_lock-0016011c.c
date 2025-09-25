
bool CRYPTO_THREAD_read_lock(pthread_rwlock_t *param_1)

{
  int iVar1;
  
  iVar1 = pthread_rwlock_rdlock(param_1);
  return iVar1 == 0;
}


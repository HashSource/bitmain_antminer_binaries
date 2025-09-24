
bool CRYPTO_THREAD_write_lock(pthread_rwlock_t *param_1)

{
  int iVar1;
  
  iVar1 = pthread_rwlock_wrlock(param_1);
  return iVar1 == 0;
}



bool CRYPTO_THREAD_unlock(pthread_rwlock_t *param_1)

{
  int iVar1;
  
  iVar1 = pthread_rwlock_unlock(param_1);
  return iVar1 == 0;
}


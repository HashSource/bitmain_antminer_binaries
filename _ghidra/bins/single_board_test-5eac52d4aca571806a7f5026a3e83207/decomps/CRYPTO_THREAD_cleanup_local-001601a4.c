
bool CRYPTO_THREAD_cleanup_local(pthread_key_t *param_1)

{
  int iVar1;
  
  iVar1 = pthread_key_delete(*param_1);
  return iVar1 == 0;
}


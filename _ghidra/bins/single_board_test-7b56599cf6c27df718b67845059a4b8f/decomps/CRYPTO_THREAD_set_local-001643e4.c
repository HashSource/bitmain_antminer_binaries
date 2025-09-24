
bool CRYPTO_THREAD_set_local(pthread_key_t *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = pthread_setspecific(*param_1,param_2);
  return iVar1 == 0;
}


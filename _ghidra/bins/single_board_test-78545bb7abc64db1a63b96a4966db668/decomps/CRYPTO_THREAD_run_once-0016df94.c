
bool CRYPTO_THREAD_run_once(pthread_once_t *param_1,__init_routine *param_2)

{
  int iVar1;
  
  iVar1 = pthread_once(param_1,param_2);
  return iVar1 == 0;
}


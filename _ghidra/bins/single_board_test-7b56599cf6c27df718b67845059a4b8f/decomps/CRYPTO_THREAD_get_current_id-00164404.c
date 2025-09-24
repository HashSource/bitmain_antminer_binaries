
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

pthread_t CRYPTO_THREAD_get_current_id(void)

{
  pthread_t pVar1;
  
  pVar1 = pthread_self();
  return pVar1;
}


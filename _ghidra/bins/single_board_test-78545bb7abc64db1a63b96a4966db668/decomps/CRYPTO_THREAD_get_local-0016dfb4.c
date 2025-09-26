
void CRYPTO_THREAD_get_local(pthread_key_t *param_1)

{
  pthread_getspecific(*param_1);
  return;
}


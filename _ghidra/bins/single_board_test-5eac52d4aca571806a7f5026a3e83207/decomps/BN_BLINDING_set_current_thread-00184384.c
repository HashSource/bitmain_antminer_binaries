
void BN_BLINDING_set_current_thread(int param_1)

{
  pthread_t pVar1;
  
  pVar1 = CRYPTO_THREAD_get_current_id();
  *(pthread_t *)(param_1 + 0x10) = pVar1;
  return;
}



void BN_BLINDING_is_current_thread(int param_1)

{
  pthread_t pVar1;
  
  pVar1 = CRYPTO_THREAD_get_current_id();
  CRYPTO_THREAD_compare_id(pVar1,*(undefined4 *)(param_1 + 0x10));
  return;
}


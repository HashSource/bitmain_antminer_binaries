
void drbg_delete_thread_state(void)

{
  undefined4 uVar1;
  
  uVar1 = CRYPTO_THREAD_get_local(&public_drbg);
  CRYPTO_THREAD_set_local(&public_drbg,0);
  RAND_DRBG_free(uVar1);
  uVar1 = CRYPTO_THREAD_get_local(&private_drbg);
  CRYPTO_THREAD_set_local(&private_drbg,0);
  RAND_DRBG_free(uVar1);
  return;
}


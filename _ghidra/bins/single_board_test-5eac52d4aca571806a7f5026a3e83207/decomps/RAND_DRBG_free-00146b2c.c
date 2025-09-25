
void RAND_DRBG_free(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if (param_1[0x3c] != 0) {
    (**(code **)(param_1[0x3c] + 0xc))();
  }
  rand_pool_free(param_1[7]);
  CRYPTO_THREAD_lock_free(*param_1);
  CRYPTO_free_ex_data(0xf,param_1,(CRYPTO_EX_DATA *)(param_1 + 0x18));
  if (param_1[2] == 0) {
    CRYPTO_clear_free(param_1,0x104,"crypto/rand/drbg_lib.c",0x115);
    return;
  }
  CRYPTO_secure_clear_free(param_1,0x104,"crypto/rand/drbg_lib.c",0x113);
  return;
}


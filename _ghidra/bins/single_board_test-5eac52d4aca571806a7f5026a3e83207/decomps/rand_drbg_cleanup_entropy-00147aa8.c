
void rand_drbg_cleanup_entropy(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    return;
  }
  if (*(int *)(param_1 + 8) == 0) {
    CRYPTO_clear_free(param_2,param_3,"crypto/rand/rand_lib.c",0xe1);
    return;
  }
  CRYPTO_secure_clear_free(param_2,param_3,"crypto/rand/rand_lib.c",0xdf);
  return;
}


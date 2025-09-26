
void rand_pool_free(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if (param_1[2] == 0) {
      if (param_1[3] == 0) {
        CRYPTO_clear_free(*param_1,param_1[6],"crypto/rand/rand_lib.c",0x210);
      }
      else {
        CRYPTO_secure_clear_free(*param_1,param_1[6],"crypto/rand/rand_lib.c",0x20e);
      }
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}


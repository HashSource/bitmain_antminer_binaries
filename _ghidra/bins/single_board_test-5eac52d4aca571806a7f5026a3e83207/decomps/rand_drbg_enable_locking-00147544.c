
undefined4 rand_drbg_enable_locking(int *param_1)

{
  int iVar1;
  
  if (param_1[0x17] != 0) {
    ERR_put_error(0x24,0x77,0x81,"crypto/rand/drbg_lib.c",0x32c);
    return 0;
  }
  if (*param_1 == 0) {
    if (((int *)param_1[1] != (int *)0x0) && (*(int *)param_1[1] == 0)) {
      ERR_put_error(0x24,0x77,0x82,"crypto/rand/drbg_lib.c",0x333);
      return 0;
    }
    iVar1 = CRYPTO_THREAD_lock_new();
    *param_1 = iVar1;
    if (iVar1 == 0) {
      ERR_put_error(0x24,0x77,0x7e,"crypto/rand/drbg_lib.c",0x33a);
      return 0;
    }
  }
  return 1;
}



undefined4 rand_drbg_unlock(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 != 0) {
    uVar1 = CRYPTO_THREAD_unlock();
    return uVar1;
  }
  return 1;
}


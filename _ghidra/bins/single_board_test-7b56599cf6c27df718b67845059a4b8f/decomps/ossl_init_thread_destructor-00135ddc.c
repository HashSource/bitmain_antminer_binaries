
void ossl_init_thread_destructor(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      iVar1 = param_1[1];
    }
    else {
      async_delete_thread_state();
      iVar1 = param_1[1];
    }
    if (iVar1 == 0) {
      iVar1 = param_1[2];
    }
    else {
      err_delete_thread_state();
      iVar1 = param_1[2];
    }
    if (iVar1 != 0) {
      drbg_delete_thread_state();
    }
    CRYPTO_free(param_1);
    return;
  }
  return;
}


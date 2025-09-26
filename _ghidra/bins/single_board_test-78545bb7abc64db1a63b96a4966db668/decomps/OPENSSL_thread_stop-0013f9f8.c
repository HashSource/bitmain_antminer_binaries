
void OPENSSL_thread_stop(void)

{
  int *ptr;
  int iVar1;
  
  if (destructor_key != -1) {
    ptr = (int *)CRYPTO_THREAD_get_local(&destructor_key);
    CRYPTO_THREAD_set_local(&destructor_key,0);
    if (ptr != (int *)0x0) {
      if (*ptr == 0) {
        iVar1 = ptr[1];
      }
      else {
        async_delete_thread_state();
        iVar1 = ptr[1];
      }
      if (iVar1 == 0) {
        iVar1 = ptr[2];
      }
      else {
        err_delete_thread_state();
        iVar1 = ptr[2];
      }
      if (iVar1 != 0) {
        drbg_delete_thread_state();
      }
      CRYPTO_free(ptr);
      return;
    }
  }
  return;
}


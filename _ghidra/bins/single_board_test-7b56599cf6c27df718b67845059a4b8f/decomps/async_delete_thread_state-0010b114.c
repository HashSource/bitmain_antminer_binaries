
void async_delete_thread_state(void)

{
  int *ptr;
  int iVar1;
  void *pvVar2;
  
  ptr = (int *)CRYPTO_THREAD_get_local(&poolkey);
  if (ptr != (int *)0x0) {
    iVar1 = *ptr;
    if (iVar1 != 0) {
      pvVar2 = (void *)OPENSSL_sk_pop();
      while (pvVar2 != (void *)0x0) {
        CRYPTO_free(*(void **)((int)pvVar2 + 8));
        CRYPTO_free(pvVar2);
        pvVar2 = (void *)OPENSSL_sk_pop(*ptr);
      }
      iVar1 = *ptr;
    }
    OPENSSL_sk_free(iVar1);
    CRYPTO_free(ptr);
    CRYPTO_THREAD_set_local(&poolkey,0);
  }
  async_local_cleanup();
  pvVar2 = (void *)async_get_ctx();
  iVar1 = CRYPTO_THREAD_set_local(&ctxkey,0);
  if (iVar1 != 0) {
    CRYPTO_free(pvVar2);
    return;
  }
  return;
}


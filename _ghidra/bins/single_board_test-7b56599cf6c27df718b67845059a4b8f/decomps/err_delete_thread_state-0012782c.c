
void err_delete_thread_state(void)

{
  void *ptr;
  
  ptr = (void *)CRYPTO_THREAD_get_local(&err_thread_local);
  if (ptr != (void *)0x0) {
    CRYPTO_THREAD_set_local(&err_thread_local,0);
    if (*(int *)((int)ptr + 0xc0) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x80));
      *(undefined4 *)((int)ptr + 0x80) = 0;
    }
    *(undefined4 *)((int)ptr + 0xc0) = 0;
    if (*(int *)((int)ptr + 0xc4) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x84));
      *(undefined4 *)((int)ptr + 0x84) = 0;
    }
    *(undefined4 *)((int)ptr + 0xc4) = 0;
    if (*(int *)((int)ptr + 200) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x88));
      *(undefined4 *)((int)ptr + 0x88) = 0;
    }
    *(undefined4 *)((int)ptr + 200) = 0;
    if (*(int *)((int)ptr + 0xcc) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x8c));
      *(undefined4 *)((int)ptr + 0x8c) = 0;
    }
    *(undefined4 *)((int)ptr + 0xcc) = 0;
    if (*(int *)((int)ptr + 0xd0) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x90));
      *(undefined4 *)((int)ptr + 0x90) = 0;
    }
    *(undefined4 *)((int)ptr + 0xd0) = 0;
    if (*(int *)((int)ptr + 0xd4) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x94));
      *(undefined4 *)((int)ptr + 0x94) = 0;
    }
    *(undefined4 *)((int)ptr + 0xd4) = 0;
    if (*(int *)((int)ptr + 0xd8) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x98));
      *(undefined4 *)((int)ptr + 0x98) = 0;
    }
    *(undefined4 *)((int)ptr + 0xd8) = 0;
    if (*(int *)((int)ptr + 0xdc) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0x9c));
      *(undefined4 *)((int)ptr + 0x9c) = 0;
    }
    *(undefined4 *)((int)ptr + 0xdc) = 0;
    if (*(int *)((int)ptr + 0xe0) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xa0));
      *(undefined4 *)((int)ptr + 0xa0) = 0;
    }
    *(undefined4 *)((int)ptr + 0xe0) = 0;
    if (*(int *)((int)ptr + 0xe4) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xa4));
      *(undefined4 *)((int)ptr + 0xa4) = 0;
    }
    *(undefined4 *)((int)ptr + 0xe4) = 0;
    if (*(int *)((int)ptr + 0xe8) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xa8));
      *(undefined4 *)((int)ptr + 0xa8) = 0;
    }
    *(undefined4 *)((int)ptr + 0xe8) = 0;
    if (*(int *)((int)ptr + 0xec) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xac));
      *(undefined4 *)((int)ptr + 0xac) = 0;
    }
    *(undefined4 *)((int)ptr + 0xec) = 0;
    if (*(int *)((int)ptr + 0xf0) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xb0));
      *(undefined4 *)((int)ptr + 0xb0) = 0;
    }
    *(undefined4 *)((int)ptr + 0xf0) = 0;
    if (*(int *)((int)ptr + 0xf4) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xb4));
      *(undefined4 *)((int)ptr + 0xb4) = 0;
    }
    *(undefined4 *)((int)ptr + 0xf4) = 0;
    if (*(int *)((int)ptr + 0xf8) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xb8));
      *(undefined4 *)((int)ptr + 0xb8) = 0;
    }
    *(undefined4 *)((int)ptr + 0xf8) = 0;
    if (*(int *)((int)ptr + 0xfc) << 0x1f < 0) {
      CRYPTO_free(*(void **)((int)ptr + 0xbc));
      *(undefined4 *)((int)ptr + 0xbc) = 0;
    }
    *(undefined4 *)((int)ptr + 0xfc) = 0;
    CRYPTO_free(ptr);
    return;
  }
  return;
}


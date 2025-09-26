
void async_wait_ctx_reset_counts(undefined4 *param_1)

{
  void *ptr;
  void *pvVar1;
  void *pvVar2;
  
  param_1[1] = 0;
  param_1[2] = 0;
  pvVar2 = (void *)*param_1;
  pvVar1 = (void *)0x0;
  while (ptr = pvVar2, ptr != (void *)0x0) {
    if (*(int *)((int)ptr + 0x14) == 0) {
      if (*(int *)((int)ptr + 0x10) != 0) {
        *(undefined4 *)((int)ptr + 0x10) = 0;
      }
      pvVar2 = *(void **)((int)ptr + 0x18);
      pvVar1 = ptr;
    }
    else if (pvVar1 == (void *)0x0) {
      *param_1 = *(undefined4 *)((int)ptr + 0x18);
      CRYPTO_free(ptr);
      pvVar2 = (void *)*param_1;
    }
    else {
      *(undefined4 *)((int)pvVar1 + 0x18) = *(undefined4 *)((int)ptr + 0x18);
      CRYPTO_free(ptr);
      pvVar2 = *(void **)((int)pvVar1 + 0x18);
    }
  }
  return;
}


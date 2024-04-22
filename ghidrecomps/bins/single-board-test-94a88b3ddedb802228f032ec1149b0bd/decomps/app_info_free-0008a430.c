
void app_info_free(void *param_1)

{
  int iVar1;
  void *ptr;
  
  iVar1 = *(int *)((int)param_1 + 0x18) + -1;
  *(int *)((int)param_1 + 0x18) = iVar1;
  if (0 < iVar1) {
    return;
  }
  ptr = *(void **)((int)param_1 + 0x14);
  if (ptr != (void *)0x0) {
    iVar1 = *(int *)((int)ptr + 0x18) + -1;
    *(int *)((int)ptr + 0x18) = iVar1;
    if (iVar1 < 1) {
      if (*(int *)((int)ptr + 0x14) != 0) {
        app_info_free();
      }
      CRYPTO_free(ptr);
    }
  }
  CRYPTO_free(param_1);
  return;
}


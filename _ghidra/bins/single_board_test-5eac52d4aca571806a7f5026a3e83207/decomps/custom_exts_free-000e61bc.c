
void custom_exts_free(undefined4 *param_1)

{
  uint uVar1;
  void *ptr;
  uint uVar2;
  
  uVar1 = param_1[1];
  ptr = (void *)*param_1;
  if (uVar1 != 0) {
    uVar2 = 0;
    do {
      uVar2 = uVar2 + 1;
      HintPreloadData((int)ptr + 0xe8);
      if (*(int *)((int)ptr + 0x10) == 0xe5e81) {
        CRYPTO_free(*(void **)((int)ptr + 0x18));
        CRYPTO_free(*(void **)((int)ptr + 0x20));
        uVar1 = param_1[1];
      }
      ptr = (void *)((int)ptr + 0x24);
    } while (uVar2 < uVar1);
    ptr = (void *)*param_1;
  }
  CRYPTO_free(ptr);
  return;
}


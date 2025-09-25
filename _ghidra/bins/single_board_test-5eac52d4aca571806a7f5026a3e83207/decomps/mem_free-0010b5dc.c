
undefined4 mem_free(int param_1)

{
  BUF_MEM *a;
  char *pcVar1;
  undefined4 *ptr;
  bool bVar2;
  
  if (param_1 != 0) {
    ptr = *(undefined4 **)(param_1 + 0x24);
    if ((*(int *)(param_1 + 0x14) != 0) &&
       (*(int *)(param_1 + 0x10) != 0 && ptr != (undefined4 *)0x0)) {
      a = (BUF_MEM *)*ptr;
      pcVar1 = (char *)(*(int *)(param_1 + 0x18) << 0x16);
      bVar2 = (int)pcVar1 < 0;
      if (bVar2) {
        pcVar1 = (char *)0x0;
      }
      if (bVar2) {
        a->data = pcVar1;
      }
      BUF_MEM_free(a);
    }
    CRYPTO_free((void *)ptr[1]);
    CRYPTO_free(ptr);
    return 1;
  }
  return 0;
}


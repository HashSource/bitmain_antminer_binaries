
void WPACKET_cleanup(int param_1)

{
  undefined4 *ptr;
  void *pvVar1;
  
  ptr = (undefined4 *)*(void **)(param_1 + 0x14);
  while (ptr != (undefined4 *)0x0) {
    pvVar1 = (void *)*ptr;
    CRYPTO_free(ptr);
    ptr = (undefined4 *)pvVar1;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


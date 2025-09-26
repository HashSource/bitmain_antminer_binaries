
void free_dir(int param_1)

{
  undefined4 *ptr;
  
  ptr = *(undefined4 **)(param_1 + 0xc);
  if ((_STACK *)ptr[1] != (_STACK *)0x0) {
    sk_pop_free((_STACK *)ptr[1],(func *)0x163bc1);
  }
  if ((BUF_MEM *)*ptr != (BUF_MEM *)0x0) {
    BUF_MEM_free((BUF_MEM *)*ptr);
  }
  CRYPTO_free(ptr);
  return;
}


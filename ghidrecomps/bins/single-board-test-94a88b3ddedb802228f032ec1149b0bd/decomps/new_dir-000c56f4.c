
undefined4 new_dir(int param_1)

{
  BUF_MEM **ptr;
  BUF_MEM *pBVar1;
  
  ptr = (BUF_MEM **)CRYPTO_malloc(8,DAT_000c5728,0x97);
  if (ptr == (BUF_MEM **)0x0) {
    return 0;
  }
  pBVar1 = BUF_MEM_new();
  *ptr = pBVar1;
  if (pBVar1 != (BUF_MEM *)0x0) {
    ptr[1] = (BUF_MEM *)0x0;
    *(BUF_MEM ***)(param_1 + 0xc) = ptr;
    return 1;
  }
  CRYPTO_free(ptr);
  return 0;
}


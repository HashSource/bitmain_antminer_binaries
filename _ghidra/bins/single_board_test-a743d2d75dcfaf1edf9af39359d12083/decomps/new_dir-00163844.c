
undefined4 new_dir(int param_1)

{
  undefined4 *ptr;
  BUF_MEM *pBVar1;
  
  ptr = (undefined4 *)CRYPTO_malloc(8,"by_dir.c",0x97);
  if (ptr == (undefined4 *)0x0) {
    return 0;
  }
  pBVar1 = BUF_MEM_new();
  *ptr = pBVar1;
  if (pBVar1 != (BUF_MEM *)0x0) {
    ptr[1] = 0;
    *(undefined4 **)(param_1 + 0xc) = ptr;
    return 1;
  }
  CRYPTO_free(ptr);
  return 0;
}


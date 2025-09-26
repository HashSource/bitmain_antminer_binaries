
uint ecx_pub_cmp(int param_1,int param_2)

{
  int iVar1;
  size_t len;
  
  if (*(void **)(param_2 + 0x18) == (void *)0x0 || *(void **)(param_1 + 0x18) == (void *)0x0) {
    return 0xfffffffe;
  }
  iVar1 = **(int **)(param_1 + 0xc);
  if (iVar1 == 0x40a || iVar1 == 0x43f) {
    len = 0x20;
  }
  else if (iVar1 == 0x40b) {
    len = 0x38;
  }
  else {
    len = 0x39;
  }
  iVar1 = CRYPTO_memcmp(*(void **)(param_1 + 0x18),*(void **)(param_2 + 0x18),len);
  return (uint)(iVar1 == 0);
}


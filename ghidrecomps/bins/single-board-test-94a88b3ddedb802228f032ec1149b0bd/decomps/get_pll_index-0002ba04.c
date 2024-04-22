
uint get_pll_index(undefined4 param_1)

{
  size_t __n;
  int iVar1;
  void *__s1;
  char acStack_20 [12];
  uint local_14;
  
  sprintf(acStack_20,"%d",param_1);
  for (local_14 = 0; local_14 < lenghth_of_freq_pll_1385; local_14 = local_14 + 1) {
    __s1 = *(void **)(freq_pll_1385 + local_14 * 0x10);
    __n = strlen(*(char **)(freq_pll_1385 + local_14 * 0x10));
    iVar1 = memcmp(__s1,acStack_20,__n);
    if (iVar1 == 0) break;
  }
  if (local_14 == lenghth_of_freq_pll_1385) {
    local_14 = 0xffffffff;
  }
  return local_14;
}



uint get_plldata_i(int param_1,undefined4 param_2)

{
  size_t __n;
  int iVar1;
  void *__s1;
  char acStack_20 [12];
  uint local_14;
  
  sprintf(acStack_20,"%d",param_2);
  if ((param_1 == 0x569) || (param_1 == 0x56b)) {
    for (local_14 = 0; local_14 < lenghth_of_freq_pll_1385; local_14 = local_14 + 1) {
      __s1 = *(void **)(freq_pll_1385 + local_14 * 0x10);
      __n = strlen(*(char **)(freq_pll_1385 + local_14 * 0x10));
      iVar1 = memcmp(__s1,acStack_20,__n);
      if (iVar1 == 0) break;
    }
  }
  if (local_14 == lenghth_of_freq_pll_1385) {
    puts("Freq set Err!!!!");
    puts("Using 200M");
    local_14 = 4;
  }
  return local_14;
}


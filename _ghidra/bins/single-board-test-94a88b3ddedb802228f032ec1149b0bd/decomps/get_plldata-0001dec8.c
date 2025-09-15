
void get_plldata(int param_1,undefined4 param_2,undefined4 *param_3,ushort *param_4,
                undefined4 *param_5)

{
  size_t __n;
  int iVar1;
  void *__s1;
  char acStack_80 [32];
  char acStack_60 [32];
  char acStack_40 [32];
  char acStack_20 [12];
  uint local_14;
  
  sprintf(acStack_20,"%d",param_2);
  memset(acStack_40,0,0x20);
  memset(acStack_60,0,0x20);
  memset(acStack_80,0,0x20);
  if ((param_1 == 0x569) || (param_1 == 0x56b)) {
    for (local_14 = 0; local_14 < 0x6a; local_14 = local_14 + 1) {
      __s1 = *(void **)(freq_pll_1385 + local_14 * 0x10);
      __n = strlen(*(char **)(freq_pll_1385 + local_14 * 0x10));
      iVar1 = memcmp(__s1,acStack_20,__n);
      if (iVar1 == 0) break;
    }
  }
  if (local_14 == 0x6a) {
    puts("Freq set Err!!!!");
    puts("Using 200M");
    local_14 = 4;
  }
  sprintf(acStack_40,"%08x",*(undefined4 *)(freq_pll_1385 + local_14 * 0x10 + 4));
  sprintf(acStack_60,"%04x",*(undefined4 *)(freq_pll_1385 + local_14 * 0x10 + 8));
  sprintf(acStack_80,"%04x",*(undefined4 *)(freq_pll_1385 + local_14 * 0x10 + 0xc));
  printf("Freq %s, PLL1 %s, PLL2 %s, vilpll %s\n",acStack_20,acStack_40,acStack_60,acStack_80);
  *param_3 = *(undefined4 *)(freq_pll_1385 + local_14 * 0x10 + 4);
  *param_4 = (ushort)*(undefined4 *)(freq_pll_1385 + local_14 * 0x10 + 8);
  *param_5 = *(undefined4 *)(freq_pll_1385 + local_14 * 0x10 + 0xc);
  printf("PLL1 %#x, PLL2 %#x, vilpll %#x\n",*param_3,(uint)*param_4,*param_5);
  return;
}


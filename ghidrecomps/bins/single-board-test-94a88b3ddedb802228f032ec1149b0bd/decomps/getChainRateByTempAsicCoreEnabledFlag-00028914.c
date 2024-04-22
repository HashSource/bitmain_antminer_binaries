
int getChainRateByTempAsicCoreEnabledFlag(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = atoi(*(char **)(freq_pll_1385 + param_2 * 0x10));
  iVar2 = getChainTempBadCoreNum(param_1);
  return ((0x2568 - iVar2) * iVar1) / 1000;
}



int getBoardRateByTempResult(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  
  iVar1 = atoi(*(char **)(freq_pll_1385 + param_2 * 0x10));
  local_18 = 0;
  for (local_14 = 0; local_14 < 0x54; local_14 = local_14 + 1) {
    iVar2 = getChainAsicTempBadCoreNum(param_1,local_14);
    if (iVar2 < 0xf) {
      local_18 = iVar1 * (0x72 - iVar2) + local_18;
    }
  }
  return local_18 / 1000;
}



int GetBoardRate(int param_1)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  
  local_18 = 0;
  if (0 < *(int *)(last_success_freq + param_1 * 0x400)) {
    for (local_14 = 0; local_14 < 0x54; local_14 = local_14 + 1) {
      iVar1 = atoi(*(char **)(freq_pll_1385 +
                             *(int *)(last_success_freq + (local_14 + param_1 * 0x100) * 4) * 0x10))
      ;
      iVar2 = getChainAsicGoodCoreNum(param_1,local_14);
      local_18 = iVar2 * iVar1 + local_18;
    }
  }
  return local_18 / 1000;
}



int getBoardRateByHighestRateRecord(int param_1)

{
  int iVar1;
  int iVar2;
  int local_18;
  int local_14;
  
  local_18 = 0;
  if (*(int *)(highest_rate_voltage_value + param_1 * 4) < 1) {
    local_18 = 0;
  }
  else {
    iVar1 = atoi(*(char **)(freq_pll_1385 + *(int *)(highest_rate_freq + param_1 * 4) * 0x10));
    for (local_14 = 0; local_14 < 0x54; local_14 = local_14 + 1) {
      iVar2 = getChainAsicHighestRateRecordBadCoreNum(param_1,local_14);
      if (iVar2 < 0xf) {
        local_18 = iVar1 * (0x72 - iVar2) + local_18;
      }
    }
    local_18 = local_18 / 1000;
  }
  return local_18;
}


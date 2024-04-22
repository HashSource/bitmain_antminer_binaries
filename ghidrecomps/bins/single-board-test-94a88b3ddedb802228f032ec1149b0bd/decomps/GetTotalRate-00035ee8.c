
int GetTotalRate(void)

{
  int iVar1;
  int iVar2;
  int local_1c;
  int local_18;
  int local_14;
  
  local_1c = 0;
  iVar1 = is_S11();
  if (((iVar1 == 0) && (iVar1 = is_S9_Hydro(), iVar1 == 0)) && (iVar1 = is_S9i(), iVar1 == 0)) {
    for (local_14 = 0; local_14 < 0x10; local_14 = local_14 + 1) {
      if (0 < *(int *)(last_success_freq + local_14 * 0x400)) {
        for (local_18 = 0; local_18 < 0x54; local_18 = local_18 + 1) {
          iVar1 = atoi(*(char **)(freq_pll_1385 +
                                 *(int *)(last_success_freq + (local_18 + local_14 * 0x100) * 4) *
                                 0x10));
          iVar2 = getChainAsicGoodCoreNum(local_14,local_18);
          local_1c = iVar2 * iVar1 + local_1c;
        }
      }
    }
    iVar1 = local_1c / 1000;
  }
  else {
    iVar1 = total_hash_rate;
    if (total_hash_rate == 0) {
      iVar1 = get_ideal_rate_from_eeprom();
      total_hash_rate = iVar1;
    }
  }
  return iVar1;
}


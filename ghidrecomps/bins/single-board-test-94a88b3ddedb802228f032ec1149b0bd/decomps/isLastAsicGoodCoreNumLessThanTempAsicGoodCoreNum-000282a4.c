
undefined4 isLastAsicGoodCoreNumLessThanTempAsicGoodCoreNum(int param_1)

{
  undefined4 uVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  local_18 = 0;
  if ((*(int *)(Fmax + param_1 * 4) < 0x56) || (0x379 < *(int *)(chain_vol_value + param_1 * 4))) {
    for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < 0x72; local_10 = local_10 + 1) {
        if (0 < *(int *)(temp_asic_core_enabled_flag +
                        (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4)) {
          local_14 = local_14 + 1;
        }
      }
    }
    for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
      for (local_10 = 0; local_10 < 0x72; local_10 = local_10 + 1) {
        if (0 < *(int *)(last_asic_core_enabled_flag +
                        (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4)) {
          local_18 = local_18 + 1;
        }
      }
    }
    if (local_14 < local_18) {
      uVar1 = 0;
    }
    else {
      SaveAsicCoreEnabledFlagByResultToLastRecord(param_1);
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


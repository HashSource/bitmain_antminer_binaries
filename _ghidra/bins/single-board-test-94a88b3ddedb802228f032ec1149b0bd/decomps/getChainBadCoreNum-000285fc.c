
int getChainBadCoreNum(int param_1)

{
  int local_14;
  int local_10;
  int local_c;
  
  local_14 = 0;
  for (local_c = 0; local_c < 0x54; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < 0x72; local_10 = local_10 + 1) {
      if (*(int *)(asic_core_enabled_flag + (local_10 + (local_c + param_1 * 0x100) * 0x100) * 4) <
          1) {
        local_14 = local_14 + 1;
      }
    }
  }
  return local_14;
}


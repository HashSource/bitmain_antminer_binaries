
int getChainAsicGoodCoreNum(int param_1,int param_2)

{
  int local_10;
  int local_c;
  
  local_10 = 0;
  if (param_2 < 0x54) {
    if (*(int *)(chain_badcore_num + (param_2 + param_1 * 0x100) * 4) < 0xf) {
      for (local_c = 0; local_c < 0x72; local_c = local_c + 1) {
        if (0 < *(int *)(asic_core_enabled_flag +
                        (local_c + (param_2 + param_1 * 0x100) * 0x100) * 4)) {
          local_10 = local_10 + 1;
        }
      }
      local_10 = local_10 - *(int *)(chain_badcore_num + (param_2 + param_1 * 0x100) * 4);
    }
    else {
      local_10 = 0;
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}


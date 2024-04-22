
int getChainBadCoreNumUserMode(int param_1)

{
  int local_10;
  int local_c;
  
  local_c = 0;
  for (local_10 = 0; local_10 < 0x54; local_10 = local_10 + 1) {
    local_c = *(int *)(chain_badcore_num + (local_10 + param_1 * 0x100) * 4) + local_c;
  }
  return local_c;
}


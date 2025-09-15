
int get_min_scan_freq(int param_1)

{
  int iVar1;
  int local_10;
  int local_c;
  
  local_c = 9999;
  for (local_10 = 0; local_10 < 0x10; local_10 = local_10 + 1) {
    if ((*(int *)(cgpu + (local_10 + 0x9c638) * 4) != 0) &&
       (*(int *)(param_1 + (local_10 + 0x15012) * 4) < local_c)) {
      local_c = *(int *)(param_1 + (local_10 + 0x15012) * 4);
    }
  }
  iVar1 = atoi(*(char **)(freq_pll_1385 + local_c * 0x10));
  return iVar1;
}


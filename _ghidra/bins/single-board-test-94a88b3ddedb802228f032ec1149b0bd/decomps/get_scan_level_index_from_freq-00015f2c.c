
int get_scan_level_index_from_freq(int param_1,int param_2,int param_3)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0x13 < local_c) {
      *(int *)(param_3 * 0x50 + param_1 + 0x54088) = param_2;
      return 0;
    }
    if (*(int *)(param_1 + (param_3 * 0x14 + local_c + 0x15022) * 4) == param_2) break;
    if (*(int *)(param_1 + (param_3 * 0x14 + local_c + 0x15022) * 4) == 0) {
      *(int *)(param_1 + (param_3 * 0x14 + local_c + 0x15022) * 4) = param_2;
      return local_c;
    }
    local_c = local_c + 1;
  }
  return local_c;
}


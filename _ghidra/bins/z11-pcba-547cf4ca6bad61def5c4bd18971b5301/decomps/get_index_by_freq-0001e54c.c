
uint get_index_by_freq(int param_1)

{
  uint local_c;
  
  local_c = 0;
  while( true ) {
    if (100 < local_c) {
      return 0xffffffff;
    }
    if (*(int *)(freq_pll + local_c * 0x10) == param_1) break;
    local_c = local_c + 1;
  }
  return local_c;
}


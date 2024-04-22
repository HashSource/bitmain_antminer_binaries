
uint get_freq_pll_index(int param_1)

{
  FILE *__stream;
  int iVar1;
  uint local_c;
  
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: get_freq_pll_index enter freq_value = %d\n","board_frq_tuning.c",
              0x2d0,param_1);
    }
    fclose(__stream);
  }
  local_c = 0;
  while( true ) {
    if (lenghth_of_freq_pll_1385 <= local_c) {
      return 0xffffffff;
    }
    iVar1 = atoi(*(char **)(freq_pll_1385 + local_c * 0x10));
    if (iVar1 == param_1) break;
    local_c = local_c + 1;
  }
  return local_c;
}


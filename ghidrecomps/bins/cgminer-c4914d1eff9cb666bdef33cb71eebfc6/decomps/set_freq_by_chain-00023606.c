
int set_freq_by_chain(float freq,int chain)

{
  FILE *__stream;
  int iVar1;
  int chain_local;
  float freq_local;
  FILE *pFile;
  int local_pll_index;
  
  local_pll_index = 0;
  if (opt_use_pll_list) {
    local_pll_index = get_index_from_high_pll((int)freq);
  }
  if (dev->chain_exist[chain] == 0) {
    iVar1 = 0;
  }
  else {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: chain[%d] set freq:%5.2f\n","driver-btm-soc.c",0x1239,
                "set_freq_by_chain",chain,(double)freq);
      }
      fclose(__stream);
    }
    iVar1 = change_high_pll_test((uint8_t)chain,freq,local_pll_index);
  }
  return iVar1;
}


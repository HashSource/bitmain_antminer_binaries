
int get_index_from_high_pll(int freq)

{
  FILE *__stream;
  int freq_local;
  FILE *pFile;
  int i;
  
  i = 0;
  while ((((uint)i < 0x21 && (freq_high_pll_1393[i].freq != freq)) &&
         ((freq_high_pll_1393[i].freq <= (uint)freq ||
          ((uint)freq <= freq_high_pll_1393[i + -1].freq))))) {
    i = i + 1;
  }
  if (i == 0x21) {
    if (1 < log_level) {
      print_crt_time_to_file(log_file,1);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: high freq index set error,return default pll index\n",
                "driver-btm-soc.c",0x431,"get_index_from_high_pll");
      }
      fclose(__stream);
    }
    i = get_index_from_high_pll(200);
  }
  return i;
}


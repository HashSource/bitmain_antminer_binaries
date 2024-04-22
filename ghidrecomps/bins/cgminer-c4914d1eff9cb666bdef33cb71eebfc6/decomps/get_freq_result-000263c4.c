
void get_freq_result(int default_freq)

{
  _Bool _Var1;
  FILE *__stream;
  int default_freq_local;
  FILE *pFile;
  
  check_chain();
  _Var1 = read_freq_result();
  if (!_Var1) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: scan freq result error, set default freq %dM\n",
                "driver-btm-soc.c",0x171f,"get_freq_result",default_freq);
      }
      fclose(__stream);
    }
    set_freq_default(default_freq);
  }
  return;
}


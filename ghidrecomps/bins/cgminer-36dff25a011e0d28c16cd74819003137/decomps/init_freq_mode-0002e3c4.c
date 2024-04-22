
/* WARNING: Unknown calling convention */

void init_freq_mode(void)

{
  FILE *__stream;
  FILE *pFile;
  
  freq_mode = 2;
  opt_fixed_freq = true;
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: This is fix-freq version\n","driver-btm-soc.c",0x1af4,
              "init_freq_mode");
    }
    fclose(__stream);
  }
  return;
}


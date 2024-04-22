
/* WARNING: Unknown calling convention */

void get_ideal_hash_rate(void)

{
  FILE *__stream;
  FILE *pFile;
  
  g_total_fixed_hashrate = get_fixed_total_hash_rate();
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: get ideal hash rate %d\n","driver-btm-soc.c",0x4ba,
              "get_ideal_hash_rate",g_total_fixed_hashrate);
    }
    fclose(__stream);
  }
  return;
}


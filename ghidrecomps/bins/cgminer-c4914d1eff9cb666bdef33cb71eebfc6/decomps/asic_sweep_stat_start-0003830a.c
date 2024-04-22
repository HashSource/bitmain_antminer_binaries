
/* WARNING: Unknown calling convention */

void asic_sweep_stat_start(void)

{
  FILE *__stream;
  FILE *pFile;
  
  asic_sweep_state = (uint8_t *)malloc(0x9600);
  if (asic_sweep_state == (uint8_t *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: alloc memory failed","freq_scan.c",0xdac,"asic_sweep_stat_start"
               );
      }
      fclose(__stream);
    }
  }
  else {
    memset(asic_sweep_state,0,0x9600);
  }
  return;
}


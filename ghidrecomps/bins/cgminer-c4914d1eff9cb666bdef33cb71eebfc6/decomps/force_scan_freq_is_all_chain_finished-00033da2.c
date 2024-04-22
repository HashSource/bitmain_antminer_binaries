
/* WARNING: Unknown calling convention */

void force_scan_freq_is_all_chain_finished(void)

{
  FILE *__stream;
  FILE *pFile;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    if (dev->chain_exist[i] != 0) {
      scanfreq_info.test_done[i] = true;
    }
  }
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s:  force scan freq finished!\n","freq_scan.c",0x7e0,
              "force_scan_freq_is_all_chain_finished");
    }
    fclose(__stream);
  }
  return;
}


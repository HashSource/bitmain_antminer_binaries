
/* WARNING: Unknown calling convention */

freq_tuning_info * freq_tuning_create_info(void)

{
  freq_tuning_info *freq_info_00;
  FILE *__stream;
  FILE *pFile;
  freq_tuning_info *freq_info;
  
  freq_info_00 = (freq_tuning_info *)
                 _cgmalloc(0x1410c,"freq_tuning.c","freq_tuning_create_info",0x189);
  if (freq_info_00 == (freq_tuning_info *)0x0) {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Fail to alloc memory for freq info.\n","freq_tuning.c",0x18d,
                "freq_tuning_create_info");
      }
      fclose(__stream);
    }
    freq_info_00 = (freq_tuning_info *)0x0;
  }
  else {
    freq_tuning_init_freq_info(freq_info_00);
  }
  return freq_info_00;
}



uint16_t increase_freq_by_eeprom_slowly(int init_freq,int freq_step)

{
  int freq_step_local;
  int init_freq_local;
  uint32_t diff_freq [48];
  uint32_t total;
  uint32_t max;
  uint32_t min;
  FILE *pFile;
  int asic;
  int chain;
  uint32_t total_all;
  
  max = 0;
  total_all = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      min = 0xffffff;
      max = 0;
      total = 0;
      get_statistics_of_asic_freq(scan_result[chain].freq_eeprom,&min,&max,&total);
      for (asic = 0; asic < 0x30; asic = asic + 1) {
        diff_freq[asic] = scan_result[chain].freq_eeprom[asic] - min;
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          fprintf((FILE *)pFile,"%s:%d:%s: Increase eeprom frequency slowly for chain %d. to %u\n",
                  "driver-btm-soc.c",0x188b,"increase_freq_by_eeprom_slowly",chain,min);
        }
        fclose((FILE *)pFile);
      }
      increase_freq_slowly
                ((float)(longlong)init_freq,(float)(ulonglong)min,(float)(longlong)freq_step,
                 (uint8_t)chain);
      if (min != max) {
        increase_asic_diff_freq_slowly_one_chain(diff_freq,min,freq_step,chain);
      }
      scan_freq_average[chain] = total / 0x30;
      total_all = total_all + total;
    }
  }
  total_freq = total_all;
  return (uint16_t)max;
}


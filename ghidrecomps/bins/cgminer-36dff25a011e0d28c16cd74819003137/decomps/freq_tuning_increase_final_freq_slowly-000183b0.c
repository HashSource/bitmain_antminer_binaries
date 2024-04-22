
void freq_tuning_increase_final_freq_slowly(freq_tuning_info *freq_info,int init_freq,int freq_step)

{
  int freq_step_local;
  int init_freq_local;
  freq_tuning_info *freq_info_local;
  uint32_t diff_freq [48];
  uint32_t total;
  uint32_t max;
  uint32_t min;
  FILE *pFile_1;
  FILE *pFile;
  int asic;
  int chain;
  
  min = 0;
  max = 0;
  total = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFile = (FILE *)fopen(log_file,"a+");
        if (pFile != (FILE *)0x0) {
          fprintf((FILE *)pFile,"%s:%d:%s: Increase ideal frequency slowly for chain %d.\n",
                  "freq_tuning.c",0x659,"freq_tuning_increase_final_freq_slowly",chain);
        }
        fclose((FILE *)pFile);
      }
      min = 0xffffff;
      max = 0;
      total = 0;
      get_statistics_of_asic_freq((uint32_t *)(freq_info->freq_table + chain),&min,&max,&total);
      for (asic = 0; asic < 0x30; asic = asic + 1) {
        diff_freq[asic] = freq_info->freq_table[chain][asic] - min;
      }
      increase_freq_slowly
                ((float)(longlong)init_freq,(float)(ulonglong)min,(float)(longlong)freq_step,
                 (uint8_t)chain);
      if ((min != max) &&
         (increase_asic_diff_freq_slowly_one_chain(diff_freq,min,freq_step,chain), 3 < log_level)) {
        print_crt_time_to_file(log_file,3);
        pFile_1 = (FILE *)fopen(log_file,"a+");
        if (pFile_1 != (FILE *)0x0) {
          fprintf((FILE *)pFile_1,"%s:%d:%s: \n\nIncrease frequency to max %dM\n","freq_tuning.c",
                  0x670,"freq_tuning_increase_final_freq_slowly",max);
        }
        fclose((FILE *)pFile_1);
      }
    }
  }
  return;
}


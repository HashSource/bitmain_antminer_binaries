
void freq_tuning_adjust_result_for_high_temperature(freq_tuning_info *freq_info,int sub_proj_index)

{
  FILE *pFVar1;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  FILE *pFile_1;
  int freq_threshold_1;
  int freq_threshold_0_3;
  int freq_threshold;
  int asic;
  int chain;
  
  if ((g_BHB91602_proj.proj_type == 1) &&
     (g_BHB91602_proj.conf_list[sub_proj_index].proj_sub_type == 1)) {
    for (chain = 0; chain < 0x10; chain = chain + 1) {
      if (dev->chain_exist[chain] != 0) {
        if ((chain == 0) || (chain == 3)) {
          freq_threshold = 400;
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,
                      "%s:%d:%s: Adjust chain %d frequency <= %dM at high hash rate for S15 due to high temperature.\n"
                      ,"freq_tuning.c",0x8d2,"freq_tuning_adjust_result_for_high_temperature",chain,
                      400);
            }
            fclose(pFVar1);
          }
        }
        else {
          if (chain != 1) goto LAB_0001a5dc;
          freq_threshold = 0x186;
          if (3 < log_level) {
            print_crt_time_to_file(log_file,3);
            pFVar1 = fopen(log_file,"a+");
            if (pFVar1 != (FILE *)0x0) {
              fprintf(pFVar1,
                      "%s:%d:%s: Adjust chain %d frequency <= %dM at high hash rate for S15 due to high temperature.\n"
                      ,"freq_tuning.c",0x8d7,"freq_tuning_adjust_result_for_high_temperature",1,
                      0x186);
            }
            fclose(pFVar1);
          }
        }
        for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
          if (freq_threshold < freq_info->freq_table[chain][asic]) {
            freq_info->freq_table[chain][asic] = freq_threshold;
          }
        }
      }
LAB_0001a5dc:
    }
  }
  return;
}


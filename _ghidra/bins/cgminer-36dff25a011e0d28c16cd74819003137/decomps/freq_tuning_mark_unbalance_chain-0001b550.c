
void freq_tuning_mark_unbalance_chain(freq_tuning_info *freq_info)

{
  FILE *pFVar1;
  freq_tuning_info *freq_info_local;
  FILE *pFile_2;
  FILE *pFile_1;
  FILE *pFile;
  int sub_proj_index;
  int freq;
  int asic;
  int chain;
  
  if (3 < log_level) {
    print_crt_time_to_file(log_file,3);
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d:%s: Mark unbalance freq.\n","freq_tuning.c",0x9c7,
              "freq_tuning_mark_unbalance_chain");
    }
    fclose(pFVar1);
  }
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if (dev->chain_exist[chain] != 0) {
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: g_chain_unbalance[%d] = %d\n","freq_tuning.c",0x9d0,
                  "freq_tuning_mark_unbalance_chain",chain,(uint)g_chain_unbalance[chain]);
        }
        fclose(pFVar1);
      }
      if (g_chain_unbalance[chain] == '\0') {
        freq = 200;
      }
      else {
        freq = 100;
      }
      if (3 < log_level) {
        print_crt_time_to_file(log_file,3);
        pFVar1 = fopen(log_file,"a+");
        if (pFVar1 != (FILE *)0x0) {
          fprintf(pFVar1,"%s:%d:%s: chain[%d]: freq = %d\n","freq_tuning.c",0x9db,
                  "freq_tuning_mark_unbalance_chain",chain,freq);
        }
        fclose(pFVar1);
      }
      for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
        freq_info->freq_table[chain][asic] = freq;
      }
      freq_info->vol_value_table[chain] = (g_BHB91602_proj.conf_list)->base_voltage;
      freq_info->ideal_hash_rate[chain] = (freq_info->asic_num_per_chain * freq * 0x2a0) / 1000;
    }
  }
  for (sub_proj_index = 0; sub_proj_index < g_BHB91602_proj.sub_proj_count;
      sub_proj_index = sub_proj_index + 1) {
    freq_tuning_save_result(freq_info,sub_proj_index);
  }
  return;
}



void freq_tuning_adjust_result_for_hash_rate_threshold
               (freq_tuning_info *freq_info,int sub_proj_index)

{
  int iVar1;
  FILE *__stream;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  int freq_diff;
  _Bool is_rounding_TH;
  
  if ((g_BHB91602_proj.proj_type == 1) &&
     (g_BHB91602_proj.conf_list[sub_proj_index].proj_sub_type == 1)) {
    freq_tuning_adjust_result_for_hash_rate_threshold_S15_H(freq_info,sub_proj_index);
  }
  else {
    iVar1 = freq_tuning_adjust_result_according_to_hash_rate
                      (freq_info,g_BHB91602_proj.conf_list[sub_proj_index].max_hash_rate * 1000,
                       g_BHB91602_proj.conf_list[sub_proj_index].proj_sub_type == 1);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,
                "%s:%d:%s: Adjust frequency %dM+ due to hash rate excceed target too much.\n",
                "freq_tuning.c",0x96d,"freq_tuning_adjust_result_for_hash_rate_threshold",iVar1);
      }
      fclose(__stream);
    }
  }
  return;
}


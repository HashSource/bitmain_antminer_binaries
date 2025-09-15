
void freq_tuning_adjust_result_for_J_TH(freq_tuning_info *freq_info,int sub_proj_index)

{
  int iVar1;
  FILE *__stream;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile;
  int freq_diff;
  int hash_rate_target;
  
  if ((g_BHB91602_proj.proj_type == 1) &&
     (g_BHB91602_proj.conf_list[sub_proj_index].proj_sub_type == 0)) {
    iVar1 = freq_tuning_adjust_result_according_to_hash_rate
                      (freq_info,(uint)dev->chain_num * freq_info->asic_num_per_chain * 0x2aa80,
                       false);
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d:%s: Adjust frequency %dM+ at economic mode for S15 due to J/TH.\n",
                "freq_tuning.c",0x8f7,"freq_tuning_adjust_result_for_J_TH",iVar1);
      }
      fclose(__stream);
    }
  }
  return;
}



void freq_tuning_adjust_result_for_poor_heat_dissipation
               (freq_tuning_info *freq_info,int sub_proj_index)

{
  FILE *pFVar1;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  FILE *pFile_1;
  FILE *pFile;
  int freq_threshold;
  int chain_id;
  int asic;
  
  if (((g_BHB91602_proj.proj_type == 1) &&
      (g_BHB91602_proj.conf_list[sub_proj_index].proj_sub_type == 1)) && (dev->chain_exist[2] != 0))
  {
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d:%s: Adjust S15 chain %d frequency <=%dM at high hash rate due to its poor heat dissipation.\n"
                ,"freq_tuning.c",0x83b,"freq_tuning_adjust_result_for_poor_heat_dissipation",2,0x17c
               );
      }
      fclose(pFVar1);
    }
    for (asic = 0; asic < freq_info->asic_num_per_chain; asic = asic + 1) {
      if (0x17c < freq_info->freq_table[2][asic]) {
        freq_info->freq_table[2][asic] = 0x17c;
      }
    }
    if (3 < log_level) {
      print_crt_time_to_file(log_file,3);
      pFVar1 = fopen(log_file,"a+");
      if (pFVar1 != (FILE *)0x0) {
        fprintf(pFVar1,
                "%s:%d:%s: Adjust S15 chain 3 frequency [0M 0M 10M 10M 20M 20M] according to its distance to air in.\n"
                ,"freq_tuning.c",0x844,"freq_tuning_adjust_result_for_poor_heat_dissipation");
      }
      fclose(pFVar1);
    }
    freq_tuning_adjust_result_according_to_distance_to_air_in(freq_info,2);
  }
  return;
}



void freq_tuning_set_pass_or_not(freq_tuning_info *freq_info,int sub_proj_index)

{
  int iVar1;
  int sub_proj_index_local;
  freq_tuning_info *freq_info_local;
  
  iVar1 = freq_tuning_get_hash_rate_GH(freq_info);
  if ((iVar1 < g_BHB91602_proj.conf_list[sub_proj_index].target_hash_rate) &&
     (g_BHB91602_proj.conf_list[sub_proj_index].base_voltage <
      g_BHB91602_proj.conf_list[sub_proj_index].max_voltage)) {
    freq_info->is_pass = false;
  }
  else {
    freq_info->is_pass = true;
  }
  return;
}


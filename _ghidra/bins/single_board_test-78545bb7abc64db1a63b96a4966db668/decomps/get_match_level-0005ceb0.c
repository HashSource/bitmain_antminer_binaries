
void get_match_level(test_ctx *level_info)

{
  test_ctx *level_info_local;
  char time_stamp [48];
  char tmp1 [256];
  
  if (((g_rt.config)->sweeped_res_index < 0) || (10 < (g_rt.config)->sweeped_res_index)) {
    level_info->level = -1;
  }
  else {
    level_info->level = (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].level;
    level_info->pre_open_core_voltage =
         (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].pre_open_core_voltage;
    level_info->freq = (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].freq;
    level_info->voltage = (g_rt.config)->tests[(g_rt.config)->sweeped_res_index].voltage;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : match level:%d\n","get_match_level",level_info->level);
    snprintf(tmp1,0x100,"match level:%d",level_info->level);
    log_to_file(tmp1,time_stamp);
  }
  return;
}


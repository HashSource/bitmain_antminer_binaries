
void copy_works_from_PT2_super_pattern(void *param_1,pattern_info *p_info)

{
  pattern_info *p_info_local;
  void *local_conf_local;
  char time_stamp [48];
  char tmp1 [2048];
  Local_Config_Info *info;
  int print_cnt;
  int i;
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: copy_works_from_PT2_super_pattern\n","copy_works_from_PT2_super_pattern");
  builtin_strncpy(tmp1,"copy_works_from_PT2_super_patter",0x20);
  tmp1[0x20] = 'n';
  tmp1[0x21] = '\0';
  log_to_file(tmp1,time_stamp);
  for (i = 0; (uint)i < *(uint *)((int)param_1 + 0x40); i = i + 1) {
    g_works[i] = (pattern_work *)p_info->works[i];
  }
  return;
}


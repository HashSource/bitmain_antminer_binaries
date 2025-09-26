
void set_multiple_ft_bin_info_to_nv_format(ft_bin_list_t *list,char *ft_version,int len)

{
  int len_local;
  char *ft_version_local;
  ft_bin_list_t *list_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t ft_val;
  int i;
  
  memset(ft_version,0,len);
  if (list->ft_bin_cnt == 0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ft_bin_cnt is 0.\n","set_multiple_ft_bin_info_to_nv_format");
    builtin_strncpy(tmp1,"ft_bin_cnt is 0.",0x10);
    tmp1[0x10] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  else {
    *ft_version = list->ft_bin_id | 0xc0;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: ftversion[0]:%d\n","set_multiple_ft_bin_info_to_nv_format",(uint)(byte)*ft_version);
    snprintf(tmp1,0x800,"ftversion[0]:%d",(uint)(byte)*ft_version);
    log_to_file(tmp1,time_stamp);
    for (i = 0; i < list->ft_bin_cnt; i = i + 1) {
      ft_val = list->ft_bin[i].v;
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: ft_val:%d\n","set_multiple_ft_bin_info_to_nv_format",ft_val);
      snprintf(tmp1,0x800,"ft_val:%d",ft_val);
      log_to_file(tmp1,time_stamp);
      memcpy(ft_version + i * 3 + 1,&ft_val,3);
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: ft_version:%d %d %d\n","set_multiple_ft_bin_info_to_nv_format",
             (uint)(byte)ft_version[i * 3 + 1],(uint)(byte)ft_version[i * 3 + 2],
             (uint)(byte)ft_version[(i + 1) * 3]);
      snprintf(tmp1,0x800,"ft_version:%d %d %d",(uint)(byte)ft_version[i * 3 + 1],
               (uint)(byte)ft_version[i * 3 + 2],(uint)(byte)ft_version[(i + 1) * 3]);
      log_to_file(tmp1,time_stamp);
    }
  }
  return;
}


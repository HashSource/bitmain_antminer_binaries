
void get_multiple_ft_bin_info_from_nv_format(uint32_t chain,char *ft_version,ft_bin_list_t *list)

{
  ft_bin_list_t *list_local;
  char *ft_version_local;
  uint32_t chain_local;
  char time_stamp [48];
  char tmp1 [2048];
  uint32_t ft_val;
  int index;
  _Bool list_exist;
  _Bool multiple;
  uint8_t multipe_head;
  int i;
  
  memset(list,0,0x14);
  multipe_head = *ft_version;
  multiple = (multipe_head & 0x80) != 0;
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: ftversion[0]:%d\n","get_multiple_ft_bin_info_from_nv_format",(uint)(byte)*ft_version);
  snprintf(tmp1,0x800,"ftversion[0]:%d",(uint)(byte)*ft_version);
  log_to_file(tmp1,time_stamp);
  if ((multiple != false) && (list_exist = (multipe_head & 0x40) != 0, list_exist)) {
    list->ft_bin_id = multipe_head & 0x3f;
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: %d %d %d %d \n","get_multiple_ft_bin_info_from_nv_format",(uint)multipe_head,
           (uint)list->ft_bin_id,(uint)multipe_head << 2,(int)((uint)multipe_head << 2) >> 2);
    snprintf(tmp1,0x800,"%d %d %d %d ",(uint)multipe_head,(uint)list->ft_bin_id,
             (uint)multipe_head << 2,(int)((uint)multipe_head << 2) >> 2);
    log_to_file(tmp1,time_stamp);
    index = 0;
    for (i = 0; i < 3; i = i + 1) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: get from str,ft_version:%d %d %d\n","get_multiple_ft_bin_info_from_nv_format",
             (uint)(byte)ft_version[i * 3 + 1],(uint)(byte)ft_version[i * 3 + 2],
             (uint)(byte)ft_version[(i + 1) * 3]);
      snprintf(tmp1,0x800,"get from str,ft_version:%d %d %d",(uint)(byte)ft_version[i * 3 + 1],
               (uint)(byte)ft_version[i * 3 + 2],(uint)(byte)ft_version[(i + 1) * 3]);
      log_to_file(tmp1,time_stamp);
      memcpy(&ft_val,ft_version + i * 3 + 1,3);
      list->ft_bin[i].v = ft_val;
      if (((uint)*(ushort *)(list->ft_bin + i) << 0x16) >> 0x1a != 0) {
        list->ft_bin_cnt = list->ft_bin_cnt + 1;
      }
    }
    log_out_multiple_ft_bin_info(list);
  }
  return;
}


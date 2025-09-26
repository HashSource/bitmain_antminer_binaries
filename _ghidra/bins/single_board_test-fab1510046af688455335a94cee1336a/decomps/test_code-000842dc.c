
void test_code(hashboard_qr_code *qr_code,char *qr_str)

{
  _Bool _Var1;
  char *qr_str_local;
  hashboard_qr_code *qr_code_local;
  char time_stamp [48];
  char tmp1 [2048];
  ft_bin_list_t ft_bin_list;
  char ft_version [10];
  
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: test ft info:%s\n","test_code",qr_str);
  snprintf(tmp1,0x800,"test ft info:%s",qr_str);
  log_to_file(tmp1,time_stamp);
  _Var1 = scan_multiple_ft_bin_info(qr_str,qr_code);
  if (_Var1) {
    log_out_multiple_ft_bin_info(&qr_code->ft_bin_list);
    memset(ft_version,0,10);
    memset(ft_version,0,10);
    set_multiple_ft_bin_info_to_nv_format(&qr_code->ft_bin_list,ft_version,10);
    memset(&ft_bin_list,0,0x14);
    get_multiple_ft_bin_info_from_nv_format(0,ft_version,&ft_bin_list);
  }
  return;
}


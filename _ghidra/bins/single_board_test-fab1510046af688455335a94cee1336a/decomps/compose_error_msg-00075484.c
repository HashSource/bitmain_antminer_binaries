
int compose_error_msg(char *sn,_Bool ok,int error_no,int error_info,char *send_msg)

{
  int iVar1;
  undefined *puVar2;
  int error_info_local;
  int error_no_local;
  _Bool ok_local;
  char *sn_local;
  char time_stamp [48];
  char tmp1 [2048];
  char error_dec [20];
  
  error_dec[0] = '\0';
  error_dec[1] = '\0';
  error_dec[2] = '\0';
  error_dec[3] = '\0';
  error_dec[4] = '\0';
  error_dec[5] = '\0';
  error_dec[6] = '\0';
  error_dec[7] = '\0';
  error_dec[8] = '\0';
  error_dec[9] = '\0';
  error_dec[10] = '\0';
  error_dec[0xb] = '\0';
  error_dec[0xc] = '\0';
  error_dec[0xd] = '\0';
  error_dec[0xe] = '\0';
  error_dec[0xf] = '\0';
  error_dec[0x10] = '\0';
  error_dec[0x11] = '\0';
  error_dec[0x12] = '\0';
  error_dec[0x13] = '\0';
  if (((uint)error_no < 0xd) && (-1 < error_no)) {
    if (error_no == 6) {
      snprintf(error_dec,0x14,"BA %d",error_info);
    }
    else if (error_no == 7) {
      snprintf(error_dec,0x14,"L%d",error_info);
    }
    else if (error_no == 3) {
      snprintf(error_dec,0x14,"%d asic",error_info);
    }
    else {
      if (err_msg_table[error_no].error_no != error_no) {
        print_time_stamp(time_stamp,0x30);
        printf("%s ",time_stamp);
        printf("%s: compose_error_msg, error_no doesn\'t match:%d\n","compose_error_msg",error_no);
        snprintf(tmp1,0x800,"compose_error_msg, error_no doesn\'t match:%d",error_no);
        log_to_file(tmp1,time_stamp);
        return 2;
      }
      error_dec._0_4_ = *(undefined4 *)err_msg_table[error_no].error_code_desc;
      error_dec._4_4_ = *(undefined4 *)(err_msg_table[error_no].error_code_desc + 4);
      error_dec._8_4_ = *(undefined4 *)(err_msg_table[error_no].error_code_desc + 8);
      error_dec._12_4_ = *(undefined4 *)(err_msg_table[error_no].error_code_desc + 0xc);
      error_dec._16_4_ = *(undefined4 *)(err_msg_table[error_no].error_code_desc + 0x10);
    }
    if (ok) {
      puVar2 = &DAT_001e3670;
    }
    else {
      puVar2 = &DAT_001e3690;
    }
    snprintf(send_msg,100,
             "[{\"sn\":\"%s\",\"type\":\"2\",\"code\":\"%s\",\"codedes\":\"%s\",\"results\":\"%s\"}]"
             ,sn,error_no * 0x24 + 0x24c470,error_dec,puVar2);
    iVar1 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s: compose_error_msg, invalid error_no:%d\n","compose_error_msg",error_no);
    snprintf(tmp1,0x800,"compose_error_msg, invalid error_no:%d",error_no);
    log_to_file(tmp1,time_stamp);
    iVar1 = 2;
  }
  return iVar1;
}


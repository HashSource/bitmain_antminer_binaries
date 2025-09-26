
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reset_registoer_buf(void)

{
  char time_stamp [48];
  char tmp1 [256];
  
  if (reg_value_buf == (reg_buf *)0x0) {
    reg_value_buf = (reg_buf *)malloc(0x13ffc);
    if (reg_value_buf == (reg_buf *)0x0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s : malloc reg_value_buf failed\n","reset_registoer_buf");
      builtin_strncpy(tmp1,"malloc reg_value_buf failed",0x1c);
      log_to_file(tmp1,time_stamp);
    }
    else {
      memset(reg_value_buf,0,0x13ffc);
    }
  }
  else {
    memset(reg_value_buf,0,0x13ffc);
  }
  return;
}


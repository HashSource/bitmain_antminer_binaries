
/* WARNING: Unknown calling convention */

_Bool check_scan_code_gun(void)

{
  _Bool _Var1;
  char time_stamp [48];
  char tmp1 [256];
  bitmain_sys_capability_t info;
  
  get_system_capability(&info);
  if ((info.board_num == 0) ||
     (gCode_gun_chain = info.board[info.board_num - 1].board_id, gCode_gun_chain != 3)) {
    _Var1 = false;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : check_scan_code_gun succ\n","check_scan_code_gun");
    builtin_strncpy(tmp1,"check_scan_code_gun succ",0x18);
    tmp1[0x18] = '\0';
    log_to_file(tmp1,time_stamp);
    _Var1 = true;
  }
  return _Var1;
}


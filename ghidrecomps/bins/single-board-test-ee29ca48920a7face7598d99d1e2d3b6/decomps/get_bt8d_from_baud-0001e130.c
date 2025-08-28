
uint get_bt8d_from_baud(int param_1)

{
  uint uVar1;
  char local_418 [48];
  undefined2 local_3e8;
  undefined4 local_18;
  uint local_14;
  
  local_18 = 5;
  local_14 = 0;
  while( true ) {
    if (4 < local_14) {
      if (local_14 == 5) {
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
          builtin_strncpy(local_418,"get bt8d value failed!!!,use default to continue",0x30);
          local_3e8 = 10;
          _applog(3,local_418,0);
        }
        uVar1 = get_bt8d_from_baud(0x1c200);
      }
      else {
        uVar1 = 0xff;
      }
      return uVar1;
    }
    if (*(int *)(&baud_BT8D_values + local_14 * 0xc) == param_1) break;
    local_14 = local_14 + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
    snprintf(local_418,0x400,"get bt8d %d\n",(uint)(byte)(&DAT_0004748c)[local_14 * 0xc]);
    _applog(3,local_418,0);
  }
  return (uint)(byte)(&DAT_0004748c)[local_14 * 0xc];
}


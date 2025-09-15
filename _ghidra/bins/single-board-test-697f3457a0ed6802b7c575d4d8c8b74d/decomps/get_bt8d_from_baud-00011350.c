
uint8_t get_bt8d_from_baud(uint32_t baud)

{
  uint8_t uVar1;
  uint32_t baud_local;
  char tmp42 [1024];
  size_t max;
  size_t index;
  
  index = 0;
  while( true ) {
    if (4 < index) {
      if (index == 5) {
        if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"get bt8d value failed!!!,use default to continue",0x30);
          tmp42[0x30] = '\n';
          tmp42[0x31] = '\0';
          _applog(3,tmp42,false);
        }
        uVar1 = get_bt8d_from_baud(0x1c200);
      }
      else {
        uVar1 = 0xff;
      }
      return uVar1;
    }
    if (baud_BT8D_values[index].baud == baud) break;
    index = index + 1;
  }
  if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
    snprintf(tmp42,0x400,"get bt8d %d\n",(uint)baud_BT8D_values[index].bt8d);
    _applog(3,tmp42,false);
  }
  return baud_BT8D_values[index].bt8d;
}


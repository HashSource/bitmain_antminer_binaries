
void pm_handle(int param_1,int param_2,byte param_3)

{
  char acStack_418 [1027];
  byte local_15;
  int local_14;
  
  local_14 = param_1;
  dump_str(app_conf._0_4_,0,param_1,param_2);
  local_15 = CRC5_v1(param_1 + 2,(param_2 - 3U & 0x1f) * 8 + 3 & 0xff);
  if (local_15 == (*(byte *)(local_14 + 8) & 0x1f)) {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_418,0x400,"pmonitor[%02x] %02x %02x %02x %02x\n",
               (uint)*(byte *)(local_14 + 7),(uint)*(byte *)(local_14 + 3),
               (uint)*(byte *)(local_14 + 4),(uint)*(byte *)(local_14 + 5),
               (uint)*(byte *)(local_14 + 6));
      _applog(2,acStack_418,0);
    }
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
    snprintf(acStack_418,0x400,"%s chain%d CRC error crc = %02x\n","pm_handle",(uint)param_3,
             (uint)local_15);
    _applog(0,acStack_418,0);
  }
  return;
}


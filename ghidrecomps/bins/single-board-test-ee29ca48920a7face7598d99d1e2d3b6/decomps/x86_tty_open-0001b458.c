
undefined4 x86_tty_open(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_434 [2];
  char acStack_42c [1024];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  
  local_28 = 0;
  local_24 = 8;
  local_20 = 1;
  local_1c = 0x4e;
  local_18 = 0;
  local_14 = 0x400;
  local_c = 0;
  local_434[0] = param_1;
  local_2c = param_2;
  while( true ) {
    if (0 < local_c) {
      return 0;
    }
    sprintf(g_chain + local_c * 0x20 + 5,"ttyUSB%d",local_434[0],local_434,param_2);
    local_10 = uart_open(local_c * 0x20 + 0x48461,&local_2c);
    if (local_10 < 0) break;
    *(int *)(g_chain + local_c * 0x20) = local_10;
    g_chain[local_c * 0x20 + 4] = (char)local_c;
    local_c = local_c + 1;
  }
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
    snprintf(acStack_42c,0x400,"open chain%d failed\n",local_c);
    _applog(1,acStack_42c,0);
  }
  return 0xffffffff;
}



undefined4
i2c_recv(byte param_1,undefined param_2,undefined param_3,undefined param_4,undefined *param_5)

{
  int iVar1;
  char cVar2;
  char acStack_130 [256];
  byte local_30;
  undefined local_2f;
  undefined local_2e;
  undefined4 local_2c;
  undefined local_24;
  undefined local_23;
  undefined local_22;
  undefined local_1c;
  undefined local_1b;
  undefined local_1a;
  undefined local_19;
  int local_18;
  int local_14;
  
  local_14 = 0;
  local_18 = i2c_status(param_1,param_2);
  if (local_18 < 1) {
    if (local_18 < 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_130,0x100,"%s[%d]not received the i2c response\n",__func___6505,0x1d3);
        _applog(0,acStack_130,0);
      }
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_130,0x100,"%s[%d]i2c is idle\n",__func___6505,0x1d6);
        _applog(0,acStack_130,0);
      }
      local_1b = 0;
      local_1c = param_2;
      local_1a = param_3;
      local_19 = param_4;
      midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x28),7,&local_1c);
      usleep(300000);
      local_18 = i2c_status(param_1,param_2);
      if (local_18 < 1) {
        if (local_18 < 0) {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
            snprintf(acStack_130,0x100,"%s[%d]-not received the i2c response\n",__func___6505,0x1e6)
            ;
            _applog(0,acStack_130,0);
          }
        }
        else {
          if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
            snprintf(acStack_130,0x100,"%s[%d]-i2c is idle\n",__func___6505,0x1e9);
            _applog(0,acStack_130,0);
          }
          local_23 = 0;
          local_22 = 0x20;
          local_24 = param_2;
          midd_ioctl(*(undefined4 *)(g_chain + (uint)param_1 * 0x28),0,&local_24);
          usleep(500000);
          local_2e = 0x20;
          local_30 = param_1;
          local_2f = param_2;
          do {
            usleep(100000);
            iVar1 = read_reg_item(&local_30);
            if (0 < iVar1) {
              *param_5 = (char)local_2c;
              return 1;
            }
            iVar1 = local_14;
            if (2 < local_14) {
              iVar1 = 0;
            }
            cVar2 = (char)iVar1;
            if (local_14 < 3) {
              cVar2 = '\x01';
            }
            local_14 = local_14 + 1;
          } while (cVar2 != '\0');
        }
      }
      else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
        snprintf(acStack_130,0x100,"%s[%d]-i2c is busy\n",__func___6505,0x1e3);
        _applog(0,acStack_130,0);
      }
    }
  }
  else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (-1 < opt_log_level)) {
    snprintf(acStack_130,0x100,"%s[%d]i2c is busy\n",__func___6505,0x1d0);
    _applog(0,acStack_130,0);
  }
  return 0xffffffff;
}


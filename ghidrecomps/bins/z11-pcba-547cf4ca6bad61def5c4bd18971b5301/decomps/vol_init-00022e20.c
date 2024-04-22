
undefined4 vol_init(ushort param_1)

{
  undefined4 uVar1;
  char acStack_410 [1026];
  ushort local_e;
  int local_c;
  
  if ((param_1 < 0x385) && (0x2ed < param_1)) {
    if (param_1 == 800) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_410,0x400,"setting voltage == configed voltage %d\n",800);
        _applog(2,acStack_410,0);
      }
      uVar1 = 1;
    }
    else {
      for (local_c = 0; local_c < 3; local_c = local_c + 1) {
        local_e = ISL_set_voltage(gChain,0,(&isl_dev_addr)[local_c],param_1);
        if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
          snprintf(acStack_410,0x400,"asic%d read back voltage = %d\n",local_c,(uint)local_e);
          _applog(2,acStack_410,0);
        }
      }
      uVar1 = 0;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_410,0x400,"illeagel setting voltage is %d\n",(uint)param_1);
      _applog(2,acStack_410,0);
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


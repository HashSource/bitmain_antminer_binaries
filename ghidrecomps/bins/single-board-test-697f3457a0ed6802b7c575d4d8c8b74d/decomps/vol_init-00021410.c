
int vol_init(ushort vol)

{
  uint16_t uVar1;
  int iVar2;
  ushort vol_local;
  char tmp42 [1024];
  ushort read_back;
  int which_asic;
  
  if ((vol < 0x385) && (0x2ed < vol)) {
    if (vol == 800) {
      if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"setting voltage == configed voltage %d\n",800);
        _applog(2,tmp42,false);
      }
      iVar2 = 1;
    }
    else {
      for (which_asic = 0; which_asic < 3; which_asic = which_asic + 1) {
        uVar1 = ISL_set_voltage(gChain,'\0',isl_dev_addr[which_asic],vol);
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"asic%d read back voltage = %d\n",which_asic,(uint)uVar1);
          _applog(2,tmp42,false);
        }
      }
      iVar2 = 0;
    }
  }
  else {
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"illeagel setting voltage is %d\n",(uint)vol);
      _applog(2,tmp42,false);
    }
    iVar2 = -1;
  }
  return iVar2;
}



undefined4
read_sensor(undefined param_1,int param_2,undefined param_3,byte param_4,undefined *param_5)

{
  int iVar1;
  char acStack_418 [1024];
  uint local_18;
  undefined4 local_14;
  
  local_18 = 0;
  iVar1 = i2c_recv(param_1,*(undefined *)((int)&sensor_chip_addr + param_2),param_3,param_4,
                   &local_18);
  if (iVar1 == 0) {
    if (((local_18 & 0xc0000000) == 0) && ((local_18 & 0xff) != 0)) {
      local_14 = 5;
      if (param_5 != (undefined *)0x0) {
        *param_5 = (char)local_18;
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (2 < opt_log_level)) {
        snprintf(acStack_418,0x400,
                 "Read i2c success sensroid=%02x, sensor-regaddr=%02x sensor-regdata=%08x\n",
                 (uint)*(byte *)((int)&sensor_chip_addr + param_2),(uint)param_4,local_18);
        _applog(3,acStack_418,0);
      }
    }
    else {
      local_14 = 6;
      if ((use_syslog != '\0') || ((opt_log_output != '\0' || (0 < opt_log_level)))) {
        snprintf(acStack_418,0x400,
                 "Read i2c failed sensroid=%02x, sensor-regaddr=%02x sensor-regdata=%08x\n",
                 (uint)*(byte *)((int)&sensor_chip_addr + param_2),(uint)param_4,local_18);
        _applog(1,acStack_418,0);
      }
    }
  }
  else {
    local_14 = 6;
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (0 < opt_log_level)) {
      snprintf(acStack_418,0x400,
               "Read i2c failed sensroid=%02x, sensor-regaddr=%02x sensor-regdata=%08x\n",
               (uint)*(byte *)((int)&sensor_chip_addr + param_2),(uint)param_4,local_18);
      _applog(1,acStack_418,0);
    }
  }
  return local_14;
}


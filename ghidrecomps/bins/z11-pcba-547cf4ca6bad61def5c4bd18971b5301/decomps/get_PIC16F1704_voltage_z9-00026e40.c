
void get_PIC16F1704_voltage_z9(undefined4 param_1,undefined param_2)

{
  char acStack_41c [1024];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_c;
  
  for (local_c = 0; local_c < 4; local_c = local_c + 1) {
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = PIC16F1704_i2c_forward_send
                         (param_1,param_2,*(undefined *)((int)&isl68127_i2c_dev_addr + local_c),1,
                          0x21,2,&local_1c);
    if (local_10 == 0) {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_41c,0x400,"read %02x vol success, 0x%02x%02x\n",
                 (uint)*(byte *)((int)&isl68127_i2c_dev_addr + local_c),local_1c & 0xff,
                 (uint)local_1c._1_1_);
        _applog(2,acStack_41c,0);
      }
    }
    else if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_41c,0x400,"read %02x vol failed, 0x%02x%02x\n",
               (uint)*(byte *)((int)&isl68127_i2c_dev_addr + local_c),local_1c & 0xff,
               (uint)local_1c._1_1_);
      _applog(2,acStack_41c,0);
    }
  }
  return;
}


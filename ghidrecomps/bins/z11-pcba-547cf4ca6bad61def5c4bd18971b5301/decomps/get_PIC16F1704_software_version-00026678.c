
undefined4 get_PIC16F1704_software_version(undefined param_1,undefined param_2,byte *param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_428 [1024];
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  byte local_1c;
  undefined2 local_18;
  ushort local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 4;
  local_1c = 0;
  local_20 = 0xff;
  local_14 = 0x1b;
  local_18 = 0x1b00;
  local_28 = 0x1704aa55;
  local_24 = 0x1b00;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_28 + (uint)local_11));
  }
  usleep(200000);
  for (local_11 = 0; local_11 < 5; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_20 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_428,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n"
             ,"get_PIC16F1704_software_version",local_20 & 0xff,local_20 >> 8 & 0xff,
             local_20 >> 0x10 & 0xff,local_20 >> 0x18,(uint)local_1c);
    _applog(2,acStack_428,0);
  }
  if ((local_20._1_1_ == '\x17') && ((char)local_20 == '\x05')) {
    local_14 = local_20._2_1_ + 0x1c;
    if (((char)(local_14 >> 8) == local_20._3_1_) && ((byte)local_14 == local_1c)) {
      *param_3 = local_20._2_1_;
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_428,0x400,"--- %s ok, version = 0x%02x\n\n",
                 "get_PIC16F1704_software_version",(uint)*param_3);
        _applog(2,acStack_428,0);
      }
      uVar2 = 1;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_428,0x400,"--- %s failed! crc = 0x%04x\n\n",
                 "get_PIC16F1704_software_version",(uint)local_14);
        _applog(2,acStack_428,0);
      }
      uVar2 = 0;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_428,0x400,"--- %s failed!\n\n","get_PIC16F1704_software_version");
      _applog(2,acStack_428,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}


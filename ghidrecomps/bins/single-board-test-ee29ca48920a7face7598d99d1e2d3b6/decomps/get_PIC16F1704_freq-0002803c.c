
undefined4 get_PIC16F1704_freq(undefined param_1,undefined param_2,ushort *param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_430 [1024];
  undefined4 local_30;
  undefined2 local_2c;
  undefined4 local_28;
  undefined2 local_24;
  undefined2 local_20;
  ushort local_1c;
  undefined local_1a;
  byte local_19;
  
  local_1a = 4;
  local_24 = 0;
  local_28 = 0xff;
  local_1c = 0x29;
  local_20 = 0x2900;
  local_30 = 0x2504aa55;
  local_2c = 0x2900;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_19 = 0; local_19 < 6; local_19 = local_19 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_30 + (uint)local_19));
  }
  usleep(300000);
  for (local_19 = 0; local_19 < 6; local_19 = local_19 + 1) {
    uVar3 = (uint)local_19;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_28 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_430,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
             ,"get_PIC16F1704_freq",local_28 & 0xff,local_28 >> 8 & 0xff,local_28 >> 0x10 & 0xff,
             local_28 >> 0x18,(uint)(byte)local_24,(uint)local_24._1_1_);
    _applog(2,acStack_430,0);
  }
  if ((local_28._1_1_ == '%') && ((char)local_28 == '\x06')) {
    local_1c = (ushort)local_28._3_1_ + local_28._2_1_ + 0x2b;
    if (((char)(local_1c >> 8) == (byte)local_24) && ((char)local_1c == local_24._1_1_)) {
      *param_3 = CONCAT11(local_28._2_1_,local_28._3_1_);
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_430,0x400,"--- %s ok, freq = %d\n\n","get_PIC16F1704_freq",(uint)*param_3);
        _applog(2,acStack_430,0);
      }
      uVar2 = 1;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_430,0x400,"--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_freq",
                 (uint)local_1c);
        _applog(2,acStack_430,0);
      }
      uVar2 = 0;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_430,0x400,"--- %s failed!\n\n","get_PIC16F1704_freq");
      _applog(2,acStack_430,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}


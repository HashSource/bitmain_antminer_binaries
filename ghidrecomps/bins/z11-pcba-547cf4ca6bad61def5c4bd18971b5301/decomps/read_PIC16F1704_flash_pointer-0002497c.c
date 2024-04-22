
undefined4
read_PIC16F1704_flash_pointer(undefined param_1,undefined param_2,byte *param_3,byte *param_4)

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
  short local_1c;
  undefined local_1a;
  byte local_19;
  
  local_1a = 4;
  local_24 = 0;
  local_28 = 0xff;
  local_1c = 0xc;
  local_20 = 0xc00;
  local_30 = 0x804aa55;
  local_2c = 0xc00;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_19 = 0; local_19 < 6; local_19 = local_19 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_30 + (uint)local_19));
  }
  usleep(100000);
  for (local_19 = 0; local_19 < 6; local_19 = local_19 + 1) {
    uVar3 = (uint)local_19;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_28 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((local_28._1_1_ == 8) && ((char)local_28 == '\x06')) {
    local_1c = (ushort)local_28._3_1_ + local_28._2_1_ + 0xe;
    if (((byte)((ushort)local_1c >> 8) == (byte)local_24) && ((byte)local_1c == local_24._1_1_)) {
      *param_3 = local_28._2_1_;
      *param_4 = local_28._3_1_;
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_430,0x400,"--- %s ok! flash_addr_h = 0x%02x, flash_addr_l = 0x%02x\n\n",
                 "read_PIC16F1704_flash_pointer",(uint)*param_3,(uint)*param_4);
        _applog(2,acStack_430,0);
      }
      uVar2 = 1;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_430,0x400,
                 "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
                 ,"read_PIC16F1704_flash_pointer",local_28 & 0xff,8,(uint)local_28._2_1_,
                 (uint)local_28._3_1_,(uint)(byte)local_24,(uint)local_24._1_1_);
        _applog(2,acStack_430,0);
      }
      uVar2 = 0;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_430,0x400,
               "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
               ,"read_PIC16F1704_flash_pointer",local_28 & 0xff,(uint)local_28._1_1_,
               (uint)local_28._2_1_,(uint)local_28._3_1_,(uint)(byte)local_24,(uint)local_24._1_1_);
      _applog(2,acStack_430,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}



undefined4 read_hash_id_PIC16F1704(undefined param_1,undefined param_2,int param_3)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  char acStack_438 [1024];
  undefined4 local_38;
  undefined2 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined2 local_20;
  ushort local_1c;
  undefined local_1a;
  byte local_19;
  
  local_1a = 4;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_30 = 0xff;
  local_1c = 0x17;
  local_20 = 0x1700;
  local_38 = 0x1304aa55;
  local_34 = 0x1700;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_19 = 0; local_19 < 6; local_19 = local_19 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_38 + (uint)local_19));
  }
  usleep(200000);
  for (local_19 = 0; local_19 < 0x10; local_19 = local_19 + 1) {
    uVar3 = (uint)local_19;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_30 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
    snprintf(acStack_438,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,\t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,\t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x,\t\tread_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n"
             ,"read_hash_id_PIC16F1704",local_30 & 0xff,local_30 >> 8 & 0xff,local_30 >> 0x10 & 0xff
             ,local_30 >> 0x18,local_2c & 0xff,local_2c >> 8 & 0xff,local_2c >> 0x10 & 0xff,
             local_2c >> 0x18,local_28 & 0xff,local_28 >> 8 & 0xff,local_28 >> 0x10 & 0xff,
             local_28 >> 0x18,local_24 & 0xff,local_24 >> 8 & 0xff,local_24 >> 0x10 & 0xff,
             local_24 >> 0x18);
    _applog(2,acStack_438,0);
  }
  if ((local_30._1_1_ == '\x13') && ((char)local_30 == '\x10')) {
    local_1c = (ushort)local_24._1_1_ +
               (ushort)(byte)local_24 +
               (ushort)local_28._3_1_ +
               (ushort)local_28._2_1_ +
               (ushort)local_28._1_1_ +
               (ushort)(byte)local_28 +
               (ushort)local_2c._3_1_ +
               (ushort)local_2c._2_1_ +
               (ushort)local_2c._1_1_ +
               (ushort)(byte)local_2c + (ushort)local_30._3_1_ + local_30._2_1_ + 0x23;
    if (((char)(local_1c >> 8) == local_24._2_1_) && ((char)local_1c == local_24._3_1_)) {
      for (local_19 = 0; local_19 < 0xc; local_19 = local_19 + 1) {
        *(undefined *)((uint)local_19 + param_3) = *(undefined *)((int)&local_30 + local_19 + 2);
      }
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_438,0x400,"--- %s ok\n\n","read_hash_id_PIC16F1704");
        _applog(2,acStack_438,0);
      }
      uVar2 = 1;
    }
    else {
      if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
        snprintf(acStack_438,0x400,"--- %s failed! crc = 0x%04x\n\n","read_hash_id_PIC16F1704",
                 (uint)local_1c);
        _applog(2,acStack_438,0);
      }
      uVar2 = 0;
    }
  }
  else {
    if (((use_syslog != '\0') || (opt_log_output != '\0')) || (1 < opt_log_level)) {
      snprintf(acStack_438,0x400,"--- %s failed!\n\n","read_hash_id_PIC16F1704");
      _applog(2,acStack_438,0);
    }
    uVar2 = 0;
  }
  return uVar2;
}


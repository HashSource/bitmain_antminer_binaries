
undefined4
read_PIC16F1704_flash_point32_ter(undefined param_1,undefined param_2,byte *param_3,byte *param_4)

{
  undefined uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  short local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 4;
  local_1c = 0;
  local_20 = 0xff;
  local_14 = 0xc;
  local_18 = 0xc00;
  local_28 = 0x804aa55;
  local_24 = 0xc00;
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_28 + (uint)local_11));
  }
  usleep(100000);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    uVar3 = (uint)local_11;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_20 + uVar3) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  if ((local_20._1_1_ == 8) && ((char)local_20 == '\x06')) {
    local_14 = local_20._2_1_ + 0xe + (ushort)local_20._3_1_;
    if (((byte)((ushort)local_14 >> 8) == (byte)local_1c) && ((byte)local_14 == local_1c._1_1_)) {
      *param_3 = local_20._2_1_;
      *param_4 = local_20._3_1_;
      printf("\n--- %s ok! flash_addr_h = 0x%02x, flash_addr_l = 0x%02x\n\n",
             "read_PIC16F1704_flash_point32_ter",(uint)*param_3,(uint)*param_4);
      uVar2 = 1;
    }
    else {
      printf("\n--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
             ,"read_PIC16F1704_flash_point32_ter",local_20 & 0xff,8,(uint)local_20._2_1_,
             (uint)local_20._3_1_,(uint)(byte)local_1c,(uint)local_1c._1_1_);
      uVar2 = 0;
    }
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
           ,"read_PIC16F1704_flash_point32_ter",local_20 & 0xff,(uint)local_20._1_1_,
           (uint)local_20._2_1_,(uint)local_20._3_1_,(uint)(byte)local_1c,(uint)local_1c._1_1_);
    uVar2 = 0;
  }
  return uVar2;
}


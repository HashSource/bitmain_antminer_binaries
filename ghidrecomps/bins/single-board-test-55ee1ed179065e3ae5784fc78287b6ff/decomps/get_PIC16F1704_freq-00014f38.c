
undefined4 get_PIC16F1704_freq(undefined param_1,undefined param_2,ushort *param_3)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  ushort local_14;
  undefined local_12;
  byte local_11;
  
  local_12 = 4;
  local_1c = 0;
  local_20 = 0xff;
  local_14 = 0x29;
  local_18 = 0x2900;
  local_28 = 0x2504aa55;
  local_24 = 0x2900;
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_2,param_1,*(undefined *)((int)&local_28 + (uint)local_11));
  }
  usleep(300000);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    uVar6 = (uint)local_11;
    uVar1 = read_pic(param_2,param_1);
    *(undefined *)((int)&local_20 + uVar6) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  usleep(200000);
  uVar2 = local_20 >> 0x10 & 0xff;
  uVar6 = local_20 >> 0x18;
  uVar3 = (uint)(byte)local_1c;
  uVar4 = (uint)local_1c._1_1_;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
         ,"get_PIC16F1704_freq",local_20 & 0xff,local_20 >> 8 & 0xff,uVar2,uVar6,uVar3,uVar4);
  if ((local_20._1_1_ == '%') && ((local_20 & 0xff) == 6)) {
    local_14 = (byte)local_20 + 0x25 + (ushort)local_20._2_1_ + (ushort)local_20._3_1_;
    if (((char)(local_14 >> 8) == (byte)local_1c) && ((char)local_14 == local_1c._1_1_)) {
      *param_3 = CONCAT11(local_20._2_1_,local_20._3_1_);
      printf("\n--- %s ok, freq = %d\n\n","get_PIC16F1704_freq",(uint)*param_3,(uint)*param_3,uVar2,
             uVar6,uVar3,uVar4);
      uVar5 = 1;
    }
    else {
      printf("\n--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_freq",(uint)local_14,(uint)local_14
             ,uVar2,uVar6,uVar3,uVar4);
      uVar5 = 0;
    }
  }
  else {
    printf("\n--- %s failed!\n\n","get_PIC16F1704_freq");
    uVar5 = 0;
  }
  return uVar5;
}


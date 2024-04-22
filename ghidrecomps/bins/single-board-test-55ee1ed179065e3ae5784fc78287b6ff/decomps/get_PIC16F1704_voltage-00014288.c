
undefined4 get_PIC16F1704_voltage(undefined param_1,undefined param_2,byte *param_3)

{
  undefined uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
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
  local_14 = 0x1c;
  local_18 = 0x1c00;
  local_28 = 0x1804aa55;
  local_24 = 0x1c00;
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  for (local_11 = 0; local_11 < 6; local_11 = local_11 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_28 + (uint)local_11));
  }
  usleep(200000);
  for (local_11 = 0; local_11 < 5; local_11 = local_11 + 1) {
    uVar5 = (uint)local_11;
    uVar1 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_20 + uVar5) = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  uVar2 = local_20 >> 0x10 & 0xff;
  uVar5 = local_20 >> 0x18;
  uVar3 = (uint)local_1c;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n"
         ,"get_PIC16F1704_voltage",local_20 & 0xff,local_20 >> 8 & 0xff,uVar2,uVar5,uVar3);
  if ((local_20._1_1_ == '\x18') && ((local_20 & 0xff) == 5)) {
    local_14 = (byte)local_20 + 0x18 + (ushort)local_20._2_1_;
    if (((char)(local_14 >> 8) == local_20._3_1_) && ((byte)local_14 == local_1c)) {
      *param_3 = local_20._2_1_;
      printf("\n--- %s ok, voltage = 0x%02x\n\n","get_PIC16F1704_voltage",(uint)*param_3,
             (uint)*param_3,uVar2,uVar5,uVar3);
      uVar4 = 1;
    }
    else {
      printf("\n--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_voltage",(uint)local_14,
             (uint)local_14,uVar2,uVar5,uVar3);
      uVar4 = 0;
    }
  }
  else {
    printf("\n--- %s failed!\n\n","get_PIC16F1704_voltage");
    uVar4 = 0;
  }
  return uVar4;
}


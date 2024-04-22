
undefined4 read_temperature_offset_PIC16F1704(undefined param_1,undefined param_2,int param_3)

{
  byte bVar1;
  undefined uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined4 local_3c;
  undefined2 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  ushort local_24;
  undefined local_22;
  byte local_21;
  
  local_22 = 4;
  local_30 = 0;
  local_2c = 0;
  local_34 = 0xff;
  local_21 = 0;
  local_24 = 0x27;
  local_28 = 0x2700;
  local_3c = 0x2304aa55;
  local_38 = 0x2700;
  pthread_mutex_lock((pthread_mutex_t *)i2c_mutex);
  for (local_21 = 0; local_21 < 6; local_21 = local_21 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_3c + (uint)local_21));
  }
  usleep(200000);
  for (local_21 = 0; local_21 < 0xc; local_21 = local_21 + 1) {
    uVar12 = (uint)local_21;
    uVar2 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_34 + uVar12) = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)i2c_mutex);
  uVar3 = local_34 >> 0x10 & 0xff;
  uVar12 = local_34 >> 0x18;
  uVar4 = local_30 & 0xff;
  uVar5 = local_30 >> 8 & 0xff;
  uVar6 = local_30 >> 0x10 & 0xff;
  uVar13 = local_30 >> 0x18;
  uVar7 = local_2c & 0xff;
  uVar8 = local_2c >> 8 & 0xff;
  uVar9 = local_2c >> 0x10 & 0xff;
  uVar14 = local_2c >> 0x18;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,         read_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,         read_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n"
         ,"read_temperature_offset_PIC16F1704",local_34 & 0xff,local_34 >> 8 & 0xff,uVar3,uVar12,
         uVar4,uVar5,uVar6,uVar13,uVar7,uVar8,uVar9,uVar14);
  if ((local_34._1_1_ == '#') && ((local_34 & 0xff) == 0xc)) {
    local_24 = (byte)local_34 + 0x23 + (ushort)local_34._2_1_ + (ushort)local_34._3_1_ +
               (ushort)(byte)local_30 + (ushort)local_30._1_1_ + (ushort)local_30._2_1_ +
               (ushort)local_30._3_1_ + (ushort)(byte)local_2c + (ushort)local_2c._1_1_;
    if (((char)(local_24 >> 8) == local_2c._2_1_) &&
       (uVar10 = (uint)(byte)local_24, uVar10 == local_2c >> 0x18)) {
      for (local_21 = 0; local_21 < 8; local_21 = local_21 + 1) {
        bVar1 = *(byte *)((int)&local_34 + local_21 + 2);
        uVar10 = (uint)bVar1;
        *(byte *)(param_3 + (uint)local_21) = bVar1;
      }
      printf("\n--- %s ok\n\n","read_temperature_offset_PIC16F1704",uVar10,(uint)local_21,uVar3,
             uVar12,uVar4,uVar5,uVar6,uVar13,uVar7,uVar8,uVar9,uVar14);
      uVar11 = 1;
    }
    else {
      printf("\n--- %s failed! crc = 0x%04x\n\n","read_temperature_offset_PIC16F1704",(uint)local_24
             ,(uint)local_24,uVar3,uVar12,uVar4,uVar5,uVar6,uVar13,uVar7,uVar8,uVar9,uVar14);
      uVar11 = 0;
    }
  }
  else {
    printf("\n--- %s failed!\n\n","read_temperature_offset_PIC16F1704");
    uVar11 = 0;
  }
  return uVar11;
}


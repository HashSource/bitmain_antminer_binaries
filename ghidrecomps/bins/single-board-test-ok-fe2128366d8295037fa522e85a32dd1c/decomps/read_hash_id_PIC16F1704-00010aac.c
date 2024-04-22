
undefined4 read_hash_id_PIC16F1704(undefined param_1,undefined param_2,int param_3)

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
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined2 local_30;
  ushort local_2c;
  undefined local_2a;
  byte local_29;
  
  local_2a = 4;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_40 = 0xff;
  local_2c = 0x17;
  local_30 = 0x1700;
  local_48 = 0x1304aa55;
  local_44 = 0x1700;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (local_29 = 0; local_29 < 6; local_29 = local_29 + 1) {
    write_pic(param_1,param_2,*(undefined *)((int)&local_48 + (uint)local_29));
  }
  usleep(200000);
  for (local_29 = 0; local_29 < 0x10; local_29 = local_29 + 1) {
    uVar15 = (uint)local_29;
    uVar2 = read_pic(param_1,param_2);
    *(undefined *)((int)&local_40 + uVar15) = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  uVar4 = local_40 >> 0x10 & 0xff;
  uVar15 = local_40 >> 0x18;
  uVar5 = local_3c & 0xff;
  uVar6 = local_3c >> 8 & 0xff;
  uVar7 = local_3c >> 0x10 & 0xff;
  uVar16 = local_3c >> 0x18;
  uVar8 = local_38 & 0xff;
  uVar9 = local_38 >> 8 & 0xff;
  uVar10 = local_38 >> 0x10 & 0xff;
  uVar17 = local_38 >> 0x18;
  uVar11 = local_34 & 0xff;
  uVar12 = local_34 >> 8 & 0xff;
  uVar13 = local_34 >> 0x10 & 0xff;
  uVar18 = local_34 >> 0x18;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,\t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,\t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x,\t\tread_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n"
         ,"read_hash_id_PIC16F1704",local_40 & 0xff,local_40 >> 8 & 0xff,uVar4,uVar15,uVar5,uVar6,
         uVar7,uVar16,uVar8,uVar9,uVar10,uVar17,uVar11,uVar12,uVar13,uVar18);
  if ((local_40._1_1_ == '\x13') && ((local_40 & 0xff) == 0x10)) {
    local_2c = (byte)local_40 + 0x13 + (ushort)local_40._2_1_ + (ushort)local_40._3_1_ +
               (ushort)(byte)local_3c + (ushort)local_3c._1_1_ + (ushort)local_3c._2_1_ +
               (ushort)local_3c._3_1_ + (ushort)(byte)local_38 + (ushort)local_38._1_1_ +
               (ushort)local_38._2_1_ + (ushort)local_38._3_1_ + (ushort)(byte)local_34 +
               (ushort)local_34._1_1_;
    if (((char)(local_2c >> 8) == local_34._2_1_) &&
       (uVar3 = (uint)(byte)local_2c, uVar3 == local_34 >> 0x18)) {
      for (local_29 = 0; local_29 < 0xc; local_29 = local_29 + 1) {
        bVar1 = *(byte *)((int)&local_40 + local_29 + 2);
        uVar3 = (uint)bVar1;
        *(byte *)(param_3 + (uint)local_29) = bVar1;
      }
      printf("\n--- %s ok\n\n","read_hash_id_PIC16F1704",uVar3,(uint)local_29,uVar4,uVar15,uVar5,
             uVar6,uVar7,uVar16,uVar8,uVar9,uVar10,uVar17,uVar11,uVar12,uVar13,uVar18);
      uVar14 = 1;
    }
    else {
      printf("\n--- %s failed! crc = 0x%04x\n\n","read_hash_id_PIC16F1704",(uint)local_2c,
             (uint)local_2c,uVar4,uVar15,uVar5,uVar6,uVar7,uVar16,uVar8,uVar9,uVar10,uVar17,uVar11,
             uVar12,uVar13,uVar18);
      uVar14 = 0;
    }
  }
  else {
    printf("\n--- %s failed!\n\n","read_hash_id_PIC16F1704");
    uVar14 = 0;
  }
  return uVar14;
}


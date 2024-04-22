
/* WARNING: Unknown calling convention */

int set_dsPIC33EP16GS202_threshold_voltage
              (uint which_chain,uchar which_i2c,ushort vol,ushort vol1,ushort vol2,ushort vol3,
              ushort vol_p)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uchar send_data [16];
  
  uVar9 = (uint)vol1;
  uVar8 = (uint)vol;
  pbVar4 = send_data;
  uVar5 = (uint)vol_p;
  uVar7 = (uint)vol3;
  uVar6 = (uint)vol2;
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[11] = '\0';
  send_data[12] = '\0';
  send_data[13] = '\0';
  send_data[14] = '\0';
  send_data[15] = '\0';
  printf("\n--- %s\n",DAT_00023fa0);
  uVar3 = uVar5 + 0x41 + uVar7 + uVar6 + uVar9 + uVar8 & 0xffff;
  if (uVar8 != 0) {
    uVar8 = 1;
  }
  if (uVar9 != 0) {
    uVar9 = 1;
  }
  if (uVar6 != 0) {
    uVar6 = 1;
  }
  if (uVar7 != 0) {
    uVar7 = 1;
  }
  send_data[15] = (char)uVar3;
  send_data[14] = (char)(uVar3 >> 8);
  if (uVar5 != 0) {
    uVar5 = 1;
  }
  send_data._8_2_ = CONCAT11((uchar)uVar6,(uchar)(vol2 >> 8));
  send_data._8_3_ = CONCAT12((uchar)(vol3 >> 8),send_data._8_2_);
  send_data[5] = (char)uVar8;
  send_data[4] = (char)(vol >> 8);
  send_data[6] = (char)(vol1 >> 8);
  send_data[7] = (uchar)uVar9;
  send_data[11] = (uchar)uVar7;
  send_data._12_2_ = CONCAT11((uchar)uVar5,(uchar)(vol_p >> 8));
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x0e';
  send_data[3] = '3';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  uVar5 = (uint)which_i2c << 0x1a | 0x400000 | (which_chain & 0xff) << 0x10;
  while (i2c_write(uVar3 | uVar5), send_data + 0xf != pbVar4) {
    pbVar4 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
  }
  usleep(100000);
  bVar1 = i2c_read(uVar5);
  bVar2 = i2c_read(uVar5);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((bVar1 == 0x33) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_00023fa0);
    usleep(500000);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_00023fa0,
         (uint)bVar1,(uint)bVar2);
  return 0;
}


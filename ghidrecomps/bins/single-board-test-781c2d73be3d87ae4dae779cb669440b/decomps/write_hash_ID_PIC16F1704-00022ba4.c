
/* WARNING: Unknown calling convention */

int write_hash_ID_PIC16F1704(uint which_chain,uchar which_i2c,uchar *buf)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte bStack_2d;
  uchar send_data [18];
  
  pbVar3 = buf + -1;
  uVar4 = 0x22;
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[11] = '\0';
  send_data[12] = '\0';
  send_data[13] = '\0';
  send_data[14] = '\0';
  send_data[15] = '\0';
  pbVar6 = pbVar3;
  do {
    pbVar6 = pbVar6 + 1;
    uVar5 = uVar4 + *pbVar6;
    uVar4 = uVar5 & 0xffff;
  } while (pbVar6 != buf + 0xb);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x10';
  pbVar6 = send_data + 3;
  send_data[3] = '\x12';
  do {
    pbVar3 = pbVar3 + 1;
    pbVar6 = pbVar6 + 1;
    *pbVar6 = *pbVar3;
  } while (buf + 0xb != pbVar3);
  send_data[16] = (uchar)(uVar4 >> 8);
  uVar4 = (uint)which_i2c << 0x1a | 0xa00000 | (which_chain & 0xff) << 0x10;
  pbVar6 = &bStack_2d;
  send_data[17] = (uchar)uVar5;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  do {
    pbVar6 = pbVar6 + 1;
    i2c_write(*pbVar6 | uVar4);
  } while (send_data + 0x11 != pbVar6);
  usleep(400000);
  bVar1 = i2c_read(uVar4);
  bVar2 = i2c_read(uVar4);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((bVar1 == 0x12) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_00022c90);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_00022c90,
         (uint)bVar1,(uint)bVar2);
  return 0;
}


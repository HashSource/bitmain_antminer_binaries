
/* WARNING: Unknown calling convention */

int send_data_to_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  byte bStack_31;
  uchar send_data [22];
  
  pbVar6 = buf + -1;
  uVar4 = 0x16;
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
  send_data[16] = '\0';
  send_data[17] = '\0';
  send_data[18] = '\0';
  send_data[19] = '\0';
  pbVar3 = pbVar6;
  do {
    pbVar3 = pbVar3 + 1;
    uVar5 = uVar4 + *pbVar3;
    uVar4 = uVar5 & 0xffff;
  } while (pbVar3 != buf + 0xf);
  send_data[21] = (uchar)uVar5;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x14';
  pbVar3 = send_data + 3;
  send_data[3] = '\x02';
  do {
    pbVar6 = pbVar6 + 1;
    pbVar3 = pbVar3 + 1;
    *pbVar3 = *pbVar6;
  } while (pbVar3 != send_data + 0x13);
  send_data[20] = (uchar)(uVar4 >> 8);
  pbVar3 = &bStack_31;
  uVar4 = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  do {
    pbVar3 = pbVar3 + 1;
    i2c_write(*pbVar3 | uVar4);
  } while (send_data + 0x15 != pbVar3);
  usleep(100000);
  bVar1 = i2c_read(uVar4);
  bVar2 = i2c_read(uVar4);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((bVar1 == 2) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_00022430);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_00022430,
         (uint)bVar1,(uint)bVar2);
  return 0;
}


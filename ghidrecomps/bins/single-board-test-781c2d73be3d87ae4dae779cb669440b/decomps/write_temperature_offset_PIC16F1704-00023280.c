
/* WARNING: Unknown calling convention */

int write_temperature_offset_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  byte bStack_29;
  uchar send_data [14];
  
  pbVar3 = buf + -1;
  uVar5 = 0x2e;
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[11] = '\0';
  pbVar4 = pbVar3;
  do {
    pbVar4 = pbVar4 + 1;
    uVar6 = uVar5 + *pbVar4;
    uVar5 = uVar6 & 0xffff;
  } while (pbVar4 != buf + 7);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\f';
  pbVar4 = send_data + 3;
  send_data[3] = '\"';
  do {
    pbVar3 = pbVar3 + 1;
    pbVar4 = pbVar4 + 1;
    *pbVar4 = *pbVar3;
  } while (buf + 7 != pbVar3);
  send_data[12] = (uchar)(uVar5 >> 8);
  pbVar4 = &bStack_29;
  uVar5 = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  send_data[13] = (uchar)uVar6;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  do {
    pbVar4 = pbVar4 + 1;
    i2c_write(*pbVar4 | uVar5);
  } while (send_data + 0xd != pbVar4);
  usleep(200000);
  bVar1 = i2c_read(uVar5);
  bVar2 = i2c_read(uVar5);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((bVar1 == 0x22) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_00023368);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_00023368,
         (uint)bVar1,(uint)bVar2);
  return 0;
}


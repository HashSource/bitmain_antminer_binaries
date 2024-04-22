
/* WARNING: Unknown calling convention */

int enable_dsPIC33EP16GS202_dc_dc(uint which_chain,uchar which_i2c,uchar enable)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint config_data;
  uchar send_data [7];
  
  pbVar4 = send_data;
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  printf("\n--- %s\n",DAT_0002408c);
  send_data[6] = (uchar)(enable + 0x1a);
  send_data[5] = (uchar)(enable + 0x1a >> 8);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x05';
  send_data[3] = '\x15';
  send_data[4] = enable;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  config_data = (uint)which_i2c << 0x1a | 0x400000 | (which_chain & 0xff) << 0x10;
  while (i2c_write(uVar3 | config_data), send_data + 6 != pbVar4) {
    pbVar4 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
  }
  usleep(100000);
  bVar1 = i2c_read(config_data);
  bVar2 = i2c_read(config_data);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((bVar1 == 0x15) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_0002408c);
    usleep(500000);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_0002408c,
         (uint)bVar1,(uint)bVar2);
  return 0;
}


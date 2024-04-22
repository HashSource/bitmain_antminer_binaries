
/* WARNING: Unknown calling convention */

int set_dsPIC33EP16GS202_voltage(uint which_chain,uchar which_i2c,uchar voltage)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint config_data;
  uchar send_data [9];
  
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[8] = '\0';
  printf("\n--- %s\n",DAT_00023e2c);
  send_data[4] = voltage;
  send_data[8] = (uchar)(voltage + 0x17);
  send_data[7] = (uchar)(voltage + 0x17 >> 8);
  pbVar4 = send_data;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\a';
  send_data[3] = '\x10';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  config_data = (uint)which_i2c << 0x1a | 0x400000 | (which_chain & 0xff) << 0x10;
  while (i2c_write(uVar3 | config_data), send_data + 8 != pbVar4) {
    pbVar4 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
  }
  usleep(200000);
  bVar1 = i2c_read(config_data);
  bVar2 = i2c_read(config_data);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((bVar1 == 0x10) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_00023e2c);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_00023e2c,
         (uint)bVar1,(uint)bVar2);
  return 0;
}


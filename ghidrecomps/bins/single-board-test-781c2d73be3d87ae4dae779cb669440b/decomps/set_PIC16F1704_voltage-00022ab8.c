
/* WARNING: Unknown calling convention */

int set_PIC16F1704_voltage(uint which_chain,uchar which_i2c,uchar voltage)

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
  printf("\n--- %s\n",DAT_00022ba0);
  send_data[6] = (uchar)(voltage + 0x15);
  send_data[5] = (uchar)(voltage + 0x15 >> 8);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x05';
  send_data[3] = '\x10';
  send_data[4] = voltage;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  config_data = (uint)which_i2c << 0x1a | 0xa00000 | (which_chain & 0xff) << 0x10;
  while (i2c_write(uVar3 | config_data), send_data + 6 != pbVar4) {
    pbVar4 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
  }
  usleep(200000);
  bVar1 = i2c_read(config_data);
  bVar2 = i2c_read(config_data);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((bVar1 == 0x10) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_00022ba0);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_00022ba0,
         (uint)bVar1,(uint)bVar2);
  return 0;
}



/* WARNING: Unknown calling convention */

int write_data_into_PIC16F1704_flash(uint which_i2c,uchar which_chain)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint config_data;
  uchar send_data [6];
  
  pbVar4 = send_data;
  send_data[1] = 0xaa;
  send_data[0] = 'U';
  send_data[2] = '\x04';
  send_data[3] = '\x05';
  send_data[4] = '\0';
  send_data[5] = '\t';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  config_data = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  while (i2c_write(uVar3 | config_data), send_data + 5 != pbVar4) {
    pbVar4 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
  }
  usleep(200000);
  bVar1 = i2c_read(config_data);
  bVar2 = i2c_read(config_data);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((bVar1 == 5) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_00022914);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_00022914,
         (uint)bVar1,(uint)bVar2);
  return 0;
}


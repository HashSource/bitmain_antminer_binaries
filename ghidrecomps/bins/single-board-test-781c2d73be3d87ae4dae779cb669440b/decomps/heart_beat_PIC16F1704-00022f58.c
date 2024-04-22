
/* WARNING: Unknown calling convention */

int heart_beat_PIC16F1704(uint which_chain,uchar which_i2c)

{
  uchar uVar1;
  uint uVar2;
  byte *pbVar3;
  uchar *puVar4;
  uchar *puVar5;
  uint config_data;
  uchar read_back_data [6];
  uchar auStack_2a [2];
  uchar send_data [6];
  
  send_data[1] = 0xaa;
  read_back_data[0] = '\0';
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  send_data[0] = 'U';
  pbVar3 = send_data;
  send_data[2] = '\x04';
  config_data = (uint)which_i2c << 0x1a | 0xa00000 | (which_chain & 0xff) << 0x10;
  send_data[3] = '\x16';
  send_data[4] = '\0';
  send_data[5] = '\x1a';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar2 = 0x55;
  while (i2c_write(uVar2 | config_data), pbVar3 != send_data + 5) {
    pbVar3 = pbVar3 + 1;
    uVar2 = (uint)*pbVar3;
  }
  usleep(100000);
  puVar4 = read_back_data;
  do {
    uVar1 = i2c_read(config_data);
    puVar5 = puVar4 + 1;
    *puVar4 = uVar1;
    puVar4 = puVar5;
  } while (auStack_2a != puVar5);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[1] == '\x16') && (read_back_data[2] == '\x01')) {
    printf("\n--- %s ok\n\n",DAT_00023028);
    return 1;
  }
  printf("\n--- %s failed!\n\n",DAT_00023028);
  return 0;
}


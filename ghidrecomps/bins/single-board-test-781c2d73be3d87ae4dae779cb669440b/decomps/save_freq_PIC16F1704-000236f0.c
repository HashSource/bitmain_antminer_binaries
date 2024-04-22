
/* WARNING: Unknown calling convention */

int save_freq_PIC16F1704(uint which_chain,uchar which_i2c,ushort freq)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  uint config_data;
  uchar send_data [8];
  
  send_data[5] = (uchar)freq;
  pbVar5 = send_data;
  iVar4 = (uint)send_data[5] + (uint)(freq >> 8) + 0x2a;
  send_data[4] = (uchar)(freq >> 8);
  send_data[6] = (uchar)((uint)iVar4 >> 8);
  send_data[7] = (uchar)iVar4;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '$';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  config_data = (uint)which_i2c << 0x1a | 0xa00000 | (which_chain & 0xff) << 0x10;
  while (i2c_write(uVar3 | config_data), send_data + 7 != pbVar5) {
    pbVar5 = pbVar5 + 1;
    uVar3 = (uint)*pbVar5;
  }
  usleep(300000);
  bVar1 = i2c_read(config_data);
  bVar2 = i2c_read(config_data);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((bVar1 == 0x24) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n",DAT_000237c8);
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",DAT_000237c8,
         (uint)bVar1,(uint)bVar2);
  return 0;
}



/* WARNING: Unknown calling convention */

int set_PIC16F1704_flash_pointer
              (uint which_i2c,uchar which_chain,uchar flash_addr_h,uchar flash_addr_l)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  ushort crc;
  int iVar4;
  byte *pbVar5;
  uint config_data;
  uchar send_data [8];
  
  iVar4 = (uint)flash_addr_h + (uint)flash_addr_l + 7;
  pbVar5 = send_data;
  send_data[0] = 'U';
  send_data[7] = (uchar)iVar4;
  send_data[6] = (uchar)((uint)iVar4 >> 8);
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '\x01';
  send_data[4] = flash_addr_h;
  send_data[5] = flash_addr_l;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  config_data = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  while (i2c_write(uVar3 | config_data), send_data + 7 != pbVar5) {
    pbVar5 = pbVar5 + 1;
    uVar3 = (uint)*pbVar5;
  }
  usleep(100000);
  bVar1 = i2c_read(config_data);
  bVar2 = i2c_read(config_data);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((bVar1 == 1) && (bVar2 == 1)) {
    printf("\n--- %s ok\n\n","set_PIC16F1704_flash_pointer");
    return 1;
  }
  printf("\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
         "set_PIC16F1704_flash_pointer",(uint)bVar1,(uint)bVar2);
  return 0;
}


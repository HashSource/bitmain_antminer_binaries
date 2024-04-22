
/* WARNING: Unknown calling convention */

int read_PIC16F1704_flash_pointer
              (uint which_i2c,uchar which_chain,uchar *flash_addr_h,uchar *flash_addr_l)

{
  uchar uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uchar *puVar5;
  uchar *puVar6;
  uint uVar7;
  uchar read_back_data [6];
  uchar auStack_32 [2];
  uchar send_data [6];
  
  send_data[2] = '\x04';
  pbVar4 = send_data;
  uVar7 = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '\b';
  send_data[4] = '\0';
  send_data[5] = '\f';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar2 = 0x55;
  while (i2c_write(uVar2 | uVar7), pbVar4 != send_data + 5) {
    pbVar4 = pbVar4 + 1;
    uVar2 = (uint)*pbVar4;
  }
  usleep(100000);
  puVar5 = read_back_data;
  do {
    uVar1 = i2c_read(uVar7);
    puVar6 = puVar5 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar6;
  } while (auStack_32 != puVar6);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  uVar2 = (uint)read_back_data._0_4_ >> 8 & 0xff;
  if ((uVar2 == 8) && ((read_back_data._0_4_ & 0xff) == 6)) {
    uVar2 = (uint)read_back_data[3];
    uVar7 = read_back_data[2] + uVar2 + 0xe;
    if ((uVar7 * 0x10000 >> 0x18 != (uint)read_back_data[4]) ||
       ((uVar7 & 0xff) != (uint)read_back_data[5])) {
      printf("\n--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
             ,DAT_0002256c,6,8,(uint)read_back_data[2],uVar2,(uint)read_back_data[4],
             (uint)read_back_data[5]);
      return 0;
    }
    *flash_addr_h = read_back_data[2];
    *flash_addr_l = read_back_data[3];
    printf("\n--- %s ok! flash_addr_h = 0x%02x, flash_addr_l = 0x%02x\n\n",DAT_0002256c,
           (uint)*flash_addr_h,uVar2);
    iVar3 = 1;
  }
  else {
    printf("\n--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
           ,DAT_0002256c,read_back_data._0_4_ & 0xff,uVar2,(uint)read_back_data[2],
           (uint)read_back_data[3],(uint)read_back_data[4],(uint)read_back_data[5]);
    iVar3 = 0;
  }
  return iVar3;
}


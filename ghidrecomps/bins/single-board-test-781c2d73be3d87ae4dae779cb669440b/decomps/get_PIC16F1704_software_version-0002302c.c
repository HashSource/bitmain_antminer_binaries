
/* WARNING: Unknown calling convention */

int get_PIC16F1704_software_version(uint which_i2c,uchar which_chain,uchar *version)

{
  uchar uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uchar *puVar5;
  uchar *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uchar read_back_data [5];
  uchar auStack_2b [3];
  uchar send_data [6];
  
  send_data[1] = 0xaa;
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  pbVar4 = send_data;
  send_data[2] = '\x04';
  uVar8 = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  send_data[3] = '\x17';
  send_data[4] = '\0';
  send_data[5] = '\x1b';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar2 = 0x55;
  while (i2c_write(uVar2 | uVar8), pbVar4 != send_data + 5) {
    pbVar4 = pbVar4 + 1;
    uVar2 = (uint)*pbVar4;
  }
  usleep(200000);
  puVar5 = read_back_data;
  do {
    uVar1 = i2c_read(uVar8);
    puVar6 = puVar5 + 1;
    *puVar5 = uVar1;
    puVar5 = puVar6;
  } while (puVar6 != auStack_2b);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  uVar9 = read_back_data._0_4_ & 0xff;
  uVar7 = (uint)read_back_data._0_4_ >> 8 & 0xff;
  uVar1 = read_back_data[2];
  uVar10 = (uint)read_back_data[2];
  uVar2 = (uint)read_back_data._0_4_ >> 0x18;
  uVar11 = (uint)read_back_data[4];
  uVar8 = uVar10;
  uVar12 = uVar2;
  uVar13 = uVar11;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n"
         ,DAT_00023158,uVar9,uVar7,uVar10,uVar2,uVar11);
  if (uVar7 == 0x17 && uVar9 == 5) {
    uVar7 = uVar10 + 0x1c;
    uVar9 = uVar7 * 0x10000 >> 0x18;
    if ((uVar9 != uVar2) || (uVar9 = uVar7 & 0xff, uVar11 != uVar9)) {
      printf("\n--- %s failed! crc = 0x%04x\n\n",DAT_00023158,uVar7,uVar9,uVar8,uVar12,uVar13);
      return 0;
    }
    *version = uVar1;
    printf("\n--- %s ok, version = 0x%02x\n\n",DAT_00023158,uVar10,uVar9,uVar8,uVar12,uVar13);
    iVar3 = 1;
  }
  else {
    printf("\n--- %s failed!\n\n",DAT_00023158);
    iVar3 = 0;
  }
  return iVar3;
}


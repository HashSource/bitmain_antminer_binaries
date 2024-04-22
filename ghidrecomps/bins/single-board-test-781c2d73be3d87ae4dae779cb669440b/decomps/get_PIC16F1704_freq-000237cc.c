
/* WARNING: Unknown calling convention */

int get_PIC16F1704_freq(uint which_chain,uchar which_i2c,ushort *freq)

{
  undefined4 uVar1;
  uchar uVar2;
  uchar uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  uchar *puVar7;
  uchar *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uchar read_back_data [6];
  uchar auStack_2a [2];
  uchar send_data [6];
  
  send_data[1] = 0xaa;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  pbVar6 = send_data;
  send_data[0] = 'U';
  uVar10 = (uint)which_i2c << 0x1a | 0xa00000 | (which_chain & 0xff) << 0x10;
  send_data[2] = '\x04';
  send_data[3] = '%';
  send_data[4] = '\0';
  send_data[5] = ')';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar4 = 0x55;
  while (i2c_write(uVar4 | uVar10), pbVar6 != send_data + 5) {
    pbVar6 = pbVar6 + 1;
    uVar4 = (uint)*pbVar6;
  }
  usleep(300000);
  puVar7 = read_back_data;
  do {
    uVar3 = i2c_read(uVar10);
    puVar8 = puVar7 + 1;
    *puVar7 = uVar3;
    puVar7 = puVar8;
  } while (puVar8 != auStack_2a);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  uVar11 = read_back_data._0_4_ & 0xff;
  uVar9 = (uint)read_back_data._0_4_ >> 8 & 0xff;
  uVar3 = read_back_data[2];
  uVar13 = (uint)read_back_data[2];
  uVar2 = read_back_data[3];
  uVar12 = (uint)read_back_data[3];
  uVar14 = (uint)read_back_data[4];
  uVar15 = (uint)read_back_data[5];
  uVar4 = uVar13;
  uVar10 = uVar12;
  uVar16 = uVar14;
  uVar17 = uVar15;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
         ,DAT_00023910,uVar11,uVar9,uVar13,uVar12,uVar14,uVar15);
  uVar1 = DAT_00023910;
  if (uVar9 == 0x25 && uVar11 == 6) {
    uVar9 = uVar13 + uVar12 + 0x2b;
    uVar11 = uVar9 * 0x10000 >> 0x18;
    if ((uVar11 != uVar14) || (uVar11 = uVar9 & 0xff, uVar15 != uVar11)) {
      printf("\n--- %s failed! crc = 0x%04x\n\n",DAT_00023910,uVar9,uVar11,uVar4,uVar10,uVar16,
             uVar17);
      return 0;
    }
    *freq = CONCAT11(uVar3,uVar2);
    printf("\n--- %s ok, freq = %d\n\n",uVar1,(uint)CONCAT11(uVar3,uVar2),uVar11,uVar4,uVar10,uVar16
           ,uVar17);
    iVar5 = 1;
  }
  else {
    printf("\n--- %s failed!\n\n",DAT_00023910);
    iVar5 = 0;
  }
  return iVar5;
}


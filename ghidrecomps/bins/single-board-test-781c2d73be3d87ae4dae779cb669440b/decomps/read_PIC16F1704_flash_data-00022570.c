
/* WARNING: Unknown calling convention */

int read_PIC16F1704_flash_data(uint which_i2c,uchar which_chain,uchar *buf)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uchar uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uchar *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uchar send_data [6];
  uchar uStack_3d;
  uchar read_back_data [20];
  
  send_data[1] = 0xaa;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[11] = '\0';
  read_back_data[12] = '\0';
  read_back_data[13] = '\0';
  read_back_data[14] = '\0';
  read_back_data[15] = '\0';
  read_back_data[16] = '\0';
  read_back_data[17] = '\0';
  read_back_data[18] = '\0';
  read_back_data[19] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[2] = '\x04';
  pbVar9 = send_data;
  send_data[3] = '\x03';
  uVar15 = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  send_data[4] = '\0';
  send_data[5] = '\a';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar5 = 0x55;
  while (i2c_write(uVar5 | uVar15), send_data + 5 != pbVar9) {
    pbVar9 = pbVar9 + 1;
    uVar5 = (uint)*pbVar9;
  }
  puVar12 = &uStack_3d;
  usleep(300000);
  do {
    uVar4 = i2c_read(uVar15);
    puVar12 = puVar12 + 1;
    *puVar12 = uVar4;
  } while (read_back_data + 0x13 != puVar12);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  uVar10 = read_back_data._8_4_ & 0xff;
  uVar7 = (uint)read_back_data._8_4_ >> 0x10 & 0xff;
  uVar5 = (uint)read_back_data._8_4_ >> 0x18;
  uVar16 = read_back_data._12_4_ & 0xff;
  uVar18 = (uint)read_back_data._12_4_ >> 8 & 0xff;
  uVar11 = (uint)read_back_data._8_4_ >> 8 & 0xff;
  uVar20 = (uint)read_back_data._12_4_ >> 0x10 & 0xff;
  uVar8 = read_back_data._16_4_ & 0xff;
  uVar15 = (uint)read_back_data._12_4_ >> 0x18;
  uVar13 = (uint)read_back_data._16_4_ >> 8 & 0xff;
  uVar17 = (uint)read_back_data._16_4_ >> 0x10 & 0xff;
  uVar1 = (uint)read_back_data._16_4_ >> 0x18;
  uVar21 = (uint)read_back_data._0_4_ >> 8 & 0xff;
  uVar14 = (uint)read_back_data._0_4_ >> 0x10 & 0xff;
  uVar19 = read_back_data._0_4_ & 0xff;
  uVar2 = (uint)read_back_data._0_4_ >> 0x18;
  uVar24 = read_back_data._4_4_ & 0xff;
  uVar23 = (uint)read_back_data._4_4_ >> 8 & 0xff;
  uVar22 = (uint)read_back_data._4_4_ >> 0x10 & 0xff;
  uVar3 = (uint)read_back_data._4_4_ >> 0x18;
  uVar25 = uVar14;
  uVar26 = uVar2;
  uVar27 = uVar24;
  uVar28 = uVar23;
  uVar29 = uVar22;
  uVar30 = uVar3;
  uVar31 = uVar10;
  uVar32 = uVar11;
  uVar33 = uVar7;
  uVar34 = uVar5;
  uVar35 = uVar16;
  uVar36 = uVar18;
  uVar37 = uVar20;
  uVar38 = uVar15;
  uVar39 = uVar8;
  uVar40 = uVar13;
  uVar41 = uVar17;
  uVar42 = uVar1;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,         read_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,         read_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x,         read_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x,         read_back_data[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n"
         ,DAT_0002277c,uVar19,uVar21,uVar14,uVar2,uVar24,uVar23,uVar22,uVar3,uVar10,uVar11,uVar7,
         uVar5,uVar16,uVar18,uVar20,uVar15,uVar8,uVar13,uVar17,uVar1);
  usleep(100000);
  if (uVar19 == 0x14 && uVar21 == 3) {
    uVar13 = uVar14 + uVar2 + 0x17 + uVar24 + uVar23 + uVar22 + uVar3 + uVar10 + uVar11 + uVar7 +
             uVar5 + uVar16 + uVar18 + uVar20 + uVar15 + uVar8 + uVar13;
    uVar5 = uVar13 & 0xffff;
    if ((uVar17 != uVar5 >> 8) || (uVar17 = uVar13 & 0xff, uVar1 != uVar17)) {
      printf("\n--- %s failed! crc = 0x%04x\n\n",DAT_0002277c,uVar5,uVar17,uVar25,uVar26,uVar27,
             uVar28,uVar29,uVar30,uVar31,uVar32,uVar33,uVar34,uVar35,uVar36,uVar37,uVar38,uVar39,
             uVar40,uVar41,uVar42);
      return 0;
    }
    pbVar9 = read_back_data + 2;
    puVar12 = buf + -1;
    while( true ) {
      puVar12 = puVar12 + 1;
      *puVar12 = (uchar)uVar14;
      if (pbVar9 == read_back_data + 0x11) break;
      pbVar9 = pbVar9 + 1;
      uVar14 = (uint)*pbVar9;
    }
    printf("\n--- %s ok\n\n",DAT_0002277c,pbVar9,puVar12,uVar25,uVar26,uVar27,uVar28,uVar29,uVar30,
           uVar31,uVar32,uVar33,uVar34,uVar35,uVar36,uVar37,uVar38,uVar39,uVar40,uVar41,uVar42);
    iVar6 = 1;
  }
  else {
    printf("\n--- %s failed!\n\n",DAT_0002277c);
    iVar6 = 0;
  }
  return iVar6;
}


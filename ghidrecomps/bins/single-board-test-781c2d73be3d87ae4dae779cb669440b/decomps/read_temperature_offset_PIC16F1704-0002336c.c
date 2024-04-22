
/* WARNING: Unknown calling convention */

int read_temperature_offset_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  uint uVar1;
  uchar uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uchar *puVar8;
  uint uVar9;
  uchar *puVar10;
  uint uVar11;
  uint uVar12;
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
  uchar send_data [6];
  uchar read_back_data [12];
  uchar auStack_28 [4];
  
  send_data[1] = 0xaa;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[11] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[2] = '\x04';
  pbVar6 = send_data;
  send_data[3] = '#';
  uVar12 = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  send_data[4] = '\0';
  send_data[5] = '\'';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar3 = 0x55;
  while (i2c_write(uVar3 | uVar12), send_data + 5 != pbVar6) {
    pbVar6 = pbVar6 + 1;
    uVar3 = (uint)*pbVar6;
  }
  usleep(200000);
  puVar8 = read_back_data;
  do {
    uVar2 = i2c_read(uVar12);
    puVar10 = puVar8 + 1;
    *puVar8 = uVar2;
    puVar8 = puVar10;
  } while (puVar10 != auStack_28);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  uVar5 = (uint)read_back_data._0_4_ >> 0x10 & 0xff;
  uVar3 = (uint)read_back_data._0_4_ >> 0x18;
  uVar16 = read_back_data._4_4_ & 0xff;
  uVar12 = (uint)read_back_data._4_4_ >> 0x18;
  uVar7 = (uint)read_back_data._0_4_ >> 8 & 0xff;
  uVar9 = read_back_data._0_4_ & 0xff;
  uVar11 = read_back_data._8_4_ & 0xff;
  uVar15 = (uint)read_back_data._4_4_ >> 8 & 0xff;
  uVar14 = (uint)read_back_data._4_4_ >> 0x10 & 0xff;
  uVar13 = (uint)read_back_data._8_4_ >> 8 & 0xff;
  uVar17 = (uint)read_back_data._8_4_ >> 0x10 & 0xff;
  uVar1 = (uint)read_back_data._8_4_ >> 0x18;
  uVar18 = uVar5;
  uVar19 = uVar3;
  uVar20 = uVar16;
  uVar21 = uVar15;
  uVar22 = uVar14;
  uVar23 = uVar12;
  uVar24 = uVar11;
  uVar25 = uVar13;
  uVar26 = uVar17;
  uVar27 = uVar1;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,         read_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,         read_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n"
         ,DAT_000234fc,uVar9,uVar7,uVar5,uVar3,uVar16,uVar15,uVar14,uVar12,uVar11,uVar13,uVar17,
         uVar1);
  if (uVar9 == 0xc && uVar7 == 0x23) {
    uVar13 = uVar3 + uVar5 + 0x2f + uVar16 + uVar15 + uVar14 + uVar12 + uVar11 + uVar13;
    if ((uVar17 != uVar13 >> 8) || (uVar11 = uVar13 & 0xff, uVar1 != uVar11)) {
      printf("\n--- %s failed! crc = 0x%04x\n\n",DAT_000234fc,uVar13,uVar11,uVar18,uVar19,uVar20,
             uVar21,uVar22,uVar23,uVar24,uVar25,uVar26,uVar27);
      return 0;
    }
    puVar8 = buf + -1;
    pbVar6 = read_back_data + 2;
    while( true ) {
      puVar8 = puVar8 + 1;
      *puVar8 = (uchar)uVar5;
      if (buf + 7 == puVar8) break;
      pbVar6 = pbVar6 + 1;
      uVar5 = (uint)*pbVar6;
    }
    printf("\n--- %s ok\n\n",DAT_000234fc,puVar8,buf + 7,uVar18,uVar19,uVar20,uVar21,uVar22,uVar23,
           uVar24,uVar25,uVar26,uVar27);
    iVar4 = 1;
  }
  else {
    printf("\n--- %s failed!\n\n",DAT_000234fc,uVar7,uVar9,uVar18,uVar19,uVar20,uVar21,uVar22,uVar23
           ,uVar24,uVar25,uVar26,uVar27);
    iVar4 = 0;
  }
  return iVar4;
}



/* WARNING: Unknown calling convention */

int read_hash_id_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  uint uVar1;
  uint uVar2;
  uchar uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uchar *puVar11;
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
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uchar send_data [6];
  uchar uStack_39;
  uchar read_back_data [16];
  
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
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  pbVar9 = send_data;
  send_data[2] = '\x04';
  uVar12 = (uint)which_chain << 0x10 | 0xa00000 | which_i2c << 0x1a;
  send_data[3] = '\x13';
  send_data[4] = '\0';
  send_data[5] = '\x17';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  uVar4 = 0x55;
  while (i2c_write(uVar4 | uVar12), send_data + 5 != pbVar9) {
    pbVar9 = pbVar9 + 1;
    uVar4 = (uint)*pbVar9;
  }
  puVar11 = &uStack_39;
  usleep(200000);
  do {
    uVar3 = i2c_read(uVar12);
    puVar11 = puVar11 + 1;
    *puVar11 = uVar3;
  } while (read_back_data + 0xf != puVar11);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  uVar4 = (uint)read_back_data._4_4_ >> 0x18;
  uVar10 = read_back_data._4_4_ & 0xff;
  uVar6 = (uint)read_back_data._4_4_ >> 8 & 0xff;
  uVar18 = read_back_data._8_4_ & 0xff;
  uVar7 = (uint)read_back_data._4_4_ >> 0x10 & 0xff;
  uVar19 = (uint)read_back_data._8_4_ >> 8 & 0xff;
  uVar20 = (uint)read_back_data._8_4_ >> 0x10 & 0xff;
  uVar13 = (uint)read_back_data._0_4_ >> 0x10 & 0xff;
  uVar8 = (uint)read_back_data._12_4_ >> 8 & 0xff;
  uVar12 = (uint)read_back_data._0_4_ >> 0x18;
  uVar1 = (uint)read_back_data._12_4_ >> 0x18;
  uVar14 = read_back_data._0_4_ & 0xff;
  uVar15 = (uint)read_back_data._0_4_ >> 8 & 0xff;
  uVar2 = (uint)read_back_data._8_4_ >> 0x18;
  uVar16 = read_back_data._12_4_ & 0xff;
  uVar17 = (uint)read_back_data._12_4_ >> 0x10 & 0xff;
  uVar21 = uVar13;
  uVar22 = uVar12;
  uVar23 = uVar10;
  uVar24 = uVar6;
  uVar25 = uVar7;
  uVar26 = uVar4;
  uVar27 = uVar18;
  uVar28 = uVar19;
  uVar29 = uVar20;
  uVar30 = uVar2;
  uVar31 = uVar16;
  uVar32 = uVar8;
  uVar33 = uVar17;
  uVar34 = uVar1;
  printf("--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,        read_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,        read_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x,        read_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n"
         ,DAT_00022e68,uVar14,uVar15,uVar13,uVar12,uVar10,uVar6,uVar7,uVar4,uVar18,uVar19,uVar20,
         uVar2,uVar16,uVar8,uVar17,uVar1);
  if (uVar14 == 0x10 && uVar15 == 0x13) {
    uVar4 = uVar10 + uVar13 + uVar12 + 0x23 + uVar6 + uVar7 + uVar4 + uVar18 + uVar19 + uVar20 +
            uVar2 + uVar16 + uVar8;
    uVar12 = uVar4 & 0xffff;
    if ((uVar17 != uVar12 >> 8) || (uVar8 = uVar4 & 0xff, uVar1 != uVar8)) {
      printf("\n--- %s failed! crc = 0x%04x\n\n",DAT_00022e68,uVar12,uVar8,uVar21,uVar22,uVar23,
             uVar24,uVar25,uVar26,uVar27,uVar28,uVar29,uVar30,uVar31,uVar32,uVar33,uVar34);
      return 0;
    }
    pbVar9 = read_back_data + 2;
    puVar11 = buf + -1;
    while( true ) {
      puVar11 = puVar11 + 1;
      *puVar11 = (uchar)uVar13;
      if (buf + 0xb == puVar11) break;
      pbVar9 = pbVar9 + 1;
      uVar13 = (uint)*pbVar9;
    }
    printf("\n--- %s ok\n\n",DAT_00022e68,buf + 0xb,puVar11,uVar21,uVar22,uVar23,uVar24,uVar25,
           uVar26,uVar27,uVar28,uVar29,uVar30,uVar31,uVar32,uVar33,uVar34);
    iVar5 = 1;
  }
  else {
    printf("\n--- %s failed!\n\n",DAT_00022e68);
    iVar5 = 0;
  }
  return iVar5;
}


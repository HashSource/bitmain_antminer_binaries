
void md5_block_data_order(int *param_1,byte *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
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
  uint local_6c;
  int local_30;
  
  iVar1 = *param_1;
  local_6c = param_1[1];
  uVar8 = param_1[2];
  uVar10 = param_1[3];
  local_30 = param_3;
  if (param_3 != 0) {
    do {
      uVar2 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
              (uint)param_2[3] << 0x18;
      uVar5 = ((uVar10 ^ uVar8) & local_6c ^ uVar10) + 0xd76aa478 + uVar2 + iVar1;
      HintPreloadData(param_2 + 0x41);
      uVar25 = (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 | (uint)param_2[4] |
               (uint)param_2[7] << 0x18;
      uVar6 = local_6c + (uVar5 >> 0x19 | uVar5 * 0x80);
      uVar3 = (uint)param_2[10] << 0x10 | (uint)param_2[9] << 8 | (uint)param_2[8] |
              (uint)param_2[0xb] << 0x18;
      uVar5 = uVar10 + 0xe8c7b756 + uVar25 + ((uVar8 ^ local_6c) & uVar6 ^ uVar8);
      uVar9 = uVar6 + (uVar5 >> 0x14 | uVar5 * 0x1000);
      uVar11 = (uint)param_2[0xe] << 0x10 | (uint)param_2[0xd] << 8 | (uint)param_2[0xc] |
               (uint)param_2[0xf] << 0x18;
      uVar5 = uVar8 + 0x242070db + uVar3 + ((uVar6 ^ local_6c) & uVar9 ^ local_6c);
      uVar20 = uVar9 + (uVar5 >> 0xf | uVar5 * 0x20000);
      uVar5 = (uint)param_2[0x12] << 0x10 | (uint)param_2[0x11] << 8 | (uint)param_2[0x10] |
              (uint)param_2[0x13] << 0x18;
      uVar4 = local_6c + 0xc1bdceee + uVar11 + ((uVar9 ^ uVar6) & uVar20 ^ uVar6);
      uVar18 = uVar20 + (uVar4 >> 10 | uVar4 * 0x400000);
      uVar12 = (uint)param_2[0x16] << 0x10 | (uint)param_2[0x15] << 8 | (uint)param_2[0x14] |
               (uint)param_2[0x17] << 0x18;
      uVar4 = uVar5 + 0xf57c0faf + uVar6 + ((uVar20 ^ uVar9) & uVar18 ^ uVar9);
      uVar14 = uVar18 + (uVar4 >> 0x19 | uVar4 * 0x80);
      uVar6 = (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x19] << 8 | (uint)param_2[0x18] |
              (uint)param_2[0x1b] << 0x18;
      uVar4 = uVar12 + 0x4787c62a + uVar9 + ((uVar18 ^ uVar20) & uVar14 ^ uVar20);
      uVar13 = uVar14 + (uVar4 >> 0x14 | uVar4 * 0x1000);
      uVar7 = (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 | (uint)param_2[0x1c] |
              (uint)param_2[0x1f] << 0x18;
      uVar4 = uVar6 + 0xa8304613 + uVar20 + (uVar13 & (uVar14 ^ uVar18) ^ uVar18);
      uVar4 = uVar13 + (uVar4 >> 0xf | uVar4 * 0x20000);
      uVar20 = (uint)param_2[0x22] << 0x10 | (uint)param_2[0x21] << 8 | (uint)param_2[0x20] |
               (uint)param_2[0x23] << 0x18;
      uVar9 = uVar7 + 0xfd469501 + uVar18 + ((uVar13 ^ uVar14) & uVar4 ^ uVar14);
      uVar9 = uVar4 + (uVar9 >> 10 | uVar9 * 0x400000);
      uVar14 = uVar20 + 0x698098d8 + uVar14 + ((uVar4 ^ uVar13) & uVar9 ^ uVar13);
      uVar14 = uVar9 + (uVar14 >> 0x19 | uVar14 * 0x80);
      HintPreloadData(param_2 + 0x42);
      HintPreloadData(param_2 + 0x43);
      uVar22 = (uint)param_2[0x26] << 0x10 | (uint)param_2[0x25] << 8 | (uint)param_2[0x24] |
               (uint)param_2[0x27] << 0x18;
      uVar15 = (uint)param_2[0x2a] << 0x10 | (uint)param_2[0x29] << 8 | (uint)param_2[0x28] |
               (uint)param_2[0x2b] << 0x18;
      uVar13 = uVar13 + uVar22 + 0x8b44f7af + ((uVar9 ^ uVar4) & uVar14 ^ uVar4);
      uVar13 = uVar14 + (uVar13 >> 0x14 | uVar13 * 0x1000);
      uVar16 = (uint)param_2[0x2e] << 0x10 | (uint)param_2[0x2d] << 8 | (uint)param_2[0x2c] |
               (uint)param_2[0x2f] << 0x18;
      uVar4 = uVar4 + (uVar15 - 0xa44f) + ((uVar14 ^ uVar9) & uVar13 ^ uVar9);
      uVar4 = uVar13 + (uVar4 >> 0xf | uVar4 * 0x20000);
      uVar9 = uVar16 + 0x895cd7be + uVar9 + (uVar4 & (uVar13 ^ uVar14) ^ uVar14);
      uVar21 = (uint)param_2[0x32] << 0x10 | (uint)param_2[0x31] << 8 | (uint)param_2[0x30] |
               (uint)param_2[0x33] << 0x18;
      uVar9 = uVar4 + (uVar9 >> 10 | uVar9 * 0x400000);
      uVar23 = (uint)param_2[0x36] << 0x10 | (uint)param_2[0x35] << 8 | (uint)param_2[0x34] |
               (uint)param_2[0x37] << 0x18;
      uVar14 = uVar21 + 0x6b901122 + uVar14 + (uVar9 & (uVar4 ^ uVar13) ^ uVar13);
      uVar14 = uVar9 + (uVar14 >> 0x19 | uVar14 * 0x80);
      uVar17 = (uint)param_2[0x3a] << 0x10 | (uint)param_2[0x39] << 8 | (uint)param_2[0x38] |
               (uint)param_2[0x3b] << 0x18;
      uVar13 = ((uVar9 ^ uVar4) & uVar14 ^ uVar4) + uVar23 + 0xfd987193 + uVar13;
      uVar13 = uVar14 + (uVar13 >> 0x14 | uVar13 * 0x1000);
      uVar4 = uVar17 + 0xa679438e + uVar4 + ((uVar14 ^ uVar9) & uVar13 ^ uVar9);
      uVar18 = (uint)param_2[0x3e] << 0x10 | (uint)param_2[0x3d] << 8 | (uint)param_2[0x3c] |
               (uint)param_2[0x3f] << 0x18;
      uVar19 = uVar13 + (uVar4 >> 0xf | uVar4 * 0x20000);
      uVar4 = uVar9 + uVar18 + 0x49b40821 + ((uVar13 ^ uVar14) & uVar19 ^ uVar14);
      uVar4 = uVar19 + (uVar4 >> 10 | uVar4 * 0x400000);
      uVar9 = uVar25 + 0xf61e2562 + uVar14 + ((uVar4 ^ uVar19) & uVar13 ^ uVar19);
      uVar14 = uVar4 + (uVar9 >> 0x1b | uVar9 * 0x20);
      uVar9 = ((uVar14 ^ uVar4) & uVar19 ^ uVar4) + uVar13 + uVar6 + 0xc040b340;
      uVar13 = uVar14 + (uVar9 >> 0x17 | uVar9 * 0x200);
      uVar9 = uVar16 + 0x265e5a51 + uVar19 + (uVar4 & (uVar13 ^ uVar14) ^ uVar14);
      uVar19 = uVar13 + (uVar9 >> 0x12 | uVar9 * 0x4000);
      uVar4 = uVar2 + 0xe9b6c7aa + uVar4 + ((uVar19 ^ uVar13) & uVar14 ^ uVar13);
      uVar4 = uVar19 + (uVar4 >> 0xc | uVar4 * 0x100000);
      param_2 = param_2 + 0x40;
      HintPreloadData(param_2);
      uVar9 = ((uVar4 ^ uVar19) & uVar13 ^ uVar19) + uVar12 + 0xd62f105d + uVar14;
      uVar14 = uVar4 + (uVar9 >> 0x1b | uVar9 * 0x20);
      uVar9 = ((uVar14 ^ uVar4) & uVar19 ^ uVar4) + uVar15 + 0x2441453 + uVar13;
      uVar13 = uVar14 + (uVar9 >> 0x17 | uVar9 * 0x200);
      uVar9 = ((uVar13 ^ uVar14) & uVar4 ^ uVar14) + uVar18 + 0xd8a1e681 + uVar19;
      uVar24 = uVar13 + (uVar9 >> 0x12 | uVar9 * 0x4000);
      uVar4 = uVar5 + 0xe7d3fbc8 + uVar4 + (uVar14 & (uVar24 ^ uVar13) ^ uVar13);
      uVar9 = uVar24 + (uVar4 >> 0xc | uVar4 * 0x100000);
      uVar4 = uVar22 + 0x21e1cde6 + uVar14 + ((uVar9 ^ uVar24) & uVar13 ^ uVar24);
      uVar26 = uVar9 + (uVar4 >> 0x1b | uVar4 * 0x20);
      uVar4 = ((uVar26 ^ uVar9) & uVar24 ^ uVar9) + uVar17 + 0xc33707d6 + uVar13;
      uVar19 = uVar26 + (uVar4 >> 0x17 | uVar4 * 0x200);
      uVar4 = uVar11 + 0xf4d50d87 + uVar24 + (uVar9 & (uVar19 ^ uVar26) ^ uVar26);
      uVar4 = uVar19 + (uVar4 >> 0x12 | uVar4 * 0x4000);
      uVar9 = uVar20 + 0x455a14ed + uVar9 + ((uVar4 ^ uVar19) & uVar26 ^ uVar19);
      uVar14 = uVar4 + (uVar9 >> 0xc | uVar9 * 0x100000);
      uVar9 = ((uVar14 ^ uVar4) & uVar19 ^ uVar4) + uVar23 + 0xa9e3e905 + uVar26;
      uVar13 = uVar14 + (uVar9 >> 0x1b | uVar9 * 0x20);
      uVar9 = ((uVar13 ^ uVar14) & uVar4 ^ uVar14) + uVar3 + 0xfcefa3f8 + uVar19;
      uVar9 = uVar13 + (uVar9 >> 0x17 | uVar9 * 0x200);
      uVar4 = ((uVar9 ^ uVar13) & uVar14 ^ uVar13) + uVar7 + 0x676f02d9 + uVar4;
      uVar4 = uVar9 + (uVar4 >> 0x12 | uVar4 * 0x4000);
      uVar14 = uVar21 + 0x8d2a4c8a + uVar14 + ((uVar4 ^ uVar9) & uVar13 ^ uVar9);
      uVar19 = uVar4 + (uVar14 >> 0xc | uVar14 * 0x100000);
      uVar14 = (uVar19 ^ uVar4 ^ uVar9) + (uVar12 - 0x5c6be) + uVar13;
      uVar14 = uVar19 + (uVar14 >> 0x1c | uVar14 * 0x10);
      uVar9 = (uVar19 ^ uVar4 ^ uVar14) + uVar20 + 0x8771f681 + uVar9;
      uVar9 = uVar14 + (uVar9 >> 0x15 | uVar9 * 0x800);
      uVar4 = (uVar14 ^ uVar19 ^ uVar9) + uVar16 + 0x6d9d6122 + uVar4;
      uVar24 = uVar9 + (uVar4 >> 0x10 | uVar4 * 0x10000);
      uVar4 = uVar17 + 0xfde5380c + uVar19 + (uVar9 ^ uVar14 ^ uVar24);
      uVar13 = uVar24 + (uVar4 >> 9 | uVar4 * 0x800000);
      uVar4 = uVar25 + 0xa4beea44 + uVar14 + (uVar24 ^ uVar9 ^ uVar13);
      uVar14 = uVar13 + (uVar4 >> 0x1c | uVar4 * 0x10);
      uVar4 = uVar5 + 0x4bdecfa9 + uVar9 + (uVar13 ^ uVar24 ^ uVar14);
      uVar9 = uVar14 + (uVar4 >> 0x15 | uVar4 * 0x800);
      uVar4 = uVar7 + 0xf6bb4b60 + uVar24 + (uVar14 ^ uVar13 ^ uVar9);
      uVar4 = uVar9 + (uVar4 >> 0x10 | uVar4 * 0x10000);
      uVar13 = uVar13 + uVar15 + 0xbebfbc70 + (uVar9 ^ uVar14 ^ uVar4);
      uVar13 = uVar4 + (uVar13 >> 9 | uVar13 * 0x800000);
      uVar14 = (uVar4 ^ uVar9 ^ uVar13) + uVar14 + uVar23 + 0x289b7ec6;
      uVar14 = uVar13 + (uVar14 >> 0x1c | uVar14 * 0x10);
      uVar9 = uVar2 + 0xeaa127fa + uVar9 + (uVar13 ^ uVar4 ^ uVar14);
      uVar9 = uVar14 + (uVar9 >> 0x15 | uVar9 * 0x800);
      uVar4 = uVar11 + 0xd4ef3085 + uVar4 + (uVar14 ^ uVar13 ^ uVar9);
      uVar19 = uVar9 + (uVar4 >> 0x10 | uVar4 * 0x10000);
      uVar4 = (uVar9 ^ uVar14 ^ uVar19) + uVar13 + uVar6 + 0x4881d05;
      uVar13 = uVar19 + (uVar4 >> 9 | uVar4 * 0x800000);
      uVar4 = (uVar19 ^ uVar9 ^ uVar13) + uVar14 + uVar22 + 0xd9d4d039;
      uVar4 = uVar13 + (uVar4 >> 0x1c | uVar4 * 0x10);
      uVar9 = uVar9 + uVar21 + 0xe6db99e5 + (uVar13 ^ uVar19 ^ uVar4);
      uVar9 = uVar4 + (uVar9 >> 0x15 | uVar9 * 0x800);
      uVar14 = (uVar4 ^ uVar13 ^ uVar9) + uVar19 + uVar18 + 0x1fa27cf8;
      uVar14 = uVar9 + (uVar14 >> 0x10 | uVar14 * 0x10000);
      uVar13 = uVar3 + 0xc4ac5665 + uVar13 + (uVar9 ^ uVar4 ^ uVar14);
      uVar13 = uVar14 + (uVar13 >> 9 | uVar13 * 0x800000);
      uVar2 = uVar4 + uVar2 + 0xf4292244 + ((uVar13 | ~uVar9) ^ uVar14);
      uVar2 = uVar13 + (uVar2 >> 0x1a | uVar2 * 0x40);
      uVar4 = uVar7 + 0x432aff97 + uVar9 + ((uVar2 | ~uVar14) ^ uVar13);
      uVar4 = uVar2 + (uVar4 >> 0x16 | uVar4 * 0x400);
      uVar9 = uVar14 + uVar17 + 0xab9423a7 + ((uVar4 | ~uVar13) ^ uVar2);
      uVar9 = uVar4 + (uVar9 >> 0x11 | uVar9 * 0x8000);
      uVar7 = uVar12 + 0xfc93a039 + uVar13 + ((uVar9 | ~uVar2) ^ uVar4);
      uVar7 = uVar9 + (uVar7 >> 0xb | uVar7 * 0x200000);
      uVar2 = uVar2 + uVar21 + 0x655b59c3 + ((uVar7 | ~uVar4) ^ uVar9);
      uVar2 = uVar7 + (uVar2 >> 0x1a | uVar2 * 0x40);
      uVar4 = uVar11 + 0x8f0ccc92 + uVar4 + ((uVar2 | ~uVar9) ^ uVar7);
      uVar4 = uVar2 + (uVar4 >> 0x16 | uVar4 * 0x400);
      uVar9 = (uVar15 - 0x100b83) + uVar9 + ((uVar4 | ~uVar7) ^ uVar2);
      uVar9 = uVar4 + (uVar9 >> 0x11 | uVar9 * 0x8000);
      uVar7 = uVar25 + 0x85845dd1 + uVar7 + ((uVar9 | ~uVar2) ^ uVar4);
      uVar14 = uVar9 + (uVar7 >> 0xb | uVar7 * 0x200000);
      uVar2 = uVar20 + 0x6fa87e4f + uVar2 + ((uVar14 | ~uVar4) ^ uVar9);
      uVar20 = uVar14 + (uVar2 >> 0x1a | uVar2 * 0x40);
      uVar2 = uVar18 + 0xfe2ce6e0 + uVar4 + ((uVar20 | ~uVar9) ^ uVar14);
      uVar7 = uVar20 + (uVar2 >> 0x16 | uVar2 * 0x400);
      uVar2 = uVar6 + 0xa3014314 + uVar9 + ((uVar7 | ~uVar14) ^ uVar20);
      uVar4 = uVar7 + (uVar2 >> 0x11 | uVar2 * 0x8000);
      uVar2 = uVar23 + 0x4e0811a1 + uVar14 + ((uVar4 | ~uVar20) ^ uVar7);
      uVar2 = uVar4 + (uVar2 >> 0xb | uVar2 * 0x200000);
      uVar5 = uVar5 + 0xf7537e82 + uVar20 + ((uVar2 | ~uVar7) ^ uVar4);
      uVar5 = uVar2 + (uVar5 >> 0x1a | uVar5 * 0x40);
      iVar1 = iVar1 + uVar5;
      *param_1 = iVar1;
      uVar6 = uVar16 + 0xbd3af235 + uVar7 + ((uVar5 | ~uVar4) ^ uVar2);
      uVar6 = uVar5 + (uVar6 >> 0x16 | uVar6 * 0x400);
      uVar10 = uVar10 + uVar6;
      uVar4 = uVar3 + 0x2ad7d2bb + uVar4 + ((uVar6 | ~uVar2) ^ uVar5);
      uVar4 = uVar6 + (uVar4 >> 0x11 | uVar4 * 0x8000);
      param_1[3] = uVar10;
      uVar8 = uVar8 + uVar4;
      uVar2 = uVar22 + 0xeb86d391 + uVar2 + (uVar6 ^ (uVar4 | ~uVar5));
      param_1[2] = uVar8;
      local_6c = local_6c + uVar4 + (uVar2 >> 0xb | uVar2 * 0x200000);
      param_1[1] = local_6c;
      local_30 = local_30 + -1;
    } while (local_30 != 0);
  }
  return;
}


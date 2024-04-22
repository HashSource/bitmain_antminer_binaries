
void sha512_block_data_order(uint *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
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
  uint uVar27;
  uint uVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  int iVar33;
  uint uVar34;
  bool bVar35;
  uint local_dd0;
  uint local_dcc;
  uint local_dc8;
  uint local_dc4;
  uint local_dc0;
  uint local_dbc;
  uint local_db8;
  uint local_db4;
  uint local_db0;
  uint local_dac;
  uint local_da8;
  uint local_da4;
  uint local_da0;
  uint local_d9c;
  uint local_d98;
  uint local_d94;
  uint local_d90;
  uint local_d8c;
  uint local_d88;
  uint local_d84;
  uint local_d80;
  uint local_d7c;
  uint local_d78;
  uint local_d74;
  uint local_d70;
  uint local_d6c;
  uint local_d68;
  uint local_d64;
  uint local_d60;
  uint local_d5c;
  uint local_d58;
  uint local_d54;
  uint local_d50;
  uint local_d4c;
  uint local_d48;
  uint local_d44;
  uint local_d40;
  uint local_d3c;
  uint local_d38;
  uint local_d34;
  uint local_d30;
  uint local_d2c;
  uint local_d28;
  uint local_d24;
  uint local_d20;
  uint local_d1c;
  uint local_d18;
  uint local_d14;
  uint local_d10;
  uint local_d0c;
  uint *local_d00;
  int local_cf0;
  uint local_ce0;
  uint local_cdc;
  uint local_cd8;
  uint local_cd4;
  uint local_6c8;
  uint uStack_6c4;
  uint local_6c0;
  uint uStack_6bc;
  uint local_6b8;
  uint uStack_6b4;
  uint local_6b0;
  uint uStack_6ac;
  uint local_6a8;
  uint uStack_6a4;
  uint local_6a0;
  uint uStack_69c;
  int local_28;
  
  if (param_3 != 0) {
    local_ce0 = *param_1;
    local_cdc = param_1[1];
    local_6c8 = param_1[2];
    uStack_6c4 = param_1[3];
    local_6b8 = param_1[10];
    uStack_6b4 = param_1[0xb];
    local_6c0 = param_1[4];
    uStack_6bc = param_1[5];
    local_6b0 = param_1[0xc];
    uStack_6ac = param_1[0xd];
    local_6a8 = param_1[6];
    uStack_6a4 = param_1[7];
    local_6a0 = param_1[0xe];
    uStack_69c = param_1[0xf];
    local_cd8 = param_1[8];
    local_cd4 = param_1[9];
    local_28 = param_3;
    do {
      HintPreloadData(param_2 + 0x81);
      HintPreloadData(param_2 + 0x82);
      HintPreloadData(param_2 + 0x83);
      local_d0c = (uint)*param_2 << 0x18 | (uint)param_2[1] << 0x10 | (uint)param_2[2] << 8 |
                  (uint)param_2[3];
      uVar9 = (local_cd8 >> 0x12 | local_cd4 << 0xe) ^ (local_cd8 >> 0xe | local_cd4 << 0x12) ^
              (local_cd8 << 0x17 | local_cd4 >> 9);
      uVar16 = local_6b0 & ~local_cd8 ^ local_6b8 & local_cd8;
      uVar10 = local_6a0 + DAT_000921d8 + uVar9;
      local_d10 = (uint)param_2[7] | (uint)param_2[4] << 0x18 | (uint)param_2[5] << 0x10 |
                  (uint)param_2[6] << 8;
      uVar11 = uVar10 + uVar16;
      uVar30 = uVar11 + local_d10;
      iVar33 = uStack_69c + DAT_000921dc + (uint)CARRY4(local_6a0,DAT_000921d8) +
               ((local_cd4 >> 0x12 | local_cd8 << 0xe) ^ (local_cd4 >> 0xe | local_cd8 << 0x12) ^
               (local_cd4 << 0x17 | local_cd8 >> 9)) + (uint)CARRY4(local_6a0 + DAT_000921d8,uVar9)
               + (uStack_6ac & ~local_cd4 ^ uStack_6b4 & local_cd4) + (uint)CARRY4(uVar10,uVar16) +
               local_d0c + CARRY4(uVar11,local_d10);
      uVar21 = uVar30 + local_6a8;
      uVar27 = iVar33 + uStack_6a4 + CARRY4(uVar30,local_6a8);
      uVar11 = (local_ce0 << 0x1e | local_cdc >> 2) ^ (local_ce0 >> 0x1c | local_cdc << 4) ^
               (local_ce0 << 0x19 | local_cdc >> 7);
      uVar9 = local_6c0 & local_6c8 ^ local_6c0 & local_ce0 ^ local_6c8 & local_ce0;
      uVar10 = uVar9 + uVar11;
      uVar17 = uVar10 + uVar30;
      uVar19 = (uStack_6bc & uStack_6c4 ^ uStack_6bc & local_cdc ^ uStack_6c4 & local_cdc) +
               ((local_cdc << 0x1e | local_ce0 >> 2) ^ (local_cdc >> 0x1c | local_ce0 << 4) ^
               (local_cdc << 0x19 | local_ce0 >> 7)) + (uint)CARRY4(uVar9,uVar11) +
               iVar33 + (uint)CARRY4(uVar10,uVar30);
      local_d1c = (uint)param_2[8] << 0x18 | (uint)param_2[9] << 0x10 | (uint)param_2[10] << 8 |
                  (uint)param_2[0xb];
      local_d20 = (uint)param_2[0xf] | (uint)param_2[0xc] << 0x18 | (uint)param_2[0xd] << 0x10 |
                  (uint)param_2[0xe] << 8;
      uVar11 = (uVar21 >> 0x12 | uVar27 * 0x4000) ^ (uVar21 >> 0xe | uVar27 * 0x40000) ^
               (uVar21 * 0x800000 | uVar27 >> 9);
      uVar16 = local_6b0 + DAT_000921e0 + local_d20;
      uVar9 = uVar16 + uVar11;
      uVar10 = uVar21 & local_cd8 ^ local_6b8 & ~uVar21;
      uVar30 = uVar9 + uVar10;
      iVar33 = uStack_6ac + DAT_000921e4 + (uint)CARRY4(local_6b0,DAT_000921e0) +
               local_d1c + CARRY4(local_6b0 + DAT_000921e0,local_d20) +
               ((uVar27 >> 0x12 | uVar21 * 0x4000) ^ (uVar27 >> 0xe | uVar21 * 0x40000) ^
               (uVar27 * 0x800000 | uVar21 >> 9)) + (uint)CARRY4(uVar16,uVar11) +
               (uVar27 & local_cd4 ^ uStack_6b4 & ~uVar27) + (uint)CARRY4(uVar9,uVar10);
      uVar12 = uVar30 + local_6c0;
      uVar14 = iVar33 + uStack_6bc + CARRY4(uVar30,local_6c0);
      uVar9 = uVar17 & local_6c8 ^ uVar17 & local_ce0 ^ local_6c8 & local_ce0;
      uVar10 = (uVar17 * 0x40000000 | uVar19 >> 2) ^ (uVar17 >> 0x1c | uVar19 * 0x10) ^
               (uVar17 * 0x2000000 | uVar19 >> 7);
      uVar11 = uVar10 + uVar9;
      uVar22 = uVar11 + uVar30;
      uVar28 = ((uVar19 * 0x40000000 | uVar17 >> 2) ^ (uVar19 >> 0x1c | uVar17 * 0x10) ^
               (uVar19 * 0x2000000 | uVar17 >> 7)) +
               (uVar19 & uStack_6c4 ^ uVar19 & local_cdc ^ uStack_6c4 & local_cdc) +
               (uint)CARRY4(uVar10,uVar9) + iVar33 + (uint)CARRY4(uVar11,uVar30);
      local_d24 = (uint)param_2[0x10] << 0x18 | (uint)param_2[0x11] << 0x10 |
                  (uint)param_2[0x12] << 8 | (uint)param_2[0x13];
      local_d28 = (uint)param_2[0x17] | (uint)param_2[0x14] << 0x18 | (uint)param_2[0x15] << 0x10 |
                  (uint)param_2[0x16] << 8;
      uVar10 = (uVar12 >> 0x12 | uVar14 * 0x4000) ^ (uVar12 >> 0xe | uVar14 * 0x40000) ^
               (uVar12 * 0x800000 | uVar14 >> 9);
      uVar11 = local_6b8 + DAT_000921e8 + local_d28;
      uVar9 = uVar12 & uVar21 ^ local_cd8 & ~uVar12;
      uVar16 = uVar11 + uVar10;
      uVar30 = uVar16 + uVar9;
      iVar33 = uStack_6b4 + DAT_000921ec + (uint)CARRY4(local_6b8,DAT_000921e8) +
               local_d24 + CARRY4(local_6b8 + DAT_000921e8,local_d28) +
               ((uVar14 >> 0x12 | uVar12 * 0x4000) ^ (uVar14 >> 0xe | uVar12 * 0x40000) ^
               (uVar14 * 0x800000 | uVar12 >> 9)) + (uint)CARRY4(uVar11,uVar10) +
               (uVar14 & uVar27 ^ local_cd4 & ~uVar14) + (uint)CARRY4(uVar16,uVar9);
      uVar18 = uVar30 + local_6c8;
      uVar20 = iVar33 + uStack_6c4 + CARRY4(uVar30,local_6c8);
      uVar10 = uVar22 & local_ce0 ^ uVar22 & uVar17 ^ uVar17 & local_ce0;
      uVar11 = (uVar22 * 0x40000000 | uVar28 >> 2) ^ (uVar22 >> 0x1c | uVar28 * 0x10) ^
               (uVar22 * 0x2000000 | uVar28 >> 7);
      uVar16 = uVar11 + uVar10;
      uVar9 = uVar16 + uVar30;
      uVar30 = ((uVar28 * 0x40000000 | uVar22 >> 2) ^ (uVar28 >> 0x1c | uVar22 * 0x10) ^
               (uVar28 * 0x2000000 | uVar22 >> 7)) +
               (uVar28 & local_cdc ^ uVar28 & uVar19 ^ uVar19 & local_cdc) +
               (uint)CARRY4(uVar11,uVar10) + iVar33 + (uint)CARRY4(uVar16,uVar30);
      local_d34 = (uint)param_2[0x18] << 0x18 | (uint)param_2[0x19] << 0x10 |
                  (uint)param_2[0x1a] << 8 | (uint)param_2[0x1b];
      local_d38 = (uint)param_2[0x1f] | (uint)param_2[0x1c] << 0x18 | (uint)param_2[0x1d] << 0x10 |
                  (uint)param_2[0x1e] << 8;
      uVar16 = (uVar18 >> 0x12 | uVar20 * 0x4000) ^ (uVar18 >> 0xe | uVar20 * 0x40000) ^
               (uVar18 * 0x800000 | uVar20 >> 9);
      uVar10 = local_cd8 + DAT_000921f0 + local_d38;
      uVar11 = uVar18 & uVar12 ^ uVar21 & ~uVar18;
      uVar23 = uVar10 + uVar16;
      uVar24 = uVar23 + uVar11;
      iVar33 = local_cd4 + DAT_000921f4 + (uint)CARRY4(local_cd8,DAT_000921f0) +
               local_d34 + CARRY4(local_cd8 + DAT_000921f0,local_d38) +
               ((uVar20 >> 0x12 | uVar18 * 0x4000) ^ (uVar20 >> 0xe | uVar18 * 0x40000) ^
               (uVar20 * 0x800000 | uVar18 >> 9)) + (uint)CARRY4(uVar10,uVar16) +
               (uVar20 & uVar14 ^ uVar27 & ~uVar20) + (uint)CARRY4(uVar23,uVar11);
      uVar11 = uVar9 & uVar17 ^ uVar9 & uVar22 ^ uVar22 & uVar17;
      uVar16 = (uVar9 * 0x40000000 | uVar30 >> 2) ^ (uVar9 >> 0x1c | uVar30 * 0x10) ^
               (uVar9 * 0x2000000 | uVar30 >> 7);
      uVar13 = uVar24 + local_ce0;
      uVar15 = iVar33 + local_cdc + CARRY4(uVar24,local_ce0);
      uVar23 = uVar11 + uVar16;
      uVar10 = uVar23 + uVar24;
      uVar23 = (uVar30 & uVar19 ^ uVar30 & uVar28 ^ uVar28 & uVar19) +
               ((uVar30 * 0x40000000 | uVar9 >> 2) ^ (uVar30 >> 0x1c | uVar9 * 0x10) ^
               (uVar30 * 0x2000000 | uVar9 >> 7)) + (uint)CARRY4(uVar11,uVar16) +
               iVar33 + (uint)CARRY4(uVar23,uVar24);
      local_d2c = (uint)param_2[0x20] << 0x18 | (uint)param_2[0x21] << 0x10 |
                  (uint)param_2[0x22] << 8 | (uint)param_2[0x23];
      local_d30 = (uint)param_2[0x27] | (uint)param_2[0x24] << 0x18 | (uint)param_2[0x25] << 0x10 |
                  (uint)param_2[0x26] << 8;
      uVar16 = local_d30 + DAT_00092ee8 + uVar21;
      uVar31 = (uVar13 >> 0x12 | uVar15 * 0x4000) ^ (uVar13 >> 0xe | uVar15 * 0x40000) ^
               (uVar13 * 0x800000 | uVar15 >> 9);
      uVar11 = uVar13 & uVar18 ^ uVar12 & ~uVar13;
      uVar25 = uVar16 + uVar31;
      uVar26 = uVar10 & uVar22 ^ uVar10 & uVar9 ^ uVar9 & uVar22;
      uVar24 = uVar25 + uVar11;
      iVar33 = local_d2c + DAT_00092eec + (uint)CARRY4(local_d30,DAT_00092ee8) +
               uVar27 + CARRY4(local_d30 + DAT_00092ee8,uVar21) +
               ((uVar15 >> 0x12 | uVar13 * 0x4000) ^ (uVar15 >> 0xe | uVar13 * 0x40000) ^
               (uVar15 * 0x800000 | uVar13 >> 9)) + (uint)CARRY4(uVar16,uVar31) +
               (uVar15 & uVar20 ^ uVar14 & ~uVar15) + (uint)CARRY4(uVar25,uVar11);
      uVar32 = (uVar10 * 0x40000000 | uVar23 >> 2) ^ (uVar10 >> 0x1c | uVar23 * 0x10) ^
               (uVar10 * 0x2000000 | uVar23 >> 7);
      uVar11 = uVar26 + uVar32;
      uVar25 = uVar24 + uVar17;
      uVar31 = iVar33 + uVar19 + CARRY4(uVar24,uVar17);
      local_d44 = (uint)param_2[0x28] << 0x18 | (uint)param_2[0x29] << 0x10 |
                  (uint)param_2[0x2a] << 8 | (uint)param_2[0x2b];
      local_d48 = (uint)param_2[0x2f] | (uint)param_2[0x2c] << 0x18 | (uint)param_2[0x2d] << 0x10 |
                  (uint)param_2[0x2e] << 8;
      uVar16 = local_d48 + DAT_00092ef0 + uVar12;
      uVar19 = (uVar25 >> 0x12 | uVar31 * 0x4000) ^ (uVar25 >> 0xe | uVar31 * 0x40000) ^
               (uVar25 * 0x800000 | uVar31 >> 9);
      uVar17 = uVar25 & uVar13 ^ uVar18 & ~uVar25;
      uVar21 = uVar19 + uVar16;
      uVar27 = uVar21 + uVar17;
      iVar29 = ((uVar31 >> 0x12 | uVar25 * 0x4000) ^ (uVar31 >> 0xe | uVar25 * 0x40000) ^
               (uVar31 * 0x800000 | uVar25 >> 9)) +
               local_d44 + DAT_00092ef4 + (uint)CARRY4(local_d48,DAT_00092ef0) +
               uVar14 + CARRY4(local_d48 + DAT_00092ef0,uVar12) + (uint)CARRY4(uVar19,uVar16) +
               (uVar31 & uVar15 ^ uVar20 & ~uVar31) + (uint)CARRY4(uVar21,uVar17);
      uVar12 = uVar11 + uVar24;
      uVar26 = (uVar23 & uVar28 ^ uVar23 & uVar30 ^ uVar30 & uVar28) +
               ((uVar23 * 0x40000000 | uVar10 >> 2) ^ (uVar23 >> 0x1c | uVar10 * 0x10) ^
               (uVar23 * 0x2000000 | uVar10 >> 7)) + (uint)CARRY4(uVar26,uVar32) +
               iVar33 + (uint)CARRY4(uVar11,uVar24);
      uVar19 = uVar27 + uVar22;
      uVar22 = iVar29 + uVar28 + CARRY4(uVar27,uVar22);
      local_d3c = (uint)param_2[0x30] << 0x18 | (uint)param_2[0x31] << 0x10 |
                  (uint)param_2[0x32] << 8 | (uint)param_2[0x33];
      local_d40 = (uint)param_2[0x37] | (uint)param_2[0x34] << 0x18 | (uint)param_2[0x35] << 0x10 |
                  (uint)param_2[0x36] << 8;
      uVar24 = uVar12 & uVar9 ^ uVar12 & uVar10 ^ uVar10 & uVar9;
      uVar17 = (uVar12 * 0x40000000 | uVar26 >> 2) ^ (uVar12 >> 0x1c | uVar26 * 0x10) ^
               (uVar12 * 0x2000000 | uVar26 >> 7);
      uVar11 = local_d40 + DAT_00092ef8 + uVar18;
      uVar14 = (uVar19 >> 0x12 | uVar22 * 0x4000) ^ (uVar19 >> 0xe | uVar22 * 0x40000) ^
               (uVar19 * 0x800000 | uVar22 >> 9);
      uVar16 = uVar19 & uVar25 ^ uVar13 & ~uVar19;
      uVar28 = uVar17 + uVar24;
      uVar32 = uVar14 + uVar11;
      uVar21 = uVar28 + uVar27;
      uVar27 = ((uVar26 * 0x40000000 | uVar12 >> 2) ^ (uVar26 >> 0x1c | uVar12 * 0x10) ^
               (uVar26 * 0x2000000 | uVar12 >> 7)) +
               (uVar26 & uVar30 ^ uVar26 & uVar23 ^ uVar23 & uVar30) + (uint)CARRY4(uVar17,uVar24) +
               iVar29 + (uint)CARRY4(uVar28,uVar27);
      uVar24 = uVar32 + uVar16;
      iVar33 = ((uVar22 >> 0x12 | uVar19 * 0x4000) ^ (uVar22 >> 0xe | uVar19 * 0x40000) ^
               (uVar22 * 0x800000 | uVar19 >> 9)) +
               local_d3c + DAT_00092efc + (uint)CARRY4(local_d40,DAT_00092ef8) +
               uVar20 + CARRY4(local_d40 + DAT_00092ef8,uVar18) + (uint)CARRY4(uVar14,uVar11) +
               (uVar22 & uVar31 ^ uVar15 & ~uVar22) + (uint)CARRY4(uVar32,uVar16);
      uVar18 = uVar24 + uVar9;
      uVar32 = iVar33 + uVar30 + CARRY4(uVar24,uVar9);
      local_d54 = (uint)param_2[0x38] << 0x18 | (uint)param_2[0x39] << 0x10 |
                  (uint)param_2[0x3a] << 8 | (uint)param_2[0x3b];
      local_d58 = (uint)param_2[0x3f] | (uint)param_2[0x3c] << 0x18 | (uint)param_2[0x3d] << 0x10 |
                  (uint)param_2[0x3e] << 8;
      uVar17 = uVar21 & uVar10 ^ uVar21 & uVar12 ^ uVar12 & uVar10;
      uVar9 = (uVar21 * 0x40000000 | uVar27 >> 2) ^ (uVar21 >> 0x1c | uVar27 * 0x10) ^
              (uVar21 * 0x2000000 | uVar27 >> 7);
      uVar16 = uVar17 + uVar9;
      uVar20 = local_d58 + DAT_00092f00 + uVar13;
      uVar11 = (uVar18 >> 0x12 | uVar32 * 0x4000) ^ (uVar18 >> 0xe | uVar32 * 0x40000) ^
               (uVar18 * 0x800000 | uVar32 >> 9);
      uVar30 = uVar16 + uVar24;
      uVar14 = (uVar27 & uVar23 ^ uVar27 & uVar26 ^ uVar26 & uVar23) +
               ((uVar27 * 0x40000000 | uVar21 >> 2) ^ (uVar27 >> 0x1c | uVar21 * 0x10) ^
               (uVar27 * 0x2000000 | uVar21 >> 7)) + (uint)CARRY4(uVar17,uVar9) +
               iVar33 + (uint)CARRY4(uVar16,uVar24);
      uVar16 = uVar20 + uVar11;
      uVar9 = uVar25 & ~uVar18 ^ uVar18 & uVar19;
      uVar24 = uVar16 + uVar9;
      iVar33 = local_d54 + DAT_00092f04 + (uint)CARRY4(local_d58,DAT_00092f00) +
               uVar15 + CARRY4(local_d58 + DAT_00092f00,uVar13) +
               ((uVar32 >> 0x12 | uVar18 * 0x4000) ^ (uVar32 >> 0xe | uVar18 * 0x40000) ^
               (uVar32 * 0x800000 | uVar18 >> 9)) + (uint)CARRY4(uVar20,uVar11) +
               (uVar31 & ~uVar32 ^ uVar32 & uVar22) + (uint)CARRY4(uVar16,uVar9);
      uVar13 = uVar24 + uVar10;
      uVar15 = iVar33 + uVar23 + CARRY4(uVar24,uVar10);
      local_d5c = (uint)param_2[0x40] << 0x18 | (uint)param_2[0x41] << 0x10 |
                  (uint)param_2[0x42] << 8 | (uint)param_2[0x43];
      uVar11 = uVar30 & uVar12 ^ uVar30 & uVar21 ^ uVar21 & uVar12;
      uVar9 = (uVar30 * 0x40000000 | uVar14 >> 2) ^ (uVar30 >> 0x1c | uVar14 * 0x10) ^
              (uVar30 * 0x2000000 | uVar14 >> 7);
      local_d60 = (uint)param_2[0x47] | (uint)param_2[0x44] << 0x18 | (uint)param_2[0x45] << 0x10 |
                  (uint)param_2[0x46] << 8;
      uVar10 = uVar11 + uVar9;
      uVar20 = uVar10 + uVar24;
      uVar28 = (uVar14 & uVar26 ^ uVar14 & uVar27 ^ uVar27 & uVar26) +
               ((uVar14 * 0x40000000 | uVar30 >> 2) ^ (uVar14 >> 0x1c | uVar30 * 0x10) ^
               (uVar14 * 0x2000000 | uVar30 >> 7)) + (uint)CARRY4(uVar11,uVar9) +
               iVar33 + (uint)CARRY4(uVar10,uVar24);
      uVar11 = local_d60 + DAT_00092f08 + uVar25;
      uVar9 = (uVar13 >> 0x12 | uVar15 * 0x4000) ^ (uVar13 >> 0xe | uVar15 * 0x40000) ^
              (uVar13 * 0x800000 | uVar15 >> 9);
      uVar16 = uVar11 + uVar9;
      uVar10 = uVar13 & uVar18 ^ uVar19 & ~uVar13;
      uVar24 = uVar16 + uVar10;
      iVar33 = local_d5c + DAT_00092f0c + (uint)CARRY4(local_d60,DAT_00092f08) +
               uVar31 + CARRY4(local_d60 + DAT_00092f08,uVar25) +
               ((uVar15 >> 0x12 | uVar13 * 0x4000) ^ (uVar15 >> 0xe | uVar13 * 0x40000) ^
               (uVar15 * 0x800000 | uVar13 >> 9)) + (uint)CARRY4(uVar11,uVar9) +
               (uVar15 & uVar32 ^ uVar22 & ~uVar15) + (uint)CARRY4(uVar16,uVar10);
      uVar23 = uVar24 + uVar12;
      uVar12 = iVar33 + uVar26 + CARRY4(uVar24,uVar12);
      uVar11 = uVar30 & uVar21 ^ uVar20 & uVar21 ^ uVar20 & uVar30;
      uVar9 = (uVar20 * 0x40000000 | uVar28 >> 2) ^ (uVar20 >> 0x1c | uVar28 * 0x10) ^
              (uVar20 * 0x2000000 | uVar28 >> 7);
      uVar10 = uVar9 + uVar11;
      uVar25 = uVar10 + uVar24;
      uVar31 = ((uVar28 * 0x40000000 | uVar20 >> 2) ^ (uVar28 >> 0x1c | uVar20 * 0x10) ^
               (uVar28 * 0x2000000 | uVar20 >> 7)) +
               (uVar14 & uVar27 ^ uVar28 & uVar27 ^ uVar28 & uVar14) + (uint)CARRY4(uVar9,uVar11) +
               iVar33 + (uint)CARRY4(uVar10,uVar24);
      uVar9 = (uVar23 >> 0x12 | uVar12 * 0x4000) ^ (uVar23 >> 0xe | uVar12 * 0x40000) ^
              (uVar23 * 0x800000 | uVar12 >> 9);
      uVar10 = uVar23 & uVar13 ^ uVar18 & ~uVar23;
      uVar16 = uVar25 & uVar30 ^ uVar25 & uVar20 ^ uVar20 & uVar30;
      pbVar1 = param_2 + 0x7b;
      uVar24 = (uVar25 * 0x40000000 | uVar31 >> 2) ^ (uVar25 >> 0x1c | uVar31 * 0x10) ^
               (uVar25 * 0x2000000 | uVar31 >> 7);
      pbVar2 = param_2 + 0x7f;
      local_d64 = (uint)param_2[0x48] << 0x18 | (uint)param_2[0x49] << 0x10 |
                  (uint)param_2[0x4a] << 8 | (uint)param_2[0x4b];
      local_d68 = (uint)param_2[0x4f] | (uint)param_2[0x4c] << 0x18 | (uint)param_2[0x4d] << 0x10 |
                  (uint)param_2[0x4e] << 8;
      uVar11 = local_d68 + DAT_00093df0 + uVar19;
      uVar17 = uVar9 + uVar11;
      uVar26 = uVar17 + uVar10;
      iVar33 = ((uVar12 >> 0x12 | uVar23 * 0x4000) ^ (uVar12 >> 0xe | uVar23 * 0x40000) ^
               (uVar12 * 0x800000 | uVar23 >> 9)) +
               local_d64 + DAT_00093df4 + (uint)CARRY4(local_d68,DAT_00093df0) +
               uVar22 + CARRY4(local_d68 + DAT_00093df0,uVar19) + (uint)CARRY4(uVar9,uVar11) +
               (uVar12 & uVar15 ^ uVar32 & ~uVar12) + (uint)CARRY4(uVar17,uVar10);
      uVar19 = uVar26 + uVar21;
      uVar22 = iVar33 + uVar27 + CARRY4(uVar26,uVar21);
      uVar9 = uVar16 + uVar24;
      uVar27 = uVar26 + uVar9;
      local_d94 = iVar33 + (uVar31 & uVar14 ^ uVar31 & uVar28 ^ uVar28 & uVar14) +
                           ((uVar31 * 0x40000000 | uVar25 >> 2) ^ (uVar31 >> 0x1c | uVar25 * 0x10) ^
                           (uVar31 * 0x2000000 | uVar25 >> 7)) + (uint)CARRY4(uVar16,uVar24) +
                           (uint)CARRY4(uVar26,uVar9);
      local_d4c = (uint)param_2[0x50] << 0x18 | (uint)param_2[0x51] << 0x10 |
                  (uint)param_2[0x52] << 8 | (uint)param_2[0x53];
      local_d50 = (uint)param_2[0x57] | (uint)param_2[0x54] << 0x18 | (uint)param_2[0x55] << 0x10 |
                  (uint)param_2[0x56] << 8;
      uVar11 = local_d50 + DAT_00093df8 + uVar18;
      uVar9 = (uVar19 >> 0x12 | uVar22 * 0x4000) ^ (uVar19 >> 0xe | uVar22 * 0x40000) ^
              (uVar19 * 0x800000 | uVar22 >> 9);
      uVar24 = uVar11 + uVar9;
      uVar16 = uVar19 & uVar23 ^ uVar13 & ~uVar19;
      uVar10 = uVar24 + uVar16;
      iVar33 = local_d4c + DAT_00093dfc + (uint)CARRY4(local_d50,DAT_00093df8) +
               uVar32 + CARRY4(local_d50 + DAT_00093df8,uVar18) +
               ((uVar22 >> 0x12 | uVar19 * 0x4000) ^ (uVar22 >> 0xe | uVar19 * 0x40000) ^
               (uVar22 * 0x800000 | uVar19 >> 9)) + (uint)CARRY4(uVar11,uVar9) +
               (uVar22 & uVar12 ^ uVar15 & ~uVar22) + (uint)CARRY4(uVar24,uVar16);
      uVar9 = uVar10 + uVar30;
      uVar30 = iVar33 + uVar14 + CARRY4(uVar10,uVar30);
      uVar17 = uVar27 & uVar20 ^ uVar27 & uVar25 ^ uVar25 & uVar20;
      uVar11 = (uVar27 * 0x40000000 | local_d94 >> 2) ^ (uVar27 >> 0x1c | local_d94 * 0x10) ^
               (uVar27 * 0x2000000 | local_d94 >> 7);
      local_d74 = (uint)param_2[0x58] << 0x18 | (uint)param_2[0x59] << 0x10 |
                  (uint)param_2[0x5a] << 8 | (uint)param_2[0x5b];
      uVar16 = uVar11 + uVar17;
      uVar24 = uVar16 + uVar10;
      uVar18 = ((local_d94 * 0x40000000 | uVar27 >> 2) ^ (local_d94 >> 0x1c | uVar27 * 0x10) ^
               (local_d94 * 0x2000000 | uVar27 >> 7)) +
               (local_d94 & uVar28 ^ local_d94 & uVar31 ^ uVar31 & uVar28) +
               (uint)CARRY4(uVar11,uVar17) + iVar33 + (uint)CARRY4(uVar16,uVar10);
      local_d78 = (uint)param_2[0x5f] | (uint)param_2[0x5c] << 0x18 | (uint)param_2[0x5d] << 0x10 |
                  (uint)param_2[0x5e] << 8;
      uVar17 = DAT_00093e00 + local_d78 + uVar13;
      uVar10 = (uVar9 >> 0x12 | uVar30 * 0x4000) ^ (uVar9 >> 0xe | uVar30 * 0x40000) ^
               (uVar9 * 0x800000 | uVar30 >> 9);
      uVar14 = uVar17 + uVar10;
      uVar11 = uVar9 & uVar19 ^ uVar23 & ~uVar9;
      uVar16 = uVar11 + uVar14;
      iVar33 = (uVar30 & uVar22 ^ uVar12 & ~uVar30) +
               DAT_00093e04 + local_d74 + CARRY4(DAT_00093e00,local_d78) +
               uVar15 + CARRY4(DAT_00093e00 + local_d78,uVar13) +
               ((uVar30 >> 0x12 | uVar9 * 0x4000) ^ (uVar30 >> 0xe | uVar9 * 0x40000) ^
               (uVar30 * 0x800000 | uVar9 >> 9)) + (uint)CARRY4(uVar17,uVar10) +
               (uint)CARRY4(uVar11,uVar14);
      uVar15 = uVar16 + uVar20;
      uVar20 = iVar33 + uVar28 + CARRY4(uVar16,uVar20);
      uVar17 = uVar24 & uVar25 ^ uVar24 & uVar27 ^ uVar27 & uVar25;
      uVar11 = (uVar24 * 0x40000000 | uVar18 >> 2) ^ (uVar24 >> 0x1c | uVar18 * 0x10) ^
               (uVar24 * 0x2000000 | uVar18 >> 7);
      uVar10 = uVar17 + uVar11;
      uVar13 = uVar10 + uVar16;
      uVar14 = (uVar18 & uVar31 ^ uVar18 & local_d94 ^ local_d94 & uVar31) +
               ((uVar18 * 0x40000000 | uVar24 >> 2) ^ (uVar18 >> 0x1c | uVar24 * 0x10) ^
               (uVar18 * 0x2000000 | uVar24 >> 7)) + (uint)CARRY4(uVar17,uVar11) +
               iVar33 + (uint)CARRY4(uVar10,uVar16);
      local_d6c = (uint)param_2[0x60] << 0x18 | (uint)param_2[0x61] << 0x10 |
                  (uint)param_2[0x62] << 8 | (uint)param_2[99];
      local_d70 = (uint)param_2[0x67] | (uint)param_2[100] << 0x18 | (uint)param_2[0x65] << 0x10 |
                  (uint)param_2[0x66] << 8;
      uVar11 = DAT_00093e08 + local_d70 + uVar23;
      uVar10 = (uVar15 >> 0x12 | uVar20 * 0x4000) ^ (uVar15 >> 0xe | uVar20 * 0x40000) ^
               (uVar15 * 0x800000 | uVar20 >> 9);
      uVar16 = uVar11 + uVar10;
      uVar17 = uVar19 & ~uVar15 ^ uVar15 & uVar9;
      uVar21 = uVar17 + uVar16;
      iVar33 = (uVar22 & ~uVar20 ^ uVar20 & uVar30) +
               DAT_00093e0c + local_d6c + CARRY4(DAT_00093e08,local_d70) +
               uVar12 + CARRY4(DAT_00093e08 + local_d70,uVar23) +
               ((uVar20 >> 0x12 | uVar15 * 0x4000) ^ (uVar20 >> 0xe | uVar15 * 0x40000) ^
               (uVar20 * 0x800000 | uVar15 >> 9)) + (uint)CARRY4(uVar11,uVar10) +
               (uint)CARRY4(uVar17,uVar16);
      local_dd0 = uVar21 + uVar25;
      local_dcc = iVar33 + uVar31 + CARRY4(uVar21,uVar25);
      uVar10 = uVar13 & uVar27 ^ uVar13 & uVar24 ^ uVar24 & uVar27;
      uVar16 = (uVar13 * 0x40000000 | uVar14 >> 2) ^ (uVar13 >> 0x1c | uVar14 * 0x10) ^
               (uVar13 * 0x2000000 | uVar14 >> 7);
      uVar11 = uVar10 + uVar16;
      local_dc0 = uVar11 + uVar21;
      local_dbc = (uVar14 & local_d94 ^ uVar14 & uVar18 ^ uVar18 & local_d94) +
                  ((uVar14 * 0x40000000 | uVar13 >> 2) ^ (uVar14 >> 0x1c | uVar13 * 0x10) ^
                  (uVar14 * 0x2000000 | uVar13 >> 7)) + (uint)CARRY4(uVar10,uVar16) +
                  iVar33 + (uint)CARRY4(uVar11,uVar21);
      local_d7c = (uint)param_2[0x68] << 0x18 | (uint)param_2[0x69] << 0x10 |
                  (uint)param_2[0x6a] << 8 | (uint)param_2[0x6b];
      local_d80 = (uint)param_2[0x6f] | (uint)param_2[0x6c] << 0x18 | (uint)param_2[0x6d] << 0x10 |
                  (uint)param_2[0x6e] << 8;
      uVar12 = (local_dd0 >> 0x12 | local_dcc * 0x4000) ^ (local_dd0 >> 0xe | local_dcc * 0x40000) ^
               (local_dd0 * 0x800000 | local_dcc >> 9);
      uVar10 = local_d80 + DAT_00093e10 + uVar19;
      uVar11 = uVar10 + uVar12;
      uVar16 = local_dd0 & uVar15 ^ uVar9 & ~local_dd0;
      uVar23 = uVar16 + uVar11;
      iVar33 = (local_dcc & uVar20 ^ uVar30 & ~local_dcc) +
               local_d7c + DAT_00093e14 + (uint)CARRY4(local_d80,DAT_00093e10) +
               uVar22 + CARRY4(local_d80 + DAT_00093e10,uVar19) +
               ((local_dcc >> 0x12 | local_dd0 * 0x4000) ^ (local_dcc >> 0xe | local_dd0 * 0x40000)
               ^ (local_dcc * 0x800000 | local_dd0 >> 9)) + (uint)CARRY4(uVar10,uVar12) +
               (uint)CARRY4(uVar16,uVar11);
      local_d98 = uVar27 + uVar23;
      local_d94 = local_d94 + iVar33 + (uint)CARRY4(uVar27,uVar23);
      uVar11 = local_dc0 & uVar24 ^ local_dc0 & uVar13 ^ uVar13 & uVar24;
      uVar10 = (local_dc0 * 0x40000000 | local_dbc >> 2) ^ (local_dc0 >> 0x1c | local_dbc * 0x10) ^
               (local_dc0 * 0x2000000 | local_dbc >> 7);
      uVar16 = uVar11 + uVar10;
      local_dc8 = uVar16 + uVar23;
      local_dc4 = (local_dbc & uVar18 ^ local_dbc & uVar14 ^ uVar14 & uVar18) +
                  ((local_dbc * 0x40000000 | local_dc0 >> 2) ^
                   (local_dbc >> 0x1c | local_dc0 * 0x10) ^ (local_dbc * 0x2000000 | local_dc0 >> 7)
                  ) + (uint)CARRY4(uVar11,uVar10) + iVar33 + (uint)CARRY4(uVar16,uVar23);
      uVar19 = (local_d98 >> 0x12 | local_d94 * 0x4000) ^ (local_d98 >> 0xe | local_d94 * 0x40000) ^
               (local_d98 * 0x800000 | local_d94 >> 9);
      uVar12 = local_dc8 & local_dc0 ^ local_dc8 & uVar13 ^ local_dc0 & uVar13;
      uVar21 = uVar15 & ~local_d98 ^ local_d98 & local_dd0;
      uVar10 = (local_dc8 * 0x40000000 | local_dc4 >> 2) ^ (local_dc8 >> 0x1c | local_dc4 * 0x10) ^
               (local_dc8 * 0x2000000 | local_dc4 >> 7);
      local_d84 = (uint)param_2[0x70] << 0x18 | (uint)param_2[0x71] << 0x10 |
                  (uint)param_2[0x72] << 8 | (uint)param_2[0x73];
      local_d88 = (uint)param_2[0x77] | (uint)param_2[0x74] << 0x18 | (uint)param_2[0x75] << 0x10 |
                  (uint)param_2[0x76] << 8;
      pbVar3 = param_2 + 0x78;
      pbVar4 = param_2 + 0x79;
      uVar11 = DAT_00093e18 + local_d88 + uVar9;
      uVar16 = uVar11 + uVar19;
      uVar17 = uVar10 + uVar12;
      pbVar5 = param_2 + 0x7d;
      uVar23 = uVar16 + uVar21;
      iVar33 = DAT_00093e1c + local_d84 + CARRY4(DAT_00093e18,local_d88) +
               uVar30 + CARRY4(DAT_00093e18 + local_d88,uVar9) +
               ((local_d94 >> 0x12 | local_d98 * 0x4000) ^ (local_d94 >> 0xe | local_d98 * 0x40000)
               ^ (local_d94 * 0x800000 | local_d98 >> 9)) + (uint)CARRY4(uVar11,uVar19) +
               (uVar20 & ~local_d94 ^ local_d94 & local_dcc) + (uint)CARRY4(uVar16,uVar21);
      pbVar6 = param_2 + 0x7c;
      local_db8 = uVar23 + uVar24;
      pbVar7 = param_2 + 0x7a;
      local_db4 = iVar33 + uVar18 + CARRY4(uVar23,uVar24);
      pbVar8 = param_2 + 0x7e;
      param_2 = param_2 + 0x80;
      local_db0 = uVar17 + uVar23;
      local_dac = ((local_dc4 * 0x40000000 | local_dc8 >> 2) ^
                   (local_dc4 >> 0x1c | local_dc8 * 0x10) ^ (local_dc4 * 0x2000000 | local_dc8 >> 7)
                  ) + (local_dc4 & local_dbc ^ local_dc4 & uVar14 ^ local_dbc & uVar14) +
                      (uint)CARRY4(uVar10,uVar12) + iVar33 + (uint)CARRY4(uVar17,uVar23);
      HintPreloadData(param_2);
      local_d8c = (uint)*pbVar3 << 0x18 | (uint)*pbVar4 << 0x10 | (uint)*pbVar7 << 8 | (uint)*pbVar1
      ;
      local_d00 = DAT_000940c0;
      local_d18 = local_db0 & local_dc8;
      local_d14 = local_dac & local_dc4;
      local_d90 = (uint)*pbVar2 | (uint)*pbVar6 << 0x18 | (uint)*pbVar5 << 0x10 | (uint)*pbVar8 << 8
      ;
      uVar9 = local_d90 + DAT_000940b8 + uVar15;
      uVar30 = local_db0 & local_dc0 ^ local_d18 ^ local_dc8 & local_dc0;
      uVar10 = (local_db8 >> 0x12 | local_db4 * 0x4000) ^ (local_db8 >> 0xe | local_db4 * 0x40000) ^
               (local_db8 * 0x800000 | local_db4 >> 9);
      uVar12 = uVar9 + uVar10;
      uVar23 = (local_db0 * 0x40000000 | local_dac >> 2) ^ (local_db0 >> 0x1c | local_dac * 0x10) ^
               (local_db0 * 0x2000000 | local_dac >> 7);
      uVar24 = uVar30 + uVar23;
      uVar11 = local_dd0 & ~local_db8 ^ local_db8 & local_d98;
      uVar16 = uVar11 + uVar12;
      local_cf0 = 0x10;
      iVar33 = (local_dcc & ~local_db4 ^ local_db4 & local_d94) +
               local_d8c + DAT_000940bc + (uint)CARRY4(local_d90,DAT_000940b8) +
               uVar20 + CARRY4(local_d90 + DAT_000940b8,uVar15) +
               ((local_db4 >> 0x12 | local_db8 * 0x4000) ^ (local_db4 >> 0xe | local_db8 * 0x40000)
               ^ (local_db4 * 0x800000 | local_db8 >> 9)) + (uint)CARRY4(uVar9,uVar10) +
               (uint)CARRY4(uVar11,uVar12);
      local_da8 = uVar16 + uVar13;
      local_da4 = iVar33 + uVar14 + CARRY4(uVar16,uVar13);
      local_da0 = uVar24 + uVar16;
      local_d9c = (local_dac & local_dbc ^ local_d14 ^ local_dc4 & local_dbc) +
                  ((local_dac * 0x40000000 | local_db0 >> 2) ^
                   (local_dac >> 0x1c | local_db0 * 0x10) ^ (local_dac * 0x2000000 | local_db0 >> 7)
                  ) + (uint)CARRY4(uVar30,uVar23) + iVar33 + (uint)CARRY4(uVar24,uVar16);
      do {
        uVar23 = (local_d20 >> 8 | local_d1c << 0x18) ^ (local_d20 >> 1 | local_d1c << 0x1f) ^
                 (local_d20 >> 7 | local_d1c << 0x19);
        uVar9 = (local_d88 << 3 | local_d84 >> 0x1d) ^ (local_d88 >> 0x13 | local_d84 << 0xd) ^
                (local_d88 >> 6 | local_d84 << 0x1a);
        uVar10 = uVar9 + uVar23;
        uVar16 = (local_da8 >> 0x12 | local_da4 << 0xe) ^ (local_da8 >> 0xe | local_da4 << 0x12) ^
                 (local_da8 << 0x17 | local_da4 >> 9);
        uVar12 = local_db8 & local_da8 ^ local_d98 & ~local_da8;
        uVar11 = uVar10 + local_d68;
        uVar30 = uVar16 + uVar12;
        bVar35 = CARRY4(local_d10,uVar11);
        local_d10 = local_d10 + uVar11;
        local_d0c = local_d0c +
                    ((local_d84 << 3 | local_d88 >> 0x1d) ^ (local_d84 >> 0x13 | local_d88 << 0xd) ^
                    local_d84 >> 6) +
                    ((local_d1c >> 8 | local_d20 << 0x18) ^ (local_d1c >> 1 | local_d20 << 0x1f) ^
                    local_d1c >> 7) + (uint)CARRY4(uVar9,uVar23) +
                    local_d64 + CARRY4(uVar10,local_d68) + (uint)bVar35;
        uVar9 = uVar30 + local_d00[-0x1e];
        uVar10 = uVar9 + local_d10;
        uVar13 = uVar10 + local_dd0;
        iVar33 = ((local_da4 >> 0x12 | local_da8 << 0xe) ^ (local_da4 >> 0xe | local_da8 << 0x12) ^
                 (local_da4 << 0x17 | local_da8 >> 9)) +
                 (local_db4 & local_da4 ^ local_d94 & ~local_da4) + (uint)CARRY4(uVar16,uVar12) +
                 local_d00[-0x1d] + (uint)CARRY4(uVar30,local_d00[-0x1e]) +
                 local_d0c + CARRY4(uVar9,local_d10) + local_dcc + CARRY4(uVar10,local_dd0);
        uVar22 = local_dc0 + uVar13;
        local_dbc = local_dbc + iVar33 + (uint)CARRY4(local_dc0,uVar13);
        uVar10 = (local_d28 >> 8 | local_d24 << 0x18) ^ (local_d28 >> 1 | local_d24 << 0x1f) ^
                 (local_d28 >> 7 | local_d24 << 0x19);
        bVar35 = CARRY4(local_d20,local_d50);
        uVar11 = local_d20 + local_d50;
        uVar16 = uVar11 + uVar10;
        uVar9 = (local_d90 << 3 | local_d8c >> 0x1d) ^ (local_d90 >> 0x13 | local_d8c << 0xd) ^
                (local_d90 >> 6 | local_d8c << 0x1a);
        local_d20 = uVar16 + uVar9;
        local_d1c = local_d1c + local_d4c + bVar35 +
                    ((local_d24 >> 8 | local_d28 << 0x18) ^ (local_d24 >> 1 | local_d28 << 0x1f) ^
                    local_d24 >> 7) + (uint)CARRY4(uVar11,uVar10) +
                    ((local_d8c << 3 | local_d90 >> 0x1d) ^ (local_d8c >> 0x13 | local_d90 << 0xd) ^
                    local_d8c >> 6) + (uint)CARRY4(uVar16,uVar9);
        local_d18 = local_dc8 & local_da0 ^ local_db0 & local_da0 ^ local_d18;
        uVar30 = local_d98 + local_d00[-0x1c];
        uVar10 = (local_da0 << 0x1e | local_d9c >> 2) ^ (local_da0 >> 0x1c | local_d9c << 4) ^
                 (local_da0 << 0x19 | local_d9c >> 7);
        uVar9 = local_d18 + uVar10;
        uVar12 = (uVar22 >> 0x12 | local_dbc * 0x4000) ^ (uVar22 >> 0xe | local_dbc * 0x40000) ^
                 (uVar22 * 0x800000 | local_dbc >> 9);
        uVar11 = uVar30 + local_d20;
        uVar23 = uVar9 + uVar13;
        uVar17 = (local_dc4 & local_d9c ^ local_dac & local_d9c ^ local_d14) +
                 ((local_d9c << 0x1e | local_da0 >> 2) ^ (local_d9c >> 0x1c | local_da0 << 4) ^
                 (local_d9c << 0x19 | local_da0 >> 7)) + (uint)CARRY4(local_d18,uVar10) +
                 iVar33 + (uint)CARRY4(uVar9,uVar13);
        uVar10 = uVar11 + uVar12;
        uVar9 = uVar22 & local_da8 ^ local_db8 & ~uVar22;
        uVar16 = uVar10 + uVar9;
        iVar33 = local_d94 + local_d00[-0x1b] + (uint)CARRY4(local_d98,local_d00[-0x1c]) +
                 local_d1c + CARRY4(uVar30,local_d20) +
                 ((local_dbc >> 0x12 | uVar22 * 0x4000) ^ (local_dbc >> 0xe | uVar22 * 0x40000) ^
                 (local_dbc * 0x800000 | uVar22 >> 9)) + (uint)CARRY4(uVar11,uVar12) +
                 (local_dbc & local_da4 ^ local_db4 & ~local_dbc) + (uint)CARRY4(uVar10,uVar9);
        uVar25 = uVar16 + local_dc8;
        uVar28 = iVar33 + local_dc4 + CARRY4(uVar16,local_dc8);
        bVar35 = CARRY4(local_d28,local_d78);
        uVar12 = local_d28 + local_d78;
        uVar9 = (local_d38 >> 8 | local_d34 << 0x18) ^ (local_d38 >> 1 | local_d34 << 0x1f) ^
                (local_d38 >> 7 | local_d34 << 0x19);
        uVar13 = uVar12 + uVar9;
        uVar10 = uVar23 & local_db0 ^ uVar23 & local_da0 ^ local_db0 & local_da0;
        uVar30 = (local_d10 * 8 | local_d0c >> 0x1d) ^ (local_d10 >> 0x13 | local_d0c * 0x2000) ^
                 (local_d10 >> 6 | local_d0c * 0x4000000);
        uVar11 = (uVar23 * 0x40000000 | uVar17 >> 2) ^ (uVar23 >> 0x1c | uVar17 * 0x10) ^
                 (uVar23 * 0x2000000 | uVar17 >> 7);
        local_d28 = uVar13 + uVar30;
        local_d24 = local_d24 + local_d74 + bVar35 +
                    ((local_d34 >> 8 | local_d38 << 0x18) ^ (local_d34 >> 1 | local_d38 << 0x1f) ^
                    local_d34 >> 7) + (uint)CARRY4(uVar12,uVar9) +
                    ((local_d0c * 8 | local_d10 >> 0x1d) ^ (local_d0c >> 0x13 | local_d10 * 0x2000)
                    ^ local_d0c >> 6) + (uint)CARRY4(uVar13,uVar30);
        uVar30 = uVar10 + uVar11;
        uVar9 = local_db8 + local_d00[-0x1a];
        uVar27 = uVar30 + uVar16;
        uVar31 = (uVar17 & local_dac ^ uVar17 & local_d9c ^ local_dac & local_d9c) +
                 ((uVar17 * 0x40000000 | uVar23 >> 2) ^ (uVar17 >> 0x1c | uVar23 * 0x10) ^
                 (uVar17 * 0x2000000 | uVar23 >> 7)) + (uint)CARRY4(uVar10,uVar11) +
                 iVar33 + (uint)CARRY4(uVar30,uVar16);
        uVar30 = (uVar25 >> 0x12 | uVar28 * 0x4000) ^ (uVar25 >> 0xe | uVar28 * 0x40000) ^
                 (uVar25 * 0x800000 | uVar28 >> 9);
        uVar10 = uVar9 + local_d28;
        uVar11 = uVar10 + uVar30;
        uVar16 = uVar25 & uVar22 ^ local_da8 & ~uVar25;
        uVar12 = uVar11 + uVar16;
        iVar33 = local_db4 + local_d00[-0x19] + (uint)CARRY4(local_db8,local_d00[-0x1a]) +
                 local_d24 + CARRY4(uVar9,local_d28) +
                 ((uVar28 >> 0x12 | uVar25 * 0x4000) ^ (uVar28 >> 0xe | uVar25 * 0x40000) ^
                 (uVar28 * 0x800000 | uVar25 >> 9)) + (uint)CARRY4(uVar10,uVar30) +
                 (uVar28 & local_dbc ^ local_da4 & ~uVar28) + (uint)CARRY4(uVar11,uVar16);
        uVar15 = uVar12 + local_db0;
        uVar20 = iVar33 + local_dac + CARRY4(uVar12,local_db0);
        bVar35 = CARRY4(local_d38,local_d70);
        uVar9 = local_d38 + local_d70;
        uVar13 = (local_d30 >> 8 | local_d2c << 0x18) ^ (local_d30 >> 1 | local_d2c << 0x1f) ^
                 (local_d30 >> 7 | local_d2c << 0x19);
        uVar11 = uVar27 & local_da0 ^ uVar27 & uVar23 ^ uVar23 & local_da0;
        uVar24 = (uVar27 * 0x40000000 | uVar31 >> 2) ^ (uVar27 >> 0x1c | uVar31 * 0x10) ^
                 (uVar27 * 0x2000000 | uVar31 >> 7);
        uVar10 = uVar9 + uVar13;
        uVar16 = uVar11 + uVar24;
        uVar30 = (local_d20 * 8 | local_d1c >> 0x1d) ^ (local_d20 >> 0x13 | local_d1c * 0x2000) ^
                 (local_d20 >> 6 | local_d1c * 0x4000000);
        local_d38 = uVar10 + uVar30;
        local_d34 = local_d34 + local_d6c + bVar35 +
                    ((local_d2c >> 8 | local_d30 << 0x18) ^ (local_d2c >> 1 | local_d30 << 0x1f) ^
                    local_d2c >> 7) + (uint)CARRY4(uVar9,uVar13) +
                    ((local_d1c * 8 | local_d20 >> 0x1d) ^ (local_d1c >> 0x13 | local_d20 * 0x2000)
                    ^ local_d1c >> 6) + (uint)CARRY4(uVar10,uVar30);
        uVar30 = uVar16 + uVar12;
        uVar18 = (uVar31 & local_d9c ^ uVar31 & uVar17 ^ uVar17 & local_d9c) +
                 ((uVar31 * 0x40000000 | uVar27 >> 2) ^ (uVar31 >> 0x1c | uVar27 * 0x10) ^
                 (uVar31 * 0x2000000 | uVar27 >> 7)) + (uint)CARRY4(uVar11,uVar24) +
                 iVar33 + (uint)CARRY4(uVar16,uVar12);
        uVar11 = local_da8 + local_d00[-0x18];
        uVar16 = uVar11 + local_d38;
        uVar9 = (uVar15 >> 0x12 | uVar20 * 0x4000) ^ (uVar15 >> 0xe | uVar20 * 0x40000) ^
                (uVar15 * 0x800000 | uVar20 >> 9);
        uVar10 = uVar9 + uVar16;
        uVar12 = uVar22 & ~uVar15 ^ uVar15 & uVar25;
        uVar21 = uVar10 + uVar12;
        iVar33 = ((uVar20 >> 0x12 | uVar15 * 0x4000) ^ (uVar20 >> 0xe | uVar15 * 0x40000) ^
                 (uVar20 * 0x800000 | uVar15 >> 9)) +
                 local_da4 + local_d00[-0x17] + (uint)CARRY4(local_da8,local_d00[-0x18]) +
                 local_d34 + CARRY4(uVar11,local_d38) + (uint)CARRY4(uVar9,uVar16) +
                 (local_dbc & ~uVar20 ^ uVar20 & uVar28) + (uint)CARRY4(uVar10,uVar12);
        uVar12 = uVar21 + local_da0;
        uVar19 = iVar33 + local_d9c + CARRY4(uVar21,local_da0);
        bVar35 = CARRY4(local_d30,local_d80);
        uVar16 = local_d30 + local_d80;
        uVar9 = (local_d48 >> 8 | local_d44 << 0x18) ^ (local_d48 >> 1 | local_d44 << 0x1f) ^
                (local_d48 >> 7 | local_d44 << 0x19);
        uVar13 = uVar16 + uVar9;
        uVar11 = (local_d28 * 8 | local_d24 >> 0x1d) ^ (local_d28 >> 0x13 | local_d24 * 0x2000) ^
                 (local_d28 >> 6 | local_d24 * 0x4000000);
        uVar10 = uVar22 + local_d00[-0x16];
        local_d30 = uVar13 + uVar11;
        local_d2c = local_d2c + local_d7c + bVar35 +
                    ((local_d44 >> 8 | local_d48 << 0x18) ^ (local_d44 >> 1 | local_d48 << 0x1f) ^
                    local_d44 >> 7) + (uint)CARRY4(uVar16,uVar9) +
                    ((local_d24 * 8 | local_d28 >> 0x1d) ^ (local_d24 >> 0x13 | local_d28 * 0x2000)
                    ^ local_d24 >> 6) + (uint)CARRY4(uVar13,uVar11);
        uVar14 = uVar30 & uVar23 ^ uVar30 & uVar27 ^ uVar27 & uVar23;
        uVar13 = (uVar30 * 0x40000000 | uVar18 >> 2) ^ (uVar30 >> 0x1c | uVar18 * 0x10) ^
                 (uVar30 * 0x2000000 | uVar18 >> 7);
        uVar9 = uVar10 + local_d30;
        uVar24 = uVar13 + uVar14;
        uVar11 = (uVar12 >> 0x12 | uVar19 * 0x4000) ^ (uVar12 >> 0xe | uVar19 * 0x40000) ^
                 (uVar12 * 0x800000 | uVar19 >> 9);
        uVar26 = uVar9 + uVar11;
        uVar16 = uVar12 & uVar15 ^ uVar25 & ~uVar12;
        uVar32 = uVar24 + uVar21;
        uVar34 = ((uVar18 * 0x40000000 | uVar30 >> 2) ^ (uVar18 >> 0x1c | uVar30 * 0x10) ^
                 (uVar18 * 0x2000000 | uVar30 >> 7)) +
                 (uVar18 & uVar17 ^ uVar18 & uVar31 ^ uVar31 & uVar17) + (uint)CARRY4(uVar13,uVar14)
                 + iVar33 + (uint)CARRY4(uVar24,uVar21);
        uVar24 = uVar26 + uVar16;
        iVar33 = local_dbc + local_d00[-0x15] + (uint)CARRY4(uVar22,local_d00[-0x16]) +
                 local_d2c + CARRY4(uVar10,local_d30) +
                 ((uVar19 >> 0x12 | uVar12 * 0x4000) ^ (uVar19 >> 0xe | uVar12 * 0x40000) ^
                 (uVar19 * 0x800000 | uVar12 >> 9)) + (uint)CARRY4(uVar9,uVar11) +
                 (uVar19 & uVar20 ^ uVar28 & ~uVar19) + (uint)CARRY4(uVar26,uVar16);
        uVar22 = uVar24 + uVar23;
        uVar26 = iVar33 + uVar17 + CARRY4(uVar24,uVar23);
        bVar35 = CARRY4(local_d48,local_d88);
        uVar11 = local_d48 + local_d88;
        uVar16 = (local_d40 >> 8 | local_d3c << 0x18) ^ (local_d40 >> 1 | local_d3c << 0x1f) ^
                 (local_d40 >> 7 | local_d3c << 0x19);
        uVar9 = uVar11 + uVar16;
        uVar10 = (local_d38 * 8 | local_d34 >> 0x1d) ^ (local_d38 >> 0x13 | local_d34 * 0x2000) ^
                 (local_d38 >> 6 | local_d34 * 0x4000000);
        local_d48 = uVar9 + uVar10;
        local_d44 = local_d44 + local_d84 + bVar35 +
                    ((local_d3c >> 8 | local_d40 << 0x18) ^ (local_d3c >> 1 | local_d40 << 0x1f) ^
                    local_d3c >> 7) + (uint)CARRY4(uVar11,uVar16) +
                    ((local_d34 * 8 | local_d38 >> 0x1d) ^ (local_d34 >> 0x13 | local_d38 * 0x2000)
                    ^ local_d34 >> 6) + (uint)CARRY4(uVar9,uVar10);
        uVar23 = uVar32 & uVar27 ^ uVar32 & uVar30 ^ uVar30 & uVar27;
        uVar16 = (uVar32 * 0x40000000 | uVar34 >> 2) ^ (uVar32 >> 0x1c | uVar34 * 0x10) ^
                 (uVar32 * 0x2000000 | uVar34 >> 7);
        uVar9 = local_d48 + local_d00[-0x14];
        uVar10 = uVar23 + uVar16;
        uVar11 = uVar9 + uVar25;
        uVar13 = (uVar22 >> 0x12 | uVar26 * 0x4000) ^ (uVar22 >> 0xe | uVar26 * 0x40000) ^
                 (uVar22 * 0x800000 | uVar26 >> 9);
        uVar17 = uVar10 + uVar24;
        uVar21 = (uVar34 & uVar31 ^ uVar34 & uVar18 ^ uVar18 & uVar31) +
                 ((uVar34 * 0x40000000 | uVar32 >> 2) ^ (uVar34 >> 0x1c | uVar32 * 0x10) ^
                 (uVar34 * 0x2000000 | uVar32 >> 7)) + (uint)CARRY4(uVar23,uVar16) +
                 iVar33 + (uint)CARRY4(uVar10,uVar24);
        uVar23 = uVar13 + uVar11;
        uVar10 = uVar22 & uVar12 ^ uVar15 & ~uVar22;
        uVar16 = uVar23 + uVar10;
        iVar33 = ((uVar26 >> 0x12 | uVar22 * 0x4000) ^ (uVar26 >> 0xe | uVar22 * 0x40000) ^
                 (uVar26 * 0x800000 | uVar22 >> 9)) +
                 local_d44 + local_d00[-0x13] + (uint)CARRY4(local_d48,local_d00[-0x14]) +
                 uVar28 + CARRY4(uVar9,uVar25) + (uint)CARRY4(uVar13,uVar11) +
                 (uVar26 & uVar19 ^ uVar20 & ~uVar26) + (uint)CARRY4(uVar23,uVar10);
        uVar25 = uVar16 + uVar27;
        uVar27 = iVar33 + uVar31 + CARRY4(uVar16,uVar27);
        bVar35 = CARRY4(local_d40,local_d90);
        uVar11 = local_d40 + local_d90;
        uVar24 = (local_d58 >> 8 | local_d54 << 0x18) ^ (local_d58 >> 1 | local_d54 << 0x1f) ^
                 (local_d58 >> 7 | local_d54 << 0x19);
        uVar23 = uVar11 + uVar24;
        uVar9 = (local_d30 * 8 | local_d2c >> 0x1d) ^ (local_d30 >> 0x13 | local_d2c * 0x2000) ^
                (local_d30 >> 6 | local_d2c * 0x4000000);
        uVar13 = uVar17 & uVar30 ^ uVar17 & uVar32 ^ uVar32 & uVar30;
        uVar10 = (uVar17 * 0x40000000 | uVar21 >> 2) ^ (uVar17 >> 0x1c | uVar21 * 0x10) ^
                 (uVar17 * 0x2000000 | uVar21 >> 7);
        local_d40 = uVar23 + uVar9;
        local_d3c = local_d3c + local_d8c + bVar35 +
                    ((local_d54 >> 8 | local_d58 << 0x18) ^ (local_d54 >> 1 | local_d58 << 0x1f) ^
                    local_d54 >> 7) + (uint)CARRY4(uVar11,uVar24) +
                    ((local_d2c * 8 | local_d30 >> 0x1d) ^ (local_d2c >> 0x13 | local_d30 * 0x2000)
                    ^ local_d2c >> 6) + (uint)CARRY4(uVar23,uVar9);
        uVar9 = uVar13 + uVar10;
        uVar11 = local_d40 + local_d00[-0x12];
        uVar24 = uVar9 + uVar16;
        uVar14 = (uVar21 & uVar18 ^ uVar21 & uVar34 ^ uVar34 & uVar18) +
                 ((uVar21 * 0x40000000 | uVar17 >> 2) ^ (uVar21 >> 0x1c | uVar17 * 0x10) ^
                 (uVar21 * 0x2000000 | uVar17 >> 7)) + (uint)CARRY4(uVar13,uVar10) +
                 iVar33 + (uint)CARRY4(uVar9,uVar16);
        uVar16 = uVar11 + uVar15;
        uVar10 = (uVar25 >> 0x12 | uVar27 * 0x4000) ^ (uVar25 >> 0xe | uVar27 * 0x40000) ^
                 (uVar25 * 0x800000 | uVar27 >> 9);
        uVar13 = uVar16 + uVar10;
        uVar9 = uVar25 & uVar22 ^ uVar12 & ~uVar25;
        uVar23 = uVar13 + uVar9;
        iVar33 = local_d3c + local_d00[-0x11] + (uint)CARRY4(local_d40,local_d00[-0x12]) +
                 uVar20 + CARRY4(uVar11,uVar15) +
                 ((uVar27 >> 0x12 | uVar25 * 0x4000) ^ (uVar27 >> 0xe | uVar25 * 0x40000) ^
                 (uVar27 * 0x800000 | uVar25 >> 9)) + (uint)CARRY4(uVar16,uVar10) +
                 (uVar27 & uVar26 ^ uVar19 & ~uVar27) + (uint)CARRY4(uVar13,uVar9);
        uVar15 = uVar23 + uVar30;
        uVar20 = iVar33 + uVar18 + CARRY4(uVar23,uVar30);
        uVar9 = (local_d60 >> 8 | local_d5c << 0x18) ^ (local_d60 >> 1 | local_d5c << 0x1f) ^
                (local_d60 >> 7 | local_d5c << 0x19);
        bVar35 = CARRY4(uVar9,local_d58);
        uVar9 = uVar9 + local_d58;
        uVar16 = uVar24 & uVar32 ^ uVar24 & uVar17 ^ uVar17 & uVar32;
        uVar30 = (uVar24 * 0x40000000 | uVar14 >> 2) ^ (uVar24 >> 0x1c | uVar14 * 0x10) ^
                 (uVar24 * 0x2000000 | uVar14 >> 7);
        uVar11 = (local_d48 * 8 | local_d44 >> 0x1d) ^ (local_d48 >> 0x13 | local_d44 * 0x2000) ^
                 (local_d48 >> 6 | local_d44 * 0x4000000);
        uVar10 = uVar9 + local_d10;
        uVar13 = uVar16 + uVar30;
        local_d58 = uVar10 + uVar11;
        local_d54 = ((local_d5c >> 8 | local_d60 << 0x18) ^ (local_d5c >> 1 | local_d60 << 0x1f) ^
                    local_d5c >> 7) + local_d54 + bVar35 + local_d0c + CARRY4(uVar9,local_d10) +
                    ((local_d44 * 8 | local_d48 >> 0x1d) ^ (local_d44 >> 0x13 | local_d48 * 0x2000)
                    ^ local_d44 >> 6) + (uint)CARRY4(uVar10,uVar11);
        uVar9 = uVar13 + uVar23;
        uVar23 = (uVar14 & uVar34 ^ uVar14 & uVar21 ^ uVar21 & uVar34) +
                 ((uVar14 * 0x40000000 | uVar24 >> 2) ^ (uVar14 >> 0x1c | uVar24 * 0x10) ^
                 (uVar14 * 0x2000000 | uVar24 >> 7)) + (uint)CARRY4(uVar16,uVar30) +
                 iVar33 + (uint)CARRY4(uVar13,uVar23);
        uVar10 = local_d58 + local_d00[-0x10];
        uVar11 = uVar10 + uVar12;
        uVar16 = (uVar15 >> 0x12 | uVar20 * 0x4000) ^ (uVar15 >> 0xe | uVar20 * 0x40000) ^
                 (uVar15 * 0x800000 | uVar20 >> 9);
        uVar13 = uVar11 + uVar16;
        uVar30 = uVar22 & ~uVar15 ^ uVar15 & uVar25;
        uVar28 = uVar13 + uVar30;
        iVar33 = local_d54 + local_d00[-0xf] + (uint)CARRY4(local_d58,local_d00[-0x10]) +
                 uVar19 + CARRY4(uVar10,uVar12) +
                 ((uVar20 >> 0x12 | uVar15 * 0x4000) ^ (uVar20 >> 0xe | uVar15 * 0x40000) ^
                 (uVar20 * 0x800000 | uVar15 >> 9)) + (uint)CARRY4(uVar11,uVar16) +
                 (uVar26 & ~uVar20 ^ uVar20 & uVar27) + (uint)CARRY4(uVar13,uVar30);
        uVar10 = uVar28 + uVar32;
        uVar12 = iVar33 + uVar34 + CARRY4(uVar28,uVar32);
        uVar30 = (local_d68 >> 8 | local_d64 << 0x18) ^ (local_d68 >> 1 | local_d64 << 0x1f) ^
                 (local_d68 >> 7 | local_d64 << 0x19);
        uVar11 = uVar9 & uVar17 ^ uVar9 & uVar24 ^ uVar24 & uVar17;
        bVar35 = CARRY4(uVar30,local_d60);
        uVar30 = uVar30 + local_d60;
        uVar19 = (uVar9 * 0x40000000 | uVar23 >> 2) ^ (uVar9 >> 0x1c | uVar23 * 0x10) ^
                 (uVar9 * 0x2000000 | uVar23 >> 7);
        uVar16 = uVar11 + uVar19;
        uVar18 = (local_d40 * 8 | local_d3c >> 0x1d) ^ (local_d40 >> 0x13 | local_d3c * 0x2000) ^
                 (local_d40 >> 6 | local_d3c * 0x4000000);
        uVar13 = uVar30 + local_d20;
        uVar31 = uVar16 + uVar28;
        uVar32 = (uVar23 & uVar21 ^ uVar23 & uVar14 ^ uVar14 & uVar21) +
                 ((uVar23 * 0x40000000 | uVar9 >> 2) ^ (uVar23 >> 0x1c | uVar9 * 0x10) ^
                 (uVar23 * 0x2000000 | uVar9 >> 7)) + (uint)CARRY4(uVar11,uVar19) +
                 iVar33 + (uint)CARRY4(uVar16,uVar28);
        local_d60 = uVar13 + uVar18;
        local_d5c = ((local_d64 >> 8 | local_d68 << 0x18) ^ (local_d64 >> 1 | local_d68 << 0x1f) ^
                    local_d64 >> 7) + local_d5c + bVar35 + local_d1c + CARRY4(uVar30,local_d20) +
                    ((local_d3c * 8 | local_d40 >> 0x1d) ^ (local_d3c >> 0x13 | local_d40 * 0x2000)
                    ^ local_d3c >> 6) + (uint)CARRY4(uVar13,uVar18);
        uVar30 = local_d60 + local_d00[-0xe];
        uVar13 = uVar30 + uVar22;
        uVar16 = (uVar10 >> 0x12 | uVar12 * 0x4000) ^ (uVar10 >> 0xe | uVar12 * 0x40000) ^
                 (uVar10 * 0x800000 | uVar12 >> 9);
        uVar18 = uVar13 + uVar16;
        uVar11 = uVar25 & ~uVar10 ^ uVar10 & uVar15;
        uVar19 = uVar18 + uVar11;
        iVar33 = local_d5c + local_d00[-0xd] + (uint)CARRY4(local_d60,local_d00[-0xe]) +
                 uVar26 + CARRY4(uVar30,uVar22) +
                 ((uVar12 >> 0x12 | uVar10 * 0x4000) ^ (uVar12 >> 0xe | uVar10 * 0x40000) ^
                 (uVar12 * 0x800000 | uVar10 >> 9)) + (uint)CARRY4(uVar13,uVar16) +
                 (uVar27 & ~uVar12 ^ uVar12 & uVar20) + (uint)CARRY4(uVar18,uVar11);
        uVar11 = uVar19 + uVar17;
        uVar13 = iVar33 + uVar21 + CARRY4(uVar19,uVar17);
        uVar17 = uVar31 & uVar24 ^ uVar31 & uVar9 ^ uVar9 & uVar24;
        uVar18 = (uVar31 * 0x40000000 | uVar32 >> 2) ^ (uVar31 >> 0x1c | uVar32 * 0x10) ^
                 (uVar31 * 0x2000000 | uVar32 >> 7);
        uVar16 = (local_d50 >> 8 | local_d4c << 0x18) ^ (local_d50 >> 1 | local_d4c << 0x1f) ^
                 (local_d50 >> 7 | local_d4c << 0x19);
        uVar30 = uVar17 + uVar18;
        bVar35 = CARRY4(uVar16,local_d68);
        uVar16 = uVar16 + local_d68;
        uVar21 = uVar30 + uVar19;
        uVar28 = (uVar32 & uVar14 ^ uVar32 & uVar23 ^ uVar23 & uVar14) +
                 ((uVar32 * 0x40000000 | uVar31 >> 2) ^ (uVar32 >> 0x1c | uVar31 * 0x10) ^
                 (uVar32 * 0x2000000 | uVar31 >> 7)) + (uint)CARRY4(uVar17,uVar18) +
                 iVar33 + (uint)CARRY4(uVar30,uVar19);
        uVar17 = (local_d58 * 8 | local_d54 >> 0x1d) ^ (local_d58 >> 0x13 | local_d54 * 0x2000) ^
                 (local_d58 >> 6 | local_d54 * 0x4000000);
        uVar30 = uVar16 + local_d28;
        local_d68 = uVar30 + uVar17;
        local_d64 = ((local_d4c >> 8 | local_d50 << 0x18) ^ (local_d4c >> 1 | local_d50 << 0x1f) ^
                    local_d4c >> 7) + local_d64 + bVar35 + local_d24 + CARRY4(uVar16,local_d28) +
                    ((local_d54 * 8 | local_d58 >> 0x1d) ^ (local_d54 >> 0x13 | local_d58 * 0x2000)
                    ^ local_d54 >> 6) + (uint)CARRY4(uVar30,uVar17);
        uVar17 = local_d68 + local_d00[-0xc];
        uVar18 = uVar17 + uVar25;
        uVar16 = (uVar11 >> 0x12 | uVar13 * 0x4000) ^ (uVar11 >> 0xe | uVar13 * 0x40000) ^
                 (uVar11 * 0x800000 | uVar13 >> 9);
        uVar19 = uVar18 + uVar16;
        uVar30 = uVar15 & ~uVar11 ^ uVar11 & uVar10;
        uVar22 = uVar19 + uVar30;
        iVar33 = local_d64 + local_d00[-0xb] + (uint)CARRY4(local_d68,local_d00[-0xc]) +
                 uVar27 + CARRY4(uVar17,uVar25) +
                 ((uVar13 >> 0x12 | uVar11 * 0x4000) ^ (uVar13 >> 0xe | uVar11 * 0x40000) ^
                 (uVar13 * 0x800000 | uVar11 >> 9)) + (uint)CARRY4(uVar18,uVar16) +
                 (uVar20 & ~uVar13 ^ uVar13 & uVar12) + (uint)CARRY4(uVar19,uVar30);
        uVar17 = uVar22 + uVar24;
        uVar18 = iVar33 + uVar14 + CARRY4(uVar22,uVar24);
        uVar19 = uVar21 & uVar9 ^ uVar21 & uVar31 ^ uVar31 & uVar9;
        uVar24 = (uVar21 * 0x40000000 | uVar28 >> 2) ^ (uVar21 >> 0x1c | uVar28 * 0x10) ^
                 (uVar21 * 0x2000000 | uVar28 >> 7);
        uVar30 = uVar19 + uVar24;
        uVar16 = (local_d78 >> 8 | local_d74 << 0x18) ^ (local_d78 >> 1 | local_d74 << 0x1f) ^
                 (local_d78 >> 7 | local_d74 << 0x19);
        uVar14 = uVar30 + uVar22;
        uVar19 = (uVar28 & uVar23 ^ uVar28 & uVar32 ^ uVar32 & uVar23) +
                 ((uVar28 * 0x40000000 | uVar21 >> 2) ^ (uVar28 >> 0x1c | uVar21 * 0x10) ^
                 (uVar28 * 0x2000000 | uVar21 >> 7)) + (uint)CARRY4(uVar19,uVar24) +
                 iVar33 + (uint)CARRY4(uVar30,uVar22);
        bVar35 = CARRY4(uVar16,local_d50);
        uVar16 = uVar16 + local_d50;
        uVar30 = uVar16 + local_d38;
        uVar24 = (local_d60 * 8 | local_d5c >> 0x1d) ^ (local_d60 >> 0x13 | local_d5c * 0x2000) ^
                 (local_d60 >> 6 | local_d5c * 0x4000000);
        local_d50 = uVar30 + uVar24;
        local_d4c = ((local_d74 >> 8 | local_d78 << 0x18) ^ (local_d74 >> 1 | local_d78 << 0x1f) ^
                    local_d74 >> 7) + local_d4c + bVar35 + local_d34 + CARRY4(uVar16,local_d38) +
                    ((local_d5c * 8 | local_d60 >> 0x1d) ^ (local_d5c >> 0x13 | local_d60 * 0x2000)
                    ^ local_d5c >> 6) + (uint)CARRY4(uVar30,uVar24);
        uVar24 = local_d50 + local_d00[-10];
        uVar22 = uVar24 + uVar15;
        uVar30 = (uVar17 >> 0x12 | uVar18 * 0x4000) ^ (uVar17 >> 0xe | uVar18 * 0x40000) ^
                 (uVar17 * 0x800000 | uVar18 >> 9);
        uVar25 = uVar22 + uVar30;
        uVar16 = uVar10 & ~uVar17 ^ uVar17 & uVar11;
        uVar26 = uVar25 + uVar16;
        iVar33 = local_d4c + local_d00[-9] + (uint)CARRY4(local_d50,local_d00[-10]) +
                 uVar20 + CARRY4(uVar24,uVar15) +
                 ((uVar18 >> 0x12 | uVar17 * 0x4000) ^ (uVar18 >> 0xe | uVar17 * 0x40000) ^
                 (uVar18 * 0x800000 | uVar17 >> 9)) + (uint)CARRY4(uVar22,uVar30) +
                 (uVar12 & ~uVar18 ^ uVar18 & uVar13) + (uint)CARRY4(uVar25,uVar16);
        uVar24 = uVar26 + uVar9;
        uVar15 = iVar33 + uVar23 + CARRY4(uVar26,uVar9);
        uVar9 = uVar14 & uVar31 ^ uVar14 & uVar21 ^ uVar21 & uVar31;
        uVar23 = (uVar14 * 0x40000000 | uVar19 >> 2) ^ (uVar14 >> 0x1c | uVar19 * 0x10) ^
                 (uVar14 * 0x2000000 | uVar19 >> 7);
        uVar16 = uVar9 + uVar23;
        uVar30 = (local_d70 >> 8 | local_d6c << 0x18) ^ (local_d70 >> 1 | local_d6c << 0x1f) ^
                 (local_d70 >> 7 | local_d6c << 0x19);
        bVar35 = CARRY4(uVar30,local_d78);
        uVar30 = uVar30 + local_d78;
        uVar22 = uVar16 + uVar26;
        uVar26 = (uVar19 & uVar32 ^ uVar19 & uVar28 ^ uVar28 & uVar32) +
                 ((uVar19 * 0x40000000 | uVar14 >> 2) ^ (uVar19 >> 0x1c | uVar14 * 0x10) ^
                 (uVar19 * 0x2000000 | uVar14 >> 7)) + (uint)CARRY4(uVar9,uVar23) +
                 iVar33 + (uint)CARRY4(uVar16,uVar26);
        uVar16 = (local_d68 * 8 | local_d64 >> 0x1d) ^ (local_d68 >> 0x13 | local_d64 * 0x2000) ^
                 (local_d68 >> 6 | local_d64 * 0x4000000);
        uVar9 = uVar30 + local_d30;
        local_d78 = uVar9 + uVar16;
        local_d74 = ((local_d6c >> 8 | local_d70 << 0x18) ^ (local_d6c >> 1 | local_d70 << 0x1f) ^
                    local_d6c >> 7) + local_d74 + bVar35 + local_d2c + CARRY4(uVar30,local_d30) +
                    ((local_d64 * 8 | local_d68 >> 0x1d) ^ (local_d64 >> 0x13 | local_d68 * 0x2000)
                    ^ local_d64 >> 6) + (uint)CARRY4(uVar9,uVar16);
        uVar9 = local_d78 + local_d00[-8];
        uVar16 = uVar9 + uVar10;
        uVar25 = (uVar24 >> 0x12 | uVar15 * 0x4000) ^ (uVar24 >> 0xe | uVar15 * 0x40000) ^
                 (uVar24 * 0x800000 | uVar15 >> 9);
        uVar30 = uVar16 + uVar25;
        uVar23 = uVar11 & ~uVar24 ^ uVar24 & uVar17;
        uVar20 = uVar23 + uVar30;
        iVar33 = (uVar13 & ~uVar15 ^ uVar15 & uVar18) +
                 local_d74 + local_d00[-7] + (uint)CARRY4(local_d78,local_d00[-8]) +
                 uVar12 + CARRY4(uVar9,uVar10) +
                 ((uVar15 >> 0x12 | uVar24 * 0x4000) ^ (uVar15 >> 0xe | uVar24 * 0x40000) ^
                 (uVar15 * 0x800000 | uVar24 >> 9)) + (uint)CARRY4(uVar16,uVar25) +
                 (uint)CARRY4(uVar23,uVar30);
        uVar12 = uVar20 + uVar31;
        uVar25 = iVar33 + uVar32 + CARRY4(uVar20,uVar31);
        uVar10 = uVar22 & uVar21 ^ uVar22 & uVar14 ^ uVar14 & uVar21;
        uVar9 = (uVar22 * 0x40000000 | uVar26 >> 2) ^ (uVar22 >> 0x1c | uVar26 * 0x10) ^
                (uVar22 * 0x2000000 | uVar26 >> 7);
        uVar16 = uVar10 + uVar9;
        uVar27 = uVar16 + uVar20;
        uVar31 = (uVar26 & uVar28 ^ uVar26 & uVar19 ^ uVar19 & uVar28) +
                 ((uVar26 * 0x40000000 | uVar22 >> 2) ^ (uVar26 >> 0x1c | uVar22 * 0x10) ^
                 (uVar26 * 0x2000000 | uVar22 >> 7)) + (uint)CARRY4(uVar10,uVar9) +
                 iVar33 + (uint)CARRY4(uVar16,uVar20);
        uVar10 = (local_d80 >> 8 | local_d7c << 0x18) ^ (local_d80 >> 1 | local_d7c << 0x1f) ^
                 (local_d80 >> 7 | local_d7c << 0x19);
        bVar35 = CARRY4(uVar10,local_d70);
        uVar10 = uVar10 + local_d70;
        uVar16 = uVar10 + local_d48;
        uVar9 = (local_d50 * 8 | local_d4c >> 0x1d) ^ (local_d50 >> 0x13 | local_d4c * 0x2000) ^
                (local_d50 >> 6 | local_d4c * 0x4000000);
        local_d70 = uVar16 + uVar9;
        local_d6c = ((local_d7c >> 8 | local_d80 << 0x18) ^ (local_d7c >> 1 | local_d80 << 0x1f) ^
                    local_d7c >> 7) + local_d6c + bVar35 + local_d44 + CARRY4(uVar10,local_d48) +
                    ((local_d4c * 8 | local_d50 >> 0x1d) ^ (local_d4c >> 0x13 | local_d50 * 0x2000)
                    ^ local_d4c >> 6) + (uint)CARRY4(uVar16,uVar9);
        uVar10 = local_d70 + local_d00[-6];
        uVar20 = (uVar12 >> 0x12 | uVar25 * 0x4000) ^ (uVar12 >> 0xe | uVar25 * 0x40000) ^
                 (uVar12 * 0x800000 | uVar25 >> 9);
        uVar16 = uVar10 + uVar11;
        uVar30 = uVar16 + uVar20;
        uVar9 = uVar17 & ~uVar12 ^ uVar12 & uVar24;
        uVar23 = uVar30 + uVar9;
        iVar33 = local_d6c + local_d00[-5] + (uint)CARRY4(local_d70,local_d00[-6]) +
                 uVar13 + CARRY4(uVar10,uVar11) +
                 ((uVar25 >> 0x12 | uVar12 * 0x4000) ^ (uVar25 >> 0xe | uVar12 * 0x40000) ^
                 (uVar25 * 0x800000 | uVar12 >> 9)) + (uint)CARRY4(uVar16,uVar20) +
                 (uVar18 & ~uVar25 ^ uVar25 & uVar15) + (uint)CARRY4(uVar30,uVar9);
        local_dd0 = uVar23 + uVar21;
        local_dcc = iVar33 + uVar28 + CARRY4(uVar23,uVar21);
        uVar11 = uVar27 & uVar14 ^ uVar27 & uVar22 ^ uVar22 & uVar14;
        uVar9 = (uVar27 * 0x40000000 | uVar31 >> 2) ^ (uVar27 >> 0x1c | uVar31 * 0x10) ^
                (uVar27 * 0x2000000 | uVar31 >> 7);
        uVar10 = uVar9 + uVar11;
        local_dc0 = uVar10 + uVar23;
        local_dbc = ((uVar31 * 0x40000000 | uVar27 >> 2) ^ (uVar31 >> 0x1c | uVar27 * 0x10) ^
                    (uVar31 * 0x2000000 | uVar27 >> 7)) +
                    (uVar31 & uVar19 ^ uVar31 & uVar26 ^ uVar26 & uVar19) +
                    (uint)CARRY4(uVar9,uVar11) + iVar33 + (uint)CARRY4(uVar10,uVar23);
        uVar9 = (local_d88 >> 8 | local_d84 << 0x18) ^ (local_d88 >> 1 | local_d84 << 0x1f) ^
                (local_d88 >> 7 | local_d84 << 0x19);
        bVar35 = CARRY4(uVar9,local_d80);
        uVar9 = uVar9 + local_d80;
        uVar10 = uVar9 + local_d40;
        uVar11 = (local_d78 * 8 | local_d74 >> 0x1d) ^ (local_d78 >> 0x13 | local_d74 * 0x2000) ^
                 (local_d78 >> 6 | local_d74 * 0x4000000);
        local_d80 = uVar10 + uVar11;
        local_d7c = ((local_d84 >> 8 | local_d88 << 0x18) ^ (local_d84 >> 1 | local_d88 << 0x1f) ^
                    local_d84 >> 7) + local_d7c + bVar35 + local_d3c + CARRY4(uVar9,local_d40) +
                    ((local_d74 * 8 | local_d78 >> 0x1d) ^ (local_d74 >> 0x13 | local_d78 * 0x2000)
                    ^ local_d74 >> 6) + (uint)CARRY4(uVar10,uVar11);
        uVar11 = local_d00[-4] + local_d80;
        uVar16 = uVar11 + uVar17;
        uVar23 = (local_dd0 >> 0x12 | local_dcc * 0x4000) ^ (local_dd0 >> 0xe | local_dcc * 0x40000)
                 ^ (local_dd0 * 0x800000 | local_dcc >> 9);
        uVar30 = uVar16 + uVar23;
        uVar9 = local_dd0 & uVar12 ^ uVar24 & ~local_dd0;
        uVar10 = uVar9 + uVar30;
        iVar33 = (local_dcc & uVar25 ^ uVar15 & ~local_dcc) +
                 local_d00[-3] + local_d7c + CARRY4(local_d00[-4],local_d80) +
                 uVar18 + CARRY4(uVar11,uVar17) +
                 ((local_dcc >> 0x12 | local_dd0 * 0x4000) ^
                  (local_dcc >> 0xe | local_dd0 * 0x40000) ^ (local_dcc * 0x800000 | local_dd0 >> 9)
                 ) + (uint)CARRY4(uVar16,uVar23) + (uint)CARRY4(uVar9,uVar30);
        uVar16 = local_dc0 & uVar22 ^ local_dc0 & uVar27 ^ uVar27 & uVar22;
        uVar11 = (local_dc0 * 0x40000000 | local_dbc >> 2) ^ (local_dc0 >> 0x1c | local_dbc * 0x10)
                 ^ (local_dc0 * 0x2000000 | local_dbc >> 7);
        local_d98 = uVar10 + uVar14;
        local_d94 = iVar33 + uVar19 + CARRY4(uVar10,uVar14);
        uVar9 = uVar16 + uVar11;
        local_dc8 = uVar9 + uVar10;
        local_dc4 = (local_dbc & uVar26 ^ local_dbc & uVar31 ^ uVar31 & uVar26) +
                    ((local_dbc * 0x40000000 | local_dc0 >> 2) ^
                     (local_dbc >> 0x1c | local_dc0 * 0x10) ^
                    (local_dbc * 0x2000000 | local_dc0 >> 7)) + (uint)CARRY4(uVar16,uVar11) +
                    iVar33 + (uint)CARRY4(uVar9,uVar10);
        uVar9 = (local_d90 >> 8 | local_d8c << 0x18) ^ (local_d90 >> 1 | local_d8c << 0x1f) ^
                (local_d90 >> 7 | local_d8c << 0x19);
        bVar35 = CARRY4(uVar9,local_d88);
        uVar9 = uVar9 + local_d88;
        uVar10 = uVar9 + local_d58;
        uVar11 = (local_d70 * 8 | local_d6c >> 0x1d) ^ (local_d70 >> 0x13 | local_d6c * 0x2000) ^
                 (local_d70 >> 6 | local_d6c * 0x4000000);
        local_d88 = uVar10 + uVar11;
        local_d84 = ((local_d8c >> 8 | local_d90 << 0x18) ^ (local_d8c >> 1 | local_d90 << 0x1f) ^
                    local_d8c >> 7) + local_d84 + bVar35 + local_d54 + CARRY4(uVar9,local_d58) +
                    ((local_d6c * 8 | local_d70 >> 0x1d) ^ (local_d6c >> 0x13 | local_d70 * 0x2000)
                    ^ local_d6c >> 6) + (uint)CARRY4(uVar10,uVar11);
        uVar11 = local_d00[-2] + local_d88;
        uVar30 = uVar11 + uVar24;
        uVar9 = (local_d98 >> 0x12 | local_d94 * 0x4000) ^ (local_d98 >> 0xe | local_d94 * 0x40000)
                ^ (local_d98 * 0x800000 | local_d94 >> 9);
        uVar23 = uVar30 + uVar9;
        uVar10 = uVar12 & ~local_d98 ^ local_d98 & local_dd0;
        uVar16 = uVar10 + uVar23;
        iVar33 = (uVar25 & ~local_d94 ^ local_d94 & local_dcc) +
                 local_d00[-1] + local_d84 + CARRY4(local_d00[-2],local_d88) +
                 uVar15 + CARRY4(uVar11,uVar24) +
                 ((local_d94 >> 0x12 | local_d98 * 0x4000) ^
                  (local_d94 >> 0xe | local_d98 * 0x40000) ^ (local_d94 * 0x800000 | local_d98 >> 9)
                 ) + (uint)CARRY4(uVar30,uVar9) + (uint)CARRY4(uVar10,uVar23);
        uVar11 = local_dc8 & uVar27 ^ local_dc8 & local_dc0 ^ local_dc0 & uVar27;
        uVar9 = (local_dc8 * 0x40000000 | local_dc4 >> 2) ^ (local_dc8 >> 0x1c | local_dc4 * 0x10) ^
                (local_dc8 * 0x2000000 | local_dc4 >> 7);
        local_db8 = uVar16 + uVar22;
        local_db4 = iVar33 + uVar26 + CARRY4(uVar16,uVar22);
        uVar10 = uVar9 + uVar11;
        local_db0 = uVar10 + uVar16;
        local_dac = ((local_dc4 * 0x40000000 | local_dc8 >> 2) ^
                     (local_dc4 >> 0x1c | local_dc8 * 0x10) ^
                    (local_dc4 * 0x2000000 | local_dc8 >> 7)) +
                    (local_dc4 & uVar31 ^ local_dc4 & local_dbc ^ local_dbc & uVar31) +
                    (uint)CARRY4(uVar9,uVar11) + iVar33 + (uint)CARRY4(uVar10,uVar16);
        HintPreloadData(&DAT_00156be0 + local_cf0 * 2);
        HintPreloadData(&DAT_00156be8 + local_cf0 * 2);
        uVar9 = (local_d10 >> 8 | local_d0c * 0x1000000) ^
                (local_d10 >> 1 | local_d0c * -0x80000000) ^
                (local_d10 >> 7 | local_d0c * 0x2000000);
        local_d18 = local_db0 & local_dc8;
        local_d14 = local_dac & local_dc4;
        bVar35 = CARRY4(uVar9,local_d90);
        uVar9 = uVar9 + local_d90;
        HintPreloadData(&DAT_00156bf0 + local_cf0 * 2);
        HintPreloadData(&DAT_00156bf8 + local_cf0 * 2);
        uVar11 = (local_d80 * 8 | local_d7c >> 0x1d) ^ (local_d80 >> 0x13 | local_d7c * 0x2000) ^
                 (local_d80 >> 6 | local_d7c * 0x4000000);
        uVar10 = uVar9 + local_d60;
        local_d90 = uVar10 + uVar11;
        local_d8c = ((local_d0c >> 8 | local_d10 * 0x1000000) ^
                     (local_d0c >> 1 | local_d10 * -0x80000000) ^ local_d0c >> 7) +
                    local_d8c + bVar35 + local_d5c + CARRY4(uVar9,local_d60) +
                    ((local_d7c * 8 | local_d80 >> 0x1d) ^ (local_d7c >> 0x13 | local_d80 * 0x2000)
                    ^ local_d7c >> 6) + (uint)CARRY4(uVar10,uVar11);
        uVar13 = local_d90 + *local_d00;
        uVar11 = uVar13 + uVar12;
        uVar23 = (local_db8 >> 0x12 | local_db4 * 0x4000) ^ (local_db8 >> 0xe | local_db4 * 0x40000)
                 ^ (local_db8 * 0x800000 | local_db4 >> 9);
        uVar30 = local_db0 & local_dc0 ^ local_d18 ^ local_dc8 & local_dc0;
        uVar9 = (local_db0 * 0x40000000 | local_dac >> 2) ^ (local_db0 >> 0x1c | local_dac * 0x10) ^
                (local_db0 * 0x2000000 | local_dac >> 7);
        uVar24 = uVar11 + uVar23;
        uVar10 = uVar9 + uVar30;
        uVar16 = local_dd0 & ~local_db8 ^ local_db8 & local_d98;
        uVar17 = uVar24 + uVar16;
        iVar33 = local_d8c + local_d00[1] + (uint)CARRY4(local_d90,*local_d00) +
                 uVar25 + CARRY4(uVar13,uVar12) +
                 ((local_db4 >> 0x12 | local_db8 * 0x4000) ^
                  (local_db4 >> 0xe | local_db8 * 0x40000) ^ (local_db4 * 0x800000 | local_db8 >> 9)
                 ) + (uint)CARRY4(uVar11,uVar23) +
                 (local_dcc & ~local_db4 ^ local_db4 & local_d94) + (uint)CARRY4(uVar24,uVar16);
        local_cf0 = local_cf0 + 0x10;
        local_da8 = uVar17 + uVar27;
        local_da4 = iVar33 + uVar31 + CARRY4(uVar17,uVar27);
        local_da0 = uVar10 + uVar17;
        local_d9c = ((local_dac * 0x40000000 | local_db0 >> 2) ^
                     (local_dac >> 0x1c | local_db0 * 0x10) ^
                    (local_dac * 0x2000000 | local_db0 >> 7)) +
                    (local_dac & local_dbc ^ local_d14 ^ local_dc4 & local_dbc) +
                    (uint)CARRY4(uVar9,uVar30) + iVar33 + (uint)CARRY4(uVar10,uVar17);
        local_d00 = local_d00 + 0x20;
      } while (local_cf0 != 0x50);
      bVar35 = CARRY4(local_ce0,local_da0);
      local_ce0 = local_ce0 + local_da0;
      local_cdc = local_cdc + local_d9c + bVar35;
      bVar35 = CARRY4(local_6c8,local_db0);
      local_6c8 = local_6c8 + local_db0;
      uStack_6c4 = uStack_6c4 + local_dac + bVar35;
      bVar35 = CARRY4(local_6c0,local_dc8);
      local_6c0 = local_6c0 + local_dc8;
      uStack_6bc = uStack_6bc + local_dc4 + bVar35;
      bVar35 = CARRY4(local_6a8,local_dc0);
      local_6a8 = local_6a8 + local_dc0;
      uStack_6a4 = uStack_6a4 + local_dbc + bVar35;
      bVar35 = CARRY4(local_cd8,local_da8);
      local_cd8 = local_cd8 + local_da8;
      local_cd4 = local_cd4 + local_da4 + bVar35;
      bVar35 = CARRY4(local_6b8,local_db8);
      local_6b8 = local_6b8 + local_db8;
      uStack_6b4 = uStack_6b4 + local_db4 + bVar35;
      bVar35 = CARRY4(local_6b0,local_d98);
      local_6b0 = local_6b0 + local_d98;
      uStack_6ac = uStack_6ac + local_d94 + bVar35;
      bVar35 = CARRY4(local_6a0,local_dd0);
      local_6a0 = local_6a0 + local_dd0;
      uStack_69c = uStack_69c + local_dcc + bVar35;
      *param_1 = local_ce0;
      param_1[1] = local_cdc;
      param_1[2] = local_6c8;
      param_1[3] = uStack_6c4;
      param_1[4] = local_6c0;
      param_1[5] = uStack_6bc;
      param_1[6] = local_6a8;
      param_1[7] = uStack_6a4;
      param_1[10] = local_6b8;
      param_1[0xb] = uStack_6b4;
      param_1[8] = local_cd8;
      param_1[9] = local_cd4;
      local_28 = local_28 + -1;
      param_1[0xc] = local_6b0;
      param_1[0xd] = uStack_6ac;
      param_1[0xe] = local_6a0;
      param_1[0xf] = uStack_69c;
    } while (local_28 != 0);
  }
  return;
}


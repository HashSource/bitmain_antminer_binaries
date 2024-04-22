
void sha_block_data_order(uint *param_1,byte *param_2,int param_3)

{
  uint uVar1;
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
  uint uVar27;
  uint uVar28;
  uint uVar29;
  byte *local_a4;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_50;
  uint local_4c;
  int local_30;
  
  local_5c = *param_1;
  local_50 = param_1[1];
  local_60 = param_1[2];
  local_58 = param_1[3];
  local_4c = param_1[4];
  local_a4 = param_2;
  local_30 = param_3;
  do {
    uVar1 = local_50 >> 2 | local_50 << 0x1e;
    uVar17 = (uint)local_a4[1] << 0x10 | (uint)*local_a4 << 0x18 | (uint)local_a4[3] |
             (uint)local_a4[2] << 8;
    uVar11 = (uint)local_a4[5] << 0x10 | (uint)local_a4[4] << 0x18 | (uint)local_a4[7] |
             (uint)local_a4[6] << 8;
    uVar2 = local_5c >> 2 | local_5c << 0x1e;
    uVar6 = (local_5c >> 0x1b | local_5c << 5) + 0x5a827999 +
            ((local_58 ^ local_60) & local_50 ^ local_58) + uVar17 + local_4c;
    uVar7 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar15 = (uint)local_a4[9] << 0x10 | (uint)local_a4[8] << 0x18 | (uint)local_a4[0xb] |
             (uint)local_a4[10] << 8;
    uVar8 = local_58 + 0x5a827999 + ((uVar1 ^ local_60) & local_5c ^ local_60) + uVar11 +
            (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar25 = (uint)local_a4[0xd] << 0x10 | (uint)local_a4[0xc] << 0x18 | (uint)local_a4[0xf] |
             (uint)local_a4[0xe] << 8;
    uVar12 = local_60 + 0x5a827999 + uVar15 + (uVar6 & (uVar2 ^ uVar1) ^ uVar1) +
             (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar18 = (uint)local_a4[0x11] << 0x10 | (uint)local_a4[0x10] << 0x18 | (uint)local_a4[0x13] |
             (uint)local_a4[0x12] << 8;
    uVar6 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar26 = ((uVar7 ^ uVar2) & uVar8 ^ uVar2) + uVar1 + 0x5a827999 + uVar25 +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar1 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar20 = (uint)local_a4[0x15] << 0x10 | (uint)local_a4[0x14] << 0x18 | (uint)local_a4[0x17] |
             (uint)local_a4[0x16] << 8;
    uVar8 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar16 = (uint)local_a4[0x19] << 0x10 | (uint)local_a4[0x18] << 0x18 | (uint)local_a4[0x1b] |
             (uint)local_a4[0x1a] << 8;
    uVar12 = uVar2 + 0x5a827999 + uVar18 + ((uVar6 ^ uVar7) & uVar12 ^ uVar7) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar2 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = uVar20 + 0x5a827999 + uVar7 + ((uVar1 ^ uVar6) & uVar26 ^ uVar6) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar6 = uVar16 + 0x5a827999 + uVar6 + ((uVar8 ^ uVar1) & uVar12 ^ uVar1) +
            (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar21 = (uint)local_a4[0x1d] << 0x10 | (uint)local_a4[0x1c] << 0x18 | (uint)local_a4[0x1f] |
             (uint)local_a4[0x1e] << 8;
    uVar7 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar3 = (uint)local_a4[0x25] << 0x10 | (uint)local_a4[0x24] << 0x18 | (uint)local_a4[0x27] |
            (uint)local_a4[0x26] << 8;
    uVar12 = ((uVar2 ^ uVar8) & uVar26 ^ uVar8) + uVar1 + uVar21 + 0x5a827999 +
             (uVar6 >> 0x1b | uVar6 * 0x20);
    uVar19 = (uint)local_a4[0x21] << 0x10 | (uint)local_a4[0x20] << 0x18 | (uint)local_a4[0x23] |
             (uint)local_a4[0x22] << 8;
    uVar1 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar4 = (uint)local_a4[0x29] << 0x10 | (uint)local_a4[0x28] << 0x18 | (uint)local_a4[0x2b] |
            (uint)local_a4[0x2a] << 8;
    uVar8 = ((uVar7 ^ uVar2) & uVar6 ^ uVar2) + uVar19 + 0x5a827999 + uVar8 +
            (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar6 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar12 = ((uVar1 ^ uVar7) & uVar12 ^ uVar7) + uVar2 + uVar3 + 0x5a827999 +
             (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar5 = (uint)local_a4[0x2d] << 0x10 | (uint)local_a4[0x2c] << 0x18 | (uint)local_a4[0x2f] |
            (uint)local_a4[0x2e] << 8;
    uVar2 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar27 = (uint)local_a4[0x31] << 0x10 | (uint)local_a4[0x30] << 0x18 | (uint)local_a4[0x33] |
             (uint)local_a4[0x32] << 8;
    uVar8 = uVar4 + 0x5a827999 + uVar7 + ((uVar6 ^ uVar1) & uVar8 ^ uVar1) +
            (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar13 = (uint)local_a4[0x35] << 0x10 | (uint)local_a4[0x34] << 0x18 | (uint)local_a4[0x37] |
             (uint)local_a4[0x36] << 8;
    uVar26 = ((uVar2 ^ uVar6) & uVar12 ^ uVar6) + uVar5 + 0x5a827999 + uVar1 +
             (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar1 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar12 = uVar6 + uVar27 + 0x5a827999 + ((uVar7 ^ uVar2) & uVar8 ^ uVar2) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar14 = (uint)local_a4[0x39] << 0x10 | (uint)local_a4[0x38] << 0x18 | (uint)local_a4[0x3b] |
             (uint)local_a4[0x3a] << 8;
    uVar6 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar8 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = uVar13 + 0x5a827999 + uVar2 + ((uVar1 ^ uVar7) & uVar26 ^ uVar7) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar10 = (uint)local_a4[0x3d] << 0x10 | (uint)local_a4[0x3c] << 0x18 | (uint)local_a4[0x3f] |
             (uint)local_a4[0x3e] << 8;
    uVar17 = uVar15 ^ uVar17 ^ uVar19 ^ uVar13;
    uVar12 = (uVar12 & (uVar6 ^ uVar1) ^ uVar1) + uVar14 + 0x5a827999 + uVar7 +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar9 = uVar25 ^ uVar11 ^ uVar3 ^ uVar14;
    uVar26 = uVar1 + uVar10 + 0x5a827999 + ((uVar8 ^ uVar6) & uVar26 ^ uVar6) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar28 = uVar17 + 0x5a827999 + uVar6 + (uVar12 & (uVar2 ^ uVar8) ^ uVar8) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar1 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar18 ^ uVar15 ^ uVar4 ^ uVar10;
    uVar26 = uVar9 + 0x5a827999 + uVar8 + (uVar26 & (uVar7 ^ uVar2) ^ uVar2) +
             (uVar28 >> 0x1b | uVar28 * 0x20);
    uVar11 = uVar20 ^ uVar25 ^ uVar5 ^ uVar17;
    uVar6 = uVar28 >> 2 | uVar28 * 0x40000000;
    uVar8 = uVar12 + 0x5a827999 + uVar2 + ((uVar1 ^ uVar7) & uVar28 ^ uVar7) +
            (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar25 = uVar16 ^ uVar18 ^ uVar27 ^ uVar9;
    uVar26 = uVar11 + 0x5a827999 + uVar7 + (uVar26 & (uVar6 ^ uVar1) ^ uVar1) +
             (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar7 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar15 = uVar21 ^ uVar20 ^ uVar13 ^ uVar12;
    uVar28 = uVar19 ^ uVar16 ^ uVar14 ^ uVar11;
    uVar16 = uVar25 + 0x6ed9eba1 + uVar1 + (uVar2 ^ uVar6 ^ uVar8) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar1 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar20 = uVar3 ^ uVar21 ^ uVar10 ^ uVar25;
    uVar8 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar26 = uVar6 + uVar15 + 0x6ed9eba1 + (uVar7 ^ uVar2 ^ uVar26) +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar18 = uVar4 ^ uVar19 ^ uVar17 ^ uVar15;
    uVar6 = uVar28 + 0x6ed9eba1 + uVar2 + (uVar1 ^ uVar7 ^ uVar16) +
            (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar26 = uVar20 + 0x6ed9eba1 + uVar7 + (uVar8 ^ uVar1 ^ uVar26) + (uVar6 >> 0x1b | uVar6 * 0x20)
    ;
    uVar21 = uVar5 ^ uVar3 ^ uVar9 ^ uVar28;
    uVar7 = uVar6 >> 2 | uVar6 * 0x40000000;
    uVar3 = uVar1 + uVar18 + 0x6ed9eba1 + (uVar2 ^ uVar8 ^ uVar6) + (uVar26 >> 0x1b | uVar26 * 0x20)
    ;
    uVar1 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar22 = uVar27 ^ uVar4 ^ uVar12 ^ uVar20;
    uVar6 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar24 = uVar13 ^ uVar5 ^ uVar11 ^ uVar18;
    uVar4 = uVar21 + 0x6ed9eba1 + uVar8 + (uVar7 ^ uVar2 ^ uVar26) + (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar8 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar26 = uVar22 + 0x6ed9eba1 + uVar2 + (uVar1 ^ uVar7 ^ uVar3) + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar19 = uVar14 ^ uVar27 ^ uVar25 ^ uVar21;
    uVar7 = uVar7 + uVar24 + 0x6ed9eba1 + (uVar6 ^ uVar1 ^ uVar4) + (uVar26 >> 0x1b | uVar26 * 0x20)
    ;
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar26 = uVar19 + 0x6ed9eba1 + uVar1 + (uVar8 ^ uVar6 ^ uVar26) + (uVar7 >> 0x1b | uVar7 * 0x20)
    ;
    uVar29 = uVar10 ^ uVar13 ^ uVar15 ^ uVar22;
    uVar1 = uVar7 >> 2 | uVar7 * 0x40000000;
    uVar3 = uVar29 + 0x6ed9eba1 + uVar6 + (uVar2 ^ uVar8 ^ uVar7) + (uVar26 >> 0x1b | uVar26 * 0x20)
    ;
    uVar13 = uVar17 ^ uVar14 ^ uVar28 ^ uVar24;
    uVar7 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar6 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar4 = uVar13 + 0x6ed9eba1 + uVar8 + (uVar1 ^ uVar2 ^ uVar26) + (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar16 = uVar9 ^ uVar10 ^ uVar20 ^ uVar19;
    uVar10 = uVar12 ^ uVar17 ^ uVar18 ^ uVar29;
    uVar8 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar5 = uVar16 + 0x6ed9eba1 + uVar2 + (uVar7 ^ uVar1 ^ uVar3) + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar9 = uVar11 ^ uVar9 ^ uVar21 ^ uVar13;
    uVar2 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar12 = uVar25 ^ uVar12 ^ uVar22 ^ uVar16;
    uVar26 = uVar15 ^ uVar11 ^ uVar24 ^ uVar10;
    uVar3 = uVar28 ^ uVar25 ^ uVar19 ^ uVar9;
    uVar17 = uVar20 ^ uVar15 ^ uVar29 ^ uVar12;
    uVar23 = uVar18 ^ uVar28 ^ uVar13 ^ uVar26;
    uVar28 = uVar21 ^ uVar20 ^ uVar16 ^ uVar3;
    uVar27 = uVar22 ^ uVar18 ^ uVar10 ^ uVar17;
    uVar21 = uVar24 ^ uVar21 ^ uVar9 ^ uVar23;
    uVar22 = uVar19 ^ uVar22 ^ uVar12 ^ uVar28;
    uVar24 = uVar29 ^ uVar24 ^ uVar26 ^ uVar27;
    uVar20 = uVar13 ^ uVar19 ^ uVar3 ^ uVar21;
    uVar14 = uVar13 ^ uVar10 ^ uVar23 ^ uVar24;
    uVar29 = uVar16 ^ uVar29 ^ uVar17 ^ uVar22;
    HintPreloadData(local_a4 + 0x41);
    uVar11 = uVar16 ^ uVar9 ^ uVar28 ^ uVar20;
    uVar15 = uVar12 ^ uVar10 ^ uVar27 ^ uVar29;
    uVar16 = uVar26 ^ uVar9 ^ uVar21 ^ uVar14;
    uVar13 = uVar3 ^ uVar12 ^ uVar22 ^ uVar11;
    HintPreloadData(local_a4 + 0x42);
    HintPreloadData(local_a4 + 0x43);
    uVar18 = uVar17 ^ uVar26 ^ uVar24 ^ uVar15;
    uVar19 = uVar23 ^ uVar3 ^ uVar20 ^ uVar16;
    HintPreloadData(local_a4 + 0x40);
    uVar25 = uVar28 ^ uVar17 ^ uVar29 ^ uVar13;
    uVar4 = uVar10 + 0x6ed9eba1 + uVar1 + (uVar6 ^ uVar7 ^ uVar4) + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar5 = uVar9 + 0x6ed9eba1 + uVar7 + (uVar8 ^ uVar6 ^ uVar5) + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar1 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar4 = uVar12 + 0x6ed9eba1 + uVar6 + (uVar2 ^ uVar8 ^ uVar4) + (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar12 = uVar26 + 0x6ed9eba1 + uVar8 + (uVar5 ^ uVar1 ^ uVar2) + (uVar4 >> 0x1b | uVar4 * 0x20);
    uVar6 = uVar4 >> 2 | uVar4 * 0x40000000;
    uVar26 = uVar3 + 0x6ed9eba1 + uVar2 + (uVar7 ^ uVar1 ^ uVar4) + (uVar12 >> 0x1b | uVar12 * 0x20)
    ;
    uVar2 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar8 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar3 = uVar17 + 0x6ed9eba1 + uVar1 + (uVar12 ^ uVar6 ^ uVar7) +
            (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar12 = uVar7 + uVar23 + 0x6ed9eba1 + (uVar26 ^ uVar2 ^ uVar6) + (uVar3 >> 0x1b | uVar3 * 0x20)
    ;
    uVar1 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = uVar28 + 0x6ed9eba1 + uVar6 + (uVar8 ^ uVar2 ^ uVar3) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar12 = ((uVar12 | uVar1) & uVar8 | uVar12 & uVar1) +
             uVar2 + uVar27 + 0x8f1bbcdc + (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar6 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar8 = uVar21 + 0x8f1bbcdc + uVar8 + (uVar26 & uVar7 | (uVar26 | uVar7) & uVar1) +
            (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar12 = ((uVar12 | uVar2) & uVar7 | uVar12 & uVar2) +
             uVar1 + uVar22 + 0x8f1bbcdc + (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar1 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar8 = uVar24 + 0x8f1bbcdc + uVar7 + ((uVar8 | uVar6) & uVar2 | uVar8 & uVar6) +
            (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = ((uVar12 | uVar1) & uVar6 | uVar12 & uVar1) +
             uVar2 + uVar20 + 0x8f1bbcdc + (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar5 = uVar27 ^ uVar23 ^ uVar14 ^ uVar18;
    uVar2 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar12 = uVar29 + 0x8f1bbcdc + uVar6 + ((uVar8 | uVar7) & uVar1 | uVar8 & uVar7) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar6 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar23 = uVar21 ^ uVar28 ^ uVar11 ^ uVar19;
    uVar8 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = ((uVar26 | uVar2) & uVar7 | uVar26 & uVar2) +
             uVar14 + 0x8f1bbcdc + uVar1 + (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar1 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar11 + 0x8f1bbcdc + uVar7 + ((uVar12 | uVar6) & uVar2 | uVar12 & uVar6) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar28 = uVar22 ^ uVar27 ^ uVar15 ^ uVar25;
    uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar21 = uVar24 ^ uVar21 ^ uVar16 ^ uVar5;
    uVar26 = ((uVar26 | uVar8) & uVar6 | uVar26 & uVar8) +
             uVar15 + 0x8f1bbcdc + uVar2 + (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar12 = uVar16 + 0x8f1bbcdc + uVar6 + (uVar12 & uVar1 | (uVar12 | uVar1) & uVar8) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar27 = uVar20 ^ uVar22 ^ uVar13 ^ uVar23;
    uVar6 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar3 = uVar29 ^ uVar24 ^ uVar18 ^ uVar28;
    uVar26 = ((uVar26 | uVar7) & uVar1 | uVar26 & uVar7) +
             uVar8 + uVar13 + 0x8f1bbcdc + (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar12 = uVar18 + 0x8f1bbcdc + uVar1 + ((uVar12 | uVar2) & uVar7 | uVar12 & uVar2) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar1 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar20 = uVar14 ^ uVar20 ^ uVar19 ^ uVar21;
    uVar8 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar4 = uVar11 ^ uVar29 ^ uVar25 ^ uVar27;
    uVar26 = ((uVar26 | uVar6) & uVar2 | uVar26 & uVar6) +
             uVar7 + uVar19 + 0x8f1bbcdc + (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar7 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar25 + 0x8f1bbcdc + uVar2 + ((uVar12 | uVar1) & uVar6 | uVar12 & uVar1) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar14 = uVar15 ^ uVar14 ^ uVar5 ^ uVar3;
    uVar2 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar22 = uVar16 ^ uVar11 ^ uVar23 ^ uVar20;
    uVar26 = ((uVar26 | uVar8) & uVar1 | uVar26 & uVar8) +
             uVar5 + 0x8f1bbcdc + uVar6 + (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar12 = uVar23 + 0x8f1bbcdc + uVar1 + ((uVar12 | uVar7) & uVar8 | uVar12 & uVar7) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar1 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar11 = uVar13 ^ uVar15 ^ uVar28 ^ uVar4;
    uVar6 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar24 = uVar18 ^ uVar16 ^ uVar21 ^ uVar14;
    uVar26 = ((uVar26 | uVar2) & uVar7 | uVar26 & uVar2) +
             uVar28 + 0x8f1bbcdc + uVar8 + (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar12 = uVar21 + 0x8f1bbcdc + uVar7 + ((uVar12 | uVar1) & uVar2 | uVar12 & uVar1) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar7 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar17 = uVar19 ^ uVar13 ^ uVar27 ^ uVar22;
    uVar8 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar9 = uVar25 ^ uVar18 ^ uVar3 ^ uVar11;
    uVar26 = uVar27 + 0x8f1bbcdc + uVar2 + (uVar12 >> 0x1b | uVar12 * 0x20) +
             ((uVar26 | uVar6) & uVar1 | uVar26 & uVar6);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar3 + 0x8f1bbcdc + uVar1 + ((uVar12 | uVar7) & uVar6 | uVar12 & uVar7) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar1 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar10 = uVar5 ^ uVar19 ^ uVar20 ^ uVar24;
    uVar16 = uVar23 ^ uVar25 ^ uVar4 ^ uVar17;
    uVar26 = (uVar8 ^ uVar7 ^ uVar26) + uVar20 + 0xca62c1d6 + uVar6 +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar6 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar4 + 0xca62c1d6 + uVar7 + (uVar2 ^ uVar8 ^ uVar12) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar13 = uVar28 ^ uVar5 ^ uVar14 ^ uVar9;
    uVar19 = uVar21 ^ uVar23 ^ uVar22 ^ uVar10;
    uVar26 = (uVar1 ^ uVar2 ^ uVar26) + uVar8 + uVar14 + 0xca62c1d6 +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar15 = uVar2 + uVar22 + 0xca62c1d6 + (uVar6 ^ uVar1 ^ uVar12) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar8 = uVar15 >> 2 | uVar15 * 0x40000000;
    uVar12 = (uVar7 ^ uVar6 ^ uVar26) + uVar11 + 0xca62c1d6 + uVar1 +
             (uVar15 >> 0x1b | uVar15 * 0x20);
    uVar1 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar5 = uVar27 ^ uVar28 ^ uVar11 ^ uVar16;
    uVar18 = uVar3 ^ uVar21 ^ uVar24 ^ uVar13;
    uVar26 = uVar24 + 0xca62c1d6 + uVar6 + (uVar2 ^ uVar7 ^ uVar15) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar15 = uVar20 ^ uVar27 ^ uVar17 ^ uVar19;
    uVar6 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = (uVar8 ^ uVar2 ^ uVar12) + uVar7 + uVar17 + 0xca62c1d6 +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar7 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = uVar2 + uVar9 + 0xca62c1d6 + (uVar1 ^ uVar8 ^ uVar26) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar2 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar10 + 0xca62c1d6 + uVar8 + (uVar6 ^ uVar1 ^ uVar12) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar8 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar3 = uVar4 ^ uVar3 ^ uVar9 ^ uVar5;
    uVar26 = uVar16 + 0xca62c1d6 + uVar1 + (uVar7 ^ uVar6 ^ uVar26) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar17 = uVar14 ^ uVar20 ^ uVar10 ^ uVar18;
    uVar12 = (uVar2 ^ uVar7 ^ uVar12) + uVar13 + 0xca62c1d6 + uVar6 +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar1 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar6 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = uVar19 + 0xca62c1d6 + uVar7 + (uVar26 ^ uVar8 ^ uVar2) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar7 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar5 + 0xca62c1d6 + uVar2 + (uVar1 ^ uVar8 ^ uVar12) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar26 = uVar18 + 0xca62c1d6 + uVar8 + (uVar6 ^ uVar1 ^ uVar26) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar2 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar8 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar12 = uVar15 + 0xca62c1d6 + uVar1 + (uVar12 ^ uVar7 ^ uVar6) +
             (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar1 = uVar12 >> 2 | uVar12 * 0x40000000;
    uVar26 = uVar3 + 0xca62c1d6 + uVar6 + (uVar2 ^ uVar7 ^ uVar26) +
             (uVar12 >> 0x1b | uVar12 * 0x20);
    uVar6 = uVar26 >> 2 | uVar26 * 0x40000000;
    uVar5 = uVar17 + 0xca62c1d6 + uVar7 + (uVar8 ^ uVar2 ^ uVar12) +
            (uVar26 >> 0x1b | uVar26 * 0x20);
    uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar12 = (uVar22 ^ uVar4 ^ uVar16 ^ uVar15) + 0xca62c1d6 + uVar2 + (uVar26 ^ uVar1 ^ uVar8) +
             (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar2 = uVar8 + (uVar11 ^ uVar14 ^ uVar13 ^ uVar3) + 0xca62c1d6 + (uVar6 ^ uVar1 ^ uVar5) +
            (uVar12 >> 0x1b | uVar12 * 0x20);
    local_60 = local_60 + (uVar12 >> 2 | uVar12 * 0x40000000);
    local_4c = local_4c + uVar6;
    local_5c = local_5c +
               (uVar7 ^ uVar6 ^ uVar12) + uVar1 + (uVar24 ^ uVar22 ^ uVar19 ^ uVar17) + 0xca62c1d6 +
               (uVar2 >> 0x1b | uVar2 * 0x20);
    local_50 = local_50 + uVar2;
    param_1[2] = local_60;
    local_58 = local_58 + uVar7;
    local_30 = local_30 + -1;
    *param_1 = local_5c;
    param_1[1] = local_50;
    param_1[3] = local_58;
    param_1[4] = local_4c;
    local_a4 = local_a4 + 0x40;
  } while (local_30 != 0);
  return;
}


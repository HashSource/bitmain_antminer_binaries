
void sha1_block_data_order(uint *param_1,int param_2,int param_3)

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
  int local_a4;
  uint local_90;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_34;
  int local_30;
  
  local_5c = *param_1;
  local_a4 = param_2 + 0x40;
  local_58 = param_1[1];
  local_34 = param_1[4];
  local_54 = param_1[3];
  local_90 = param_1[2];
  local_30 = param_3;
  do {
    uVar20 = local_58 >> 2 | local_58 << 0x1e;
    uVar8 = (uint)*(byte *)(local_a4 + -0x3f) << 0x10 | (uint)*(byte *)(local_a4 + -0x40) << 0x18 |
            (uint)*(byte *)(local_a4 + -0x3d) | (uint)*(byte *)(local_a4 + -0x3e) << 8;
    uVar6 = (uint)*(byte *)(local_a4 + -0x3b) << 0x10 | (uint)*(byte *)(local_a4 + -0x3c) << 0x18 |
            (uint)*(byte *)(local_a4 + -0x39) | (uint)*(byte *)(local_a4 + -0x3a) << 8;
    uVar4 = local_5c >> 2 | local_5c << 0x1e;
    uVar21 = (uint)*(byte *)(local_a4 + -0x37) << 0x10 | (uint)*(byte *)(local_a4 + -0x38) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x35) | (uint)*(byte *)(local_a4 + -0x36) << 8;
    uVar1 = ((local_54 ^ local_90) & local_58 ^ local_54) +
            (local_5c >> 0x1b | local_5c << 5) + 0x5a827999 + uVar8 + local_34;
    uVar24 = uVar1 >> 2 | uVar1 * 0x40000000;
    uVar3 = local_54 + 0x5a827999 + ((local_90 ^ uVar20) & local_5c ^ local_90) + uVar6 +
            (uVar1 >> 0x1b | uVar1 * 0x20);
    uVar7 = uVar3 >> 2 | uVar3 * 0x40000000;
    HintPreloadData(local_a4);
    HintPreloadData(local_a4 + 1);
    uVar5 = local_90 + 0x5a827999 + uVar21 + ((uVar20 ^ uVar4) & uVar1 ^ uVar20) +
            (uVar3 >> 0x1b | uVar3 * 0x20);
    HintPreloadData(local_a4 + 2);
    uVar22 = (uint)*(byte *)(local_a4 + -0x33) << 0x10 | (uint)*(byte *)(local_a4 + -0x34) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x31) | (uint)*(byte *)(local_a4 + -0x32) << 8;
    HintPreloadData(local_a4 + 3);
    uVar3 = uVar20 + 0x5a827999 + uVar22 + ((uVar24 ^ uVar4) & uVar3 ^ uVar4) +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar17 = (uint)*(byte *)(local_a4 + -0x2f) << 0x10 | (uint)*(byte *)(local_a4 + -0x30) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x2d) | (uint)*(byte *)(local_a4 + -0x2e) << 8;
    uVar20 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar9 = (uint)*(byte *)(local_a4 + -0x2b) << 0x10 | (uint)*(byte *)(local_a4 + -0x2c) << 0x18 |
            (uint)*(byte *)(local_a4 + -0x29) | (uint)*(byte *)(local_a4 + -0x2a) << 8;
    uVar1 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar5 = (uVar5 & (uVar7 ^ uVar24) ^ uVar24) + uVar4 + 0x5a827999 + uVar17 +
            (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar11 = (uint)*(byte *)(local_a4 + -0x27) << 0x10 | (uint)*(byte *)(local_a4 + -0x28) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x25) | (uint)*(byte *)(local_a4 + -0x26) << 8;
    uVar4 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar3 = uVar9 + 0x5a827999 + uVar24 + ((uVar7 ^ uVar20) & uVar3 ^ uVar7) +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar24 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar5 = uVar7 + uVar11 + 0x5a827999 + ((uVar20 ^ uVar1) & uVar5 ^ uVar20) +
            (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar12 = (uint)*(byte *)(local_a4 + -0x23) << 0x10 | (uint)*(byte *)(local_a4 + -0x24) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x21) | (uint)*(byte *)(local_a4 + -0x22) << 8;
    uVar18 = (uint)*(byte *)(local_a4 + -0x1f) << 0x10 | (uint)*(byte *)(local_a4 + -0x20) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x1d) | (uint)*(byte *)(local_a4 + -0x1e) << 8;
    uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar3 = uVar12 + 0x5a827999 + uVar20 + (uVar3 & (uVar1 ^ uVar4) ^ uVar1) +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar19 = (uint)*(byte *)(local_a4 + -0x1b) << 0x10 | (uint)*(byte *)(local_a4 + -0x1c) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x19) | (uint)*(byte *)(local_a4 + -0x1a) << 8;
    uVar5 = uVar18 + 0x5a827999 + uVar1 + (uVar5 & (uVar4 ^ uVar24) ^ uVar4) +
            (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar20 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar2 = (uint)*(byte *)(local_a4 + -0x17) << 0x10 | (uint)*(byte *)(local_a4 + -0x18) << 0x18 |
            (uint)*(byte *)(local_a4 + -0x15) | (uint)*(byte *)(local_a4 + -0x16) << 8;
    uVar1 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar23 = uVar4 + uVar19 + 0x5a827999 + ((uVar24 ^ uVar7) & uVar3 ^ uVar24) +
             (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar15 = (uint)*(byte *)(local_a4 + -0x13) << 0x10 | (uint)*(byte *)(local_a4 + -0x14) << 0x18 |
             (uint)*(byte *)(local_a4 + -0x11) | (uint)*(byte *)(local_a4 + -0x12) << 8;
    uVar13 = (uint)*(byte *)(local_a4 + -0xf) << 0x10 | (uint)*(byte *)(local_a4 + -0x10) << 0x18 |
             (uint)*(byte *)(local_a4 + -0xd) | (uint)*(byte *)(local_a4 + -0xe) << 8;
    uVar4 = uVar23 >> 2 | uVar23 * 0x40000000;
    uVar3 = uVar24 + uVar2 + 0x5a827999 + ((uVar7 ^ uVar20) & uVar5 ^ uVar7) +
            (uVar23 >> 0x1b | uVar23 * 0x20);
    uVar16 = (uint)*(byte *)(local_a4 + -0xb) << 0x10 | (uint)*(byte *)(local_a4 + -0xc) << 0x18 |
             (uint)*(byte *)(local_a4 + -9) | (uint)*(byte *)(local_a4 + -10) << 8;
    uVar23 = ((uVar20 ^ uVar1) & uVar23 ^ uVar20) + uVar15 + 0x5a827999 + uVar7 +
             (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar24 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar5 = uVar20 + uVar13 + 0x5a827999 + ((uVar1 ^ uVar4) & uVar3 ^ uVar1) +
            (uVar23 >> 0x1b | uVar23 * 0x20);
    uVar20 = uVar23 >> 2 | uVar23 * 0x40000000;
    uVar7 = uVar5 >> 2 | uVar5 * 0x40000000;
    uVar14 = (uint)*(byte *)(local_a4 + -3) << 0x10 | (uint)*(byte *)(local_a4 + -4) << 0x18 |
             (uint)*(byte *)(local_a4 + -1) | (uint)*(byte *)(local_a4 + -2) << 8;
    uVar3 = uVar1 + uVar16 + 0x5a827999 + ((uVar4 ^ uVar24) & uVar23 ^ uVar4) +
            (uVar5 >> 0x1b | uVar5 * 0x20);
    uVar10 = (uint)*(byte *)(local_a4 + -7) << 0x10 | (uint)*(byte *)(local_a4 + -8) << 0x18 |
             (uint)*(byte *)(local_a4 + -5) | (uint)*(byte *)(local_a4 + -6) << 8;
    uVar1 = uVar3 >> 2 | uVar3 * 0x40000000;
    uVar23 = uVar4 + uVar10 + 0x5a827999 + ((uVar24 ^ uVar20) & uVar5 ^ uVar24) +
             (uVar3 >> 0x1b | uVar3 * 0x20);
    uVar4 = uVar8 ^ uVar21 ^ uVar18 ^ uVar16;
    uVar4 = uVar4 >> 0x1f | uVar4 << 1;
    uVar5 = uVar6 ^ uVar22 ^ uVar19 ^ uVar10;
    uVar8 = uVar24 + uVar14 + 0x5a827999 + ((uVar20 ^ uVar7) & uVar3 ^ uVar20) +
            (uVar23 >> 0x1b | uVar23 * 0x20);
    uVar24 = uVar23 >> 2 | uVar23 * 0x40000000;
    uVar3 = uVar5 >> 0x1f | uVar5 << 1;
    uVar5 = uVar8 >> 2 | uVar8 * 0x40000000;
    uVar6 = uVar21 ^ uVar17 ^ uVar2 ^ uVar14;
    uVar6 = uVar6 >> 0x1f | uVar6 << 1;
    uVar23 = ((uVar7 ^ uVar1) & uVar23 ^ uVar7) + uVar20 + uVar4 + 0x5a827999 +
             (uVar8 >> 0x1b | uVar8 * 0x20);
    uVar20 = uVar22 ^ uVar9 ^ uVar15 ^ uVar4;
    uVar21 = ((uVar1 ^ uVar24) & uVar8 ^ uVar1) + uVar7 + uVar3 + 0x5a827999 +
             (uVar23 >> 0x1b | uVar23 * 0x20);
    uVar20 = uVar20 >> 0x1f | uVar20 << 1;
    uVar7 = uVar23 >> 2 | uVar23 * 0x40000000;
    uVar22 = uVar6 + 0x5a827999 + uVar1 + ((uVar24 ^ uVar5) & uVar23 ^ uVar24) +
             (uVar21 >> 0x1b | uVar21 * 0x20);
    uVar1 = uVar21 >> 2 | uVar21 * 0x40000000;
    uVar23 = uVar17 ^ uVar11 ^ uVar13 ^ uVar3;
    uVar23 = uVar23 >> 0x1f | uVar23 << 1;
    uVar8 = uVar9 ^ uVar12 ^ uVar16 ^ uVar6;
    uVar8 = uVar8 >> 0x1f | uVar8 << 1;
    uVar9 = uVar22 >> 2 | uVar22 * 0x40000000;
    uVar21 = uVar20 + 0x5a827999 + uVar24 + ((uVar5 ^ uVar7) & uVar21 ^ uVar5) +
             (uVar22 >> 0x1b | uVar22 * 0x20);
    uVar24 = uVar11 ^ uVar18 ^ uVar10 ^ uVar20;
    uVar24 = uVar24 >> 0x1f | uVar24 << 1;
    uVar11 = uVar5 + uVar23 + 0x6ed9eba1 + (uVar22 ^ uVar7 ^ uVar1) +
             (uVar21 >> 0x1b | uVar21 * 0x20);
    uVar5 = uVar21 >> 2 | uVar21 * 0x40000000;
    uVar22 = uVar12 ^ uVar19 ^ uVar14 ^ uVar23;
    uVar17 = uVar7 + uVar8 + 0x6ed9eba1 + (uVar1 ^ uVar9 ^ uVar21) +
             (uVar11 >> 0x1b | uVar11 * 0x20);
    uVar7 = uVar22 >> 0x1f | uVar22 << 1;
    uVar21 = uVar11 >> 2 | uVar11 * 0x40000000;
    uVar22 = uVar17 >> 2 | uVar17 * 0x40000000;
    uVar12 = uVar18 ^ uVar2 ^ uVar4 ^ uVar8;
    uVar18 = (uVar9 ^ uVar5 ^ uVar11) + uVar1 + uVar24 + 0x6ed9eba1 +
             (uVar17 >> 0x1b | uVar17 * 0x20);
    uVar1 = uVar12 >> 0x1f | uVar12 << 1;
    uVar11 = uVar19 ^ uVar15 ^ uVar3 ^ uVar24;
    uVar11 = uVar11 >> 0x1f | uVar11 << 1;
    uVar19 = uVar7 + 0x6ed9eba1 + uVar9 + (uVar17 ^ uVar5 ^ uVar21) +
             (uVar18 >> 0x1b | uVar18 * 0x20);
    uVar9 = uVar18 >> 2 | uVar18 * 0x40000000;
    uVar12 = uVar19 >> 2 | uVar19 * 0x40000000;
    uVar2 = uVar2 ^ uVar13 ^ uVar6 ^ uVar7;
    uVar2 = uVar2 >> 0x1f | uVar2 << 1;
    uVar17 = uVar16 ^ uVar15 ^ uVar20 ^ uVar1;
    uVar17 = uVar17 >> 0x1f | uVar17 << 1;
    uVar18 = (uVar18 ^ uVar21 ^ uVar22) + uVar5 + uVar1 + 0x6ed9eba1 +
             (uVar19 >> 0x1b | uVar19 * 0x20);
    uVar15 = (uVar22 ^ uVar9 ^ uVar19) + uVar11 + 0x6ed9eba1 + uVar21 +
             (uVar18 >> 0x1b | uVar18 * 0x20);
    uVar5 = uVar18 >> 2 | uVar18 * 0x40000000;
    uVar21 = uVar13 ^ uVar10 ^ uVar23 ^ uVar11;
    uVar21 = uVar21 >> 0x1f | uVar21 << 1;
    uVar13 = (uVar18 ^ uVar9 ^ uVar12) + uVar22 + uVar2 + 0x6ed9eba1 +
             (uVar15 >> 0x1b | uVar15 * 0x20);
    uVar22 = uVar13 >> 2 | uVar13 * 0x40000000;
    uVar18 = uVar15 >> 2 | uVar15 * 0x40000000;
    uVar19 = uVar14 ^ uVar16 ^ uVar8 ^ uVar2;
    uVar19 = uVar19 >> 0x1f | uVar19 << 1;
    uVar15 = uVar9 + uVar17 + 0x6ed9eba1 + (uVar12 ^ uVar5 ^ uVar15) +
             (uVar13 >> 0x1b | uVar13 * 0x20);
    uVar9 = uVar10 ^ uVar4 ^ uVar24 ^ uVar17;
    uVar9 = uVar9 >> 0x1f | uVar9 << 1;
    uVar10 = (uVar13 ^ uVar5 ^ uVar18) + uVar12 + uVar21 + 0x6ed9eba1 +
             (uVar15 >> 0x1b | uVar15 * 0x20);
    uVar12 = uVar15 >> 2 | uVar15 * 0x40000000;
    uVar16 = (uVar18 ^ uVar22 ^ uVar15) + uVar5 + uVar19 + 0x6ed9eba1 +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar5 = uVar14 ^ uVar3 ^ uVar7 ^ uVar21;
    uVar5 = uVar5 >> 0x1f | uVar5 << 1;
    uVar15 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar13 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar4 = uVar4 ^ uVar6 ^ uVar1 ^ uVar19;
    uVar4 = uVar4 >> 0x1f | uVar4 << 1;
    uVar10 = uVar18 + uVar9 + 0x6ed9eba1 + (uVar22 ^ uVar12 ^ uVar10) +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar3 = uVar3 ^ uVar20 ^ uVar11 ^ uVar9;
    uVar3 = uVar3 >> 0x1f | uVar3 << 1;
    uVar18 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar14 = uVar22 + uVar5 + 0x6ed9eba1 + (uVar12 ^ uVar15 ^ uVar16) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar10 = uVar12 + uVar4 + 0x6ed9eba1 + (uVar15 ^ uVar13 ^ uVar10) +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar6 = uVar6 ^ uVar23 ^ uVar2 ^ uVar5;
    uVar6 = uVar6 >> 0x1f | uVar6 << 1;
    uVar22 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar12 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar20 = uVar20 ^ uVar8 ^ uVar17 ^ uVar4;
    uVar20 = uVar20 >> 0x1f | uVar20 << 1;
    uVar14 = uVar15 + uVar3 + 0x6ed9eba1 + (uVar13 ^ uVar18 ^ uVar14) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar23 = uVar23 ^ uVar24 ^ uVar21 ^ uVar3;
    uVar23 = uVar23 >> 0x1f | uVar23 << 1;
    uVar13 = (uVar10 ^ uVar18 ^ uVar22) + uVar13 + uVar6 + 0x6ed9eba1 +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar15 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar8 = uVar8 ^ uVar7 ^ uVar19 ^ uVar6;
    uVar8 = uVar8 >> 0x1f | uVar8 << 1;
    uVar16 = uVar24 ^ uVar1 ^ uVar9 ^ uVar20;
    uVar10 = (uVar14 ^ uVar22 ^ uVar12) + uVar18 + uVar20 + 0x6ed9eba1 +
             (uVar13 >> 0x1b | uVar13 * 0x20);
    uVar24 = uVar13 >> 2 | uVar13 * 0x40000000;
    uVar18 = uVar16 >> 0x1f | uVar16 << 1;
    uVar14 = uVar22 + uVar23 + 0x6ed9eba1 + (uVar12 ^ uVar15 ^ uVar13) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar22 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar13 = uVar7 ^ uVar11 ^ uVar5 ^ uVar23;
    uVar7 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar13 = uVar13 >> 0x1f | uVar13 << 1;
    uVar10 = (uVar10 ^ uVar15 ^ uVar24) + uVar12 + uVar8 + 0x6ed9eba1 +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar1 = uVar1 ^ uVar2 ^ uVar4 ^ uVar8;
    uVar1 = uVar1 >> 0x1f | uVar1 << 1;
    uVar14 = uVar15 + uVar18 + 0x6ed9eba1 + (uVar24 ^ uVar22 ^ uVar14) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar12 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar11 = uVar11 ^ uVar17 ^ uVar3 ^ uVar18;
    uVar10 = uVar24 + uVar13 + 0x6ed9eba1 + (uVar22 ^ uVar7 ^ uVar10) +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar24 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar11 = uVar11 >> 0x1f | uVar11 << 1;
    uVar15 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar2 = uVar2 ^ uVar21 ^ uVar6 ^ uVar13;
    uVar14 = ((uVar14 | uVar12) & uVar7 | uVar14 & uVar12) +
             uVar22 + uVar1 + 0x8f1bbcdc + (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar22 = uVar2 >> 0x1f | uVar2 << 1;
    uVar10 = uVar7 + uVar11 + 0x8f1bbcdc + ((uVar10 | uVar24) & uVar12 | uVar10 & uVar24) +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar7 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar17 = uVar17 ^ uVar19 ^ uVar20 ^ uVar1;
    uVar2 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar17 = uVar17 >> 0x1f | uVar17 << 1;
    uVar16 = ((uVar14 | uVar15) & uVar24 | uVar14 & uVar15) +
             uVar12 + uVar22 + 0x8f1bbcdc + (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar21 = uVar21 ^ uVar9 ^ uVar23 ^ uVar11;
    uVar21 = uVar21 >> 0x1f | uVar21 << 1;
    uVar12 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar19 = uVar19 ^ uVar5 ^ uVar8 ^ uVar22;
    uVar19 = uVar19 >> 0x1f | uVar19 << 1;
    uVar10 = ((uVar10 | uVar2) & uVar15 | uVar10 & uVar2) + uVar24 + uVar17 + 0x8f1bbcdc +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar24 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar14 = uVar9 ^ uVar4 ^ uVar18 ^ uVar17;
    uVar16 = ((uVar16 | uVar7) & uVar2 | uVar16 & uVar7) +
             uVar15 + uVar21 + 0x8f1bbcdc + (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar9 = uVar3 ^ uVar5 ^ uVar13 ^ uVar21;
    uVar5 = uVar14 >> 0x1f | uVar14 << 1;
    uVar9 = uVar9 >> 0x1f | uVar9 << 1;
    uVar15 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar10 = (uVar10 & uVar12 | (uVar10 | uVar12) & uVar7) + uVar2 + uVar19 + 0x8f1bbcdc +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar2 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar4 = uVar19 ^ uVar4 ^ uVar6 ^ uVar1;
    uVar4 = uVar4 >> 0x1f | uVar4 << 1;
    uVar16 = ((uVar16 | uVar24) & uVar12 | uVar16 & uVar24) +
             uVar7 + uVar5 + 0x8f1bbcdc + (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar14 = uVar12 + uVar9 + 0x8f1bbcdc + (uVar10 & uVar15 | (uVar10 | uVar15) & uVar24) +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar7 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar3 = uVar3 ^ uVar20 ^ uVar11 ^ uVar5;
    uVar3 = uVar3 >> 0x1f | uVar3 << 1;
    uVar12 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar6 = uVar6 ^ uVar23 ^ uVar22 ^ uVar9;
    uVar10 = uVar4 + 0x8f1bbcdc + uVar24 + (uVar14 >> 0x1b | uVar14 * 0x20) +
             ((uVar16 | uVar2) & uVar15 | uVar16 & uVar2);
    uVar14 = uVar3 + 0x8f1bbcdc + uVar15 + ((uVar14 | uVar7) & uVar2 | uVar14 & uVar7) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar24 = uVar6 >> 0x1f | uVar6 << 1;
    uVar20 = uVar20 ^ uVar8 ^ uVar17 ^ uVar4;
    uVar20 = uVar20 >> 0x1f | uVar20 << 1;
    uVar6 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar15 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar10 = uVar24 + 0x8f1bbcdc + uVar2 + (uVar14 >> 0x1b | uVar14 * 0x20) +
             ((uVar10 | uVar12) & uVar7 | uVar10 & uVar12);
    uVar23 = uVar23 ^ uVar18 ^ uVar21 ^ uVar3;
    uVar23 = uVar23 >> 0x1f | uVar23 << 1;
    uVar14 = ((uVar14 | uVar6) & uVar12 | uVar14 & uVar6) + uVar7 + uVar20 + 0x8f1bbcdc +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar7 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar2 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar8 = uVar8 ^ uVar13 ^ uVar19 ^ uVar24;
    uVar8 = uVar8 >> 0x1f | uVar8 << 1;
    uVar16 = uVar12 + uVar23 + 0x8f1bbcdc + (uVar14 >> 0x1b | uVar14 * 0x20) +
             ((uVar10 | uVar15) & uVar6 | uVar10 & uVar15);
    uVar12 = uVar18 ^ uVar1 ^ uVar5 ^ uVar20;
    uVar12 = uVar12 >> 0x1f | uVar12 << 1;
    uVar10 = uVar6 + uVar8 + 0x8f1bbcdc + ((uVar14 | uVar7) & uVar15 | uVar14 & uVar7) +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar6 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar13 = uVar13 ^ uVar11 ^ uVar9 ^ uVar23;
    uVar18 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar13 = uVar13 >> 0x1f | uVar13 << 1;
    uVar1 = uVar1 ^ uVar22 ^ uVar4 ^ uVar8;
    uVar14 = uVar15 + uVar12 + 0x8f1bbcdc + (uVar10 >> 0x1b | uVar10 * 0x20) +
             ((uVar16 | uVar2) & uVar7 | uVar16 & uVar2);
    uVar1 = uVar1 >> 0x1f | uVar1 << 1;
    uVar15 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar10 = ((uVar10 | uVar6) & uVar2 | uVar10 & uVar6) + uVar7 + uVar13 + 0x8f1bbcdc +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar7 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar11 = uVar11 ^ uVar17 ^ uVar3 ^ uVar12;
    uVar11 = uVar11 >> 0x1f | uVar11 << 1;
    uVar22 = uVar22 ^ uVar21 ^ uVar24 ^ uVar13;
    uVar22 = uVar22 >> 0x1f | uVar22 << 1;
    uVar14 = uVar2 + uVar1 + 0x8f1bbcdc + (uVar10 >> 0x1b | uVar10 * 0x20) +
             ((uVar14 | uVar18) & uVar6 | uVar14 & uVar18);
    uVar2 = uVar17 ^ uVar19 ^ uVar20 ^ uVar1;
    uVar2 = uVar2 >> 0x1f | uVar2 << 1;
    uVar10 = uVar11 + 0x8f1bbcdc + uVar6 + (uVar10 & uVar15 | (uVar10 | uVar15) & uVar18) +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar6 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar17 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar21 = uVar21 ^ uVar5 ^ uVar23 ^ uVar11;
    uVar21 = uVar21 >> 0x1f | uVar21 << 1;
    uVar14 = ((uVar14 | uVar7) & uVar15 | uVar14 & uVar7) +
             uVar18 + uVar22 + 0x8f1bbcdc + (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar18 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar19 = uVar8 ^ uVar19 ^ uVar9 ^ uVar22;
    uVar19 = uVar19 >> 0x1f | uVar19 << 1;
    uVar10 = uVar15 + uVar2 + 0x8f1bbcdc + ((uVar10 | uVar6) & uVar7 | uVar10 & uVar6) +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar5 = uVar5 ^ uVar4 ^ uVar12 ^ uVar2;
    uVar5 = uVar5 >> 0x1f | uVar5 << 1;
    uVar14 = uVar21 + 0xca62c1d6 + uVar7 + (uVar14 ^ uVar6 ^ uVar17) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar7 = uVar3 ^ uVar9 ^ uVar13 ^ uVar21;
    uVar7 = uVar7 >> 0x1f | uVar7 << 1;
    uVar9 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar15 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar10 = (uVar17 ^ uVar18 ^ uVar10) + uVar6 + uVar19 + 0xca62c1d6 +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar6 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar4 = uVar4 ^ uVar24 ^ uVar1 ^ uVar19;
    uVar4 = uVar4 >> 0x1f | uVar4 << 1;
    uVar17 = uVar17 + uVar5 + 0xca62c1d6 + (uVar14 ^ uVar18 ^ uVar9) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar3 = uVar3 ^ uVar20 ^ uVar11 ^ uVar5;
    uVar3 = uVar3 >> 0x1f | uVar3 << 1;
    uVar18 = uVar18 + uVar7 + 0xca62c1d6 + (uVar10 ^ uVar9 ^ uVar15) +
             (uVar17 >> 0x1b | uVar17 * 0x20);
    uVar10 = uVar9 + uVar4 + 0xca62c1d6 + (uVar15 ^ uVar6 ^ uVar17) +
             (uVar18 >> 0x1b | uVar18 * 0x20);
    uVar9 = uVar17 >> 2 | uVar17 * 0x40000000;
    uVar20 = uVar20 ^ uVar8 ^ uVar2 ^ uVar4;
    uVar20 = uVar20 >> 0x1f | uVar20 << 1;
    uVar14 = uVar24 ^ uVar23 ^ uVar22 ^ uVar7;
    uVar24 = uVar18 >> 2 | uVar18 * 0x40000000;
    uVar16 = uVar15 + uVar3 + 0xca62c1d6 + (uVar6 ^ uVar9 ^ uVar18) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar17 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar18 = uVar14 >> 0x1f | uVar14 << 1;
    uVar23 = uVar23 ^ uVar12 ^ uVar21 ^ uVar3;
    uVar23 = uVar23 >> 0x1f | uVar23 << 1;
    uVar15 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar10 = (uVar9 ^ uVar24 ^ uVar10) + uVar6 + uVar18 + 0xca62c1d6 +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar6 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar8 = uVar8 ^ uVar13 ^ uVar19 ^ uVar18;
    uVar14 = uVar20 + 0xca62c1d6 + uVar9 + (uVar24 ^ uVar17 ^ uVar16) +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar8 = uVar8 >> 0x1f | uVar8 << 1;
    uVar9 = uVar14 >> 2 | uVar14 * 0x40000000;
    uVar12 = uVar12 ^ uVar1 ^ uVar5 ^ uVar20;
    uVar12 = uVar12 >> 0x1f | uVar12 << 1;
    uVar16 = (uVar10 ^ uVar17 ^ uVar15) + uVar24 + uVar23 + 0xca62c1d6 +
             (uVar14 >> 0x1b | uVar14 * 0x20);
    uVar24 = uVar16 >> 2 | uVar16 * 0x40000000;
    uVar10 = uVar17 + uVar8 + 0xca62c1d6 + (uVar14 ^ uVar15 ^ uVar6) +
             (uVar16 >> 0x1b | uVar16 * 0x20);
    uVar17 = uVar13 ^ uVar11 ^ uVar7 ^ uVar23;
    uVar17 = uVar17 >> 0x1f | uVar17 << 1;
    uVar13 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar15 = (uVar6 ^ uVar9 ^ uVar16) + uVar15 + uVar12 + 0xca62c1d6 +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar1 = uVar1 ^ uVar22 ^ uVar4 ^ uVar8;
    uVar1 = uVar1 >> 0x1f | uVar1 << 1;
    uVar11 = uVar11 ^ uVar2 ^ uVar3 ^ uVar12;
    uVar11 = uVar11 >> 0x1f | uVar11 << 1;
    uVar10 = (uVar10 ^ uVar9 ^ uVar24) + uVar17 + 0xca62c1d6 + uVar6 +
             (uVar15 >> 0x1b | uVar15 * 0x20);
    uVar6 = uVar15 >> 2 | uVar15 * 0x40000000;
    uVar22 = uVar22 ^ uVar21 ^ uVar18 ^ uVar17;
    uVar22 = uVar22 >> 0x1f | uVar22 << 1;
    uVar15 = (uVar24 ^ uVar13 ^ uVar15) + uVar1 + 0xca62c1d6 + uVar9 +
             (uVar10 >> 0x1b | uVar10 * 0x20);
    uVar9 = uVar10 >> 2 | uVar10 * 0x40000000;
    uVar18 = uVar15 >> 2 | uVar15 * 0x40000000;
    uVar1 = uVar2 ^ uVar19 ^ uVar20 ^ uVar1;
    uVar2 = uVar24 + uVar11 + 0xca62c1d6 + (uVar13 ^ uVar6 ^ uVar10) +
            (uVar15 >> 0x1b | uVar15 * 0x20);
    uVar20 = uVar1 >> 0x1f | uVar1 << 1;
    uVar11 = uVar11 ^ uVar21 ^ uVar5 ^ uVar23;
    uVar24 = uVar2 >> 2 | uVar2 * 0x40000000;
    uVar1 = uVar11 >> 0x1f | uVar11 << 1;
    uVar23 = uVar13 + uVar22 + 0xca62c1d6 + (uVar6 ^ uVar9 ^ uVar15) +
             (uVar2 >> 0x1b | uVar2 * 0x20);
    uVar21 = uVar6 + uVar20 + 0xca62c1d6 + (uVar9 ^ uVar18 ^ uVar2) +
             (uVar23 >> 0x1b | uVar23 * 0x20);
    uVar22 = uVar22 ^ uVar19 ^ uVar7 ^ uVar8;
    uVar6 = uVar23 >> 2 | uVar23 * 0x40000000;
    uVar20 = uVar5 ^ uVar4 ^ uVar12 ^ uVar20;
    uVar4 = uVar21 >> 2 | uVar21 * 0x40000000;
    uVar23 = uVar9 + uVar1 + 0xca62c1d6 + (uVar18 ^ uVar24 ^ uVar23) +
             (uVar21 >> 0x1b | uVar21 * 0x20);
    uVar8 = (uVar22 >> 0x1f | uVar22 << 1) + 0xca62c1d6 + uVar18 + (uVar24 ^ uVar6 ^ uVar21) +
            (uVar23 >> 0x1b | uVar23 * 0x20);
    uVar5 = uVar23 >> 2 | uVar23 * 0x40000000;
    uVar1 = uVar7 ^ uVar3 ^ uVar17 ^ uVar1;
    uVar20 = (uVar20 >> 0x1f | uVar20 << 1) + 0xca62c1d6 + uVar24 + (uVar6 ^ uVar4 ^ uVar23) +
             (uVar8 >> 0x1b | uVar8 * 0x20);
    local_90 = local_90 + (uVar8 >> 2 | uVar8 * 0x40000000);
    local_34 = uVar4 + local_34;
    local_54 = local_54 + uVar5;
    param_1[2] = local_90;
    local_58 = uVar20 + local_58;
    local_5c = (uVar1 >> 0x1f | uVar1 << 1) + 0xca62c1d6 + uVar6 + (uVar4 ^ uVar5 ^ uVar8) +
               (uVar20 >> 0x1b | uVar20 * 0x20) + local_5c;
    local_a4 = local_a4 + 0x40;
    param_1[4] = local_34;
    *param_1 = local_5c;
    param_1[1] = local_58;
    param_1[3] = local_54;
    local_30 = local_30 + -1;
  } while (local_30 != 0);
  return;
}


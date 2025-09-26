
void md4_block_data_order(int *param_1,byte *param_2,int param_3)

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
  int local_34;
  
  local_34 = param_3 + -1;
  iVar1 = *param_1;
  uVar6 = param_1[1];
  uVar9 = param_1[2];
  uVar16 = param_1[3];
  if (param_3 != 0) {
    do {
      local_34 = local_34 + -1;
      uVar22 = (uint)param_2[2] << 0x10 | (uint)param_2[1] << 8 | (uint)*param_2 |
               (uint)param_2[3] << 0x18;
      uVar2 = (uint)param_2[6] << 0x10 | (uint)param_2[5] << 8 | (uint)param_2[4] |
              (uint)param_2[7] << 0x18;
      uVar10 = uVar22 + ((uVar16 ^ uVar9) & uVar6 ^ uVar16) + iVar1;
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar3 = (uint)param_2[10] << 0x10 | (uint)param_2[9] << 8 | (uint)param_2[8] |
              (uint)param_2[0xb] << 0x18;
      uVar17 = uVar2 + uVar16 + (uVar10 & (uVar9 ^ uVar6) ^ uVar9);
      uVar17 = uVar17 >> 0x19 | uVar17 * 0x80;
      uVar4 = (uint)param_2[0xe] << 0x10 | (uint)param_2[0xd] << 8 | (uint)param_2[0xc] |
              (uint)param_2[0xf] << 0x18;
      uVar7 = uVar9 + uVar3 + ((uVar10 ^ uVar6) & uVar17 ^ uVar6);
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar21 = (uVar7 & (uVar17 ^ uVar10) ^ uVar10) + uVar6 + uVar4;
      uVar5 = (uint)param_2[0x10] | (uint)param_2[0x12] << 0x10 | (uint)param_2[0x11] << 8 |
              (uint)param_2[0x13] << 0x18;
      uVar21 = uVar21 >> 0xd | uVar21 * 0x80000;
      uVar10 = uVar10 + uVar5 + (uVar21 & (uVar7 ^ uVar17) ^ uVar17);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar19 = (uint)param_2[0x16] << 0x10 | (uint)param_2[0x15] << 8 | (uint)param_2[0x14] |
               (uint)param_2[0x17] << 0x18;
      uVar11 = (uint)param_2[0x1a] << 0x10 | (uint)param_2[0x19] << 8 | (uint)param_2[0x18] |
               (uint)param_2[0x1b] << 0x18;
      uVar17 = uVar17 + uVar19 + (uVar10 & (uVar21 ^ uVar7) ^ uVar7);
      uVar17 = uVar17 >> 0x19 | uVar17 * 0x80;
      uVar12 = (uint)param_2[0x1c] | (uint)param_2[0x1e] << 0x10 | (uint)param_2[0x1d] << 8 |
               (uint)param_2[0x1f] << 0x18;
      uVar7 = uVar7 + uVar11 + (uVar17 & (uVar10 ^ uVar21) ^ uVar21);
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar21 = uVar21 + uVar12 + (uVar7 & (uVar17 ^ uVar10) ^ uVar10);
      uVar18 = (uint)param_2[0x22] << 0x10 | (uint)param_2[0x21] << 8 | (uint)param_2[0x20] |
               (uint)param_2[0x23] << 0x18;
      uVar21 = uVar21 >> 0xd | uVar21 * 0x80000;
      uVar13 = (uint)param_2[0x26] << 0x10 | (uint)param_2[0x25] << 8 | (uint)param_2[0x24] |
               (uint)param_2[0x27] << 0x18;
      uVar10 = uVar10 + uVar18 + (uVar21 & (uVar7 ^ uVar17) ^ uVar17);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar14 = (uint)param_2[0x2a] << 0x10 | (uint)param_2[0x29] << 8 | (uint)param_2[0x28] |
               (uint)param_2[0x2b] << 0x18;
      uVar17 = uVar17 + uVar13 + ((uVar21 ^ uVar7) & uVar10 ^ uVar7);
      uVar17 = uVar17 >> 0x19 | uVar17 * 0x80;
      uVar23 = (uint)param_2[0x2e] << 0x10 | (uint)param_2[0x2d] << 8 | (uint)param_2[0x2c] |
               (uint)param_2[0x2f] << 0x18;
      uVar7 = uVar7 + uVar14 + (uVar17 & (uVar10 ^ uVar21) ^ uVar21);
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar21 = uVar21 + uVar23 + (uVar7 & (uVar17 ^ uVar10) ^ uVar10);
      uVar15 = (uint)param_2[0x32] << 0x10 | (uint)param_2[0x31] << 8 | (uint)param_2[0x30] |
               (uint)param_2[0x33] << 0x18;
      uVar21 = uVar21 >> 0xd | uVar21 * 0x80000;
      uVar24 = (uint)param_2[0x36] << 0x10 | (uint)param_2[0x35] << 8 | (uint)param_2[0x34] |
               (uint)param_2[0x37] << 0x18;
      uVar10 = uVar10 + uVar15 + (uVar21 & (uVar7 ^ uVar17) ^ uVar17);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar17 + uVar24 + ((uVar21 ^ uVar7) & uVar10 ^ uVar7);
      uVar17 = uVar17 >> 0x19 | uVar17 * 0x80;
      uVar20 = (uint)param_2[0x3a] << 0x10 | (uint)param_2[0x39] << 8 | (uint)param_2[0x38] |
               (uint)param_2[0x3b] << 0x18;
      uVar7 = uVar7 + uVar20 + (uVar17 & (uVar10 ^ uVar21) ^ uVar21);
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar8 = (uint)param_2[0x3e] << 0x10 | (uint)param_2[0x3d] << 8 | (uint)param_2[0x3c] |
              (uint)param_2[0x3f] << 0x18;
      uVar21 = uVar21 + uVar8 + (uVar7 & (uVar17 ^ uVar10) ^ uVar10);
      uVar21 = uVar21 >> 0xd | uVar21 * 0x80000;
      uVar10 = uVar10 + uVar22 + 0x5a827999 + (uVar21 & (uVar7 | uVar17) | uVar7 & uVar17);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = (uVar10 & (uVar21 | uVar7) | uVar21 & uVar7) + uVar5 + 0x5a827999 + uVar17;
      uVar17 = uVar17 >> 0x1b | uVar17 * 0x20;
      uVar7 = uVar7 + uVar18 + 0x5a827999 + (uVar17 & (uVar10 | uVar21) | uVar10 & uVar21);
      uVar7 = uVar7 >> 0x17 | uVar7 * 0x200;
      uVar21 = uVar21 + uVar15 + 0x5a827999 + (uVar7 & (uVar17 | uVar10) | uVar17 & uVar10);
      uVar21 = uVar21 >> 0x13 | uVar21 * 0x2000;
      uVar10 = uVar10 + uVar2 + 0x5a827999 + (uVar21 & (uVar7 | uVar17) | uVar7 & uVar17);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar17 + uVar19 + 0x5a827999 + (uVar10 & (uVar21 | uVar7) | uVar21 & uVar7);
      uVar17 = uVar17 >> 0x1b | uVar17 * 0x20;
      param_2 = param_2 + 0x40;
      uVar7 = uVar7 + uVar13 + 0x5a827999 + (uVar17 & (uVar10 | uVar21) | uVar10 & uVar21);
      uVar7 = uVar7 >> 0x17 | uVar7 * 0x200;
      uVar21 = uVar24 + 0x5a827999 + uVar21 + (uVar7 & (uVar17 | uVar10) | uVar17 & uVar10);
      uVar21 = uVar21 >> 0x13 | uVar21 * 0x2000;
      uVar10 = uVar3 + 0x5a827999 + uVar10 + (uVar21 & (uVar7 | uVar17) | uVar7 & uVar17);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar17 + uVar11 + 0x5a827999 + (uVar21 & uVar7 | uVar10 & (uVar21 | uVar7));
      uVar17 = uVar17 >> 0x1b | uVar17 * 0x20;
      uVar7 = uVar7 + uVar14 + 0x5a827999 + (uVar17 & (uVar10 | uVar21) | uVar10 & uVar21);
      uVar7 = uVar7 >> 0x17 | uVar7 * 0x200;
      uVar21 = uVar21 + uVar20 + 0x5a827999 + (uVar7 & (uVar17 | uVar10) | uVar17 & uVar10);
      uVar21 = uVar21 >> 0x13 | uVar21 * 0x2000;
      uVar10 = uVar10 + uVar4 + 0x5a827999 + (uVar21 & (uVar7 | uVar17) | uVar7 & uVar17);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar17 + uVar12 + 0x5a827999 + (uVar10 & (uVar21 | uVar7) | uVar21 & uVar7);
      uVar17 = uVar17 >> 0x1b | uVar17 * 0x20;
      uVar7 = uVar7 + uVar23 + 0x5a827999 + (uVar17 & (uVar10 | uVar21) | uVar10 & uVar21);
      uVar7 = uVar7 >> 0x17 | uVar7 * 0x200;
      uVar21 = uVar21 + uVar8 + 0x5a827999 + (uVar7 & (uVar17 | uVar10) | uVar17 & uVar10);
      uVar21 = uVar21 >> 0x13 | uVar21 * 0x2000;
      uVar10 = uVar10 + uVar22 + 0x6ed9eba1 + (uVar7 ^ uVar17 ^ uVar21);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar17 + uVar18 + 0x6ed9eba1 + (uVar21 ^ uVar7 ^ uVar10);
      uVar17 = uVar17 >> 0x17 | uVar17 * 0x200;
      uVar7 = uVar5 + 0x6ed9eba1 + uVar7 + (uVar10 ^ uVar21 ^ uVar17);
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar21 = uVar15 + 0x6ed9eba1 + uVar21 + (uVar17 ^ uVar10 ^ uVar7);
      uVar21 = uVar21 >> 0x11 | uVar21 * 0x8000;
      uVar10 = uVar10 + uVar3 + 0x6ed9eba1 + (uVar7 ^ uVar17 ^ uVar21);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar14 + 0x6ed9eba1 + uVar17 + (uVar21 ^ uVar7 ^ uVar10);
      uVar17 = uVar17 >> 0x17 | uVar17 * 0x200;
      uVar7 = (uVar10 ^ uVar21 ^ uVar17) + uVar7 + uVar11 + 0x6ed9eba1;
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar21 = uVar20 + 0x6ed9eba1 + uVar21 + (uVar17 ^ uVar10 ^ uVar7);
      uVar21 = uVar21 >> 0x11 | uVar21 * 0x8000;
      uVar10 = uVar10 + uVar2 + 0x6ed9eba1 + (uVar7 ^ uVar17 ^ uVar21);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar13 + 0x6ed9eba1 + uVar17 + (uVar21 ^ uVar7 ^ uVar10);
      uVar17 = uVar17 >> 0x17 | uVar17 * 0x200;
      uVar7 = uVar7 + uVar19 + 0x6ed9eba1 + (uVar10 ^ uVar21 ^ uVar17);
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar21 = uVar24 + 0x6ed9eba1 + uVar21 + (uVar17 ^ uVar10 ^ uVar7);
      uVar21 = uVar21 >> 0x11 | uVar21 * 0x8000;
      uVar10 = uVar4 + 0x6ed9eba1 + uVar10 + (uVar7 ^ uVar17 ^ uVar21);
      uVar10 = uVar10 >> 0x1d | uVar10 * 8;
      uVar17 = uVar23 + 0x6ed9eba1 + uVar17 + (uVar21 ^ uVar7 ^ uVar10);
      uVar17 = uVar17 >> 0x17 | uVar17 * 0x200;
      uVar7 = uVar7 + uVar12 + 0x6ed9eba1 + (uVar10 ^ uVar21 ^ uVar17);
      uVar7 = uVar7 >> 0x15 | uVar7 * 0x800;
      uVar21 = uVar8 + 0x6ed9eba1 + uVar21 + (uVar17 ^ uVar10 ^ uVar7);
      uVar16 = uVar16 + uVar17;
      uVar6 = uVar6 + (uVar21 >> 0x11 | uVar21 * 0x8000);
      iVar1 = iVar1 + uVar10;
      uVar9 = uVar9 + uVar7;
      *param_1 = iVar1;
      param_1[1] = uVar6;
      param_1[2] = uVar9;
      param_1[3] = uVar16;
    } while (local_34 != -1);
  }
  return;
}


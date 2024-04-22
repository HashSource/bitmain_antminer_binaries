
void CAST_set_key(CAST_KEY *key,int len,uchar *data)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  byte *unaff_r4;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int unaff_r7;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  uint local_120;
  uint local_11c;
  uint *local_118;
  int local_110;
  uint local_10c;
  int local_108;
  uint local_fc;
  uint local_f0;
  uint local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  uint local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  uint local_c4;
  int local_c0;
  uint local_bc;
  int local_b8;
  uint local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  iVar1 = DAT_0011fafc;
  if (0xf < len) {
    len = 0x10;
  }
  pbVar6 = data;
  if (0 < len) {
    pbVar6 = data + -1;
    unaff_r4 = data + len + -1;
  }
  local_e0 = 0;
  local_dc = 0;
  local_d8 = 0;
  local_d4 = 0;
  local_d0 = 0;
  local_cc = 0;
  local_c8 = 0;
  local_c4 = 0;
  local_c0 = 0;
  local_bc = 0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0;
  local_a8 = 0;
  local_a4 = 0;
  puVar10 = &local_e4;
  iVar13 = 0;
  if (0 < len) {
    do {
      pbVar6 = pbVar6 + 1;
      puVar10 = puVar10 + 1;
      *puVar10 = (uint)*pbVar6;
      iVar13 = local_dc;
    } while (pbVar6 != unaff_r4);
  }
  if (10 < len) {
    unaff_r7 = 0;
  }
  if (len < 0xb) {
    unaff_r7 = 1;
  }
  local_11c = local_bc;
  iVar2 = local_ac << 2;
  local_fc = iVar13 << 0x10 | local_e0 << 0x18 | local_d4 | local_d8 << 8;
  iVar13 = local_b0 << 2;
  iVar19 = DAT_0011fafc + local_c0 * 4;
  key->short_key = unaff_r7;
  local_f0 = local_cc << 0x10 | local_d0 << 0x18 | local_c4 | local_c8 << 8;
  uVar28 = local_ac << 0x10 | local_b0 << 0x18 | local_a4 | local_a8 << 8;
  local_108 = local_a8 << 2;
  local_120 = *(uint *)(iVar19 + 0x400);
  uVar26 = local_bc << 0x10 | local_c0 << 0x18 | local_b4 | local_b8 << 8;
  local_110 = local_b8 << 2;
  uVar24 = *(uint *)(iVar1 + local_a4 * 4);
  local_10c = *(uint *)(iVar1 + local_b4 * 4);
  local_118 = &local_a0;
  while( true ) {
    local_120 = uVar24 ^ *(uint *)(iVar1 + local_108 + 0xc00) ^
                         *(uint *)(iVar1 + iVar13 + 0x400) ^ *(uint *)(iVar1 + iVar2 + 0x800) ^
                         local_fc ^ local_120;
    iVar13 = iVar1 + (local_120 & 0xff) * 4;
    iVar11 = iVar1 + (local_120 >> 0x18) * 4;
    iVar2 = iVar1 + ((local_120 << 8) >> 0x18) * 4;
    uVar24 = (local_120 << 0x10) >> 0x18;
    iVar19 = iVar1 + uVar24 * 4;
    uVar25 = *(uint *)(iVar13 + 0x400);
    uVar14 = *(uint *)(iVar2 + 0x400);
    uVar7 = *(uint *)(iVar19 + 0xc00);
    uVar26 = *(uint *)(iVar11 + 0x800) ^ *(uint *)(iVar13 + 0xc00) ^
             *(uint *)(iVar1 + local_110 + 0xc00) ^ *(uint *)(iVar1 + uVar24 * 4) ^ uVar14 ^ uVar26;
    uVar17 = *(uint *)(iVar11 + 0xc00);
    iVar12 = iVar1 + (uVar26 >> 0x18) * 4;
    iVar15 = iVar1 + ((uVar26 << 8) >> 0x18) * 4;
    iVar8 = iVar1 + (uVar26 & 0xff) * 4;
    uVar4 = *(uint *)(iVar12 + 0xc00);
    uVar24 = (uVar26 << 0x10) >> 0x18;
    uVar18 = *(uint *)(iVar1 + uVar24 * 4);
    uVar9 = *(uint *)(iVar15 + 0x400);
    uVar20 = *(uint *)(iVar1 + uVar24 * 4 + 0xc00);
    uVar28 = *(uint *)(iVar8 + 0x800) ^ uVar4 ^ *(uint *)(iVar1 + local_11c * 4 + 0x800) ^ uVar18 ^
             uVar9 ^ uVar28;
    iVar30 = iVar1 + (uVar28 >> 0x18) * 4;
    uVar21 = *(uint *)(iVar1 + (uVar28 & 0xff) * 4);
    uVar5 = *(uint *)(iVar1 + ((uVar28 << 0x10) >> 0x18) * 4 + 0x800);
    uVar24 = (uVar28 << 8) >> 0x18;
    uVar16 = *(uint *)(iVar1 + uVar24 * 4);
    uVar24 = *(uint *)(iVar1 + uVar24 * 4 + 0x400);
    local_10c = *(uint *)(iVar1 + (uVar28 & 0xff) * 4 + 0x400) ^ *(uint *)(iVar30 + 0xc00) ^ uVar5 ^
                uVar16 ^ local_f0 ^ local_10c;
    uVar31 = *(uint *)(iVar1 + ((local_10c << 0x10) >> 0x18) * 4 + 0x800);
    uVar22 = *(uint *)(iVar1 + (local_10c & 0xff) * 4);
    iVar13 = iVar1 + (local_10c >> 0x18) * 4;
    uVar23 = *(uint *)(iVar13 + 0x800);
    uVar29 = *(uint *)(iVar13 + 0xc00);
    uVar3 = *(uint *)(iVar1 + ((local_10c << 8) >> 0x18) * 4);
    *local_118 = *(uint *)(iVar8 + 0x400) ^ *(uint *)(iVar19 + 0x800) ^ uVar20 ^
                 *(uint *)(iVar30 + 0x800) ^ uVar16;
    local_118[1] = uVar5 ^ uVar21 ^ uVar18 ^ uVar9 ^ uVar4;
    local_118[2] = uVar23 ^ uVar25 ^ uVar7 ^ uVar24 ^ uVar3;
    local_118[3] = uVar14 ^ uVar17 ^ uVar22 ^ uVar29 ^ uVar31;
    uVar28 = *(uint *)(iVar15 + 0x800) ^
             *(uint *)(iVar11 + 0x400) ^
             *(uint *)(iVar12 + 0x400) ^ *(uint *)(iVar1 + (uVar26 & 0xff) * 4) ^ uVar20 ^ uVar28;
    uVar9 = *(uint *)(iVar1 + ((uVar28 << 0x10) >> 0x18) * 4);
    iVar19 = iVar1 + (uVar28 & 0xff) * 4;
    iVar13 = iVar1 + ((uVar28 << 8) >> 0x18) * 4;
    uVar14 = *(uint *)(iVar19 + 0x400);
    uVar17 = *(uint *)(iVar1 + (uVar28 >> 0x18) * 4);
    uVar21 = *(uint *)(iVar13 + 0x800);
    uVar27 = *(uint *)(iVar19 + 0xc00) ^
             uVar7 ^ local_120 ^ *(uint *)(iVar1 + (uVar28 >> 0x18) * 4 + 0x800) ^ uVar9 ^
             *(uint *)(iVar13 + 0x400);
    iVar13 = iVar1 + (uVar27 & 0xff) * 4;
    uVar24 = *(uint *)(iVar1 + ((uVar27 << 0x10) >> 0x18) * 4);
    uVar7 = *(uint *)(iVar1 + (uVar27 >> 0x18) * 4);
    uVar5 = *(uint *)(iVar13 + 0x800);
    iVar8 = iVar1 + ((uVar27 << 8) >> 0x18) * 4;
    uVar32 = *(uint *)(iVar13 + 0xc00);
    uVar4 = *(uint *)(iVar8 + 0x800);
    uVar3 = uVar26 ^ *(uint *)(iVar2 + 0x800) ^ uVar5 ^
            *(uint *)(iVar1 + (uVar27 >> 0x18) * 4 + 0xc00) ^ uVar24 ^ *(uint *)(iVar8 + 0x400);
    uVar26 = (uVar3 << 8) >> 0x18;
    iVar13 = iVar1 + (uVar3 & 0xff) * 4;
    iVar8 = iVar1 + ((uVar3 << 0x10) >> 0x18) * 4;
    iVar11 = iVar1 + (uVar3 >> 0x18) * 4;
    uVar29 = *(uint *)(iVar13 + 0xc00);
    iVar2 = iVar1 + uVar26 * 4;
    uVar16 = *(uint *)(iVar11 + 0x400);
    uVar26 = *(uint *)(iVar11 + 0xc00) ^
             *(uint *)(iVar13 + 0x400) ^ *(uint *)(iVar1 + (local_120 & 0xff) * 4) ^ local_10c ^
             *(uint *)(iVar8 + 0x800) ^ *(uint *)(iVar1 + uVar26 * 4);
    uVar18 = *(uint *)(iVar1 + (uVar26 & 0xff) * 4 + 0xc00);
    uVar23 = (uVar26 << 8) >> 0x18;
    iVar13 = iVar1 + ((uVar26 << 0x10) >> 0x18) * 4;
    uVar20 = *(uint *)(iVar1 + (uVar26 >> 0x18) * 4 + 0x400);
    uVar22 = *(uint *)(iVar1 + uVar23 * 4);
    iVar12 = iVar1 + uVar23 * 4;
    uVar23 = *(uint *)(iVar13 + 0x400);
    uVar25 = *(uint *)(iVar8 + 0x400);
    uVar31 = *(uint *)(iVar2 + 0xc00);
    local_118[4] = uVar9 ^ *(uint *)(iVar19 + 0x800) ^ *(uint *)(iVar11 + 0x800) ^ uVar20 ^
                   *(uint *)(iVar12 + 0xc00);
    local_118[6] = uVar5 ^ uVar14 ^ uVar24 ^ uVar16 ^ uVar31;
    local_118[5] = uVar22 ^ uVar17 ^ uVar21 ^ uVar18 ^ uVar23;
    local_118[7] = uVar4 ^ uVar32 ^ uVar7 ^ uVar29 ^ uVar25;
    uVar29 = *(uint *)(iVar12 + 0x800) ^
             uVar16 ^ uVar28 ^ uVar20 ^ *(uint *)(iVar1 + (uVar26 & 0xff) * 4) ^
             *(uint *)(iVar13 + 0xc00);
    iVar19 = iVar1 + (uVar29 >> 0x18) * 4;
    iVar11 = iVar1 + (uVar29 & 0xff) * 4;
    iVar13 = iVar1 + ((uVar29 << 8) >> 0x18) * 4;
    uVar24 = (uVar29 << 0x10) >> 0x18;
    uVar28 = *(uint *)(iVar1 + uVar24 * 4);
    iVar12 = iVar1 + uVar24 * 4;
    uVar14 = *(uint *)(iVar13 + 0x800);
    uVar31 = *(uint *)(iVar11 + 0x800);
    uVar4 = *(uint *)(iVar19 + 0x800) ^ uVar3 ^ *(uint *)(iVar8 + 0xc00) ^ *(uint *)(iVar11 + 0xc00)
            ^ uVar28 ^ *(uint *)(iVar13 + 0x400);
    iVar8 = iVar1 + (uVar4 >> 0x18) * 4;
    uVar5 = *(uint *)(iVar1 + (uVar4 >> 0x18) * 4);
    iVar13 = iVar1 + ((uVar4 << 8) >> 0x18) * 4;
    uVar17 = *(uint *)(iVar1 + (uVar4 & 0xff) * 4 + 0x800);
    uVar24 = (uVar4 << 0x10) >> 0x18;
    uVar16 = *(uint *)(iVar1 + uVar24 * 4);
    uVar20 = *(uint *)(iVar13 + 0x800);
    uVar7 = *(uint *)(iVar1 + uVar24 * 4 + 0xc00);
    local_fc = uVar26 ^ *(uint *)(iVar2 + 0x800) ^ uVar17 ^ *(uint *)(iVar8 + 0xc00) ^ uVar16 ^
               *(uint *)(iVar13 + 0x400);
    iVar13 = iVar1 + (local_fc & 0xff) * 4;
    iVar15 = iVar1 + (local_fc >> 0x18) * 4;
    uVar24 = *(uint *)(iVar13 + 0xc00);
    uVar21 = *(uint *)(iVar12 + 0x400);
    iVar11 = iVar1 + ((local_fc << 0x10) >> 0x18) * 4;
    uVar26 = (local_fc << 8) >> 0x18;
    iVar2 = iVar1 + uVar26 * 4;
    uVar22 = *(uint *)(iVar11 + 0x400);
    uVar18 = *(uint *)(iVar15 + 0x400);
    uVar9 = uVar27 ^ *(uint *)(iVar1 + (uVar3 & 0xff) * 4) ^ *(uint *)(iVar13 + 0x400) ^
            *(uint *)(iVar15 + 0xc00) ^ *(uint *)(iVar11 + 0x800) ^ *(uint *)(iVar1 + uVar26 * 4);
    uVar23 = *(uint *)(iVar2 + 0x800);
    uVar26 = *(uint *)(iVar2 + 0xc00);
    uVar25 = *(uint *)(iVar1 + (uVar9 >> 0x18) * 4 + 0x400);
    uVar3 = *(uint *)(iVar1 + ((uVar9 << 8) >> 0x18) * 4 + 0xc00);
    local_118[9] = *(uint *)(iVar1 + (uVar9 >> 0x18) * 4) ^
                   *(uint *)(iVar1 + (uVar9 & 0xff) * 4 + 0xc00) ^
                   uVar14 ^ *(uint *)(iVar1 + (uVar29 >> 0x18) * 4) ^
                   *(uint *)(iVar1 + ((uVar9 << 0x10) >> 0x18) * 4 + 0x400);
    local_118[10] = uVar17 ^ uVar21 ^ uVar16 ^ uVar18 ^ uVar26;
    local_118[8] = uVar28 ^ uVar31 ^ uVar23 ^ uVar25 ^ uVar3;
    local_118[0xb] = uVar20 ^ uVar7 ^ uVar5 ^ uVar24 ^ uVar22;
    local_fc = local_fc ^
               *(uint *)(iVar19 + 0x400) ^
               *(uint *)(iVar8 + 0x400) ^ *(uint *)(iVar1 + (uVar4 & 0xff) * 4) ^ uVar20 ^ uVar7;
    iVar13 = iVar1 + (local_fc >> 0x18) * 4;
    iVar8 = iVar1 + (local_fc & 0xff) * 4;
    uVar28 = (local_fc << 0x10) >> 0x18;
    uVar3 = *(uint *)(iVar1 + ((local_fc << 8) >> 0x18) * 4 + 0x400);
    uVar18 = *(uint *)(iVar13 + 0xc00);
    local_f0 = *(uint *)(iVar1 + uVar28 * 4) ^
               uVar29 ^ *(uint *)(iVar12 + 0xc00) ^ *(uint *)(iVar13 + 0x800) ^
               *(uint *)(iVar8 + 0xc00) ^ uVar3;
    uVar17 = *(uint *)(iVar8 + 0x400);
    uVar21 = *(uint *)(iVar1 + uVar28 * 4 + 0xc00);
    iVar11 = iVar1 + (local_f0 & 0xff) * 4;
    uVar7 = *(uint *)(iVar1 + (local_f0 >> 0x18) * 4 + 0xc00);
    uVar22 = (local_f0 << 0x10) >> 0x18;
    uVar23 = *(uint *)(iVar1 + ((local_f0 << 8) >> 0x18) * 4 + 0x400);
    uVar20 = *(uint *)(iVar1 + (local_f0 & 0xff) * 4);
    uVar26 = uVar4 ^ uVar14 ^ *(uint *)(iVar11 + 0x800) ^ uVar7 ^ *(uint *)(iVar1 + uVar22 * 4) ^
             uVar23;
    local_110 = ((uVar26 << 0x10) >> 0x18) * 4;
    iVar19 = iVar1 + (uVar26 >> 0x18) * 4;
    local_10c = *(uint *)(iVar1 + (uVar26 & 0xff) * 4);
    uVar14 = *(uint *)(iVar1 + local_110 + 0x800);
    local_11c = (uVar26 << 8) >> 0x18;
    uVar16 = *(uint *)(iVar1 + local_11c * 4);
    local_120 = *(uint *)(iVar19 + 0x400);
    uVar28 = uVar9 ^ *(uint *)(iVar1 + (uVar29 & 0xff) * 4) ^
             *(uint *)(iVar1 + (uVar26 & 0xff) * 4 + 0x400) ^ *(uint *)(iVar19 + 0xc00) ^ uVar14 ^
             uVar16;
    local_108 = ((uVar28 << 0x10) >> 0x18) * 4;
    uVar24 = (uVar28 << 8) >> 0x18;
    iVar2 = uVar24 * 4;
    uVar4 = *(uint *)(iVar1 + uVar24 * 4);
    iVar13 = (uVar28 >> 0x18) * 4;
    uVar24 = *(uint *)(iVar1 + (uVar28 & 0xff) * 4);
    uVar25 = *(uint *)(iVar1 + iVar13 + 0x800);
    uVar9 = *(uint *)(iVar1 + local_108 + 0x800);
    uVar5 = *(uint *)(iVar1 + iVar2 + 0xc00);
    local_118[0xc] =
         *(uint *)(iVar11 + 0x400) ^ *(uint *)(iVar8 + 0x800) ^
         *(uint *)(iVar1 + uVar22 * 4 + 0xc00) ^ *(uint *)(iVar19 + 0x800) ^ uVar16;
    local_118[0xd] = uVar20 ^ uVar7 ^ uVar23 ^ local_10c ^ uVar14;
    local_118[0xe] = uVar21 ^ uVar17 ^ local_120 ^ uVar25 ^ uVar4;
    local_118[0xf] = uVar3 ^ uVar18 ^ uVar24 ^ uVar9 ^ uVar5;
    if (local_118 != &local_a0) break;
    local_118 = &local_60;
  }
  key->data[9] = local_50 + 0x10U & 0x1f;
  key->data[1] = local_60 + 0x10 & 0x1f;
  key->data[3] = local_5c + 0x10U & 0x1f;
  key->data[5] = local_58 + 0x10U & 0x1f;
  key->data[0xb] = local_4c + 0x10U & 0x1f;
  key->data[0xd] = local_48 + 0x10U & 0x1f;
  key->data[0xf] = local_44 + 0x10U & 0x1f;
  key->data[0] = local_a0;
  key->data[7] = local_54 + 0x10U & 0x1f;
  key->data[2] = local_9c;
  key->data[4] = local_98;
  key->data[6] = local_94;
  key->data[8] = local_90;
  key->data[10] = local_8c;
  key->data[0xc] = local_88;
  key->data[0xe] = local_84;
  key->data[0x10] = local_80;
  key->data[0x11] = local_40 + 0x10U & 0x1f;
  key->data[0x13] = local_3c + 0x10U & 0x1f;
  key->data[0x17] = local_34 + 0x10U & 0x1f;
  key->data[0x19] = local_30 + 0x10U & 0x1f;
  key->data[0x1b] = local_2c + 0x10U & 0x1f;
  key->data[0x1d] = local_28 + 0x10U & 0x1f;
  key->data[0x1f] = local_24 + 0x10U & 0x1f;
  key->data[0x15] = local_38 + 0x10U & 0x1f;
  key->data[0x12] = local_7c;
  key->data[0x14] = local_78;
  key->data[0x16] = local_74;
  key->data[0x18] = local_70;
  key->data[0x1a] = local_6c;
  key->data[0x1c] = local_68;
  key->data[0x1e] = local_64;
  return;
}


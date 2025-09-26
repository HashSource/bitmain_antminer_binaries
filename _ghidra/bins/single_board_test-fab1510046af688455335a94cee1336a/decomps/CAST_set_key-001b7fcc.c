
void CAST_set_key(CAST_KEY *key,int len,uchar *data)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  byte *unaff_r4;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
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
  uint uVar30;
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
  
  if (0xf < len) {
    len = 0x10;
  }
  pbVar12 = data;
  if (0 < len) {
    pbVar12 = data + -1;
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
  puVar15 = &local_e4;
  iVar16 = 0;
  if (0 < len) {
    do {
      pbVar12 = pbVar12 + 1;
      puVar15 = puVar15 + 1;
      *puVar15 = (uint)*pbVar12;
      iVar16 = local_dc;
    } while (pbVar12 != unaff_r4);
  }
  if (10 < len) {
    unaff_r7 = 0;
  }
  if (len < 0xb) {
    unaff_r7 = 1;
  }
  local_11c = local_bc;
  iVar7 = local_ac << 2;
  local_fc = iVar16 << 0x10 | local_e0 << 0x18 | local_d4 | local_d8 << 8;
  iVar16 = local_b0 << 2;
  key->short_key = unaff_r7;
  local_f0 = local_cc << 0x10 | local_d0 << 0x18 | local_c4 | local_c8 << 8;
  uVar27 = local_ac << 0x10 | local_b0 << 0x18 | local_a4 | local_a8 << 8;
  local_108 = local_a8 << 2;
  local_120 = *(uint *)(CAST_S_table6 + local_c0 * 4);
  uVar26 = local_bc << 0x10 | local_c0 << 0x18 | local_b4 | local_b8 << 8;
  local_110 = local_b8 << 2;
  uVar24 = *(uint *)(&CAST_S_table5 + local_a4 * 4);
  local_10c = *(uint *)(&CAST_S_table5 + local_b4 * 4);
  local_118 = &local_a0;
  while( true ) {
    local_120 = uVar24 ^ *(uint *)(CAST_S_table7 + local_108) ^
                         *(uint *)(CAST_S_table6 + iVar16) ^ *(uint *)(CAST_S_table4 + iVar7) ^
                         local_fc ^ local_120;
    iVar16 = (local_120 & 0xff) * 4;
    iVar7 = (local_120 >> 0x18) * 4;
    iVar1 = ((local_120 << 8) >> 0x18) * 4;
    uVar24 = (local_120 << 0x10) >> 0x18;
    iVar2 = uVar24 * 4;
    uVar25 = *(uint *)(CAST_S_table6 + iVar16);
    uVar17 = *(uint *)(CAST_S_table6 + iVar1);
    uVar13 = *(uint *)(CAST_S_table7 + iVar2);
    uVar26 = *(uint *)(CAST_S_table4 + iVar7) ^ *(uint *)(CAST_S_table7 + iVar16) ^
             *(uint *)(CAST_S_table7 + local_110) ^ *(uint *)(&CAST_S_table5 + uVar24 * 4) ^ uVar17
             ^ uVar26;
    uVar18 = *(uint *)(CAST_S_table7 + iVar7);
    iVar16 = (uVar26 >> 0x18) * 4;
    iVar3 = ((uVar26 << 8) >> 0x18) * 4;
    iVar4 = (uVar26 & 0xff) * 4;
    uVar10 = *(uint *)(CAST_S_table7 + iVar16);
    uVar24 = (uVar26 << 0x10) >> 0x18;
    uVar19 = *(uint *)(&CAST_S_table5 + uVar24 * 4);
    uVar14 = *(uint *)(CAST_S_table6 + iVar3);
    uVar20 = *(uint *)(CAST_S_table7 + uVar24 * 4);
    uVar27 = *(uint *)(CAST_S_table4 + iVar4) ^ uVar10 ^ *(uint *)(CAST_S_table4 + local_11c * 4) ^
             uVar19 ^ uVar14 ^ uVar27;
    iVar5 = (uVar27 >> 0x18) * 4;
    uVar21 = *(uint *)(&CAST_S_table5 + (uVar27 & 0xff) * 4);
    uVar11 = *(uint *)(CAST_S_table4 + ((uVar27 << 0x10) >> 0x18) * 4);
    uVar24 = (uVar27 << 8) >> 0x18;
    uVar8 = *(uint *)(CAST_S_table6 + uVar24 * 4);
    local_10c = *(uint *)(CAST_S_table6 + (uVar27 & 0xff) * 4) ^ *(uint *)(CAST_S_table7 + iVar5) ^
                uVar11 ^ *(uint *)(&CAST_S_table5 + uVar24 * 4) ^ local_f0 ^ local_10c;
    uVar29 = *(uint *)(CAST_S_table4 + ((local_10c << 0x10) >> 0x18) * 4);
    uVar22 = *(uint *)(&CAST_S_table5 + (local_10c & 0xff) * 4);
    iVar6 = (local_10c >> 0x18) * 4;
    uVar23 = *(uint *)(CAST_S_table4 + iVar6);
    uVar28 = *(uint *)(CAST_S_table7 + iVar6);
    uVar9 = *(uint *)(&CAST_S_table5 + ((local_10c << 8) >> 0x18) * 4);
    *local_118 = *(uint *)(CAST_S_table6 + iVar4) ^ *(uint *)(CAST_S_table4 + iVar2) ^ uVar20 ^
                 *(uint *)(CAST_S_table4 + iVar5) ^ *(uint *)(&CAST_S_table5 + uVar24 * 4);
    local_118[1] = uVar11 ^ uVar21 ^ uVar19 ^ uVar14 ^ uVar10;
    local_118[2] = uVar23 ^ uVar25 ^ uVar13 ^ uVar8 ^ uVar9;
    local_118[3] = uVar17 ^ uVar18 ^ uVar22 ^ uVar28 ^ uVar29;
    uVar27 = *(uint *)(CAST_S_table4 + iVar3) ^
             *(uint *)(CAST_S_table6 + iVar7) ^
             *(uint *)(CAST_S_table6 + iVar16) ^ *(uint *)(&CAST_S_table5 + (uVar26 & 0xff) * 4) ^
             uVar20 ^ uVar27;
    iVar16 = (uVar27 & 0xff) * 4;
    iVar7 = ((uVar27 << 8) >> 0x18) * 4;
    uVar11 = *(uint *)(CAST_S_table6 + iVar16);
    uVar17 = *(uint *)(&CAST_S_table5 + (uVar27 >> 0x18) * 4);
    uVar20 = *(uint *)(CAST_S_table4 + iVar7);
    uVar29 = *(uint *)(CAST_S_table7 + iVar16) ^
             uVar13 ^ local_120 ^ *(uint *)(CAST_S_table4 + (uVar27 >> 0x18) * 4) ^
             *(uint *)(&CAST_S_table5 + ((uVar27 << 0x10) >> 0x18) * 4) ^
             *(uint *)(CAST_S_table6 + iVar7);
    iVar7 = (uVar29 & 0xff) * 4;
    uVar24 = *(uint *)(&CAST_S_table5 + ((uVar29 << 0x10) >> 0x18) * 4);
    uVar13 = *(uint *)(&CAST_S_table5 + (uVar29 >> 0x18) * 4);
    uVar10 = *(uint *)(CAST_S_table4 + iVar7);
    iVar2 = ((uVar29 << 8) >> 0x18) * 4;
    uVar30 = *(uint *)(CAST_S_table7 + iVar7);
    uVar9 = *(uint *)(CAST_S_table4 + iVar2);
    uVar8 = uVar26 ^ *(uint *)(CAST_S_table4 + iVar1) ^ uVar10 ^
            *(uint *)(CAST_S_table7 + (uVar29 >> 0x18) * 4) ^ uVar24 ^
            *(uint *)(CAST_S_table6 + iVar2);
    uVar26 = (uVar8 << 8) >> 0x18;
    iVar7 = (uVar8 & 0xff) * 4;
    iVar1 = ((uVar8 << 0x10) >> 0x18) * 4;
    iVar2 = (uVar8 >> 0x18) * 4;
    uVar25 = *(uint *)(CAST_S_table7 + iVar7);
    iVar3 = uVar26 * 4;
    uVar14 = *(uint *)(CAST_S_table6 + iVar2);
    uVar26 = *(uint *)(CAST_S_table7 + iVar2) ^
             *(uint *)(CAST_S_table6 + iVar7) ^
             *(uint *)(&CAST_S_table5 + (local_120 & 0xff) * 4) ^ local_10c ^
             *(uint *)(CAST_S_table4 + iVar1) ^ *(uint *)(&CAST_S_table5 + uVar26 * 4);
    uVar18 = *(uint *)(CAST_S_table7 + (uVar26 & 0xff) * 4);
    uVar22 = (uVar26 << 8) >> 0x18;
    iVar7 = ((uVar26 << 0x10) >> 0x18) * 4;
    uVar19 = *(uint *)(CAST_S_table6 + (uVar26 >> 0x18) * 4);
    uVar21 = *(uint *)(&CAST_S_table5 + uVar22 * 4);
    iVar4 = uVar22 * 4;
    uVar22 = *(uint *)(CAST_S_table6 + iVar7);
    uVar23 = *(uint *)(CAST_S_table6 + iVar1);
    uVar28 = *(uint *)(CAST_S_table7 + iVar3);
    local_118[4] = *(uint *)(&CAST_S_table5 + ((uVar27 << 0x10) >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table4 + iVar16) ^ *(uint *)(CAST_S_table4 + iVar2) ^ uVar19 ^
                   *(uint *)(CAST_S_table7 + iVar4);
    local_118[6] = uVar10 ^ uVar11 ^ uVar24 ^ uVar14 ^ uVar28;
    local_118[5] = uVar21 ^ uVar17 ^ uVar20 ^ uVar18 ^ uVar22;
    local_118[7] = uVar9 ^ uVar30 ^ uVar13 ^ uVar25 ^ uVar23;
    uVar28 = *(uint *)(CAST_S_table4 + iVar4) ^
             uVar14 ^ uVar27 ^ uVar19 ^ *(uint *)(&CAST_S_table5 + (uVar26 & 0xff) * 4) ^
             *(uint *)(CAST_S_table7 + iVar7);
    iVar16 = (uVar28 >> 0x18) * 4;
    iVar7 = (uVar28 & 0xff) * 4;
    iVar2 = ((uVar28 << 8) >> 0x18) * 4;
    uVar24 = (uVar28 << 0x10) >> 0x18;
    uVar27 = *(uint *)(&CAST_S_table5 + uVar24 * 4);
    iVar4 = uVar24 * 4;
    uVar14 = *(uint *)(CAST_S_table4 + iVar2);
    uVar30 = *(uint *)(CAST_S_table4 + iVar7);
    uVar9 = *(uint *)(CAST_S_table4 + iVar16) ^ uVar8 ^ *(uint *)(CAST_S_table7 + iVar1) ^
            *(uint *)(CAST_S_table7 + iVar7) ^ uVar27 ^ *(uint *)(CAST_S_table6 + iVar2);
    iVar7 = (uVar9 >> 0x18) * 4;
    uVar10 = *(uint *)(&CAST_S_table5 + (uVar9 >> 0x18) * 4);
    iVar1 = ((uVar9 << 8) >> 0x18) * 4;
    uVar18 = *(uint *)(CAST_S_table4 + (uVar9 & 0xff) * 4);
    uVar24 = (uVar9 << 0x10) >> 0x18;
    uVar17 = *(uint *)(&CAST_S_table5 + uVar24 * 4);
    uVar20 = *(uint *)(CAST_S_table4 + iVar1);
    uVar11 = *(uint *)(CAST_S_table7 + uVar24 * 4);
    local_fc = uVar26 ^ *(uint *)(CAST_S_table4 + iVar3) ^ uVar18 ^ *(uint *)(CAST_S_table7 + iVar7)
               ^ uVar17 ^ *(uint *)(CAST_S_table6 + iVar1);
    iVar1 = (local_fc & 0xff) * 4;
    iVar2 = (local_fc >> 0x18) * 4;
    uVar24 = *(uint *)(CAST_S_table7 + iVar1);
    uVar21 = *(uint *)(CAST_S_table6 + iVar4);
    iVar3 = ((local_fc << 0x10) >> 0x18) * 4;
    uVar26 = (local_fc << 8) >> 0x18;
    iVar5 = uVar26 * 4;
    uVar22 = *(uint *)(CAST_S_table6 + iVar3);
    uVar19 = *(uint *)(CAST_S_table6 + iVar2);
    uVar13 = uVar29 ^ *(uint *)(&CAST_S_table5 + (uVar8 & 0xff) * 4) ^
             *(uint *)(CAST_S_table6 + iVar1) ^ *(uint *)(CAST_S_table7 + iVar2) ^
             *(uint *)(CAST_S_table4 + iVar3) ^ *(uint *)(&CAST_S_table5 + uVar26 * 4);
    uVar23 = *(uint *)(CAST_S_table4 + iVar5);
    uVar26 = *(uint *)(CAST_S_table7 + iVar5);
    uVar25 = *(uint *)(CAST_S_table6 + (uVar13 >> 0x18) * 4);
    uVar8 = *(uint *)(CAST_S_table7 + ((uVar13 << 8) >> 0x18) * 4);
    local_118[9] = *(uint *)(&CAST_S_table5 + (uVar13 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table7 + (uVar13 & 0xff) * 4) ^
                   uVar14 ^ *(uint *)(&CAST_S_table5 + (uVar28 >> 0x18) * 4) ^
                   *(uint *)(CAST_S_table6 + ((uVar13 << 0x10) >> 0x18) * 4);
    local_118[10] = uVar18 ^ uVar21 ^ uVar17 ^ uVar19 ^ uVar26;
    local_118[8] = uVar27 ^ uVar30 ^ uVar23 ^ uVar25 ^ uVar8;
    local_118[0xb] = uVar20 ^ uVar11 ^ uVar10 ^ uVar24 ^ uVar22;
    local_fc = local_fc ^
               *(uint *)(CAST_S_table6 + iVar16) ^
               *(uint *)(CAST_S_table6 + iVar7) ^ *(uint *)(&CAST_S_table5 + (uVar9 & 0xff) * 4) ^
               uVar20 ^ uVar11;
    iVar16 = (local_fc >> 0x18) * 4;
    iVar1 = (local_fc & 0xff) * 4;
    uVar27 = (local_fc << 0x10) >> 0x18;
    uVar8 = *(uint *)(CAST_S_table6 + ((local_fc << 8) >> 0x18) * 4);
    uVar18 = *(uint *)(CAST_S_table7 + iVar16);
    local_f0 = *(uint *)(&CAST_S_table5 + uVar27 * 4) ^
               uVar28 ^ *(uint *)(CAST_S_table7 + iVar4) ^ *(uint *)(CAST_S_table4 + iVar16) ^
               *(uint *)(CAST_S_table7 + iVar1) ^ uVar8;
    uVar17 = *(uint *)(CAST_S_table6 + iVar1);
    uVar20 = *(uint *)(CAST_S_table7 + uVar27 * 4);
    iVar2 = (local_f0 & 0xff) * 4;
    uVar11 = *(uint *)(CAST_S_table7 + (local_f0 >> 0x18) * 4);
    uVar21 = (local_f0 << 0x10) >> 0x18;
    uVar22 = *(uint *)(CAST_S_table6 + ((local_f0 << 8) >> 0x18) * 4);
    uVar19 = *(uint *)(&CAST_S_table5 + (local_f0 & 0xff) * 4);
    uVar26 = uVar9 ^ uVar14 ^ *(uint *)(CAST_S_table4 + iVar2) ^ uVar11 ^
             *(uint *)(&CAST_S_table5 + uVar21 * 4) ^ uVar22;
    local_110 = ((uVar26 << 0x10) >> 0x18) * 4;
    iVar3 = (uVar26 >> 0x18) * 4;
    local_10c = *(uint *)(&CAST_S_table5 + (uVar26 & 0xff) * 4);
    uVar14 = *(uint *)(CAST_S_table4 + local_110);
    local_11c = (uVar26 << 8) >> 0x18;
    local_120 = *(uint *)(CAST_S_table6 + iVar3);
    uVar27 = uVar13 ^ *(uint *)(&CAST_S_table5 + (uVar28 & 0xff) * 4) ^
             *(uint *)(CAST_S_table6 + (uVar26 & 0xff) * 4) ^ *(uint *)(CAST_S_table7 + iVar3) ^
             uVar14 ^ *(uint *)(&CAST_S_table5 + local_11c * 4);
    local_108 = ((uVar27 << 0x10) >> 0x18) * 4;
    uVar24 = (uVar27 << 8) >> 0x18;
    iVar7 = uVar24 * 4;
    uVar9 = *(uint *)(&CAST_S_table5 + uVar24 * 4);
    iVar16 = (uVar27 >> 0x18) * 4;
    uVar24 = *(uint *)(&CAST_S_table5 + (uVar27 & 0xff) * 4);
    uVar23 = *(uint *)(CAST_S_table4 + iVar16);
    uVar13 = *(uint *)(CAST_S_table4 + local_108);
    uVar10 = *(uint *)(CAST_S_table7 + iVar7);
    local_118[0xc] =
         *(uint *)(CAST_S_table6 + iVar2) ^ *(uint *)(CAST_S_table4 + iVar1) ^
         *(uint *)(CAST_S_table7 + uVar21 * 4) ^ *(uint *)(CAST_S_table4 + iVar3) ^
         *(uint *)(&CAST_S_table5 + local_11c * 4);
    local_118[0xd] = uVar19 ^ uVar11 ^ uVar22 ^ local_10c ^ uVar14;
    local_118[0xe] = uVar20 ^ uVar17 ^ local_120 ^ uVar23 ^ uVar9;
    local_118[0xf] = uVar8 ^ uVar18 ^ uVar24 ^ uVar13 ^ uVar10;
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



void CAST_set_key(CAST_KEY *key,int len,uchar *data)

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
  bool bVar30;
  uint *local_140;
  uint local_13c;
  uint local_138;
  uint local_134;
  uint local_130;
  uint local_12c;
  uint local_128;
  uint local_108;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  uint local_d4;
  uint local_d0;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
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
  int local_64;
  int local_60;
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
  
  memset(&local_e8,0,0x40);
  if (0xf < len) {
    len = 0x10;
  }
  if (((((0 < len) && (local_e8 = (uint)*data, len != 1)) && (local_e4 = (uint)data[1], len != 2))
      && (((local_e0 = (uint)data[2], len != 3 && (local_dc = (uint)data[3], len != 4)) &&
          ((local_d8 = (uint)data[4], len != 5 &&
           ((local_d4 = (uint)data[5], len != 6 && (local_d0 = (uint)data[6], len != 7)))))))) &&
     ((local_cc = (uint)data[7], len != 8 &&
      (((((local_c8 = (uint)data[8], len != 9 && (local_c4 = (uint)data[9], len != 10)) &&
         (local_c0 = (uint)data[10], len != 0xb)) &&
        ((local_bc = (uint)data[0xb], len != 0xc && (local_b8 = (uint)data[0xc], len != 0xd)))) &&
       ((local_b4 = (uint)data[0xd], len != 0xe && (local_b0 = (uint)data[0xe], len == 0x10))))))))
  {
    local_ac = (uint)data[0xf];
  }
  local_134 = local_b8;
  local_128 = local_c4;
  local_130 = local_c0;
  local_13c = local_e4 << 0x10 | local_e8 << 0x18 | local_dc | local_e0 << 8;
  key->short_key = (uint)(len < 0xb);
  local_12c = local_d4 << 0x10 | local_d8 << 0x18 | local_cc | local_d0 << 8;
  uVar4 = local_b4 << 0x10 | local_b8 << 0x18 | local_ac | local_b0 << 8;
  local_138 = local_c4 << 0x10 | local_c8 << 0x18 | local_bc | local_c0 << 8;
  local_108 = *(uint *)(CAST_S_table5 + local_bc * 4);
  uVar10 = *(uint *)(CAST_S_table5 + local_ac * 4);
  uVar14 = *(uint *)(CAST_S_table6 + local_c8 * 4);
  local_140 = &local_a8;
  do {
    uVar14 = uVar14 ^ local_13c ^
                      *(uint *)(CAST_S_table4 + local_b4 * 4) ^
                      *(uint *)(CAST_S_table6 + local_134 * 4) ^
                      *(uint *)(&CAST_S_table7 + local_b0 * 4) ^ uVar10;
    uVar5 = uVar14 >> 0x18;
    uVar7 = uVar14 & 0xff;
    uVar10 = (uVar14 << 0x10) >> 0x18;
    uVar21 = (uVar14 << 8) >> 0x18;
    uVar6 = *(uint *)(CAST_S_table6 + uVar21 * 4);
    uVar1 = *(uint *)(&CAST_S_table7 + uVar10 * 4);
    uVar8 = *(uint *)(CAST_S_table6 + uVar7 * 4);
    local_138 = *(uint *)(&CAST_S_table7 + local_130 * 4) ^
                *(uint *)(&CAST_S_table7 + uVar7 * 4) ^ *(uint *)(CAST_S_table4 + uVar5 * 4) ^
                *(uint *)(CAST_S_table5 + uVar10 * 4) ^ uVar6 ^ local_138;
    uVar11 = local_138 & 0xff;
    uVar9 = *(uint *)(&CAST_S_table7 + uVar5 * 4);
    uVar15 = (local_138 << 0x10) >> 0x18;
    uVar12 = (local_138 << 8) >> 0x18;
    uVar2 = *(uint *)(&CAST_S_table7 + (local_138 >> 0x18) * 4);
    uVar3 = *(uint *)(CAST_S_table5 + uVar15 * 4);
    uVar13 = *(uint *)(CAST_S_table6 + uVar12 * 4);
    uVar4 = *(uint *)(CAST_S_table4 + uVar11 * 4) ^ uVar2 ^ *(uint *)(CAST_S_table4 + local_128 * 4)
            ^ uVar3 ^ uVar13 ^ uVar4;
    uVar16 = *(uint *)(&CAST_S_table7 + uVar15 * 4);
    uVar17 = (uVar4 << 8) >> 0x18;
    uVar15 = *(uint *)(CAST_S_table5 + (uVar4 & 0xff) * 4);
    uVar24 = *(uint *)(CAST_S_table4 + ((uVar4 << 0x10) >> 0x18) * 4);
    uVar18 = *(uint *)(CAST_S_table6 + uVar17 * 4);
    local_108 = *(uint *)(&CAST_S_table7 + (uVar4 >> 0x18) * 4) ^
                *(uint *)(CAST_S_table6 + (uVar4 & 0xff) * 4) ^ uVar24 ^
                *(uint *)(CAST_S_table5 + uVar17 * 4) ^ local_12c ^ local_108;
    *local_140 = *(uint *)(CAST_S_table4 + uVar10 * 4) ^ *(uint *)(CAST_S_table6 + uVar11 * 4) ^
                 uVar16 ^ *(uint *)(CAST_S_table4 + (uVar4 >> 0x18) * 4) ^
                 *(uint *)(CAST_S_table5 + uVar17 * 4);
    uVar17 = *(uint *)(CAST_S_table5 + ((local_108 << 8) >> 0x18) * 4);
    local_140[1] = uVar3 ^ uVar13 ^ uVar2 ^ uVar15 ^ uVar24;
    uVar10 = *(uint *)(CAST_S_table5 + (local_108 & 0xff) * 4);
    local_140[2] = uVar8 ^ uVar1 ^ uVar18 ^ *(uint *)(CAST_S_table4 + (local_108 >> 0x18) * 4) ^
                   uVar17;
    uVar8 = *(uint *)(CAST_S_table5 + uVar7 * 4);
    uVar4 = *(uint *)(CAST_S_table6 + (local_138 >> 0x18) * 4) ^
            *(uint *)(CAST_S_table5 + uVar11 * 4) ^ *(uint *)(CAST_S_table6 + uVar5 * 4) ^ uVar16 ^
            *(uint *)(CAST_S_table4 + uVar12 * 4) ^ uVar4;
    uVar5 = *(uint *)(CAST_S_table4 + uVar21 * 4);
    uVar11 = uVar4 & 0xff;
    uVar3 = (uVar4 << 8) >> 0x18;
    uVar15 = *(uint *)(CAST_S_table5 + ((uVar4 << 0x10) >> 0x18) * 4);
    uVar2 = *(uint *)(CAST_S_table5 + (uVar4 >> 0x18) * 4);
    uVar7 = *(uint *)(CAST_S_table4 + uVar3 * 4);
    uVar22 = *(uint *)(CAST_S_table4 + (uVar4 >> 0x18) * 4) ^ uVar14 ^ uVar1 ^
             *(uint *)(&CAST_S_table7 + uVar11 * 4) ^ uVar15 ^ *(uint *)(CAST_S_table6 + uVar3 * 4);
    uVar25 = (uVar22 << 8) >> 0x18;
    uVar16 = *(uint *)(CAST_S_table4 + uVar11 * 4);
    local_140[3] = *(uint *)(&CAST_S_table7 + (local_108 >> 0x18) * 4) ^ uVar10 ^ uVar9 ^ uVar6 ^
                   *(uint *)(CAST_S_table4 + ((local_108 << 0x10) >> 0x18) * 4);
    uVar10 = *(uint *)(CAST_S_table5 + ((uVar22 << 0x10) >> 0x18) * 4);
    uVar13 = *(uint *)(CAST_S_table4 + (uVar22 & 0xff) * 4);
    uVar14 = *(uint *)(CAST_S_table6 + uVar25 * 4) ^
             local_138 ^ uVar5 ^ uVar13 ^ *(uint *)(&CAST_S_table7 + (uVar22 >> 0x18) * 4) ^ uVar10;
    uVar17 = uVar14 & 0xff;
    uVar26 = uVar14 >> 0x18;
    uVar24 = (uVar14 << 0x10) >> 0x18;
    uVar6 = (uVar14 << 8) >> 0x18;
    uVar12 = local_108 ^ uVar8 ^ *(uint *)(CAST_S_table6 + uVar17 * 4) ^
             *(uint *)(&CAST_S_table7 + uVar26 * 4) ^ *(uint *)(CAST_S_table4 + uVar24 * 4) ^
             *(uint *)(CAST_S_table5 + uVar6 * 4);
    uVar1 = *(uint *)(CAST_S_table6 + (uVar12 >> 0x18) * 4);
    uVar9 = (uVar12 << 0x10) >> 0x18;
    uVar3 = *(uint *)(CAST_S_table4 + uVar26 * 4);
    uVar5 = (uVar12 << 8) >> 0x18;
    uVar8 = *(uint *)(&CAST_S_table7 + uVar5 * 4);
    local_140[5] = uVar7 ^ uVar2 ^ *(uint *)(&CAST_S_table7 + (uVar12 & 0xff) * 4) ^
                   *(uint *)(CAST_S_table6 + uVar9 * 4) ^ *(uint *)(CAST_S_table5 + uVar5 * 4);
    local_140[4] = uVar15 ^ uVar16 ^ uVar3 ^ uVar1 ^ uVar8;
    uVar3 = *(uint *)(CAST_S_table5 + uVar17 * 4);
    uVar27 = uVar4 ^ *(uint *)(CAST_S_table6 + uVar26 * 4) ^ uVar1 ^
             *(uint *)(CAST_S_table5 + (uVar12 & 0xff) * 4) ^ *(uint *)(CAST_S_table4 + uVar5 * 4) ^
             *(uint *)(&CAST_S_table7 + uVar9 * 4);
    uVar19 = uVar27 & 0xff;
    uVar7 = uVar27 >> 0x18;
    uVar20 = (uVar27 << 0x10) >> 0x18;
    uVar28 = (uVar27 << 8) >> 0x18;
    uVar8 = *(uint *)(CAST_S_table5 + (uVar22 >> 0x18) * 4);
    uVar16 = *(uint *)(CAST_S_table5 + uVar20 * 4);
    uVar9 = *(uint *)(CAST_S_table4 + uVar19 * 4);
    uVar23 = *(uint *)(CAST_S_table4 + uVar7 * 4) ^ uVar14 ^ *(uint *)(&CAST_S_table7 + uVar24 * 4)
             ^ *(uint *)(&CAST_S_table7 + uVar19 * 4) ^ uVar16 ^
             *(uint *)(CAST_S_table6 + uVar28 * 4);
    uVar4 = *(uint *)(&CAST_S_table7 + (uVar22 & 0xff) * 4);
    uVar29 = (uVar23 << 0x10) >> 0x18;
    uVar5 = uVar23 >> 0x18;
    uVar18 = *(uint *)(CAST_S_table4 + (uVar23 & 0xff) * 4);
    uVar21 = *(uint *)(&CAST_S_table7 + uVar17 * 4);
    uVar14 = *(uint *)(CAST_S_table5 + uVar29 * 4);
    uVar1 = (uVar23 << 8) >> 0x18;
    uVar17 = *(uint *)(CAST_S_table4 + uVar25 * 4);
    uVar15 = *(uint *)(CAST_S_table6 + uVar24 * 4);
    uVar12 = *(uint *)(CAST_S_table6 + uVar1 * 4) ^
             uVar14 ^ *(uint *)(&CAST_S_table7 + uVar5 * 4) ^
                      uVar12 ^ *(uint *)(CAST_S_table4 + uVar6 * 4) ^ uVar18;
    uVar25 = (uVar12 << 0x10) >> 0x18;
    uVar2 = *(uint *)(CAST_S_table4 + uVar25 * 4);
    local_140[6] = uVar13 ^ *(uint *)(CAST_S_table6 + uVar11 * 4) ^ uVar10 ^
                   *(uint *)(CAST_S_table6 + uVar26 * 4) ^ *(uint *)(&CAST_S_table7 + uVar6 * 4);
    uVar10 = *(uint *)(CAST_S_table6 + (uVar12 & 0xff) * 4);
    uVar6 = *(uint *)(&CAST_S_table7 + (uVar12 >> 0x18) * 4);
    uVar24 = (uVar12 << 8) >> 0x18;
    local_140[7] = uVar21 ^ uVar8 ^ uVar4 ^ uVar17 ^ uVar15;
    uVar26 = uVar10 ^ uVar22 ^ uVar3 ^ uVar6 ^ uVar2 ^ *(uint *)(CAST_S_table5 + uVar24 * 4);
    local_140[8] = *(uint *)(CAST_S_table4 + uVar24 * 4) ^ uVar16 ^ uVar9 ^
                   *(uint *)(CAST_S_table6 + (uVar26 >> 0x18) * 4) ^
                   *(uint *)(&CAST_S_table7 + ((uVar26 << 8) >> 0x18) * 4);
    uVar13 = *(uint *)(CAST_S_table4 + uVar28 * 4);
    uVar10 = *(uint *)(CAST_S_table5 + uVar7 * 4);
    local_13c = *(uint *)(CAST_S_table6 + uVar5 * 4) ^
                *(uint *)(CAST_S_table5 + (uVar23 & 0xff) * 4) ^
                *(uint *)(CAST_S_table6 + uVar7 * 4) ^ *(uint *)(CAST_S_table4 + uVar1 * 4) ^
                *(uint *)(&CAST_S_table7 + uVar29 * 4) ^ uVar12;
    uVar17 = local_13c & 0xff;
    uVar11 = *(uint *)(CAST_S_table6 + uVar20 * 4);
    uVar21 = *(uint *)(&CAST_S_table7 + (uVar26 & 0xff) * 4);
    uVar15 = *(uint *)(CAST_S_table5 + (uVar26 >> 0x18) * 4);
    uVar28 = (local_13c << 0x10) >> 0x18;
    uVar7 = *(uint *)(CAST_S_table6 + ((local_13c << 8) >> 0x18) * 4);
    uVar22 = *(uint *)(CAST_S_table6 + (uVar12 >> 0x18) * 4);
    local_12c = *(uint *)(&CAST_S_table7 + uVar17 * 4) ^
                *(uint *)(&CAST_S_table7 + uVar20 * 4) ^ uVar27 ^
                *(uint *)(CAST_S_table4 + (local_13c >> 0x18) * 4) ^
                *(uint *)(CAST_S_table5 + uVar28 * 4) ^ uVar7;
    uVar2 = *(uint *)(&CAST_S_table7 + uVar24 * 4);
    uVar8 = local_12c & 0xff;
    uVar9 = *(uint *)(&CAST_S_table7 + (local_12c >> 0x18) * 4);
    uVar24 = (local_12c << 0x10) >> 0x18;
    uVar3 = *(uint *)(CAST_S_table5 + uVar19 * 4);
    uVar16 = *(uint *)(CAST_S_table6 + ((uVar26 << 0x10) >> 0x18) * 4);
    uVar6 = *(uint *)(CAST_S_table6 + ((local_12c << 8) >> 0x18) * 4);
    local_138 = *(uint *)(CAST_S_table4 + uVar8 * 4) ^ uVar23 ^ uVar13 ^ uVar9 ^
                *(uint *)(CAST_S_table5 + uVar24 * 4) ^ uVar6;
    local_140[0xb] =
         *(uint *)(CAST_S_table4 + uVar1 * 4) ^ *(uint *)(&CAST_S_table7 + uVar29 * 4) ^
         *(uint *)(CAST_S_table5 + uVar5 * 4) ^ *(uint *)(&CAST_S_table7 + (uVar12 & 0xff) * 4) ^
         *(uint *)(CAST_S_table6 + uVar25 * 4);
    uVar12 = local_138 >> 0x18;
    local_130 = (local_138 << 0x10) >> 0x18;
    uVar4 = *(uint *)(CAST_S_table6 + (local_138 & 0xff) * 4);
    local_128 = (local_138 << 8) >> 0x18;
    local_140[10] = uVar11 ^ uVar18 ^ uVar14 ^ uVar22 ^ uVar2;
    local_140[9] = uVar13 ^ uVar10 ^ uVar21 ^ uVar15 ^ uVar16;
    uVar1 = *(uint *)(CAST_S_table5 + local_128 * 4);
    uVar15 = *(uint *)(&CAST_S_table7 + uVar28 * 4);
    uVar2 = *(uint *)(&CAST_S_table7 + (local_13c >> 0x18) * 4);
    uVar21 = *(uint *)(CAST_S_table6 + uVar8 * 4);
    uVar4 = *(uint *)(&CAST_S_table7 + uVar12 * 4) ^ uVar26 ^ uVar3 ^ uVar4 ^
            *(uint *)(CAST_S_table4 + local_130 * 4) ^ uVar1;
    local_108 = *(uint *)(CAST_S_table5 + (local_138 & 0xff) * 4);
    uVar5 = *(uint *)(CAST_S_table4 + uVar17 * 4);
    uVar17 = *(uint *)(CAST_S_table6 + uVar17 * 4);
    local_134 = uVar4 >> 0x18;
    uVar3 = *(uint *)(&CAST_S_table7 + uVar24 * 4);
    local_b4 = (uVar4 << 8) >> 0x18;
    uVar10 = *(uint *)(CAST_S_table5 + (uVar4 & 0xff) * 4);
    local_b0 = (uVar4 << 0x10) >> 0x18;
    uVar14 = *(uint *)(CAST_S_table6 + uVar12 * 4);
    uVar11 = *(uint *)(CAST_S_table4 + uVar12 * 4);
    uVar16 = *(uint *)(CAST_S_table4 + local_134 * 4);
    uVar18 = *(uint *)(CAST_S_table4 + local_b0 * 4);
    uVar12 = *(uint *)(CAST_S_table5 + local_b4 * 4);
    uVar13 = *(uint *)(&CAST_S_table7 + local_b4 * 4);
    local_140[0xd] =
         *(uint *)(CAST_S_table5 + uVar8 * 4) ^ uVar9 ^ uVar6 ^ local_108 ^
         *(uint *)(CAST_S_table4 + local_130 * 4);
    local_140[0xc] = uVar21 ^ uVar5 ^ uVar3 ^ uVar11 ^ uVar1;
    local_140[0xe] = uVar17 ^ uVar15 ^ uVar14 ^ uVar16 ^ uVar12;
    bVar30 = local_140 == &local_a8;
    local_140[0xf] = uVar2 ^ uVar7 ^ uVar10 ^ uVar18 ^ uVar13;
    local_140 = &local_68;
  } while (bVar30);
  key->data[1] = local_68 + 0x10 & 0x1f;
  key->data[3] = local_64 + 0x10U & 0x1f;
  key->data[5] = local_60 + 0x10U & 0x1f;
  key->data[7] = local_5c + 0x10U & 0x1f;
  key->data[9] = local_58 + 0x10U & 0x1f;
  key->data[0xb] = local_54 + 0x10U & 0x1f;
  key->data[0xd] = local_50 + 0x10U & 0x1f;
  key->data[0xf] = local_4c + 0x10U & 0x1f;
  key->data[2] = local_a4;
  key->data[0] = local_a8;
  key->data[4] = local_a0;
  key->data[6] = local_9c;
  key->data[8] = local_98;
  key->data[10] = local_94;
  key->data[0xc] = local_90;
  key->data[0xe] = local_8c;
  key->data[0x11] = local_48 + 0x10U & 0x1f;
  key->data[0x10] = local_88;
  key->data[0x15] = local_40 + 0x10U & 0x1f;
  key->data[0x17] = local_3c + 0x10U & 0x1f;
  key->data[0x19] = local_38 + 0x10U & 0x1f;
  key->data[0x1b] = local_34 + 0x10U & 0x1f;
  key->data[0x14] = local_80;
  key->data[0x13] = local_44 + 0x10U & 0x1f;
  key->data[0x1d] = local_30 + 0x10U & 0x1f;
  key->data[0x1f] = local_2c + 0x10U & 0x1f;
  key->data[0x12] = local_84;
  key->data[0x16] = local_7c;
  key->data[0x18] = local_78;
  key->data[0x1a] = local_74;
  key->data[0x1c] = local_70;
  key->data[0x1e] = local_6c;
  return;
}


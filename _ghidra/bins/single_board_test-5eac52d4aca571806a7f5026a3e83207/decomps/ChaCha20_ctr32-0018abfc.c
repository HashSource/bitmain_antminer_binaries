
void ChaCha20_ctr32(uint *param_1,uint *param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  byte *pbVar2;
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
  int iVar14;
  byte *pbVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  byte *pbVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint local_e0;
  uint local_dc;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  int local_c0;
  uint *local_bc;
  uint *local_b8;
  uint local_b4;
  uint local_ac;
  uint local_a8;
  byte bStack_69;
  undefined4 local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  uVar3 = *param_4;
  uVar4 = param_4[1];
  uVar5 = param_4[2];
  uVar6 = param_4[3];
  uVar7 = param_4[4];
  uVar8 = param_4[5];
  uVar9 = param_4[6];
  uVar17 = param_4[7];
  uVar10 = param_5[1];
  local_b4 = *param_5;
  uVar11 = param_5[2];
  uVar12 = param_5[3];
  local_ac = param_3;
  local_bc = param_2;
  local_b8 = param_1;
  if (param_3 != 0) {
    do {
      if (local_ac < 0x40) {
        local_a8 = 0;
      }
      else {
        local_a8 = local_ac - 0x40;
        local_ac = 0x40;
      }
      uVar24 = 0x79622d32;
      uVar25 = 0x3320646e;
      uVar26 = 0x61707865;
      local_c0 = 10;
      local_c8 = 0x6b206574;
      local_30 = uVar11;
      local_2c = uVar12;
      local_58 = uVar3;
      local_54 = uVar4;
      local_4c = uVar6;
      uVar21 = local_b4;
      local_50 = uVar5;
      local_48 = uVar7;
      local_e0 = uVar9;
      local_dc = uVar10;
      local_cc = uVar17;
      local_c4 = uVar8;
      do {
        local_30 = local_50 + uVar24 ^ local_30;
        uVar21 = uVar26 + local_58 ^ uVar21;
        local_2c = local_2c ^ local_c8 + local_4c;
        uVar16 = local_30 >> 0x10 | local_30 << 0x10;
        uVar21 = uVar21 >> 0x10 | uVar21 << 0x10;
        uVar13 = local_2c >> 0x10 | local_2c << 0x10;
        local_dc = uVar25 + local_54 ^ local_dc;
        uVar18 = local_dc >> 0x10 | local_dc << 0x10;
        local_48 = uVar21 + local_48;
        local_c4 = local_c4 + uVar18;
        local_e0 = local_e0 + uVar16;
        local_cc = local_cc + uVar13;
        uVar19 = local_48 ^ local_58;
        uVar1 = local_c4 ^ local_54;
        uVar1 = uVar1 >> 0x14 | uVar1 << 0xc;
        uVar19 = uVar19 >> 0x14 | uVar19 << 0xc;
        uVar23 = local_50 ^ local_e0;
        uVar23 = uVar23 >> 0x14 | uVar23 << 0xc;
        uVar25 = uVar25 + local_54 + uVar1;
        uVar26 = uVar26 + local_58 + uVar19;
        uVar24 = local_50 + uVar24 + uVar23;
        uVar22 = local_4c ^ local_cc;
        uVar18 = uVar18 ^ uVar25;
        uVar21 = uVar21 ^ uVar26;
        uVar18 = uVar18 >> 0x18 | uVar18 << 8;
        uVar21 = uVar21 >> 0x18 | uVar21 << 8;
        uVar22 = uVar22 >> 0x14 | uVar22 << 0xc;
        uVar16 = uVar16 ^ uVar24;
        uVar16 = uVar16 >> 0x18 | uVar16 << 8;
        local_c8 = local_c8 + local_4c + uVar22;
        uVar13 = uVar13 ^ local_c8;
        local_48 = local_48 + uVar21;
        uVar13 = uVar13 >> 0x18 | uVar13 << 8;
        local_c4 = local_c4 + uVar18;
        uVar1 = uVar1 ^ local_c4;
        local_e0 = local_e0 + uVar16;
        uVar23 = uVar23 ^ local_e0;
        uVar23 = uVar23 >> 0x19 | uVar23 << 7;
        local_cc = local_cc + uVar13;
        uVar25 = uVar25 + uVar23;
        uVar22 = uVar22 ^ local_cc;
        uVar21 = uVar21 ^ uVar25;
        uVar19 = uVar19 ^ local_48;
        uVar1 = uVar1 >> 0x19 | uVar1 << 7;
        uVar19 = uVar19 >> 0x19 | uVar19 << 7;
        uVar22 = uVar22 >> 0x19 | uVar22 << 7;
        uVar21 = uVar21 >> 0x10 | uVar21 << 0x10;
        local_c8 = local_c8 + uVar19;
        uVar26 = uVar26 + uVar1;
        uVar16 = uVar16 ^ local_c8;
        uVar13 = uVar13 ^ uVar26;
        uVar16 = uVar16 >> 0x10 | uVar16 << 0x10;
        uVar13 = uVar13 >> 0x10 | uVar13 << 0x10;
        uVar24 = uVar24 + uVar22;
        local_c4 = local_c4 + uVar16;
        uVar18 = uVar18 ^ uVar24;
        local_e0 = local_e0 + uVar13;
        uVar18 = uVar18 >> 0x10 | uVar18 << 0x10;
        local_cc = local_cc + uVar21;
        local_48 = local_48 + uVar18;
        uVar19 = uVar19 ^ local_c4;
        uVar1 = uVar1 ^ local_e0;
        uVar23 = uVar23 ^ local_cc;
        uVar23 = uVar23 >> 0x14 | uVar23 << 0xc;
        uVar1 = uVar1 >> 0x14 | uVar1 << 0xc;
        uVar22 = uVar22 ^ local_48;
        uVar22 = uVar22 >> 0x14 | uVar22 << 0xc;
        uVar19 = uVar19 >> 0x14 | uVar19 << 0xc;
        uVar24 = uVar24 + uVar22;
        local_c8 = local_c8 + uVar19;
        uVar18 = uVar18 ^ uVar24;
        local_dc = uVar18 >> 0x18 | uVar18 << 8;
        uVar16 = uVar16 ^ local_c8;
        local_30 = uVar16 >> 0x18 | uVar16 << 8;
        uVar26 = uVar26 + uVar1;
        uVar13 = uVar13 ^ uVar26;
        uVar25 = uVar25 + uVar23;
        local_c4 = local_c4 + local_30;
        local_2c = uVar13 >> 0x18 | uVar13 << 8;
        uVar21 = uVar21 ^ uVar25;
        uVar21 = uVar21 >> 0x18 | uVar21 << 8;
        local_e0 = local_e0 + local_2c;
        local_cc = local_cc + uVar21;
        uVar23 = uVar23 ^ local_cc;
        local_48 = local_48 + local_dc;
        uVar19 = uVar19 ^ local_c4;
        uVar22 = uVar22 ^ local_48;
        local_4c = uVar22 >> 0x19 | uVar22 << 7;
        local_58 = uVar19 >> 0x19 | uVar19 << 7;
        local_50 = uVar23 >> 0x19 | uVar23 << 7;
        local_c0 = local_c0 + -1;
        uVar1 = uVar1 ^ local_e0;
        local_54 = uVar1 >> 0x19 | uVar1 << 7;
      } while (local_c0 != 0);
      local_58 = uVar3 + local_58;
      local_54 = uVar4 + local_54;
      local_50 = local_50 + uVar5;
      local_4c = local_4c + uVar6;
      local_48 = local_48 + uVar7;
      local_44 = local_c4 + uVar8;
      local_40 = local_e0 + uVar9;
      local_68 = uVar26 + 0x61707865;
      local_60 = uVar24 + 0x79622d32;
      local_3c = local_cc + uVar17;
      local_5c = local_c8 + 0x6b206574;
      local_34 = local_dc + uVar10;
      local_30 = uVar11 + local_30;
      local_64 = uVar25 + 0x3320646e;
      local_2c = uVar12 + local_2c;
      local_38 = uVar21 + local_b4;
      if (local_ac < 6 ||
          ((((uint)local_b8 | (uint)local_bc) & 3) != 0 ||
          local_bc < local_b8 + 1 && local_b8 < local_bc + 1)) {
        pbVar20 = &bStack_69;
        pbVar15 = (byte *)((int)local_bc + -1);
        pbVar2 = (byte *)((int)local_b8 + -1);
        do {
          pbVar15 = pbVar15 + 1;
          pbVar20 = pbVar20 + 1;
          pbVar2 = pbVar2 + 1;
          *pbVar2 = *pbVar15 ^ *pbVar20;
        } while ((byte *)((local_ac - 1) + (int)local_bc) != pbVar15);
      }
      else {
        iVar14 = (local_ac - 4 >> 2) + 1;
        uVar16 = iVar14 * 4;
        *local_b8 = *local_bc ^ uVar26 + 0x61707865;
        if (((((iVar14 != 1) && (local_b8[1] = local_bc[1] ^ uVar25 + 0x3320646e, iVar14 != 2)) &&
             (local_b8[2] = local_bc[2] ^ uVar24 + 0x79622d32, iVar14 != 3)) &&
            (((local_b8[3] = local_bc[3] ^ local_c8 + 0x6b206574, iVar14 != 4 &&
              (local_b8[4] = local_bc[4] ^ local_58, iVar14 != 5)) &&
             ((local_b8[5] = local_bc[5] ^ local_54, iVar14 != 6 &&
              ((local_b8[6] = local_50 ^ local_bc[6], iVar14 != 7 &&
               (local_b8[7] = local_bc[7] ^ local_4c, iVar14 != 8)))))))) &&
           ((local_b8[8] = local_bc[8] ^ local_48, iVar14 != 9 &&
            (((((local_b8[9] = local_bc[9] ^ local_44, iVar14 != 10 &&
                (local_b8[10] = local_bc[10] ^ local_40, iVar14 != 0xb)) &&
               (local_b8[0xb] = local_bc[0xb] ^ local_3c, iVar14 != 0xc)) &&
              ((local_b8[0xc] = local_bc[0xc] ^ uVar21 + local_b4, iVar14 != 0xd &&
               (local_b8[0xd] = local_bc[0xd] ^ local_34, iVar14 != 0xe)))) &&
             (local_b8[0xe] = local_bc[0xe] ^ local_30, iVar14 == 0x10)))))) {
          local_b8[0xf] = local_bc[0xf] ^ local_2c;
        }
        if (local_ac != uVar16) {
          uVar21 = uVar16 + 1;
          *(byte *)(local_b8 + iVar14) = *(byte *)(&local_68 + iVar14) ^ (byte)local_bc[iVar14];
          if (uVar21 < local_ac) {
            uVar24 = uVar16 + 2;
            *(byte *)((int)local_b8 + uVar21) =
                 *(byte *)((int)&local_68 + uVar16 + 1) ^ *(byte *)((int)local_bc + uVar21);
            if (uVar24 < local_ac) {
              *(byte *)((int)local_b8 + uVar24) =
                   *(byte *)((int)&local_68 + uVar16 + 2) ^ *(byte *)((int)local_bc + uVar24);
            }
          }
        }
      }
      local_b8 = (uint *)((int)local_b8 + local_ac);
      local_bc = (uint *)((int)local_bc + local_ac);
      local_b4 = local_b4 + 1;
      local_ac = local_a8;
    } while (local_a8 != 0);
  }
  return;
}



void sha256_block_data_order(uint *param_1,byte *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint local_cc;
  uint local_c8;
  uint local_c4;
  uint local_c0;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  int local_ac;
  uint local_a8;
  byte *local_a4;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_8c;
  uint local_88;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  int local_68;
  uint local_60 [4];
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
  uint local_28;
  uint local_24;
  
  if (param_3 != 0) {
    local_80 = param_1[1];
    local_88 = *param_1;
    local_78 = param_1[2];
    local_6c = param_1[3];
    local_8c = param_1[4];
    local_7c = param_1[5];
    local_74 = param_1[6];
    local_70 = param_1[7];
    local_a4 = param_2;
    local_68 = param_3;
    do {
      local_60[0] = (uint)local_a4[1] << 0x10 | (uint)*local_a4 << 0x18 | (uint)local_a4[3] |
                    (uint)local_a4[2] << 8;
      iVar8 = local_70 + 0x428a2f98 +
              ((local_8c >> 6 | local_8c << 0x1a) ^ (local_8c >> 0xb | local_8c << 0x15) ^
              (local_8c >> 0x19 | local_8c << 7)) + (local_7c & local_8c ^ local_74 & ~local_8c) +
              local_60[0];
      uVar5 = iVar8 + local_6c;
      local_60[1] = (uint)local_a4[5] << 0x10 | (uint)local_a4[4] << 0x18 | (uint)local_a4[7] |
                    (uint)local_a4[6] << 8;
      iVar1 = local_74 + 0x71374491 + local_60[1] +
              ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80)) + (uVar5 & local_8c ^ local_7c & ~uVar5);
      uVar2 = iVar1 + local_78;
      local_60[2] = (uint)local_a4[9] << 0x10 | (uint)local_a4[8] << 0x18 | (uint)local_a4[0xb] |
                    (uint)local_a4[10] << 8;
      uVar9 = (local_78 & local_88 ^ local_80 & local_88 ^ local_78 & local_80) +
              ((local_88 >> 2 | local_88 << 0x1e) ^ (local_88 >> 0xd | local_88 << 0x13) ^
              (local_88 >> 0x16 | local_88 << 10)) + iVar8;
      iVar8 = local_7c + 0xb5c0fbcf + local_60[2] +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80)) + (uVar2 & uVar5 ^ local_8c & ~uVar2);
      uVar3 = iVar8 + local_80;
      local_60[3] = (uint)local_a4[0xd] << 0x10 | (uint)local_a4[0xc] << 0x18 | (uint)local_a4[0xf]
                    | (uint)local_a4[0xe] << 8;
      uVar4 = (uVar9 & local_80 ^ uVar9 & local_88 ^ local_80 & local_88) +
              ((uVar9 >> 2 | uVar9 * 0x40000000) ^ (uVar9 >> 0xd | uVar9 * 0x80000) ^
              (uVar9 >> 0x16 | uVar9 * 0x400)) + iVar1;
      iVar7 = local_8c + 0xe9b5dba5 + local_60[3] +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80)) + (uVar3 & uVar2 ^ uVar5 & ~uVar3);
      local_50 = (uint)local_a4[0x11] << 0x10 | (uint)local_a4[0x10] << 0x18 | (uint)local_a4[0x13]
                 | (uint)local_a4[0x12] << 8;
      uVar11 = iVar7 + local_88;
      uVar12 = (uVar4 & uVar9 ^ uVar4 & local_88 ^ uVar9 & local_88) +
               ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
               (uVar4 >> 0x16 | uVar4 * 0x400)) + iVar8;
      iVar1 = local_50 + 0x3956c25b + uVar5 +
              ((uVar11 >> 6 | uVar11 * 0x4000000) ^ (uVar11 >> 0xb | uVar11 * 0x200000) ^
              (uVar11 >> 0x19 | uVar11 * 0x80)) + (uVar2 & ~uVar11 ^ uVar11 & uVar3);
      uVar10 = uVar9 + iVar1;
      local_4c = (uint)local_a4[0x15] << 0x10 | (uint)local_a4[0x14] << 0x18 | (uint)local_a4[0x17]
                 | (uint)local_a4[0x16] << 8;
      uVar6 = (uVar4 & uVar9 ^ uVar12 & uVar9 ^ uVar12 & uVar4) +
              ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^
              (uVar12 >> 0x16 | uVar12 * 0x400)) + iVar7;
      iVar8 = local_4c + 0x59f111f1 + uVar2 +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + (uVar3 & ~uVar10 ^ uVar10 & uVar11);
      uVar2 = uVar4 + iVar8;
      local_48 = (uint)local_a4[0x19] << 0x10 | (uint)local_a4[0x18] << 0x18 | (uint)local_a4[0x1b]
                 | (uint)local_a4[0x1a] << 8;
      uVar5 = (uVar6 & uVar4 ^ uVar6 & uVar12 ^ uVar12 & uVar4) +
              ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
              (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar1;
      iVar1 = local_48 + 0x923f82a4 + uVar3 +
              ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80)) + (uVar11 & ~uVar2 ^ uVar2 & uVar10);
      uVar13 = uVar12 + iVar1;
      local_44 = (uint)local_a4[0x1d] << 0x10 | (uint)local_a4[0x1c] << 0x18 | (uint)local_a4[0x1f]
                 | (uint)local_a4[0x1e] << 8;
      uVar4 = (uVar5 & uVar6 ^ uVar5 & uVar12 ^ uVar6 & uVar12) +
              ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
              (uVar5 >> 0x16 | uVar5 * 0x400)) + iVar8;
      uVar3 = (uVar4 & uVar5 ^ uVar4 & uVar6 ^ uVar5 & uVar6) +
              ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^
              (uVar4 >> 0x16 | uVar4 * 0x400)) + iVar1;
      iVar1 = (uVar10 & ~uVar13 ^ uVar13 & uVar2) +
              local_44 + 0xab1c5ed5 + uVar11 +
              ((uVar13 >> 6 | uVar13 * 0x4000000) ^ (uVar13 >> 0xb | uVar13 * 0x200000) ^
              (uVar13 >> 0x19 | uVar13 * 0x80));
      uVar6 = iVar1 + uVar6;
      local_40 = (uint)local_a4[0x21] << 0x10 | (uint)local_a4[0x20] << 0x18 | (uint)local_a4[0x23]
                 | (uint)local_a4[0x22] << 8;
      iVar8 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80)) + local_40 + 0xd807aa98 + uVar10 +
              (uVar2 & ~uVar6 ^ uVar6 & uVar13);
      uVar9 = uVar5 + iVar8;
      uVar10 = ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^
               (uVar3 >> 0x16 | uVar3 * 0x400)) + (uVar3 & uVar4 ^ uVar3 & uVar5 ^ uVar4 & uVar5) +
               iVar1;
      local_3c = (uint)local_a4[0x27] | (uint)local_a4[0x25] << 0x10 | (uint)local_a4[0x24] << 0x18
                 | (uint)local_a4[0x26] << 8;
      local_c0 = (uVar10 & uVar3 ^ uVar10 & uVar4 ^ uVar3 & uVar4) +
                 ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^
                 (uVar10 >> 0x16 | uVar10 * 0x400)) + iVar8;
      iVar1 = local_3c + 0x12835b01 + uVar2 +
              ((uVar9 >> 6 | uVar9 * 0x4000000) ^ (uVar9 >> 0xb | uVar9 * 0x200000) ^
              (uVar9 >> 0x19 | uVar9 * 0x80)) + (uVar13 & ~uVar9 ^ uVar9 & uVar6);
      uVar4 = iVar1 + uVar4;
      local_38 = (uint)local_a4[0x29] << 0x10 | (uint)local_a4[0x28] << 0x18 | (uint)local_a4[0x2b]
                 | (uint)local_a4[0x2a] << 8;
      local_c4 = (local_c0 & uVar10 ^ local_c0 & uVar3 ^ uVar10 & uVar3) +
                 ((local_c0 >> 2 | local_c0 * 0x40000000) ^ (local_c0 >> 0xd | local_c0 * 0x80000) ^
                 (local_c0 >> 0x16 | local_c0 * 0x400)) + iVar1;
      iVar1 = (uVar4 & uVar9 ^ uVar6 & ~uVar4) +
              local_38 + 0x243185be + uVar13 +
              ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^
              (uVar4 >> 0x19 | uVar4 * 0x80));
      uVar3 = iVar1 + uVar3;
      local_34 = (uint)local_a4[0x2f] | (uint)local_a4[0x2d] << 0x10 | (uint)local_a4[0x2c] << 0x18
                 | (uint)local_a4[0x2e] << 8;
      uVar5 = ((local_c4 >> 2 | local_c4 * 0x40000000) ^ (local_c4 >> 0xd | local_c4 * 0x80000) ^
              (local_c4 >> 0x16 | local_c4 * 0x400)) +
              (local_c4 & local_c0 ^ local_c4 & uVar10 ^ local_c0 & uVar10) + iVar1;
      iVar1 = (uVar9 & ~uVar3 ^ uVar3 & uVar4) +
              local_34 + 0x550c7dc3 + uVar6 +
              ((uVar3 >> 6 | uVar3 * 0x4000000) ^ (uVar3 >> 0xb | uVar3 * 0x200000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar10 = uVar10 + iVar1;
      uVar6 = ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
              (uVar5 >> 0x16 | uVar5 * 0x400)) +
              (uVar5 & local_c4 ^ uVar5 & local_c0 ^ local_c4 & local_c0) + iVar1;
      local_30 = (uint)local_a4[0x31] << 0x10 | (uint)local_a4[0x30] << 0x18 | (uint)local_a4[0x33]
                 | (uint)local_a4[0x32] << 8;
      iVar1 = local_30 + 0x72be5d74 + uVar9 +
              ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + (uVar4 & ~uVar10 ^ uVar10 & uVar3);
      local_c0 = iVar1 + local_c0;
      local_2c = (uint)local_a4[0x35] << 0x10 | (uint)local_a4[0x34] << 0x18 | (uint)local_a4[0x37]
                 | (uint)local_a4[0x36] << 8;
      local_c8 = (uVar6 & local_c4 ^ uVar6 & uVar5 ^ uVar5 & local_c4) +
                 ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                 (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar1;
      iVar1 = local_2c + 0x80deb1fe + uVar4 +
              ((local_c0 >> 6 | local_c0 * 0x4000000) ^ (local_c0 >> 0xb | local_c0 * 0x200000) ^
              (local_c0 >> 0x19 | local_c0 * 0x80)) + (uVar3 & ~local_c0 ^ local_c0 & uVar10);
      local_c4 = iVar1 + local_c4;
      local_b4 = (uVar6 & uVar5 ^ local_c8 & uVar5 ^ local_c8 & uVar6) +
                 ((local_c8 >> 2 | local_c8 * 0x40000000) ^ (local_c8 >> 0xd | local_c8 * 0x80000) ^
                 (local_c8 >> 0x16 | local_c8 * 0x400)) + iVar1;
      local_28 = (uint)local_a4[0x39] << 0x10 | (uint)local_a4[0x38] << 0x18 | (uint)local_a4[0x3b]
                 | (uint)local_a4[0x3a] << 8;
      iVar1 = (local_c4 & local_c0 ^ uVar10 & ~local_c4) +
              local_28 + 0x9bdc06a7 + uVar3 +
              ((local_c4 >> 6 | local_c4 * 0x4000000) ^ (local_c4 >> 0xb | local_c4 * 0x200000) ^
              (local_c4 >> 0x19 | local_c4 * 0x80));
      uVar5 = iVar1 + uVar5;
      local_b8 = (local_c8 & uVar6 ^ local_b4 & uVar6 ^ local_b4 & local_c8) +
                 ((local_b4 >> 2 | local_b4 * 0x40000000) ^ (local_b4 >> 0xd | local_b4 * 0x80000) ^
                 (local_b4 >> 0x16 | local_b4 * 0x400)) + iVar1;
      local_24 = (uint)local_a4[0x3d] << 0x10 | (uint)local_a4[0x3c] << 0x18 | (uint)local_a4[0x3f]
                 | (uint)local_a4[0x3e] << 8;
      local_a8 = local_b4 & local_b8;
      local_ac = DAT_000907f8;
      iVar1 = local_24 + 0xc19bf174 + uVar10 +
              ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80)) + (uVar5 & local_c4 ^ local_c0 & ~uVar5);
      local_b0 = (local_b8 & local_c8 ^ local_a8 ^ local_b4 & local_c8) +
                 ((local_b8 >> 2 | local_b8 * 0x40000000) ^ (local_b8 >> 0xd | local_b8 * 0x80000) ^
                 (local_b8 >> 0x16 | local_b8 * 0x400)) + iVar1;
      uVar6 = uVar6 + iVar1;
      local_a4 = local_a4 + 0x40;
      local_94 = 0;
      uVar2 = 0x11;
      local_9c = 0x1e;
      local_98 = 0x1d;
      local_cc = 0x10;
      while( true ) {
        iVar1 = *(int *)(local_ac + 0x40);
        uVar12 = local_cc + 0xf & 0xf;
        uVar3 = local_cc + 2 & 0xf;
        uVar11 = ((local_28 >> 0x11 | local_28 << 0xf) ^ (local_28 >> 0x13 | local_28 << 0xd) ^
                 local_28 >> 10) +
                 ((local_60[1] >> 7 | local_60[1] << 0x19) ^
                  (local_60[1] >> 0x12 | local_60[1] << 0xe) ^ local_60[1] >> 3) + local_60[0] +
                 local_3c;
        local_60[local_94] = uVar11;
        uVar9 = local_60[uVar12];
        uVar4 = local_60[uVar3];
        uVar10 = local_60[local_cc + 10 & 0xf] + local_60[uVar2 & 0xf] +
                 ((uVar4 >> 7 | uVar4 << 0x19) ^ (uVar4 >> 0x12 | uVar4 << 0xe) ^ uVar4 >> 3) +
                 ((uVar9 >> 0x11 | uVar9 << 0xf) ^ (uVar9 >> 0x13 | uVar9 << 0xd) ^ uVar9 >> 10);
        iVar1 = (local_c4 & ~uVar6 ^ uVar5 & uVar6) +
                ((uVar6 >> 6 | uVar6 << 0x1a) ^ (uVar6 >> 0xb | uVar6 << 0x15) ^
                (uVar6 >> 0x19 | uVar6 << 7)) + iVar1 + uVar11 + local_c0;
        local_60[uVar2 & 0xf] = uVar10;
        uVar2 = local_60[local_94];
        uVar4 = local_cc + 3 & 0xf;
        local_c8 = local_c8 + iVar1;
        uVar9 = local_60[uVar4];
        local_c0 = ((local_b0 >> 2 | local_b0 << 0x1e) ^ (local_b0 >> 0xd | local_b0 << 0x13) ^
                   (local_b0 >> 0x16 | local_b0 << 10)) +
                   (local_b4 & local_b0 ^ local_b8 & local_b0 ^ local_a8) + iVar1;
        uVar11 = ((uVar9 >> 7 | uVar9 << 0x19) ^ (uVar9 >> 0x12 | uVar9 << 0xe) ^ uVar9 >> 3) +
                 local_60[uVar3] + local_60[local_cc + 0xb & 0xf] +
                 ((uVar2 >> 0x11 | uVar2 << 0xf) ^ (uVar2 >> 0x13 | uVar2 << 0xd) ^ uVar2 >> 10);
        local_60[uVar3] = uVar11;
        uVar9 = local_cc + 4 & 0xf;
        uVar2 = local_60[local_cc + 0x11 & 0xf];
        uVar3 = local_60[uVar9];
        iVar1 = local_c4 + *(int *)(local_ac + 0x44) + uVar10 +
                ((local_c8 >> 6 | local_c8 * 0x4000000) ^ (local_c8 >> 0xb | local_c8 * 0x200000) ^
                (local_c8 >> 0x19 | local_c8 * 0x80)) + (uVar5 & ~local_c8 ^ local_c8 & uVar6);
        local_c4 = ((local_c0 >> 2 | local_c0 * 0x40000000) ^ (local_c0 >> 0xd | local_c0 * 0x80000)
                   ^ (local_c0 >> 0x16 | local_c0 * 0x400)) +
                   (local_c0 & local_b0 ^ local_c0 & local_b8 ^ local_b8 & local_b0) + iVar1;
        local_b4 = iVar1 + local_b4;
        uVar2 = ((uVar2 >> 0x11 | uVar2 << 0xf) ^ (uVar2 >> 0x13 | uVar2 << 0xd) ^ uVar2 >> 10) +
                ((uVar3 >> 7 | uVar3 << 0x19) ^ (uVar3 >> 0x12 | uVar3 << 0xe) ^
                local_60[uVar9] >> 3) + local_60[local_cc + 0xc & 0xf] + local_60[uVar4];
        uVar10 = local_cc + 5 & 0xf;
        local_60[uVar4] = uVar2;
        uVar4 = local_60[local_cc + 0x12 & 0xf];
        uVar3 = local_60[uVar10];
        iVar1 = (uVar6 & ~local_b4 ^ local_b4 & local_c8) +
                uVar11 + uVar5 + *(int *)(local_ac + 0x48) +
                ((local_b4 >> 6 | local_b4 * 0x4000000) ^ (local_b4 >> 0xb | local_b4 * 0x200000) ^
                (local_b4 >> 0x19 | local_b4 * 0x80));
        local_b8 = iVar1 + local_b8;
        uVar5 = (local_c4 & local_c0 ^ local_c4 & local_b0 ^ local_c0 & local_b0) +
                ((local_c4 >> 2 | local_c4 * 0x40000000) ^ (local_c4 >> 0xd | local_c4 * 0x80000) ^
                (local_c4 >> 0x16 | local_c4 * 0x400)) + iVar1;
        uVar11 = local_cc + 6 & 0xf;
        uVar3 = ((uVar4 >> 0x11 | uVar4 << 0xf) ^ (uVar4 >> 0x13 | uVar4 << 0xd) ^ uVar4 >> 10) +
                ((uVar3 >> 7 | uVar3 << 0x19) ^ (uVar3 >> 0x12 | uVar3 << 0xe) ^ uVar3 >> 3) +
                local_60[local_98 & 0xf] + local_60[uVar9];
        local_60[uVar9] = uVar3;
        uVar4 = local_60[local_cc + 0x13 & 0xf];
        uVar9 = local_60[uVar11];
        iVar1 = uVar6 + *(int *)(local_ac + 0x4c) + uVar2 +
                ((local_b8 >> 6 | local_b8 * 0x4000000) ^ (local_b8 >> 0xb | local_b8 * 0x200000) ^
                (local_b8 >> 0x19 | local_b8 * 0x80)) + (local_c8 & ~local_b8 ^ local_b8 & local_b4)
        ;
        local_b0 = iVar1 + local_b0;
        uVar6 = iVar1 + (uVar5 & local_c4 ^ uVar5 & local_c0 ^ local_c4 & local_c0) +
                        ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^
                        (uVar5 >> 0x16 | uVar5 * 0x400));
        iVar1 = *(int *)(local_ac + 0x50);
        uVar13 = local_cc + 7 & 0xf;
        uVar4 = local_60[local_9c & 0xf] + local_60[uVar10] +
                ((uVar9 >> 7 | uVar9 << 0x19) ^ (uVar9 >> 0x12 | uVar9 << 0xe) ^ uVar9 >> 3) +
                ((uVar4 >> 0x11 | uVar4 << 0xf) ^ (uVar4 >> 0x13 | uVar4 << 0xd) ^ uVar4 >> 10);
        local_60[uVar10] = uVar4;
        uVar2 = local_60[local_cc + 0x14 & 0xf];
        iVar1 = ((local_b0 >> 6 | local_b0 * 0x4000000) ^ (local_b0 >> 0xb | local_b0 * 0x200000) ^
                (local_b0 >> 0x19 | local_b0 * 0x80)) + local_c8 + iVar1 + uVar3 +
                (local_b4 & ~local_b0 ^ local_b0 & local_b8);
        uVar3 = local_60[uVar13];
        local_c0 = local_c0 + iVar1;
        local_c8 = (uVar6 & uVar5 ^ uVar6 & local_c4 ^ uVar5 & local_c4) +
                   ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^
                   (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar1;
        uVar9 = local_cc + 8;
        iVar1 = uVar4 + *(int *)(local_ac + 0x54) + local_b4 +
                ((local_c0 >> 6 | local_c0 * 0x4000000) ^ (local_c0 >> 0xb | local_c0 * 0x200000) ^
                (local_c0 >> 0x19 | local_c0 * 0x80)) + (local_b8 & ~local_c0 ^ local_c0 & local_b0)
        ;
        uVar4 = uVar9 & 0xf;
        uVar3 = local_60[uVar12] + local_60[uVar11] +
                ((uVar3 >> 7 | uVar3 << 0x19) ^ (uVar3 >> 0x12 | uVar3 << 0xe) ^ uVar3 >> 3) +
                ((uVar2 >> 0x11 | uVar2 << 0xf) ^ (uVar2 >> 0x13 | uVar2 << 0xd) ^ uVar2 >> 10);
        local_98 = local_cc + 0x15;
        local_60[uVar11] = uVar3;
        local_b4 = ((local_c8 >> 2 | local_c8 * 0x40000000) ^ (local_c8 >> 0xd | local_c8 * 0x80000)
                   ^ (local_c8 >> 0x16 | local_c8 * 0x400)) +
                   (local_c8 & uVar6 ^ local_c8 & uVar5 ^ uVar6 & uVar5) + iVar1;
        local_c4 = local_c4 + iVar1;
        uVar10 = local_60[uVar4];
        uVar2 = local_60[local_98 & 0xf];
        iVar1 = uVar3 + *(int *)(local_ac + 0x58) + local_b8 +
                ((local_c4 >> 6 | local_c4 * 0x4000000) ^ (local_c4 >> 0xb | local_c4 * 0x200000) ^
                (local_c4 >> 0x19 | local_c4 * 0x80)) + (local_b0 & ~local_c4 ^ local_c4 & local_c0)
        ;
        uVar5 = iVar1 + uVar5;
        local_b8 = (local_b4 & uVar6 ^ local_b4 & local_c8 ^ local_c8 & uVar6) +
                   ((local_b4 >> 2 | local_b4 * 0x40000000) ^ (local_b4 >> 0xd | local_b4 * 0x80000)
                   ^ (local_b4 >> 0x16 | local_b4 * 0x400)) + iVar1;
        local_a8 = local_b8 & local_b4;
        uVar2 = ((uVar10 >> 7 | uVar10 << 0x19) ^ (uVar10 >> 0x12 | uVar10 << 0xe) ^ uVar10 >> 3) +
                local_60[uVar13] + local_60[local_94] +
                ((uVar2 >> 0x11 | uVar2 << 0xf) ^ (uVar2 >> 0x13 | uVar2 << 0xd) ^ uVar2 >> 10);
        iVar1 = *(int *)(local_ac + 0x5c);
        local_60[uVar13] = uVar2;
        iVar1 = uVar2 + iVar1 + local_b0 +
                ((uVar5 >> 6 | uVar5 * 0x4000000) ^ (uVar5 >> 0xb | uVar5 * 0x200000) ^
                (uVar5 >> 0x19 | uVar5 * 0x80)) + (local_c0 & ~uVar5 ^ uVar5 & local_c4);
        uVar6 = uVar6 + iVar1;
        local_b0 = (local_b8 & local_c8 ^ local_a8 ^ local_b4 & local_c8) +
                   ((local_b8 >> 2 | local_b8 * 0x40000000) ^ (local_b8 >> 0xd | local_b8 * 0x80000)
                   ^ (local_b8 >> 0x16 | local_b8 * 0x400)) + iVar1;
        HintPreloadData(&DAT_00156a50 + (local_cc + 7) * 4);
        local_ac = local_ac + 0x20;
        if (uVar9 == 0x40) break;
        local_9c = local_cc + 0x16;
        uVar2 = local_cc + 9;
        local_60[0] = local_60[uVar4];
        local_60[1] = local_60[uVar2 & 0xf];
        local_28 = local_60[local_9c & 0xf];
        local_3c = local_60[local_cc + 0x11 & 0xf];
        local_cc = uVar9;
        local_94 = uVar4;
      }
      local_88 = local_b0 + local_88;
      local_80 = local_b8 + local_80;
      local_78 = local_b4 + local_78;
      local_6c = local_6c + local_c8;
      local_8c = uVar6 + local_8c;
      local_7c = local_7c + uVar5;
      local_74 = local_c4 + local_74;
      local_70 = local_70 + local_c0;
      *param_1 = local_88;
      param_1[1] = local_80;
      param_1[2] = local_78;
      param_1[3] = local_6c;
      param_1[4] = local_8c;
      param_1[5] = local_7c;
      param_1[6] = local_74;
      param_1[7] = local_70;
      local_68 = local_68 + -1;
    } while (local_68 != 0);
  }
  return;
}


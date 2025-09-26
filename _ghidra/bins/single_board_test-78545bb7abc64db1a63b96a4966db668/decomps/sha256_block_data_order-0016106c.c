
void sha256_block_data_order(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint local_f4;
  undefined1 *local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  uint local_dc;
  uint local_d8;
  int local_d4;
  uint local_c4;
  uint local_c0;
  uint local_bc;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  int local_98;
  uint local_94;
  uint local_68 [4];
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
  
  local_98 = param_3 + -1;
  if (param_3 != 0) {
    local_b4 = *param_1;
    local_d4 = param_2 + 0x40;
    local_a0 = param_1[1];
    local_ac = param_1[2];
    local_94 = param_1[3];
    local_b0 = param_1[4];
    local_a8 = param_1[5];
    local_a4 = param_1[6];
    local_9c = param_1[7];
    do {
      local_68[0] = (uint)*(byte *)(local_d4 + -0x3f) << 0x10 |
                    (uint)*(byte *)(local_d4 + -0x40) << 0x18 | (uint)*(byte *)(local_d4 + -0x3d) |
                    (uint)*(byte *)(local_d4 + -0x3e) << 8;
      iVar4 = local_9c + 0x428a2f98 +
              ((local_b0 >> 0xb | local_b0 << 0x15) ^ (local_b0 >> 6 | local_b0 << 0x1a) ^
              (local_b0 >> 0x19 | local_b0 << 7)) + (local_a4 & ~local_b0 ^ local_b0 & local_a8) +
              local_68[0];
      uVar2 = iVar4 + local_94;
      local_68[1] = (uint)*(byte *)(local_d4 + -0x3b) << 0x10 |
                    (uint)*(byte *)(local_d4 + -0x3c) << 0x18 | (uint)*(byte *)(local_d4 + -0x39) |
                    (uint)*(byte *)(local_d4 + -0x3a) << 8;
      local_68[2] = (uint)*(byte *)(local_d4 + -0x37) << 0x10 |
                    (uint)*(byte *)(local_d4 + -0x38) << 0x18 | (uint)*(byte *)(local_d4 + -0x35) |
                    (uint)*(byte *)(local_d4 + -0x36) << 8;
      iVar13 = local_a4 + 0x71374491 + local_68[1] +
               ((uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 6 | uVar2 * 0x4000000) ^
               (uVar2 >> 0x19 | uVar2 * 0x80)) + (local_a8 & ~uVar2 ^ uVar2 & local_b0);
      uVar10 = iVar13 + local_ac;
      uVar1 = (local_ac & local_a0 ^ local_ac & local_b4 ^ local_b4 & local_a0) +
              ((local_b4 >> 0xd | local_b4 << 0x13) ^ (local_b4 >> 2 | local_b4 << 0x1e) ^
              (local_b4 >> 0x16 | local_b4 << 10)) + iVar4;
      iVar4 = local_a8 + 0xb5c0fbcf + local_68[2] +
              ((uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 6 | uVar10 * 0x4000000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + (uVar2 & uVar10 ^ local_b0 & ~uVar10);
      uVar3 = iVar4 + local_a0;
      local_68[3] = (uint)*(byte *)(local_d4 + -0x33) << 0x10 |
                    (uint)*(byte *)(local_d4 + -0x34) << 0x18 | (uint)*(byte *)(local_d4 + -0x31) |
                    (uint)*(byte *)(local_d4 + -0x32) << 8;
      uVar6 = ((local_a0 ^ local_b4) & uVar1 ^ local_b4 & local_a0) +
              ((uVar1 >> 0xd | uVar1 * 0x80000) ^ (uVar1 >> 2 | uVar1 * 0x40000000) ^
              (uVar1 >> 0x16 | uVar1 * 0x400)) + iVar13;
      iVar13 = (uVar2 & ~uVar3 ^ uVar10 & uVar3) +
               local_b0 + 0xe9b5dba5 + local_68[3] +
               ((uVar3 >> 0xb | uVar3 * 0x200000) ^ (uVar3 >> 6 | uVar3 * 0x4000000) ^
               (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar14 = iVar13 + local_b4;
      local_58 = (uint)*(byte *)(local_d4 + -0x2d) |
                 (uint)*(byte *)(local_d4 + -0x2f) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x30) << 0x18 | (uint)*(byte *)(local_d4 + -0x2e) << 8;
      uVar7 = ((uVar1 ^ local_b4) & uVar6 ^ uVar1 & local_b4) +
              ((uVar6 >> 0xd | uVar6 * 0x80000) ^ (uVar6 >> 2 | uVar6 * 0x40000000) ^
              (uVar6 >> 0x16 | uVar6 * 0x400)) + iVar4;
      iVar4 = uVar2 + local_58 + 0x3956c25b +
              ((uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 6 | uVar14 * 0x4000000) ^
              (uVar14 >> 0x19 | uVar14 * 0x80)) + (uVar10 & ~uVar14 ^ uVar3 & uVar14);
      HintPreloadData(local_d4 + 1);
      HintPreloadData(local_d4 + 2);
      HintPreloadData(local_d4 + 3);
      HintPreloadData(local_d4);
      uVar5 = ((uVar7 >> 0xd | uVar7 * 0x80000) ^ (uVar7 >> 2 | uVar7 * 0x40000000) ^
              (uVar7 >> 0x16 | uVar7 * 0x400)) + ((uVar1 ^ uVar6) & uVar7 ^ uVar1 & uVar6) + iVar13;
      local_54 = (uint)*(byte *)(local_d4 + -0x2b) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x2c) << 0x18 | (uint)*(byte *)(local_d4 + -0x29) |
                 (uint)*(byte *)(local_d4 + -0x2a) << 8;
      uVar1 = uVar1 + iVar4;
      iVar13 = local_54 + 0x59f111f1 + uVar10 +
               ((uVar1 >> 0xb | uVar1 * 0x200000) ^ (uVar1 >> 6 | uVar1 * 0x4000000) ^
               (uVar1 >> 0x19 | uVar1 * 0x80)) + (uVar3 & ~uVar1 ^ uVar14 & uVar1);
      uVar10 = ((uVar6 ^ uVar7) & uVar5 ^ uVar6 & uVar7) +
               ((uVar5 >> 0xd | uVar5 * 0x80000) ^ (uVar5 >> 2 | uVar5 * 0x40000000) ^
               (uVar5 >> 0x16 | uVar5 * 0x400)) + iVar4;
      local_50 = (uint)*(byte *)(local_d4 + -0x27) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x28) << 0x18 | (uint)*(byte *)(local_d4 + -0x25) |
                 (uint)*(byte *)(local_d4 + -0x26) << 8;
      uVar6 = uVar6 + iVar13;
      iVar4 = uVar3 + local_50 + 0x923f82a4 +
              ((uVar6 >> 0xb | uVar6 * 0x200000) ^ (uVar6 >> 6 | uVar6 * 0x4000000) ^
              (uVar6 >> 0x19 | uVar6 * 0x80)) + (uVar14 & ~uVar6 ^ uVar1 & uVar6);
      uVar8 = uVar7 + iVar4;
      uVar2 = iVar13 + ((uVar7 ^ uVar5) & uVar10 ^ uVar7 & uVar5) +
                       ((uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 2 | uVar10 * 0x40000000) ^
                       (uVar10 >> 0x16 | uVar10 * 0x400));
      local_4c = (uint)*(byte *)(local_d4 + -0x23) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x24) << 0x18 | (uint)*(byte *)(local_d4 + -0x21) |
                 (uint)*(byte *)(local_d4 + -0x22) << 8;
      uVar3 = iVar4 + ((uVar2 >> 0xd | uVar2 * 0x80000) ^ (uVar2 >> 2 | uVar2 * 0x40000000) ^
                      (uVar2 >> 0x16 | uVar2 * 0x400)) + ((uVar5 ^ uVar10) & uVar2 ^ uVar10 & uVar5)
      ;
      iVar4 = (uVar1 & ~uVar8 ^ uVar8 & uVar6) +
              local_4c + 0xab1c5ed5 + uVar14 +
              ((uVar8 >> 0xb | uVar8 * 0x200000) ^ (uVar8 >> 6 | uVar8 * 0x4000000) ^
              (uVar8 >> 0x19 | uVar8 * 0x80));
      uVar5 = uVar5 + iVar4;
      local_48 = (uint)*(byte *)(local_d4 + -0x1f) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x20) << 0x18 | (uint)*(byte *)(local_d4 + -0x1d) |
                 (uint)*(byte *)(local_d4 + -0x1e) << 8;
      uVar7 = iVar4 + ((uVar3 >> 0xd | uVar3 * 0x80000) ^ (uVar3 >> 2 | uVar3 * 0x40000000) ^
                      (uVar3 >> 0x16 | uVar3 * 0x400)) + ((uVar10 ^ uVar2) & uVar3 ^ uVar10 & uVar2)
      ;
      iVar4 = (uVar6 & ~uVar5 ^ uVar8 & uVar5) +
              local_48 + 0xd807aa98 + uVar1 +
              ((uVar5 >> 0xb | uVar5 * 0x200000) ^ (uVar5 >> 6 | uVar5 * 0x4000000) ^
              (uVar5 >> 0x19 | uVar5 * 0x80));
      uVar10 = uVar10 + iVar4;
      local_44 = (uint)*(byte *)(local_d4 + -0x1b) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x1c) << 0x18 | (uint)*(byte *)(local_d4 + -0x19) |
                 (uint)*(byte *)(local_d4 + -0x1a) << 8;
      local_ec = ((uVar3 ^ uVar2) & uVar7 ^ uVar2 & uVar3) +
                 ((uVar7 >> 0xd | uVar7 * 0x80000) ^ (uVar7 >> 2 | uVar7 * 0x40000000) ^
                 (uVar7 >> 0x16 | uVar7 * 0x400)) + iVar4;
      iVar4 = uVar6 + local_44 + 0x12835b01 +
              ((uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 6 | uVar10 * 0x4000000) ^
              (uVar10 >> 0x19 | uVar10 * 0x80)) + (uVar8 & ~uVar10 ^ uVar5 & uVar10);
      uVar2 = uVar2 + iVar4;
      local_40 = (uint)*(byte *)(local_d4 + -0x17) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x18) << 0x18 | (uint)*(byte *)(local_d4 + -0x15) |
                 (uint)*(byte *)(local_d4 + -0x16) << 8;
      local_dc = ((uVar3 ^ uVar7) & local_ec ^ uVar3 & uVar7) +
                 ((local_ec >> 0xd | local_ec * 0x80000) ^ (local_ec >> 2 | local_ec * 0x40000000) ^
                 (local_ec >> 0x16 | local_ec * 0x400)) + iVar4;
      iVar4 = (uVar5 & ~uVar2 ^ uVar10 & uVar2) +
              local_40 + 0x243185be + uVar8 +
              ((uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 6 | uVar2 * 0x4000000) ^
              (uVar2 >> 0x19 | uVar2 * 0x80));
      uVar3 = uVar3 + iVar4;
      local_3c = (uint)*(byte *)(local_d4 + -0x13) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x14) << 0x18 | (uint)*(byte *)(local_d4 + -0x11) |
                 (uint)*(byte *)(local_d4 + -0x12) << 8;
      local_d8 = ((local_ec ^ uVar7) & local_dc ^ uVar7 & local_ec) +
                 ((local_dc >> 0xd | local_dc * 0x80000) ^ (local_dc >> 2 | local_dc * 0x40000000) ^
                 (local_dc >> 0x16 | local_dc * 0x400)) + iVar4;
      iVar4 = (uVar10 & ~uVar3 ^ uVar2 & uVar3) +
              local_3c + 0x550c7dc3 + uVar5 +
              ((uVar3 >> 0xb | uVar3 * 0x200000) ^ (uVar3 >> 6 | uVar3 * 0x4000000) ^
              (uVar3 >> 0x19 | uVar3 * 0x80));
      uVar7 = uVar7 + iVar4;
      local_38 = (uint)*(byte *)(local_d4 + -0xf) << 0x10 |
                 (uint)*(byte *)(local_d4 + -0x10) << 0x18 | (uint)*(byte *)(local_d4 + -0xd) |
                 (uint)*(byte *)(local_d4 + -0xe) << 8;
      local_e4 = ((local_ec ^ local_dc) & local_d8 ^ local_ec & local_dc) +
                 ((local_d8 >> 0xd | local_d8 * 0x80000) ^ (local_d8 >> 2 | local_d8 * 0x40000000) ^
                 (local_d8 >> 0x16 | local_d8 * 0x400)) + iVar4;
      iVar4 = (uVar2 & ~uVar7 ^ uVar3 & uVar7) +
              ((uVar7 >> 0xb | uVar7 * 0x200000) ^ (uVar7 >> 6 | uVar7 * 0x4000000) ^
              (uVar7 >> 0x19 | uVar7 * 0x80)) + local_38 + 0x72be5d74 + uVar10;
      local_ec = local_ec + iVar4;
      local_34 = (uint)*(byte *)(local_d4 + -0xb) << 0x10 | (uint)*(byte *)(local_d4 + -0xc) << 0x18
                 | (uint)*(byte *)(local_d4 + -9) | (uint)*(byte *)(local_d4 + -10) << 8;
      uVar5 = iVar4 + ((local_e4 >> 0xd | local_e4 * 0x80000) ^
                       (local_e4 >> 2 | local_e4 * 0x40000000) ^
                      (local_e4 >> 0x16 | local_e4 * 0x400)) +
                      ((local_dc ^ local_d8) & local_e4 ^ local_d8 & local_dc);
      iVar4 = (uVar3 & ~local_ec ^ uVar7 & local_ec) +
              local_34 + 0x80deb1fe + uVar2 +
              ((local_ec >> 0xb | local_ec * 0x200000) ^ (local_ec >> 6 | local_ec * 0x4000000) ^
              (local_ec >> 0x19 | local_ec * 0x80));
      local_dc = local_dc + iVar4;
      local_30 = (uint)*(byte *)(local_d4 + -7) << 0x10 | (uint)*(byte *)(local_d4 + -8) << 0x18 |
                 (uint)*(byte *)(local_d4 + -5) | (uint)*(byte *)(local_d4 + -6) << 8;
      uVar10 = iVar4 + ((local_d8 ^ local_e4) & uVar5 ^ local_d8 & local_e4) +
                       ((uVar5 >> 0xd | uVar5 * 0x80000) ^ (uVar5 >> 2 | uVar5 * 0x40000000) ^
                       (uVar5 >> 0x16 | uVar5 * 0x400));
      iVar4 = (local_ec & local_dc ^ uVar7 & ~local_dc) +
              uVar3 + local_30 + 0x9bdc06a7 +
              ((local_dc >> 0xb | local_dc * 0x200000) ^ (local_dc >> 6 | local_dc * 0x4000000) ^
              (local_dc >> 0x19 | local_dc * 0x80));
      local_e8 = iVar4 + ((local_e4 ^ uVar5) & uVar10 ^ local_e4 & uVar5) +
                         ((uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 2 | uVar10 * 0x40000000) ^
                         (uVar10 >> 0x16 | uVar10 * 0x400));
      local_d8 = local_d8 + iVar4;
      local_2c = (uint)*(byte *)(local_d4 + -1) |
                 (uint)*(byte *)(local_d4 + -3) << 0x10 | (uint)*(byte *)(local_d4 + -4) << 0x18 |
                 (uint)*(byte *)(local_d4 + -2) << 8;
      local_f0 = &K256;
      iVar4 = (local_ec & ~local_d8 ^ local_dc & local_d8) +
              local_2c + 0xc19bf174 + uVar7 +
              ((local_d8 >> 0xb | local_d8 * 0x200000) ^ (local_d8 >> 6 | local_d8 * 0x4000000) ^
              (local_d8 >> 0x19 | local_d8 * 0x80));
      local_e4 = local_e4 + iVar4;
      uVar2 = 0x11;
      uVar1 = iVar4 + ((uVar5 ^ uVar10) & local_e8 ^ uVar5 & uVar10) +
                      ((local_e8 >> 0xd | local_e8 * 0x80000) ^
                       (local_e8 >> 2 | local_e8 * 0x40000000) ^
                      (local_e8 >> 0x16 | local_e8 * 0x400));
      local_f4 = 0x10;
      local_c0 = 0;
      local_c4 = 0x1d;
      local_bc = 0x1e;
      while( true ) {
        HintPreloadData(local_f0 + 0x7c);
        iVar4 = *(int *)(local_f0 + 0x40);
        uVar3 = local_f4 + 2 & 0xf;
        uVar12 = local_f4 + 0xf & 0xf;
        uVar6 = ((local_30 >> 0x13 | local_30 << 0xd) ^ (local_30 >> 0x11 | local_30 << 0xf) ^
                local_30 >> 10) +
                ((local_68[1] >> 0x12 | local_68[1] << 0xe) ^
                 (local_68[1] >> 7 | local_68[1] << 0x19) ^ local_68[1] >> 3) + local_68[0] +
                local_44;
        local_68[local_c0] = uVar6;
        uVar7 = local_68[uVar12];
        uVar8 = local_68[uVar3];
        iVar4 = uVar6 + iVar4 + (local_dc & ~local_e4 ^ local_e4 & local_d8) +
                                ((local_e4 >> 0xb | local_e4 << 0x15) ^
                                 (local_e4 >> 6 | local_e4 << 0x1a) ^
                                (local_e4 >> 0x19 | local_e4 << 7)) + local_ec;
        uVar14 = local_68[uVar2 & 0xf] + local_68[local_f4 + 10 & 0xf] +
                 ((uVar8 >> 0x12 | uVar8 << 0xe) ^ (uVar8 >> 7 | uVar8 << 0x19) ^ uVar8 >> 3) +
                 ((uVar7 >> 0x13 | uVar7 << 0xd) ^ (uVar7 >> 0x11 | uVar7 << 0xf) ^ uVar7 >> 10);
        uVar5 = iVar4 + uVar5;
        local_68[uVar2 & 0xf] = uVar14;
        uVar8 = local_f4 + 3 & 0xf;
        uVar7 = local_68[local_c0];
        uVar2 = local_68[uVar8];
        local_ec = ((uVar1 >> 0xd | uVar1 << 0x13) ^ (uVar1 >> 2 | uVar1 << 0x1e) ^
                   (uVar1 >> 0x16 | uVar1 << 10)) +
                   (uVar1 & uVar10 ^ uVar1 & local_e8 ^ local_e8 & uVar10) + iVar4;
        uVar6 = ((uVar7 >> 0x13 | uVar7 << 0xd) ^ (uVar7 >> 0x11 | uVar7 << 0xf) ^ uVar7 >> 10) +
                local_68[uVar3] + local_68[local_f4 + 0xb & 0xf] +
                ((uVar2 >> 0x12 | uVar2 << 0xe) ^ (uVar2 >> 7 | uVar2 << 0x19) ^ uVar2 >> 3);
        local_68[uVar3] = uVar6;
        uVar2 = local_f4 + 4 & 0xf;
        uVar7 = local_68[uVar2];
        uVar3 = local_68[local_f4 + 0x11 & 0xf];
        iVar4 = *(int *)(local_f0 + 0x44) + local_dc + uVar14 +
                ((uVar5 >> 0xb | uVar5 * 0x200000) ^ (uVar5 >> 6 | uVar5 * 0x4000000) ^
                (uVar5 >> 0x19 | uVar5 * 0x80)) + (local_d8 & ~uVar5 ^ local_e4 & uVar5);
        local_dc = iVar4 + ((local_ec >> 0xd | local_ec * 0x80000) ^
                            (local_ec >> 2 | local_ec * 0x40000000) ^
                           (local_ec >> 0x16 | local_ec * 0x400)) +
                           ((uVar1 ^ local_e8) & local_ec ^ uVar1 & local_e8);
        uVar10 = iVar4 + uVar10;
        iVar4 = *(int *)(local_f0 + 0x48);
        uVar11 = local_f4 + 5 & 0xf;
        uVar14 = local_68[local_f4 + 0xc & 0xf] + local_68[uVar8] +
                 ((uVar7 >> 0x12 | uVar7 << 0xe) ^ (uVar7 >> 7 | uVar7 << 0x19) ^ uVar7 >> 3) +
                 ((uVar3 >> 0x13 | uVar3 << 0xd) ^ (uVar3 >> 0x11 | uVar3 << 0xf) ^ uVar3 >> 10);
        local_68[uVar8] = uVar14;
        uVar7 = local_68[uVar11];
        uVar3 = local_68[local_f4 + 0x12 & 0xf];
        iVar13 = ((uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 6 | uVar10 * 0x4000000) ^
                 (uVar10 >> 0x19 | uVar10 * 0x80)) + local_d8 + iVar4 + uVar6 +
                 (local_e4 & ~uVar10 ^ uVar5 & uVar10);
        local_e8 = iVar13 + local_e8;
        uVar6 = local_68[uVar2] + local_68[local_c4 & 0xf] +
                ((uVar7 >> 0x12 | uVar7 << 0xe) ^ (uVar7 >> 7 | uVar7 << 0x19) ^ uVar7 >> 3) +
                ((uVar3 >> 0x13 | uVar3 << 0xd) ^ (uVar3 >> 0x11 | uVar3 << 0xf) ^ uVar3 >> 10);
        iVar4 = *(int *)(local_f0 + 0x4c);
        uVar3 = local_f4 + 6 & 0xf;
        local_d8 = iVar13 + ((local_ec ^ uVar1) & local_dc ^ local_ec & uVar1) +
                            ((local_dc >> 0xd | local_dc * 0x80000) ^
                             (local_dc >> 2 | local_dc * 0x40000000) ^
                            (local_dc >> 0x16 | local_dc * 0x400));
        local_68[uVar2] = uVar6;
        uVar2 = local_68[uVar3];
        uVar7 = local_68[local_f4 + 0x13 & 0xf];
        iVar13 = *(int *)(local_f0 + 0x50);
        iVar4 = (local_e8 & uVar10 ^ uVar5 & ~local_e8) +
                uVar14 + iVar4 + local_e4 +
                ((local_e8 >> 0xb | local_e8 * 0x200000) ^ (local_e8 >> 6 | local_e8 * 0x4000000) ^
                (local_e8 >> 0x19 | local_e8 * 0x80));
        uVar1 = iVar4 + uVar1;
        uVar2 = local_68[local_bc & 0xf] + local_68[uVar11] +
                ((uVar2 >> 0x12 | uVar2 << 0xe) ^ (uVar2 >> 7 | uVar2 << 0x19) ^ uVar2 >> 3) +
                ((uVar7 >> 0x13 | uVar7 << 0xd) ^ (uVar7 >> 0x11 | uVar7 << 0xf) ^ uVar7 >> 10);
        local_68[uVar11] = uVar2;
        local_e4 = ((local_ec ^ local_dc) & local_d8 ^ local_ec & local_dc) +
                   ((local_d8 >> 0xd | local_d8 * 0x80000) ^ (local_d8 >> 2 | local_d8 * 0x40000000)
                   ^ (local_d8 >> 0x16 | local_d8 * 0x400)) + iVar4;
        uVar7 = local_f4 + 7 & 0xf;
        iVar4 = (uVar10 & ~uVar1 ^ local_e8 & uVar1) +
                uVar5 + iVar13 + uVar6 +
                ((uVar1 >> 0xb | uVar1 * 0x200000) ^ (uVar1 >> 6 | uVar1 * 0x4000000) ^
                (uVar1 >> 0x19 | uVar1 * 0x80));
        uVar8 = local_68[uVar7];
        local_ec = local_ec + iVar4;
        uVar6 = local_68[local_f4 + 0x14 & 0xf];
        uVar5 = iVar4 + ((local_dc ^ local_d8) & local_e4 ^ local_dc & local_d8) +
                        ((local_e4 >> 0xd | local_e4 * 0x80000) ^
                         (local_e4 >> 2 | local_e4 * 0x40000000) ^
                        (local_e4 >> 0x16 | local_e4 * 0x400));
        uVar14 = local_f4 + 8;
        iVar9 = *(int *)(local_f0 + 0x58);
        iVar4 = ((local_ec >> 0xb | local_ec * 0x200000) ^ (local_ec >> 6 | local_ec * 0x4000000) ^
                (local_ec >> 0x19 | local_ec * 0x80)) + uVar2 + *(int *)(local_f0 + 0x54) + uVar10 +
                (local_e8 & ~local_ec ^ uVar1 & local_ec);
        uVar2 = ((uVar6 >> 0x13 | uVar6 << 0xd) ^ (uVar6 >> 0x11 | uVar6 << 0xf) ^ uVar6 >> 10) +
                ((uVar8 >> 0x12 | uVar8 << 0xe) ^ (uVar8 >> 7 | uVar8 << 0x19) ^ uVar8 >> 3) +
                local_68[uVar12] + local_68[uVar3];
        uVar8 = uVar14 & 0xf;
        uVar10 = iVar4 + ((uVar5 >> 0xd | uVar5 * 0x80000) ^ (uVar5 >> 2 | uVar5 * 0x40000000) ^
                         (uVar5 >> 0x16 | uVar5 * 0x400)) +
                         ((local_d8 ^ local_e4) & uVar5 ^ local_d8 & local_e4);
        iVar13 = *(int *)(local_f0 + 0x5c);
        local_dc = local_dc + iVar4;
        local_c4 = local_f4 + 0x15;
        local_68[uVar3] = uVar2;
        uVar6 = local_68[local_c4 & 0xf];
        uVar3 = local_68[uVar8];
        iVar4 = ((local_dc >> 0xb | local_dc * 0x200000) ^ (local_dc >> 6 | local_dc * 0x4000000) ^
                (local_dc >> 0x19 | local_dc * 0x80)) + uVar2 + iVar9 + local_e8 +
                (uVar1 & ~local_dc ^ local_dc & local_ec);
        local_d8 = local_d8 + iVar4;
        local_e8 = iVar4 + ((uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 2 | uVar10 * 0x40000000)
                           ^ (uVar10 >> 0x16 | uVar10 * 0x400)) +
                           ((local_e4 ^ uVar5) & uVar10 ^ local_e4 & uVar5);
        local_f0 = local_f0 + 0x20;
        uVar2 = ((uVar3 >> 0x12 | uVar3 << 0xe) ^ (uVar3 >> 7 | uVar3 << 0x19) ^ uVar3 >> 3) +
                local_68[uVar7] + local_68[local_c0] +
                ((uVar6 >> 0x13 | uVar6 << 0xd) ^ (uVar6 >> 0x11 | uVar6 << 0xf) ^ uVar6 >> 10);
        local_68[uVar7] = uVar2;
        iVar4 = ((local_d8 >> 0xb | local_d8 * 0x200000) ^ (local_d8 >> 6 | local_d8 * 0x4000000) ^
                (local_d8 >> 0x19 | local_d8 * 0x80)) + uVar1 + uVar2 + iVar13 +
                (local_ec & ~local_d8 ^ local_dc & local_d8);
        local_e4 = local_e4 + iVar4;
        uVar1 = iVar4 + ((local_e8 >> 0xd | local_e8 * 0x80000) ^
                         (local_e8 >> 2 | local_e8 * 0x40000000) ^
                        (local_e8 >> 0x16 | local_e8 * 0x400)) +
                        ((uVar5 ^ uVar10) & local_e8 ^ uVar5 & uVar10);
        if (uVar14 == 0x40) break;
        uVar2 = local_f4 + 9;
        local_bc = local_f4 + 0x16;
        local_68[0] = local_68[uVar8];
        local_68[1] = local_68[uVar2 & 0xf];
        local_30 = local_68[local_bc & 0xf];
        local_44 = local_68[local_f4 + 0x11 & 0xf];
        local_f4 = uVar14;
        local_c0 = uVar8;
      }
      local_b4 = local_b4 + uVar1;
      local_a0 = local_a0 + local_e8;
      local_ac = local_ac + uVar10;
      local_94 = local_94 + uVar5;
      local_b0 = local_b0 + local_e4;
      local_a8 = local_a8 + local_d8;
      local_a4 = local_a4 + local_dc;
      local_9c = local_9c + local_ec;
      *param_1 = local_b4;
      local_98 = local_98 + -1;
      local_d4 = local_d4 + 0x40;
      param_1[1] = local_a0;
      param_1[2] = local_ac;
      param_1[3] = local_94;
      param_1[4] = local_b0;
      param_1[5] = local_a8;
      param_1[6] = local_a4;
      param_1[7] = local_9c;
    } while (local_98 != -1);
  }
  return;
}


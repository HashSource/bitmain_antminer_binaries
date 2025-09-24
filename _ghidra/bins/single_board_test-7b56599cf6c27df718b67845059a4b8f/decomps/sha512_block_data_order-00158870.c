
void sha512_block_data_order(uint *param_1,int param_2,int param_3)

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
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  char *pcVar27;
  char *pcVar28;
  bool bVar29;
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
  uint local_d80;
  uint local_d7c;
  uint local_d78;
  uint local_d74;
  int local_d70;
  uint local_d68;
  uint local_d64;
  uint local_d60;
  uint local_d5c;
  uint local_d58;
  uint local_d54;
  uint local_d48;
  uint uStack_d44;
  uint local_d40;
  uint local_d3c;
  uint local_d38;
  uint local_d34;
  uint local_d30;
  uint uStack_d2c;
  uint local_d28;
  uint uStack_d24;
  uint local_d18;
  uint local_d14;
  uint local_d10;
  uint uStack_d0c;
  uint local_d08;
  uint uStack_d04;
  uint local_bf0;
  uint uStack_bec;
  uint local_be8;
  uint local_be4;
  uint local_6e0;
  uint uStack_6dc;
  uint local_6d0;
  uint uStack_6cc;
  uint local_6c8;
  uint uStack_6c4;
  uint local_6c0;
  uint uStack_6bc;
  uint local_530;
  uint uStack_52c;
  uint local_528;
  uint uStack_524;
  int local_30;
  
  local_30 = param_3 + -1;
  if (param_3 != 0) {
    local_bf0 = *param_1;
    uStack_bec = param_1[1];
    local_6e0 = param_1[2];
    uStack_6dc = param_1[3];
    local_d70 = param_2 + 0x80;
    local_6c8 = param_1[4];
    uStack_6c4 = param_1[5];
    local_530 = param_1[6];
    uStack_52c = param_1[7];
    local_be8 = param_1[8];
    local_be4 = param_1[9];
    local_6d0 = param_1[10];
    uStack_6cc = param_1[0xb];
    local_6c0 = param_1[0xc];
    uStack_6bc = param_1[0xd];
    local_528 = param_1[0xe];
    uStack_524 = param_1[0xf];
    do {
      uStack_d04 = (uint)*(byte *)(local_d70 + -0x7d) |
                   (uint)*(byte *)(local_d70 + -0x7e) << 8 |
                   (uint)*(byte *)(local_d70 + -0x80) << 0x18 |
                   (uint)*(byte *)(local_d70 + -0x7f) << 0x10;
      uVar1 = (local_be8 << 0x17 | local_be4 >> 9) ^
              (local_be8 >> 0xe | local_be4 << 0x12) ^ (local_be8 >> 0x12 | local_be4 << 0xe);
      uVar20 = uVar1 + local_528 + 0xd728ae22;
      uVar21 = local_be8 & local_6d0 ^ local_6c0 & ~local_be8;
      local_d08 = (uint)*(byte *)(local_d70 + -0x7a) << 8 |
                  (uint)*(byte *)(local_d70 + -0x7b) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x7c) << 0x18 | (uint)*(byte *)(local_d70 + -0x79);
      uVar22 = uVar20 + uVar21;
      uVar12 = local_d08 + uVar22;
      iVar18 = uStack_d04 +
               ((local_be4 << 0x17 | local_be8 >> 9) ^
               (local_be4 >> 0xe | local_be8 << 0x12) ^ (local_be4 >> 0x12 | local_be8 << 0xe)) +
               uStack_524 + 0x428a2f98 + (uint)(0x28d751dd < local_528) +
               (uint)CARRY4(uVar1,local_528 + 0xd728ae22) +
               (local_be4 & uStack_6cc ^ uStack_6bc & ~local_be4) + (uint)CARRY4(uVar20,uVar21) +
               (uint)CARRY4(local_d08,uVar22);
      uVar4 = uVar12 + local_530;
      uVar6 = iVar18 + uStack_52c + CARRY4(uVar12,local_530);
      uVar1 = (local_bf0 << 0x19 | uStack_bec >> 7) ^
              (local_bf0 >> 0x1c | uStack_bec << 4) ^ (local_bf0 << 0x1e | uStack_bec >> 2);
      uVar20 = local_6e0 & local_6c8 ^ local_bf0 & local_6e0 ^ local_bf0 & local_6c8;
      uVar22 = uVar20 + uVar1;
      local_dc4 = (uint)*(byte *)(local_d70 + -0x75) |
                  (uint)*(byte *)(local_d70 + -0x76) << 8 |
                  (uint)*(byte *)(local_d70 + -0x78) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x77) << 0x10;
      uVar21 = uVar12 + uVar22;
      uVar22 = iVar18 + (uStack_6dc & uStack_6c4 ^ uStack_bec & uStack_6dc ^ uStack_bec & uStack_6c4
                        ) + ((uStack_bec << 0x19 | local_bf0 >> 7) ^
                            (uStack_bec >> 0x1c | local_bf0 << 4) ^
                            (uStack_bec << 0x1e | local_bf0 >> 2)) + (uint)CARRY4(uVar20,uVar1) +
                        (uint)CARRY4(uVar12,uVar22);
      HintPreloadData(local_d70);
      HintPreloadData(local_d70 + 1);
      local_dc8 = (uint)*(byte *)(local_d70 + -0x72) << 8 |
                  (uint)*(byte *)(local_d70 + -0x73) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x74) << 0x18 | (uint)*(byte *)(local_d70 + -0x71);
      uVar12 = local_dc8 + local_6c0 + 0x23ef65cd;
      uVar20 = (uVar4 * 0x800000 | uVar6 >> 9) ^
               (uVar4 >> 0xe | uVar6 * 0x40000) ^ (uVar4 >> 0x12 | uVar6 * 0x4000);
      uVar13 = uVar12 + uVar20;
      uVar1 = local_6d0 & ~uVar4 ^ local_be8 & uVar4;
      HintPreloadData(local_d70 + 2);
      uVar7 = uVar13 + uVar1;
      iVar18 = local_dc4 +
               uStack_6bc + (0xdc109a32 < local_6c0) + 0x71374491 +
               (uint)CARRY4(local_dc8,local_6c0 + 0x23ef65cd) +
               ((uVar6 * 0x800000 | uVar4 >> 9) ^
               (uVar6 >> 0xe | uVar4 * 0x40000) ^ (uVar6 >> 0x12 | uVar4 * 0x4000)) +
               (uint)CARRY4(uVar12,uVar20) +
               (uStack_6cc & ~uVar6 ^ local_be4 & uVar6) + (uint)CARRY4(uVar13,uVar1);
      uVar8 = uVar7 + local_6c8;
      uVar10 = iVar18 + uStack_6c4 + CARRY4(uVar7,local_6c8);
      uVar1 = local_bf0 & local_6e0 ^ uVar21 & (local_bf0 ^ local_6e0);
      uVar12 = (uVar21 * 0x2000000 | uVar22 >> 7) ^
               (uVar21 >> 0x1c | uVar22 * 0x10) ^ (uVar21 * 0x40000000 | uVar22 >> 2);
      uVar20 = uVar1 + uVar12;
      uVar9 = uVar7 + uVar20;
      uVar11 = iVar18 + (uStack_bec & uStack_6dc ^ uVar22 & (uStack_bec ^ uStack_6dc)) +
                        ((uVar22 * 0x2000000 | uVar21 >> 7) ^
                        (uVar22 >> 0x1c | uVar21 * 0x10) ^ (uVar22 * 0x40000000 | uVar21 >> 2)) +
                        (uint)CARRY4(uVar1,uVar12) + (uint)CARRY4(uVar7,uVar20);
      local_da4 = (uint)*(byte *)(local_d70 + -0x6d) |
                  (uint)*(byte *)(local_d70 + -0x6e) << 8 |
                  (uint)*(byte *)(local_d70 + -0x70) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x6f) << 0x10;
      HintPreloadData(local_d70 + 3);
      local_da8 = (uint)*(byte *)(local_d70 + -0x6a) << 8 |
                  (uint)*(byte *)(local_d70 + -0x6b) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x6c) << 0x18 | (uint)*(byte *)(local_d70 + -0x69);
      uVar20 = (uVar8 * 0x800000 | uVar10 >> 9) ^
               (uVar8 >> 0xe | uVar10 * 0x40000) ^ (uVar8 >> 0x12 | uVar10 * 0x4000);
      uVar7 = local_da8 + local_6d0 + 0xec4d3b2f;
      uVar1 = uVar7 + uVar20;
      uVar12 = local_be8 & ~uVar8 ^ uVar4 & uVar8;
      uVar13 = uVar1 + uVar12;
      iVar18 = local_da4 + uStack_6cc + 0xb5c0fbcf + (uint)(0x13b2c4d0 < local_6d0) +
               (uint)CARRY4(local_da8,local_6d0 + 0xec4d3b2f) +
               ((uVar10 * 0x800000 | uVar8 >> 9) ^
               (uVar10 >> 0xe | uVar8 * 0x40000) ^ (uVar10 >> 0x12 | uVar8 * 0x4000)) +
               (uint)CARRY4(uVar7,uVar20) +
               (local_be4 & ~uVar10 ^ uVar6 & uVar10) + (uint)CARRY4(uVar1,uVar12);
      uVar7 = uVar13 + local_6e0;
      uVar2 = iVar18 + uStack_6dc + (uint)CARRY4(uVar13,local_6e0);
      uVar1 = (uVar9 >> 0x1c | uVar11 * 0x10) ^ (uVar9 * 0x40000000 | uVar11 >> 2) ^
              (uVar9 * 0x2000000 | uVar11 >> 7);
      uVar20 = local_bf0 & uVar21 ^ (local_bf0 ^ uVar21) & uVar9;
      uVar12 = uVar20 + uVar1;
      uVar3 = uVar13 + uVar12;
      uVar5 = iVar18 + (uStack_bec & uVar22 ^ (uStack_bec ^ uVar22) & uVar11) +
                       ((uVar11 >> 0x1c | uVar9 * 0x10) ^ (uVar11 * 0x40000000 | uVar9 >> 2) ^
                       (uVar11 * 0x2000000 | uVar9 >> 7)) + (uint)CARRY4(uVar20,uVar1) +
                       (uint)CARRY4(uVar13,uVar12);
      local_dcc = (uint)*(byte *)(local_d70 + -0x65) |
                  (uint)*(byte *)(local_d70 + -0x68) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x67) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x66) << 8;
      local_dd0 = (uint)*(byte *)(local_d70 + -0x62) << 8 |
                  (uint)*(byte *)(local_d70 + -99) << 0x10 |
                  (uint)*(byte *)(local_d70 + -100) << 0x18 | (uint)*(byte *)(local_d70 + -0x61);
      uVar1 = (uVar7 * 0x800000 | uVar2 >> 9) ^
              (uVar7 >> 0xe | uVar2 * 0x40000) ^ (uVar7 >> 0x12 | uVar2 * 0x4000);
      uVar20 = local_dd0 + local_be8 + 0x8189dbbc;
      uVar12 = uVar4 & ~uVar7 ^ uVar8 & uVar7;
      uVar13 = uVar20 + uVar1;
      uVar14 = uVar13 + uVar12;
      iVar18 = local_dcc + local_be4 + (0x7e762443 < local_be8) + 0xe9b5dba5 +
               (uint)CARRY4(local_dd0,local_be8 + 0x8189dbbc) +
               ((uVar2 * 0x800000 | uVar7 >> 9) ^
               (uVar2 >> 0xe | uVar7 * 0x40000) ^ (uVar2 >> 0x12 | uVar7 * 0x4000)) +
               (uint)CARRY4(uVar20,uVar1) +
               (uVar6 & ~uVar2 ^ uVar10 & uVar2) + (uint)CARRY4(uVar13,uVar12);
      uVar23 = local_bf0 + uVar14;
      uVar24 = uStack_bec + iVar18 + (uint)CARRY4(local_bf0,uVar14);
      uVar12 = (uVar3 * 0x2000000 | uVar5 >> 7) ^
               (uVar3 >> 0x1c | uVar5 * 0x10) ^ (uVar3 * 0x40000000 | uVar5 >> 2);
      uVar20 = uVar3 & (uVar9 ^ uVar21) ^ uVar9 & uVar21;
      uVar1 = uVar12 + uVar20;
      uVar15 = uVar14 + uVar1;
      uVar19 = iVar18 + ((uVar5 * 0x2000000 | uVar3 >> 7) ^
                        (uVar5 >> 0x1c | uVar3 * 0x10) ^ (uVar5 * 0x40000000 | uVar3 >> 2)) +
                        (uVar5 & (uVar11 ^ uVar22) ^ uVar11 & uVar22) + (uint)CARRY4(uVar12,uVar20)
                        + (uint)CARRY4(uVar14,uVar1);
      local_dbc = (uint)*(byte *)(local_d70 + -0x5d) |
                  (uint)*(byte *)(local_d70 + -0x60) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x5f) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x5e) << 8;
      local_dc0 = (uint)*(byte *)(local_d70 + -0x5a) << 8 |
                  (uint)*(byte *)(local_d70 + -0x5b) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x5c) << 0x18 | (uint)*(byte *)(local_d70 + -0x59);
      uVar13 = uVar4 + local_dc0 + 0xf348b538;
      uVar14 = (uVar23 * 0x800000 | uVar24 >> 9) ^
               (uVar23 >> 0xe | uVar24 * 0x40000) ^ (uVar23 >> 0x12 | uVar24 * 0x4000);
      uVar1 = uVar13 + uVar14;
      uVar20 = uVar8 & ~uVar23 ^ uVar7 & uVar23;
      uVar12 = uVar1 + uVar20;
      iVar18 = uVar6 + local_dbc + (0xcb74ac7 < local_dc0) + 0x3956c25b +
                       (uint)CARRY4(uVar4,local_dc0 + 0xf348b538) +
               ((uVar24 * 0x800000 | uVar23 >> 9) ^
               (uVar24 >> 0xe | uVar23 * 0x40000) ^ (uVar24 >> 0x12 | uVar23 * 0x4000)) +
               (uint)CARRY4(uVar13,uVar14) +
               (uVar10 & ~uVar24 ^ uVar2 & uVar24) + (uint)CARRY4(uVar1,uVar20);
      uVar16 = (uVar15 * 0x2000000 | uVar19 >> 7) ^
               (uVar15 >> 0x1c | uVar19 * 0x10) ^ (uVar15 * 0x40000000 | uVar19 >> 2);
      uVar13 = (uVar9 ^ uVar3) & uVar15 ^ uVar9 & uVar3;
      uVar6 = uVar16 + uVar13;
      uVar4 = uVar21 + uVar12;
      uVar14 = uVar22 + iVar18 + (uint)CARRY4(uVar21,uVar12);
      local_d9c = (uint)*(byte *)(local_d70 + -0x55) |
                  (uint)*(byte *)(local_d70 + -0x56) << 8 |
                  (uint)*(byte *)(local_d70 + -0x58) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x57) << 0x10;
      local_da0 = (uint)*(byte *)(local_d70 + -0x52) << 8 |
                  (uint)*(byte *)(local_d70 + -0x53) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x54) << 0x18 | (uint)*(byte *)(local_d70 + -0x51);
      uVar17 = (uVar4 * 0x800000 | uVar14 >> 9) ^
               (uVar4 >> 0xe | uVar14 * 0x40000) ^ (uVar4 >> 0x12 | uVar14 * 0x4000);
      uVar1 = uVar8 + local_da0 + 0xb605d019;
      uVar20 = uVar7 & ~uVar4 ^ uVar23 & uVar4;
      uVar22 = uVar1 + uVar17;
      uVar25 = uVar6 + uVar12;
      uVar26 = ((uVar19 * 0x2000000 | uVar15 >> 7) ^
               (uVar19 >> 0x1c | uVar15 * 0x10) ^ (uVar19 * 0x40000000 | uVar15 >> 2)) +
               ((uVar11 ^ uVar5) & uVar19 ^ uVar11 & uVar5) + (uint)CARRY4(uVar16,uVar13) +
               iVar18 + (uint)CARRY4(uVar6,uVar12);
      uVar21 = uVar20 + uVar22;
      iVar18 = (uVar2 & ~uVar14 ^ uVar24 & uVar14) +
               uVar10 + local_d9c + (0x49fa2fe6 < local_da0) + 0x59f111f1 +
               (uint)CARRY4(uVar8,local_da0 + 0xb605d019) +
               ((uVar14 * 0x800000 | uVar4 >> 9) ^
               (uVar14 >> 0xe | uVar4 * 0x40000) ^ (uVar14 >> 0x12 | uVar4 * 0x4000)) +
               (uint)CARRY4(uVar1,uVar17) + (uint)CARRY4(uVar20,uVar22);
      uVar6 = uVar9 + uVar21;
      uVar10 = uVar11 + iVar18 + (uint)CARRY4(uVar9,uVar21);
      local_d74 = (uint)*(byte *)(local_d70 + -0x4d) |
                  (uint)*(byte *)(local_d70 + -0x4e) << 8 |
                  (uint)*(byte *)(local_d70 + -0x50) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x4f) << 0x10;
      uVar12 = uVar25 & (uVar15 ^ uVar3) ^ uVar15 & uVar3;
      local_d78 = (uint)*(byte *)(local_d70 + -0x4a) << 8 |
                  (uint)*(byte *)(local_d70 + -0x4b) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x4c) << 0x18 | (uint)*(byte *)(local_d70 + -0x49);
      uVar1 = (uVar25 * 0x2000000 | uVar26 >> 7) ^
              (uVar25 >> 0x1c | uVar26 * 0x10) ^ (uVar25 * 0x40000000 | uVar26 >> 2);
      uVar20 = uVar1 + uVar12;
      uVar8 = uVar7 + local_d78 + 0xaf194f9b;
      uVar9 = (uVar6 * 0x800000 | uVar10 >> 9) ^
              (uVar6 >> 0xe | uVar10 * 0x40000) ^ (uVar6 >> 0x12 | uVar10 * 0x4000);
      uVar22 = uVar21 + uVar20;
      uVar13 = iVar18 + ((uVar26 * 0x2000000 | uVar25 >> 7) ^
                        (uVar26 >> 0x1c | uVar25 * 0x10) ^ (uVar26 * 0x40000000 | uVar25 >> 2)) +
                        (uVar26 & (uVar19 ^ uVar5) ^ uVar19 & uVar5) + (uint)CARRY4(uVar1,uVar12) +
               (uint)CARRY4(uVar21,uVar20);
      uVar21 = uVar9 + uVar8;
      uVar20 = uVar4 & uVar6 ^ uVar23 & ~uVar6;
      uVar1 = uVar21 + uVar20;
      iVar18 = ((uVar10 * 0x800000 | uVar6 >> 9) ^
               (uVar10 >> 0xe | uVar6 * 0x40000) ^ (uVar10 >> 0x12 | uVar6 * 0x4000)) +
               uVar2 + local_d74 + (0x50e6b064 < local_d78) + -0x6dc07d5c +
                       (uint)CARRY4(uVar7,local_d78 + 0xaf194f9b) + (uint)CARRY4(uVar9,uVar8) +
               (uVar14 & uVar10 ^ uVar24 & ~uVar10) + (uint)CARRY4(uVar21,uVar20);
      uVar11 = uVar1 + uVar3;
      uVar16 = iVar18 + uVar5 + CARRY4(uVar1,uVar3);
      local_d94 = (uint)*(byte *)(local_d70 + -0x45) |
                  (uint)*(byte *)(local_d70 + -0x46) << 8 |
                  (uint)*(byte *)(local_d70 + -0x48) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x47) << 0x10;
      uVar20 = uVar22 & (uVar15 ^ uVar25) ^ uVar15 & uVar25;
      uVar21 = (uVar22 * 0x2000000 | uVar13 >> 7) ^
               (uVar22 >> 0x1c | uVar13 * 0x10) ^ (uVar22 * 0x40000000 | uVar13 >> 2);
      local_d98 = (uint)*(byte *)(local_d70 + -0x42) << 8 |
                  (uint)*(byte *)(local_d70 + -0x43) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x44) << 0x18 | (uint)*(byte *)(local_d70 + -0x41);
      uVar12 = uVar20 + uVar21;
      uVar2 = uVar1 + uVar12;
      uVar3 = iVar18 + (uVar13 & (uVar19 ^ uVar26) ^ uVar19 & uVar26) +
                       ((uVar13 * 0x2000000 | uVar22 >> 7) ^
                       (uVar13 >> 0x1c | uVar22 * 0x10) ^ (uVar13 * 0x40000000 | uVar22 >> 2)) +
                       (uint)CARRY4(uVar20,uVar21) + (uint)CARRY4(uVar1,uVar12);
      uVar21 = uVar23 + local_d98 + 0xda6d8118;
      uVar7 = (uVar11 * 0x800000 | uVar16 >> 9) ^
              (uVar11 >> 0xe | uVar16 * 0x40000) ^ (uVar11 >> 0x12 | uVar16 * 0x4000);
      uVar20 = uVar7 + uVar21;
      uVar1 = uVar4 & ~uVar11 ^ uVar6 & uVar11;
      uVar12 = uVar20 + uVar1;
      iVar18 = ((uVar16 * 0x800000 | uVar11 >> 9) ^
               (uVar16 >> 0xe | uVar11 * 0x40000) ^ (uVar16 >> 0x12 | uVar11 * 0x4000)) +
               uVar24 + local_d94 + 0xab1c5ed5 + (uint)(0x25927ee7 < local_d98) +
                        (uint)CARRY4(uVar23,local_d98 + 0xda6d8118) + (uint)CARRY4(uVar7,uVar21) +
               (uVar14 & ~uVar16 ^ uVar10 & uVar16) + (uint)CARRY4(uVar20,uVar1);
      uVar1 = uVar12 + uVar15;
      uVar7 = iVar18 + uVar19 + CARRY4(uVar12,uVar15);
      uStack_d44 = (uint)*(byte *)(local_d70 + -0x3d) |
                   (uint)*(byte *)(local_d70 + -0x3e) << 8 |
                   (uint)*(byte *)(local_d70 + -0x40) << 0x18 |
                   (uint)*(byte *)(local_d70 + -0x3f) << 0x10;
      uVar21 = uVar2 & (uVar22 ^ uVar25) ^ uVar22 & uVar25;
      uVar5 = (uVar2 * 0x2000000 | uVar3 >> 7) ^
              (uVar2 >> 0x1c | uVar3 * 0x10) ^ (uVar2 * 0x40000000 | uVar3 >> 2);
      uVar20 = uVar21 + uVar5;
      local_d48 = (uint)*(byte *)(local_d70 + -0x3a) << 8 |
                  (uint)*(byte *)(local_d70 + -0x3b) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x3c) << 0x18 | (uint)*(byte *)(local_d70 + -0x39);
      uVar15 = uVar12 + uVar20;
      uVar17 = iVar18 + (uVar3 & (uVar13 ^ uVar26) ^ uVar13 & uVar26) +
                        ((uVar3 * 0x2000000 | uVar2 >> 7) ^
                        (uVar3 >> 0x1c | uVar2 * 0x10) ^ (uVar3 * 0x40000000 | uVar2 >> 2)) +
                        (uint)CARRY4(uVar21,uVar5) + (uint)CARRY4(uVar12,uVar20);
      uVar8 = uVar4 + local_d48 + 0xa3030242;
      uVar12 = (uVar1 * 0x800000 | uVar7 >> 9) ^
               (uVar1 >> 0xe | uVar7 * 0x40000) ^ (uVar1 >> 0x12 | uVar7 * 0x4000);
      uVar5 = uVar6 & ~uVar1 ^ uVar11 & uVar1;
      uVar21 = uVar12 + uVar8;
      uVar20 = uVar21 + uVar5;
      iVar18 = ((uVar7 * 0x800000 | uVar1 >> 9) ^
               (uVar7 >> 0xe | uVar1 * 0x40000) ^ (uVar7 >> 0x12 | uVar1 * 0x4000)) +
               uVar14 + uStack_d44 + 0xd807aa98 + (uint)(0x5cfcfdbd < local_d48) +
                        (uint)CARRY4(uVar4,local_d48 + 0xa3030242) + (uint)CARRY4(uVar12,uVar8) +
               (uVar10 & ~uVar7 ^ uVar16 & uVar7) + (uint)CARRY4(uVar21,uVar5);
      uVar5 = uVar25 + uVar20;
      uVar8 = uVar26 + iVar18 + (uint)CARRY4(uVar25,uVar20);
      local_d8c = (uint)*(byte *)(local_d70 + -0x36) << 8 |
                  (uint)*(byte *)(local_d70 + -0x38) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x37) << 0x10 | (uint)*(byte *)(local_d70 + -0x35);
      uVar12 = (uVar15 * 0x2000000 | uVar17 >> 7) ^
               (uVar15 >> 0x1c | uVar17 * 0x10) ^ (uVar15 * 0x40000000 | uVar17 >> 2);
      uVar4 = uVar22 & uVar2 ^ (uVar22 ^ uVar2) & uVar15;
      uVar21 = uVar4 + uVar12;
      uVar9 = uVar20 + uVar21;
      local_d14 = iVar18 + (uVar13 & uVar3 ^ (uVar13 ^ uVar3) & uVar17) +
                           ((uVar17 * 0x2000000 | uVar15 >> 7) ^
                           (uVar17 >> 0x1c | uVar15 * 0x10) ^ (uVar17 * 0x40000000 | uVar15 >> 2)) +
                           (uint)CARRY4(uVar4,uVar12) + (uint)CARRY4(uVar20,uVar21);
      local_d90 = (uint)*(byte *)(local_d70 + -0x32) << 8 |
                  (uint)*(byte *)(local_d70 + -0x33) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x31) | (uint)*(byte *)(local_d70 + -0x34) << 0x18;
      uVar14 = uVar6 + local_d90 + 0x45706fbe;
      uVar4 = (uVar5 * 0x800000 | uVar8 >> 9) ^
              (uVar5 >> 0xe | uVar8 * 0x40000) ^ (uVar5 >> 0x12 | uVar8 * 0x4000);
      uVar21 = uVar4 + uVar14;
      uVar12 = uVar11 & ~uVar5 ^ uVar1 & uVar5;
      uVar20 = uVar21 + uVar12;
      iVar18 = ((uVar8 * 0x800000 | uVar5 >> 9) ^
               (uVar8 >> 0xe | uVar5 * 0x40000) ^ (uVar8 >> 0x12 | uVar5 * 0x4000)) +
               uVar10 + local_d8c + (0xba8f9041 < local_d90) + 0x12835b01 +
                        (uint)CARRY4(uVar6,local_d90 + 0x45706fbe) + (uint)CARRY4(uVar4,uVar14) +
               (uVar16 & ~uVar8 ^ uVar7 & uVar8) + (uint)CARRY4(uVar21,uVar12);
      uVar21 = uVar22 + uVar20;
      uVar13 = uVar13 + iVar18 + (uint)CARRY4(uVar22,uVar20);
      uVar12 = (uVar9 >> 0x1c | local_d14 * 0x10) ^ (uVar9 * 0x40000000 | local_d14 >> 2) ^
               (uVar9 * 0x2000000 | local_d14 >> 7);
      uVar22 = uVar2 & uVar15 ^ uVar9 & (uVar2 ^ uVar15);
      local_db4 = (uint)*(byte *)(local_d70 + -0x2d) |
                  (uint)*(byte *)(local_d70 + -0x2e) << 8 |
                  (uint)*(byte *)(local_d70 + -0x30) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x2f) << 0x10;
      uVar4 = uVar22 + uVar12;
      uVar6 = uVar4 + uVar20;
      uVar10 = (uVar3 & uVar17 ^ local_d14 & (uVar3 ^ uVar17)) +
               ((local_d14 >> 0x1c | uVar9 * 0x10) ^ (local_d14 * 0x40000000 | uVar9 >> 2) ^
               (local_d14 * 0x2000000 | uVar9 >> 7)) + (uint)CARRY4(uVar22,uVar12) + iVar18 +
               (uint)CARRY4(uVar4,uVar20);
      local_db8 = (uint)*(byte *)(local_d70 + -0x2a) << 8 |
                  (uint)*(byte *)(local_d70 + -0x2b) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x2c) << 0x18 | (uint)*(byte *)(local_d70 + -0x29);
      uVar22 = uVar11 + local_db8 + 0x4ee4b28c;
      uVar4 = (uVar21 >> 0xe | uVar13 * 0x40000) ^ (uVar21 >> 0x12 | uVar13 * 0x4000) ^
              (uVar21 * 0x800000 | uVar13 >> 9);
      uVar20 = uVar22 + uVar4;
      uVar12 = uVar5 & uVar21 ^ uVar1 & ~uVar21;
      uVar14 = uVar20 + uVar12;
      iVar18 = uVar16 + local_db4 + (0xb11b4d73 < local_db8) + 0x243185be +
               (uint)CARRY4(uVar11,local_db8 + 0x4ee4b28c) +
               ((uVar13 >> 0xe | uVar21 * 0x40000) ^ (uVar13 >> 0x12 | uVar21 * 0x4000) ^
               (uVar13 * 0x800000 | uVar21 >> 9)) + (uint)CARRY4(uVar22,uVar4) +
               (uVar8 & uVar13 ^ uVar7 & ~uVar13) + (uint)CARRY4(uVar20,uVar12);
      uVar11 = uVar2 + uVar14;
      uVar3 = uVar3 + iVar18 + (uint)CARRY4(uVar2,uVar14);
      uVar20 = (uVar6 * 0x2000000 | uVar10 >> 7) ^
               (uVar6 >> 0x1c | uVar10 * 0x10) ^ (uVar6 * 0x40000000 | uVar10 >> 2);
      uVar12 = uVar9 & uVar15 ^ uVar6 & (uVar9 ^ uVar15);
      uVar2 = uVar12 + uVar20;
      local_d64 = (uint)*(byte *)(local_d70 + -0x25) |
                  (uint)*(byte *)(local_d70 + -0x28) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x27) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x26) << 8;
      uVar22 = uVar2 + uVar14;
      local_d34 = (local_d14 & uVar17 ^ uVar10 & (local_d14 ^ uVar17)) +
                  ((uVar10 * 0x2000000 | uVar6 >> 7) ^
                  (uVar10 >> 0x1c | uVar6 * 0x10) ^ (uVar10 * 0x40000000 | uVar6 >> 2)) +
                  (uint)CARRY4(uVar12,uVar20) + iVar18 + (uint)CARRY4(uVar2,uVar14);
      local_d68 = (uint)*(byte *)(local_d70 + -0x22) << 8 |
                  (uint)*(byte *)(local_d70 + -0x23) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x24) << 0x18 | (uint)*(byte *)(local_d70 + -0x21);
      uVar4 = uVar1 + local_d68 + 0xd5ffb4e2;
      uVar2 = (uVar11 * 0x800000 | uVar3 >> 9) ^
              (uVar11 >> 0xe | uVar3 * 0x40000) ^ (uVar11 >> 0x12 | uVar3 * 0x4000);
      uVar20 = uVar5 & ~uVar11 ^ uVar21 & uVar11;
      uVar12 = uVar2 + uVar4;
      uVar16 = uVar12 + uVar20;
      iVar18 = ((uVar3 * 0x800000 | uVar11 >> 9) ^
               (uVar3 >> 0xe | uVar11 * 0x40000) ^ (uVar3 >> 0x12 | uVar11 * 0x4000)) +
               uVar7 + local_d64 + 0x550c7dc3 + (uint)(0x2a004b1d < local_d68) +
                       (uint)CARRY4(uVar1,local_d68 + 0xd5ffb4e2) + (uint)CARRY4(uVar2,uVar4) +
               (uVar8 & ~uVar3 ^ uVar13 & uVar3) + (uint)CARRY4(uVar12,uVar20);
      uVar4 = uVar16 + uVar15;
      uVar14 = iVar18 + uVar17 + CARRY4(uVar16,uVar15);
      uVar12 = (uVar22 * 0x2000000 | local_d34 >> 7) ^
               (uVar22 >> 0x1c | local_d34 * 0x10) ^ (uVar22 * 0x40000000 | local_d34 >> 2);
      uVar20 = uVar22 & (uVar9 ^ uVar6) ^ uVar9 & uVar6;
      uVar1 = uVar12 + uVar20;
      uVar15 = uVar1 + uVar16;
      local_d7c = ((local_d34 * 0x2000000 | uVar22 >> 7) ^
                  (local_d34 >> 0x1c | uVar22 * 0x10) ^ (local_d34 * 0x40000000 | uVar22 >> 2)) +
                  (local_d34 & (local_d14 ^ uVar10) ^ local_d14 & uVar10) +
                  (uint)CARRY4(uVar12,uVar20) + iVar18 + (uint)CARRY4(uVar1,uVar16);
      local_d3c = (uint)*(byte *)(local_d70 + -0x1d) |
                  (uint)*(byte *)(local_d70 + -0x1e) << 8 |
                  (uint)*(byte *)(local_d70 + -0x20) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0x1f) << 0x10;
      local_d40 = (uint)*(byte *)(local_d70 + -0x1a) << 8 |
                  (uint)*(byte *)(local_d70 + -0x1b) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x1c) << 0x18 | (uint)*(byte *)(local_d70 + -0x19);
      uVar1 = uVar5 + local_d40 + 0xf27b896f;
      uVar20 = (uVar4 * 0x800000 | uVar14 >> 9) ^
               (uVar4 >> 0xe | uVar14 * 0x40000) ^ (uVar4 >> 0x12 | uVar14 * 0x4000);
      uVar12 = uVar21 & ~uVar4 ^ uVar11 & uVar4;
      uVar7 = uVar20 + uVar1;
      uVar2 = uVar7 + uVar12;
      iVar18 = ((uVar14 * 0x800000 | uVar4 >> 9) ^
               (uVar14 >> 0xe | uVar4 * 0x40000) ^ (uVar14 >> 0x12 | uVar4 * 0x4000)) +
               uVar8 + local_d3c + (0xd847690 < local_d40) + 0x72be5d74 +
                       (uint)CARRY4(uVar5,local_d40 + 0xf27b896f) + (uint)CARRY4(uVar20,uVar1) +
               (uVar13 & ~uVar14 ^ uVar3 & uVar14) + (uint)CARRY4(uVar7,uVar12);
      local_d18 = uVar9 + uVar2;
      local_d14 = local_d14 + iVar18 + (uint)CARRY4(uVar9,uVar2);
      uVar7 = (uVar15 * 0x2000000 | local_d7c >> 7) ^
              (uVar15 >> 0x1c | local_d7c * 0x10) ^ (uVar15 * 0x40000000 | local_d7c >> 2);
      uVar12 = uVar15 & (uVar22 ^ uVar6) ^ uVar22 & uVar6;
      uVar20 = uVar12 + uVar7;
      uVar1 = uVar20 + uVar2;
      uVar7 = (local_d7c & (local_d34 ^ uVar10) ^ local_d34 & uVar10) +
              ((local_d7c * 0x2000000 | uVar15 >> 7) ^
              (local_d7c >> 0x1c | uVar15 * 0x10) ^ (local_d7c * 0x40000000 | uVar15 >> 2)) +
              (uint)CARRY4(uVar12,uVar7) + iVar18 + (uint)CARRY4(uVar20,uVar2);
      uStack_d2c = (uint)*(byte *)(local_d70 + -0x15) |
                   (uint)*(byte *)(local_d70 + -0x16) << 8 |
                   (uint)*(byte *)(local_d70 + -0x18) << 0x18 |
                   (uint)*(byte *)(local_d70 + -0x17) << 0x10;
      local_d30 = (uint)*(byte *)(local_d70 + -0x12) << 8 |
                  (uint)*(byte *)(local_d70 + -0x13) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0x14) << 0x18 | (uint)*(byte *)(local_d70 + -0x11);
      uVar20 = (local_d18 * 0x800000 | local_d14 >> 9) ^
               (local_d18 >> 0xe | local_d14 * 0x40000) ^ (local_d18 >> 0x12 | local_d14 * 0x4000);
      uVar12 = uVar21 + local_d30 + 0x3b1696b1;
      uVar8 = uVar12 + uVar20;
      uVar5 = uVar11 & ~local_d18 ^ uVar4 & local_d18;
      uVar2 = uVar5 + uVar8;
      iVar18 = (uVar3 & ~local_d14 ^ uVar14 & local_d14) +
               uVar13 + uStack_d2c + (0xc4e9694e < local_d30) + -0x7f214e02 +
                        (uint)CARRY4(uVar21,local_d30 + 0x3b1696b1) +
               ((local_d14 * 0x800000 | local_d18 >> 9) ^
               (local_d14 >> 0xe | local_d18 * 0x40000) ^ (local_d14 >> 0x12 | local_d18 * 0x4000))
               + (uint)CARRY4(uVar12,uVar20) + (uint)CARRY4(uVar5,uVar8);
      uVar20 = (uVar1 * 0x2000000 | uVar7 >> 7) ^
               (uVar1 >> 0x1c | uVar7 * 0x10) ^ (uVar1 * 0x40000000 | uVar7 >> 2);
      uVar12 = uVar1 & (uVar22 ^ uVar15) ^ uVar22 & uVar15;
      uVar21 = uVar12 + uVar20;
      local_d58 = uVar2 + uVar6;
      local_d54 = iVar18 + uVar10 + (uint)CARRY4(uVar2,uVar6);
      local_d60 = uVar2 + uVar21;
      local_d5c = iVar18 + (uVar7 & (local_d34 ^ local_d7c) ^ local_d34 & local_d7c) +
                           ((uVar7 * 0x2000000 | uVar1 >> 7) ^
                           (uVar7 >> 0x1c | uVar1 * 0x10) ^ (uVar7 * 0x40000000 | uVar1 >> 2)) +
                           (uint)CARRY4(uVar12,uVar20) + (uint)CARRY4(uVar2,uVar21);
      local_dac = (uint)*(byte *)(local_d70 + -0xd) |
                  (uint)*(byte *)(local_d70 + -0xe) << 8 |
                  (uint)*(byte *)(local_d70 + -0x10) << 0x18 |
                  (uint)*(byte *)(local_d70 + -0xf) << 0x10;
      local_db0 = (uint)*(byte *)(local_d70 + -10) << 8 |
                  (uint)*(byte *)(local_d70 + -0xb) << 0x10 |
                  (uint)*(byte *)(local_d70 + -0xc) << 0x18 | (uint)*(byte *)(local_d70 + -9);
      uVar20 = uVar11 + local_db0 + 0x25c71235;
      uVar21 = (local_d58 * 0x800000 | local_d54 >> 9) ^
               (local_d58 >> 0xe | local_d54 * 0x40000) ^ (local_d58 >> 0x12 | local_d54 * 0x4000);
      uVar2 = uVar21 + uVar20;
      uVar13 = uVar4 & ~local_d58 ^ local_d18 & local_d58;
      uVar12 = uVar2 + uVar13;
      iVar18 = ((local_d54 * 0x800000 | local_d58 >> 9) ^
               (local_d54 >> 0xe | local_d58 * 0x40000) ^ (local_d54 >> 0x12 | local_d58 * 0x4000))
               + uVar3 + local_dac + 0x9bdc06a7 + (uint)(0xda38edca < local_db0) +
                         (uint)CARRY4(uVar11,local_db0 + 0x25c71235) + (uint)CARRY4(uVar21,uVar20) +
               (uVar14 & ~local_d54 ^ local_d14 & local_d54) + (uint)CARRY4(uVar2,uVar13);
      uVar20 = (local_d60 * 0x2000000 | local_d5c >> 7) ^
               (local_d60 >> 0x1c | local_d5c * 0x10) ^ (local_d60 * 0x40000000 | local_d5c >> 2);
      uVar21 = uVar1 & uVar15 ^ local_d60 & (uVar1 ^ uVar15);
      local_d38 = uVar22 + uVar12;
      local_d34 = local_d34 + iVar18 + (uint)CARRY4(uVar22,uVar12);
      uVar22 = uVar21 + uVar20;
      local_d10 = uVar22 + uVar12;
      uStack_d0c = (uVar7 & local_d7c ^ local_d5c & (uVar7 ^ local_d7c)) +
                   ((local_d5c * 0x2000000 | local_d60 >> 7) ^
                   (local_d5c >> 0x1c | local_d60 * 0x10) ^
                   (local_d5c * 0x40000000 | local_d60 >> 2)) + (uint)CARRY4(uVar21,uVar20) + iVar18
                   + (uint)CARRY4(uVar22,uVar12);
      uStack_d24 = (uint)*(byte *)(local_d70 + -5) |
                   (uint)*(byte *)(local_d70 + -6) << 8 |
                   (uint)*(byte *)(local_d70 + -8) << 0x18 | (uint)*(byte *)(local_d70 + -7) << 0x10
      ;
      uVar22 = (local_d38 * 0x800000 | local_d34 >> 9) ^
               (local_d38 >> 0xe | local_d34 * 0x40000) ^ (local_d38 >> 0x12 | local_d34 * 0x4000);
      local_d28 = (uint)*(byte *)(local_d70 + -2) << 8 |
                  (uint)*(byte *)(local_d70 + -3) << 0x10 |
                  (uint)*(byte *)(local_d70 + -4) << 0x18 | (uint)*(byte *)(local_d70 + -1);
      uVar20 = uVar4 + local_d28 + 0xcf692694;
      uVar12 = uVar20 + uVar22;
      uVar21 = local_d58 & local_d38 ^ local_d18 & ~local_d38;
      uVar13 = (local_d10 * 0x2000000 | uStack_d0c >> 7) ^
               (local_d10 >> 0x1c | uStack_d0c * 0x10) ^ (local_d10 * 0x40000000 | uStack_d0c >> 2);
      uVar2 = uVar12 + uVar21;
      iVar18 = uVar14 + uStack_d24 + 0xc19bf174 + (uint)(0x3096d96b < local_d28) +
               (uint)CARRY4(uVar4,local_d28 + 0xcf692694) +
               ((local_d34 * 0x800000 | local_d38 >> 9) ^
               (local_d34 >> 0xe | local_d38 * 0x40000) ^ (local_d34 >> 0x12 | local_d38 * 0x4000))
               + (uint)CARRY4(uVar20,uVar22) +
               (local_d54 & local_d34 ^ local_d14 & ~local_d34) + (uint)CARRY4(uVar12,uVar21);
      local_d80 = uVar15 + uVar2;
      local_d7c = local_d7c + iVar18 + (uint)CARRY4(uVar15,uVar2);
      uVar20 = local_d10 & (uVar1 ^ local_d60) ^ uVar1 & local_d60;
      uVar21 = uVar20 + uVar13;
      uVar12 = uVar2 + uVar21;
      uVar20 = iVar18 + (uStack_d0c & (uVar7 ^ local_d5c) ^ uVar7 & local_d5c) +
                        ((uStack_d0c * 0x2000000 | local_d10 >> 7) ^
                        (uStack_d0c >> 0x1c | local_d10 * 0x10) ^
                        (uStack_d0c * 0x40000000 | local_d10 >> 2)) + (uint)CARRY4(uVar20,uVar13) +
                        (uint)CARRY4(uVar2,uVar21);
      pcVar27 = &UNK_0021ef20;
      do {
        HintPreloadData(pcVar27);
        HintPreloadData(pcVar27 + 8);
        HintPreloadData(pcVar27 + 0x10);
        HintPreloadData(pcVar27 + 0x18);
        uVar2 = (local_dc8 >> 7 | local_dc4 << 0x19) ^
                (local_dc8 >> 1 | local_dc4 << 0x1f) ^ (local_dc8 >> 8 | local_dc4 << 0x18);
        uVar3 = (local_db0 >> 6 | local_dac << 0x1a) ^
                (local_db0 >> 0x13 | local_dac << 0xd) ^ (local_db0 << 3 | local_dac >> 0x1d);
        uVar4 = uVar3 + uVar2;
        uVar22 = (local_d80 << 0x17 | local_d7c >> 9) ^
                 (local_d80 >> 0xe | local_d7c << 0x12) ^ (local_d80 >> 0x12 | local_d7c << 0xe);
        uVar21 = local_d80 & local_d38 ^ local_d58 & ~local_d80;
        uVar5 = uVar4 + local_d90;
        uVar13 = uVar21 + uVar22;
        bVar29 = CARRY4(local_d08,uVar5);
        local_d08 = local_d08 + uVar5;
        uStack_d04 = uStack_d04 +
                     (local_dac >> 6 ^
                     (local_dac >> 0x13 | local_db0 << 0xd) ^ (local_dac << 3 | local_db0 >> 0x1d))
                     + (local_dc4 >> 7 ^
                       (local_dc4 >> 1 | local_dc8 << 0x1f) ^ (local_dc4 >> 8 | local_dc8 << 0x18))
                     + (uint)CARRY4(uVar3,uVar2) + local_d8c + (uint)CARRY4(uVar4,local_d90) +
                     (uint)bVar29;
        pcVar28 = pcVar27 + 0x80;
        uVar2 = *(uint *)(pcVar27 + -0x80) + uVar13;
        uVar4 = local_d08 + uVar2;
        uVar3 = local_d18 + uVar4;
        iVar18 = local_d14 +
                 uStack_d04 +
                 *(int *)(pcVar27 + -0x7c) +
                 (local_d7c & local_d34 ^ local_d54 & ~local_d7c) +
                 ((local_d7c << 0x17 | local_d80 >> 9) ^
                 (local_d7c >> 0xe | local_d80 << 0x12) ^ (local_d7c >> 0x12 | local_d80 << 0xe)) +
                 (uint)CARRY4(uVar21,uVar22) + (uint)CARRY4(*(uint *)(pcVar27 + -0x80),uVar13) +
                 (uint)CARRY4(local_d08,uVar2) + (uint)CARRY4(local_d18,uVar4);
        uVar8 = uVar3 + uVar1;
        uVar15 = iVar18 + uVar7 + CARRY4(uVar3,uVar1);
        uVar7 = (local_da8 >> 7 | local_da4 << 0x19) ^
                (local_da8 >> 1 | local_da4 << 0x1f) ^ (local_da8 >> 8 | local_da4 << 0x18);
        uVar1 = local_db8 + uVar7;
        uVar21 = local_d10 & local_d60 ^ local_d10 & uVar12 ^ local_d60 & uVar12;
        bVar29 = CARRY4(local_dc8,uVar1);
        uVar1 = local_dc8 + uVar1;
        uVar2 = (uVar12 << 0x19 | uVar20 >> 7) ^
                (uVar12 >> 0x1c | uVar20 << 4) ^ (uVar12 << 0x1e | uVar20 >> 2);
        uVar22 = (local_d28 >> 6 | uStack_d24 << 0x1a) ^
                 (local_d28 >> 0x13 | uStack_d24 << 0xd) ^ (local_d28 << 3 | uStack_d24 >> 0x1d);
        uVar13 = uVar2 + uVar21;
        local_dc8 = uVar22 + uVar1;
        local_dc4 = (uStack_d24 >> 6 ^
                    (uStack_d24 >> 0x13 | local_d28 << 0xd) ^ (uStack_d24 << 3 | local_d28 >> 0x1d))
                    + local_dc4 +
                      local_db4 +
                      (local_da4 >> 7 ^
                      (local_da4 >> 1 | local_da8 << 0x1f) ^ (local_da4 >> 8 | local_da8 << 0x18)) +
                      (uint)CARRY4(local_db8,uVar7) + (uint)bVar29 + (uint)CARRY4(uVar22,uVar1);
        uVar22 = *(uint *)(pcVar27 + -0x78) + local_d58;
        uVar4 = local_dc8 + uVar22;
        uVar7 = (uVar8 * 0x800000 | uVar15 >> 9) ^
                (uVar8 >> 0xe | uVar15 * 0x40000) ^ (uVar8 >> 0x12 | uVar15 * 0x4000);
        uVar1 = uVar3 + uVar13;
        uVar13 = iVar18 + ((uVar20 << 0x19 | uVar12 >> 7) ^
                          (uVar20 >> 0x1c | uVar12 << 4) ^ (uVar20 << 0x1e | uVar12 >> 2)) +
                          (uStack_d0c & local_d5c ^ uStack_d0c & uVar20 ^ local_d5c & uVar20) +
                          (uint)CARRY4(uVar2,uVar21) + (uint)CARRY4(uVar3,uVar13);
        uVar21 = uVar4 + uVar7;
        uVar2 = local_d38 & ~uVar8 ^ local_d80 & uVar8;
        uVar14 = uVar21 + uVar2;
        iVar18 = local_dc4 +
                 *(int *)(pcVar27 + -0x74) + local_d54 +
                 (uint)CARRY4(*(uint *)(pcVar27 + -0x78),local_d58) + (uint)CARRY4(local_dc8,uVar22)
                 + ((uVar15 * 0x800000 | uVar8 >> 9) ^
                   (uVar15 >> 0xe | uVar8 * 0x40000) ^ (uVar15 >> 0x12 | uVar8 * 0x4000)) +
                 (uint)CARRY4(uVar4,uVar7) +
                 (local_d34 & ~uVar15 ^ local_d7c & uVar15) + (uint)CARRY4(uVar21,uVar2);
        uVar2 = local_d60 + uVar14;
        uVar4 = local_d5c + iVar18 + (uint)CARRY4(local_d60,uVar14);
        uVar21 = (local_dd0 >> 7 | local_dcc << 0x19) ^
                 (local_dd0 >> 1 | local_dcc << 0x1f) ^ (local_dd0 >> 8 | local_dcc << 0x18);
        uVar5 = local_d68 + uVar21;
        uVar7 = local_d10 & uVar12 ^ (local_d10 ^ uVar12) & uVar1;
        uVar22 = (uVar1 * 0x2000000 | uVar13 >> 7) ^
                 (uVar1 >> 0x1c | uVar13 * 0x10) ^ (uVar1 * 0x40000000 | uVar13 >> 2);
        uVar3 = (local_d08 >> 0x13 | uStack_d04 * 0x2000) ^ (local_d08 * 8 | uStack_d04 >> 0x1d) ^
                (local_d08 >> 6 | uStack_d04 * 0x4000000);
        bVar29 = CARRY4(local_da8,uVar5);
        uVar5 = local_da8 + uVar5;
        uVar6 = uVar7 + uVar22;
        local_da8 = uVar3 + uVar5;
        local_da4 = ((uStack_d04 >> 0x13 | local_d08 * 0x2000) ^
                     (uStack_d04 * 8 | local_d08 >> 0x1d) ^ uStack_d04 >> 6) +
                    local_da4 +
                    local_d64 +
                    (local_dcc >> 7 ^
                    (local_dcc >> 1 | local_dd0 << 0x1f) ^ (local_dcc >> 8 | local_dd0 << 0x18)) +
                    (uint)CARRY4(local_d68,uVar21) + (uint)bVar29 + (uint)CARRY4(uVar3,uVar5);
        uVar5 = uVar6 + uVar14;
        uVar9 = (uStack_d0c & uVar20 ^ (uStack_d0c ^ uVar20) & uVar13) +
                ((uVar13 * 0x2000000 | uVar1 >> 7) ^
                (uVar13 >> 0x1c | uVar1 * 0x10) ^ (uVar13 * 0x40000000 | uVar1 >> 2)) +
                (uint)CARRY4(uVar7,uVar22) + iVar18 + (uint)CARRY4(uVar6,uVar14);
        uVar6 = (uVar2 * 0x800000 | uVar4 >> 9) ^
                (uVar2 >> 0xe | uVar4 * 0x40000) ^ (uVar2 >> 0x12 | uVar4 * 0x4000);
        uVar7 = *(uint *)(pcVar27 + -0x70) + local_d38;
        uVar21 = local_da8 + uVar7;
        uVar22 = local_d80 & ~uVar2 ^ uVar8 & uVar2;
        uVar3 = uVar21 + uVar6;
        uVar10 = uVar3 + uVar22;
        iVar18 = local_da4 +
                 *(int *)(pcVar27 + -0x6c) + local_d34 +
                 (uint)CARRY4(*(uint *)(pcVar27 + -0x70),local_d38) + (uint)CARRY4(local_da8,uVar7)
                 + ((uVar4 * 0x800000 | uVar2 >> 9) ^
                   (uVar4 >> 0xe | uVar2 * 0x40000) ^ (uVar4 >> 0x12 | uVar2 * 0x4000)) +
                 (uint)CARRY4(uVar21,uVar6) +
                 (local_d7c & ~uVar4 ^ uVar15 & uVar4) + (uint)CARRY4(uVar3,uVar22);
        uVar3 = local_d10 + uVar10;
        uVar6 = uStack_d0c + iVar18 + (uint)CARRY4(local_d10,uVar10);
        uVar21 = (local_dc0 >> 7 | local_dbc << 0x19) ^
                 (local_dc0 >> 1 | local_dbc << 0x1f) ^ (local_dc0 >> 8 | local_dbc << 0x18);
        uVar14 = (uVar5 >> 0x1c | uVar9 * 0x10) ^ (uVar5 * 0x40000000 | uVar9 >> 2) ^
                 (uVar5 * 0x2000000 | uVar9 >> 7);
        uVar22 = uVar1 & uVar12 ^ uVar5 & (uVar1 ^ uVar12);
        uVar7 = local_d40 + uVar21;
        uVar11 = uVar22 + uVar14;
        uVar17 = (local_dc8 >> 6 | local_dc4 * 0x4000000) ^
                 (local_dc8 >> 0x13 | local_dc4 * 0x2000) ^ (local_dc8 * 8 | local_dc4 >> 0x1d);
        bVar29 = CARRY4(local_dd0,uVar7);
        uVar7 = local_dd0 + uVar7;
        uVar16 = uVar11 + uVar10;
        uVar23 = (uVar13 & uVar20 ^ uVar9 & (uVar13 ^ uVar20)) +
                 ((uVar9 >> 0x1c | uVar5 * 0x10) ^ (uVar9 * 0x40000000 | uVar5 >> 2) ^
                 (uVar9 * 0x2000000 | uVar5 >> 7)) + (uint)CARRY4(uVar22,uVar14) + iVar18 +
                 (uint)CARRY4(uVar11,uVar10);
        local_dd0 = uVar17 + uVar7;
        local_dcc = (local_dc4 >> 6 ^
                    (local_dc4 >> 0x13 | local_dc8 * 0x2000) ^ (local_dc4 * 8 | local_dc8 >> 0x1d))
                    + local_dcc +
                      local_d3c +
                      (local_dbc >> 7 ^
                      (local_dbc >> 1 | local_dc0 << 0x1f) ^ (local_dbc >> 8 | local_dc0 << 0x18)) +
                      (uint)CARRY4(local_d40,uVar21) + (uint)bVar29 + (uint)CARRY4(uVar17,uVar7);
        uVar7 = local_d80 + *(uint *)(pcVar27 + -0x68);
        uVar10 = local_dd0 + uVar7;
        uVar21 = (uVar3 * 0x800000 | uVar6 >> 9) ^
                 (uVar3 >> 0xe | uVar6 * 0x40000) ^ (uVar3 >> 0x12 | uVar6 * 0x4000);
        uVar14 = uVar10 + uVar21;
        uVar22 = uVar8 & ~uVar3 ^ uVar2 & uVar3;
        uVar11 = uVar14 + uVar22;
        iVar18 = local_dcc +
                 local_d7c + *(int *)(pcVar27 + -100) +
                 (uint)CARRY4(local_d80,*(uint *)(pcVar27 + -0x68)) + (uint)CARRY4(local_dd0,uVar7)
                 + ((uVar6 * 0x800000 | uVar3 >> 9) ^
                   (uVar6 >> 0xe | uVar3 * 0x40000) ^ (uVar6 >> 0x12 | uVar3 * 0x4000)) +
                 (uint)CARRY4(uVar10,uVar21) +
                 (uVar15 & ~uVar6 ^ uVar4 & uVar6) + (uint)CARRY4(uVar14,uVar22);
        uVar10 = uVar11 + uVar12;
        uVar17 = iVar18 + uVar20 + CARRY4(uVar11,uVar12);
        uVar22 = (local_da0 >> 7 | local_d9c << 0x19) ^
                 (local_da0 >> 1 | local_d9c << 0x1f) ^ (local_da0 >> 8 | local_d9c << 0x18);
        uVar20 = local_d30 + uVar22;
        bVar29 = CARRY4(local_dc0,uVar20);
        uVar20 = local_dc0 + uVar20;
        uVar21 = (local_da8 >> 6 | local_da4 * 0x4000000) ^
                 (local_da8 >> 0x13 | local_da4 * 0x2000) ^ (local_da8 * 8 | local_da4 >> 0x1d);
        uVar12 = *(uint *)(pcVar27 + -0x60) + uVar8;
        local_dc0 = uVar20 + uVar21;
        local_dbc = local_dbc +
                    uStack_d2c +
                    (local_d9c >> 7 ^
                    (local_d9c >> 1 | local_da0 << 0x1f) ^ (local_d9c >> 8 | local_da0 << 0x18)) +
                    (uint)CARRY4(local_d30,uVar22) + (uint)bVar29 +
                    (local_da4 >> 6 ^
                    (local_da4 >> 0x13 | local_da8 * 0x2000) ^ (local_da4 * 8 | local_da8 >> 0x1d))
                    + (uint)CARRY4(uVar20,uVar21);
        uVar25 = (uVar16 >> 0x1c | uVar23 * 0x10) ^ (uVar16 * 0x40000000 | uVar23 >> 2) ^
                 (uVar16 * 0x2000000 | uVar23 >> 7);
        uVar21 = uVar5 & uVar1 ^ uVar16 & (uVar5 ^ uVar1);
        uVar22 = (uVar10 * 0x800000 | uVar17 >> 9) ^
                 (uVar10 >> 0xe | uVar17 * 0x40000) ^ (uVar10 >> 0x12 | uVar17 * 0x4000);
        uVar24 = uVar12 + local_dc0;
        uVar7 = uVar21 + uVar25;
        uVar20 = uVar22 + uVar24;
        uVar19 = uVar2 & ~uVar10 ^ uVar3 & uVar10;
        uVar14 = uVar7 + uVar11;
        uVar11 = (uVar9 & uVar13 ^ uVar23 & (uVar9 ^ uVar13)) +
                 ((uVar23 >> 0x1c | uVar16 * 0x10) ^ (uVar23 * 0x40000000 | uVar16 >> 2) ^
                 (uVar23 * 0x2000000 | uVar16 >> 7)) + (uint)CARRY4(uVar21,uVar25) +
                 iVar18 + (uint)CARRY4(uVar7,uVar11);
        uVar21 = uVar20 + uVar19;
        iVar18 = ((uVar17 * 0x800000 | uVar10 >> 9) ^
                 (uVar17 >> 0xe | uVar10 * 0x40000) ^ (uVar17 >> 0x12 | uVar10 * 0x4000)) +
                 *(int *)(pcVar27 + -0x5c) + uVar15 + (uint)CARRY4(*(uint *)(pcVar27 + -0x60),uVar8)
                 + local_dbc + (uint)CARRY4(uVar12,local_dc0) + (uint)CARRY4(uVar22,uVar24) +
                 (uVar4 & ~uVar17 ^ uVar6 & uVar17) + (uint)CARRY4(uVar20,uVar19);
        uVar22 = uVar21 + uVar1;
        uVar13 = iVar18 + uVar13 + CARRY4(uVar21,uVar1);
        uVar12 = (local_d78 >> 7 | local_d74 << 0x19) ^
                 (local_d78 >> 1 | local_d74 << 0x1f) ^ (local_d78 >> 8 | local_d74 << 0x18);
        uVar1 = local_db0 + uVar12;
        bVar29 = CARRY4(local_da0,uVar1);
        uVar1 = local_da0 + uVar1;
        uVar20 = (local_dd0 >> 6 | local_dcc * 0x4000000) ^
                 (local_dd0 >> 0x13 | local_dcc * 0x2000) ^ (local_dd0 * 8 | local_dcc >> 0x1d);
        local_da0 = uVar20 + uVar1;
        local_d9c = (local_dcc >> 6 ^
                    (local_dcc >> 0x13 | local_dd0 * 0x2000) ^ (local_dcc * 8 | local_dd0 >> 0x1d))
                    + local_d9c +
                      local_dac +
                      (local_d74 >> 7 ^
                      (local_d74 >> 1 | local_d78 << 0x1f) ^ (local_d74 >> 8 | local_d78 << 0x18)) +
                      (uint)CARRY4(local_db0,uVar12) + (uint)bVar29 + (uint)CARRY4(uVar20,uVar1);
        uVar7 = (uVar14 * 0x2000000 | uVar11 >> 7) ^
                (uVar14 >> 0x1c | uVar11 * 0x10) ^ (uVar14 * 0x40000000 | uVar11 >> 2);
        uVar1 = (uVar5 ^ uVar16) & uVar14 ^ uVar5 & uVar16;
        uVar19 = *(uint *)(pcVar27 + -0x58) + local_da0;
        uVar15 = uVar1 + uVar7;
        uVar20 = uVar19 + uVar2;
        uVar12 = (uVar22 * 0x800000 | uVar13 >> 9) ^
                 (uVar22 >> 0xe | uVar13 * 0x40000) ^ (uVar22 >> 0x12 | uVar13 * 0x4000);
        uVar8 = uVar15 + uVar21;
        uVar15 = ((uVar9 ^ uVar23) & uVar11 ^ uVar9 & uVar23) +
                 ((uVar11 * 0x2000000 | uVar14 >> 7) ^
                 (uVar11 >> 0x1c | uVar14 * 0x10) ^ (uVar11 * 0x40000000 | uVar14 >> 2)) +
                 (uint)CARRY4(uVar1,uVar7) + iVar18 + (uint)CARRY4(uVar15,uVar21);
        uVar1 = uVar12 + uVar20;
        uVar7 = uVar10 & uVar22 ^ uVar3 & ~uVar22;
        uVar21 = uVar7 + uVar1;
        iVar18 = (uVar17 & uVar13 ^ uVar6 & ~uVar13) +
                 ((uVar13 * 0x800000 | uVar22 >> 9) ^
                 (uVar13 >> 0xe | uVar22 * 0x40000) ^ (uVar13 >> 0x12 | uVar22 * 0x4000)) +
                 *(int *)(pcVar27 + -0x54) +
                 local_d9c + CARRY4(*(uint *)(pcVar27 + -0x58),local_da0) + uVar4 +
                 (uint)CARRY4(uVar19,uVar2) + (uint)CARRY4(uVar12,uVar20) +
                 (uint)CARRY4(uVar7,uVar1);
        uVar19 = uVar5 + uVar21;
        uVar9 = uVar9 + iVar18 + (uint)CARRY4(uVar5,uVar21);
        uVar1 = (local_d98 >> 7 | local_d94 << 0x19) ^
                (local_d98 >> 1 | local_d94 << 0x1f) ^ (local_d98 >> 8 | local_d94 << 0x18);
        uVar2 = local_d28 + uVar1;
        uVar20 = uVar16 & uVar14 ^ uVar8 & (uVar16 ^ uVar14);
        bVar29 = CARRY4(local_d78,uVar2);
        uVar2 = local_d78 + uVar2;
        uVar4 = (uVar8 * 0x2000000 | uVar15 >> 7) ^
                (uVar8 >> 0x1c | uVar15 * 0x10) ^ (uVar8 * 0x40000000 | uVar15 >> 2);
        uVar12 = uVar20 + uVar4;
        uVar7 = (local_dc0 >> 6 | local_dbc * 0x4000000) ^
                (local_dc0 >> 0x13 | local_dbc * 0x2000) ^ (local_dc0 * 8 | local_dbc >> 0x1d);
        local_d78 = uVar2 + uVar7;
        local_d74 = local_d74 +
                    uStack_d24 +
                    (local_d94 >> 7 ^
                    (local_d94 >> 1 | local_d98 << 0x1f) ^ (local_d94 >> 8 | local_d98 << 0x18)) +
                    (uint)CARRY4(local_d28,uVar1) + (uint)bVar29 +
                    (local_dbc >> 6 ^
                    (local_dbc >> 0x13 | local_dc0 * 0x2000) ^ (local_dbc * 8 | local_dc0 >> 0x1d))
                    + (uint)CARRY4(uVar2,uVar7);
        uVar2 = *(uint *)(pcVar27 + -0x50) + local_d78;
        uVar1 = uVar12 + uVar21;
        uVar7 = (uVar23 & uVar11 ^ uVar15 & (uVar23 ^ uVar11)) +
                ((uVar15 * 0x2000000 | uVar8 >> 7) ^
                (uVar15 >> 0x1c | uVar8 * 0x10) ^ (uVar15 * 0x40000000 | uVar8 >> 2)) +
                (uint)CARRY4(uVar20,uVar4) + iVar18 + (uint)CARRY4(uVar12,uVar21);
        uVar20 = (uVar19 * 0x800000 | uVar9 >> 9) ^
                 (uVar19 >> 0xe | uVar9 * 0x40000) ^ (uVar19 >> 0x12 | uVar9 * 0x4000);
        uVar21 = uVar3 + uVar2;
        uVar4 = uVar21 + uVar20;
        uVar12 = uVar10 & ~uVar19 ^ uVar22 & uVar19;
        uVar5 = uVar4 + uVar12;
        iVar18 = uVar6 + *(int *)(pcVar27 + -0x4c) +
                         local_d74 + CARRY4(*(uint *)(pcVar27 + -0x50),local_d78) +
                 (uint)CARRY4(uVar3,uVar2) +
                 ((uVar9 * 0x800000 | uVar19 >> 9) ^
                 (uVar9 >> 0xe | uVar19 * 0x40000) ^ (uVar9 >> 0x12 | uVar19 * 0x4000)) +
                 (uint)CARRY4(uVar21,uVar20) +
                 (uVar17 & ~uVar9 ^ uVar13 & uVar9) + (uint)CARRY4(uVar4,uVar12);
        uVar4 = uVar5 + uVar16;
        uVar6 = iVar18 + uVar23 + (uint)CARRY4(uVar5,uVar16);
        uVar20 = (local_d48 >> 7 | uStack_d44 << 0x19) ^
                 (local_d48 >> 1 | uStack_d44 << 0x1f) ^ (local_d48 >> 8 | uStack_d44 << 0x18);
        uVar21 = local_d08 + uVar20;
        uVar3 = (uVar1 >> 0x1c | uVar7 * 0x10) ^ (uVar1 * 0x40000000 | uVar7 >> 2) ^
                (uVar1 * 0x2000000 | uVar7 >> 7);
        uVar2 = uVar1 & (uVar8 ^ uVar14) ^ uVar8 & uVar14;
        bVar29 = CARRY4(uVar21,local_d98);
        uVar21 = uVar21 + local_d98;
        uVar12 = (local_da0 >> 6 | local_d9c * 0x4000000) ^
                 (local_da0 >> 0x13 | local_d9c * 0x2000) ^ (local_da0 * 8 | local_d9c >> 0x1d);
        uVar16 = uVar2 + uVar3;
        local_d98 = uVar12 + uVar21;
        local_d94 = (local_d9c >> 6 ^
                    (local_d9c >> 0x13 | local_da0 * 0x2000) ^ (local_d9c * 8 | local_da0 >> 0x1d))
                    + uStack_d04 +
                      (uStack_d44 >> 7 ^
                      (uStack_d44 >> 1 | local_d48 << 0x1f) ^ (uStack_d44 >> 8 | local_d48 << 0x18))
                      + (uint)CARRY4(local_d08,uVar20) + local_d94 + (uint)bVar29 +
                      (uint)CARRY4(uVar12,uVar21);
        uVar21 = uVar5 + uVar16;
        uVar2 = iVar18 + (uVar7 & (uVar15 ^ uVar11) ^ uVar15 & uVar11) +
                         ((uVar7 >> 0x1c | uVar1 * 0x10) ^ (uVar7 * 0x40000000 | uVar1 >> 2) ^
                         (uVar7 * 0x2000000 | uVar1 >> 7)) + (uint)CARRY4(uVar2,uVar3) +
                         (uint)CARRY4(uVar5,uVar16);
        uVar16 = *(uint *)(pcVar27 + -0x48) + local_d98;
        uVar12 = uVar10 + uVar16;
        uVar5 = (uVar4 >> 0xe | uVar6 * 0x40000) ^ (uVar4 >> 0x12 | uVar6 * 0x4000) ^
                (uVar4 * 0x800000 | uVar6 >> 9);
        uVar3 = uVar5 + uVar12;
        uVar20 = uVar22 & ~uVar4 ^ uVar19 & uVar4;
        uVar23 = uVar3 + uVar20;
        iVar18 = ((uVar6 >> 0xe | uVar4 * 0x40000) ^ (uVar6 >> 0x12 | uVar4 * 0x4000) ^
                 (uVar6 * 0x800000 | uVar4 >> 9)) +
                 uVar17 + *(int *)(pcVar27 + -0x44) + local_d94 +
                          (uint)CARRY4(*(uint *)(pcVar27 + -0x48),local_d98) +
                 (uint)CARRY4(uVar10,uVar16) + (uint)CARRY4(uVar5,uVar12) +
                 (uVar13 & ~uVar6 ^ uVar9 & uVar6) + (uint)CARRY4(uVar3,uVar20);
        uVar3 = uVar14 + uVar23;
        uVar11 = uVar11 + iVar18 + (uint)CARRY4(uVar14,uVar23);
        uVar14 = (local_d90 >> 7 | local_d8c << 0x19) ^
                 (local_d90 >> 1 | local_d8c << 0x1f) ^ (local_d90 >> 8 | local_d8c << 0x18);
        uVar10 = (uVar21 * 0x2000000 | uVar2 >> 7) ^
                 (uVar21 >> 0x1c | uVar2 * 0x10) ^ (uVar21 * 0x40000000 | uVar2 >> 2);
        uVar20 = uVar8 & uVar1 ^ uVar21 & (uVar8 ^ uVar1);
        uVar5 = local_dc8 + uVar14;
        uVar16 = uVar20 + uVar10;
        uVar12 = (local_d78 >> 6 | local_d74 * 0x4000000) ^
                 (local_d78 >> 0x13 | local_d74 * 0x2000) ^ (local_d78 * 8 | local_d74 >> 0x1d);
        bVar29 = CARRY4(local_d48,uVar5);
        uVar5 = local_d48 + uVar5;
        uVar25 = uVar16 + uVar23;
        uVar26 = (uVar15 & uVar7 ^ uVar2 & (uVar15 ^ uVar7)) +
                 ((uVar2 * 0x2000000 | uVar21 >> 7) ^
                 (uVar2 >> 0x1c | uVar21 * 0x10) ^ (uVar2 * 0x40000000 | uVar21 >> 2)) +
                 (uint)CARRY4(uVar20,uVar10) + iVar18 + (uint)CARRY4(uVar16,uVar23);
        local_d48 = uVar12 + uVar5;
        uStack_d44 = (local_d74 >> 6 ^
                     (local_d74 >> 0x13 | local_d78 * 0x2000) ^ (local_d74 * 8 | local_d78 >> 0x1d))
                     + uStack_d44 +
                       local_dc4 +
                       (local_d8c >> 7 ^
                       (local_d8c >> 1 | local_d90 << 0x1f) ^ (local_d8c >> 8 | local_d90 << 0x18))
                       + (uint)CARRY4(local_dc8,uVar14) + (uint)bVar29 + (uint)CARRY4(uVar12,uVar5);
        uVar10 = *(uint *)(pcVar27 + -0x40) + local_d48;
        uVar5 = uVar22 + uVar10;
        uVar20 = (uVar3 * 0x800000 | uVar11 >> 9) ^
                 (uVar3 >> 0xe | uVar11 * 0x40000) ^ (uVar3 >> 0x12 | uVar11 * 0x4000);
        uVar12 = uVar4 & uVar3 ^ uVar19 & ~uVar3;
        uVar16 = uVar20 + uVar5;
        uVar14 = uVar16 + uVar12;
        iVar18 = ((uVar11 * 0x800000 | uVar3 >> 9) ^
                 (uVar11 >> 0xe | uVar3 * 0x40000) ^ (uVar11 >> 0x12 | uVar3 * 0x4000)) +
                 uVar13 + *(int *)(pcVar27 + -0x3c) +
                          uStack_d44 + CARRY4(*(uint *)(pcVar27 + -0x40),local_d48) +
                 (uint)CARRY4(uVar22,uVar10) + (uint)CARRY4(uVar20,uVar5) +
                 (uVar6 & uVar11 ^ uVar9 & ~uVar11) + (uint)CARRY4(uVar16,uVar12);
        uVar10 = uVar14 + uVar8;
        uVar15 = iVar18 + uVar15 + (uint)CARRY4(uVar14,uVar8);
        uVar13 = (uVar25 * 0x2000000 | uVar26 >> 7) ^
                 (uVar25 >> 0x1c | uVar26 * 0x10) ^ (uVar25 * 0x40000000 | uVar26 >> 2);
        uVar20 = (uVar21 ^ uVar1) & uVar25 ^ uVar21 & uVar1;
        uVar22 = uVar20 + uVar13;
        uVar5 = (local_db8 >> 7 | local_db4 << 0x19) ^
                (local_db8 >> 1 | local_db4 << 0x1f) ^ (local_db8 >> 8 | local_db4 << 0x18);
        uVar12 = local_da8 + uVar5;
        uVar23 = uVar14 + uVar22;
        uVar24 = iVar18 + ((uVar2 ^ uVar7) & uVar26 ^ uVar2 & uVar7) +
                          ((uVar26 * 0x2000000 | uVar25 >> 7) ^
                          (uVar26 >> 0x1c | uVar25 * 0x10) ^ (uVar26 * 0x40000000 | uVar25 >> 2)) +
                          (uint)CARRY4(uVar20,uVar13) + (uint)CARRY4(uVar14,uVar22);
        uVar20 = (local_d98 >> 6 | local_d94 * 0x4000000) ^
                 (local_d98 >> 0x13 | local_d94 * 0x2000) ^ (local_d98 * 8 | local_d94 >> 0x1d);
        bVar29 = CARRY4(local_d90,uVar12);
        uVar12 = local_d90 + uVar12;
        local_d90 = uVar20 + uVar12;
        local_d8c = (local_d94 >> 6 ^
                    (local_d94 >> 0x13 | local_d98 * 0x2000) ^ (local_d94 * 8 | local_d98 >> 0x1d))
                    + local_d8c +
                      local_da4 +
                      (local_db4 >> 7 ^
                      (local_db4 >> 1 | local_db8 << 0x1f) ^ (local_db4 >> 8 | local_db8 << 0x18)) +
                      (uint)CARRY4(local_da8,uVar5) + (uint)bVar29 + (uint)CARRY4(uVar20,uVar12);
        uVar12 = *(uint *)(pcVar27 + -0x38) + local_d90;
        uVar13 = uVar19 + uVar12;
        uVar5 = (uVar10 * 0x800000 | uVar15 >> 9) ^
                (uVar10 >> 0xe | uVar15 * 0x40000) ^ (uVar10 >> 0x12 | uVar15 * 0x4000);
        uVar20 = uVar5 + uVar13;
        uVar22 = uVar4 & ~uVar10 ^ uVar3 & uVar10;
        uVar14 = uVar20 + uVar22;
        iVar18 = ((uVar15 * 0x800000 | uVar10 >> 9) ^
                 (uVar15 >> 0xe | uVar10 * 0x40000) ^ (uVar15 >> 0x12 | uVar10 * 0x4000)) +
                 uVar9 + *(int *)(pcVar27 + -0x34) + local_d8c +
                         (uint)CARRY4(*(uint *)(pcVar27 + -0x38),local_d90) +
                 (uint)CARRY4(uVar19,uVar12) + (uint)CARRY4(uVar5,uVar13) +
                 (uVar6 & ~uVar15 ^ uVar11 & uVar15) + (uint)CARRY4(uVar20,uVar22);
        uVar8 = uVar14 + uVar1;
        uVar16 = iVar18 + uVar7 + (uint)CARRY4(uVar14,uVar1);
        uVar1 = (uVar23 * 0x2000000 | uVar24 >> 7) ^
                (uVar23 >> 0x1c | uVar24 * 0x10) ^ (uVar23 * 0x40000000 | uVar24 >> 2);
        uVar22 = (uVar21 ^ uVar25) & uVar23 ^ uVar21 & uVar25;
        uVar20 = uVar1 + uVar22;
        uVar12 = (local_d68 >> 7 | local_d64 << 0x19) ^
                 (local_d68 >> 1 | local_d64 << 0x1f) ^ (local_d68 >> 8 | local_d64 << 0x18);
        uVar5 = uVar14 + uVar20;
        uVar14 = iVar18 + ((uVar24 * 0x2000000 | uVar23 >> 7) ^
                          (uVar24 >> 0x1c | uVar23 * 0x10) ^ (uVar24 * 0x40000000 | uVar23 >> 2)) +
                          ((uVar2 ^ uVar26) & uVar24 ^ uVar2 & uVar26) + (uint)CARRY4(uVar1,uVar22)
                 + (uint)CARRY4(uVar14,uVar20);
        uVar20 = local_dd0 + uVar12;
        uVar1 = (local_d48 >> 6 | uStack_d44 * 0x4000000) ^
                (local_d48 >> 0x13 | uStack_d44 * 0x2000) ^ (local_d48 * 8 | uStack_d44 >> 0x1d);
        bVar29 = CARRY4(local_db8,uVar20);
        uVar20 = local_db8 + uVar20;
        local_db8 = uVar1 + uVar20;
        local_db4 = (uStack_d44 >> 6 ^
                    (uStack_d44 >> 0x13 | local_d48 * 0x2000) ^ (uStack_d44 * 8 | local_d48 >> 0x1d)
                    ) + local_db4 +
                        local_dcc +
                        (local_d64 >> 7 ^
                        (local_d64 >> 1 | local_d68 << 0x1f) ^ (local_d64 >> 8 | local_d68 << 0x18))
                        + (uint)CARRY4(local_dd0,uVar12) + (uint)bVar29 + (uint)CARRY4(uVar1,uVar20)
        ;
        uVar12 = *(uint *)(pcVar27 + -0x30) + local_db8;
        uVar22 = uVar4 + uVar12;
        uVar7 = (uVar8 * 0x800000 | uVar16 >> 9) ^
                (uVar8 >> 0xe | uVar16 * 0x40000) ^ (uVar8 >> 0x12 | uVar16 * 0x4000);
        uVar13 = uVar10 & uVar8 ^ uVar3 & ~uVar8;
        uVar20 = uVar7 + uVar22;
        uVar1 = uVar13 + uVar20;
        iVar18 = (uVar15 & uVar16 ^ uVar11 & ~uVar16) +
                 ((uVar16 * 0x800000 | uVar8 >> 9) ^
                 (uVar16 >> 0xe | uVar8 * 0x40000) ^ (uVar16 >> 0x12 | uVar8 * 0x4000)) +
                 uVar6 + *(int *)(pcVar27 + -0x2c) + local_db4 +
                         (uint)CARRY4(*(uint *)(pcVar27 + -0x30),local_db8) +
                 (uint)CARRY4(uVar4,uVar12) + (uint)CARRY4(uVar7,uVar22) +
                 (uint)CARRY4(uVar13,uVar20);
        uVar9 = uVar1 + uVar21;
        uVar17 = iVar18 + uVar2 + (uint)CARRY4(uVar1,uVar21);
        uVar20 = (uVar5 * 0x2000000 | uVar14 >> 7) ^
                 (uVar5 >> 0x1c | uVar14 * 0x10) ^ (uVar5 * 0x40000000 | uVar14 >> 2);
        uVar21 = uVar25 & uVar23 ^ uVar5 & (uVar25 ^ uVar23);
        uVar12 = uVar20 + uVar21;
        uVar22 = uVar1 + uVar12;
        local_d34 = iVar18 + ((uVar14 * 0x2000000 | uVar5 >> 7) ^
                             (uVar14 >> 0x1c | uVar5 * 0x10) ^ (uVar14 * 0x40000000 | uVar5 >> 2)) +
                             (uVar26 & uVar24 ^ uVar14 & (uVar26 ^ uVar24)) +
                             (uint)CARRY4(uVar20,uVar21) + (uint)CARRY4(uVar1,uVar12);
        uVar21 = (local_d40 >> 7 | local_d3c << 0x19) ^
                 (local_d40 >> 1 | local_d3c << 0x1f) ^ (local_d40 >> 8 | local_d3c << 0x18);
        uVar20 = uVar21 + local_dc0;
        uVar1 = (local_d90 >> 0x13 | local_d8c * 0x2000) ^ (local_d90 * 8 | local_d8c >> 0x1d) ^
                (local_d90 >> 6 | local_d8c * 0x4000000);
        bVar29 = CARRY4(local_d68,uVar20);
        uVar20 = local_d68 + uVar20;
        local_d68 = uVar1 + uVar20;
        local_d64 = ((local_d8c >> 0x13 | local_d90 * 0x2000) ^ (local_d8c * 8 | local_d90 >> 0x1d)
                    ^ local_d8c >> 6) +
                    local_d64 +
                    (local_d3c >> 7 ^
                    (local_d3c >> 1 | local_d40 << 0x1f) ^ (local_d3c >> 8 | local_d40 << 0x18)) +
                    local_dbc + (uint)CARRY4(uVar21,local_dc0) + (uint)bVar29 +
                    (uint)CARRY4(uVar1,uVar20);
        uVar21 = *(uint *)(pcVar27 + -0x28) + local_d68;
        uVar1 = uVar3 + uVar21;
        uVar12 = (uVar9 * 0x800000 | uVar17 >> 9) ^
                 (uVar9 >> 0xe | uVar17 * 0x40000) ^ (uVar9 >> 0x12 | uVar17 * 0x4000);
        uVar13 = uVar8 & uVar9 ^ uVar10 & ~uVar9;
        uVar7 = uVar1 + uVar12;
        uVar20 = uVar13 + uVar7;
        iVar18 = (uVar16 & uVar17 ^ uVar15 & ~uVar17) +
                 uVar11 + *(int *)(pcVar27 + -0x24) + local_d64 +
                          (uint)CARRY4(*(uint *)(pcVar27 + -0x28),local_d68) +
                 (uint)CARRY4(uVar3,uVar21) +
                 ((uVar17 * 0x800000 | uVar9 >> 9) ^
                 (uVar17 >> 0xe | uVar9 * 0x40000) ^ (uVar17 >> 0x12 | uVar9 * 0x4000)) +
                 (uint)CARRY4(uVar1,uVar12) + (uint)CARRY4(uVar13,uVar7);
        uVar13 = uVar20 + uVar25;
        uVar3 = iVar18 + uVar26 + CARRY4(uVar20,uVar25);
        uVar1 = (uVar22 * 0x2000000 | local_d34 >> 7) ^
                (uVar22 >> 0x1c | local_d34 * 0x10) ^ (uVar22 * 0x40000000 | local_d34 >> 2);
        uVar21 = uVar5 & uVar23 ^ uVar22 & (uVar5 ^ uVar23);
        uVar12 = uVar21 + uVar1;
        uVar4 = uVar20 + uVar12;
        uVar6 = iVar18 + (uVar14 & uVar24 ^ local_d34 & (uVar14 ^ uVar24)) +
                         ((local_d34 * 0x2000000 | uVar22 >> 7) ^
                         (local_d34 >> 0x1c | uVar22 * 0x10) ^
                         (local_d34 * 0x40000000 | uVar22 >> 2)) + (uint)CARRY4(uVar21,uVar1) +
                (uint)CARRY4(uVar20,uVar12);
        uVar21 = (local_d30 >> 7 | uStack_d2c << 0x19) ^
                 (local_d30 >> 1 | uStack_d2c << 0x1f) ^ (local_d30 >> 8 | uStack_d2c << 0x18);
        uVar1 = local_da0 + uVar21;
        uVar20 = (local_db8 >> 6 | local_db4 * 0x4000000) ^
                 (local_db8 >> 0x13 | local_db4 * 0x2000) ^ (local_db8 * 8 | local_db4 >> 0x1d);
        bVar29 = CARRY4(local_d40,uVar1);
        uVar1 = local_d40 + uVar1;
        local_d40 = uVar20 + uVar1;
        local_d3c = (local_db4 >> 6 ^
                    (local_db4 >> 0x13 | local_db8 * 0x2000) ^ (local_db4 * 8 | local_db8 >> 0x1d))
                    + local_d3c +
                      local_d9c +
                      (uStack_d2c >> 7 ^
                      (uStack_d2c >> 1 | local_d30 << 0x1f) ^ (uStack_d2c >> 8 | local_d30 << 0x18))
                      + (uint)CARRY4(local_da0,uVar21) + (uint)bVar29 + (uint)CARRY4(uVar20,uVar1);
        uVar7 = *(uint *)(pcVar27 + -0x20) + local_d40;
        uVar2 = (uVar13 * 0x800000 | uVar3 >> 9) ^
                (uVar13 >> 0xe | uVar3 * 0x40000) ^ (uVar13 >> 0x12 | uVar3 * 0x4000);
        uVar21 = uVar10 + uVar7;
        uVar1 = uVar21 + uVar2;
        uVar12 = uVar8 & ~uVar13 ^ uVar9 & uVar13;
        uVar20 = uVar12 + uVar1;
        iVar18 = (uVar16 & ~uVar3 ^ uVar17 & uVar3) +
                 uVar15 + *(int *)(pcVar27 + -0x1c) +
                          local_d3c + CARRY4(*(uint *)(pcVar27 + -0x20),local_d40) +
                 (uint)CARRY4(uVar10,uVar7) +
                 ((uVar3 * 0x800000 | uVar13 >> 9) ^
                 (uVar3 >> 0xe | uVar13 * 0x40000) ^ (uVar3 >> 0x12 | uVar13 * 0x4000)) +
                 (uint)CARRY4(uVar21,uVar2) + (uint)CARRY4(uVar12,uVar1);
        uVar21 = (uVar4 * 0x2000000 | uVar6 >> 7) ^
                 (uVar4 >> 0x1c | uVar6 * 0x10) ^ (uVar4 * 0x40000000 | uVar6 >> 2);
        uVar12 = uVar4 & (uVar5 ^ uVar22) ^ uVar5 & uVar22;
        uVar7 = uVar21 + uVar12;
        local_d18 = uVar20 + uVar23;
        local_d14 = iVar18 + uVar24 + CARRY4(uVar20,uVar23);
        uVar1 = uVar20 + uVar7;
        uVar7 = iVar18 + ((uVar6 * 0x2000000 | uVar4 >> 7) ^
                         (uVar6 >> 0x1c | uVar4 * 0x10) ^ (uVar6 * 0x40000000 | uVar4 >> 2)) +
                         (uVar6 & (uVar14 ^ local_d34) ^ uVar14 & local_d34) +
                         (uint)CARRY4(uVar21,uVar12) + (uint)CARRY4(uVar20,uVar7);
        uVar21 = (local_db0 >> 7 | local_dac << 0x19) ^
                 (local_db0 >> 1 | local_dac << 0x1f) ^ (local_db0 >> 8 | local_dac << 0x18);
        uVar20 = local_d78 + uVar21;
        uVar12 = (local_d68 >> 6 | local_d64 * 0x4000000) ^
                 (local_d68 >> 0x13 | local_d64 * 0x2000) ^ (local_d68 * 8 | local_d64 >> 0x1d);
        bVar29 = CARRY4(local_d30,uVar20);
        uVar20 = local_d30 + uVar20;
        local_d30 = uVar12 + uVar20;
        uStack_d2c = (local_d64 >> 6 ^
                     (local_d64 >> 0x13 | local_d68 * 0x2000) ^ (local_d64 * 8 | local_d68 >> 0x1d))
                     + uStack_d2c +
                       local_d74 +
                       (local_dac >> 7 ^
                       (local_dac >> 1 | local_db0 << 0x1f) ^ (local_dac >> 8 | local_db0 << 0x18))
                       + (uint)CARRY4(local_d78,uVar21) + (uint)bVar29 + (uint)CARRY4(uVar12,uVar20)
        ;
        uVar11 = *(uint *)(pcVar27 + -0x18) + local_d30;
        uVar20 = uVar8 + uVar11;
        uVar21 = (local_d18 * 0x800000 | local_d14 >> 9) ^
                 (local_d18 >> 0xe | local_d14 * 0x40000) ^ (local_d18 >> 0x12 | local_d14 * 0x4000)
        ;
        uVar12 = uVar21 + uVar20;
        uVar2 = uVar9 & ~local_d18 ^ uVar13 & local_d18;
        uVar10 = uVar12 + uVar2;
        iVar18 = ((local_d14 * 0x800000 | local_d18 >> 9) ^
                 (local_d14 >> 0xe | local_d18 * 0x40000) ^ (local_d14 >> 0x12 | local_d18 * 0x4000)
                 ) + uVar16 + *(int *)(pcVar27 + -0x14) +
                              uStack_d2c + CARRY4(*(uint *)(pcVar27 + -0x18),local_d30) +
                     (uint)CARRY4(uVar8,uVar11) + (uint)CARRY4(uVar21,uVar20) +
                 (uVar17 & ~local_d14 ^ uVar3 & local_d14) + (uint)CARRY4(uVar12,uVar2);
        local_d58 = uVar10 + uVar5;
        local_d54 = iVar18 + uVar14 + CARRY4(uVar10,uVar5);
        uVar20 = (uVar1 * 0x2000000 | uVar7 >> 7) ^
                 (uVar1 >> 0x1c | uVar7 * 0x10) ^ (uVar1 * 0x40000000 | uVar7 >> 2);
        uVar21 = uVar4 & uVar22 ^ (uVar4 ^ uVar22) & uVar1;
        uVar12 = uVar21 + uVar20;
        local_d60 = uVar10 + uVar12;
        local_d5c = iVar18 + (uVar6 & local_d34 ^ (uVar6 ^ local_d34) & uVar7) +
                             ((uVar7 * 0x2000000 | uVar1 >> 7) ^
                             (uVar7 >> 0x1c | uVar1 * 0x10) ^ (uVar7 * 0x40000000 | uVar1 >> 2)) +
                             (uint)CARRY4(uVar21,uVar20) + (uint)CARRY4(uVar10,uVar12);
        uVar12 = (local_d28 >> 7 | uStack_d24 << 0x19) ^
                 (local_d28 >> 1 | uStack_d24 << 0x1f) ^ (local_d28 >> 8 | uStack_d24 << 0x18);
        uVar20 = local_d98 + uVar12;
        uVar21 = (local_d40 >> 6 | local_d3c * 0x4000000) ^
                 (local_d40 >> 0x13 | local_d3c * 0x2000) ^ (local_d40 * 8 | local_d3c >> 0x1d);
        bVar29 = CARRY4(local_db0,uVar20);
        uVar20 = local_db0 + uVar20;
        local_db0 = uVar21 + uVar20;
        local_dac = (local_d3c >> 6 ^
                    (local_d3c >> 0x13 | local_d40 * 0x2000) ^ (local_d3c * 8 | local_d40 >> 0x1d))
                    + local_dac +
                      local_d94 +
                      (uStack_d24 >> 7 ^
                      (uStack_d24 >> 1 | local_d28 << 0x1f) ^ (uStack_d24 >> 8 | local_d28 << 0x18))
                      + (uint)CARRY4(local_d98,uVar12) + (uint)bVar29 + (uint)CARRY4(uVar21,uVar20);
        uVar5 = *(uint *)(pcVar27 + -0x10) + local_db0;
        uVar20 = (local_d58 * 0x800000 | local_d54 >> 9) ^
                 (local_d58 >> 0xe | local_d54 * 0x40000) ^ (local_d58 >> 0x12 | local_d54 * 0x4000)
        ;
        uVar12 = uVar9 + uVar5;
        uVar2 = local_d18 & local_d58 ^ uVar13 & ~local_d58;
        uVar21 = uVar12 + uVar20;
        uVar14 = uVar21 + uVar2;
        iVar18 = uVar17 + *(int *)(pcVar27 + -0xc) +
                          local_dac + CARRY4(*(uint *)(pcVar27 + -0x10),local_db0) +
                 (uint)CARRY4(uVar9,uVar5) +
                 ((local_d54 * 0x800000 | local_d58 >> 9) ^
                 (local_d54 >> 0xe | local_d58 * 0x40000) ^ (local_d54 >> 0x12 | local_d58 * 0x4000)
                 ) + (uint)CARRY4(uVar12,uVar20) +
                 (local_d14 & local_d54 ^ uVar3 & ~local_d54) + (uint)CARRY4(uVar21,uVar2);
        uVar20 = (local_d60 * 0x2000000 | local_d5c >> 7) ^
                 (local_d60 >> 0x1c | local_d5c * 0x10) ^ (local_d60 * 0x40000000 | local_d5c >> 2);
        local_d38 = uVar22 + uVar14;
        local_d34 = local_d34 + iVar18 + (uint)CARRY4(uVar22,uVar14);
        uVar21 = local_d60 & (uVar4 ^ uVar1) ^ uVar4 & uVar1;
        uVar12 = uVar20 + uVar21;
        local_d10 = uVar12 + uVar14;
        uStack_d0c = ((local_d5c * 0x2000000 | local_d60 >> 7) ^
                     (local_d5c >> 0x1c | local_d60 * 0x10) ^
                     (local_d5c * 0x40000000 | local_d60 >> 2)) +
                     (local_d5c & (uVar6 ^ uVar7) ^ uVar6 & uVar7) + (uint)CARRY4(uVar20,uVar21) +
                     iVar18 + (uint)CARRY4(uVar12,uVar14);
        uVar20 = (local_d08 >> 7 | uStack_d04 * 0x2000000) ^
                 (local_d08 >> 1 | uStack_d04 * -0x80000000) ^
                 (local_d08 >> 8 | uStack_d04 * 0x1000000);
        uVar21 = (local_d30 >> 6 | uStack_d2c * 0x4000000) ^
                 (local_d30 >> 0x13 | uStack_d2c * 0x2000) ^ (local_d30 * 8 | uStack_d2c >> 0x1d);
        uVar12 = local_d48 + uVar20;
        bVar29 = CARRY4(local_d28,uVar12);
        uVar12 = local_d28 + uVar12;
        local_d28 = uVar21 + uVar12;
        uStack_d24 = (uStack_d2c >> 6 ^
                     (uStack_d2c >> 0x13 | local_d30 * 0x2000) ^
                     (uStack_d2c * 8 | local_d30 >> 0x1d)) +
                     uStack_d24 +
                     uStack_d44 +
                     (uStack_d04 >> 7 ^
                     (uStack_d04 >> 1 | local_d08 * -0x80000000) ^
                     (uStack_d04 >> 8 | local_d08 * 0x1000000)) + (uint)CARRY4(local_d48,uVar20) +
                     (uint)bVar29 + (uint)CARRY4(uVar21,uVar12);
        uVar5 = (local_d38 * 0x800000 | local_d34 >> 9) ^
                (local_d38 >> 0xe | local_d34 * 0x40000) ^ (local_d38 >> 0x12 | local_d34 * 0x4000);
        uVar20 = *(uint *)(pcVar27 + -8) + local_d28;
        uVar8 = uVar13 + uVar20;
        uVar12 = uVar5 + uVar8;
        uVar21 = local_d18 & ~local_d38 ^ local_d58 & local_d38;
        uVar22 = (local_d10 * 0x2000000 | uStack_d0c >> 7) ^
                 (local_d10 >> 0x1c | uStack_d0c * 0x10) ^
                 (local_d10 * 0x40000000 | uStack_d0c >> 2);
        uVar2 = local_d10 & (local_d60 ^ uVar1) ^ local_d60 & uVar1;
        uVar14 = uVar12 + uVar21;
        iVar18 = ((local_d34 * 0x800000 | local_d38 >> 9) ^
                 (local_d34 >> 0xe | local_d38 * 0x40000) ^ (local_d34 >> 0x12 | local_d38 * 0x4000)
                 ) + uVar3 + *(int *)(pcVar27 + -4) +
                             uStack_d24 + CARRY4(*(uint *)(pcVar27 + -8),local_d28) +
                             (uint)CARRY4(uVar13,uVar20) + (uint)CARRY4(uVar5,uVar8) +
                 (local_d14 & ~local_d34 ^ local_d54 & local_d34) + (uint)CARRY4(uVar12,uVar21);
        uVar20 = uVar2 + uVar22;
        local_d80 = uVar4 + uVar14;
        local_d7c = uVar6 + iVar18 + (uint)CARRY4(uVar4,uVar14);
        uVar12 = uVar14 + uVar20;
        uVar20 = iVar18 + (uStack_d0c & (local_d5c ^ uVar7) ^ local_d5c & uVar7) +
                          ((uStack_d0c * 0x2000000 | local_d10 >> 7) ^
                          (uStack_d0c >> 0x1c | local_d10 * 0x10) ^
                          (uStack_d0c * 0x40000000 | local_d10 >> 2)) + (uint)CARRY4(uVar2,uVar22) +
                          (uint)CARRY4(uVar14,uVar20);
        pcVar27 = pcVar28;
      } while (pcVar28 != "_enc");
      bVar29 = CARRY4(local_bf0,uVar12);
      local_bf0 = local_bf0 + uVar12;
      uStack_bec = uStack_bec + uVar20 + bVar29;
      bVar29 = CARRY4(local_d10,local_6e0);
      local_6e0 = local_d10 + local_6e0;
      uStack_6dc = uStack_d0c + uStack_6dc + (uint)bVar29;
      bVar29 = CARRY4(local_d60,local_6c8);
      local_6c8 = local_d60 + local_6c8;
      uStack_6c4 = local_d5c + uStack_6c4 + bVar29;
      bVar29 = CARRY4(uVar1,local_530);
      local_530 = uVar1 + local_530;
      uStack_52c = uVar7 + uStack_52c + (uint)bVar29;
      bVar29 = CARRY4(local_d80,local_be8);
      local_be8 = local_d80 + local_be8;
      local_be4 = local_d7c + local_be4 + (uint)bVar29;
      bVar29 = CARRY4(local_d38,local_6d0);
      local_6d0 = local_d38 + local_6d0;
      uStack_6cc = local_d34 + uStack_6cc + (uint)bVar29;
      bVar29 = CARRY4(local_d58,local_6c0);
      local_6c0 = local_d58 + local_6c0;
      uStack_6bc = local_d54 + uStack_6bc + (uint)bVar29;
      bVar29 = CARRY4(local_d18,local_528);
      local_528 = local_d18 + local_528;
      uStack_524 = local_d14 + uStack_524 + (uint)bVar29;
      *param_1 = local_bf0;
      param_1[1] = uStack_bec;
      local_30 = local_30 + -1;
      param_1[2] = local_6e0;
      param_1[3] = uStack_6dc;
      local_d70 = local_d70 + 0x80;
      param_1[4] = local_6c8;
      param_1[5] = uStack_6c4;
      param_1[6] = local_530;
      param_1[7] = uStack_52c;
      param_1[8] = local_be8;
      param_1[9] = local_be4;
      param_1[10] = local_6d0;
      param_1[0xb] = uStack_6cc;
      param_1[0xc] = local_6c0;
      param_1[0xd] = uStack_6bc;
      param_1[0xe] = local_528;
      param_1[0xf] = uStack_524;
    } while (local_30 != -1);
  }
  return;
}


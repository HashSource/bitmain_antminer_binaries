
void x25519_sc_reduce(byte *param_1)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  longlong lVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  uint uVar28;
  int iVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int iVar39;
  uint uVar40;
  int iVar41;
  uint uVar42;
  int iVar43;
  int iVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  uint uVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  uint uVar54;
  uint uVar55;
  uint uVar56;
  uint uVar57;
  uint uVar58;
  uint uVar59;
  uint uVar60;
  uint uVar61;
  uint uVar62;
  uint uVar63;
  uint uVar64;
  uint uVar65;
  uint uVar66;
  int iVar67;
  uint uVar68;
  uint uVar69;
  uint uVar70;
  uint uVar71;
  uint uVar72;
  uint uVar73;
  uint uVar74;
  uint uVar75;
  uint uVar76;
  int iVar77;
  int iVar78;
  uint uVar79;
  uint uVar80;
  uint uVar81;
  uint uVar82;
  uint uVar83;
  uint uVar84;
  uint uVar85;
  byte local_160;
  uint local_148;
  int local_144;
  byte local_140;
  undefined4 local_138;
  int local_134;
  byte local_130;
  undefined4 local_128;
  int local_124;
  uint local_120;
  int local_11c;
  uint local_110;
  int local_10c;
  uint local_108;
  int local_104;
  uint local_100;
  int local_fc;
  uint local_f8;
  int local_f4;
  undefined4 local_f0;
  int local_ec;
  uint local_e8;
  int local_e4;
  uint local_d8;
  int local_d4;
  undefined4 local_d0;
  int local_cc;
  undefined4 local_c8;
  int local_c4;
  undefined4 local_c0;
  int local_bc;
  undefined4 local_b8;
  int local_b4;
  uint local_b0;
  int local_ac;
  undefined4 local_60;
  int iStack_5c;
  
  uVar18 = *(uint *)(param_1 + 0x3c) >> 3;
  uVar31 = *(uint *)(param_1 + 0x39) >> 6 & 0x1fffff;
  uVar16 = ((uint)param_1[0x38] << 8 | (uint)param_1[0x39] << 0x10 | (uint)param_1[0x37]) >> 1 &
           0x1fffff;
  uVar15 = *(uint *)(param_1 + 0x34) >> 4 & 0x1fffff;
  uVar45 = ((uint)param_1[0x31] << 0x10 | (uint)param_1[0x30] << 8 | (uint)param_1[0x2f]) >> 2 &
           0x1fffff;
  uVar38 = *(uint *)(param_1 + 0x31) >> 7 & 0x1fffff;
  local_148 = (uint)param_1[1] << 8;
  lVar1 = (ulonglong)uVar18 * 0x215d1 +
          (ulonglong)
          (((uint)param_1[0x28] << 8 | (uint)param_1[0x29] << 0x10 | (uint)param_1[0x27]) >> 3);
  uVar56 = (param_1[2] & 0x1f) << 0x10 | local_148;
  uVar19 = *(uint *)(param_1 + 0x2c) >> 5 & 0x1fffff;
  uVar2 = (ulonglong)uVar16 * 0xa2c13 +
          ((ulonglong)(*(uint *)(param_1 + 0x17) >> 5) & 0xffffffff001fffff);
  lVar9 = (ulonglong)uVar16 * 0x72d18 +
          (ulonglong)uVar31 * 0xa2c13 +
          (ulonglong)
          (((uint)param_1[0x1a] | (uint)param_1[0x1b] << 8 | (uint)param_1[0x1c] << 0x10) >> 2 &
          0x1fffff) + (ulonglong)uVar15 * 0x9fb67;
  uVar8 = (ulonglong)uVar15 * 0xa2c13 +
          (ulonglong)
          ((uint)param_1[0x15] | (uint)param_1[0x16] << 8 | (param_1[0x17] & 0x1f) << 0x10);
  lVar6 = (ulonglong)uVar18 * 0xa2c13 + (ulonglong)(*(uint *)(param_1 + 0x1c) >> 7 & 0x1fffff) +
          (ulonglong)uVar31 * 0x72d18 + (ulonglong)uVar16 * 0x9fb67;
  uVar3 = (ulonglong)uVar15 * 0x72d18 + (uVar2 & 0xffffffff);
  lVar4 = (ulonglong)uVar38 * 0x72d18 + (uVar8 & 0xffffffff) +
          CONCAT44((int)(uVar8 >> 0x20),(int)((ulonglong)uVar45 * 0x9fb67));
  iVar39 = (int)((ulonglong)uVar45 * 0x9fb67 >> 0x20) + (int)((ulonglong)lVar4 >> 0x20);
  uVar21 = (uint)lVar4;
  lVar10 = (ulonglong)uVar18 * 0xfff59083 +
           CONCAT44(-uVar18,(uint)param_1[0x2a] |
                            (param_1[0x2c] & 0x1f) << 0x10 | (uint)param_1[0x2b] << 8);
  uVar8 = (ulonglong)uVar18 * 0x9fb67 +
          (ulonglong)
          (((uint)param_1[0x22] | (uint)param_1[0x23] << 8 | (uint)param_1[0x24] << 0x10) >> 1 &
          0x1fffff) +
          CONCAT44((int)((ulonglong)uVar31 * 0xfff0c653 >> 0x20) + -uVar31,
                   (int)((ulonglong)uVar31 * 0xfff0c653));
  local_60 = (undefined4)lVar1;
  iStack_5c = (int)((ulonglong)lVar1 >> 0x20);
  lVar1 = (ulonglong)uVar31 * 0xfff59083 + CONCAT44(-uVar31,local_60);
  uVar32 = (uint)lVar1;
  lVar7 = (ulonglong)uVar16 * 0x215d1 + (uVar8 & 0xffffffff) +
          CONCAT44((int)(uVar8 >> 0x20),(int)((ulonglong)uVar15 * 0xfff59083));
  uVar17 = (uint)lVar7;
  lVar5 = (ulonglong)uVar15 * 0xfff0c653 + CONCAT44(-uVar15,(int)lVar6);
  lVar4 = (ulonglong)uVar38 * 0x9fb67 + (uVar3 & 0xffffffff);
  local_10c = (int)((ulonglong)uVar38 * 0xa2c13 >> 0x20);
  lVar12 = (ulonglong)uVar38 * 0x215d1 +
           CONCAT44((int)((ulonglong)lVar6 >> 0x20) + (int)((ulonglong)lVar5 >> 0x20),(int)lVar5);
  local_110 = (uint)((ulonglong)uVar38 * 0xa2c13);
  uVar20 = ((uint)param_1[0x14] << 0x10 | (uint)param_1[0x13] << 8 | (uint)param_1[0x12]) >> 3;
  lVar11 = (ulonglong)uVar18 * 0x72d18 + (ulonglong)(*(uint *)(param_1 + 0x1f) >> 4 & 0x1fffff) +
           (ulonglong)uVar31 * 0x9fb67 +
           CONCAT44((int)((ulonglong)uVar16 * 0xfff0c653 >> 0x20) + -uVar16,
                    (int)((ulonglong)uVar16 * 0xfff0c653)) + (ulonglong)uVar15 * 0x215d1 +
           CONCAT44((int)((ulonglong)uVar38 * 0xfff59083 >> 0x20) + -uVar38,
                    (int)((ulonglong)uVar38 * 0xfff59083));
  local_134 = (int)((ulonglong)uVar16 * 0xfff59083 >> 0x20);
  local_138 = (undefined4)((ulonglong)uVar16 * 0xfff59083);
  lVar13 = (ulonglong)uVar31 * 0x215d1 +
           (ulonglong)uVar18 * 0xfff0c653 +
           (CONCAT44(-uVar18,*(uint *)(param_1 + 0x24) >> 6) & 0xffffffff001fffff) +
           CONCAT44(local_134 + -uVar16,local_138);
  lVar14 = (ulonglong)uVar45 * 0xa2c13 + (ulonglong)(*(uint *)(param_1 + 0xf) >> 6 & 0x1fffff);
  lVar5 = (ulonglong)uVar45 * 0x72d18 + (ulonglong)(local_110 + uVar20);
  uVar16 = (uint)lVar5;
  lVar6 = (ulonglong)uVar45 * 0xfff0c653 + CONCAT44(-uVar45,(int)lVar4);
  uVar18 = (uint)lVar6;
  local_11c = (int)((ulonglong)uVar45 * 0x215d1 >> 0x20);
  local_120 = (uint)((ulonglong)uVar45 * 0x215d1);
  uVar23 = (uint)((ulonglong)(lVar11 + 0x100000) >> 0x20);
  lVar9 = (ulonglong)uVar38 * 0xfff0c653 + CONCAT44(-uVar38,(int)lVar9) +
          CONCAT44((int)((ulonglong)lVar9 >> 0x20),local_120);
  uVar31 = (uint)lVar9;
  local_11c = local_11c + (int)((ulonglong)lVar9 >> 0x20);
  uVar24 = (uint)(lVar11 + 0x100000) >> 0x15;
  uVar51 = local_11c + (uint)(0xffefffff < uVar31);
  uVar57 = uVar31 + 0x100000 >> 0x15;
  uVar58 = uVar57 | uVar51 * 0x800;
  iVar25 = (int)((ulonglong)(lVar14 + 0x100000) >> 0x20);
  uVar26 = (uint)(lVar14 + 0x100000) >> 0x15;
  iVar27 = iVar39 + (uint)(0xffefffff < uVar21);
  uVar75 = uVar24 | uVar23 * 0x800;
  uVar76 = uVar26 | iVar25 * 0x800;
  uVar28 = uVar21 + 0x100000 >> 0x15;
  uVar84 = uVar28 | iVar27 * 0x800;
  lVar9 = (ulonglong)uVar45 * 0xfff59083 + CONCAT44(-uVar45,(int)lVar12);
  uVar45 = (uint)lVar9;
  uVar38 = uVar45 + uVar58;
  iVar29 = (int)((ulonglong)lVar12 >> 0x20) + (int)((ulonglong)lVar9 >> 0x20) +
           ((int)uVar51 >> 0x15) + (uint)CARRY4(uVar45,uVar58);
  uVar45 = uVar17 + uVar75;
  iVar33 = (int)((ulonglong)uVar15 * 0xfff59083 >> 0x20) + -uVar15 + (int)((ulonglong)lVar7 >> 0x20)
           + ((int)uVar23 >> 0x15) + (uint)CARRY4(uVar17,uVar75);
  uVar58 = uVar16 + uVar76;
  iVar34 = local_10c + (uint)CARRY4(local_110,uVar20) + (int)((ulonglong)lVar5 >> 0x20) +
           (uint)CARRY4(uVar16,uVar76);
  uVar75 = uVar18 + uVar84;
  iVar35 = (int)(uVar2 >> 0x20) + (int)(uVar3 >> 0x20) + (int)((ulonglong)lVar4 >> 0x20) +
           (int)((ulonglong)lVar6 >> 0x20) + (uint)CARRY4(uVar18,uVar84);
  uVar20 = (uint)((ulonglong)(lVar13 + 0x100000) >> 0x20);
  uVar15 = (uint)(lVar13 + 0x100000) >> 0x15;
  uVar40 = iVar29 + (uint)(0xffefffff < uVar38);
  uVar76 = uVar38 + 0x100000 >> 0x15;
  uVar84 = uVar15 | uVar20 * 0x800;
  uVar16 = uVar76 | uVar40 * 0x800;
  uVar52 = iVar33 + (uint)(0xffefffff < uVar45);
  iVar77 = iVar34 + (uint)(0xffefffff < uVar58);
  uVar17 = uVar58 + 0x100000 >> 0x15;
  uVar36 = uVar32 + uVar84;
  uVar18 = uVar17 | iVar77 * 0x800;
  iVar41 = iStack_5c + (int)((ulonglong)lVar1 >> 0x20) +
           ((int)uVar20 >> 0x15) + (uint)CARRY4(uVar32,uVar84);
  uVar42 = iVar35 + (uint)(0xffefffff < uVar75);
  uVar59 = uVar31 + uVar57 * -0x200000;
  uVar84 = uVar75 + 0x100000 >> 0x15;
  uVar85 = uVar84 | uVar42 * 0x800;
  uVar46 = uVar45 + 0x100000 >> 0x15;
  uVar47 = uVar46 | uVar52 * 0x800;
  uVar48 = uVar38 + uVar76 * -0x200000;
  uVar32 = (uint)((ulonglong)(lVar10 + 0x100000) >> 0x20);
  uVar49 = (uint)(lVar10 + 0x100000) >> 0x15;
  uVar50 = uVar49 | uVar32 * 0x800;
  uVar60 = (uint)lVar11 + uVar24 * -0x200000;
  uVar37 = uVar16 + uVar60;
  iVar43 = ((int)uVar40 >> 0x15) +
           (((int)((ulonglong)lVar11 >> 0x20) - (((int)uVar23 >> 0x15) << 0x15 | uVar23 & 0x1fffff))
           - (uint)((uint)lVar11 < uVar24 * 0x200000)) + (uint)CARRY4(uVar16,uVar60);
  uVar61 = uVar19 + uVar50;
  iVar22 = ((int)uVar32 >> 0x15) + (uint)CARRY4(uVar19,uVar50);
  uVar24 = uVar21 + uVar28 * -0x200000;
  uVar16 = (uint)lVar13 + uVar15 * -0x200000;
  uVar60 = uVar18 + uVar24;
  uVar69 = uVar75 + uVar84 * -0x200000;
  uVar50 = uVar47 + uVar16;
  iVar44 = ((int)uVar52 >> 0x15) +
           (((int)((ulonglong)lVar13 >> 0x20) - (((int)uVar20 >> 0x15) << 0x15 | uVar20 & 0x1fffff))
           - (uint)((uint)lVar13 < uVar15 * 0x200000)) + (uint)CARRY4(uVar47,uVar16);
  uVar23 = (uint)lVar10 + uVar49 * -0x200000;
  uVar15 = uVar45 + uVar46 * -0x200000;
  iVar33 = (iVar33 - (((int)uVar52 >> 0x15) << 0x15 | uVar52 & 0x1fffff)) -
           (uint)(uVar45 < uVar46 * 0x200000);
  uVar16 = uVar36 + 0x100000 >> 0x15;
  uVar46 = iVar41 + (uint)(0xffefffff < uVar36);
  uVar19 = uVar16 | uVar46 * 0x800;
  uVar20 = uVar23 + uVar19;
  iVar30 = (((int)((ulonglong)lVar10 >> 0x20) - (((int)uVar32 >> 0x15) << 0x15 | uVar32 & 0x1fffff))
           - (uint)((uint)lVar10 < uVar49 * 0x200000)) + ((int)uVar46 >> 0x15) +
           (uint)CARRY4(uVar23,uVar19);
  uVar45 = uVar36 + uVar16 * -0x200000;
  iVar41 = (iVar41 - (((int)uVar46 >> 0x15) << 0x15 | uVar46 & 0x1fffff)) -
           (uint)(uVar36 < uVar16 * 0x200000);
  lVar1 = (ulonglong)uVar61 * 0x9fb67 + CONCAT44(iVar22 * 0x9fb67,uVar58 + uVar17 * -0x200000);
  local_ec = (int)((ulonglong)uVar20 * 0x72d18 >> 0x20);
  local_f0 = (undefined4)((ulonglong)uVar20 * 0x72d18);
  lVar9 = CONCAT44(iVar30 * 0x72d18 + local_ec,local_f0);
  lVar7 = (ulonglong)uVar20 * 0xfff0c653 + CONCAT44(iVar30 * -0xf39ad + -uVar20,(int)lVar1);
  local_cc = (int)((ulonglong)uVar45 * 0x9fb67 >> 0x20);
  local_e4 = (int)((ulonglong)uVar20 * 0x9fb67 >> 0x20);
  local_d0 = (undefined4)((ulonglong)uVar45 * 0x9fb67);
  lVar10 = CONCAT44(iVar41 * 0x9fb67 + local_cc,local_d0);
  iVar78 = iVar30 * 0x9fb67 + local_e4;
  local_e8 = (uint)((ulonglong)uVar20 * 0x9fb67);
  lVar11 = (ulonglong)uVar61 * 0x72d18 +
           CONCAT44(iVar22 * 0x72d18,(uint)lVar14 + uVar26 * -0x200000) +
           CONCAT44(((int)((ulonglong)lVar14 >> 0x20) - iVar25) -
                    (uint)((uint)lVar14 < uVar26 * 0x200000),local_e8);
  uVar32 = (uint)lVar11;
  local_d4 = (int)((ulonglong)uVar45 * 0x72d18 >> 0x20);
  local_d8 = (uint)((ulonglong)uVar45 * 0x72d18);
  lVar4 = (ulonglong)uVar45 * 0x215d1 + CONCAT44(iVar41 * 0x215d1,(int)lVar7);
  lVar5 = (ulonglong)uVar50 * 0xfff59083 + CONCAT44(iVar44 * -0xa6f7d + -uVar50,(int)lVar4);
  uVar49 = (uint)lVar5;
  local_104 = (int)((ulonglong)uVar61 * 0x215d1 >> 0x20);
  local_fc = (int)((ulonglong)uVar20 * 0x215d1 >> 0x20);
  local_108 = (uint)((ulonglong)uVar61 * 0x215d1);
  uVar23 = (uint)((ulonglong)uVar20 * 0xfff59083);
  local_100 = (uint)((ulonglong)uVar20 * 0x215d1);
  uVar26 = local_108 + uVar69;
  local_ec = (int)((ulonglong)uVar50 * 0x9fb67 >> 0x20);
  uVar70 = uVar23 + uVar26;
  local_f0 = (undefined4)((ulonglong)uVar50 * 0x9fb67);
  lVar12 = (ulonglong)uVar20 * 0xa2c13 +
           (CONCAT44(iVar30 * 0xa2c13,*(uint *)(param_1 + 10) >> 4) & 0xffffffff001fffff) +
           CONCAT44(iVar41 * 0x72d18 + local_d4,local_d8) +
           CONCAT44(iVar44 * 0x9fb67 + local_ec,local_f0);
  local_144 = (int)((ulonglong)uVar61 * 0xfff0c653 >> 0x20);
  local_148 = (uint)((ulonglong)uVar61 * 0xfff0c653);
  uVar19 = local_148 + uVar60;
  uVar36 = local_100 + uVar19;
  uVar16 = (uint)((ulonglong)uVar45 * 0xfff59083);
  lVar6 = (ulonglong)uVar61 * 0xfff59083 + CONCAT44(iVar22 * -0xa6f7d + -uVar61,uVar59 + uVar85);
  uVar62 = (uint)lVar6;
  iVar67 = ((local_11c - (((int)uVar51 >> 0x15) << 0x15 | uVar51 & 0x1fffff)) -
           (uint)(uVar31 < uVar57 * 0x200000)) + ((int)uVar42 >> 0x15) + (uint)CARRY4(uVar59,uVar85)
           + (int)((ulonglong)lVar6 >> 0x20);
  uVar31 = (uint)((ulonglong)uVar45 * 0xfff0c653);
  uVar57 = uVar16 + uVar36;
  iVar27 = (int)((ulonglong)uVar45 * 0xfff59083 >> 0x20) + iVar41 * -0xa6f7d + -uVar45 +
           iVar30 * 0x215d1 + local_fc +
           local_144 + iVar22 * -0xf39ad + -uVar61 +
           ((iVar39 - iVar27) - (uint)(uVar21 < uVar28 * 0x200000)) + (uint)CARRY4(uVar18,uVar24) +
           (uint)CARRY4(local_148,uVar60) + (uint)CARRY4(local_100,uVar19) +
           (uint)CARRY4(uVar16,uVar36);
  uVar21 = uVar32 + uVar31;
  local_f4 = (int)((ulonglong)uVar50 * 0x72d18 >> 0x20);
  local_f8 = (uint)((ulonglong)uVar50 * 0x72d18);
  local_cc = (int)((ulonglong)uVar15 * 0x72d18 >> 0x20);
  local_d0 = (undefined4)((ulonglong)uVar15 * 0x72d18);
  local_e4 = (int)((ulonglong)uVar50 * 0x215d1 >> 0x20);
  local_e8 = (uint)((ulonglong)uVar50 * 0x215d1);
  local_d4 = (int)((ulonglong)uVar15 * 0x9fb67 >> 0x20);
  local_d8 = (uint)((ulonglong)uVar15 * 0x9fb67);
  lVar6 = (ulonglong)uVar15 * 0xfff0c653 + CONCAT44(iVar33 * -0xf39ad + -uVar15,(int)lVar12);
  uVar16 = (uint)lVar6;
  local_c4 = (int)((ulonglong)uVar15 * 0x215d1 >> 0x20);
  local_c8 = (undefined4)((ulonglong)uVar15 * 0x215d1);
  local_b4 = (int)((ulonglong)uVar37 * 0x9fb67 >> 0x20);
  local_b8 = (undefined4)((ulonglong)uVar37 * 0x9fb67);
  lVar13 = (ulonglong)uVar50 * 0xa2c13 +
           (CONCAT44(iVar44 * 0xa2c13,
                     ((uint)param_1[5] | (uint)param_1[6] << 8 | (uint)param_1[7] << 0x10) >> 2) &
           0xffffffff001fffff) + CONCAT44(iVar33 * 0x72d18 + local_cc,local_d0) +
           CONCAT44(iVar43 * 0x9fb67 + local_b4,local_b8);
  lVar14 = (ulonglong)uVar37 * 0xa2c13 + CONCAT44(iVar43 * 0xa2c13,*param_1 | uVar56);
  uVar19 = (uint)((ulonglong)(lVar13 + 0x100000) >> 0x20);
  uVar36 = (uint)(lVar14 + 0x100000) >> 0x15;
  uVar24 = (uint)(lVar13 + 0x100000) >> 0x15;
  uVar51 = (uint)((ulonglong)(lVar14 + 0x100000) >> 0x20);
  local_ac = (int)((ulonglong)uVar37 * 0x215d1 >> 0x20);
  local_124 = (int)((ulonglong)uVar37 * 0xfff0c653 >> 0x20);
  local_b0 = (uint)((ulonglong)uVar37 * 0x215d1);
  local_128 = (undefined4)((ulonglong)uVar37 * 0xfff0c653);
  uVar28 = uVar16 + local_b0;
  local_bc = (int)((ulonglong)uVar37 * 0x72d18 >> 0x20);
  iVar25 = (int)((ulonglong)lVar12 >> 0x20) + (int)((ulonglong)lVar6 >> 0x20) +
           iVar43 * 0x215d1 + local_ac + (uint)CARRY4(uVar16,local_b0);
  local_c0 = (undefined4)((ulonglong)uVar37 * 0x72d18);
  lVar6 = (ulonglong)uVar15 * 0xfff59083 + CONCAT44(iVar33 * -0xa6f7d + -uVar15,local_e8 + uVar21);
  uVar71 = (uint)lVar6;
  iVar39 = iVar44 * 0x215d1 + local_e4 +
           iVar78 + (int)((ulonglong)lVar11 >> 0x20) +
           (int)((ulonglong)uVar45 * 0xfff0c653 >> 0x20) + iVar41 * -0xf39ad + -uVar45 +
           (uint)CARRY4(uVar32,uVar31) + (uint)CARRY4(local_e8,uVar21) +
           (int)((ulonglong)lVar6 >> 0x20);
  lVar6 = (ulonglong)uVar45 * 0xa2c13 +
          (CONCAT44(iVar41 * 0xa2c13,*(uint *)(param_1 + 7) >> 7) & 0xffffffff001fffff) +
          CONCAT44(iVar44 * 0x72d18 + local_f4,local_f8) +
          CONCAT44(iVar33 * 0x9fb67 + local_d4,local_d8) +
          CONCAT44(iVar43 * -0xf39ad + -uVar37 + local_124,local_128) +
          CONCAT44((int)uVar19 >> 0x15,uVar24 | uVar19 * 0x800);
  uVar63 = iVar25 + (uint)(0xffefffff < uVar28);
  lVar11 = (ulonglong)uVar15 * 0xa2c13 +
           (CONCAT44(iVar33 * 0xa2c13,*(uint *)(param_1 + 2) >> 5) & 0xffffffff001fffff) +
           CONCAT44(iVar43 * 0x72d18 + local_bc,local_c0) +
           CONCAT44((int)uVar51 >> 0x15,uVar36 | uVar51 * 0x800);
  uVar64 = (uint)((ulonglong)(lVar6 + 0x100000) >> 0x20);
  uVar53 = uVar28 + 0x100000 >> 0x15;
  uVar79 = (uint)((ulonglong)(lVar11 + 0x100000) >> 0x20);
  uVar80 = (uint)(lVar6 + 0x100000) >> 0x15;
  uVar16 = (uint)(lVar11 + 0x100000) >> 0x15;
  uVar47 = iVar39 + (uint)(0xffefffff < uVar71);
  uVar45 = uVar71 + 0x100000 >> 0x15;
  uVar81 = iVar27 + (uint)(0xffefffff < uVar57);
  uVar32 = uVar57 + 0x100000 >> 0x15;
  uVar54 = iVar67 + (uint)(0xffefffff < uVar62);
  uVar46 = uVar62 + 0x100000 >> 0x15;
  uVar21 = uVar46 | uVar54 * 0x800;
  uVar55 = uVar80 | uVar64 * 0x800;
  uVar52 = uVar16 | uVar79 * 0x800;
  uVar18 = uVar45 | uVar47 * 0x800;
  uVar56 = uVar32 | uVar81 * 0x800;
  uVar85 = (uint)lVar13 + uVar24 * -0x200000;
  uVar59 = uVar28 + uVar53 * -0x200000;
  uVar60 = uVar48 + uVar21;
  iVar29 = ((iVar29 - (((int)uVar40 >> 0x15) << 0x15 | uVar40 & 0x1fffff)) -
           (uint)(uVar38 < uVar76 * 0x200000)) + ((int)uVar54 >> 0x15) + (uint)CARRY4(uVar48,uVar21)
  ;
  local_d4 = (int)((ulonglong)uVar37 * 0xfff59083 >> 0x20);
  local_d8 = (uint)((ulonglong)uVar37 * 0xfff59083);
  lVar9 = (ulonglong)uVar61 * 0xa2c13 +
          (CONCAT44(iVar22 * 0xa2c13,
                    ((uint)param_1[0xd] | (uint)param_1[0xe] << 8 | (uint)param_1[0xf] << 0x10) >> 1
                   ) & 0xffffffff001fffff) + lVar9 + lVar10 +
          CONCAT44((int)((ulonglong)uVar50 * 0xfff0c653 >> 0x20) + iVar44 * -0xf39ad + -uVar50,
                   (int)((ulonglong)uVar50 * 0xfff0c653)) +
          CONCAT44(iVar33 * 0x215d1 + local_c4,local_c8) +
          CONCAT44(iVar43 * -0xa6f7d + -uVar37 + local_d4,local_d8) +
          CONCAT44((int)uVar63 >> 0x15,uVar53 | uVar63 * 0x800);
  uVar65 = uVar49 + uVar18;
  iVar33 = ((iVar34 - iVar77) - (uint)(uVar58 < uVar17 * 0x200000)) +
           (int)((ulonglong)lVar1 >> 0x20) + (int)((ulonglong)lVar7 >> 0x20) +
           (int)((ulonglong)lVar4 >> 0x20) + (int)((ulonglong)lVar5 >> 0x20) +
           ((int)uVar47 >> 0x15) + (uint)CARRY4(uVar49,uVar18);
  uVar66 = uVar71 + uVar45 * -0x200000;
  uVar68 = uVar70 + uVar56;
  iVar30 = (int)((ulonglong)uVar20 * 0xfff59083 >> 0x20) + iVar30 * -0xa6f7d + -uVar20 +
           iVar22 * 0x215d1 + local_104 +
           ((iVar35 - (((int)uVar42 >> 0x15) << 0x15 | uVar42 & 0x1fffff)) -
           (uint)(uVar75 < uVar84 * 0x200000)) + (uint)CARRY4(local_108,uVar69) +
           (uint)CARRY4(uVar23,uVar26) + ((int)uVar81 >> 0x15) + (uint)CARRY4(uVar70,uVar56);
  uVar72 = uVar57 + uVar32 * -0x200000;
  uVar75 = uVar62 + uVar46 * -0x200000;
  uVar82 = (uint)((ulonglong)(lVar9 + 0x100000) >> 0x20);
  uVar73 = iVar29 + (uint)(0xffefffff < uVar60);
  uVar76 = uVar60 + 0x100000 >> 0x15;
  iVar22 = (int)uVar73 >> 0x15;
  uVar58 = uVar76 | uVar73 * 0x800;
  uVar21 = (uint)(lVar9 + 0x100000) >> 0x15;
  uVar17 = uVar21 | uVar82 * 0x800;
  uVar37 = uVar66 + uVar17;
  uVar70 = iVar33 + (uint)(0xffefffff < uVar65);
  uVar18 = uVar65 + 0x100000 >> 0x15;
  uVar56 = uVar18 | uVar70 * 0x800;
  lVar1 = (ulonglong)uVar58 * 0xa2c13 + CONCAT44(iVar22 * 0xa2c13,(uint)lVar14 + uVar36 * -0x200000)
  ;
  uVar40 = (uint)lVar1;
  uVar48 = (((int)((ulonglong)lVar14 >> 0x20) - (((int)uVar51 >> 0x15) << 0x15 | uVar51 & 0x1fffff))
           - (uint)((uint)lVar14 < uVar36 * 0x200000)) + (int)((ulonglong)lVar1 >> 0x20);
  uVar74 = uVar40 >> 0x15;
  uVar20 = uVar74 | uVar48 * 0x800;
  uVar50 = uVar72 + uVar56;
  lVar1 = (ulonglong)uVar58 * 0x72d18 + CONCAT44(iVar22 * 0x72d18,(uint)lVar11 + uVar16 * -0x200000)
  ;
  uVar15 = (uint)lVar1;
  uVar61 = uVar65 + uVar18 * -0x200000;
  uVar49 = uVar15 + uVar20;
  uVar69 = (((int)((ulonglong)lVar11 >> 0x20) - (((int)uVar79 >> 0x15) << 0x15 | uVar79 & 0x1fffff))
           - (uint)((uint)lVar11 < uVar16 * 0x200000)) + (int)((ulonglong)lVar1 >> 0x20) +
           ((int)uVar48 >> 0x15) + (uint)CARRY4(uVar15,uVar20);
  uVar20 = uVar49 >> 0x15;
  uVar51 = iVar30 + (uint)(0xffefffff < uVar68);
  uVar31 = uVar20 | uVar69 * 0x800;
  lVar1 = (ulonglong)uVar58 * 0x9fb67 + CONCAT44(iVar22 * 0x9fb67,uVar52 + uVar85);
  uVar16 = (uint)lVar1;
  uVar15 = uVar31 + uVar16;
  uVar31 = ((int)uVar69 >> 0x15) +
           ((int)uVar79 >> 0x15) +
           (((int)((ulonglong)lVar13 >> 0x20) - (((int)uVar19 >> 0x15) << 0x15 | uVar19 & 0x1fffff))
           - (uint)((uint)lVar13 < uVar24 * 0x200000)) + (uint)CARRY4(uVar52,uVar85) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar31,uVar16);
  uVar38 = uVar68 + 0x100000 >> 0x15;
  uVar23 = uVar15 >> 0x15;
  uVar24 = uVar38 | uVar51 * 0x800;
  uVar26 = uVar23 | uVar31 * 0x800;
  uVar16 = uVar24 + uVar75;
  lVar1 = (ulonglong)uVar58 * 0xfff0c653 +
          CONCAT44(iVar22 * -0xf39ad + -uVar58,(uint)lVar6 + uVar80 * -0x200000);
  uVar19 = (uint)lVar1;
  uVar52 = uVar26 + uVar19;
  uVar85 = ((int)uVar31 >> 0x15) +
           (((int)((ulonglong)lVar6 >> 0x20) - (((int)uVar64 >> 0x15) << 0x15 | uVar64 & 0x1fffff))
           - (uint)((uint)lVar6 < uVar80 * 0x200000)) + (int)((ulonglong)lVar1 >> 0x20) +
           (uint)CARRY4(uVar26,uVar19);
  uVar19 = uVar52 >> 0x15;
  uVar26 = uVar19 | uVar85 * 0x800;
  lVar1 = (ulonglong)uVar58 * 0x215d1 + CONCAT44(iVar22 * 0x215d1,uVar55 + uVar59);
  uVar84 = (uint)lVar1;
  uVar36 = uVar26 + uVar84;
  uVar42 = ((int)uVar85 >> 0x15) +
           ((int)uVar64 >> 0x15) +
           ((iVar25 - (((int)uVar63 >> 0x15) << 0x15 | uVar63 & 0x1fffff)) -
           (uint)(uVar28 < uVar53 * 0x200000)) + (uint)CARRY4(uVar55,uVar59) +
           (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar26,uVar84);
  uVar26 = uVar36 >> 0x15;
  lVar1 = (ulonglong)uVar58 * 0xfff59083 +
          CONCAT44(iVar22 * -0xa6f7d + -uVar58,(uint)lVar9 + uVar21 * -0x200000) +
          CONCAT44(((int)((ulonglong)lVar9 >> 0x20) -
                   (((int)uVar82 >> 0x15) << 0x15 | uVar82 & 0x1fffff)) -
                   (uint)((uint)lVar9 < uVar21 * 0x200000),uVar26 | uVar42 * 0x800);
  uVar79 = (uint)lVar1;
  uVar83 = ((int)uVar42 >> 0x15) + (int)((ulonglong)lVar1 >> 0x20);
  uVar28 = uVar79 >> 0x15;
  uVar84 = uVar28 | uVar83 * 0x800;
  uVar80 = uVar68 + uVar38 * -0x200000;
  uVar21 = uVar60 + uVar76 * -0x200000;
  uVar58 = uVar84 + uVar37;
  uVar84 = ((int)uVar83 >> 0x15) +
           ((iVar39 - (((int)uVar47 >> 0x15) << 0x15 | uVar47 & 0x1fffff)) -
           (uint)(uVar71 < uVar45 * 0x200000)) + ((int)uVar82 >> 0x15) + (uint)CARRY4(uVar66,uVar17)
           + (uint)CARRY4(uVar84,uVar37);
  uVar17 = uVar58 >> 0x15;
  uVar45 = uVar40 + uVar74 * -0x200000;
  uVar53 = uVar49 + uVar20 * -0x200000;
  uVar47 = uVar17 | uVar84 * 0x800;
  uVar55 = uVar52 + uVar19 * -0x200000;
  uVar71 = uVar36 + uVar26 * -0x200000;
  uVar37 = uVar79 + uVar28 * -0x200000;
  uVar66 = uVar47 + uVar61;
  uVar65 = ((int)uVar84 >> 0x15) +
           ((iVar33 - (((int)uVar70 >> 0x15) << 0x15 | uVar70 & 0x1fffff)) -
           (uint)(uVar65 < uVar18 * 0x200000)) + (uint)CARRY4(uVar47,uVar61);
  uVar18 = uVar66 >> 0x15;
  uVar47 = uVar18 | uVar65 * 0x800;
  uVar63 = uVar58 + uVar17 * -0x200000;
  uVar64 = uVar50 + uVar47;
  uVar70 = ((iVar27 - (((int)uVar81 >> 0x15) << 0x15 | uVar81 & 0x1fffff)) -
           (uint)(uVar57 < uVar32 * 0x200000)) + ((int)uVar70 >> 0x15) + (uint)CARRY4(uVar72,uVar56)
           + ((int)uVar65 >> 0x15) + (uint)CARRY4(uVar50,uVar47);
  uVar59 = uVar64 >> 0x15;
  uVar32 = uVar59 | uVar70 * 0x800;
  uVar56 = uVar66 + uVar18 * -0x200000;
  uVar47 = uVar80 + uVar32;
  uVar57 = ((iVar30 - (((int)uVar51 >> 0x15) << 0x15 | uVar51 & 0x1fffff)) -
           (uint)(uVar68 < uVar38 * 0x200000)) + ((int)uVar70 >> 0x15) + (uint)CARRY4(uVar80,uVar32)
  ;
  uVar68 = uVar47 >> 0x15;
  uVar50 = uVar68 | uVar57 * 0x800;
  uVar38 = uVar64 + uVar59 * -0x200000;
  uVar61 = uVar16 + uVar50;
  uVar32 = uVar61 >> 0x15;
  uVar46 = ((int)uVar51 >> 0x15) +
           ((iVar67 - (((int)uVar54 >> 0x15) << 0x15 | uVar54 & 0x1fffff)) -
           (uint)(uVar62 < uVar46 * 0x200000)) + (uint)CARRY4(uVar24,uVar75) +
           ((int)uVar57 >> 0x15) + (uint)CARRY4(uVar16,uVar50);
  uVar16 = uVar32 | uVar46 * 0x800;
  uVar24 = uVar47 + uVar68 * -0x200000;
  uVar75 = uVar21 + uVar16;
  iVar25 = ((iVar29 - (iVar22 << 0x15 | uVar73 & 0x1fffff)) - (uint)(uVar60 < uVar76 * 0x200000)) +
           ((int)uVar46 >> 0x15) + (uint)CARRY4(uVar21,uVar16);
  uVar76 = uVar75 >> 0x15;
  iVar22 = iVar25 >> 0x15;
  uVar51 = uVar61 + uVar32 * -0x200000;
  uVar50 = uVar76 | iVar25 * 0x800;
  uVar16 = (uint)((ulonglong)uVar50 * 0xa2c13);
  local_120 = (uint)((ulonglong)uVar50 * 0x72d18);
  uVar21 = uVar45 + uVar16;
  iVar25 = ((uVar48 - (((int)uVar48 >> 0x15) << 0x15 | uVar48 & 0x1fffff)) -
           (uint)(uVar40 < uVar74 * 0x200000)) +
           iVar22 * 0xa2c13 + (int)((ulonglong)uVar50 * 0xa2c13 >> 0x20) +
           (uint)CARRY4(uVar45,uVar16);
  uVar16 = uVar21 >> 0x15;
  uVar45 = uVar53 + local_120;
  uVar48 = uVar16 | iVar25 * 0x800;
  uVar40 = uVar48 + uVar45;
  iVar25 = (iVar25 >> 0x15) +
           ((uVar69 - (((int)uVar69 >> 0x15) << 0x15 | uVar69 & 0x1fffff)) -
           (uint)(uVar49 < uVar20 * 0x200000)) +
           iVar22 * 0x72d18 + (int)((ulonglong)uVar50 * 0x72d18 >> 0x20) +
           (uint)CARRY4(uVar53,local_120) + (uint)CARRY4(uVar48,uVar45);
  uVar20 = uVar40 >> 0x15;
  iVar27 = uVar21 + uVar16 * -0x200000;
  *param_1 = (byte)iVar27;
  lVar1 = (ulonglong)uVar50 * 0x9fb67 + CONCAT44(iVar22 * 0x9fb67,uVar15 + uVar23 * -0x200000) +
          CONCAT44((uVar31 - (((int)uVar31 >> 0x15) << 0x15 | uVar31 & 0x1fffff)) -
                   (uint)(uVar15 < uVar23 * 0x200000),uVar20 | iVar25 * 0x800);
  uVar15 = (uint)lVar1;
  iVar25 = (iVar25 >> 0x15) + (int)((ulonglong)lVar1 >> 0x20);
  uVar16 = uVar15 >> 0x15;
  param_1[1] = (byte)((uint)iVar27 >> 8);
  uVar31 = uVar16 | iVar25 * 0x800;
  uVar40 = uVar40 + uVar20 * -0x200000;
  param_1[2] = (byte)((uint)iVar27 >> 0x10) | (char)uVar40 * ' ';
  local_fc = (int)((ulonglong)uVar50 * 0xfff0c653 >> 0x20);
  param_1[3] = (byte)(uVar40 >> 3);
  param_1[4] = (byte)(uVar40 >> 0xb);
  local_100 = (uint)((ulonglong)uVar50 * 0xfff0c653);
  uVar21 = local_100 + uVar55;
  local_f4 = (int)((ulonglong)uVar50 * 0x215d1 >> 0x20);
  uVar48 = uVar31 + uVar21;
  iVar25 = (iVar25 >> 0x15) +
           local_fc + iVar22 * -0xf39ad + -uVar50 +
           ((uVar85 - (((int)uVar85 >> 0x15) << 0x15 | uVar85 & 0x1fffff)) -
           (uint)(uVar52 < uVar19 * 0x200000)) + (uint)CARRY4(local_100,uVar55) +
           (uint)CARRY4(uVar31,uVar21);
  uVar31 = uVar48 >> 0x15;
  local_f8 = (uint)((ulonglong)uVar50 * 0x215d1);
  uVar21 = uVar31 | iVar25 * 0x800;
  uVar15 = uVar15 + uVar16 * -0x200000;
  param_1[5] = (byte)(uVar40 >> 0x13) | (char)uVar15 * '\x04';
  param_1[6] = (byte)(uVar15 >> 6);
  uVar16 = local_f8 + uVar71;
  uVar45 = uVar21 + uVar16;
  uVar19 = uVar45 >> 0x15;
  iVar25 = (iVar25 >> 0x15) +
           iVar22 * 0x215d1 + local_f4 +
           ((uVar42 - (((int)uVar42 >> 0x15) << 0x15 | uVar42 & 0x1fffff)) -
           (uint)(uVar36 < uVar26 * 0x200000)) + (uint)CARRY4(local_f8,uVar71) +
           (uint)CARRY4(uVar21,uVar16);
  uVar20 = uVar19 | iVar25 * 0x800;
  local_d4 = (int)((ulonglong)uVar50 * 0xfff59083 >> 0x20);
  local_d8 = (uint)((ulonglong)uVar50 * 0xfff59083);
  uVar16 = uVar37 + local_d8;
  uVar21 = uVar20 + uVar16;
  iVar22 = (iVar25 >> 0x15) +
           ((uVar83 - (((int)uVar83 >> 0x15) << 0x15 | uVar83 & 0x1fffff)) -
           (uint)(uVar79 < uVar28 * 0x200000)) + local_d4 + iVar22 * -0xa6f7d + -uVar50 +
           (uint)CARRY4(uVar37,local_d8) + (uint)CARRY4(uVar20,uVar16);
  uVar23 = uVar21 >> 0x15;
  uVar20 = uVar23 | iVar22 * 0x800;
  uVar48 = uVar48 + uVar31 * -0x200000;
  param_1[9] = (byte)(uVar48 >> 9);
  param_1[7] = (byte)(uVar15 >> 0xe) | (char)uVar48 * -0x80;
  uVar16 = uVar63 + uVar20;
  iVar22 = ((uVar84 - (((int)uVar84 >> 0x15) << 0x15 | uVar84 & 0x1fffff)) -
           (uint)(uVar58 < uVar17 * 0x200000)) + (iVar22 >> 0x15) + (uint)CARRY4(uVar63,uVar20);
  uVar20 = uVar16 >> 0x15;
  uVar17 = uVar20 | iVar22 * 0x800;
  uVar45 = uVar45 + uVar19 * -0x200000;
  uVar21 = uVar21 + uVar23 * -0x200000;
  uVar31 = uVar17 + uVar56;
  iVar22 = (iVar22 >> 0x15) +
           ((uVar65 - (((int)uVar65 >> 0x15) << 0x15 | uVar65 & 0x1fffff)) -
           (uint)(uVar66 < uVar18 * 0x200000)) + (uint)CARRY4(uVar17,uVar56);
  uVar18 = uVar31 >> 0x15 | iVar22 * 0x800;
  param_1[10] = (byte)(uVar48 >> 0x11) | (char)uVar45 * '\x10';
  param_1[0xb] = (byte)(uVar45 >> 4);
  param_1[0xc] = (byte)(uVar45 >> 0xc);
  param_1[0xd] = (byte)(uVar45 >> 0x14) | (char)uVar21 * '\x02';
  uVar17 = uVar18 + uVar38;
  uVar15 = uVar17 >> 0x15;
  iVar22 = (iVar22 >> 0x15) +
           ((uVar70 - (((int)uVar70 >> 0x15) << 0x15 | uVar70 & 0x1fffff)) -
           (uint)(uVar64 < uVar59 * 0x200000)) + (uint)CARRY4(uVar18,uVar38);
  uVar16 = uVar16 + uVar20 * -0x200000;
  uVar56 = uVar15 | iVar22 * 0x800;
  uVar19 = uVar24 + uVar56;
  uVar18 = uVar19 >> 0x15;
  iVar25 = ((uVar57 - (((int)uVar57 >> 0x15) << 0x15 | uVar57 & 0x1fffff)) -
           (uint)(uVar47 < uVar68 * 0x200000)) + (iVar22 >> 0x15) + (uint)CARRY4(uVar24,uVar56);
  uVar56 = uVar18 | iVar25 * 0x800;
  param_1[0xf] = (byte)(uVar21 >> 0xf) | (char)uVar16 * '@';
  param_1[0x10] = (byte)(uVar16 >> 2);
  local_148._0_1_ = (byte)(uVar16 >> 0x12) | (char)uVar31 * '\b';
  param_1[0x11] = (byte)(uVar16 >> 10);
  local_130 = (byte)(uVar21 >> 7);
  param_1[0xe] = local_130;
  iVar22 = uVar17 + uVar15 * -0x200000;
  uVar16 = uVar51 + uVar56;
  uVar21 = uVar16 >> 0x15;
  uVar19 = uVar19 + uVar18 * -0x200000;
  uVar17 = uVar75 + uVar76 * -0x200000 +
           (uVar21 | (((uVar46 - (uVar46 & 0x1fffff)) - (uint)(uVar61 < uVar32 * 0x200000)) +
                     (iVar25 >> 0x15) + (uint)CARRY4(uVar51,uVar56)) * 0x800);
  param_1[0x17] = (byte)((uint)iVar22 >> 0x10) | (char)uVar19 * ' ';
  param_1[0x1e] = (byte)(uVar17 >> 9);
  uVar16 = uVar16 + uVar21 * -0x200000;
  param_1[0x1f] = (byte)(uVar17 >> 0x11);
  param_1[0x12] = (byte)local_148;
  local_140 = (byte)(uVar31 >> 5);
  local_160 = (byte)iVar22;
  local_130 = (byte)(uVar19 >> 3);
  param_1[0x13] = local_140;
  local_128._0_1_ = (byte)(uVar31 >> 0xd);
  param_1[8] = (byte)(uVar48 >> 1);
  param_1[0x15] = local_160;
  param_1[0x14] = (byte)local_128;
  local_138._0_1_ = (byte)((uint)iVar22 >> 8);
  param_1[0x18] = local_130;
  param_1[0x1a] = (byte)(uVar19 >> 0x13) | (char)uVar16 * '\x04';
  param_1[0x16] = (byte)local_138;
  local_120._0_1_ = (byte)(uVar19 >> 0xb);
  param_1[0x1b] = (byte)(uVar16 >> 6);
  param_1[0x1c] = (byte)(uVar16 >> 0xe) | (char)uVar17 * -0x80;
  param_1[0x19] = (byte)local_120;
  param_1[0x1d] = (byte)(uVar17 >> 1);
  return;
}


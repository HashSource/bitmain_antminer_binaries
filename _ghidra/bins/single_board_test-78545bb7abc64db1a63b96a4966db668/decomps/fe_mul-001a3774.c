
void fe_mul(int *param_1,int *param_2,int *param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  ulonglong uVar6;
  longlong lVar7;
  ulonglong uVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  int iVar12;
  ulonglong uVar13;
  longlong lVar14;
  int iVar15;
  int iVar16;
  longlong lVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  int iVar42;
  uint uVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  int iVar48;
  uint uVar49;
  uint uVar50;
  int iVar51;
  int iVar52;
  int iVar53;
  int iVar54;
  undefined8 local_168;
  undefined8 local_160;
  int local_158;
  int local_150;
  undefined8 local_140;
  int local_110;
  int local_e8;
  undefined8 local_c0;
  
  iVar30 = param_2[1];
  iVar33 = *param_2;
  iVar46 = iVar30 << 1;
  iVar40 = param_3[5];
  iVar34 = param_3[4];
  iVar31 = param_3[3];
  iVar41 = param_2[3];
  iVar35 = param_2[2];
  iVar24 = iVar31 * 0x13;
  iVar54 = param_3[1];
  iVar53 = param_2[4];
  iVar52 = param_3[2];
  iVar47 = iVar41 << 1;
  iVar36 = *param_3;
  iVar37 = param_3[6];
  iVar45 = iVar40 * 0x13;
  iVar48 = param_2[5];
  iVar20 = param_3[8];
  iVar44 = param_3[7];
  iVar26 = iVar48 << 1;
  iVar51 = param_3[9] * 0x13;
  iVar38 = param_2[6];
  iVar27 = param_2[7];
  iVar12 = iVar37 * 0x13;
  iVar23 = iVar20 * 0x13;
  iVar42 = param_2[8];
  uVar1 = (longlong)iVar35 * (longlong)iVar52 +
          (longlong)iVar34 * (longlong)iVar33 +
          ((longlong)(int)((ulonglong)((longlong)iVar31 * (longlong)iVar46) >> 0x20) << 0x20 |
          (longlong)iVar31 * (longlong)iVar46 & 0xffffffffU);
  iVar21 = param_2[9];
  iVar15 = iVar34 * 0x13;
  iVar16 = iVar44 * 0x13;
  iVar39 = iVar21 << 1;
  iVar22 = iVar27 << 1;
  uVar2 = (longlong)iVar35 * (longlong)iVar31 +
          (longlong)iVar40 * (longlong)iVar33 + (longlong)iVar34 * (longlong)iVar30;
  uVar2 = (longlong)iVar41 * (longlong)iVar52 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  uVar3 = (longlong)iVar37 * (longlong)iVar33 + (longlong)iVar40 * (longlong)iVar46;
  uVar4 = (longlong)iVar36 * (longlong)iVar33 +
          ((longlong)(int)((ulonglong)((longlong)iVar46 * (longlong)iVar51) >> 0x20) << 0x20 |
          (longlong)iVar46 * (longlong)iVar51 & 0xffffffffU);
  uVar5 = (longlong)iVar44 * (longlong)iVar33 + (longlong)iVar37 * (longlong)iVar30;
  uVar6 = (longlong)iVar20 * (longlong)iVar33 +
          ((longlong)(int)((ulonglong)((longlong)iVar44 * (longlong)iVar46) >> 0x20) << 0x20 |
          (longlong)iVar44 * (longlong)iVar46 & 0xffffffffU);
  uVar4 = (longlong)iVar16 * (longlong)iVar47 +
          (longlong)iVar23 * (longlong)iVar35 +
          ((longlong)(int)(uVar4 >> 0x20) << 0x20 | uVar4 & 0xffffffff);
  lVar7 = (longlong)iVar39 * (longlong)iVar45 +
          (longlong)iVar42 * (longlong)iVar12 +
          (longlong)iVar22 * (longlong)iVar16 +
          (longlong)iVar38 * (longlong)iVar23 +
          (longlong)iVar26 * (longlong)iVar51 +
          (longlong)iVar53 * (longlong)iVar36 +
          (longlong)iVar47 * (longlong)iVar54 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar1 = (longlong)iVar41 * (longlong)iVar23 +
          (longlong)iVar35 * (longlong)iVar51 +
          (longlong)iVar54 * (longlong)iVar33 +
          ((longlong)(int)((ulonglong)((longlong)iVar36 * (longlong)iVar30) >> 0x20) << 0x20 |
          (longlong)iVar36 * (longlong)iVar30 & 0xffffffffU);
  uVar6 = (longlong)iVar47 * (longlong)iVar40 +
          (longlong)iVar35 * (longlong)iVar37 +
          ((longlong)(int)(uVar6 >> 0x20) << 0x20 | uVar6 & 0xffffffff);
  uVar8 = (longlong)iVar31 * (longlong)iVar33 +
          ((longlong)(int)((ulonglong)((longlong)iVar52 * (longlong)iVar30) >> 0x20) << 0x20 |
          (longlong)iVar52 * (longlong)iVar30 & 0xffffffffU);
  uVar13 = lVar7 + 0x2000000;
  iVar32 = (int)(uVar13 >> 0x20);
  lVar14 = (longlong)iVar21 * (longlong)iVar12 +
           (longlong)iVar42 * (longlong)iVar16 +
           (longlong)iVar27 * (longlong)iVar23 +
           (longlong)iVar38 * (longlong)iVar51 +
           (longlong)iVar48 * (longlong)iVar36 +
           (longlong)iVar53 * (longlong)iVar54 +
           ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff) +
           CONCAT44(iVar32 >> 0x1a,(uint)uVar13 >> 0x1a | iVar32 * 0x40);
  lVar9 = lVar14 + 0x1000000;
  uVar28 = (uint)lVar9;
  uVar2 = (longlong)iVar35 * (longlong)iVar54 +
          ((longlong)(int)(uVar8 >> 0x20) << 0x20 | uVar8 & 0xffffffff);
  iVar32 = (int)((ulonglong)lVar9 >> 0x20);
  local_c0 = CONCAT44(iVar32 >> 0x19,uVar28 >> 0x19 | iVar32 * 0x80);
  local_c0 = (longlong)iVar39 * (longlong)iVar16 +
             (longlong)iVar42 * (longlong)iVar23 +
             (longlong)iVar22 * (longlong)iVar51 +
             (longlong)iVar38 * (longlong)iVar36 +
             (longlong)iVar26 * (longlong)iVar54 +
             (longlong)iVar53 * (longlong)iVar52 +
             (longlong)iVar47 * (longlong)iVar31 +
             (longlong)iVar35 * (longlong)iVar34 +
             ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) + local_c0;
  lVar9 = local_c0 + 0x2000000;
  uVar29 = (uint)lVar9;
  iVar32 = (int)((ulonglong)lVar9 >> 0x20);
  uVar3 = (longlong)(iVar52 * 0x13) * (longlong)iVar42 +
          (longlong)iVar24 * (longlong)iVar22 +
          (longlong)iVar15 * (longlong)iVar38 +
          (longlong)iVar45 * (longlong)iVar26 +
          (longlong)iVar12 * (longlong)iVar53 +
          ((longlong)(int)(uVar4 >> 0x20) << 0x20 | uVar4 & 0xffffffff);
  uVar4 = (longlong)iVar26 * (longlong)iVar16 +
          (longlong)iVar53 * (longlong)iVar23 +
          (longlong)iVar47 * (longlong)iVar51 +
          (longlong)iVar35 * (longlong)iVar36 +
          (longlong)iVar52 * (longlong)iVar33 +
          ((longlong)(int)((ulonglong)((longlong)iVar54 * (longlong)iVar46) >> 0x20) << 0x20 |
          (longlong)iVar54 * (longlong)iVar46 & 0xffffffffU);
  uVar1 = (longlong)iVar27 * (longlong)iVar15 +
          (longlong)iVar38 * (longlong)iVar45 +
          (longlong)iVar48 * (longlong)iVar12 +
          (longlong)iVar53 * (longlong)iVar16 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  lVar9 = (longlong)(iVar54 * 0x13) * (longlong)iVar39 +
          ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff);
  lVar10 = (longlong)iVar21 * (longlong)iVar23 +
           (longlong)iVar42 * (longlong)iVar51 +
           (longlong)iVar27 * (longlong)iVar36 +
           (longlong)iVar38 * (longlong)iVar54 +
           (longlong)iVar48 * (longlong)iVar52 +
           (longlong)iVar53 * (longlong)iVar31 +
           (longlong)iVar41 * (longlong)iVar34 +
           (longlong)iVar35 * (longlong)iVar40 +
           ((longlong)(int)(uVar5 >> 0x20) << 0x20 | uVar5 & 0xffffffff) +
           CONCAT44(iVar32 >> 0x1a,uVar29 >> 0x1a | iVar32 * 0x40);
  iVar32 = (int)((ulonglong)(lVar9 + 0x2000000) >> 0x20);
  local_168 = CONCAT44(iVar32 >> 0x1a,(uint)(lVar9 + 0x2000000) >> 0x1a | iVar32 * 0x40);
  uVar3 = (longlong)iVar42 * (longlong)iVar36 +
          (longlong)iVar22 * (longlong)iVar54 +
          (longlong)iVar38 * (longlong)iVar52 +
          (longlong)iVar26 * (longlong)iVar31 +
          (longlong)iVar53 * (longlong)iVar34 +
          ((longlong)(int)(uVar6 >> 0x20) << 0x20 | uVar6 & 0xffffffff);
  local_110 = (int)lVar10;
  lVar10 = lVar10 + 0x1000000;
  uVar49 = (uint)lVar10;
  iVar26 = (int)((ulonglong)lVar10 >> 0x20);
  uVar2 = (longlong)iVar48 * (longlong)iVar23 +
          (longlong)iVar53 * (longlong)iVar51 +
          (longlong)iVar41 * (longlong)iVar36 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  uVar4 = (longlong)iVar22 * (longlong)iVar45 +
          (longlong)iVar38 * (longlong)iVar12 +
          ((longlong)(int)(uVar4 >> 0x20) << 0x20 | uVar4 & 0xffffffff);
  uVar5 = (longlong)iVar27 * (longlong)iVar52 +
          (longlong)iVar38 * (longlong)iVar31 +
          (longlong)iVar48 * (longlong)iVar34 +
          (longlong)iVar53 * (longlong)iVar40 +
          (longlong)iVar41 * (longlong)iVar37 +
          (longlong)iVar35 * (longlong)iVar44 +
          (longlong)param_3[9] * (longlong)iVar33 + (longlong)iVar20 * (longlong)iVar30;
  lVar10 = (longlong)iVar21 * (longlong)(iVar52 * 0x13) +
           (longlong)iVar42 * (longlong)iVar24 +
           ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff) + local_168;
  lVar11 = lVar10 + 0x1000000;
  uVar18 = (uint)lVar11;
  iVar23 = (int)((ulonglong)lVar11 >> 0x20);
  lVar11 = (longlong)iVar39 * (longlong)iVar51 +
           ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) +
           CONCAT44(iVar26 >> 0x19,uVar49 >> 0x19 | iVar26 * 0x80);
  local_168._0_4_ = (int)lVar11;
  lVar11 = lVar11 + 0x2000000;
  uVar50 = (uint)lVar11;
  iVar51 = (int)((ulonglong)lVar11 >> 0x20);
  uVar1 = (longlong)iVar42 * (longlong)iVar54 +
          ((longlong)(int)(uVar5 >> 0x20) << 0x20 | uVar5 & 0xffffffff);
  local_160 = CONCAT44(iVar23 >> 0x19,uVar18 >> 0x19 | iVar23 * 0x80);
  local_158 = (int)lVar10 - (uVar18 & 0xfe000000);
  uVar2 = (longlong)iVar27 * (longlong)iVar12 +
          (longlong)iVar38 * (longlong)iVar16 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  uVar2 = (longlong)iVar42 * (longlong)iVar45 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  local_160 = (longlong)iVar39 * (longlong)iVar24 +
              (longlong)iVar42 * (longlong)iVar15 +
              ((longlong)(int)(uVar4 >> 0x20) << 0x20 | uVar4 & 0xffffffff) + local_160;
  lVar10 = local_160 + 0x2000000;
  uVar19 = (uint)lVar10;
  iVar24 = (int)((ulonglong)lVar10 >> 0x20);
  lVar10 = (longlong)iVar21 * (longlong)iVar36 +
           ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff) +
           CONCAT44(iVar51 >> 0x1a,uVar50 >> 0x1a | iVar51 * 0x40);
  lVar11 = lVar10 + 0x1000000;
  uVar43 = (uint)lVar11;
  iVar45 = (int)((ulonglong)lVar11 >> 0x20);
  local_140 = CONCAT44(iVar24 >> 0x1a,uVar19 >> 0x1a | iVar24 * 0x40);
  uVar18 = iVar45 * 0x80;
  uVar25 = uVar43 >> 0x19 | uVar18;
  iVar45 = iVar45 >> 0x19;
  local_140 = (longlong)iVar21 * (longlong)iVar15 +
              ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff) + local_140;
  param_1[2] = (int)local_160 - (uVar19 & 0xfc000000);
  lVar11 = local_140 + 0x1000000;
  uVar19 = (uint)lVar11;
  iVar24 = (int)((ulonglong)lVar11 >> 0x20);
  lVar9 = (lVar9 - (lVar9 + 0x2000000U & 0xfffffffffc000000)) +
          CONCAT44(iVar45 * 3 +
                   ((iVar45 << 3 | uVar18 >> 0x1d) + (uint)CARRY4(uVar25,uVar25 * 8)) * 2 +
                   (uint)CARRY4(uVar25 * 9,uVar25 * 9) + (uint)CARRY4(uVar25,uVar25 * 0x12),
                   uVar25 * 0x13);
  lVar11 = (lVar7 - (uVar13 & 0xfffffffffc000000)) +
           CONCAT44(iVar24 >> 0x19,uVar19 >> 0x19 | iVar24 * 0x80);
  lVar7 = lVar9 + 0x2000000;
  uVar25 = (uint)lVar7;
  lVar17 = lVar11 + 0x2000000;
  uVar18 = (uint)lVar17;
  *param_1 = (int)lVar9 - (uVar25 & 0xfc000000);
  local_160._0_4_ = (int)local_140;
  local_150 = (int)lVar10;
  local_e8 = (int)local_c0;
  param_1[1] = (uVar25 >> 0x1a | (int)((ulonglong)lVar7 >> 0x20) * 0x40) + local_158;
  param_1[9] = local_150 - (uVar43 & 0xfe000000);
  param_1[8] = (int)local_168 - (uVar50 & 0xfc000000);
  param_1[3] = (int)local_160 - (uVar19 & 0xfe000000);
  param_1[7] = local_110 - (uVar49 & 0xfe000000);
  param_1[4] = (int)lVar11 - (uVar18 & 0xfc000000);
  param_1[5] = ((int)lVar14 - (uVar28 & 0xfe000000)) +
               (uVar18 >> 0x1a | (int)((ulonglong)lVar17 >> 0x20) * 0x40);
  param_1[6] = local_e8 - (uVar29 & 0xfc000000);
  return;
}


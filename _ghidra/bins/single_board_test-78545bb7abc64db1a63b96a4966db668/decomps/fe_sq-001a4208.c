
void fe_sq(int *param_1,int *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  ulonglong uVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  ulonglong uVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int iVar30;
  uint uVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  int iVar35;
  int iVar36;
  uint uVar37;
  uint uVar38;
  uint uVar39;
  int iVar40;
  uint uVar41;
  int iVar42;
  uint uVar43;
  int iVar44;
  int local_e8;
  int local_d8;
  int local_a0;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  int local_40;
  
  iVar26 = param_2[1];
  iVar44 = param_2[6];
  iVar27 = param_2[3];
  iVar28 = *param_2;
  iVar29 = param_2[4];
  iVar30 = iVar26 << 1;
  iVar33 = param_2[9];
  iVar19 = param_2[2];
  iVar34 = iVar28 << 1;
  iVar35 = param_2[5];
  iVar20 = iVar27 << 1;
  iVar21 = param_2[8];
  iVar15 = param_2[7];
  iVar16 = iVar29 << 1;
  iVar22 = iVar19 << 1;
  iVar17 = iVar33 * 0x26;
  iVar18 = iVar35 << 1;
  iVar32 = iVar21 * 0x13;
  iVar23 = iVar15 << 1;
  uVar1 = (longlong)iVar29 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar30 * (longlong)iVar20) >> 0x20) << 0x20 |
          (longlong)iVar30 * (longlong)iVar20 & 0xffffffffU);
  iVar40 = iVar44 * 0x13;
  uVar1 = (longlong)iVar19 * (longlong)iVar19 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar1 = (longlong)iVar17 * (longlong)iVar18 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar2 = (longlong)iVar35 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar29 * (longlong)iVar30) >> 0x20) << 0x20 |
          (longlong)iVar29 * (longlong)iVar30 & 0xffffffffU);
  uVar1 = (longlong)(iVar44 << 1) * (longlong)iVar32 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar3 = (longlong)iVar44 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar30 * (longlong)iVar18) >> 0x20) << 0x20 |
          (longlong)iVar30 * (longlong)iVar18 & 0xffffffffU);
  iVar42 = iVar15 * 0x26;
  uVar2 = (longlong)iVar22 * (longlong)iVar27 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  lVar4 = (longlong)iVar42 * (longlong)iVar15 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar1 = (longlong)iVar17 * (longlong)iVar44 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  iVar36 = (int)((ulonglong)(lVar4 + 0x2000000) >> 0x20);
  local_90 = CONCAT44(iVar36 >> 0x1a,(uint)(lVar4 + 0x2000000) >> 0x1a | iVar36 * 0x40);
  uVar2 = (longlong)iVar32 * (longlong)iVar22 +
          (longlong)iVar28 * (longlong)iVar28 + (longlong)iVar30 * (longlong)iVar17;
  uVar5 = (longlong)iVar15 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar44 * (longlong)iVar30) >> 0x20) << 0x20 |
          (longlong)iVar44 * (longlong)iVar30 & 0xffffffffU);
  local_90 = (longlong)iVar32 * (longlong)iVar23 +
             ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff) + local_90;
  lVar6 = local_90 + 0x1000000;
  iVar28 = (int)((ulonglong)lVar6 >> 0x20);
  local_40 = (int)local_90;
  uVar1 = (longlong)iVar42 * (longlong)iVar20 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  local_88 = CONCAT44(iVar28 >> 0x19,(uint)lVar6 >> 0x19 | iVar28 * 0x80);
  local_40 = local_40 - (local_40 + 0x1000000U & 0xfe000000);
  local_88 = (longlong)iVar32 * (longlong)iVar21 +
             (longlong)iVar17 * (longlong)iVar23 +
             (longlong)iVar20 * (longlong)iVar27 +
             (longlong)iVar22 * (longlong)iVar29 +
             ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) + local_88;
  lVar6 = local_88 + 0x2000000;
  uVar38 = (uint)lVar6;
  iVar28 = (int)((ulonglong)lVar6 >> 0x20);
  uVar2 = (longlong)iVar22 * (longlong)iVar44 +
          (longlong)iVar21 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar30 * (longlong)iVar23) >> 0x20) << 0x20 |
          (longlong)iVar30 * (longlong)iVar23 & 0xffffffffU);
  local_80 = CONCAT44(iVar28 >> 0x1a,uVar38 >> 0x1a | iVar28 * 0x40);
  uVar1 = (longlong)iVar40 * (longlong)iVar16 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar3 = (longlong)iVar20 * (longlong)iVar29 +
          (longlong)iVar22 * (longlong)iVar35 +
          ((longlong)(int)(uVar5 >> 0x20) << 0x20 | uVar5 & 0xffffffff);
  lVar6 = (longlong)(iVar35 * 0x26) * (longlong)iVar35 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar1 = (longlong)iVar18 * (longlong)iVar20 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  uVar1 = (longlong)iVar29 * (longlong)iVar29 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar2 = (longlong)iVar17 * (longlong)iVar20 +
          (longlong)iVar19 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar26 * (longlong)iVar30) >> 0x20) << 0x20 |
          (longlong)iVar26 * (longlong)iVar30 & 0xffffffffU);
  local_80 = (longlong)iVar17 * (longlong)iVar21 +
             ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) + local_80;
  uVar3 = (longlong)iVar33 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar21 * (longlong)iVar30) >> 0x20) << 0x20 |
          (longlong)iVar21 * (longlong)iVar30 & 0xffffffffU);
  uVar5 = (longlong)iVar42 * (longlong)iVar29 +
          (longlong)iVar32 * (longlong)iVar20 +
          (longlong)iVar26 * (longlong)iVar34 +
          ((longlong)(int)((ulonglong)((longlong)iVar19 * (longlong)iVar17) >> 0x20) << 0x20 |
          (longlong)iVar19 * (longlong)iVar17 & 0xffffffffU);
  uVar10 = lVar6 + 0x2000000;
  iVar21 = (int)(uVar10 >> 0x20);
  local_a0 = (int)local_80;
  local_80 = local_80 + 0x1000000;
  uVar24 = (uint)local_80;
  iVar28 = (int)((ulonglong)local_80 >> 0x20);
  lVar11 = (longlong)iVar40 * (longlong)iVar18 +
           ((longlong)(int)(uVar5 >> 0x20) << 0x20 | uVar5 & 0xffffffff) +
           CONCAT44(iVar21 >> 0x1a,(uint)uVar10 >> 0x1a | iVar21 * 0x40);
  uVar2 = (longlong)iVar42 * (longlong)iVar18 +
          (longlong)iVar16 * (longlong)iVar32 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  lVar12 = (longlong)iVar17 * (longlong)iVar33 +
           ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff) +
           CONCAT44(iVar28 >> 0x19,uVar24 >> 0x19 | iVar28 * 0x80);
  lVar7 = lVar11 + 0x1000000;
  uVar43 = (uint)lVar7;
  iVar21 = (int)((ulonglong)lVar7 >> 0x20);
  lVar7 = lVar12 + 0x2000000;
  uVar31 = (uint)lVar7;
  iVar28 = (int)((ulonglong)lVar7 >> 0x20);
  lVar7 = (longlong)iVar40 * (longlong)iVar44 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff) +
          CONCAT44(iVar21 >> 0x19,uVar43 >> 0x19 | iVar21 * 0x80);
  uVar1 = (longlong)iVar32 * (longlong)iVar18 +
          (longlong)iVar17 * (longlong)iVar29 +
          (longlong)iVar27 * (longlong)iVar34 + (longlong)iVar19 * (longlong)iVar30;
  local_e8 = (int)lVar7;
  lVar7 = lVar7 + 0x2000000;
  uVar25 = (uint)lVar7;
  iVar32 = (int)((ulonglong)lVar7 >> 0x20);
  lVar7 = (longlong)iVar16 * (longlong)iVar35 +
          (longlong)iVar20 * (longlong)iVar44 +
          (longlong)iVar22 * (longlong)iVar15 +
          ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) +
          CONCAT44(iVar28 >> 0x1a,uVar31 >> 0x1a | iVar28 * 0x40);
  lVar8 = lVar7 + 0x1000000;
  uVar39 = (uint)lVar8;
  iVar40 = (int)((ulonglong)lVar8 >> 0x20);
  uVar14 = iVar40 * 0x80;
  uVar41 = uVar39 >> 0x19 | uVar14;
  iVar40 = iVar40 >> 0x19;
  param_1[2] = local_e8 - (uVar25 & 0xfc000000);
  lVar8 = (longlong)iVar42 * (longlong)iVar44 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff) +
          CONCAT44(iVar32 >> 0x1a,uVar25 >> 0x1a | iVar32 * 0x40);
  lVar9 = lVar8 + 0x1000000;
  uVar37 = (uint)lVar9;
  iVar32 = (int)((ulonglong)lVar9 >> 0x20);
  lVar9 = (lVar6 - (uVar10 & 0xfffffffffc000000)) +
          CONCAT44(iVar40 * 3 +
                   ((iVar40 << 3 | uVar14 >> 0x1d) + (uint)CARRY4(uVar41,uVar41 * 8)) * 2 +
                   (uint)CARRY4(uVar41 * 9,uVar41 * 9) + (uint)CARRY4(uVar41,uVar41 * 0x12),
                   uVar41 * 0x13);
  lVar4 = (lVar4 - (lVar4 + 0x2000000U & 0xfffffffffc000000)) +
          CONCAT44(iVar32 >> 0x19,uVar37 >> 0x19 | iVar32 * 0x80);
  lVar13 = lVar9 + 0x2000000;
  uVar14 = (uint)lVar13;
  lVar6 = lVar4 + 0x2000000;
  uVar25 = (uint)lVar6;
  local_e8 = (int)lVar8;
  local_d8 = (int)lVar7;
  param_1[9] = local_d8 - (uVar39 & 0xfe000000);
  param_1[7] = local_a0 - (uVar24 & 0xfe000000);
  param_1[6] = (int)local_88 - (uVar38 & 0xfc000000);
  param_1[4] = (int)lVar4 - (uVar25 & 0xfc000000);
  *param_1 = (int)lVar9 - (uVar14 & 0xfc000000);
  param_1[5] = local_40 + (uVar25 >> 0x1a | (int)((ulonglong)lVar6 >> 0x20) * 0x40);
  param_1[1] = ((int)lVar11 - (uVar43 & 0xfe000000)) +
               (uVar14 >> 0x1a | (int)((ulonglong)lVar13 >> 0x20) * 0x40);
  param_1[8] = (int)lVar12 - (uVar31 & 0xfc000000);
  param_1[3] = local_e8 - (uVar37 & 0xfe000000);
  return;
}


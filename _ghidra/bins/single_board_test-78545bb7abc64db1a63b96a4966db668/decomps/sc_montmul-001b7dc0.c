
void sc_montmul(int *param_1,int param_2,uint *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  longlong lVar6;
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
  uint *puVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint local_220;
  int local_21c;
  uint local_134;
  uint local_130;
  uint local_128;
  uint local_120;
  uint local_118;
  uint local_110;
  uint local_108;
  ulonglong local_f8;
  ulonglong local_e8;
  ulonglong local_e0;
  undefined1 auStack_64 [64];
  
  memset(auStack_64,0,0x3c);
  puVar21 = (uint *)(param_2 + -4);
  uVar23 = 0;
  uVar16 = 0;
  uVar18 = 0;
  uVar15 = 0;
  uVar9 = 0;
  uVar22 = 0;
  local_108 = 0;
  local_110 = 0;
  uVar13 = 0;
  uVar8 = 0;
  local_118 = 0;
  local_120 = 0;
  local_128 = 0;
  local_130 = 0;
  local_134 = 0;
  do {
    puVar21 = puVar21 + 1;
    uVar11 = *puVar21;
    uVar2 = (ulonglong)*param_3 * (ulonglong)uVar11 + (ulonglong)local_130;
    local_f8 = (ulonglong)uVar22;
    local_e8 = (ulonglong)uVar16;
    local_e0 = (ulonglong)uVar9;
    uVar24 = (int)uVar2 * -0x516e743b;
    uVar3 = (ulonglong)param_3[1] * (ulonglong)uVar11 + (ulonglong)local_128 + (uVar2 >> 0x20);
    uVar4 = (ulonglong)param_3[2] * (ulonglong)uVar11 + (ulonglong)local_120 + (uVar3 >> 0x20);
    uVar5 = (ulonglong)param_3[3] * (ulonglong)uVar11 + (ulonglong)local_118 + (uVar4 >> 0x20);
    uVar2 = (ulonglong)uVar24 * 0x2378c292 + (uVar3 & 0xffffffff) +
            ((ulonglong)uVar24 * 0xab5844f3 + (uVar2 & 0xffffffff) >> 0x20);
    local_130 = (uint)uVar2;
    uVar3 = (ulonglong)param_3[4] * (ulonglong)uVar11 + (ulonglong)local_110 + (uVar5 >> 0x20);
    uVar2 = (ulonglong)uVar24 * 0x8dc58f55 + (uVar4 & 0xffffffff) + (uVar2 >> 0x20);
    local_128 = (uint)uVar2;
    uVar4 = (ulonglong)param_3[5] * (ulonglong)uVar11 + (ulonglong)local_108 + (uVar3 >> 0x20);
    uVar2 = (ulonglong)uVar24 * 0x216cc272 + (uVar5 & 0xffffffff) + (uVar2 >> 0x20);
    local_120 = (uint)uVar2;
    uVar5 = (ulonglong)param_3[6] * (ulonglong)uVar11 + (ulonglong)uVar8 + (uVar4 >> 0x20);
    uVar2 = (ulonglong)uVar24 * 0xaed63690 + (uVar3 & 0xffffffff) + (uVar2 >> 0x20);
    local_118 = (uint)uVar2;
    uVar3 = (ulonglong)param_3[7] * (ulonglong)uVar11 + (ulonglong)uVar18 + (uVar5 >> 0x20);
    uVar18 = (uint)uVar3;
    uVar2 = (ulonglong)uVar24 * 0xc44edb49 + (uVar4 & 0xffffffff) + (uVar2 >> 0x20);
    local_110 = (uint)uVar2;
    uVar3 = (ulonglong)param_3[8] * (ulonglong)uVar11 + local_f8 + (uVar3 >> 0x20);
    uVar16 = (uint)uVar3;
    lVar1 = (ulonglong)uVar24 * 0x7cca23e9 + (uVar5 & 0xffffffff) + (uVar2 >> 0x20);
    local_108 = (uint)lVar1;
    uVar9 = (uint)((ulonglong)lVar1 >> 0x20);
    lVar1 = (ulonglong)uVar24 * 0xffffffff;
    uVar2 = (ulonglong)param_3[9] * (ulonglong)uVar11 + (ulonglong)uVar13 + (uVar3 >> 0x20);
    local_220 = (uint)lVar1;
    local_21c = (int)((ulonglong)lVar1 >> 0x20);
    uVar13 = local_220 + uVar18;
    uVar22 = local_220 + uVar16;
    uVar8 = uVar9 + uVar13;
    uVar9 = local_21c + (uint)CARRY4(local_220,uVar18) + (uint)CARRY4(uVar9,uVar13);
    uVar3 = (ulonglong)param_3[10] * (ulonglong)uVar11 + local_e8 + (uVar2 >> 0x20);
    uVar17 = (uint)uVar3;
    uVar18 = uVar9 + uVar22;
    uVar3 = (ulonglong)param_3[0xb] * (ulonglong)uVar11 + local_e0 + (uVar3 >> 0x20);
    uVar7 = (uint)uVar3;
    lVar6 = lVar1 + (uVar2 & 0xffffffff) +
            (ulonglong)(local_21c + (uint)CARRY4(local_220,uVar16) + (uint)CARRY4(uVar9,uVar22));
    uVar22 = (uint)lVar6;
    uVar9 = (uint)((ulonglong)lVar6 >> 0x20);
    uVar2 = (ulonglong)param_3[0xc] * (ulonglong)uVar11 + (ulonglong)uVar15 + (uVar3 >> 0x20);
    uVar15 = local_220 + uVar17;
    uVar13 = uVar9 + uVar15;
    uVar9 = local_21c + (uint)CARRY4(local_220,uVar17) + (uint)CARRY4(uVar9,uVar15);
    uVar3 = (ulonglong)param_3[0xd] * (ulonglong)uVar11 + (ulonglong)uVar23 + (uVar2 >> 0x20);
    uVar11 = (uint)(uVar3 >> 0x20);
    uVar15 = local_220 + uVar7;
    uVar16 = uVar9 + uVar15;
    uVar2 = lVar1 + (uVar2 & 0xffffffff) +
            (ulonglong)(local_21c + (uint)CARRY4(local_220,uVar7) + (uint)CARRY4(uVar9,uVar15));
    uVar9 = (uint)uVar2;
    lVar1 = (ulonglong)uVar24 * 0x3fffffff + (uVar3 & 0xffffffff) + (uVar2 >> 0x20);
    uVar15 = (uint)lVar1;
    uVar7 = (uint)((ulonglong)lVar1 >> 0x20);
    uVar17 = uVar11 + local_134;
    uVar23 = uVar7 + uVar17;
    local_134 = (uint)CARRY4(uVar11,local_134) + (uint)CARRY4(uVar7,uVar17);
  } while (puVar21 != (uint *)(param_2 + 0x34));
  uVar11 = (0xab5844f2 < local_130) - 1;
  uVar24 = uVar11 + local_128 + 0xdc873d6e;
  uVar11 = ((int)uVar11 >> 0x1f) + (uint)CARRY4(uVar11,local_128) + -1 +
           (uint)(0x2378c291 < uVar11 + local_128);
  uVar14 = uVar11 + local_120 + 0x723a70ab;
  uVar7 = ((int)uVar11 >> 0x1f) + (uint)CARRY4(uVar11,local_120) + -1 +
          (uint)(0x8dc58f54 < uVar11 + local_120);
  uVar11 = uVar7 + local_118 + 0xde933d8e;
  uVar17 = ((int)uVar7 >> 0x1f) + (uint)CARRY4(uVar7,local_118) + -1 +
           (uint)(0x216cc271 < uVar7 + local_118);
  uVar7 = uVar17 + local_110 + 0x5129c970;
  uVar17 = ((int)uVar17 >> 0x1f) + (uint)CARRY4(uVar17,local_110) + -1 +
           (uint)(0xaed6368f < uVar17 + local_110);
  uVar10 = uVar17 + local_108 + 0x3bb124b7;
  uVar12 = ((int)uVar17 >> 0x1f) + (uint)CARRY4(uVar17,local_108) + -1 +
           (uint)(0xc44edb48 < uVar17 + local_108);
  uVar17 = uVar12 + uVar8 + 0x8335dc17;
  uVar8 = ((int)uVar12 >> 0x1f) + (uint)CARRY4(uVar12,uVar8) + -1 +
          (uint)(0x7cca23e8 < uVar12 + uVar8);
  uVar12 = uVar8 + uVar18 + 1;
  uVar8 = ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,uVar18) + -1 +
          (uint)(0xfffffffe < uVar8 + uVar18);
  uVar19 = uVar8 + uVar22 + 1;
  uVar8 = ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,uVar22) + -1 +
          (uint)(0xfffffffe < uVar8 + uVar22);
  uVar18 = uVar8 + uVar13 + 1;
  uVar8 = ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,uVar13) + -1 +
          (uint)(0xfffffffe < uVar8 + uVar13);
  uVar20 = uVar8 + uVar16 + 1;
  uVar16 = ((int)uVar8 >> 0x1f) + (uint)CARRY4(uVar8,uVar16) + -1 +
           (uint)(0xfffffffe < uVar8 + uVar16);
  uVar8 = uVar16 + uVar9 + 1;
  uVar9 = ((int)uVar16 >> 0x1f) + (uint)CARRY4(uVar16,uVar9) + -1 +
          (uint)(0xfffffffe < uVar16 + uVar9);
  uVar13 = uVar9 + uVar15 + 1;
  uVar22 = ((int)uVar9 >> 0x1f) + (uint)CARRY4(uVar9,uVar15) + -1 +
           (uint)(0xfffffffe < uVar9 + uVar15);
  local_134 = local_134 +
              ((int)uVar22 >> 0x1f) + (uint)CARRY4(uVar22,uVar23) +
              ((0x3ffffffe < uVar22 + uVar23) - 1);
  uVar9 = (uint)CARRY4(local_130 + 0x54a7bb0d,local_134 & 0xab5844f3);
  uVar15 = uVar9 + uVar24;
  uVar9 = (uint)CARRY4(uVar9,uVar24) + (uint)CARRY4(uVar15,local_134 & 0x2378c292);
  param_1[1] = uVar15 + (local_134 & 0x2378c292);
  *param_1 = local_130 + 0x54a7bb0d + (local_134 & 0xab5844f3);
  uVar15 = uVar9 + uVar14;
  uVar16 = (uint)CARRY4(uVar9,uVar14) + (uint)CARRY4(uVar15,local_134 & 0x8dc58f55);
  param_1[2] = uVar15 + (local_134 & 0x8dc58f55);
  uVar9 = uVar16 + uVar11;
  uVar15 = (uint)CARRY4(uVar16,uVar11) + (uint)CARRY4(uVar9,local_134 & 0x216cc272);
  param_1[3] = uVar9 + (local_134 & 0x216cc272);
  uVar16 = uVar15 + uVar7;
  uVar9 = (uint)CARRY4(uVar15,uVar7) + (uint)CARRY4(uVar16,local_134 & 0xaed63690);
  param_1[4] = uVar16 + (local_134 & 0xaed63690);
  uVar15 = uVar9 + uVar10;
  uVar9 = (uint)CARRY4(uVar9,uVar10) + (uint)CARRY4(uVar15,local_134 & 0xc44edb49);
  param_1[5] = uVar15 + (local_134 & 0xc44edb49);
  uVar16 = uVar9 + uVar17;
  uVar15 = (uint)CARRY4(uVar9,uVar17) + (uint)CARRY4(uVar16,local_134 & 0x7cca23e9);
  param_1[6] = uVar16 + (local_134 & 0x7cca23e9);
  uVar9 = uVar15 + uVar12;
  uVar15 = (uint)CARRY4(uVar15,uVar12) + (uint)CARRY4(uVar9,local_134);
  param_1[7] = uVar9 + local_134;
  uVar9 = uVar15 + uVar19;
  uVar15 = (uint)CARRY4(uVar15,uVar19) + (uint)CARRY4(uVar9,local_134);
  param_1[8] = uVar9 + local_134;
  uVar16 = uVar15 + uVar18;
  uVar9 = (uint)CARRY4(uVar15,uVar18) + (uint)CARRY4(uVar16,local_134);
  param_1[9] = uVar16 + local_134;
  uVar15 = uVar9 + uVar20;
  uVar9 = (uint)CARRY4(uVar9,uVar20) + (uint)CARRY4(uVar15,local_134);
  param_1[10] = uVar15 + local_134;
  uVar16 = uVar9 + uVar8;
  uVar15 = (uint)CARRY4(uVar9,uVar8) + (uint)CARRY4(uVar16,local_134);
  param_1[0xb] = uVar16 + local_134;
  uVar9 = uVar15 + uVar13;
  param_1[0xc] = local_134 + uVar9;
  param_1[0xd] = (uint)CARRY4(uVar15,uVar13) + (uint)CARRY4(local_134,uVar9) +
                 uVar22 + uVar23 + 0xc0000001 + (local_134 & 0x3fffffff);
  return;
}


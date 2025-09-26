
void fe_invert(undefined4 param_1,undefined4 param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  longlong lVar7;
  longlong lVar8;
  longlong lVar9;
  longlong lVar10;
  longlong lVar11;
  longlong lVar12;
  longlong lVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  int local_1e0;
  int local_1d8;
  int local_1d0;
  int local_1c8;
  int local_19c;
  int local_128;
  int local_120;
  int local_110;
  int local_e0;
  undefined1 auStack_c8 [40];
  undefined1 auStack_a0 [40];
  undefined1 auStack_78 [40];
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
  
  fe_sq(auStack_c8);
  fe_sq(auStack_a0,auStack_c8);
  fe_sq(auStack_a0,auStack_a0);
  iVar21 = 4;
  fe_mul(auStack_a0,param_2,auStack_a0);
  fe_mul(auStack_c8,auStack_c8,auStack_a0);
  fe_sq(auStack_78,auStack_c8);
  fe_mul(auStack_a0,auStack_a0,auStack_78);
  fe_sq(auStack_78,auStack_a0);
  do {
    fe_sq(auStack_78,auStack_78);
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  iVar21 = 9;
  fe_mul(auStack_a0,auStack_78,auStack_a0);
  fe_sq(auStack_78,auStack_a0);
  do {
    fe_sq(auStack_78,auStack_78);
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  iVar21 = 0x13;
  fe_mul(auStack_78,auStack_78,auStack_a0);
  fe_sq(&local_50,auStack_78);
  do {
    fe_sq(&local_50,&local_50);
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  iVar21 = 10;
  fe_mul(auStack_78,&local_50,auStack_78);
  do {
    fe_sq(auStack_78,auStack_78);
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  iVar21 = 0x31;
  fe_mul(auStack_a0,auStack_78,auStack_a0);
  fe_sq(auStack_78,auStack_a0);
  do {
    fe_sq(auStack_78,auStack_78);
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  fe_mul(auStack_78,auStack_78,auStack_a0);
  fe_sq(&local_50,auStack_78);
  local_e0 = 99;
  local_19c = local_44;
  local_1c8 = local_3c;
  do {
    iVar17 = local_4c << 1;
    iVar25 = local_2c * 0x26;
    iVar18 = local_19c << 1;
    iVar14 = local_50 << 1;
    iVar21 = local_30 * 0x13;
    iVar19 = local_1c8 << 1;
    iVar20 = local_48 << 1;
    uVar1 = (longlong)local_40 * (longlong)iVar14 +
            ((longlong)(int)((ulonglong)((longlong)iVar17 * (longlong)iVar18) >> 0x20) << 0x20 |
            (longlong)iVar17 * (longlong)iVar18 & 0xffffffffU);
    iVar22 = local_34 << 1;
    iVar23 = local_40 << 1;
    iVar29 = local_38 * 0x13;
    uVar1 = (longlong)local_48 * (longlong)local_48 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    uVar2 = (longlong)local_38 * (longlong)iVar14 +
            ((longlong)(int)((ulonglong)((longlong)iVar17 * (longlong)iVar19) >> 0x20) << 0x20 |
            (longlong)iVar17 * (longlong)iVar19 & 0xffffffffU);
    uVar1 = (longlong)iVar25 * (longlong)iVar19 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    iVar28 = local_34 * 0x26;
    uVar3 = (longlong)iVar20 * (longlong)local_19c +
            (longlong)local_1c8 * (longlong)iVar14 +
            ((longlong)(int)((ulonglong)((longlong)local_40 * (longlong)iVar17) >> 0x20) << 0x20 |
            (longlong)local_40 * (longlong)iVar17 & 0xffffffffU);
    uVar3 = (longlong)iVar25 * (longlong)local_38 +
            ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff);
    lVar4 = (longlong)iVar28 * (longlong)local_34 +
            (longlong)(local_38 << 1) * (longlong)iVar21 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    iVar26 = (int)((ulonglong)(lVar4 + 0x2000000) >> 0x20);
    uVar1 = (longlong)local_50 * (longlong)local_50 + (longlong)iVar17 * (longlong)iVar25;
    lVar5 = (longlong)iVar21 * (longlong)iVar22 +
            ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) +
            CONCAT44(iVar26 >> 0x1a,(uint)(lVar4 + 0x2000000) >> 0x1a | iVar26 * 0x40);
    uVar1 = (longlong)iVar21 * (longlong)iVar20 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    lVar6 = lVar5 + 0x1000000;
    iVar26 = (int)((ulonglong)lVar6 >> 0x20);
    local_120 = (int)lVar5;
    local_120 = local_120 - (local_120 + 0x1000000U & 0xfe000000);
    uVar2 = (longlong)iVar25 * (longlong)iVar22 +
            (longlong)iVar18 * (longlong)local_19c +
            (longlong)iVar20 * (longlong)local_40 +
            ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
    uVar1 = (longlong)iVar28 * (longlong)iVar18 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    lVar6 = (longlong)iVar21 * (longlong)local_30 +
            ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff) +
            CONCAT44(iVar26 >> 0x19,(uint)lVar6 >> 0x19 | iVar26 * 0x80);
    lVar5 = lVar6 + 0x2000000;
    uVar30 = (uint)lVar5;
    iVar26 = (int)((ulonglong)lVar5 >> 0x20);
    uVar2 = (longlong)iVar20 * (longlong)local_38 +
            (longlong)local_30 * (longlong)iVar14 + (longlong)iVar17 * (longlong)iVar22;
    uVar3 = (longlong)iVar18 * (longlong)local_40 +
            (longlong)iVar20 * (longlong)local_1c8 +
            (longlong)local_34 * (longlong)iVar14 +
            ((longlong)(int)((ulonglong)((longlong)local_38 * (longlong)iVar17) >> 0x20) << 0x20 |
            (longlong)local_38 * (longlong)iVar17 & 0xffffffffU);
    uVar1 = (longlong)iVar29 * (longlong)iVar23 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    lVar5 = (longlong)(local_1c8 * 0x26) * (longlong)local_1c8 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    lVar7 = (longlong)iVar25 * (longlong)local_30 +
            ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) +
            CONCAT44(iVar26 >> 0x1a,uVar30 >> 0x1a | iVar26 * 0x40);
    lVar8 = lVar7 + 0x1000000;
    uVar15 = (uint)lVar8;
    iVar26 = (int)((ulonglong)lVar8 >> 0x20);
    uVar1 = (longlong)iVar25 * (longlong)iVar18 +
            (longlong)local_48 * (longlong)iVar14 +
            ((longlong)(int)((ulonglong)((longlong)local_4c * (longlong)iVar17) >> 0x20) << 0x20 |
            (longlong)local_4c * (longlong)iVar17 & 0xffffffffU);
    iVar22 = (int)((ulonglong)(lVar5 + 0x2000000) >> 0x20);
    uVar3 = (longlong)iVar28 * (longlong)local_40 +
            (longlong)iVar21 * (longlong)iVar18 +
            (longlong)local_4c * (longlong)iVar14 +
            ((longlong)(int)((ulonglong)((longlong)local_48 * (longlong)iVar25) >> 0x20) << 0x20 |
            (longlong)local_48 * (longlong)iVar25 & 0xffffffffU);
    uVar2 = (longlong)local_40 * (longlong)local_40 +
            (longlong)iVar19 * (longlong)iVar18 +
            ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
    uVar1 = (longlong)iVar23 * (longlong)iVar21 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    lVar8 = (longlong)iVar29 * (longlong)iVar19 +
            ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff) +
            CONCAT44(iVar22 >> 0x1a,(uint)(lVar5 + 0x2000000) >> 0x1a | iVar22 * 0x40);
    iVar22 = (int)((ulonglong)(lVar8 + 0x1000000) >> 0x20);
    uVar1 = (longlong)iVar28 * (longlong)iVar19 +
            ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
    lVar9 = (longlong)iVar25 * (longlong)local_2c +
            ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff) +
            CONCAT44(iVar26 >> 0x19,uVar15 >> 0x19 | iVar26 * 0x80);
    uVar2 = (longlong)iVar18 * (longlong)local_38 +
            (longlong)iVar20 * (longlong)local_34 +
            (longlong)local_2c * (longlong)iVar14 + (longlong)local_30 * (longlong)iVar17;
    lVar10 = lVar9 + 0x2000000;
    uVar31 = (uint)lVar10;
    iVar26 = (int)((ulonglong)lVar10 >> 0x20);
    uVar3 = (longlong)iVar25 * (longlong)local_40 +
            (longlong)local_19c * (longlong)iVar14 +
            ((longlong)(int)((ulonglong)((longlong)local_48 * (longlong)iVar17) >> 0x20) << 0x20 |
            (longlong)local_48 * (longlong)iVar17 & 0xffffffffU);
    lVar10 = (longlong)iVar29 * (longlong)local_38 +
             ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff) +
             CONCAT44(iVar22 >> 0x19,(uint)(lVar8 + 0x1000000) >> 0x19 | iVar22 * 0x80);
    uVar1 = (longlong)iVar21 * (longlong)iVar19 +
            ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff);
    lVar12 = lVar10 + 0x2000000;
    iVar21 = (int)((ulonglong)lVar12 >> 0x20);
    local_1d0 = (int)lVar10;
    lVar10 = (longlong)iVar23 * (longlong)local_1c8 +
             ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff) +
             CONCAT44(iVar26 >> 0x1a,uVar31 >> 0x1a | iVar26 * 0x40);
    lVar11 = lVar10 + 0x1000000;
    uVar27 = (uint)lVar11;
    iVar29 = (int)((ulonglong)lVar11 >> 0x20);
    local_1d0 = local_1d0 - (local_1d0 + 0x2000000U & 0xfc000000);
    uVar24 = iVar29 * 0x80;
    uVar16 = uVar27 >> 0x19 | uVar24;
    iVar29 = iVar29 >> 0x19;
    lVar11 = (longlong)iVar28 * (longlong)local_38 +
             ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff) +
             CONCAT44(iVar21 >> 0x1a,(uint)lVar12 >> 0x1a | iVar21 * 0x40);
    uVar1 = lVar11 + 0x1000000;
    iVar21 = (int)(uVar1 >> 0x20);
    lVar5 = (lVar5 - (lVar5 + 0x2000000U & 0xfffffffffc000000)) +
            CONCAT44(iVar29 * 3 +
                     ((iVar29 << 3 | uVar24 >> 0x1d) + (uint)CARRY4(uVar16,uVar16 * 8)) * 2 +
                     (uint)CARRY4(uVar16 * 9,uVar16 * 9) + (uint)CARRY4(uVar16,uVar16 * 0x12),
                     uVar16 * 0x13);
    lVar12 = (lVar4 - (lVar4 + 0x2000000U & 0xfffffffffc000000)) +
             CONCAT44(iVar21 >> 0x19,(uint)uVar1 >> 0x19 | iVar21 * 0x80);
    lVar4 = lVar5 + 0x2000000;
    uVar16 = (uint)lVar4;
    lVar13 = lVar12 + 0x2000000;
    uVar24 = (uint)lVar13;
    local_50 = (int)lVar5 - (uVar16 & 0xfc000000);
    local_4c = (int)((lVar8 - (lVar8 + 0x1000000U & 0xfffffffffe000000)) +
                    (ulonglong)(uVar16 >> 0x1a | (int)((ulonglong)lVar4 >> 0x20) * 0x40));
    local_19c = (int)(lVar11 - (uVar1 & 0xfffffffffe000000));
    local_128 = (int)lVar6;
    local_1d8 = (int)lVar10;
    local_38 = local_128 - (uVar30 & 0xfc000000);
    local_2c = local_1d8 - (uVar27 & 0xfe000000);
    local_1e0 = (int)lVar9;
    local_1c8 = (uVar24 >> 0x1a | (int)((ulonglong)lVar13 >> 0x20) * 0x40) + local_120;
    local_30 = local_1e0 - (uVar31 & 0xfc000000);
    local_110 = (int)lVar7;
    local_40 = (int)lVar12 - (uVar24 & 0xfc000000);
    local_34 = local_110 - (uVar15 & 0xfe000000);
    local_e0 = local_e0 + -1;
    local_48 = local_1d0;
  } while (local_e0 != 0);
  iVar21 = 0x31;
  local_44 = local_19c;
  local_3c = local_1c8;
  fe_mul(auStack_78,&local_50,auStack_78);
  fe_sq(auStack_78);
  do {
    fe_sq(auStack_78,auStack_78);
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  iVar21 = 4;
  fe_mul(auStack_a0,auStack_78,auStack_a0);
  fe_sq(auStack_a0,auStack_a0);
  do {
    fe_sq(auStack_a0,auStack_a0);
    iVar21 = iVar21 + -1;
  } while (iVar21 != 0);
  fe_mul(param_1,auStack_a0,auStack_c8);
  return;
}


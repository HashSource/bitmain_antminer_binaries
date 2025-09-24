
void ge_p2_dbl(int *param_1,int *param_2)

{
  ulonglong uVar1;
  ulonglong uVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  longlong lVar6;
  ulonglong uVar7;
  uint uVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  int iVar34;
  uint uVar35;
  int iVar36;
  int iVar37;
  uint uVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  uint uVar42;
  uint uVar43;
  int iVar44;
  int iVar45;
  uint local_d8;
  int local_d4;
  uint local_c8;
  int local_c4;
  uint local_c0;
  int local_bc;
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
  
  fe_sq();
  fe_sq(param_1 + 0x14,param_2 + 10);
  iVar14 = param_2[0x14];
  iVar10 = param_2[0x1c] * 0x14 - param_2[0x1c];
  iVar40 = param_2[0x1d] * 0x26;
  iVar18 = param_2[0x16] << 1;
  iVar37 = iVar14 << 1;
  iVar24 = param_2[0x18] << 1;
  iVar34 = param_2[0x15] << 1;
  iVar11 = param_2[0x19] << 1;
  iVar22 = param_2[0x17] << 1;
  iVar17 = param_2[0x1a] * 0x13;
  uVar1 = (longlong)param_2[0x18] * (longlong)iVar37 +
          ((longlong)(int)((ulonglong)((longlong)iVar34 * (longlong)iVar22) >> 0x20) << 0x20 |
          (longlong)iVar34 * (longlong)iVar22 & 0xffffffffU);
  uVar2 = (longlong)iVar10 * (longlong)iVar18 +
          (longlong)iVar14 * (longlong)iVar14 +
          ((longlong)(int)((ulonglong)((longlong)iVar34 * (longlong)iVar40) >> 0x20) << 0x20 |
          (longlong)iVar34 * (longlong)iVar40 & 0xffffffffU);
  uVar1 = (longlong)param_2[0x16] * (longlong)param_2[0x16] +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  iVar30 = param_2[0x1b] * 0x26;
  uVar2 = (longlong)iVar30 * (longlong)iVar22 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  uVar3 = (longlong)param_2[0x15] * (longlong)iVar37 + (longlong)param_2[0x16] * (longlong)iVar40;
  uVar2 = (longlong)iVar17 * (longlong)iVar24 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  lVar4 = (longlong)iVar30 * (longlong)param_2[0x1b] +
          (longlong)(param_2[0x1a] << 1) * (longlong)iVar10 +
          (longlong)iVar40 * (longlong)iVar11 +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff);
  uVar15 = (uint)lVar4;
  uVar21 = uVar15 * 2;
  uVar1 = (longlong)param_2[0x1a] * (longlong)iVar37 + (longlong)iVar34 * (longlong)iVar11;
  iVar14 = (int)((ulonglong)lVar4 >> 0x20) * 2 + (uint)CARRY4(uVar15,uVar15);
  iVar23 = iVar14 + (uint)(0xfdffffff < uVar21);
  lVar4 = (longlong)(param_2[0x19] * 0x26) * (longlong)param_2[0x19] +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  uVar15 = (uint)lVar4;
  uVar42 = uVar21 + 0x2000000 >> 0x1a | iVar23 * 0x40;
  uVar8 = uVar15 * 2;
  iVar13 = (int)((ulonglong)lVar4 >> 0x20) * 2 + (uint)CARRY4(uVar15,uVar15);
  uVar19 = uVar21 + 0x2000000 & 0xfc000000;
  iVar16 = iVar13 + (uint)(0xfdffffff < uVar8);
  uVar25 = uVar21 - uVar19;
  uVar20 = uVar8 + 0x2000000 & 0xfc000000;
  uVar2 = (longlong)iVar30 * (longlong)param_2[0x18] +
          (longlong)iVar10 * (longlong)iVar22 +
          ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff);
  uVar43 = uVar8 + 0x2000000 >> 0x1a | iVar16 * 0x40;
  iVar44 = param_2[0x1b] << 1;
  uVar31 = uVar8 - uVar20;
  lVar4 = (longlong)iVar17 * (longlong)iVar11 +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  uVar15 = (uint)lVar4;
  lVar5 = (longlong)iVar10 * (longlong)iVar44 +
          (longlong)iVar40 * (longlong)param_2[0x1a] +
          (longlong)iVar18 * (longlong)param_2[0x17] +
          (longlong)param_2[0x19] * (longlong)iVar37 +
          ((longlong)(int)((ulonglong)((longlong)param_2[0x18] * (longlong)iVar34) >> 0x20) << 0x20
          | (longlong)param_2[0x18] * (longlong)iVar34 & 0xffffffffU);
  uVar32 = (uint)lVar5;
  uVar12 = uVar43 + uVar15 * 2;
  uVar33 = uVar42 + uVar32 * 2;
  uVar2 = (longlong)param_2[0x1b] * (longlong)iVar37 +
          ((longlong)(int)((ulonglong)((longlong)param_2[0x1a] * (longlong)iVar34) >> 0x20) << 0x20
          | (longlong)param_2[0x1a] * (longlong)iVar34 & 0xffffffffU);
  uVar3 = (longlong)iVar30 * (longlong)iVar11 +
          (longlong)iVar24 * (longlong)iVar10 +
          (longlong)iVar40 * (longlong)iVar22 +
          (longlong)param_2[0x16] * (longlong)iVar37 +
          ((longlong)(int)((ulonglong)((longlong)param_2[0x15] * (longlong)iVar34) >> 0x20) << 0x20
          | (longlong)param_2[0x15] * (longlong)iVar34 & 0xffffffffU);
  lVar6 = (longlong)iVar17 * (longlong)param_2[0x1a] +
          ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff);
  iVar28 = (iVar16 >> 0x1a) + (int)((ulonglong)lVar4 >> 0x20) * 2 + (uint)CARRY4(uVar15,uVar15) +
           (uint)CARRY4(uVar43,uVar15 * 2) + (uint)(0xfeffffff < uVar12);
  uVar15 = uVar12 + 0x1000000 >> 0x19 | iVar28 * 0x80;
  local_c0 = (uint)lVar6;
  local_bc = (int)((ulonglong)lVar6 >> 0x20);
  uVar26 = uVar15 + local_c0 * 2;
  iVar17 = (iVar23 >> 0x1a) +
           (int)((ulonglong)lVar5 >> 0x20) * 2 + (uint)CARRY4(uVar32,uVar32) +
           (uint)CARRY4(uVar42,uVar32 * 2) + (uint)(0xfeffffff < uVar33);
  iVar28 = (iVar28 >> 0x19) + local_bc * 2 + (uint)CARRY4(local_c0,local_c0) +
           (uint)CARRY4(uVar15,local_c0 * 2) + (uint)(0xfdffffff < uVar26);
  uVar3 = (longlong)iVar10 * (longlong)iVar11 +
          (longlong)iVar40 * (longlong)param_2[0x18] +
          (longlong)param_2[0x17] * (longlong)iVar37 +
          ((longlong)(int)((ulonglong)((longlong)param_2[0x16] * (longlong)iVar34) >> 0x20) << 0x20
          | (longlong)param_2[0x16] * (longlong)iVar34 & 0xffffffffU);
  uVar7 = (longlong)iVar11 * (longlong)iVar22 +
          (longlong)iVar18 * (longlong)param_2[0x1a] +
          (longlong)param_2[0x1c] * (longlong)iVar37 + (longlong)iVar34 * (longlong)iVar44;
  lVar6 = ((longlong)iVar10 * (longlong)param_2[0x1c] +
          (longlong)iVar40 * (longlong)iVar44 +
          (longlong)iVar22 * (longlong)param_2[0x17] +
          (longlong)iVar18 * (longlong)param_2[0x18] +
          ((longlong)(int)(uVar1 >> 0x20) << 0x20 | uVar1 & 0xffffffff)) * 2 +
          CONCAT44(iVar17 >> 0x19,uVar33 + 0x1000000 >> 0x19 | iVar17 * 0x80);
  lVar4 = lVar6 + 0x2000000;
  uVar32 = (uint)lVar4;
  iVar17 = (int)((ulonglong)lVar4 >> 0x20);
  uVar15 = uVar32 >> 0x1a | iVar17 * 0x40;
  lVar4 = (longlong)iVar40 * (longlong)param_2[0x1c] +
          (longlong)iVar22 * (longlong)param_2[0x18] +
          (longlong)iVar18 * (longlong)param_2[0x19] +
          ((longlong)(int)(uVar2 >> 0x20) << 0x20 | uVar2 & 0xffffffff);
  lVar9 = ((longlong)iVar30 * (longlong)param_2[0x1a] +
          ((longlong)(int)(uVar3 >> 0x20) << 0x20 | uVar3 & 0xffffffff)) * 2 +
          CONCAT44(iVar28 >> 0x1a,uVar26 + 0x2000000 >> 0x1a | iVar28 * 0x40);
  lVar5 = lVar9 + 0x1000000;
  uVar29 = (uint)lVar5;
  iVar11 = (int)((ulonglong)lVar5 >> 0x20);
  local_d8 = (uint)lVar4;
  local_d4 = (int)((ulonglong)lVar4 >> 0x20);
  uVar43 = uVar29 >> 0x19 | iVar11 * 0x80;
  uVar35 = uVar15 + local_d8 * 2;
  iVar17 = (iVar17 >> 0x1a) +
           local_d4 * 2 + (uint)CARRY4(local_d8,local_d8) + (uint)CARRY4(uVar15,local_d8 * 2) +
           (uint)(0xfeffffff < uVar35);
  lVar4 = (longlong)iVar40 * (longlong)param_2[0x1d] +
          (longlong)param_2[0x18] * (longlong)param_2[0x18] +
          ((longlong)(int)(uVar7 >> 0x20) << 0x20 | uVar7 & 0xffffffff);
  uVar15 = uVar35 + 0x1000000 >> 0x19 | iVar17 * 0x80;
  uVar42 = uVar43 + uVar25;
  lVar5 = (longlong)iVar24 * (longlong)param_2[0x19] +
          (longlong)iVar22 * (longlong)param_2[0x1a] +
          (longlong)iVar18 * (longlong)param_2[0x1b] +
          (longlong)param_2[0x1d] * (longlong)iVar37 +
          ((longlong)(int)((ulonglong)((longlong)param_2[0x1c] * (longlong)iVar34) >> 0x20) << 0x20
          | (longlong)param_2[0x1c] * (longlong)iVar34 & 0xffffffffU);
  uVar27 = (uint)lVar5;
  local_c8 = (uint)lVar4;
  local_c4 = (int)((ulonglong)lVar4 >> 0x20);
  uVar38 = uVar15 + local_c8 * 2;
  iVar17 = (iVar17 >> 0x19) +
           local_c4 * 2 + (uint)CARRY4(local_c8,local_c8) + (uint)CARRY4(uVar15,local_c8 * 2) +
           (uint)(0xfdffffff < uVar38);
  param_1[0x21] = (int)lVar9 - (uVar29 & 0xfe000000);
  uVar15 = uVar38 + 0x2000000 >> 0x1a | iVar17 * 0x40;
  param_1[0x25] = uVar35 - (uVar35 + 0x1000000 & 0xfe000000);
  param_1[0x20] = uVar26 - (uVar26 + 0x2000000 & 0xfc000000);
  uVar29 = uVar15 + uVar27 * 2;
  iVar10 = (iVar17 >> 0x1a) +
           (int)((ulonglong)lVar5 >> 0x20) * 2 + (uint)CARRY4(uVar27,uVar27) +
           (uint)CARRY4(uVar15,uVar27 * 2) + (uint)(0xfeffffff < uVar29);
  iVar17 = iVar10 >> 0x19;
  uVar15 = iVar10 * 0x80;
  uVar26 = uVar29 + 0x1000000 >> 0x19 | uVar15;
  param_1[0x24] = (int)lVar6 - (uVar32 & 0xfc000000);
  param_1[0x26] = uVar38 - (uVar38 + 0x2000000 & 0xfc000000);
  param_1[0x27] = uVar29 - (uVar29 + 0x1000000 & 0xfe000000);
  param_1[0x22] = uVar42 - (uVar42 + 0x2000000 & 0xfc000000);
  param_1[0x23] =
       (uVar33 - (uVar33 + 0x1000000 & 0xfe000000)) +
       (uVar42 + 0x2000000 >> 0x1a |
       ((iVar11 >> 0x19) + ((iVar14 - iVar23) - (uint)(uVar21 < uVar19)) +
        (uint)CARRY4(uVar43,uVar25) + (uint)(0xfdffffff < uVar42)) * 0x40);
  uVar21 = uVar31 + uVar26 * 0x13;
  param_1[0x1e] = uVar21 - (uVar21 + 0x2000000 & 0xfc000000);
  param_1[0x1f] =
       (uVar12 - (uVar12 + 0x1000000 & 0xfe000000)) +
       (uVar21 + 0x2000000 >> 0x1a |
       (((iVar13 - iVar16) - (uint)(uVar8 < uVar20)) +
        iVar17 * 3 + ((iVar17 << 3 | uVar15 >> 0x1d) + (uint)CARRY4(uVar26,uVar26 * 8)) * 2 +
        (uint)CARRY4(uVar26 * 9,uVar26 * 9) + (uint)CARRY4(uVar26,uVar26 * 0x12) +
        (uint)CARRY4(uVar31,uVar26 * 0x13) + (uint)(0xfdffffff < uVar21)) * 0x40);
  param_1[10] = param_2[10] + *param_2;
  param_1[0xb] = param_2[0xb] + param_2[1];
  param_1[0xc] = param_2[0xc] + param_2[2];
  param_1[0xd] = param_2[0xd] + param_2[3];
  param_1[0xe] = param_2[0xe] + param_2[4];
  param_1[0xf] = param_2[0xf] + param_2[5];
  param_1[0x10] = param_2[0x10] + param_2[6];
  param_1[0x11] = param_2[0x11] + param_2[7];
  param_1[0x12] = param_2[0x12] + param_2[8];
  param_1[0x13] = param_2[0x13] + param_2[9];
  fe_sq(&local_50,param_1 + 10);
  iVar41 = param_1[0x14] + *param_1;
  iVar17 = param_1[0x14] - *param_1;
  iVar45 = param_1[0x15] + param_1[1];
  iVar22 = param_1[0x15] - param_1[1];
  iVar28 = param_1[0x16] - param_1[2];
  iVar18 = param_1[2] + param_1[0x16];
  iVar30 = param_1[0x17] + param_1[3];
  iVar34 = param_1[0x17] - param_1[3];
  iVar37 = param_1[0x18] + param_1[4];
  iVar23 = param_1[0x18] - param_1[4];
  iVar24 = param_1[0x19] + param_1[5];
  iVar14 = param_1[0x19] - param_1[5];
  iVar13 = param_1[0x1a] + param_1[6];
  iVar10 = param_1[0x1a] - param_1[6];
  iVar11 = param_1[0x1b] + param_1[7];
  iVar39 = param_1[0x1b] - param_1[7];
  iVar16 = param_1[0x1c] + param_1[8];
  iVar36 = param_1[0x1c] - param_1[8];
  param_1[10] = iVar41;
  param_1[0x14] = iVar17;
  param_1[0xb] = iVar45;
  iVar44 = param_1[0x1d] + param_1[9];
  param_1[0x15] = iVar22;
  param_1[0xc] = iVar18;
  param_1[0x12] = iVar16;
  iVar40 = param_1[0x1d] - param_1[9];
  param_1[0xd] = iVar30;
  param_1[0x16] = iVar28;
  param_1[0xf] = iVar24;
  param_1[0xe] = iVar37;
  param_1[0x11] = iVar11;
  param_1[2] = local_48 - iVar18;
  param_1[0x10] = iVar13;
  param_1[0x13] = iVar44;
  param_1[4] = local_40 - iVar37;
  param_1[3] = local_44 - iVar30;
  param_1[6] = local_38 - iVar13;
  param_1[7] = local_34 - iVar11;
  param_1[0x17] = iVar34;
  param_1[8] = local_30 - iVar16;
  param_1[0x1b] = iVar39;
  param_1[0x1f] = param_1[0x1f] - iVar22;
  param_1[0x1c] = iVar36;
  param_1[0x18] = iVar23;
  param_1[0x1d] = iVar40;
  *param_1 = local_50 - iVar41;
  param_1[1] = local_4c - iVar45;
  param_1[0x20] = param_1[0x20] - iVar28;
  param_1[5] = local_3c - iVar24;
  param_1[9] = local_2c - iVar44;
  param_1[0x19] = iVar14;
  param_1[0x1a] = iVar10;
  param_1[0x1e] = param_1[0x1e] - iVar17;
  param_1[0x21] = param_1[0x21] - iVar34;
  param_1[0x22] = param_1[0x22] - iVar23;
  param_1[0x23] = param_1[0x23] - iVar14;
  param_1[0x24] = param_1[0x24] - iVar10;
  param_1[0x25] = param_1[0x25] - iVar39;
  param_1[0x26] = param_1[0x26] - iVar36;
  param_1[0x27] = param_1[0x27] - iVar40;
  return;
}


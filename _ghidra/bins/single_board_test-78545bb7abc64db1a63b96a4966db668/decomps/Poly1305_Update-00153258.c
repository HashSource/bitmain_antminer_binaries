
void Poly1305_Update(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint *puVar2;
  ulonglong uVar3;
  longlong lVar4;
  longlong lVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint *puVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint local_158;
  uint *local_140;
  ulonglong local_120;
  undefined4 local_118;
  undefined4 local_114;
  uint local_110;
  uint local_10c;
  uint local_100;
  undefined4 local_fc;
  uint local_c8;
  int local_bc;
  uint local_b8;
  undefined4 uStack_ac;
  uint *local_30;
  
  uVar16 = param_1[0x38];
  local_30 = param_2;
  if (uVar16 != 0) {
    uVar23 = 0x10 - uVar16;
    if (param_3 < uVar23) {
      memcpy((void *)((int)param_1 + uVar16 + 0xd0),param_2,param_3);
      param_1[0x38] = uVar16 + param_3;
      return;
    }
    local_30 = (uint *)((int)param_2 + uVar23);
    memcpy((void *)((int)param_1 + uVar16 + 0xd0),param_2,uVar23);
    uVar17 = param_1[8];
    uVar21 = uVar17 + (uVar17 >> 2);
    uVar16 = (uint)CARRY4(param_1[0x34],*param_1);
    uVar24 = param_1[0x35] + param_1[1];
    uVar12 = uVar16 + uVar24;
    uVar16 = (uint)CARRY4(param_1[0x35],param_1[1]) + (uint)CARRY4(uVar16,uVar24);
    uVar13 = param_1[5];
    uVar14 = param_1[7];
    uVar30 = param_1[6];
    uVar24 = param_1[0x36] + param_1[2];
    uVar27 = uVar16 + uVar24;
    uVar16 = (uint)CARRY4(param_1[0x36],param_1[2]) + (uint)CARRY4(uVar16,uVar24);
    uVar28 = param_1[0x37] + param_1[3];
    uVar25 = uVar30 + (uVar30 >> 2);
    uVar24 = uVar14 + (uVar14 >> 2);
    uVar15 = *param_1 + param_1[0x34];
    uVar18 = uVar16 + uVar28;
    param_3 = param_3 - uVar23;
    iVar11 = param_1[4] + 1 + (uint)CARRY4(param_1[0x37],param_1[3]) + (uint)CARRY4(uVar16,uVar28);
    uVar28 = iVar11 * uVar25;
    lVar4 = (ulonglong)uVar13 * (ulonglong)uVar15 + (ulonglong)uVar12 * (ulonglong)uVar21 +
            (ulonglong)uVar27 * (ulonglong)uVar24 + (ulonglong)uVar25 * (ulonglong)uVar18;
    lVar5 = (ulonglong)uVar18 * (ulonglong)uVar24 +
            (ulonglong)uVar30 * (ulonglong)uVar15 + (ulonglong)uVar13 * (ulonglong)uVar12 +
            (ulonglong)uVar21 * (ulonglong)uVar27;
    uVar16 = (uint)lVar5;
    local_10c = (uint)((ulonglong)lVar4 >> 0x20);
    uVar23 = uVar16 + local_10c;
    uVar25 = uVar23 + uVar28;
    uVar16 = (int)((ulonglong)lVar5 >> 0x20) + (uint)CARRY4(uVar16,local_10c) +
             (uint)CARRY4(uVar23,uVar28);
    lVar5 = (ulonglong)uVar21 * (ulonglong)uVar18 +
            (ulonglong)uVar14 * (ulonglong)uVar15 + (ulonglong)uVar12 * (ulonglong)uVar30 +
            (ulonglong)uVar13 * (ulonglong)uVar27;
    uVar29 = (uint)lVar5;
    uVar23 = uVar29 + iVar11 * uVar24;
    uVar28 = uVar16 + uVar23;
    uVar16 = (int)((ulonglong)lVar5 >> 0x20) + (uint)CARRY4(uVar29,iVar11 * uVar24) +
             (uint)CARRY4(uVar16,uVar23);
    lVar5 = (ulonglong)uVar13 * (ulonglong)uVar18 +
            (ulonglong)uVar17 * (ulonglong)uVar15 + (ulonglong)uVar14 * (ulonglong)uVar12 +
            (ulonglong)uVar27 * (ulonglong)uVar30;
    uVar24 = (uint)lVar5;
    uVar23 = uVar24 + iVar11 * uVar21;
    uVar12 = uVar16 + uVar23;
    local_110 = (uint)lVar4;
    uVar23 = iVar11 * uVar13 +
             (int)((ulonglong)lVar5 >> 0x20) + (uint)CARRY4(uVar24,iVar11 * uVar21) +
             (uint)CARRY4(uVar16,uVar23);
    uVar24 = (uVar23 & 0xfffffffc) + (uVar23 >> 2);
    uVar16 = uVar24 + local_110;
    *param_1 = uVar16;
    uVar16 = uVar25 - ((int)((uVar24 ^ uVar16 | uVar24 ^ local_110) ^ uVar16) >> 0x1f);
    param_1[1] = uVar16;
    uVar16 = uVar28 - ((int)((uVar16 | uVar25) ^ uVar16) >> 0x1f);
    param_1[2] = uVar16;
    uVar16 = uVar12 - ((int)((uVar16 | uVar28) ^ uVar16) >> 0x1f);
    param_1[3] = uVar16;
    param_1[4] = (uVar23 & 3) - ((int)((uVar16 | uVar12) ^ uVar16) >> 0x1f);
  }
  uVar16 = param_3 & 0xf;
  uVar23 = param_3 - uVar16;
  if (0xf < uVar23) {
    uVar14 = param_1[7];
    uVar21 = param_1[6];
    uVar24 = param_1[8];
    uVar15 = param_1[5];
    uVar18 = *param_1;
    uVar12 = uVar14 + (uVar14 >> 2);
    uVar28 = uVar21 + (uVar21 >> 2);
    local_120 = (ulonglong)uVar12;
    uVar13 = uVar24 + (uVar24 >> 2);
    uVar27 = param_1[1];
    uVar17 = param_1[2];
    uVar25 = param_1[3];
    uVar29 = param_1[4];
    if (uVar23 - 0x10 < 0x20) {
      local_140 = local_30;
      uVar30 = uVar23;
    }
    else {
      local_140 = local_30;
      uVar19 = uVar23;
      do {
        uVar30 = uVar19 - 0x20;
        uVar20 = (uint)CARRY4(*local_140,uVar18);
        uVar18 = uVar18 + *local_140;
        uVar26 = uVar17 + local_140[2];
        uVar8 = uVar25 + local_140[3];
        HintPreloadData(local_140 + 0xf);
        uVar9 = uVar20 + local_140[1];
        uVar10 = uVar9 + uVar27;
        uVar27 = (uint)CARRY4(uVar20,local_140[1]) + (uint)CARRY4(uVar9,uVar27);
        uVar9 = uVar19 - 0x30;
        uVar19 = uVar27 + uVar26;
        uVar17 = (uint)CARRY4(uVar17,local_140[2]) + (uint)CARRY4(uVar27,uVar26);
        uVar27 = uVar17 + uVar8;
        iVar11 = uVar29 + (uint)CARRY4(uVar25,local_140[3]) + (uint)CARRY4(uVar17,uVar8) + 1;
        uVar3 = (ulonglong)uVar14 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar21;
        lVar4 = (ulonglong)uVar15 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar13 +
                uVar19 * local_120 + (ulonglong)uVar27 * (ulonglong)uVar28;
        local_fc = (undefined4)((ulonglong)lVar4 >> 0x20);
        uVar6 = (ulonglong)uVar21 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar15 +
                (ulonglong)uVar19 * (ulonglong)uVar13;
        uVar6 = uVar27 * local_120 + (uVar6 & 0xffffffff) + CONCAT44((int)(uVar6 >> 0x20),local_fc)
                + (ulonglong)(iVar11 * uVar28);
        uStack_ac = (undefined4)(uVar3 >> 0x20);
        local_114 = (undefined4)((ulonglong)uVar27 * (ulonglong)uVar13 >> 0x20);
        local_118 = (undefined4)((ulonglong)uVar27 * (ulonglong)uVar13);
        puVar22 = local_140 + 8;
        uVar3 = (ulonglong)uVar19 * (ulonglong)uVar15 + (uVar3 & 0xffffffff) +
                CONCAT44(uStack_ac,local_118) + CONCAT44(local_114,iVar11 * uVar12) +
                (uVar6 >> 0x20);
        uVar7 = (ulonglong)uVar24 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar14 +
                (ulonglong)uVar19 * (ulonglong)uVar21;
        local_100 = (uint)lVar4;
        lVar4 = (ulonglong)uVar27 * (ulonglong)uVar15 + (uVar7 & 0xffffffff) +
                CONCAT44((int)(uVar7 >> 0x20),iVar11 * uVar13) + (uVar3 >> 0x20);
        uVar19 = iVar11 * uVar15 + (int)((ulonglong)lVar4 >> 0x20);
        uVar18 = (uVar19 & 0xfffffffc) + (uVar19 >> 2);
        uVar26 = uVar18 + local_100;
        uVar25 = (uint)CARRY4(uVar26,local_140[4]);
        local_b8 = (uint)uVar6;
        uVar17 = uVar25 + local_140[5];
        uVar27 = local_b8 - ((int)((uVar18 ^ uVar26 | uVar18 ^ local_100) ^ uVar26) >> 0x1f);
        uVar18 = uVar17 + uVar27;
        uVar25 = (uint)CARRY4(uVar25,local_140[5]) + (uint)CARRY4(uVar17,uVar27);
        uVar17 = -((int)((uVar27 | local_b8) ^ uVar27) >> 0x1f);
        uVar29 = uVar25 + local_140[6];
        local_110 = (uint)uVar3;
        uVar27 = uVar17 + local_110;
        uVar8 = uVar29 + uVar27;
        uVar17 = -((int)(uVar27 ^ (uVar17 ^ uVar27 | local_110 ^ uVar17)) >> 0x1f);
        uVar27 = (uint)CARRY4(uVar25,local_140[6]) + (uint)CARRY4(uVar29,uVar27);
        local_158 = (uint)lVar4;
        uVar25 = uVar17 + local_158;
        uVar29 = uVar27 + local_140[7];
        uVar10 = uVar29 + uVar25;
        iVar11 = (((uVar19 & 3) + 1) -
                 ((int)((local_158 ^ uVar17 | uVar17 ^ uVar25) ^ uVar25) >> 0x1f)) +
                 (uint)CARRY4(uVar27,local_140[7]) + (uint)CARRY4(uVar29,uVar25);
        uVar26 = uVar26 + local_140[4];
        lVar4 = (ulonglong)uVar15 * (ulonglong)uVar26 + (ulonglong)uVar18 * (ulonglong)uVar13 +
                uVar8 * local_120 + (ulonglong)uVar10 * (ulonglong)uVar28;
        uVar27 = (uint)lVar4;
        uVar29 = (uint)((ulonglong)lVar4 >> 0x20);
        lVar4 = (ulonglong)uVar21 * (ulonglong)uVar26 + (ulonglong)uVar18 * (ulonglong)uVar15 +
                (ulonglong)uVar8 * (ulonglong)uVar13 + uVar10 * local_120;
        uVar19 = (uint)lVar4;
        uVar25 = uVar29 + uVar19;
        uVar17 = uVar25 + iVar11 * uVar28;
        lVar4 = (ulonglong)uVar14 * (ulonglong)uVar26 + (ulonglong)uVar18 * (ulonglong)uVar21 +
                (ulonglong)uVar8 * (ulonglong)uVar15 + (ulonglong)uVar10 * (ulonglong)uVar13 +
                (ulonglong)(iVar11 * uVar12) +
                (ulonglong)
                ((int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar29,uVar19) +
                (uint)CARRY4(uVar25,iVar11 * uVar28));
        uVar20 = (uint)lVar4;
        uVar19 = (uint)((ulonglong)lVar4 >> 0x20);
        lVar4 = (ulonglong)uVar8 * (ulonglong)uVar21 +
                (ulonglong)uVar24 * (ulonglong)uVar26 + (ulonglong)uVar18 * (ulonglong)uVar14 +
                (ulonglong)uVar10 * (ulonglong)uVar15;
        uVar25 = (uint)lVar4;
        uVar18 = uVar25 + iVar11 * uVar13;
        uVar29 = uVar19 + uVar18;
        uVar19 = iVar11 * uVar15 +
                 (int)((ulonglong)lVar4 >> 0x20) + (uint)CARRY4(uVar25,iVar11 * uVar13) +
                 (uint)CARRY4(uVar19,uVar18);
        uVar25 = (uVar19 & 0xfffffffc) + (uVar19 >> 2);
        uVar18 = uVar25 + uVar27;
        uVar25 = -((int)((uVar25 ^ uVar18 | uVar25 ^ uVar27) ^ uVar18) >> 0x1f);
        uVar27 = uVar25 + uVar17;
        uVar25 = -((int)((uVar27 ^ uVar25 | uVar25 ^ uVar17) ^ uVar27) >> 0x1f);
        uVar17 = uVar25 + uVar20;
        uVar20 = -((int)((uVar20 ^ uVar25 | uVar25 ^ uVar17) ^ uVar17) >> 0x1f);
        uVar25 = uVar20 + uVar29;
        uVar29 = (uVar19 & 3) - ((int)((uVar29 ^ uVar20 | uVar20 ^ uVar25) ^ uVar25) >> 0x1f);
        local_140 = puVar22;
        uVar19 = uVar30;
      } while (0x1f < uVar9);
    }
    do {
      puVar22 = local_140 + 1;
      puVar1 = local_140 + 2;
      puVar2 = local_140 + 3;
      uVar30 = uVar30 - 0x10;
      uVar19 = (uint)CARRY4(*local_140,uVar18);
      uVar20 = uVar17 + *puVar1;
      uVar8 = uVar25 + *puVar2;
      uVar18 = uVar18 + *local_140;
      uVar9 = uVar19 + *puVar22;
      uVar10 = uVar9 + uVar27;
      local_140 = local_140 + 4;
      uVar19 = (uint)CARRY4(uVar19,*puVar22) + (uint)CARRY4(uVar9,uVar27);
      uVar27 = uVar19 + uVar20;
      uVar19 = (uint)CARRY4(uVar17,*puVar1) + (uint)CARRY4(uVar19,uVar20);
      uVar17 = uVar19 + uVar8;
      iVar11 = uVar29 + (uint)CARRY4(uVar25,*puVar2) + (uint)CARRY4(uVar19,uVar8) + 1;
      uVar3 = (ulonglong)uVar14 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar21;
      lVar4 = (ulonglong)uVar15 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar13 +
              uVar27 * local_120 + (ulonglong)uVar17 * (ulonglong)uVar28;
      uVar6 = (ulonglong)uVar21 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar15 +
              (ulonglong)uVar27 * (ulonglong)uVar13;
      uVar6 = uVar17 * local_120 + (uVar6 & 0xffffffff) +
              CONCAT44((int)(uVar6 >> 0x20),(int)((ulonglong)lVar4 >> 0x20)) +
              (ulonglong)(iVar11 * uVar28);
      local_bc = (int)(uVar3 >> 0x20);
      lVar5 = (ulonglong)uVar27 * (ulonglong)uVar15 + (uVar3 & 0xffffffff);
      lVar5 = (ulonglong)uVar17 * (ulonglong)uVar13 +
              CONCAT44(local_bc + (int)((ulonglong)lVar5 >> 0x20),(int)lVar5) +
              (ulonglong)(iVar11 * uVar12) + (uVar6 >> 0x20);
      uVar25 = (uint)lVar5;
      uVar29 = (uint)((ulonglong)lVar5 >> 0x20);
      local_100 = (uint)uVar6;
      lVar5 = (ulonglong)uVar17 * (ulonglong)uVar15 +
              (ulonglong)uVar24 * (ulonglong)uVar18 + (ulonglong)uVar10 * (ulonglong)uVar14 +
              (ulonglong)uVar27 * (ulonglong)uVar21 + (ulonglong)(iVar11 * uVar13);
      uVar17 = (uint)lVar5;
      uVar19 = uVar29 + uVar17;
      uVar29 = iVar11 * uVar15 + (int)((ulonglong)lVar5 >> 0x20) + (uint)CARRY4(uVar29,uVar17);
      local_c8 = (uint)lVar4;
      uVar17 = (uVar29 & 0xfffffffc) + (uVar29 >> 2);
      uVar18 = uVar17 + local_c8;
      uVar27 = local_100 - ((int)((uVar17 ^ uVar18 | uVar17 ^ local_c8) ^ uVar18) >> 0x1f);
      uVar17 = uVar25 - ((int)((uVar27 | local_100) ^ uVar27) >> 0x1f);
      uVar25 = uVar19 - ((int)((uVar25 | uVar17) ^ uVar17) >> 0x1f);
      uVar29 = (uVar29 & 3) - ((int)((uVar19 | uVar25) ^ uVar25) >> 0x1f);
    } while (0xf < uVar30);
    local_30 = (uint *)((int)local_30 + uVar23);
    *param_1 = uVar18;
    param_1[1] = uVar27;
    param_1[2] = uVar17;
    param_1[3] = uVar25;
    param_1[4] = uVar29;
  }
  if ((param_3 & 0xf) != 0) {
    memcpy(param_1 + 0x34,local_30,uVar16);
  }
  param_1[0x38] = uVar16;
  return;
}



int MOD_EXP_CTIME_COPY_FROM_PREBUF(int *param_1,int param_2,uint *param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint *local_40;
  uint *local_3c;
  int local_38;
  
  iVar15 = 1 << (param_5 & 0xff);
  iVar7 = bn_wexpand();
  if (iVar7 != 0) {
    local_40 = param_3;
    if ((int)param_5 < 4) {
      if (0 < param_2) {
        local_3c = (uint *)(*param_1 + -4);
        local_38 = 0;
        do {
          uVar16 = 0;
          if (0 < iVar15) {
            if (iVar15 < 9) {
              uVar22 = 0;
            }
            else {
              uVar22 = 0;
              uVar20 = 1;
              puVar12 = local_40 + 0xe;
              do {
                puVar17 = puVar12 + -0xe;
                uVar10 = uVar22 ^ param_4;
                puVar1 = puVar12 + -0xd;
                uVar8 = uVar20 ^ param_4;
                puVar2 = puVar12 + -0xc;
                uVar11 = uVar22 + 2 ^ param_4;
                puVar13 = puVar12 + -0xb;
                uVar9 = uVar22 + 3 ^ param_4;
                puVar3 = puVar12 + -10;
                uVar14 = uVar22 + 4 ^ param_4;
                puVar4 = puVar12 + -9;
                uVar21 = uVar22 + 5 ^ param_4;
                puVar5 = puVar12 + -8;
                HintPreloadData(puVar12);
                uVar18 = uVar22 + 6 ^ param_4;
                puVar6 = puVar12 + -7;
                uVar19 = uVar22 + 7 ^ param_4;
                uVar20 = uVar20 + 8;
                uVar22 = uVar22 + 8;
                puVar12 = puVar12 + 8;
                uVar16 = uVar16 | *puVar6 & (int)(uVar19 - 1 & ~uVar19) >> 0x1f |
                                  *puVar5 & (int)(uVar18 - 1 & ~uVar18) >> 0x1f |
                                  *puVar4 & (int)(uVar21 - 1 & ~uVar21) >> 0x1f |
                                  *puVar13 & (int)(uVar9 - 1 & ~uVar9) >> 0x1f |
                                  *puVar2 & (int)(uVar11 - 1 & ~uVar11) >> 0x1f |
                                  *puVar1 & (int)(uVar8 - 1 & ~uVar8) >> 0x1f |
                                  *puVar17 & (int)(uVar10 - 1 & ~uVar10) >> 0x1f |
                                  *puVar3 & (int)(uVar14 - 1 & ~uVar14) >> 0x1f;
              } while ((int)uVar20 < iVar15 + -7);
            }
            puVar12 = local_40 + uVar22;
            do {
              uVar20 = uVar22 ^ param_4;
              uVar22 = uVar22 + 1;
              uVar16 = uVar16 | *puVar12 & (int)(uVar20 - 1 & ~uVar20) >> 0x1f;
              puVar12 = puVar12 + 1;
            } while ((int)uVar22 < iVar15);
          }
          local_3c = local_3c + 1;
          *local_3c = uVar16;
          local_38 = local_38 + 1;
          local_40 = local_40 + iVar15;
        } while (param_2 != local_38);
      }
    }
    else {
      uVar16 = (int)param_4 >> (param_5 - 2 & 0xff);
      uVar22 = 1 << (param_5 - 2 & 0xff);
      if (0 < param_2) {
        puVar12 = (uint *)*param_1;
        local_3c = puVar12;
        do {
          uVar20 = 0;
          if (0 < (int)uVar22) {
            uVar8 = 0;
            puVar17 = local_40;
            do {
              uVar9 = *puVar17;
              puVar13 = puVar17 + uVar22 * 3;
              puVar1 = puVar17 + uVar22;
              puVar2 = puVar17 + uVar22 * 2;
              puVar17 = puVar17 + 1;
              uVar10 = uVar8 ^ param_4 & uVar22 - 1;
              uVar8 = uVar8 + 1;
              uVar20 = uVar20 | ((int)((uVar16 ^ 3) - 1 & ~(uVar16 ^ 3)) >> 0x1f & *puVar13 |
                                (int)(uVar16 - 1 & ~uVar16) >> 0x1f & uVar9 |
                                (int)((uVar16 ^ 2) - 1 & ~(uVar16 ^ 2)) >> 0x1f & *puVar2 |
                                (int)((uVar16 ^ 1) - 1 & ~(uVar16 ^ 1)) >> 0x1f & *puVar1) &
                                (int)(uVar10 - 1 & ~uVar10) >> 0x1f;
            } while (uVar22 != uVar8);
          }
          local_40 = local_40 + iVar15;
          puVar17 = local_3c + 1;
          *local_3c = uVar20;
          local_3c = puVar17;
        } while (puVar17 != puVar12 + param_2);
      }
    }
    iVar7 = 1;
    param_1[1] = param_2;
  }
  return iVar7;
}


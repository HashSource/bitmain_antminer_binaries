
int bn_mod_sub_fixed_top(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  int iVar19;
  int *piVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint *puVar25;
  bool bVar26;
  bool bVar27;
  
  uVar24 = param_4[1];
  iVar2 = bn_wexpand(param_1,uVar24);
  if (iVar2 != 0) {
    iVar10 = *param_1;
    iVar2 = *param_2;
    if (*param_2 == 0) {
      iVar2 = iVar10;
    }
    iVar5 = iVar10;
    if (*param_3 != 0) {
      iVar5 = *param_3;
    }
    if (uVar24 != 0) {
      iVar11 = param_2[1];
      uVar22 = 0;
      iVar3 = param_2[2];
      iVar19 = 0;
      iVar6 = param_3[2];
      iVar17 = 0;
      iVar8 = param_3[1];
      iVar4 = -iVar11;
      piVar20 = (int *)(iVar10 + -4);
      do {
        iVar13 = iVar17 * 4;
        iVar7 = (iVar11 - iVar8) + iVar4;
        iVar1 = iVar19 * 4;
        iVar17 = iVar17 - (((iVar11 + 1) - iVar3) + iVar4 >> 0x1f);
        iVar19 = iVar19 - (((iVar11 + 1) - iVar6) + iVar4 >> 0x1f);
        uVar12 = *(uint *)(iVar2 + iVar13) & iVar4 >> 0x1f;
        iVar4 = iVar4 + 1;
        uVar9 = *(uint *)(iVar5 + iVar1) & iVar7 >> 0x1f;
        bVar27 = uVar12 < uVar9;
        bVar26 = uVar12 != uVar9;
        iVar13 = uVar12 - uVar9;
        if (bVar27) {
          uVar9 = 1;
        }
        piVar20 = piVar20 + 1;
        *piVar20 = iVar13 - uVar22;
        if (!bVar27) {
          uVar9 = 0;
        }
        if (bVar26) {
          uVar22 = uVar9;
        }
      } while (iVar4 != uVar24 - iVar11);
      uVar12 = 0;
      uVar9 = -uVar22;
      iVar2 = *param_4;
      if (uVar24 < 9) {
        uVar21 = 0;
      }
      else {
        uVar21 = 0;
        iVar5 = iVar10 + 0x38;
        iVar4 = iVar2 + 0x38;
        do {
          uVar23 = uVar21 + 9;
          uVar21 = uVar21 + 8;
          HintPreloadData(iVar4);
          uVar14 = *(uint *)(iVar4 + -0x38) & uVar9;
          HintPreloadData(iVar5);
          uVar15 = uVar14 + uVar12;
          uVar14 = (uint)CARRY4(uVar14,uVar12);
          uVar12 = *(int *)(iVar5 + -0x38) + uVar15;
          *(uint *)(iVar5 + -0x38) = uVar12;
          if (uVar12 < uVar15) {
            uVar14 = uVar14 + 1;
          }
          uVar12 = *(uint *)(iVar4 + -0x34) & uVar9;
          uVar16 = uVar12 + uVar14;
          uVar15 = *(int *)(iVar5 + -0x34) + uVar16;
          uVar12 = (uint)CARRY4(uVar12,uVar14);
          *(uint *)(iVar5 + -0x34) = uVar15;
          if (uVar15 < uVar16) {
            uVar12 = uVar12 + 1;
          }
          uVar15 = *(uint *)(iVar4 + -0x30) & uVar9;
          uVar16 = uVar15 + uVar12;
          uVar14 = *(int *)(iVar5 + -0x30) + uVar16;
          uVar12 = (uint)CARRY4(uVar15,uVar12);
          *(uint *)(iVar5 + -0x30) = uVar14;
          if (uVar14 < uVar16) {
            uVar12 = uVar12 + 1;
          }
          uVar15 = *(uint *)(iVar4 + -0x2c) & uVar9;
          uVar16 = uVar15 + uVar12;
          uVar14 = *(int *)(iVar5 + -0x2c) + uVar16;
          uVar12 = (uint)CARRY4(uVar15,uVar12);
          *(uint *)(iVar5 + -0x2c) = uVar14;
          if (uVar14 < uVar16) {
            uVar12 = uVar12 + 1;
          }
          uVar15 = *(uint *)(iVar4 + -0x28) & uVar9;
          uVar16 = uVar15 + uVar12;
          uVar14 = *(int *)(iVar5 + -0x28) + uVar16;
          uVar12 = (uint)CARRY4(uVar15,uVar12);
          *(uint *)(iVar5 + -0x28) = uVar14;
          if (uVar14 < uVar16) {
            uVar12 = uVar12 + 1;
          }
          uVar15 = *(uint *)(iVar4 + -0x24) & uVar9;
          uVar16 = uVar15 + uVar12;
          uVar14 = *(int *)(iVar5 + -0x24) + uVar16;
          uVar12 = (uint)CARRY4(uVar15,uVar12);
          *(uint *)(iVar5 + -0x24) = uVar14;
          if (uVar14 < uVar16) {
            uVar12 = uVar12 + 1;
          }
          uVar15 = *(uint *)(iVar4 + -0x20) & uVar9;
          uVar16 = uVar15 + uVar12;
          uVar14 = *(int *)(iVar5 + -0x20) + uVar16;
          uVar12 = (uint)CARRY4(uVar15,uVar12);
          *(uint *)(iVar5 + -0x20) = uVar14;
          if (uVar14 < uVar16) {
            uVar12 = uVar12 + 1;
          }
          uVar15 = uVar9 & *(uint *)(iVar4 + -0x1c);
          uVar16 = uVar15 + uVar12;
          uVar14 = *(int *)(iVar5 + -0x1c) + uVar16;
          uVar12 = (uint)CARRY4(uVar15,uVar12);
          *(uint *)(iVar5 + -0x1c) = uVar14;
          if (uVar14 < uVar16) {
            uVar12 = uVar12 + 1;
          }
          iVar5 = iVar5 + 0x20;
          iVar4 = iVar4 + 0x20;
        } while (uVar23 < uVar24 - 7);
      }
      puVar18 = (uint *)(uVar21 * 4 + iVar10);
      puVar25 = (uint *)(iVar2 + uVar21 * 4);
      do {
        uVar21 = uVar21 + 1;
        uVar14 = (*puVar25 & uVar9) + uVar12;
        uVar12 = (uint)CARRY4(*puVar25 & uVar9,uVar12);
        uVar15 = uVar14 + *puVar18;
        if (uVar15 < uVar14) {
          uVar12 = uVar12 + 1;
        }
        *puVar18 = uVar15;
        puVar18 = puVar18 + 1;
        puVar25 = puVar25 + 1;
      } while (uVar21 < uVar24);
      uVar12 = uVar12 - uVar22;
      uVar22 = 0;
      if (uVar24 < 9) {
        uVar9 = 0;
      }
      else {
        uVar9 = 0;
        iVar5 = iVar10 + 0x38;
        iVar4 = iVar2 + 0x38;
        do {
          uVar23 = uVar9 + 9;
          uVar9 = uVar9 + 8;
          HintPreloadData(iVar4);
          uVar21 = *(uint *)(iVar4 + -0x38) & uVar12;
          HintPreloadData(iVar5);
          uVar14 = uVar21 + uVar22;
          uVar15 = *(int *)(iVar5 + -0x38) + uVar14;
          uVar22 = (uint)CARRY4(uVar21,uVar22);
          *(uint *)(iVar5 + -0x38) = uVar15;
          if (uVar15 < uVar14) {
            uVar22 = uVar22 + 1;
          }
          uVar21 = *(uint *)(iVar4 + -0x34) & uVar12;
          uVar14 = uVar21 + uVar22;
          uVar15 = *(int *)(iVar5 + -0x34) + uVar14;
          uVar22 = (uint)CARRY4(uVar21,uVar22);
          *(uint *)(iVar5 + -0x34) = uVar15;
          if (uVar15 < uVar14) {
            uVar22 = uVar22 + 1;
          }
          uVar14 = *(uint *)(iVar4 + -0x30) & uVar12;
          uVar15 = uVar14 + uVar22;
          uVar21 = *(int *)(iVar5 + -0x30) + uVar15;
          uVar22 = (uint)CARRY4(uVar14,uVar22);
          *(uint *)(iVar5 + -0x30) = uVar21;
          if (uVar21 < uVar15) {
            uVar22 = uVar22 + 1;
          }
          uVar14 = *(uint *)(iVar4 + -0x2c) & uVar12;
          uVar15 = uVar14 + uVar22;
          uVar21 = *(int *)(iVar5 + -0x2c) + uVar15;
          uVar22 = (uint)CARRY4(uVar14,uVar22);
          *(uint *)(iVar5 + -0x2c) = uVar21;
          if (uVar21 < uVar15) {
            uVar22 = uVar22 + 1;
          }
          uVar14 = *(uint *)(iVar4 + -0x28) & uVar12;
          uVar15 = uVar14 + uVar22;
          uVar21 = *(int *)(iVar5 + -0x28) + uVar15;
          uVar22 = (uint)CARRY4(uVar14,uVar22);
          *(uint *)(iVar5 + -0x28) = uVar21;
          if (uVar21 < uVar15) {
            uVar22 = uVar22 + 1;
          }
          uVar14 = *(uint *)(iVar4 + -0x24) & uVar12;
          uVar15 = uVar14 + uVar22;
          uVar21 = *(int *)(iVar5 + -0x24) + uVar15;
          uVar22 = (uint)CARRY4(uVar14,uVar22);
          *(uint *)(iVar5 + -0x24) = uVar21;
          if (uVar21 < uVar15) {
            uVar22 = uVar22 + 1;
          }
          uVar14 = *(uint *)(iVar4 + -0x20) & uVar12;
          uVar15 = uVar14 + uVar22;
          uVar21 = *(int *)(iVar5 + -0x20) + uVar15;
          uVar22 = (uint)CARRY4(uVar14,uVar22);
          *(uint *)(iVar5 + -0x20) = uVar21;
          if (uVar21 < uVar15) {
            uVar22 = uVar22 + 1;
          }
          uVar14 = uVar12 & *(uint *)(iVar4 + -0x1c);
          uVar15 = uVar14 + uVar22;
          uVar21 = *(int *)(iVar5 + -0x1c) + uVar15;
          uVar22 = (uint)CARRY4(uVar14,uVar22);
          *(uint *)(iVar5 + -0x1c) = uVar21;
          if (uVar21 < uVar15) {
            uVar22 = uVar22 + 1;
          }
          iVar5 = iVar5 + 0x20;
          iVar4 = iVar4 + 0x20;
        } while (uVar23 < uVar24 - 7);
      }
      puVar18 = (uint *)(iVar10 + uVar9 * 4);
      puVar25 = (uint *)(iVar2 + uVar9 * 4);
      do {
        uVar9 = uVar9 + 1;
        uVar14 = (*puVar25 & uVar12) + uVar22;
        uVar22 = (uint)CARRY4(*puVar25 & uVar12,uVar22);
        uVar21 = uVar14 + *puVar18;
        if (uVar21 < uVar14) {
          uVar22 = uVar22 + 1;
        }
        *puVar18 = uVar21;
        puVar18 = puVar18 + 1;
        puVar25 = puVar25 + 1;
      } while (uVar9 < uVar24);
    }
    iVar2 = 1;
    param_1[1] = uVar24;
    param_1[3] = 0;
  }
  return iVar2;
}


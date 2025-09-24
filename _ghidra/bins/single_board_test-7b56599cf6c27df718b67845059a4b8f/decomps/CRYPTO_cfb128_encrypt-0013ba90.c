
void CRYPTO_cfb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,uint param_5,
               uint *param_6,int param_7,code *param_8)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  
  uVar11 = *param_6;
  if (param_7 != 0) {
    pbVar17 = param_1;
    pbVar2 = param_2;
    if (uVar11 != 0 && param_3 != 0) {
      do {
        param_1 = pbVar17 + 1;
        uVar9 = uVar11 + 1 & 0xf;
        if (uVar9 != 0) {
          uVar9 = 1;
        }
        param_3 = param_3 - 1;
        uVar9 = uVar9 & 1;
        if (param_3 == 0) {
          uVar9 = 0;
        }
        bVar6 = *(byte *)(param_5 + uVar11) ^ *pbVar17;
        *(byte *)(param_5 + uVar11) = bVar6;
        uVar11 = uVar11 + 1 & 0xf;
        param_2 = pbVar2 + 1;
        *pbVar2 = bVar6;
        pbVar17 = param_1;
        pbVar2 = param_2;
      } while (uVar9 != 0);
    }
    if ((((uint)param_2 | (uint)param_1 | param_5) & 3) != 0) {
      if (param_3 != 0) {
        param_2 = param_2 + -1;
        pbVar17 = param_1;
        do {
          if (uVar11 == 0) {
            (*param_8)(param_5,param_5,param_4);
          }
          pbVar2 = pbVar17 + 1;
          bVar6 = *(byte *)(param_5 + uVar11) ^ *pbVar17;
          *(byte *)(param_5 + uVar11) = bVar6;
          uVar11 = uVar11 + 1 & 0xf;
          param_2 = param_2 + 1;
          *param_2 = bVar6;
          pbVar17 = pbVar2;
        } while (param_1 + param_3 != pbVar2);
      }
      goto LAB_0013bba4;
    }
    pbVar17 = param_1;
    pbVar2 = param_2;
    uVar9 = param_3;
    if (param_3 < 0x10) {
      if (param_3 == 0) goto LAB_0013bba4;
      (*param_8)(param_5,param_5,param_4);
      iVar8 = param_3 - 1;
    }
    else {
      do {
        (*param_8)(param_5,param_5,param_4);
        uVar15 = uVar11 + 4;
        uVar4 = uVar11 + 8;
        uVar7 = uVar11 + 0xc;
        if (uVar11 < 0x10) {
          uVar10 = *(uint *)(param_5 + uVar11) ^ *(uint *)(pbVar17 + uVar11);
          *(uint *)(param_5 + uVar11) = uVar10;
          *(uint *)(pbVar2 + uVar11) = uVar10;
          if (uVar15 < 0x10) {
            uVar11 = *(uint *)(param_5 + uVar15) ^ *(uint *)(pbVar17 + uVar15);
            *(uint *)(param_5 + uVar15) = uVar11;
            *(uint *)(pbVar2 + uVar15) = uVar11;
            if (uVar4 < 0x10) {
              uVar11 = *(uint *)(param_5 + uVar4) ^ *(uint *)(pbVar17 + uVar4);
              *(uint *)(param_5 + uVar4) = uVar11;
              *(uint *)(pbVar2 + uVar4) = uVar11;
              if (uVar7 < 0x10) {
                uVar11 = *(uint *)(param_5 + uVar7) ^ *(uint *)(pbVar17 + uVar7);
                *(uint *)(param_5 + uVar7) = uVar11;
                *(uint *)(pbVar2 + uVar7) = uVar11;
              }
            }
          }
        }
        uVar9 = uVar9 - 0x10;
        uVar11 = 0;
        pbVar17 = pbVar17 + 0x10;
        pbVar2 = pbVar2 + 0x10;
      } while (0xf < uVar9);
      uVar9 = param_3 - 0x10 >> 4;
      uVar11 = param_3 & 0xf;
      iVar8 = (uVar9 + 1) * 0x10;
      param_2 = param_2 + iVar8;
      param_1 = param_1 + iVar8;
      if (uVar11 == 0) goto LAB_0013bba4;
      iVar8 = (param_3 - 0x11) + uVar9 * -0x10;
      (*param_8)(param_5,param_5,param_4);
      uVar11 = 0;
    }
    iVar13 = uVar11 + 4;
    pbVar2 = (byte *)(param_5 + uVar11);
    pbVar17 = param_1 + iVar13;
    pbVar16 = param_1 + uVar11;
    pbVar12 = (byte *)(param_5 + iVar13);
    pbVar5 = param_2 + iVar13;
    bVar21 = pbVar2 <= pbVar17;
    bVar20 = pbVar17 == pbVar2;
    if (bVar21 && !bVar20) {
      bVar21 = pbVar16 <= pbVar12;
      bVar20 = pbVar12 == pbVar16;
    }
    pbVar1 = param_2 + uVar11;
    bVar22 = pbVar1 <= pbVar17;
    bVar18 = pbVar17 == pbVar1;
    if (bVar22 && !bVar18) {
      bVar22 = pbVar16 <= pbVar5;
      bVar18 = pbVar5 == pbVar16;
    }
    bVar23 = pbVar2 <= pbVar5;
    bVar19 = pbVar5 == pbVar2;
    if (bVar23 && !bVar19) {
      bVar23 = pbVar1 <= pbVar12;
      bVar19 = pbVar12 == pbVar1;
    }
    if ((((uint)pbVar1 | (uint)pbVar16 | (uint)pbVar2) & 3) != 0 ||
        (bVar23 && !bVar19 || (iVar8 + 1U < 7 || (bVar21 && !bVar20 || bVar22 && !bVar18)))) {
      iVar14 = uVar11 + 1;
      bVar6 = *(byte *)(param_5 + uVar11) ^ param_1[uVar11];
      *(byte *)(param_5 + uVar11) = bVar6;
      param_2[uVar11] = bVar6;
      if (iVar8 == 0) goto LAB_0013bf58;
      iVar3 = uVar11 + 2;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar8 == 1) goto LAB_0013bf58;
      iVar14 = uVar11 + 3;
      bVar6 = *(byte *)(param_5 + iVar3) ^ param_1[iVar3];
      *(byte *)(param_5 + iVar3) = bVar6;
      param_2[iVar3] = bVar6;
      if (iVar8 == 2) goto LAB_0013bf58;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar8 == 3) goto LAB_0013bf58;
      iVar14 = uVar11 + 5;
      bVar6 = *(byte *)(param_5 + iVar13) ^ param_1[iVar13];
      *(byte *)(param_5 + iVar13) = bVar6;
      param_2[iVar13] = bVar6;
      if (iVar8 == 4) goto LAB_0013bf58;
      iVar13 = uVar11 + 6;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar8 == 5) goto LAB_0013bf58;
      iVar14 = uVar11 + 7;
      bVar6 = *(byte *)(param_5 + iVar13) ^ param_1[iVar13];
      *(byte *)(param_5 + iVar13) = bVar6;
      param_2[iVar13] = bVar6;
      if (iVar8 == 6) goto LAB_0013bf58;
      iVar13 = uVar11 + 8;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar8 == 7) goto LAB_0013bf58;
      iVar14 = uVar11 + 9;
      bVar6 = *(byte *)(param_5 + iVar13) ^ param_1[iVar13];
      *(byte *)(param_5 + iVar13) = bVar6;
      param_2[iVar13] = bVar6;
      if (iVar8 == 8) goto LAB_0013bf58;
      iVar13 = uVar11 + 10;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar8 == 9) goto LAB_0013bf58;
      iVar14 = uVar11 + 0xb;
      bVar6 = *(byte *)(param_5 + iVar13) ^ param_1[iVar13];
      *(byte *)(param_5 + iVar13) = bVar6;
      param_2[iVar13] = bVar6;
      if (iVar8 == 10) goto LAB_0013bf58;
      iVar13 = uVar11 + 0xc;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar8 == 0xb) goto LAB_0013bf58;
      iVar14 = uVar11 + 0xd;
      bVar6 = *(byte *)(param_5 + iVar13) ^ param_1[iVar13];
      *(byte *)(param_5 + iVar13) = bVar6;
      param_2[iVar13] = bVar6;
      if (iVar8 == 0xc) goto LAB_0013bf58;
      iVar13 = uVar11 + 0xe;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar8 == 0xd) goto LAB_0013bf58;
    }
    else {
      iVar14 = (iVar8 - 3U >> 2) + 1;
      uVar9 = *(uint *)(param_5 + uVar11) ^ *(uint *)(param_1 + uVar11);
      *(uint *)(param_5 + uVar11) = uVar9;
      *(uint *)(param_2 + uVar11) = uVar9;
      if (iVar14 != 1) {
        bVar20 = iVar14 == 3;
        uVar9 = *(uint *)(pbVar16 + 4) ^ *(uint *)(pbVar2 + 4);
        *(uint *)(pbVar2 + 4) = uVar9;
        *(uint *)(pbVar1 + 4) = uVar9;
        if (bVar20) {
          uVar9 = *(uint *)(pbVar2 + 8) ^ *(uint *)(pbVar16 + 8);
        }
        if (bVar20) {
          *(uint *)(pbVar2 + 8) = uVar9;
        }
        if (bVar20) {
          *(uint *)(pbVar1 + 8) = uVar9;
        }
      }
      iVar13 = uVar11 + iVar14 * 4;
      iVar3 = iVar8 + iVar14 * -4;
      if (iVar14 * 4 == iVar8 + 1U) goto LAB_0013bf58;
      iVar14 = iVar13 + 1;
      bVar6 = *(byte *)(param_5 + iVar13) ^ param_1[iVar13];
      *(byte *)(param_5 + iVar13) = bVar6;
      param_2[iVar13] = bVar6;
      if (iVar3 == 0) goto LAB_0013bf58;
      iVar13 = iVar13 + 2;
      bVar6 = *(byte *)(param_5 + iVar14) ^ param_1[iVar14];
      *(byte *)(param_5 + iVar14) = bVar6;
      param_2[iVar14] = bVar6;
      if (iVar3 == 1) goto LAB_0013bf58;
    }
    bVar6 = *(byte *)(param_5 + iVar13) ^ param_1[iVar13];
    *(byte *)(param_5 + iVar13) = bVar6;
    param_2[iVar13] = bVar6;
    goto LAB_0013bf58;
  }
  pbVar17 = param_1;
  pbVar2 = param_2;
  if (param_3 != 0 && uVar11 != 0) {
    do {
      param_1 = pbVar17 + 1;
      bVar6 = *pbVar17;
      uVar9 = uVar11 + 1 & 0xf;
      if (uVar9 != 0) {
        uVar9 = 1;
      }
      param_3 = param_3 - 1;
      uVar9 = uVar9 & 1;
      if (param_3 == 0) {
        uVar9 = 0;
      }
      param_2 = pbVar2 + 1;
      *pbVar2 = *(byte *)(param_5 + uVar11) ^ bVar6;
      *(byte *)(param_5 + uVar11) = bVar6;
      uVar11 = uVar11 + 1 & 0xf;
      pbVar17 = param_1;
      pbVar2 = param_2;
    } while (uVar9 != 0);
  }
  if ((((uint)param_2 | (uint)param_1 | param_5) & 3) != 0) {
    if (param_3 != 0) {
      param_2 = param_2 + -1;
      pbVar17 = param_1;
      do {
        if (uVar11 == 0) {
          (*param_8)(param_5,param_5,param_4);
        }
        pbVar2 = pbVar17 + 1;
        bVar6 = *pbVar17;
        param_2 = param_2 + 1;
        *param_2 = *(byte *)(param_5 + uVar11) ^ bVar6;
        *(byte *)(param_5 + uVar11) = bVar6;
        uVar11 = uVar11 + 1 & 0xf;
        pbVar17 = pbVar2;
      } while (pbVar2 != param_1 + param_3);
    }
LAB_0013bba4:
    *param_6 = uVar11;
    return;
  }
  uVar9 = param_3;
  pbVar17 = param_1;
  pbVar2 = param_2;
  if (param_3 < 0x10) {
    if (param_3 == 0) goto LAB_0013bba4;
    (*param_8)(param_5,param_5,param_4);
    iVar8 = param_3 - 1;
  }
  else {
    do {
      (*param_8)(param_5,param_5,param_4);
      uVar15 = uVar11 + 4;
      uVar4 = uVar11 + 8;
      uVar7 = uVar11 + 0xc;
      if (uVar11 < 0x10) {
        uVar10 = *(uint *)(pbVar17 + uVar11);
        *(uint *)(pbVar2 + uVar11) = *(uint *)(param_5 + uVar11) ^ uVar10;
        *(uint *)(param_5 + uVar11) = uVar10;
        if (uVar15 < 0x10) {
          uVar11 = *(uint *)(pbVar17 + uVar15);
          *(uint *)(pbVar2 + uVar15) = *(uint *)(param_5 + uVar15) ^ uVar11;
          *(uint *)(param_5 + uVar15) = uVar11;
          if (uVar4 < 0x10) {
            uVar11 = *(uint *)(pbVar17 + uVar4);
            *(uint *)(pbVar2 + uVar4) = *(uint *)(param_5 + uVar4) ^ uVar11;
            *(uint *)(param_5 + uVar4) = uVar11;
            if (uVar7 < 0x10) {
              uVar11 = *(uint *)(pbVar17 + uVar7);
              *(uint *)(pbVar2 + uVar7) = *(uint *)(param_5 + uVar7) ^ uVar11;
              *(uint *)(param_5 + uVar7) = uVar11;
            }
          }
        }
      }
      uVar9 = uVar9 - 0x10;
      uVar11 = 0;
      pbVar17 = pbVar17 + 0x10;
      pbVar2 = pbVar2 + 0x10;
    } while (0xf < uVar9);
    uVar9 = param_3 - 0x10 >> 4;
    uVar11 = param_3 & 0xf;
    iVar8 = (uVar9 + 1) * 0x10;
    param_2 = param_2 + iVar8;
    param_1 = param_1 + iVar8;
    if (uVar11 == 0) goto LAB_0013bba4;
    iVar8 = uVar9 * -0x10 + (param_3 - 0x11);
    (*param_8)(param_5,param_5,param_4);
    uVar11 = 0;
  }
  iVar13 = uVar11 + 4;
  pbVar17 = param_1 + uVar11;
  pbVar2 = param_2 + uVar11;
  pbVar5 = (byte *)(param_5 + uVar11);
  if ((((uint)pbVar2 | (uint)pbVar5 | (uint)pbVar17) & 3) == 0 &&
      (((byte *)(param_5 + iVar13) <= pbVar2 || param_2 + iVar13 <= pbVar5) &&
      (6 < iVar8 + 1U &&
      ((param_2 + iVar13 <= pbVar17 || param_1 + iVar13 <= pbVar2) &&
      ((byte *)(param_5 + iVar13) <= pbVar17 || param_1 + iVar13 <= pbVar5))))) {
    uVar9 = *(uint *)(param_1 + uVar11);
    iVar14 = (iVar8 - 3U >> 2) + 1;
    *(uint *)(param_2 + uVar11) = uVar9 ^ *(uint *)(param_5 + uVar11);
    *(uint *)(param_5 + uVar11) = uVar9;
    if (iVar14 != 1) {
      uVar4 = *(uint *)(pbVar17 + 4);
      bVar20 = iVar14 == 3;
      uVar9 = uVar4 ^ *(uint *)(pbVar5 + 4);
      *(uint *)(pbVar2 + 4) = uVar9;
      *(uint *)(pbVar5 + 4) = uVar4;
      if (bVar20) {
        pbVar17 = *(byte **)(pbVar17 + 8);
        uVar9 = (uint)pbVar17 ^ *(uint *)(pbVar5 + 8);
      }
      if (bVar20) {
        *(uint *)(pbVar2 + 8) = uVar9;
      }
      if (bVar20) {
        *(byte **)(pbVar5 + 8) = pbVar17;
      }
    }
    iVar13 = uVar11 + iVar14 * 4;
    iVar3 = iVar8 + iVar14 * -4;
    if (iVar8 + 1U == iVar14 * 4) goto LAB_0013bf58;
    bVar6 = param_1[iVar13];
    iVar14 = iVar13 + 1;
    param_2[iVar13] = *(byte *)(param_5 + iVar13) ^ bVar6;
    *(byte *)(param_5 + iVar13) = bVar6;
    if (iVar3 == 0) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    iVar13 = iVar13 + 2;
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar3 == 1) goto LAB_0013bf58;
  }
  else {
    bVar6 = param_1[uVar11];
    iVar14 = uVar11 + 1;
    param_2[uVar11] = *(byte *)(param_5 + uVar11) ^ bVar6;
    *(byte *)(param_5 + uVar11) = bVar6;
    if (iVar8 == 0) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    iVar3 = uVar11 + 2;
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar8 == 1) goto LAB_0013bf58;
    bVar6 = param_1[iVar3];
    iVar14 = uVar11 + 3;
    param_2[iVar3] = *(byte *)(param_5 + iVar3) ^ bVar6;
    *(byte *)(param_5 + iVar3) = bVar6;
    if (iVar8 == 2) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar8 == 3) goto LAB_0013bf58;
    bVar6 = param_1[iVar13];
    iVar14 = uVar11 + 5;
    param_2[iVar13] = *(byte *)(param_5 + iVar13) ^ bVar6;
    *(byte *)(param_5 + iVar13) = bVar6;
    if (iVar8 == 4) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    iVar13 = uVar11 + 6;
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar8 == 5) goto LAB_0013bf58;
    bVar6 = param_1[iVar13];
    iVar14 = uVar11 + 7;
    param_2[iVar13] = *(byte *)(param_5 + iVar13) ^ bVar6;
    *(byte *)(param_5 + iVar13) = bVar6;
    if (iVar8 == 6) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    iVar13 = uVar11 + 8;
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar8 == 7) goto LAB_0013bf58;
    bVar6 = param_1[iVar13];
    iVar14 = uVar11 + 9;
    param_2[iVar13] = *(byte *)(param_5 + iVar13) ^ bVar6;
    *(byte *)(param_5 + iVar13) = bVar6;
    if (iVar8 == 8) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    iVar13 = uVar11 + 10;
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar8 == 9) goto LAB_0013bf58;
    bVar6 = param_1[iVar13];
    iVar14 = uVar11 + 0xb;
    param_2[iVar13] = *(byte *)(param_5 + iVar13) ^ bVar6;
    *(byte *)(param_5 + iVar13) = bVar6;
    if (iVar8 == 10) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    iVar13 = uVar11 + 0xc;
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar8 == 0xb) goto LAB_0013bf58;
    bVar6 = param_1[iVar13];
    iVar14 = uVar11 + 0xd;
    param_2[iVar13] = *(byte *)(param_5 + iVar13) ^ bVar6;
    *(byte *)(param_5 + iVar13) = bVar6;
    if (iVar8 == 0xc) goto LAB_0013bf58;
    bVar6 = param_1[iVar14];
    iVar13 = uVar11 + 0xe;
    param_2[iVar14] = *(byte *)(param_5 + iVar14) ^ bVar6;
    *(byte *)(param_5 + iVar14) = bVar6;
    if (iVar8 == 0xd) goto LAB_0013bf58;
  }
  bVar6 = param_1[iVar13];
  param_2[iVar13] = *(byte *)(param_5 + iVar13) ^ bVar6;
  *(byte *)(param_5 + iVar13) = bVar6;
LAB_0013bf58:
  *param_6 = uVar11 + iVar8 + 1;
  return;
}


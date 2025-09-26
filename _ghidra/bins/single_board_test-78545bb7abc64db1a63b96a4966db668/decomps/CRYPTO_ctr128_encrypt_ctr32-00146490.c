
void CRYPTO_ctr128_encrypt_ctr32
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,char *param_5,
               undefined4 *param_6,uint *param_7,code *param_8)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  uVar15 = *param_7;
  pbVar13 = param_1;
  pbVar14 = param_2;
  if (uVar15 != 0 && param_3 != 0) {
    do {
      pbVar2 = (byte *)((int)param_6 + uVar15);
      uVar7 = uVar15 + 1 & 0xf;
      param_1 = pbVar13 + 1;
      if (uVar7 != 0) {
        uVar7 = 1;
      }
      param_3 = param_3 - 1;
      uVar7 = uVar7 & 1;
      if (param_3 == 0) {
        uVar7 = 0;
      }
      uVar15 = uVar15 + 1 & 0xf;
      param_2 = pbVar14 + 1;
      *pbVar14 = *pbVar13 ^ *pbVar2;
      pbVar13 = param_1;
      pbVar14 = param_2;
    } while (uVar7 != 0);
  }
  uVar7 = (uint)(byte)param_5[0xd] << 0x10 | (uint)(byte)param_5[0xc] << 0x18 |
          (uint)(byte)param_5[0xf] | (uint)(byte)param_5[0xe] << 8;
  for (; 0xf < param_3; param_3 = param_3 + uVar11 * -0x10) {
    uVar11 = param_3 >> 4;
    uVar16 = uVar11 + uVar7;
    if (CARRY4(uVar11,uVar7)) {
      uVar11 = -uVar7;
      (*param_8)(param_1,param_2,uVar11,param_4,param_5);
      uVar16 = 0;
      param_5[0xc] = '\0';
      uVar7 = (uint)(byte)param_5[10] + ((byte)param_5[0xb] + 1 >> 8);
      uVar3 = (uint)(byte)param_5[9] + (uVar7 >> 8);
      param_5[0xb] = (char)((byte)param_5[0xb] + 1);
      uVar4 = (uint)(byte)param_5[8] + (uVar3 >> 8);
      param_5[10] = (char)uVar7;
      uVar7 = (uint)(byte)param_5[7] + (uVar4 >> 8);
      param_5[9] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[6] + (uVar7 >> 8);
      param_5[8] = (char)uVar4;
      uVar17 = (uint)(byte)param_5[5] + (uVar3 >> 8);
      param_5[7] = (char)uVar7;
      uVar7 = (uint)(byte)param_5[4] + (uVar17 >> 8);
      param_5[6] = (char)uVar3;
      uVar3 = (uint)(byte)param_5[3] + (uVar7 >> 8);
      param_5[0xd] = '\0';
      param_5[0xe] = '\0';
      uVar4 = (uint)(byte)param_5[2] + (uVar3 >> 8);
      param_5[0xf] = '\0';
      param_5[5] = (char)uVar17;
      iVar8 = (uint)(byte)param_5[1] + (uVar4 >> 8);
      param_5[4] = (char)uVar7;
      param_5[3] = (char)uVar3;
      param_5[2] = (char)uVar4;
      param_5[1] = (char)iVar8;
      *param_5 = *param_5 + (char)((uint)iVar8 >> 8);
    }
    else {
      (*param_8)(param_1,param_2,uVar11,param_4,param_5);
      param_5[0xf] = (char)uVar16;
      param_5[0xc] = (char)(uVar16 >> 0x18);
      param_5[0xd] = (char)(uVar16 >> 0x10);
      param_5[0xe] = (char)(uVar16 >> 8);
    }
    param_2 = param_2 + uVar11 * 0x10;
    param_1 = param_1 + uVar11 * 0x10;
    uVar7 = uVar16;
  }
  if (param_3 == 0) {
    *param_7 = uVar15;
    return;
  }
  *param_6 = 0;
  param_6[1] = 0;
  param_6[2] = 0;
  param_6[3] = 0;
  (*param_8)(param_6,param_6,1,param_4,param_5);
  iVar8 = uVar7 + 1;
  param_5[0xf] = (char)iVar8;
  param_5[0xc] = (char)((uint)iVar8 >> 0x18);
  param_5[0xd] = (char)((uint)iVar8 >> 0x10);
  param_5[0xe] = (char)((uint)iVar8 >> 8);
  if (iVar8 == 0) {
    bVar1 = param_5[0xb];
    param_5[0xb] = (char)(bVar1 + 1);
    uVar7 = (uint)(byte)param_5[10] + (bVar1 + 1 >> 8);
    uVar11 = (uint)(byte)param_5[9] + (uVar7 >> 8);
    param_5[10] = (char)uVar7;
    uVar7 = (uint)(byte)param_5[8] + (uVar11 >> 8);
    param_5[9] = (char)uVar11;
    uVar11 = (uint)(byte)param_5[7] + (uVar7 >> 8);
    param_5[8] = (char)uVar7;
    uVar7 = (uint)(byte)param_5[6] + (uVar11 >> 8);
    param_5[7] = (char)uVar11;
    uVar11 = (uint)(byte)param_5[5] + (uVar7 >> 8);
    param_5[6] = (char)uVar7;
    uVar7 = (uint)(byte)param_5[4] + (uVar11 >> 8);
    param_5[5] = (char)uVar11;
    uVar11 = (uint)(byte)param_5[3] + (uVar7 >> 8);
    param_5[4] = (char)uVar7;
    uVar7 = (uint)(byte)param_5[2] + (uVar11 >> 8);
    param_5[3] = (char)uVar11;
    iVar8 = (uint)(byte)param_5[1] + (uVar7 >> 8);
    param_5[2] = (char)uVar7;
    param_5[1] = (char)iVar8;
    *param_5 = *param_5 + (char)((uint)iVar8 >> 8);
  }
  iVar8 = uVar15 + 4;
  puVar12 = (uint *)(param_1 + uVar15);
  puVar10 = (uint *)((int)param_6 + uVar15);
  puVar5 = (uint *)(param_2 + uVar15);
  uVar7 = param_3 - 1;
  if ((((uint)puVar5 | (uint)puVar12 | (uint)puVar10) & 3) == 0 &&
      (6 < param_3 &&
      (((uint *)((int)param_6 + iVar8) <= puVar5 || param_2 + iVar8 <= puVar10) &&
      (param_1 + iVar8 <= puVar5 || param_2 + iVar8 <= puVar12)))) {
    iVar8 = (param_3 - 4 >> 2) + 1;
    uVar11 = uVar15;
    if (2 < uVar7) {
      *puVar5 = *puVar12 ^ *puVar10;
      if ((iVar8 != 1) && (puVar5[1] = puVar12[1] ^ puVar10[1], iVar8 == 3)) {
        puVar5[2] = puVar12[2] ^ puVar10[2];
      }
      uVar7 = uVar7 + iVar8 * -4;
      uVar11 = iVar8 * 4 + uVar15;
      if (param_3 == iVar8 * 4) goto LAB_00146708;
    }
    iVar8 = uVar11 + 1;
    param_2[uVar11] = *(byte *)((int)param_6 + uVar11) ^ param_1[uVar11];
    if (uVar7 != 0) {
      iVar9 = uVar11 + 2;
      param_2[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
      if (uVar7 != 1) {
        param_2[iVar9] = param_1[iVar9] ^ *(byte *)((int)param_6 + iVar9);
      }
    }
  }
  else {
    iVar9 = uVar15 + 1;
    param_2[uVar15] = *(byte *)((int)param_6 + uVar15) ^ param_1[uVar15];
    if (uVar7 != 0) {
      iVar6 = uVar15 + 2;
      param_2[iVar9] = param_1[iVar9] ^ *(byte *)((int)param_6 + iVar9);
      if (param_3 != 2) {
        iVar9 = uVar15 + 3;
        param_2[iVar6] = *(byte *)((int)param_6 + iVar6) ^ param_1[iVar6];
        if ((param_3 != 3) &&
           (param_2[iVar9] = *(byte *)((int)param_6 + iVar9) ^ param_1[iVar9], param_3 != 4)) {
          iVar9 = uVar15 + 5;
          param_2[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
          if (param_3 != 5) {
            iVar8 = uVar15 + 6;
            param_2[iVar9] = *(byte *)((int)param_6 + iVar9) ^ param_1[iVar9];
            if (param_3 != 6) {
              iVar9 = uVar15 + 7;
              param_2[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
              if (param_3 != 7) {
                iVar8 = uVar15 + 8;
                param_2[iVar9] = *(byte *)((int)param_6 + iVar9) ^ param_1[iVar9];
                if (param_3 != 8) {
                  iVar9 = uVar15 + 9;
                  param_2[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
                  if (param_3 != 9) {
                    iVar8 = uVar15 + 10;
                    param_2[iVar9] = *(byte *)((int)param_6 + iVar9) ^ param_1[iVar9];
                    if (param_3 != 10) {
                      iVar9 = uVar15 + 0xb;
                      param_2[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
                      if (param_3 != 0xb) {
                        iVar8 = uVar15 + 0xc;
                        param_2[iVar9] = *(byte *)((int)param_6 + iVar9) ^ param_1[iVar9];
                        if (param_3 != 0xc) {
                          iVar9 = uVar15 + 0xd;
                          param_2[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
                          if (param_3 != 0xd) {
                            iVar8 = uVar15 + 0xe;
                            param_2[iVar9] = *(byte *)((int)param_6 + iVar9) ^ param_1[iVar9];
                            if (param_3 != 0xe) {
                              param_2[iVar8] = *(byte *)((int)param_6 + iVar8) ^ param_1[iVar8];
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00146708:
  *param_7 = uVar15 + param_3;
  return;
}


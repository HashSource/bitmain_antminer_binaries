
undefined4
CRYPTO_ccm128_encrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  byte *pbVar4;
  uint *puVar5;
  uint *puVar6;
  code *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint *puVar14;
  byte *pbVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint *puVar19;
  uint *puVar20;
  bool bVar21;
  bool bVar22;
  uint *local_6c;
  uint *local_5c;
  uint local_38 [5];
  
  bVar1 = *param_1;
  pcVar7 = *(code **)(param_1 + 0x28);
  uVar9 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar1 & 0x40) == 0) {
    (*pcVar7)(param_1,param_1 + 0x10);
    uVar12 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar12 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar12);
  }
  uVar10 = 0;
  *param_1 = (byte)(bVar1 & 7);
  uVar18 = 0xf - (bVar1 & 7);
  uVar12 = uVar18;
  if ((bVar1 & 7) != 0) {
    do {
      bVar2 = param_1[uVar12];
      param_1[uVar12] = 0;
      uVar12 = uVar12 + 1;
      uVar10 = (uVar10 | bVar2) << 8;
    } while (uVar12 != 0xf);
  }
  bVar2 = param_1[0xf];
  param_1[0xf] = 1;
  if ((uVar10 | bVar2) != param_4) {
    return 0xffffffff;
  }
  uVar12 = param_4 + 0xf >> 3 | 1;
  iVar11 = *(uint *)(param_1 + 0x20) + uVar12;
  uVar12 = *(int *)(param_1 + 0x24) + (uint)CARRY4(*(uint *)(param_1 + 0x20),uVar12);
  bVar21 = 0x1fffffff < uVar12;
  if (uVar12 == 0x20000000) {
    bVar21 = iVar11 != 0;
  }
  *(int *)(param_1 + 0x20) = iVar11;
  *(uint *)(param_1 + 0x24) = uVar12;
  if (bVar21) {
    return 0xfffffffe;
  }
  uVar12 = param_4 >> 4;
  if (uVar12 == 0) {
    local_5c = param_3;
    if (param_4 != 0) {
LAB_00186392:
      puVar14 = (uint *)(param_1 + 0x10);
      uVar12 = param_4;
      if (param_4 == 0) {
        uVar12 = 1;
      }
      uVar10 = uVar12 >> 2;
      iVar11 = 1 - uVar10;
      puVar19 = param_2 + 1;
      if (1 < uVar10) {
        iVar11 = 0;
      }
      bVar22 = param_2 <= param_1 + 0x14;
      bVar21 = (uint *)(param_1 + 0x14) == param_2;
      if (bVar22 && !bVar21) {
        bVar22 = puVar14 <= puVar19;
        bVar21 = puVar19 == puVar14;
      }
      uVar17 = uVar10 << 2;
      if (iVar11 != 0 || ((((uint)param_2 & 3) != 0 || bVar22 && !bVar21) || param_4 < 4)) {
        uVar8 = 0;
LAB_001864e4:
        do {
          uVar16 = uVar8 + 1;
          param_1[uVar8 + 0x10] = param_1[uVar8 + 0x10] ^ *(byte *)((int)param_2 + uVar8);
          uVar8 = uVar16;
        } while (uVar16 < param_4);
      }
      else {
        if (uVar10 < 9) {
          uVar8 = 0;
          puVar6 = puVar14;
          puVar20 = param_2;
        }
        else {
          uVar8 = 0;
          puVar5 = (uint *)(param_1 + 0x30);
          puVar3 = param_2;
          do {
            puVar6 = puVar5;
            puVar20 = puVar3 + 8;
            uVar16 = uVar8 + 9;
            uVar8 = uVar8 + 8;
            HintPreloadData(puVar6 + 0xc);
            puVar6[-8] = *puVar3 ^ puVar6[-8];
            puVar6[-7] = puVar3[1] ^ puVar6[-7];
            puVar6[-6] = puVar3[2] ^ puVar6[-6];
            puVar6[-5] = puVar3[3] ^ puVar6[-5];
            puVar6[-4] = puVar3[4] ^ puVar6[-4];
            puVar6[-3] = puVar3[5] ^ puVar6[-3];
            puVar6[-2] = puVar3[6] ^ puVar6[-2];
            puVar6[-1] = puVar3[7] ^ puVar6[-1];
            puVar5 = puVar6 + 8;
            puVar3 = puVar20;
          } while (uVar16 < uVar10 - 7);
        }
        iVar13 = 0;
        do {
          uVar8 = uVar8 + 1;
          *(uint *)((int)puVar6 + iVar13) =
               *(uint *)((int)puVar20 + iVar13) ^ *(uint *)((int)puVar6 + iVar13);
          iVar13 = iVar13 + 4;
        } while (uVar8 < uVar10);
        uVar8 = uVar17;
        if (uVar12 != uVar17) goto LAB_001864e4;
      }
      (*pcVar7)(puVar14,puVar14,uVar9);
      (*pcVar7)(param_1,local_38,uVar9);
      puVar14 = local_5c + 1;
      bVar22 = local_5c <= local_38 + 1;
      bVar21 = local_38 + 1 == local_5c;
      if (bVar22 && !bVar21) {
        bVar22 = local_38 <= puVar14;
        bVar21 = puVar14 == local_38;
      }
      if (iVar11 != 0 ||
          ((((uint)local_5c | (uint)param_2) & 3) != 0 ||
          ((bVar22 && !bVar21 || local_5c < puVar19 && param_2 < puVar14) || param_4 < 4))) {
        uVar17 = 0;
      }
      else {
        if (uVar10 < 9) {
          uVar8 = 0;
          puVar14 = local_5c;
          puVar19 = local_38;
          puVar6 = param_2;
        }
        else {
          uVar8 = 0;
          puVar5 = (uint *)&stack0xffffffe8;
          puVar20 = param_2;
          puVar3 = local_5c;
          do {
            puVar19 = puVar5;
            puVar14 = puVar3 + 8;
            puVar6 = puVar20 + 8;
            uVar16 = uVar8 + 9;
            uVar8 = uVar8 + 8;
            HintPreloadData(puVar19 + 0xc);
            *puVar3 = *puVar20 ^ puVar19[-8];
            puVar3[1] = puVar20[1] ^ puVar19[-7];
            puVar3[2] = puVar20[2] ^ puVar19[-6];
            puVar3[3] = puVar20[3] ^ puVar19[-5];
            puVar3[4] = puVar20[4] ^ puVar19[-4];
            puVar3[5] = puVar19[-3] ^ puVar20[5];
            puVar3[6] = puVar20[6] ^ puVar19[-2];
            puVar3[7] = puVar20[7] ^ puVar19[-1];
            puVar5 = puVar19 + 8;
            puVar20 = puVar6;
            puVar3 = puVar14;
          } while (uVar16 < uVar10 - 7);
        }
        iVar11 = 0;
        do {
          uVar8 = uVar8 + 1;
          *(uint *)((int)puVar14 + iVar11) =
               *(uint *)((int)puVar6 + iVar11) ^ *(uint *)((int)puVar19 + iVar11);
          iVar11 = iVar11 + 4;
        } while (uVar8 < uVar10);
        if (uVar12 == uVar17) goto LAB_00186672;
      }
      do {
        *(byte *)((int)local_5c + uVar17) =
             *(byte *)((int)local_38 + uVar17) ^ *(byte *)((int)param_2 + uVar17);
        uVar17 = uVar17 + 1;
      } while (uVar17 < param_4);
    }
  }
  else {
    uVar10 = uVar12 * 0x10;
    (*param_5)(param_2,param_3,uVar12,uVar9,param_1,param_1 + 0x10);
    param_4 = param_4 + uVar12 * -0x10;
    if (param_4 != 0) {
      uVar17 = (uVar12 & 0xff) + (uint)param_1[0xf];
      uVar8 = uVar17 >> 8;
      param_1[0xf] = (byte)uVar17;
      if (uVar8 != 0 || uVar10 >> 0xc != 0) {
        uVar8 = (uint)param_1[0xe] + (uVar10 >> 0xc & 0xff) + uVar8;
        uVar17 = uVar8 >> 8;
        param_1[0xe] = (byte)uVar8;
        if (uVar17 != 0 || uVar10 >> 0x14 != 0) {
          uVar17 = (uint)param_1[0xd] + (uVar10 >> 0x14 & 0xff) + uVar17;
          uVar8 = uVar17 >> 8;
          param_1[0xd] = (byte)uVar17;
          if (uVar8 != 0 || uVar10 >> 0x1c != 0) {
            uVar8 = (uVar10 >> 0x1c) + (uint)param_1[0xc] + uVar8;
            param_1[0xc] = (byte)uVar8;
            uVar8 = uVar8 >> 8;
            if (uVar8 != 0) {
              uVar8 = uVar8 + param_1[0xb];
              param_1[0xb] = (byte)uVar8;
              uVar8 = uVar8 >> 8;
              if (uVar8 != 0) {
                uVar8 = uVar8 + param_1[10];
                param_1[10] = (byte)uVar8;
                uVar8 = uVar8 >> 8;
                if (uVar8 != 0) {
                  uVar8 = uVar8 + param_1[9];
                  param_1[9] = (byte)uVar8;
                  if (uVar8 >> 8 != 0) {
                    param_1[8] = param_1[8] + (char)(uVar8 >> 8);
                  }
                }
              }
            }
          }
        }
      }
      param_2 = param_2 + uVar12 * 4;
      local_5c = param_3 + uVar12 * 4;
      goto LAB_00186392;
    }
  }
LAB_00186672:
  local_6c = local_38;
  uVar10 = ~uVar18 + 0x11;
  uVar12 = -(int)(param_1 + uVar18) & 3U;
  if (uVar10 <= (-(int)(param_1 + uVar18) & 3U)) {
    uVar12 = uVar10;
  }
  if (uVar10 < 4) {
    uVar12 = uVar10;
  }
  uVar17 = uVar18;
  if (uVar12 != 0) {
    do {
      param_1[uVar17] = 0;
      uVar17 = uVar17 + 1;
    } while (uVar17 - uVar18 < uVar12);
    if (uVar10 == uVar12) goto LAB_00186720;
  }
  uVar8 = uVar10 - uVar12 >> 2;
  if (uVar8 != 0) {
    pbVar15 = param_1 + uVar12 + uVar18;
    if (uVar8 < 9) {
      uVar18 = 0;
    }
    else {
      uVar18 = 0;
      pbVar4 = pbVar15;
      do {
        pbVar15 = pbVar4 + 0x20;
        uVar16 = uVar18 + 9;
        uVar18 = uVar18 + 8;
        HintPreloadData(pbVar4 + 0xa0);
        pbVar4[0] = 0;
        pbVar4[1] = 0;
        pbVar4[2] = 0;
        pbVar4[3] = 0;
        pbVar4[4] = 0;
        pbVar4[5] = 0;
        pbVar4[6] = 0;
        pbVar4[7] = 0;
        pbVar4[8] = 0;
        pbVar4[9] = 0;
        pbVar4[10] = 0;
        pbVar4[0xb] = 0;
        pbVar4[0xc] = 0;
        pbVar4[0xd] = 0;
        pbVar4[0xe] = 0;
        pbVar4[0xf] = 0;
        pbVar4[0x10] = 0;
        pbVar4[0x11] = 0;
        pbVar4[0x12] = 0;
        pbVar4[0x13] = 0;
        pbVar4[0x14] = 0;
        pbVar4[0x15] = 0;
        pbVar4[0x16] = 0;
        pbVar4[0x17] = 0;
        pbVar4[0x18] = 0;
        pbVar4[0x19] = 0;
        pbVar4[0x1a] = 0;
        pbVar4[0x1b] = 0;
        pbVar4[0x1c] = 0;
        pbVar4[0x1d] = 0;
        pbVar4[0x1e] = 0;
        pbVar4[0x1f] = 0;
        pbVar4 = pbVar15;
      } while (uVar16 < uVar8 - 7);
    }
    do {
      uVar18 = uVar18 + 1;
      pbVar15[0] = 0;
      pbVar15[1] = 0;
      pbVar15[2] = 0;
      pbVar15[3] = 0;
      pbVar15 = pbVar15 + 4;
    } while (uVar18 < uVar8);
    uVar17 = uVar17 + uVar8 * 4;
    if (uVar10 - uVar12 == uVar8 * 4) goto LAB_00186720;
  }
  do {
    param_1[uVar17] = 0;
    uVar17 = uVar17 + 1;
  } while (uVar17 != 0x10);
LAB_00186720:
  (*pcVar7)(param_1,local_6c,uVar9);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_38[0] ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_38[1] ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38[2];
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_38[3];
  return 0;
}


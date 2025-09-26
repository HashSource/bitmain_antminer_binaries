
undefined4
CRYPTO_ccm128_decrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  code *pcVar16;
  undefined4 uVar17;
  uint uVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  byte *pbVar23;
  uint *puVar24;
  uint *puVar25;
  bool bVar26;
  bool bVar27;
  uint *local_68;
  uint *local_60;
  uint *local_58;
  uint local_50;
  uint local_38 [5];
  
  bVar1 = *param_1;
  pcVar16 = *(code **)(param_1 + 0x28);
  uVar17 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar1 & 0x40) == 0) {
    (*pcVar16)(param_1,param_1 + 0x10,uVar17);
  }
  uVar10 = 0;
  *param_1 = (byte)(bVar1 & 7);
  uVar22 = 0xf - (bVar1 & 7);
  uVar11 = uVar22;
  if ((bVar1 & 7) != 0) {
    do {
      bVar2 = param_1[uVar11];
      param_1[uVar11] = 0;
      uVar11 = uVar11 + 1;
      uVar10 = (uVar10 | bVar2) << 8;
    } while (uVar11 != 0xf);
  }
  bVar2 = param_1[0xf];
  param_1[0xf] = 1;
  if ((uVar10 | bVar2) != param_4) {
    return 0xffffffff;
  }
  uVar11 = param_4 >> 4;
  if (uVar11 == 0) {
    local_60 = param_2;
    local_50 = param_4;
    if (param_4 != 0) {
LAB_00186a48:
      local_58 = (uint *)(param_1 + 0x10);
      (*pcVar16)(param_1,local_38,uVar17);
      puVar8 = param_3 + 1;
      bVar27 = param_3 <= local_38 + 1;
      bVar26 = local_38 + 1 == param_3;
      if (bVar27 && !bVar26) {
        bVar27 = local_38 <= puVar8;
        bVar26 = puVar8 == local_38;
      }
      uVar11 = local_50;
      if (local_50 == 0) {
        uVar11 = 1;
      }
      uVar12 = uVar11 >> 2;
      uVar10 = uVar12 << 2;
      if (uVar12 == 0 ||
          ((((uint)param_3 | (uint)local_60) & 3) != 0 ||
          ((param_3 < local_60 + 1 && local_60 < puVar8 ||
           (local_50 < 4 || (local_58 < puVar8 && param_3 < param_1 + 0x14 || bVar27 && !bVar26)))
          || local_60 < param_1 + 0x14 && local_58 < local_60 + 1))) {
        uVar10 = 0;
LAB_00186c78:
        do {
          bVar2 = param_1[uVar10 + 0x10];
          bVar9 = *(byte *)((int)local_38 + uVar10) ^ *(byte *)((int)local_60 + uVar10);
          *(byte *)((int)param_3 + uVar10) = bVar9;
          uVar11 = uVar10 + 1;
          param_1[uVar10 + 0x10] = bVar9 ^ bVar2;
          uVar10 = uVar11;
        } while (uVar11 < local_50);
      }
      else {
        if (uVar12 < 9) {
          uVar13 = 0;
          puVar8 = param_3;
          puVar19 = local_38;
          puVar24 = local_58;
          puVar25 = local_60;
        }
        else {
          uVar13 = 0;
          puVar6 = (uint *)&stack0xffffffe8;
          puVar7 = (uint *)(param_1 + 0x30);
          puVar4 = local_60;
          puVar5 = param_3;
          do {
            puVar24 = puVar7;
            puVar19 = puVar6;
            puVar8 = puVar5 + 8;
            puVar25 = puVar4 + 8;
            uVar18 = puVar19[-8];
            uVar21 = uVar13 + 9;
            uVar14 = *puVar4;
            uVar20 = puVar24[-8];
            uVar13 = uVar13 + 8;
            HintPreloadData(puVar24 + 6);
            HintPreloadData(puVar19 + 6);
            *puVar5 = uVar14 ^ uVar18;
            puVar24[-8] = uVar14 ^ uVar18 ^ uVar20;
            uVar18 = puVar19[-7];
            uVar14 = puVar4[1];
            uVar20 = puVar24[-7];
            puVar5[1] = uVar18 ^ uVar14;
            puVar24[-7] = uVar18 ^ uVar14 ^ uVar20;
            uVar18 = puVar4[2];
            uVar14 = puVar19[-6];
            uVar20 = puVar24[-6];
            puVar5[2] = uVar18 ^ uVar14;
            puVar24[-6] = uVar18 ^ uVar14 ^ uVar20;
            uVar18 = puVar4[3];
            uVar14 = puVar19[-5];
            uVar20 = puVar24[-5];
            puVar5[3] = uVar18 ^ uVar14;
            puVar24[-5] = uVar18 ^ uVar14 ^ uVar20;
            uVar18 = puVar4[4];
            uVar14 = puVar19[-4];
            uVar20 = puVar24[-4];
            puVar5[4] = uVar18 ^ uVar14;
            puVar24[-4] = uVar18 ^ uVar14 ^ uVar20;
            uVar18 = puVar4[5];
            uVar14 = puVar19[-3];
            uVar20 = puVar24[-3];
            puVar5[5] = uVar18 ^ uVar14;
            puVar24[-3] = uVar18 ^ uVar14 ^ uVar20;
            uVar18 = puVar4[6];
            uVar14 = puVar19[-2];
            uVar20 = puVar24[-2];
            puVar5[6] = uVar18 ^ uVar14;
            puVar24[-2] = uVar18 ^ uVar14 ^ uVar20;
            uVar18 = puVar4[7];
            uVar14 = puVar19[-1];
            uVar20 = puVar24[-1];
            puVar5[7] = uVar18 ^ uVar14;
            puVar24[-1] = uVar18 ^ uVar14 ^ uVar20;
            puVar6 = puVar19 + 8;
            puVar7 = puVar24 + 8;
            puVar4 = puVar25;
            puVar5 = puVar8;
          } while (uVar21 < uVar12 - 7);
        }
        iVar15 = 0;
        do {
          uVar13 = uVar13 + 1;
          uVar14 = *(uint *)((int)puVar24 + iVar15);
          uVar20 = *(uint *)((int)puVar25 + iVar15) ^ *(uint *)((int)puVar19 + iVar15);
          *(uint *)((int)puVar8 + iVar15) = uVar20;
          *(uint *)((int)puVar24 + iVar15) = uVar20 ^ uVar14;
          iVar15 = iVar15 + 4;
        } while (uVar13 < uVar12);
        if (uVar11 != uVar10) goto LAB_00186c78;
      }
      (*pcVar16)(local_58,local_58,uVar17);
    }
  }
  else {
    uVar10 = uVar11 * 0x10;
    (*param_5)(param_2,param_3,uVar11,uVar17,param_1,param_1 + 0x10);
    local_50 = param_4 + uVar11 * -0x10;
    if (local_50 != 0) {
      uVar12 = (uVar11 & 0xff) + (uint)param_1[0xf];
      uVar13 = uVar12 >> 8;
      param_1[0xf] = (byte)uVar12;
      if (uVar13 != 0 || uVar10 >> 0xc != 0) {
        uVar13 = (uint)param_1[0xe] + (uVar10 >> 0xc & 0xff) + uVar13;
        uVar12 = uVar13 >> 8;
        param_1[0xe] = (byte)uVar13;
        if (uVar12 != 0 || uVar10 >> 0x14 != 0) {
          uVar12 = (uint)param_1[0xd] + (uVar10 >> 0x14 & 0xff) + uVar12;
          uVar13 = uVar12 >> 8;
          param_1[0xd] = (byte)uVar12;
          if (uVar13 != 0 || uVar10 >> 0x1c != 0) {
            uVar13 = (uVar10 >> 0x1c) + (uint)param_1[0xc] + uVar13;
            param_1[0xc] = (byte)uVar13;
            uVar13 = uVar13 >> 8;
            if (uVar13 != 0) {
              uVar13 = uVar13 + param_1[0xb];
              param_1[0xb] = (byte)uVar13;
              uVar13 = uVar13 >> 8;
              if (uVar13 != 0) {
                uVar13 = uVar13 + param_1[10];
                param_1[10] = (byte)uVar13;
                uVar13 = uVar13 >> 8;
                if (uVar13 != 0) {
                  uVar13 = uVar13 + param_1[9];
                  param_1[9] = (byte)uVar13;
                  if (uVar13 >> 8 != 0) {
                    param_1[8] = param_1[8] + (char)(uVar13 >> 8);
                  }
                }
              }
            }
          }
        }
      }
      param_3 = param_3 + uVar11 * 4;
      local_60 = param_2 + uVar11 * 4;
      goto LAB_00186a48;
    }
  }
  local_68 = local_38;
  uVar10 = ~uVar22 + 0x11;
  uVar11 = -(int)(param_1 + uVar22) & 3U;
  if (uVar10 <= (-(int)(param_1 + uVar22) & 3U)) {
    uVar11 = uVar10;
  }
  if (uVar10 < 4) {
    uVar11 = uVar10;
  }
  uVar12 = uVar22;
  if (uVar11 != 0) {
    do {
      param_1[uVar12] = 0;
      uVar12 = uVar12 + 1;
    } while (uVar12 - uVar22 < uVar11);
    if (uVar10 == uVar11) goto LAB_0018695a;
  }
  uVar13 = uVar10 - uVar11 >> 2;
  if (uVar13 != 0) {
    pbVar23 = param_1 + uVar22 + uVar11;
    if (uVar13 < 9) {
      uVar22 = 0;
    }
    else {
      uVar22 = 0;
      pbVar3 = pbVar23;
      do {
        pbVar23 = pbVar3 + 0x20;
        uVar20 = uVar22 + 9;
        uVar22 = uVar22 + 8;
        HintPreloadData(pbVar3 + 0xa0);
        pbVar3[0] = 0;
        pbVar3[1] = 0;
        pbVar3[2] = 0;
        pbVar3[3] = 0;
        pbVar3[4] = 0;
        pbVar3[5] = 0;
        pbVar3[6] = 0;
        pbVar3[7] = 0;
        pbVar3[8] = 0;
        pbVar3[9] = 0;
        pbVar3[10] = 0;
        pbVar3[0xb] = 0;
        pbVar3[0xc] = 0;
        pbVar3[0xd] = 0;
        pbVar3[0xe] = 0;
        pbVar3[0xf] = 0;
        pbVar3[0x10] = 0;
        pbVar3[0x11] = 0;
        pbVar3[0x12] = 0;
        pbVar3[0x13] = 0;
        pbVar3[0x14] = 0;
        pbVar3[0x15] = 0;
        pbVar3[0x16] = 0;
        pbVar3[0x17] = 0;
        pbVar3[0x18] = 0;
        pbVar3[0x19] = 0;
        pbVar3[0x1a] = 0;
        pbVar3[0x1b] = 0;
        pbVar3[0x1c] = 0;
        pbVar3[0x1d] = 0;
        pbVar3[0x1e] = 0;
        pbVar3[0x1f] = 0;
        pbVar3 = pbVar23;
      } while (uVar20 < uVar13 - 7);
    }
    do {
      uVar22 = uVar22 + 1;
      pbVar23[0] = 0;
      pbVar23[1] = 0;
      pbVar23[2] = 0;
      pbVar23[3] = 0;
      pbVar23 = pbVar23 + 4;
    } while (uVar22 < uVar13);
    uVar12 = uVar12 + uVar13 * 4;
    if (uVar10 - uVar11 == uVar13 * 4) goto LAB_0018695a;
  }
  do {
    param_1[uVar12] = 0;
    uVar12 = uVar12 + 1;
  } while (uVar12 != 0x10);
LAB_0018695a:
  (*pcVar16)(param_1,local_68,uVar17);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_38[0] ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_38[1] ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38[2];
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_38[3];
  return 0;
}


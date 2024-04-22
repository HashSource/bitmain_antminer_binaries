
undefined4
CRYPTO_ccm128_decrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  code *pcVar17;
  undefined4 uVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  undefined4 *puVar23;
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
  pcVar17 = *(code **)(param_1 + 0x28);
  uVar18 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar1 & 0x40) == 0) {
    (*pcVar17)(param_1,param_1 + 0x10,uVar18);
  }
  uVar11 = 0;
  *param_1 = (byte)(bVar1 & 7);
  uVar22 = 0xf - (bVar1 & 7);
  uVar12 = uVar22;
  if ((bVar1 & 7) != 0) {
    do {
      bVar2 = param_1[uVar12];
      param_1[uVar12] = 0;
      uVar12 = uVar12 + 1;
      uVar11 = (uVar11 | bVar2) << 8;
    } while (uVar12 != 0xf);
  }
  bVar2 = param_1[0xf];
  param_1[0xf] = 1;
  if ((uVar11 | bVar2) != param_4) {
    return 0xffffffff;
  }
  if (param_4 >> 4 == 0) {
    local_60 = param_2;
    local_50 = param_4;
    if (param_4 != 0) {
LAB_000ee2e4:
      local_58 = (uint *)(param_1 + 0x10);
      (*pcVar17)(param_1,local_38,uVar18);
      puVar9 = param_3 + 1;
      bVar27 = param_3 <= local_38 + 1;
      bVar26 = local_38 + 1 == param_3;
      if (bVar27 && !bVar26) {
        bVar27 = local_38 <= puVar9;
        bVar26 = puVar9 == local_38;
      }
      uVar12 = local_50;
      if (local_50 == 0) {
        uVar12 = 1;
      }
      uVar13 = uVar12 >> 2;
      uVar11 = uVar12 & 0xfffffffc;
      if (uVar13 == 0 ||
          ((((uint)param_3 | (uint)local_60) & 3) != 0 ||
          ((param_3 < local_60 + 1 && local_60 < puVar9 ||
           (local_50 < 4 || (local_58 < puVar9 && param_3 < param_1 + 0x14 || bVar27 && !bVar26)))
          || local_60 < param_1 + 0x14 && local_58 < local_60 + 1))) {
        uVar11 = 0;
LAB_000ee514:
        do {
          bVar2 = param_1[uVar11 + 0x10];
          bVar10 = *(byte *)((int)local_38 + uVar11) ^ *(byte *)((int)local_60 + uVar11);
          *(byte *)((int)param_3 + uVar11) = bVar10;
          uVar12 = uVar11 + 1;
          param_1[uVar11 + 0x10] = bVar10 ^ bVar2;
          uVar11 = uVar12;
        } while (uVar12 < local_50);
      }
      else {
        if (uVar13 < 9) {
          uVar14 = 0;
          puVar9 = param_3;
          puVar20 = local_38;
          puVar24 = local_58;
          puVar25 = local_60;
        }
        else {
          uVar14 = 0;
          puVar6 = (uint *)&stack0xffffffe8;
          puVar7 = (uint *)(param_1 + 0x30);
          puVar4 = local_60;
          puVar5 = param_3;
          do {
            puVar24 = puVar7;
            puVar20 = puVar6;
            puVar9 = puVar5 + 8;
            puVar25 = puVar4 + 8;
            uVar19 = puVar20[-8];
            uVar21 = uVar14 + 9;
            uVar15 = *puVar4;
            uVar8 = puVar24[-8];
            uVar14 = uVar14 + 8;
            HintPreloadData(puVar24 + 6);
            HintPreloadData(puVar20 + 6);
            *puVar5 = uVar15 ^ uVar19;
            puVar24[-8] = uVar15 ^ uVar19 ^ uVar8;
            uVar19 = puVar20[-7];
            uVar15 = puVar4[1];
            uVar8 = puVar24[-7];
            puVar5[1] = uVar19 ^ uVar15;
            puVar24[-7] = uVar19 ^ uVar15 ^ uVar8;
            uVar19 = puVar4[2];
            uVar15 = puVar20[-6];
            uVar8 = puVar24[-6];
            puVar5[2] = uVar19 ^ uVar15;
            puVar24[-6] = uVar19 ^ uVar15 ^ uVar8;
            uVar19 = puVar4[3];
            uVar15 = puVar20[-5];
            uVar8 = puVar24[-5];
            puVar5[3] = uVar19 ^ uVar15;
            puVar24[-5] = uVar19 ^ uVar15 ^ uVar8;
            uVar19 = puVar4[4];
            uVar15 = puVar20[-4];
            uVar8 = puVar24[-4];
            puVar5[4] = uVar19 ^ uVar15;
            puVar24[-4] = uVar19 ^ uVar15 ^ uVar8;
            uVar19 = puVar4[5];
            uVar15 = puVar20[-3];
            uVar8 = puVar24[-3];
            puVar5[5] = uVar19 ^ uVar15;
            puVar24[-3] = uVar19 ^ uVar15 ^ uVar8;
            uVar19 = puVar4[6];
            uVar15 = puVar20[-2];
            uVar8 = puVar24[-2];
            puVar5[6] = uVar19 ^ uVar15;
            puVar24[-2] = uVar19 ^ uVar15 ^ uVar8;
            uVar19 = puVar4[7];
            uVar15 = puVar20[-1];
            uVar8 = puVar24[-1];
            puVar5[7] = uVar19 ^ uVar15;
            puVar24[-1] = uVar19 ^ uVar15 ^ uVar8;
            puVar6 = puVar20 + 8;
            puVar7 = puVar24 + 8;
            puVar4 = puVar25;
            puVar5 = puVar9;
          } while (uVar21 < uVar13 - 7);
        }
        iVar16 = 0;
        do {
          uVar14 = uVar14 + 1;
          uVar15 = *(uint *)((int)puVar24 + iVar16);
          uVar8 = *(uint *)((int)puVar25 + iVar16) ^ *(uint *)((int)puVar20 + iVar16);
          *(uint *)((int)puVar9 + iVar16) = uVar8;
          *(uint *)((int)puVar24 + iVar16) = uVar8 ^ uVar15;
          iVar16 = iVar16 + 4;
        } while (uVar14 < uVar13);
        if (uVar12 != uVar11) goto LAB_000ee514;
      }
      (*pcVar17)(local_58,local_58,uVar18);
    }
  }
  else {
    uVar12 = param_4 & 0xfffffff0;
    (*param_5)(param_2,param_3,param_4 >> 4,uVar18,param_1,param_1 + 0x10);
    local_50 = param_4 - uVar12;
    if (local_50 != 0) {
      uVar11 = ((uVar12 << 0x14) >> 0x18) + (uint)param_1[0xf];
      uVar13 = uVar11 >> 8;
      param_1[0xf] = (byte)uVar11;
      if ((uVar13 | param_4 >> 0xc) != 0) {
        uVar13 = (uint)param_1[0xe] + (param_4 >> 0xc & 0xff) + uVar13;
        uVar11 = uVar13 >> 8;
        param_1[0xe] = (byte)uVar13;
        if ((uVar11 | param_4 >> 0x14) != 0) {
          uVar11 = (uint)param_1[0xd] + (param_4 >> 0x14 & 0xff) + uVar11;
          uVar13 = uVar11 >> 8;
          param_1[0xd] = (byte)uVar11;
          if ((uVar13 | param_4 >> 0x1c) != 0) {
            uVar13 = (param_4 >> 0x1c) + (uint)param_1[0xc] + uVar13;
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
      param_3 = (uint *)((int)param_3 + uVar12);
      local_60 = (uint *)((int)param_2 + uVar12);
      goto LAB_000ee2e4;
    }
  }
  local_68 = local_38;
  uVar11 = ~uVar22 + 0x11;
  uVar12 = -(int)(param_1 + uVar22) & 3U;
  if (uVar11 <= (-(int)(param_1 + uVar22) & 3U)) {
    uVar12 = uVar11;
  }
  if (uVar11 < 4) {
    uVar12 = uVar11;
  }
  uVar13 = uVar22;
  if (uVar12 != 0) {
    do {
      param_1[uVar13] = 0;
      uVar13 = uVar13 + 1;
    } while (uVar13 - uVar22 < uVar12);
    if (uVar11 == uVar12) goto LAB_000ee1f6;
  }
  uVar11 = uVar11 - uVar12;
  uVar14 = uVar11 >> 2;
  if (uVar14 != 0) {
    puVar23 = (undefined4 *)(param_1 + uVar22 + uVar12);
    if (uVar14 < 9) {
      uVar12 = 0;
    }
    else {
      uVar12 = 0;
      puVar3 = puVar23;
      do {
        puVar23 = puVar3 + 8;
        uVar22 = uVar12 + 9;
        uVar12 = uVar12 + 8;
        HintPreloadData(puVar3 + 0x28);
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[3] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        puVar3[7] = 0;
        puVar3 = puVar23;
      } while (uVar22 < uVar14 - 7);
    }
    do {
      uVar12 = uVar12 + 1;
      *puVar23 = 0;
      puVar23 = puVar23 + 1;
    } while (uVar12 < uVar14);
    uVar13 = uVar13 + (uVar11 & 0xfffffffc);
    if (uVar11 == (uVar11 & 0xfffffffc)) goto LAB_000ee1f6;
  }
  do {
    param_1[uVar13] = 0;
    uVar13 = uVar13 + 1;
  } while (uVar13 != 0x10);
LAB_000ee1f6:
  (*pcVar17)(param_1,local_68,uVar18);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_38[0] ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_38[1] ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38[2];
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_38[3];
  return 0;
}


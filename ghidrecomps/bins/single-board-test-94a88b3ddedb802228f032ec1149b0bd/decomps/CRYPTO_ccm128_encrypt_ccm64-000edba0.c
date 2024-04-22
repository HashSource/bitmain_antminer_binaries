
undefined4
CRYPTO_ccm128_encrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint *puVar6;
  code *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint *puVar20;
  uint *puVar21;
  bool bVar22;
  bool bVar23;
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
  uVar19 = 0xf - (bVar1 & 7);
  uVar12 = uVar19;
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
  bVar22 = 0x1fffffff < uVar12;
  if (uVar12 == 0x20000000) {
    bVar22 = iVar11 != 0;
  }
  *(int *)(param_1 + 0x20) = iVar11;
  *(uint *)(param_1 + 0x24) = uVar12;
  if (bVar22) {
    return 0xfffffffe;
  }
  if (param_4 >> 4 == 0) {
    uVar12 = param_4;
    local_5c = param_3;
    if (param_4 != 0) {
LAB_000edc2e:
      puVar14 = (uint *)(param_1 + 0x10);
      uVar10 = uVar12;
      if (uVar12 == 0) {
        uVar10 = 1;
      }
      uVar18 = uVar10 >> 2;
      uVar13 = 1 - uVar18;
      puVar20 = param_2 + 1;
      if (1 < uVar18) {
        uVar13 = 0;
      }
      bVar23 = param_2 <= param_1 + 0x14;
      bVar22 = (uint *)(param_1 + 0x14) == param_2;
      if (bVar23 && !bVar22) {
        bVar23 = puVar14 <= puVar20;
        bVar22 = puVar20 == puVar14;
      }
      uVar17 = uVar10 & 0xfffffffc;
      if ((uVar13 | ((((uint)param_2 & 3) == 0 && (!bVar23 || bVar22)) && 3 < uVar12) ^ 1) == 0) {
        if (uVar18 < 9) {
          uVar8 = 0;
          puVar6 = puVar14;
          puVar21 = param_2;
        }
        else {
          uVar8 = 0;
          puVar5 = (uint *)(param_1 + 0x30);
          puVar3 = param_2;
          do {
            puVar6 = puVar5;
            puVar21 = puVar3 + 8;
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
            puVar3 = puVar21;
          } while (uVar16 < uVar18 - 7);
        }
        iVar11 = 0;
        do {
          uVar8 = uVar8 + 1;
          *(uint *)((int)puVar6 + iVar11) =
               *(uint *)((int)puVar21 + iVar11) ^ *(uint *)((int)puVar6 + iVar11);
          iVar11 = iVar11 + 4;
        } while (uVar8 < uVar18);
        uVar8 = uVar17;
        if (uVar10 != uVar17) goto LAB_000edd80;
      }
      else {
        uVar8 = 0;
LAB_000edd80:
        do {
          uVar16 = uVar8 + 1;
          param_1[uVar8 + 0x10] = param_1[uVar8 + 0x10] ^ *(byte *)((int)param_2 + uVar8);
          uVar8 = uVar16;
        } while (uVar16 < uVar12);
      }
      (*pcVar7)(puVar14,puVar14,uVar9);
      (*pcVar7)(param_1,local_38,uVar9);
      puVar14 = local_5c + 1;
      bVar23 = local_5c <= local_38 + 1;
      bVar22 = local_38 + 1 == local_5c;
      if (bVar23 && !bVar22) {
        bVar23 = local_38 <= puVar14;
        bVar22 = puVar14 == local_38;
      }
      uVar8 = (uint)(((!bVar23 || bVar22) && (puVar20 <= local_5c || puVar14 <= param_2)) &&
                    3 < uVar12);
      if ((((uint)local_5c | (uint)param_2) & 3) != 0) {
        uVar8 = 0;
      }
      if ((uVar13 | uVar8 ^ 1) == 0) {
        if (uVar18 < 9) {
          uVar13 = 0;
          puVar14 = local_5c;
          puVar20 = local_38;
          puVar6 = param_2;
        }
        else {
          uVar13 = 0;
          puVar5 = (uint *)&stack0xffffffe8;
          puVar21 = param_2;
          puVar3 = local_5c;
          do {
            puVar20 = puVar5;
            puVar14 = puVar3 + 8;
            puVar6 = puVar21 + 8;
            uVar8 = uVar13 + 9;
            uVar13 = uVar13 + 8;
            HintPreloadData(puVar20 + 0xc);
            *puVar3 = *puVar21 ^ puVar20[-8];
            puVar3[1] = puVar21[1] ^ puVar20[-7];
            puVar3[2] = puVar21[2] ^ puVar20[-6];
            puVar3[3] = puVar21[3] ^ puVar20[-5];
            puVar3[4] = puVar21[4] ^ puVar20[-4];
            puVar3[5] = puVar20[-3] ^ puVar21[5];
            puVar3[6] = puVar21[6] ^ puVar20[-2];
            puVar3[7] = puVar21[7] ^ puVar20[-1];
            puVar5 = puVar20 + 8;
            puVar21 = puVar6;
            puVar3 = puVar14;
          } while (uVar8 < uVar18 - 7);
        }
        iVar11 = 0;
        do {
          uVar13 = uVar13 + 1;
          *(uint *)((int)puVar14 + iVar11) =
               *(uint *)((int)puVar6 + iVar11) ^ *(uint *)((int)puVar20 + iVar11);
          iVar11 = iVar11 + 4;
        } while (uVar13 < uVar18);
        if (uVar10 == uVar17) goto LAB_000edf0e;
      }
      else {
        uVar17 = 0;
      }
      do {
        *(byte *)((int)local_5c + uVar17) =
             *(byte *)((int)local_38 + uVar17) ^ *(byte *)((int)param_2 + uVar17);
        uVar17 = uVar17 + 1;
      } while (uVar17 < uVar12);
    }
  }
  else {
    uVar10 = param_4 & 0xfffffff0;
    (*param_5)(param_2,param_3,param_4 >> 4,uVar9,param_1,param_1 + 0x10);
    uVar12 = param_4 - uVar10;
    if (uVar12 != 0) {
      uVar13 = ((uVar10 << 0x14) >> 0x18) + (uint)param_1[0xf];
      uVar18 = uVar13 >> 8;
      param_1[0xf] = (byte)uVar13;
      if ((uVar18 | param_4 >> 0xc) != 0) {
        uVar18 = (uint)param_1[0xe] + (param_4 >> 0xc & 0xff) + uVar18;
        uVar13 = uVar18 >> 8;
        param_1[0xe] = (byte)uVar18;
        if ((uVar13 | param_4 >> 0x14) != 0) {
          uVar13 = (uint)param_1[0xd] + (param_4 >> 0x14 & 0xff) + uVar13;
          uVar18 = uVar13 >> 8;
          param_1[0xd] = (byte)uVar13;
          if ((uVar18 | param_4 >> 0x1c) != 0) {
            uVar18 = (param_4 >> 0x1c) + (uint)param_1[0xc] + uVar18;
            param_1[0xc] = (byte)uVar18;
            uVar18 = uVar18 >> 8;
            if (uVar18 != 0) {
              uVar18 = uVar18 + param_1[0xb];
              param_1[0xb] = (byte)uVar18;
              uVar18 = uVar18 >> 8;
              if (uVar18 != 0) {
                uVar18 = uVar18 + param_1[10];
                param_1[10] = (byte)uVar18;
                uVar18 = uVar18 >> 8;
                if (uVar18 != 0) {
                  uVar18 = uVar18 + param_1[9];
                  param_1[9] = (byte)uVar18;
                  if (uVar18 >> 8 != 0) {
                    param_1[8] = param_1[8] + (char)(uVar18 >> 8);
                  }
                }
              }
            }
          }
        }
      }
      param_2 = (uint *)((int)param_2 + uVar10);
      local_5c = (uint *)((int)param_3 + uVar10);
      goto LAB_000edc2e;
    }
  }
LAB_000edf0e:
  local_6c = local_38;
  uVar10 = ~uVar19 + 0x11;
  uVar12 = -(int)(param_1 + uVar19) & 3U;
  if (uVar10 <= (-(int)(param_1 + uVar19) & 3U)) {
    uVar12 = uVar10;
  }
  if (uVar10 < 4) {
    uVar12 = uVar10;
  }
  uVar13 = uVar19;
  if (uVar12 != 0) {
    do {
      param_1[uVar13] = 0;
      uVar13 = uVar13 + 1;
    } while (uVar13 - uVar19 < uVar12);
    if (uVar10 == uVar12) goto LAB_000edfbc;
  }
  uVar10 = uVar10 - uVar12;
  uVar18 = uVar10 >> 2;
  if (uVar18 != 0) {
    puVar15 = (undefined4 *)(param_1 + uVar12 + uVar19);
    if (uVar18 < 9) {
      uVar12 = 0;
    }
    else {
      uVar12 = 0;
      puVar4 = puVar15;
      do {
        puVar15 = puVar4 + 8;
        uVar19 = uVar12 + 9;
        uVar12 = uVar12 + 8;
        HintPreloadData(puVar4 + 0x28);
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        puVar4[6] = 0;
        puVar4[7] = 0;
        puVar4 = puVar15;
      } while (uVar19 < uVar18 - 7);
    }
    do {
      uVar12 = uVar12 + 1;
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    } while (uVar12 < uVar18);
    uVar13 = uVar13 + (uVar10 & 0xfffffffc);
    if (uVar10 == (uVar10 & 0xfffffffc)) goto LAB_000edfbc;
  }
  do {
    param_1[uVar13] = 0;
    uVar13 = uVar13 + 1;
  } while (uVar13 != 0x10);
LAB_000edfbc:
  (*pcVar7)(param_1,local_6c,uVar9);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_38[0] ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_38[1] ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_38[2];
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_38[3];
  return 0;
}



/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 CRYPTO_ccm128_decrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  code *pcVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  bool bVar17;
  bool bVar18;
  uint *local_58;
  uint *local_54;
  uint local_48 [4];
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  
  bVar1 = *param_1;
  pcVar11 = *(code **)(param_1 + 0x28);
  uVar13 = *(undefined4 *)(param_1 + 0x2c);
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar11)(param_1,param_1 + 0x10,uVar13);
  }
  uVar5 = bVar1 & 7;
  uVar8 = 0;
  uVar12 = 0xf - uVar5;
  *param_1 = (byte)uVar5;
  uVar5 = uVar12;
  if ((bVar1 & 7) != 0) {
    do {
      bVar2 = param_1[uVar5];
      param_1[uVar5] = 0;
      uVar5 = uVar5 + 1;
      uVar8 = (uVar8 | bVar2) << 8;
    } while (uVar5 != 0xf);
  }
  bVar2 = param_1[0xf];
  param_1[0xf] = 1;
  uVar8 = bVar2 | uVar8;
  if (uVar8 != param_4) {
    return 0xffffffff;
  }
  local_58 = param_3;
  local_54 = param_2;
  if (0xf < param_4) {
    puVar16 = param_3 + 8;
    puVar15 = param_2 + 8;
    do {
      HintPreloadData(puVar15);
      param_4 = param_4 - 0x10;
      (*pcVar11)(param_1,local_48,uVar13);
      bVar4 = param_1[0xf];
      HintPreloadData(puVar16);
      param_1[0xf] = bVar4 + 1;
      if (((((byte)(bVar4 + 1) == 0) &&
           (bVar4 = param_1[0xe], param_1[0xe] = bVar4 + 1, (byte)(bVar4 + 1) == 0)) &&
          (bVar4 = param_1[0xd], param_1[0xd] = bVar4 + 1, (byte)(bVar4 + 1) == 0)) &&
         (((bVar4 = param_1[0xc], param_1[0xc] = bVar4 + 1, (byte)(bVar4 + 1) == 0 &&
           (bVar4 = param_1[0xb], param_1[0xb] = bVar4 + 1, (byte)(bVar4 + 1) == 0)) &&
          ((bVar4 = param_1[10], param_1[10] = bVar4 + 1, (byte)(bVar4 + 1) == 0 &&
           (bVar4 = param_1[9], param_1[9] = bVar4 + 1, (byte)(bVar4 + 1) == 0)))))) {
        param_1[8] = param_1[8] + 1;
      }
      local_38 = puVar15[-8];
      uStack_34 = puVar15[-7];
      local_30 = puVar15[-6];
      uStack_2c = puVar15[-5];
      local_48[0] = local_38 ^ local_48[0];
      local_48[1] = uStack_34 ^ local_48[1];
      local_48[2] = local_30 ^ local_48[2];
      local_48[3] = uStack_2c ^ local_48[3];
      *(uint *)(param_1 + 0x10) = local_48[0] ^ *(uint *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x14) = local_48[1] ^ *(uint *)(param_1 + 0x14);
      *(uint *)(param_1 + 0x18) = local_48[2] ^ *(uint *)(param_1 + 0x18);
      *(uint *)(param_1 + 0x1c) = local_48[3] ^ *(uint *)(param_1 + 0x1c);
      puVar16[-8] = local_48[0];
      puVar16[-7] = local_48[1];
      puVar16[-6] = local_48[2];
      puVar16[-5] = local_48[3];
      (*pcVar11)(param_1 + 0x10,param_1 + 0x10,uVar13);
      puVar16 = puVar16 + 4;
      puVar15 = puVar15 + 4;
    } while (0xf < param_4);
    param_4 = bVar2 & 0xf;
    iVar6 = (uVar8 - 0x10 & 0xfffffff0) + 0x10;
    local_54 = (uint *)((int)param_2 + iVar6);
    local_58 = (uint *)((int)param_3 + iVar6);
  }
  if (param_4 != 0) {
    puVar15 = (uint *)(param_1 + 0x10);
    (*pcVar11)(param_1,local_48,uVar13);
    uVar5 = param_4 >> 2;
    puVar16 = local_58 + 1;
    bVar18 = local_58 <= local_48 + 1;
    bVar17 = local_48 + 1 == local_58;
    if (bVar18 && !bVar17) {
      bVar18 = local_48 <= puVar16;
      bVar17 = puVar16 == local_48;
    }
    uVar8 = uVar5 * 4;
    if (uVar5 == 0 ||
        ((((uint)local_58 | (uint)local_54) & 3) != 0 ||
        (local_54 < param_1 + 0x14 && puVar15 < local_54 + 1 ||
        ((param_4 < 4 || (puVar15 < puVar16 && local_58 < param_1 + 0x14 || bVar18 && !bVar17)) ||
        local_58 < local_54 + 1 && local_54 < puVar16)))) {
      uVar8 = 0;
LAB_000edb58:
      do {
        bVar2 = param_1[uVar8 + 0x10];
        bVar4 = *(byte *)((int)local_48 + uVar8) ^ *(byte *)((int)local_54 + uVar8);
        *(byte *)((int)local_58 + uVar8) = bVar4;
        uVar5 = uVar8 + 1;
        param_1[uVar8 + 0x10] = bVar4 ^ bVar2;
        uVar8 = uVar5;
      } while (uVar5 < param_4);
    }
    else {
      uVar7 = 0;
      iVar6 = 0;
      do {
        uVar7 = uVar7 + 1;
        uVar10 = *(uint *)((int)puVar15 + iVar6);
        uVar14 = *(uint *)((int)local_48 + iVar6) ^ *(uint *)((int)local_54 + iVar6);
        *(uint *)((int)local_58 + iVar6) = uVar14;
        *(uint *)((int)puVar15 + iVar6) = uVar14 ^ uVar10;
        iVar6 = iVar6 + 4;
      } while (uVar7 < uVar5);
      if (param_4 != uVar8) goto LAB_000edb58;
    }
    (*pcVar11)(puVar15,puVar15,uVar13);
  }
  uVar8 = ~uVar12 + 0x11;
  uVar5 = -(int)(param_1 + uVar12) & 3U;
  if (uVar8 <= (-(int)(param_1 + uVar12) & 3U)) {
    uVar5 = uVar8;
  }
  if (uVar8 < 4) {
    uVar5 = uVar8;
  }
  uVar7 = uVar12;
  if (uVar5 != 0) {
    do {
      param_1[uVar7] = 0;
      uVar7 = uVar7 + 1;
    } while (uVar7 - uVar12 < uVar5);
    if (uVar8 == uVar5) goto LAB_000eda4e;
  }
  uVar10 = uVar8 - uVar5 >> 2;
  if (uVar10 != 0) {
    pbVar9 = param_1 + uVar5 + uVar12;
    if (uVar10 < 9) {
      uVar12 = 0;
    }
    else {
      uVar12 = 0;
      pbVar3 = pbVar9;
      do {
        pbVar9 = pbVar3 + 0x20;
        uVar14 = uVar12 + 9;
        uVar12 = uVar12 + 8;
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
        pbVar3 = pbVar9;
      } while (uVar14 < uVar10 - 7);
    }
    do {
      uVar12 = uVar12 + 1;
      pbVar9[0] = 0;
      pbVar9[1] = 0;
      pbVar9[2] = 0;
      pbVar9[3] = 0;
      pbVar9 = pbVar9 + 4;
    } while (uVar12 < uVar10);
    uVar7 = uVar7 + uVar10 * 4;
    if (uVar8 - uVar5 == uVar10 * 4) goto LAB_000eda4e;
  }
  do {
    param_1[uVar7] = 0;
    uVar7 = uVar7 + 1;
  } while (uVar7 != 0x10);
LAB_000eda4e:
  (*pcVar11)(param_1,local_48,uVar13);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_48[0] ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_48[1] ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_48[2];
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_48[3];
  return 0;
}



undefined4 CRYPTO_ccm128_encrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  byte *pbVar12;
  code *pcVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  uint *puVar17;
  bool bVar18;
  bool bVar19;
  uint *local_68;
  uint *local_60;
  uint local_48 [4];
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  
  bVar1 = *param_1;
  pcVar13 = *(code **)(param_1 + 0x28);
  uVar15 = *(undefined4 *)(param_1 + 0x2c);
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar13)(param_1,param_1 + 0x10,uVar15);
    uVar8 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar8 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar8);
  }
  uVar8 = bVar1 & 7;
  uVar14 = 0;
  uVar16 = 0xf - uVar8;
  *param_1 = (byte)uVar8;
  uVar8 = uVar16;
  if ((bVar1 & 7) != 0) {
    do {
      bVar3 = param_1[uVar8];
      param_1[uVar8] = 0;
      uVar8 = uVar8 + 1;
      uVar14 = (uVar14 | bVar3) << 8;
    } while (uVar8 != 0xf);
  }
  bVar3 = param_1[0xf];
  param_1[0xf] = 1;
  uVar14 = bVar3 | uVar14;
  if (uVar14 != param_4) {
    return 0xffffffff;
  }
  uVar8 = param_4 + 0xf >> 3 | 1;
  iVar6 = *(uint *)(param_1 + 0x20) + uVar8;
  uVar8 = *(int *)(param_1 + 0x24) + (uint)CARRY4(*(uint *)(param_1 + 0x20),uVar8);
  bVar18 = 0x1fffffff < uVar8;
  if (uVar8 == 0x20000000) {
    bVar18 = iVar6 != 0;
  }
  *(int *)(param_1 + 0x20) = iVar6;
  *(uint *)(param_1 + 0x24) = uVar8;
  if (bVar18) {
    return 0xfffffffe;
  }
  if (param_4 < 0x10) {
    local_60 = param_3;
    if (param_4 != 0) goto LAB_000ed59a;
  }
  else {
    puVar11 = param_3 + 8;
    puVar17 = param_2 + 8;
    do {
      uVar8 = puVar17[-8];
      param_4 = param_4 - 0x10;
      HintPreloadData(puVar17);
      HintPreloadData(puVar11);
      uVar5 = puVar17[-7];
      uVar7 = puVar17[-6];
      uVar9 = puVar17[-5];
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ uVar8;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ uVar5;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ uVar7;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ uVar9;
      local_38 = uVar8;
      uStack_34 = uVar5;
      local_30 = uVar7;
      uStack_2c = uVar9;
      (*pcVar13)(param_1 + 0x10,param_1 + 0x10,uVar15);
      (*pcVar13)(param_1,local_48,uVar15);
      bVar2 = param_1[0xf];
      local_38 = local_48[0] ^ uVar8;
      param_1[0xf] = bVar2 + 1;
      uStack_34 = local_48[1] ^ uVar5;
      if (((((byte)(bVar2 + 1) == 0) &&
           (bVar2 = param_1[0xe], param_1[0xe] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
          (bVar2 = param_1[0xd], param_1[0xd] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
         (((bVar2 = param_1[0xc], param_1[0xc] = bVar2 + 1, (byte)(bVar2 + 1) == 0 &&
           (bVar2 = param_1[0xb], param_1[0xb] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
          ((bVar2 = param_1[10], param_1[10] = bVar2 + 1, (byte)(bVar2 + 1) == 0 &&
           (bVar2 = param_1[9], param_1[9] = bVar2 + 1, (byte)(bVar2 + 1) == 0)))))) {
        param_1[8] = param_1[8] + 1;
      }
      local_30 = local_48[2] ^ uVar7;
      uStack_2c = local_48[3] ^ uVar9;
      puVar11[-8] = local_38;
      puVar11[-7] = uStack_34;
      puVar11[-6] = local_30;
      puVar11[-5] = uStack_2c;
      puVar11 = puVar11 + 4;
      puVar17 = puVar17 + 4;
    } while (0xf < param_4);
    param_4 = bVar3 & 0xf;
    iVar6 = (uVar14 - 0x10 & 0xfffffff0) + 0x10;
    local_60 = (uint *)((int)param_3 + iVar6);
    param_2 = (uint *)((int)param_2 + iVar6);
    if ((bVar3 & 0xf) != 0) {
LAB_000ed59a:
      local_68 = local_48;
      uVar8 = param_4 >> 2;
      iVar6 = 1 - uVar8;
      puVar11 = (uint *)(param_1 + 0x10);
      if (1 < uVar8) {
        iVar6 = 0;
      }
      puVar17 = param_2 + 1;
      bVar19 = param_2 <= param_1 + 0x14;
      bVar18 = (uint *)(param_1 + 0x14) == param_2;
      if (bVar19 && !bVar18) {
        bVar19 = puVar11 <= puVar17;
        bVar18 = puVar17 == puVar11;
      }
      uVar14 = uVar8 * 4;
      if (iVar6 != 0 || (param_4 < 4 || (bVar19 && !bVar18 || ((uint)param_2 & 3) != 0))) {
        uVar5 = 0;
LAB_000ed610:
        do {
          uVar7 = uVar5 + 1;
          param_1[uVar5 + 0x10] = param_1[uVar5 + 0x10] ^ *(byte *)((int)param_2 + uVar5);
          uVar5 = uVar7;
        } while (uVar7 < param_4);
      }
      else {
        uVar5 = 0;
        iVar10 = 0;
        do {
          uVar5 = uVar5 + 1;
          *(uint *)((int)puVar11 + iVar10) =
               *(uint *)((int)param_2 + iVar10) ^ *(uint *)((int)puVar11 + iVar10);
          iVar10 = iVar10 + 4;
        } while (uVar5 < uVar8);
        uVar5 = uVar14;
        if (param_4 != uVar14) goto LAB_000ed610;
      }
      (*pcVar13)(puVar11,puVar11,uVar15);
      (*pcVar13)(param_1,local_68,uVar15);
      puVar11 = local_60 + 1;
      bVar19 = local_60 <= local_48 + 1;
      bVar18 = local_48 + 1 == local_60;
      if (bVar19 && !bVar18) {
        bVar19 = local_68 <= puVar11;
        bVar18 = puVar11 == local_68;
      }
      if (iVar6 != 0 ||
          ((((uint)local_60 | (uint)param_2) & 3) != 0 ||
          (param_4 < 4 || (bVar19 && !bVar18 || local_60 < puVar17 && param_2 < puVar11)))) {
        uVar14 = 0;
      }
      else {
        iVar6 = 0;
        uVar5 = 0;
        do {
          uVar5 = uVar5 + 1;
          *(uint *)((int)local_60 + iVar6) =
               *(uint *)((int)param_2 + iVar6) ^ *(uint *)((int)local_68 + iVar6);
          iVar6 = iVar6 + 4;
        } while (uVar5 < uVar8);
        if (param_4 == uVar14) goto LAB_000ed6b0;
      }
      do {
        *(byte *)((int)local_60 + uVar14) =
             *(byte *)((int)local_68 + uVar14) ^ *(byte *)((int)param_2 + uVar14);
        uVar14 = uVar14 + 1;
      } while (uVar14 < param_4);
    }
  }
LAB_000ed6b0:
  local_68 = local_48;
  uVar14 = ~uVar16 + 0x11;
  uVar8 = -(int)(param_1 + uVar16) & 3U;
  if (uVar14 <= (-(int)(param_1 + uVar16) & 3U)) {
    uVar8 = uVar14;
  }
  if (uVar14 < 4) {
    uVar8 = uVar14;
  }
  uVar5 = uVar16;
  if (uVar8 != 0) {
    do {
      param_1[uVar5] = 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 - uVar16 < uVar8);
    if (uVar14 == uVar8) goto LAB_000ed764;
  }
  uVar7 = uVar14 - uVar8 >> 2;
  if (uVar7 != 0) {
    pbVar12 = param_1 + uVar8 + uVar16;
    if (uVar7 < 9) {
      uVar16 = 0;
    }
    else {
      uVar16 = 0;
      pbVar4 = pbVar12;
      do {
        pbVar12 = pbVar4 + 0x20;
        uVar9 = uVar16 + 9;
        uVar16 = uVar16 + 8;
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
        pbVar4 = pbVar12;
      } while (uVar9 < uVar7 - 7);
    }
    do {
      uVar16 = uVar16 + 1;
      pbVar12[0] = 0;
      pbVar12[1] = 0;
      pbVar12[2] = 0;
      pbVar12[3] = 0;
      pbVar12 = pbVar12 + 4;
    } while (uVar16 < uVar7);
    uVar5 = uVar5 + uVar7 * 4;
    if (uVar14 - uVar8 == uVar7 * 4) goto LAB_000ed764;
  }
  do {
    param_1[uVar5] = 0;
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0x10);
LAB_000ed764:
  (*pcVar13)(param_1,local_68,uVar15);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_48[0] ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_48[1] ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_48[2];
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_48[3];
  return 0;
}


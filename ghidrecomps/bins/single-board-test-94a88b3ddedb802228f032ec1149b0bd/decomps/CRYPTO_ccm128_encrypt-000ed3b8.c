
undefined4 CRYPTO_ccm128_encrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 *puVar11;
  code *pcVar12;
  uint uVar13;
  undefined4 uVar14;
  uint uVar15;
  uint *puVar16;
  bool bVar17;
  bool bVar18;
  uint *local_68;
  uint *local_60;
  uint local_48 [4];
  uint local_38;
  uint uStack_34;
  uint local_30;
  uint uStack_2c;
  
  bVar1 = *param_1;
  pcVar12 = *(code **)(param_1 + 0x28);
  uVar14 = *(undefined4 *)(param_1 + 0x2c);
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar12)(param_1,param_1 + 0x10,uVar14);
    uVar8 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar8 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar8);
  }
  uVar8 = bVar1 & 7;
  uVar13 = 0;
  uVar15 = 0xf - uVar8;
  *param_1 = (byte)uVar8;
  uVar8 = uVar15;
  if ((bVar1 & 7) != 0) {
    do {
      bVar3 = param_1[uVar8];
      param_1[uVar8] = 0;
      uVar8 = uVar8 + 1;
      uVar13 = (uVar13 | bVar3) << 8;
    } while (uVar8 != 0xf);
  }
  bVar3 = param_1[0xf];
  param_1[0xf] = 1;
  uVar13 = bVar3 | uVar13;
  if (uVar13 != param_4) {
    return 0xffffffff;
  }
  uVar8 = param_4 + 0xf >> 3 | 1;
  iVar6 = *(uint *)(param_1 + 0x20) + uVar8;
  uVar8 = *(int *)(param_1 + 0x24) + (uint)CARRY4(*(uint *)(param_1 + 0x20),uVar8);
  bVar17 = 0x1fffffff < uVar8;
  if (uVar8 == 0x20000000) {
    bVar17 = iVar6 != 0;
  }
  *(int *)(param_1 + 0x20) = iVar6;
  *(uint *)(param_1 + 0x24) = uVar8;
  if (bVar17) {
    return 0xfffffffe;
  }
  if (param_4 < 0x10) {
    local_60 = param_3;
    if (param_4 != 0) goto LAB_000ed59a;
  }
  else {
    puVar10 = param_3 + 8;
    puVar16 = param_2 + 8;
    do {
      uVar8 = puVar16[-8];
      param_4 = param_4 - 0x10;
      HintPreloadData(puVar16);
      HintPreloadData(puVar10);
      uVar5 = puVar16[-7];
      uVar7 = puVar16[-6];
      uVar9 = puVar16[-5];
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ uVar8;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ uVar5;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ uVar7;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ uVar9;
      local_38 = uVar8;
      uStack_34 = uVar5;
      local_30 = uVar7;
      uStack_2c = uVar9;
      (*pcVar12)(param_1 + 0x10,param_1 + 0x10,uVar14);
      (*pcVar12)(param_1,local_48,uVar14);
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
      puVar10[-8] = local_38;
      puVar10[-7] = uStack_34;
      puVar10[-6] = local_30;
      puVar10[-5] = uStack_2c;
      puVar10 = puVar10 + 4;
      puVar16 = puVar16 + 4;
    } while (0xf < param_4);
    param_4 = bVar3 & 0xf;
    iVar6 = (uVar13 - 0x10 & 0xfffffff0) + 0x10;
    local_60 = (uint *)((int)param_3 + iVar6);
    param_2 = (uint *)((int)param_2 + iVar6);
    if ((bVar3 & 0xf) != 0) {
LAB_000ed59a:
      local_68 = local_48;
      uVar8 = param_4 >> 2;
      uVar13 = 1 - uVar8;
      puVar10 = (uint *)(param_1 + 0x10);
      if (1 < uVar8) {
        uVar13 = 0;
      }
      puVar16 = param_2 + 1;
      bVar18 = param_2 <= param_1 + 0x14;
      bVar17 = (uint *)(param_1 + 0x14) == param_2;
      if (bVar18 && !bVar17) {
        bVar18 = puVar10 <= puVar16;
        bVar17 = puVar16 == puVar10;
      }
      uVar5 = param_4 & 0xfffffffc;
      if ((uVar13 | (3 < param_4 && ((!bVar18 || bVar17) && ((uint)param_2 & 3) == 0)) ^ 1) == 0) {
        uVar7 = 0;
        iVar6 = 0;
        do {
          uVar7 = uVar7 + 1;
          *(uint *)((int)puVar10 + iVar6) =
               *(uint *)((int)param_2 + iVar6) ^ *(uint *)((int)puVar10 + iVar6);
          iVar6 = iVar6 + 4;
        } while (uVar7 < uVar8);
        uVar7 = uVar5;
        if (param_4 != uVar5) goto LAB_000ed610;
      }
      else {
        uVar7 = 0;
LAB_000ed610:
        do {
          uVar9 = uVar7 + 1;
          param_1[uVar7 + 0x10] = param_1[uVar7 + 0x10] ^ *(byte *)((int)param_2 + uVar7);
          uVar7 = uVar9;
        } while (uVar9 < param_4);
      }
      (*pcVar12)(puVar10,puVar10,uVar14);
      (*pcVar12)(param_1,local_68,uVar14);
      puVar10 = local_60 + 1;
      bVar18 = local_60 <= local_48 + 1;
      bVar17 = local_48 + 1 == local_60;
      if (bVar18 && !bVar17) {
        bVar18 = local_68 <= puVar10;
        bVar17 = puVar10 == local_68;
      }
      uVar7 = (uint)(3 < param_4 &&
                    ((!bVar18 || bVar17) && (puVar16 <= local_60 || puVar10 <= param_2)));
      if ((((uint)local_60 | (uint)param_2) & 3) != 0) {
        uVar7 = 0;
      }
      if ((uVar13 | uVar7 ^ 1) == 0) {
        iVar6 = 0;
        uVar13 = 0;
        do {
          uVar13 = uVar13 + 1;
          *(uint *)((int)local_60 + iVar6) =
               *(uint *)((int)param_2 + iVar6) ^ *(uint *)((int)local_68 + iVar6);
          iVar6 = iVar6 + 4;
        } while (uVar13 < uVar8);
        if (param_4 == uVar5) goto LAB_000ed6b0;
      }
      else {
        uVar5 = 0;
      }
      do {
        *(byte *)((int)local_60 + uVar5) =
             *(byte *)((int)local_68 + uVar5) ^ *(byte *)((int)param_2 + uVar5);
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_4);
    }
  }
LAB_000ed6b0:
  local_68 = local_48;
  uVar13 = ~uVar15 + 0x11;
  uVar8 = -(int)(param_1 + uVar15) & 3U;
  if (uVar13 <= (-(int)(param_1 + uVar15) & 3U)) {
    uVar8 = uVar13;
  }
  if (uVar13 < 4) {
    uVar8 = uVar13;
  }
  uVar5 = uVar15;
  if (uVar8 != 0) {
    do {
      param_1[uVar5] = 0;
      uVar5 = uVar5 + 1;
    } while (uVar5 - uVar15 < uVar8);
    if (uVar13 == uVar8) goto LAB_000ed764;
  }
  uVar13 = uVar13 - uVar8;
  uVar7 = uVar13 >> 2;
  if (uVar7 != 0) {
    puVar11 = (undefined4 *)(param_1 + uVar8 + uVar15);
    if (uVar7 < 9) {
      uVar8 = 0;
    }
    else {
      uVar8 = 0;
      puVar4 = puVar11;
      do {
        puVar11 = puVar4 + 8;
        uVar15 = uVar8 + 9;
        uVar8 = uVar8 + 8;
        HintPreloadData(puVar4 + 0x28);
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4[2] = 0;
        puVar4[3] = 0;
        puVar4[4] = 0;
        puVar4[5] = 0;
        puVar4[6] = 0;
        puVar4[7] = 0;
        puVar4 = puVar11;
      } while (uVar15 < uVar7 - 7);
    }
    do {
      uVar8 = uVar8 + 1;
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    } while (uVar8 < uVar7);
    uVar5 = uVar5 + (uVar13 & 0xfffffffc);
    if (uVar13 == (uVar13 & 0xfffffffc)) goto LAB_000ed764;
  }
  do {
    param_1[uVar5] = 0;
    uVar5 = uVar5 + 1;
  } while (uVar5 != 0x10);
LAB_000ed764:
  (*pcVar12)(param_1,local_68,uVar14);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_48[0] ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_48[1] ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_48[2];
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_48[3];
  return 0;
}


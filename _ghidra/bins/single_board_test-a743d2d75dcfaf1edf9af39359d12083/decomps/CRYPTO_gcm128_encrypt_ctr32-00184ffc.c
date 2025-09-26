
undefined4
CRYPTO_gcm128_encrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint uVar13;
  byte bVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  uint uVar18;
  uint *puVar19;
  uint uVar20;
  uint uVar21;
  byte bVar22;
  uint uVar23;
  bool bVar24;
  uint *local_40;
  int local_3c;
  
  uVar8 = *(undefined4 *)(param_1 + 0x174);
  uVar18 = *(uint *)(param_1 + 0x38) + param_4;
  uVar20 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar24 = uVar20 < 0x10;
  if (uVar20 == 0xf) {
    bVar24 = uVar18 < 0xffffffe1;
  }
  if (!bVar24) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar18;
  *(uint *)(param_1 + 0x3c) = uVar20;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  bVar14 = *(byte *)(param_1 + 0xe);
  bVar2 = *(byte *)(param_1 + 0xf);
  uVar18 = *(uint *)(param_1 + 0x168);
  bVar3 = *(byte *)(param_1 + 0xd);
  puVar12 = param_3;
  puVar9 = param_2;
  if (uVar18 != 0) {
    if (param_4 == 0) {
LAB_0018509c:
      *(uint *)(param_1 + 0x168) = uVar18;
      return 0;
    }
    do {
      iVar16 = param_1 + uVar18;
      puVar9 = (uint *)((int)param_2 + 1);
      bVar4 = *(byte *)(iVar16 + 0x40);
      uVar20 = uVar18 + 1 & 0xf;
      if (uVar20 != 0) {
        uVar20 = 1;
      }
      param_4 = param_4 - 1;
      bVar22 = (byte)*param_2 ^ *(byte *)(iVar16 + 0x10);
      if (param_4 == 0) {
        uVar20 = 0;
      }
      else {
        uVar20 = uVar20 & 1;
      }
      puVar12 = (uint *)((int)param_3 + 1);
      *(byte *)param_3 = bVar22;
      uVar18 = uVar18 + 1 & 0xf;
      *(byte *)(iVar16 + 0x40) = bVar4 ^ bVar22;
      param_2 = puVar9;
      param_3 = puVar12;
    } while (uVar20 != 0);
    if (uVar18 != 0) goto LAB_0018509c;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  uVar18 = (uint)bVar3 << 0x10 | (uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar14 << 8;
  if (0xbff < param_4) {
    puVar19 = puVar12;
    do {
      uVar18 = uVar18 + 0xc0;
      param_4 = param_4 - 0xc00;
      (*param_5)(puVar9,puVar19,0xc0,uVar8,param_1);
      *(char *)(param_1 + 0xf) = (char)uVar18;
      *(char *)(param_1 + 0xc) = (char)(uVar18 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)(uVar18 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar18 >> 8);
      puVar9 = puVar9 + 0x300;
      puVar12 = puVar19 + 0x300;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar19);
      puVar19 = puVar12;
    } while (0xbff < param_4);
  }
  uVar20 = param_4 & 0xfffffff0;
  if (uVar20 != 0) {
    uVar23 = param_4 >> 4;
    uVar18 = uVar18 + uVar23;
    param_4 = param_4 - uVar20;
    (*param_5)(puVar9,puVar12,uVar23,uVar8,param_1);
    *(char *)(param_1 + 0xf) = (char)uVar18;
    *(char *)(param_1 + 0xc) = (char)(uVar18 >> 0x18);
    *(char *)(param_1 + 0xd) = (char)(uVar18 >> 0x10);
    *(char *)(param_1 + 0xe) = (char)(uVar18 >> 8);
    puVar9 = (uint *)((int)puVar9 + uVar20);
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar12,uVar20);
    puVar12 = (uint *)((int)puVar12 + uVar20);
  }
  if (param_4 != 0) {
    puVar19 = (uint *)(param_1 + 0x10);
    iVar16 = uVar18 + 1;
    (**(code **)(param_1 + 0x170))(param_1,puVar19,uVar8);
    local_40 = (uint *)(param_1 + 0x40);
    puVar11 = puVar12 + 1;
    *(char *)(param_1 + 0xf) = (char)iVar16;
    uVar20 = param_4 >> 2;
    *(char *)(param_1 + 0xd) = (char)((uint)iVar16 >> 0x10);
    local_3c = param_4 - 1;
    uVar18 = uVar20 * 4;
    *(char *)(param_1 + 0xc) = (char)((uint)iVar16 >> 0x18);
    *(char *)(param_1 + 0xe) = (char)((uint)iVar16 >> 8);
    if (uVar20 == 0 ||
        ((((uint)puVar9 | (uint)puVar12) & 3) != 0 ||
        (((param_4 < 4 ||
          (local_40 < puVar11 && puVar12 < (uint *)(param_1 + 0x44) ||
          puVar12 < puVar9 + 1 && puVar9 < puVar11)) ||
         puVar9 < (uint *)(param_1 + 0x44) && local_40 < puVar9 + 1) ||
        puVar12 < (uint *)(param_1 + 0x14) && puVar19 < puVar11))) {
      uVar18 = 0;
    }
    else {
      if (uVar20 < 9) {
        uVar23 = 0;
        puVar11 = puVar9;
        puVar17 = puVar12;
      }
      else {
        uVar23 = 0;
        puVar7 = (uint *)(param_1 + 0x60);
        puVar5 = puVar9;
        puVar6 = puVar12;
        do {
          local_40 = puVar7;
          puVar17 = puVar6 + 8;
          puVar11 = puVar5 + 8;
          uVar13 = *puVar5;
          uVar21 = uVar23 + 9;
          uVar10 = local_40[-0x14];
          uVar15 = local_40[-8];
          uVar23 = uVar23 + 8;
          HintPreloadData(local_40 + 6);
          HintPreloadData(puVar5 + 0xe);
          *puVar6 = uVar13 ^ uVar10;
          local_40[-8] = uVar13 ^ uVar10 ^ uVar15;
          uVar13 = puVar5[1];
          uVar10 = local_40[-0x13];
          uVar15 = local_40[-7];
          puVar6[1] = uVar10 ^ uVar13;
          local_40[-7] = uVar10 ^ uVar13 ^ uVar15;
          uVar13 = local_40[-0x12];
          uVar10 = puVar5[2];
          uVar15 = local_40[-6];
          puVar6[2] = uVar10 ^ uVar13;
          local_40[-6] = uVar10 ^ uVar13 ^ uVar15;
          uVar13 = local_40[-0x11];
          uVar10 = puVar5[3];
          uVar15 = local_40[-5];
          puVar6[3] = uVar10 ^ uVar13;
          local_40[-5] = uVar10 ^ uVar13 ^ uVar15;
          uVar13 = local_40[-0x10];
          uVar10 = puVar5[4];
          uVar15 = local_40[-4];
          puVar6[4] = uVar10 ^ uVar13;
          local_40[-4] = uVar10 ^ uVar13 ^ uVar15;
          uVar10 = local_40[-0xf];
          uVar13 = puVar5[5];
          uVar15 = local_40[-3];
          puVar6[5] = uVar10 ^ uVar13;
          local_40[-3] = uVar10 ^ uVar13 ^ uVar15;
          uVar10 = local_40[-0xe];
          uVar13 = puVar5[6];
          uVar15 = local_40[-2];
          puVar6[6] = uVar10 ^ uVar13;
          local_40[-2] = uVar10 ^ uVar13 ^ uVar15;
          uVar13 = local_40[-0xd];
          uVar10 = puVar5[7];
          uVar15 = local_40[-1];
          puVar6[7] = uVar13 ^ uVar10;
          local_40[-1] = uVar13 ^ uVar10 ^ uVar15;
          puVar19 = local_40 + -0xc;
          puVar7 = local_40 + 8;
          puVar5 = puVar11;
          puVar6 = puVar17;
        } while (uVar21 < uVar20 - 7);
      }
      iVar16 = 0;
      do {
        uVar23 = uVar23 + 1;
        uVar10 = *(uint *)((int)puVar11 + iVar16) ^ *(uint *)((int)puVar19 + iVar16);
        uVar13 = *(uint *)((int)local_40 + iVar16);
        *(uint *)((int)puVar17 + iVar16) = uVar10;
        *(uint *)((int)local_40 + iVar16) = uVar10 ^ uVar13;
        iVar16 = iVar16 + 4;
      } while (uVar23 < uVar20);
      local_3c = local_3c + uVar20 * -4;
      if (param_4 == uVar18) goto LAB_00185128;
    }
    local_3c = uVar18 + local_3c;
    do {
      iVar16 = param_1 + uVar18;
      bVar1 = *(byte *)(iVar16 + 0x40);
      bVar14 = *(byte *)((int)puVar9 + uVar18) ^ *(byte *)(iVar16 + 0x10);
      *(byte *)((int)puVar12 + uVar18) = bVar14;
      uVar18 = uVar18 + 1;
      *(byte *)(iVar16 + 0x40) = bVar14 ^ bVar1;
    } while (uVar18 != local_3c + 1U);
  }
LAB_00185128:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}


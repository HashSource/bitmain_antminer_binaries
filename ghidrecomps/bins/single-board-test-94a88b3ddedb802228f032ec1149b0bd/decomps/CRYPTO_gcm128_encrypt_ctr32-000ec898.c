
undefined4
CRYPTO_gcm128_encrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  byte bVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  bool bVar24;
  uint *local_40;
  int local_3c;
  
  uVar9 = *(undefined4 *)(param_1 + 0x174);
  uVar19 = *(uint *)(param_1 + 0x38) + param_4;
  uVar21 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar24 = uVar21 < 0x10;
  if (uVar21 == 0xf) {
    bVar24 = uVar19 < 0xffffffe1;
  }
  if (!bVar24) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar19;
  *(uint *)(param_1 + 0x3c) = uVar21;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  bVar15 = *(byte *)(param_1 + 0xe);
  bVar2 = *(byte *)(param_1 + 0xf);
  uVar19 = *(uint *)(param_1 + 0x168);
  bVar3 = *(byte *)(param_1 + 0xd);
  puVar13 = param_3;
  puVar10 = param_2;
  if (uVar19 != 0) {
    if (param_4 == 0) {
LAB_000ec938:
      *(uint *)(param_1 + 0x168) = uVar19;
      return 0;
    }
    do {
      iVar17 = param_1 + uVar19;
      puVar10 = (uint *)((int)param_2 + 1);
      bVar4 = *(byte *)(iVar17 + 0x40);
      uVar21 = uVar19 + 1 & 0xf;
      if (uVar21 != 0) {
        uVar21 = 1;
      }
      param_4 = param_4 - 1;
      bVar5 = *(byte *)param_2 ^ *(byte *)(iVar17 + 0x10);
      if (param_4 == 0) {
        uVar21 = 0;
      }
      else {
        uVar21 = uVar21 & 1;
      }
      puVar13 = (uint *)((int)param_3 + 1);
      *(byte *)param_3 = bVar5;
      uVar19 = uVar19 + 1 & 0xf;
      *(byte *)(iVar17 + 0x40) = bVar4 ^ bVar5;
      param_2 = puVar10;
      param_3 = puVar13;
    } while (uVar21 != 0);
    if (uVar19 != 0) goto LAB_000ec938;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  uVar19 = (uint)bVar3 << 0x10 | (uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar15 << 8;
  if (0xbff < param_4) {
    puVar20 = puVar13;
    do {
      uVar19 = uVar19 + 0xc0;
      param_4 = param_4 - 0xc00;
      (*param_5)(puVar10,puVar20,0xc0,uVar9,param_1);
      *(char *)(param_1 + 0xf) = (char)uVar19;
      *(char *)(param_1 + 0xc) = (char)(uVar19 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)(uVar19 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar19 >> 8);
      puVar10 = puVar10 + 0x300;
      puVar13 = puVar20 + 0x300;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar20);
      puVar20 = puVar13;
    } while (0xbff < param_4);
  }
  uVar21 = param_4 & 0xfffffff0;
  if (uVar21 != 0) {
    uVar23 = param_4 >> 4;
    uVar19 = uVar19 + uVar23;
    param_4 = param_4 - uVar21;
    (*param_5)(puVar10,puVar13,uVar23,uVar9,param_1);
    *(char *)(param_1 + 0xf) = (char)uVar19;
    *(char *)(param_1 + 0xc) = (char)(uVar19 >> 0x18);
    *(char *)(param_1 + 0xd) = (char)(uVar19 >> 0x10);
    *(char *)(param_1 + 0xe) = (char)(uVar19 >> 8);
    puVar10 = (uint *)((int)puVar10 + uVar21);
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar13,uVar21);
    puVar13 = (uint *)((int)puVar13 + uVar21);
  }
  if (param_4 != 0) {
    puVar20 = (uint *)(param_1 + 0x10);
    iVar17 = uVar19 + 1;
    (**(code **)(param_1 + 0x170))(param_1,puVar20,uVar9);
    local_40 = (uint *)(param_1 + 0x40);
    puVar12 = puVar13 + 1;
    *(char *)(param_1 + 0xf) = (char)iVar17;
    uVar21 = param_4 >> 2;
    *(char *)(param_1 + 0xd) = (char)((uint)iVar17 >> 0x10);
    local_3c = param_4 - 1;
    uVar19 = param_4 & 0xfffffffc;
    *(char *)(param_1 + 0xc) = (char)((uint)iVar17 >> 0x18);
    *(char *)(param_1 + 0xe) = (char)((uint)iVar17 >> 8);
    if (uVar21 == 0 ||
        ((((uint)puVar10 | (uint)puVar13) & 3) != 0 ||
        (((param_4 < 4 ||
          (local_40 < puVar12 && puVar13 < (uint *)(param_1 + 0x44) ||
          puVar13 < puVar10 + 1 && puVar10 < puVar12)) ||
         puVar10 < (uint *)(param_1 + 0x44) && local_40 < puVar10 + 1) ||
        puVar13 < (uint *)(param_1 + 0x14) && puVar20 < puVar12))) {
      uVar19 = 0;
    }
    else {
      if (uVar21 < 9) {
        uVar23 = 0;
        puVar12 = puVar10;
        puVar18 = puVar13;
      }
      else {
        uVar23 = 0;
        puVar8 = (uint *)(param_1 + 0x60);
        puVar6 = puVar10;
        puVar7 = puVar13;
        do {
          local_40 = puVar8;
          puVar18 = puVar7 + 8;
          puVar12 = puVar6 + 8;
          uVar14 = *puVar6;
          uVar22 = uVar23 + 9;
          uVar11 = local_40[-0x14];
          uVar16 = local_40[-8];
          uVar23 = uVar23 + 8;
          HintPreloadData(local_40 + 6);
          HintPreloadData(puVar6 + 0xe);
          *puVar7 = uVar14 ^ uVar11;
          local_40[-8] = uVar14 ^ uVar11 ^ uVar16;
          uVar14 = puVar6[1];
          uVar11 = local_40[-0x13];
          uVar16 = local_40[-7];
          puVar7[1] = uVar11 ^ uVar14;
          local_40[-7] = uVar11 ^ uVar14 ^ uVar16;
          uVar14 = local_40[-0x12];
          uVar11 = puVar6[2];
          uVar16 = local_40[-6];
          puVar7[2] = uVar11 ^ uVar14;
          local_40[-6] = uVar11 ^ uVar14 ^ uVar16;
          uVar14 = local_40[-0x11];
          uVar11 = puVar6[3];
          uVar16 = local_40[-5];
          puVar7[3] = uVar11 ^ uVar14;
          local_40[-5] = uVar11 ^ uVar14 ^ uVar16;
          uVar14 = local_40[-0x10];
          uVar11 = puVar6[4];
          uVar16 = local_40[-4];
          puVar7[4] = uVar11 ^ uVar14;
          local_40[-4] = uVar11 ^ uVar14 ^ uVar16;
          uVar11 = local_40[-0xf];
          uVar14 = puVar6[5];
          uVar16 = local_40[-3];
          puVar7[5] = uVar11 ^ uVar14;
          local_40[-3] = uVar11 ^ uVar14 ^ uVar16;
          uVar11 = local_40[-0xe];
          uVar14 = puVar6[6];
          uVar16 = local_40[-2];
          puVar7[6] = uVar11 ^ uVar14;
          local_40[-2] = uVar11 ^ uVar14 ^ uVar16;
          uVar14 = local_40[-0xd];
          uVar11 = puVar6[7];
          uVar16 = local_40[-1];
          puVar7[7] = uVar14 ^ uVar11;
          local_40[-1] = uVar14 ^ uVar11 ^ uVar16;
          puVar20 = local_40 + -0xc;
          puVar8 = local_40 + 8;
          puVar6 = puVar12;
          puVar7 = puVar18;
        } while (uVar22 < uVar21 - 7);
      }
      iVar17 = 0;
      do {
        uVar23 = uVar23 + 1;
        uVar11 = *(uint *)((int)puVar12 + iVar17) ^ *(uint *)((int)puVar20 + iVar17);
        uVar14 = *(uint *)((int)local_40 + iVar17);
        *(uint *)((int)puVar18 + iVar17) = uVar11;
        *(uint *)((int)local_40 + iVar17) = uVar11 ^ uVar14;
        iVar17 = iVar17 + 4;
      } while (uVar23 < uVar21);
      local_3c = local_3c - uVar19;
      if (param_4 == uVar19) goto LAB_000ec9c4;
    }
    local_3c = uVar19 + local_3c;
    do {
      iVar17 = param_1 + uVar19;
      bVar1 = *(byte *)(iVar17 + 0x40);
      bVar15 = *(byte *)((int)puVar10 + uVar19) ^ *(byte *)(iVar17 + 0x10);
      *(byte *)((int)puVar13 + uVar19) = bVar15;
      uVar19 = uVar19 + 1;
      *(byte *)(iVar17 + 0x40) = bVar15 ^ bVar1;
    } while (uVar19 != local_3c + 1U);
  }
LAB_000ec9c4:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}


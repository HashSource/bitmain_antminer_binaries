
undefined4
CRYPTO_gcm128_decrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

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
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  uint uVar14;
  uint *puVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  bool bVar20;
  int local_40;
  
  uVar9 = *(undefined4 *)(param_1 + 0x174);
  uVar12 = *(uint *)(param_1 + 0x38) + param_4;
  uVar14 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar20 = uVar14 < 0x10;
  if (uVar14 == 0xf) {
    bVar20 = uVar12 < 0xffffffe1;
  }
  if (!bVar20) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar12;
  *(uint *)(param_1 + 0x3c) = uVar14;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar12 = *(uint *)(param_1 + 0x168);
  bVar1 = *(byte *)(param_1 + 0xc);
  bVar2 = *(byte *)(param_1 + 0xd);
  bVar3 = *(byte *)(param_1 + 0xe);
  bVar4 = *(byte *)(param_1 + 0xf);
  if (uVar12 != 0) {
    puVar13 = param_2;
    puVar11 = param_3;
    if (param_4 == 0) {
LAB_000ecdd6:
      *(uint *)(param_1 + 0x168) = uVar12;
      return 0;
    }
    do {
      iVar16 = param_1 + uVar12;
      param_2 = (uint *)((int)puVar13 + 1);
      bVar5 = *(byte *)puVar13;
      uVar12 = uVar12 + 1 & 0xf;
      uVar14 = uVar12;
      if (uVar12 != 0) {
        uVar14 = 1;
      }
      param_4 = param_4 - 1;
      param_3 = (uint *)((int)puVar11 + 1);
      *(byte *)puVar11 = *(byte *)(iVar16 + 0x10) ^ bVar5;
      if (param_4 == 0) {
        uVar14 = 0;
      }
      else {
        uVar14 = uVar14 & 1;
      }
      *(byte *)(iVar16 + 0x40) = bVar5 ^ *(byte *)(iVar16 + 0x40);
      puVar13 = param_2;
      puVar11 = param_3;
    } while (uVar14 != 0);
    if (uVar12 != 0) goto LAB_000ecdd6;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  uVar12 = (uint)bVar2 << 0x10 | (uint)bVar1 << 0x18 | (uint)bVar4 | (uint)bVar3 << 8;
  if (0xbff < param_4) {
    puVar13 = param_2;
    puVar11 = param_3;
    do {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar13,0xc00);
      uVar12 = uVar12 + 0xc0;
      param_4 = param_4 - 0xc00;
      param_2 = puVar13 + 0x300;
      param_3 = puVar11 + 0x300;
      (*param_5)(puVar13,puVar11,0xc0,uVar9,param_1);
      *(char *)(param_1 + 0xf) = (char)uVar12;
      *(char *)(param_1 + 0xc) = (char)(uVar12 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)(uVar12 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar12 >> 8);
      puVar13 = param_2;
      puVar11 = param_3;
    } while (0xbff < param_4);
  }
  uVar14 = param_4 & 0xfffffff0;
  if (uVar14 != 0) {
    uVar19 = param_4 >> 4;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,uVar14);
    uVar12 = uVar12 + uVar19;
    param_4 = param_4 - uVar14;
    (*param_5)(param_2,param_3,uVar19,uVar9,param_1);
    *(char *)(param_1 + 0xf) = (char)uVar12;
    *(char *)(param_1 + 0xc) = (char)(uVar12 >> 0x18);
    *(char *)(param_1 + 0xd) = (char)(uVar12 >> 0x10);
    *(char *)(param_1 + 0xe) = (char)(uVar12 >> 8);
    param_2 = (uint *)((int)param_2 + uVar14);
    param_3 = (uint *)((int)param_3 + uVar14);
  }
  if (param_4 != 0) {
    puVar13 = (uint *)(param_1 + 0x10);
    puVar15 = (uint *)(param_1 + 0x40);
    (**(code **)(param_1 + 0x170))(param_1,puVar13,uVar9);
    puVar11 = param_3 + 1;
    iVar16 = uVar12 + 1;
    uVar12 = param_4 >> 2;
    *(char *)(param_1 + 0xf) = (char)iVar16;
    *(char *)(param_1 + 0xd) = (char)((uint)iVar16 >> 0x10);
    local_40 = param_4 - 1;
    *(char *)(param_1 + 0xc) = (char)((uint)iVar16 >> 0x18);
    uVar14 = param_4 & 0xfffffffc;
    *(char *)(param_1 + 0xe) = (char)((uint)iVar16 >> 8);
    if (uVar12 == 0 ||
        ((((uint)param_2 | (uint)param_3) & 3) != 0 ||
        (((param_4 < 4 ||
          (puVar15 < param_2 + 1 && param_2 < (uint *)(param_1 + 0x44) ||
          param_3 < param_2 + 1 && param_2 < puVar11)) ||
         param_3 < (uint *)(param_1 + 0x44) && puVar15 < puVar11) ||
        param_3 < (uint *)(param_1 + 0x14) && puVar13 < puVar11))) {
      uVar14 = 0;
    }
    else {
      if (uVar12 < 9) {
        uVar19 = 0;
        puVar11 = param_3;
        puVar18 = param_2;
      }
      else {
        uVar19 = 0;
        puVar8 = (uint *)(param_1 + 0x60);
        puVar6 = param_3;
        puVar7 = param_2;
        do {
          puVar15 = puVar8;
          puVar18 = puVar7 + 8;
          puVar11 = puVar6 + 8;
          uVar10 = *puVar7;
          uVar17 = uVar19 + 9;
          uVar19 = uVar19 + 8;
          HintPreloadData(puVar7 + 0xe);
          HintPreloadData(puVar15 + 6);
          puVar15[-8] = puVar15[-8] ^ uVar10;
          *puVar6 = puVar15[-0x14] ^ uVar10;
          uVar10 = puVar7[1];
          puVar13 = puVar15 + -0xc;
          puVar15[-7] = puVar15[-7] ^ uVar10;
          puVar6[1] = puVar15[-0x13] ^ uVar10;
          uVar10 = puVar7[2];
          puVar15[-6] = puVar15[-6] ^ uVar10;
          puVar6[2] = puVar15[-0x12] ^ uVar10;
          uVar10 = puVar7[3];
          puVar15[-5] = puVar15[-5] ^ uVar10;
          puVar6[3] = puVar15[-0x11] ^ uVar10;
          uVar10 = puVar7[4];
          puVar15[-4] = puVar15[-4] ^ uVar10;
          puVar6[4] = puVar15[-0x10] ^ uVar10;
          uVar10 = puVar7[5];
          puVar15[-3] = puVar15[-3] ^ uVar10;
          puVar6[5] = puVar15[-0xf] ^ uVar10;
          uVar10 = puVar7[6];
          puVar15[-2] = puVar15[-2] ^ uVar10;
          puVar6[6] = puVar15[-0xe] ^ uVar10;
          uVar10 = puVar7[7];
          puVar15[-1] = puVar15[-1] ^ uVar10;
          puVar6[7] = puVar15[-0xd] ^ uVar10;
          puVar8 = puVar15 + 8;
          puVar6 = puVar11;
          puVar7 = puVar18;
        } while (uVar17 < uVar12 - 7);
      }
      iVar16 = 0;
      do {
        uVar10 = *(uint *)((int)puVar18 + iVar16);
        uVar19 = uVar19 + 1;
        *(uint *)((int)puVar15 + iVar16) = uVar10 ^ *(uint *)((int)puVar15 + iVar16);
        *(uint *)((int)puVar11 + iVar16) = uVar10 ^ *(uint *)((int)puVar13 + iVar16);
        iVar16 = iVar16 + 4;
      } while (uVar19 < uVar12);
      local_40 = local_40 - uVar14;
      if (param_4 == uVar14) goto LAB_000ecd88;
    }
    local_40 = uVar14 + local_40;
    do {
      iVar16 = param_1 + uVar14;
      bVar1 = *(byte *)((int)param_2 + uVar14);
      *(byte *)(iVar16 + 0x40) = *(byte *)(iVar16 + 0x40) ^ bVar1;
      *(byte *)((int)param_3 + uVar14) = bVar1 ^ *(byte *)(iVar16 + 0x10);
      uVar14 = uVar14 + 1;
    } while (uVar14 != local_40 + 1U);
  }
LAB_000ecd88:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}


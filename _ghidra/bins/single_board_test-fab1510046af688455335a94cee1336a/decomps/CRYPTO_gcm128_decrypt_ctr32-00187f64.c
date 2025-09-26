
undefined4
CRYPTO_gcm128_decrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint *puVar14;
  int iVar15;
  uint uVar16;
  uint *puVar17;
  uint uVar18;
  bool bVar19;
  int local_40;
  
  uVar8 = *(undefined4 *)(param_1 + 0x174);
  uVar11 = *(uint *)(param_1 + 0x38) + param_4;
  uVar13 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar19 = uVar13 < 0x10;
  if (uVar13 == 0xf) {
    bVar19 = uVar11 < 0xffffffe1;
  }
  if (!bVar19) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar11;
  *(uint *)(param_1 + 0x3c) = uVar13;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar11 = *(uint *)(param_1 + 0x168);
  bVar1 = *(byte *)(param_1 + 0xc);
  bVar2 = *(byte *)(param_1 + 0xd);
  bVar3 = *(byte *)(param_1 + 0xe);
  bVar4 = *(byte *)(param_1 + 0xf);
  if (uVar11 != 0) {
    puVar12 = param_2;
    puVar10 = param_3;
    if (param_4 == 0) {
LAB_0018807a:
      *(uint *)(param_1 + 0x168) = uVar11;
      return 0;
    }
    do {
      iVar15 = param_1 + uVar11;
      param_2 = (uint *)((int)puVar12 + 1);
      uVar13 = *puVar12;
      uVar11 = uVar11 + 1 & 0xf;
      uVar18 = uVar11;
      if (uVar11 != 0) {
        uVar18 = 1;
      }
      param_4 = param_4 - 1;
      param_3 = (uint *)((int)puVar10 + 1);
      *(byte *)puVar10 = *(byte *)(iVar15 + 0x10) ^ (byte)uVar13;
      if (param_4 == 0) {
        uVar18 = 0;
      }
      else {
        uVar18 = uVar18 & 1;
      }
      *(byte *)(iVar15 + 0x40) = (byte)uVar13 ^ *(byte *)(iVar15 + 0x40);
      puVar12 = param_2;
      puVar10 = param_3;
    } while (uVar18 != 0);
    if (uVar11 != 0) goto LAB_0018807a;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  uVar11 = (uint)bVar2 << 0x10 | (uint)bVar1 << 0x18 | (uint)bVar4 | (uint)bVar3 << 8;
  if (0xbff < param_4) {
    puVar12 = param_2;
    puVar10 = param_3;
    do {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar12,0xc00);
      uVar11 = uVar11 + 0xc0;
      param_4 = param_4 - 0xc00;
      param_2 = puVar12 + 0x300;
      param_3 = puVar10 + 0x300;
      (*param_5)(puVar12,puVar10,0xc0,uVar8,param_1);
      *(char *)(param_1 + 0xf) = (char)uVar11;
      *(char *)(param_1 + 0xc) = (char)(uVar11 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)(uVar11 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar11 >> 8);
      puVar12 = param_2;
      puVar10 = param_3;
    } while (0xbff < param_4);
  }
  uVar13 = param_4 & 0xfffffff0;
  if (uVar13 != 0) {
    uVar18 = param_4 >> 4;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,uVar13);
    uVar11 = uVar11 + uVar18;
    param_4 = param_4 - uVar13;
    (*param_5)(param_2,param_3,uVar18,uVar8,param_1);
    *(char *)(param_1 + 0xf) = (char)uVar11;
    *(char *)(param_1 + 0xc) = (char)(uVar11 >> 0x18);
    *(char *)(param_1 + 0xd) = (char)(uVar11 >> 0x10);
    *(char *)(param_1 + 0xe) = (char)(uVar11 >> 8);
    param_2 = (uint *)((int)param_2 + uVar13);
    param_3 = (uint *)((int)param_3 + uVar13);
  }
  if (param_4 != 0) {
    puVar12 = (uint *)(param_1 + 0x10);
    puVar14 = (uint *)(param_1 + 0x40);
    (**(code **)(param_1 + 0x170))(param_1,puVar12,uVar8);
    puVar10 = param_3 + 1;
    iVar15 = uVar11 + 1;
    uVar11 = param_4 >> 2;
    *(char *)(param_1 + 0xf) = (char)iVar15;
    *(char *)(param_1 + 0xd) = (char)((uint)iVar15 >> 0x10);
    local_40 = param_4 - 1;
    *(char *)(param_1 + 0xc) = (char)((uint)iVar15 >> 0x18);
    uVar13 = uVar11 * 4;
    *(char *)(param_1 + 0xe) = (char)((uint)iVar15 >> 8);
    if (uVar11 == 0 ||
        ((((uint)param_2 | (uint)param_3) & 3) != 0 ||
        (((param_4 < 4 ||
          (puVar14 < param_2 + 1 && param_2 < (uint *)(param_1 + 0x44) ||
          param_3 < param_2 + 1 && param_2 < puVar10)) ||
         param_3 < (uint *)(param_1 + 0x44) && puVar14 < puVar10) ||
        param_3 < (uint *)(param_1 + 0x14) && puVar12 < puVar10))) {
      uVar13 = 0;
    }
    else {
      if (uVar11 < 9) {
        uVar18 = 0;
        puVar10 = param_3;
        puVar17 = param_2;
      }
      else {
        uVar18 = 0;
        puVar7 = (uint *)(param_1 + 0x60);
        puVar5 = param_3;
        puVar6 = param_2;
        do {
          puVar14 = puVar7;
          puVar17 = puVar6 + 8;
          puVar10 = puVar5 + 8;
          uVar9 = *puVar6;
          uVar16 = uVar18 + 9;
          uVar18 = uVar18 + 8;
          HintPreloadData(puVar6 + 0xe);
          HintPreloadData(puVar14 + 6);
          puVar14[-8] = puVar14[-8] ^ uVar9;
          *puVar5 = puVar14[-0x14] ^ uVar9;
          uVar9 = puVar6[1];
          puVar12 = puVar14 + -0xc;
          puVar14[-7] = puVar14[-7] ^ uVar9;
          puVar5[1] = puVar14[-0x13] ^ uVar9;
          uVar9 = puVar6[2];
          puVar14[-6] = puVar14[-6] ^ uVar9;
          puVar5[2] = puVar14[-0x12] ^ uVar9;
          uVar9 = puVar6[3];
          puVar14[-5] = puVar14[-5] ^ uVar9;
          puVar5[3] = puVar14[-0x11] ^ uVar9;
          uVar9 = puVar6[4];
          puVar14[-4] = puVar14[-4] ^ uVar9;
          puVar5[4] = puVar14[-0x10] ^ uVar9;
          uVar9 = puVar6[5];
          puVar14[-3] = puVar14[-3] ^ uVar9;
          puVar5[5] = puVar14[-0xf] ^ uVar9;
          uVar9 = puVar6[6];
          puVar14[-2] = puVar14[-2] ^ uVar9;
          puVar5[6] = puVar14[-0xe] ^ uVar9;
          uVar9 = puVar6[7];
          puVar14[-1] = puVar14[-1] ^ uVar9;
          puVar5[7] = puVar14[-0xd] ^ uVar9;
          puVar7 = puVar14 + 8;
          puVar5 = puVar10;
          puVar6 = puVar17;
        } while (uVar16 < uVar11 - 7);
      }
      iVar15 = 0;
      do {
        uVar9 = *(uint *)((int)puVar17 + iVar15);
        uVar18 = uVar18 + 1;
        *(uint *)((int)puVar14 + iVar15) = uVar9 ^ *(uint *)((int)puVar14 + iVar15);
        *(uint *)((int)puVar10 + iVar15) = uVar9 ^ *(uint *)((int)puVar12 + iVar15);
        iVar15 = iVar15 + 4;
      } while (uVar18 < uVar11);
      local_40 = local_40 + uVar11 * -4;
      if (param_4 == uVar13) goto LAB_0018802c;
    }
    local_40 = uVar13 + local_40;
    do {
      iVar15 = param_1 + uVar13;
      bVar1 = *(byte *)((int)param_2 + uVar13);
      *(byte *)(iVar15 + 0x40) = *(byte *)(iVar15 + 0x40) ^ bVar1;
      *(byte *)((int)param_3 + uVar13) = bVar1 ^ *(byte *)(iVar15 + 0x10);
      uVar13 = uVar13 + 1;
    } while (uVar13 != local_40 + 1U);
  }
LAB_0018802c:
  *(uint *)(param_1 + 0x168) = param_4;
  return 0;
}


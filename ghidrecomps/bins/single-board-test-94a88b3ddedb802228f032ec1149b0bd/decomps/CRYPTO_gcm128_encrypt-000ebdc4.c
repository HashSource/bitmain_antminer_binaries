
undefined4 CRYPTO_gcm128_encrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  byte bVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  uint uVar19;
  uint *puVar20;
  uint uVar21;
  code *pcVar22;
  undefined4 uVar23;
  uint uVar24;
  uint *puVar25;
  bool bVar26;
  uint local_44;
  uint *local_40;
  uint local_3c;
  uint *local_34;
  
  puVar20 = (uint *)0xf;
  uVar15 = *(uint *)(param_1 + 0x38) + param_4;
  uVar17 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  pcVar22 = *(code **)(param_1 + 0x170);
  bVar26 = uVar17 < 0x10;
  if (uVar17 == 0xf) {
    bVar26 = uVar15 < 0xffffffe1;
  }
  uVar23 = *(undefined4 *)(param_1 + 0x174);
  if (!bVar26) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar15;
  *(uint *)(param_1 + 0x3c) = uVar17;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  bVar1 = *(byte *)(param_1 + 0xc);
  bVar11 = *(byte *)(param_1 + 0xe);
  bVar2 = *(byte *)(param_1 + 0xf);
  uVar15 = *(uint *)(param_1 + 0x168);
  bVar3 = *(byte *)(param_1 + 0xd);
  puVar8 = param_3;
  local_44 = param_4;
  local_40 = param_2;
  if (uVar15 != 0) {
    if (param_4 == 0) {
LAB_000ebe78:
      *(uint *)(param_1 + 0x168) = uVar15;
      return 0;
    }
    do {
      iVar9 = param_1 + uVar15;
      local_40 = (uint *)((int)param_2 + 1);
      bVar4 = *(byte *)(iVar9 + 0x40);
      uVar17 = uVar15 + 1 & 0xf;
      if (uVar17 != 0) {
        uVar17 = 1;
      }
      param_4 = param_4 - 1;
      bVar5 = *(byte *)param_2 ^ *(byte *)(iVar9 + 0x10);
      puVar20 = (uint *)(uint)bVar5;
      if (param_4 == 0) {
        uVar17 = 0;
      }
      else {
        uVar17 = uVar17 & 1;
      }
      puVar8 = (uint *)((int)param_3 + 1);
      *(byte *)param_3 = bVar5;
      uVar15 = uVar15 + 1 & 0xf;
      *(byte *)(iVar9 + 0x40) = bVar5 ^ bVar4;
      param_2 = local_40;
      param_3 = puVar8;
    } while (uVar17 != 0);
    if (uVar15 != 0) goto LAB_000ebe78;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    local_44 = param_4;
  }
  local_3c = (uint)bVar3 << 0x10 | (uint)bVar1 << 0x18 | (uint)bVar2 | (uint)bVar11 << 8;
  if ((((uint)puVar8 | (uint)local_40) & 3) != 0) {
    uVar15 = local_44;
    if (local_44 != 0) {
      uVar17 = 0;
      uVar15 = 0;
      do {
        while( true ) {
          iVar9 = param_1 + uVar15;
          if (uVar15 != 0) break;
          local_3c = local_3c + 1;
          (*pcVar22)(param_1,param_1 + 0x10,uVar23);
          *(char *)(param_1 + 0xf) = (char)local_3c;
          *(char *)(param_1 + 0xd) = (char)(local_3c >> 0x10);
          uVar15 = 1;
          *(char *)(param_1 + 0xe) = (char)(local_3c >> 8);
          *(char *)(param_1 + 0xc) = (char)(local_3c >> 0x18);
          bVar1 = *(byte *)(param_1 + 0x40);
          bVar11 = *(byte *)(param_1 + 0x10) ^ *(byte *)((int)local_40 + uVar17);
          *(byte *)((int)puVar8 + uVar17) = bVar11;
          *(byte *)(param_1 + 0x40) = bVar1 ^ bVar11;
          uVar17 = uVar17 + 1;
          if (uVar17 == local_44) goto LAB_000ebf4c;
        }
        bVar1 = *(byte *)(iVar9 + 0x40);
        bVar11 = *(byte *)(iVar9 + 0x10) ^ *(byte *)((int)local_40 + uVar17);
        *(byte *)((int)puVar8 + uVar17) = bVar11;
        uVar15 = uVar15 + 1 & 0xf;
        *(byte *)(iVar9 + 0x40) = bVar1 ^ bVar11;
        if (uVar15 == 0) {
          gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
        }
        uVar17 = uVar17 + 1;
      } while (uVar17 != local_44);
    }
LAB_000ebf4c:
    *(uint *)(param_1 + 0x168) = uVar15;
    return 0;
  }
  if (0xbff < local_44) {
    do {
      puVar18 = puVar8 + 0x300;
      puVar20 = local_40;
      uVar15 = local_3c;
      do {
        puVar10 = puVar8;
        uVar15 = uVar15 + 1;
        (*pcVar22)(param_1,param_1 + 0x10,uVar23);
        *(char *)(param_1 + 0xf) = (char)uVar15;
        *(char *)(param_1 + 0xe) = (char)(uVar15 >> 8);
        *(char *)(param_1 + 0xc) = (char)(uVar15 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(uVar15 >> 0x10);
        *puVar10 = *(uint *)(param_1 + 0x10) ^ *puVar20;
        puVar10[1] = *(uint *)(param_1 + 0x14) ^ puVar20[1];
        puVar10[2] = *(uint *)(param_1 + 0x18) ^ puVar20[2];
        puVar8 = puVar20 + 3;
        puVar20 = puVar20 + 4;
        puVar10[3] = *(uint *)(param_1 + 0x1c) ^ *puVar8;
        puVar8 = puVar10 + 4;
      } while (puVar8 != puVar18);
      local_44 = local_44 - 0xc00;
      local_3c = local_3c + 0xc0;
      local_40 = local_40 + 0x300;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar10 + -0x2fc);
    } while (0xbff < local_44);
  }
  uVar15 = local_44 & 0xfffffff0;
  if (uVar15 != 0) {
    if (0xf < local_44) {
      uVar24 = local_44 - 0x10 >> 4;
      uVar12 = local_3c + 1;
      uVar17 = uVar12;
      puVar18 = local_40;
      puVar20 = puVar8;
      do {
        local_3c = uVar17;
        (*pcVar22)(param_1,param_1 + 0x10,uVar23);
        *(char *)(param_1 + 0xf) = (char)local_3c;
        *(char *)(param_1 + 0xe) = (char)(local_3c >> 8);
        *(char *)(param_1 + 0xc) = (char)(local_3c >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(local_3c >> 0x10);
        *puVar20 = *(uint *)(param_1 + 0x10) ^ *puVar18;
        puVar20[1] = puVar18[1] ^ *(uint *)(param_1 + 0x14);
        puVar20[2] = puVar18[2] ^ *(uint *)(param_1 + 0x18);
        puVar10 = puVar18 + 3;
        puVar18 = puVar18 + 4;
        puVar20[3] = *puVar10 ^ *(uint *)(param_1 + 0x1c);
        puVar20 = puVar20 + 4;
        uVar17 = local_3c + 1;
      } while (local_3c != uVar12 + uVar24);
      iVar9 = uVar24 + 1;
      puVar8 = puVar8 + iVar9 * 4;
      local_40 = local_40 + iVar9 * 4;
      local_44 = local_44 & 0xf;
    }
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,(int)puVar8 - uVar15,uVar15);
  }
  if (local_44 != 0) {
    puVar18 = (uint *)(param_1 + 0x10);
    (*pcVar22)(param_1,puVar18,uVar23);
    puVar10 = (uint *)(param_1 + 0x44);
    puVar13 = puVar8 + 1;
    puVar25 = (uint *)(param_1 + 0x40);
    if (puVar8 < puVar10) {
      puVar20 = (uint *)0x0;
    }
    if (puVar8 >= puVar10) {
      puVar20 = (uint *)0x1;
    }
    if (puVar13 <= puVar25) {
      puVar20 = (uint *)((uint)puVar20 | 1);
    }
    uVar15 = (uint)puVar20 & (uint)(local_40 + 1 <= puVar8 || puVar13 <= local_40);
    if (local_44 < 4) {
      uVar15 = 0;
    }
    uVar15 = (uint)((uint *)(param_1 + 0x14) <= puVar8 || puVar13 <= puVar18) &
             uVar15 & (puVar10 <= local_40 || local_40 + 1 <= puVar25);
    iVar9 = local_3c + 1;
    uVar17 = local_44 >> 2;
    if ((((uint)puVar8 | (uint)local_40) & 3) != 0) {
      uVar15 = 0;
    }
    uVar15 = uVar15 ^ 1;
    *(char *)(param_1 + 0xf) = (char)iVar9;
    uVar12 = local_44 & 0xfffffffc;
    local_3c = local_44 - 1;
    *(char *)(param_1 + 0xc) = (char)((uint)iVar9 >> 0x18);
    if (uVar17 == 0) {
      uVar15 = 1;
    }
    *(char *)(param_1 + 0xd) = (char)((uint)iVar9 >> 0x10);
    *(char *)(param_1 + 0xe) = (char)((uint)iVar9 >> 8);
    if (uVar15 == 0) {
      if (uVar17 < 9) {
        uVar15 = 0;
        puVar20 = local_40;
        local_34 = puVar8;
      }
      else {
        puVar6 = (uint *)(param_1 + 0x60);
        uVar24 = 0;
        puVar10 = local_40;
        puVar13 = puVar8;
        do {
          puVar25 = puVar6;
          local_34 = puVar13 + 8;
          puVar20 = puVar10 + 8;
          uVar7 = *puVar10;
          uVar15 = uVar24 + 8;
          uVar21 = puVar25[-0x14];
          uVar16 = uVar24 + 9;
          uVar24 = puVar25[-8];
          HintPreloadData(puVar25 + 6);
          HintPreloadData(puVar10 + 0xe);
          *puVar13 = uVar7 ^ uVar21;
          puVar25[-8] = uVar24 ^ uVar7 ^ uVar21;
          uVar7 = puVar10[1];
          uVar24 = puVar25[-0x13];
          uVar21 = puVar25[-7];
          puVar13[1] = uVar24 ^ uVar7;
          puVar25[-7] = uVar24 ^ uVar7 ^ uVar21;
          uVar24 = puVar25[-0x12];
          uVar21 = puVar10[2];
          uVar7 = puVar25[-6];
          puVar13[2] = uVar21 ^ uVar24;
          puVar25[-6] = uVar7 ^ uVar21 ^ uVar24;
          uVar24 = puVar25[-0x11];
          uVar21 = puVar10[3];
          uVar7 = puVar25[-5];
          puVar13[3] = uVar21 ^ uVar24;
          puVar25[-5] = uVar7 ^ uVar21 ^ uVar24;
          uVar7 = puVar25[-0x10];
          uVar24 = puVar10[4];
          uVar21 = puVar25[-4];
          puVar13[4] = uVar24 ^ uVar7;
          puVar25[-4] = uVar24 ^ uVar7 ^ uVar21;
          uVar7 = puVar25[-0xf];
          uVar24 = puVar10[5];
          uVar21 = puVar25[-3];
          puVar13[5] = uVar24 ^ uVar7;
          puVar25[-3] = uVar24 ^ uVar7 ^ uVar21;
          uVar7 = puVar25[-0xe];
          uVar24 = puVar10[6];
          uVar21 = puVar25[-2];
          puVar13[6] = uVar24 ^ uVar7;
          uVar19 = puVar25[-0xd];
          puVar25[-2] = uVar24 ^ uVar7 ^ uVar21;
          uVar24 = puVar10[7];
          uVar7 = puVar25[-1];
          puVar13[7] = uVar19 ^ uVar24;
          puVar25[-1] = uVar19 ^ uVar24 ^ uVar7;
          puVar18 = puVar25 + -0xc;
          puVar6 = puVar25 + 8;
          uVar24 = uVar15;
          puVar10 = puVar20;
          puVar13 = local_34;
        } while (uVar16 < uVar17 - 7);
      }
      iVar9 = 0;
      do {
        uVar15 = uVar15 + 1;
        uVar24 = *(uint *)((int)puVar25 + iVar9);
        uVar7 = *(uint *)((int)puVar20 + iVar9) ^ *(uint *)((int)puVar18 + iVar9);
        *(uint *)((int)local_34 + iVar9) = uVar7;
        *(uint *)((int)puVar25 + iVar9) = uVar7 ^ uVar24;
        iVar9 = iVar9 + 4;
      } while (uVar15 < uVar17);
      local_3c = local_3c - uVar12;
      if (local_44 == uVar12) goto LAB_000ec0ce;
    }
    else {
      uVar12 = 0;
    }
    iVar9 = uVar12 + local_3c;
    do {
      iVar14 = param_1 + uVar12;
      bVar1 = *(byte *)(iVar14 + 0x40);
      bVar11 = *(byte *)((int)local_40 + uVar12) ^ *(byte *)(iVar14 + 0x10);
      *(byte *)((int)puVar8 + uVar12) = bVar11;
      uVar12 = uVar12 + 1;
      *(byte *)(iVar14 + 0x40) = bVar11 ^ bVar1;
    } while (uVar12 != iVar9 + 1U);
  }
LAB_000ec0ce:
  *(uint *)(param_1 + 0x168) = local_44;
  return 0;
}


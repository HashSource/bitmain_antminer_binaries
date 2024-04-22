
undefined4 CRYPTO_gcm128_decrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  code *pcVar17;
  undefined4 uVar18;
  uint uVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  uint local_44;
  uint *local_40;
  uint local_3c;
  uint *local_38;
  uint *local_34;
  
  uVar9 = *(uint *)(param_1 + 0x38) + param_4;
  uVar12 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  pcVar17 = *(code **)(param_1 + 0x170);
  bVar21 = uVar12 < 0x10;
  if (uVar12 == 0xf) {
    bVar21 = uVar9 < 0xffffffe1;
  }
  uVar18 = *(undefined4 *)(param_1 + 0x174);
  if (!bVar21) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar9;
  *(uint *)(param_1 + 0x3c) = uVar12;
  if (*(int *)(param_1 + 0x16c) != 0) {
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x16c) = 0;
  }
  uVar9 = *(uint *)(param_1 + 0x168);
  bVar1 = *(byte *)(param_1 + 0xc);
  bVar2 = *(byte *)(param_1 + 0xd);
  bVar3 = *(byte *)(param_1 + 0xe);
  bVar4 = *(byte *)(param_1 + 0xf);
  local_44 = param_4;
  local_40 = param_3;
  if (uVar9 != 0) {
    puVar13 = param_2;
    local_40 = param_3;
    if (param_4 == 0) {
LAB_000ec3d8:
      *(uint *)(param_1 + 0x168) = uVar9;
      return 0;
    }
    do {
      iVar7 = param_1 + uVar9;
      param_2 = (uint *)((int)puVar13 + 1);
      bVar5 = *(byte *)puVar13;
      uVar9 = uVar9 + 1 & 0xf;
      uVar12 = uVar9;
      if (uVar9 != 0) {
        uVar12 = 1;
      }
      local_44 = local_44 - 1;
      if (local_44 == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = uVar12 & 1;
      }
      puVar10 = (uint *)((int)local_40 + 1);
      *(byte *)local_40 = bVar5 ^ *(byte *)(iVar7 + 0x10);
      *(byte *)(iVar7 + 0x40) = bVar5 ^ *(byte *)(iVar7 + 0x40);
      puVar13 = param_2;
      local_40 = puVar10;
    } while (uVar12 != 0);
    if (uVar9 != 0) goto LAB_000ec3d8;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  local_3c = (uint)bVar2 << 0x10 | (uint)bVar1 << 0x18 | (uint)bVar4 | (uint)bVar3 << 8;
  if ((((uint)local_40 | (uint)param_2) & 3) != 0) {
    uVar9 = local_44;
    if (local_44 != 0) {
      uVar12 = 0;
      uVar9 = 0;
      do {
        while( true ) {
          iVar7 = param_1 + uVar9;
          if (uVar9 != 0) break;
          local_3c = local_3c + 1;
          (*pcVar17)(param_1,param_1 + 0x10,uVar18);
          *(char *)(param_1 + 0xf) = (char)local_3c;
          *(char *)(param_1 + 0xd) = (char)(local_3c >> 0x10);
          uVar9 = 1;
          *(char *)(param_1 + 0xc) = (char)(local_3c >> 0x18);
          *(char *)(param_1 + 0xe) = (char)(local_3c >> 8);
          bVar1 = *(byte *)((int)param_2 + uVar12);
          *(byte *)((int)local_40 + uVar12) = *(byte *)(param_1 + 0x10) ^ bVar1;
          uVar12 = uVar12 + 1;
          *(byte *)(param_1 + 0x40) = bVar1 ^ *(byte *)(param_1 + 0x40);
          if (uVar12 == local_44) goto LAB_000ec4b4;
        }
        bVar1 = *(byte *)((int)param_2 + uVar12);
        *(byte *)((int)local_40 + uVar12) = *(byte *)(iVar7 + 0x10) ^ bVar1;
        uVar9 = uVar9 + 1 & 0xf;
        *(byte *)(iVar7 + 0x40) = bVar1 ^ *(byte *)(iVar7 + 0x40);
        if (uVar9 == 0) {
          gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 != local_44);
    }
LAB_000ec4b4:
    *(uint *)(param_1 + 0x168) = uVar9;
    return 0;
  }
  if (0xbff < local_44) {
    do {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,0xc00);
      puVar10 = param_2 + 0x300;
      puVar13 = local_40;
      uVar9 = local_3c;
      do {
        uVar9 = uVar9 + 1;
        (*pcVar17)(param_1,param_1 + 0x10,uVar18);
        *(char *)(param_1 + 0xf) = (char)uVar9;
        *(char *)(param_1 + 0xe) = (char)(uVar9 >> 8);
        *(char *)(param_1 + 0xc) = (char)(uVar9 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(uVar9 >> 0x10);
        *puVar13 = *(uint *)(param_1 + 0x10) ^ *param_2;
        puVar13[1] = *(uint *)(param_1 + 0x14) ^ param_2[1];
        puVar13[2] = *(uint *)(param_1 + 0x18) ^ param_2[2];
        puVar8 = param_2 + 3;
        param_2 = param_2 + 4;
        puVar13[3] = *puVar8 ^ *(uint *)(param_1 + 0x1c);
        puVar13 = puVar13 + 4;
      } while (param_2 != puVar10);
      local_44 = local_44 - 0xc00;
      local_3c = local_3c + 0xc0;
      local_40 = local_40 + 0x300;
    } while (0xbff < local_44);
  }
  if ((local_44 & 0xfffffff0) == 0) {
LAB_000ec57e:
    if (local_44 == 0) goto LAB_000ec582;
  }
  else {
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2);
    if (0xf < local_44) {
      uVar15 = local_44 - 0x10 >> 4;
      uVar12 = local_3c + 1;
      uVar9 = uVar12;
      puVar13 = param_2;
      puVar10 = local_40;
      do {
        local_3c = uVar9;
        (*pcVar17)(param_1,param_1 + 0x10,uVar18);
        *(char *)(param_1 + 0xf) = (char)local_3c;
        *(char *)(param_1 + 0xe) = (char)(local_3c >> 8);
        *(char *)(param_1 + 0xc) = (char)(local_3c >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(local_3c >> 0x10);
        *puVar10 = *(uint *)(param_1 + 0x10) ^ *puVar13;
        puVar10[1] = puVar13[1] ^ *(uint *)(param_1 + 0x14);
        puVar10[2] = puVar13[2] ^ *(uint *)(param_1 + 0x18);
        puVar8 = puVar13 + 3;
        puVar13 = puVar13 + 4;
        puVar10[3] = *puVar8 ^ *(uint *)(param_1 + 0x1c);
        puVar10 = puVar10 + 4;
        uVar9 = local_3c + 1;
      } while (local_3c != uVar12 + uVar15);
      iVar7 = uVar15 + 1;
      local_44 = local_44 & 0xf;
      local_40 = local_40 + iVar7 * 4;
      param_2 = param_2 + iVar7 * 4;
      goto LAB_000ec57e;
    }
  }
  local_38 = (uint *)(param_1 + 0x40);
  puVar11 = (uint *)(param_1 + 0x10);
  (*pcVar17)(param_1,puVar11,uVar18);
  puVar10 = (uint *)(param_1 + 0x44);
  puVar13 = param_2 + 1;
  puVar8 = local_40 + 1;
  bVar22 = param_2 <= puVar10;
  bVar21 = puVar10 == param_2;
  if (bVar22 && !bVar21) {
    bVar22 = local_38 <= puVar13;
    bVar21 = puVar13 == local_38;
  }
  bVar23 = local_40 <= puVar13;
  bVar20 = puVar13 == local_40;
  if (bVar23 && !bVar20) {
    bVar23 = param_2 <= puVar8;
    bVar20 = puVar8 == param_2;
  }
  iVar14 = local_3c + 1;
  uVar12 = local_44 >> 2;
  *(char *)(param_1 + 0xf) = (char)iVar14;
  uVar9 = local_44 & 0xfffffffc;
  *(char *)(param_1 + 0xc) = (char)((uint)iVar14 >> 0x18);
  *(char *)(param_1 + 0xd) = (char)((uint)iVar14 >> 0x10);
  iVar7 = local_44 - 1;
  *(char *)(param_1 + 0xe) = (char)((uint)iVar14 >> 8);
  if (uVar12 == 0 ||
      ((((uint)local_40 | (uint)param_2) & 3) != 0 ||
      (local_40 < (uint *)(param_1 + 0x14) && puVar11 < puVar8 ||
      ((local_44 < 4 || (bVar22 && !bVar21 || bVar23 && !bVar20)) ||
      local_38 < puVar8 && local_40 < puVar10)))) {
    uVar9 = 0;
  }
  else {
    if (uVar12 < 9) {
      local_34 = local_40;
      uVar15 = 0;
      puVar13 = local_38;
      local_38 = param_2;
    }
    else {
      puVar6 = (uint *)(param_1 + 0x60);
      puVar10 = param_2;
      puVar8 = local_40;
      local_3c = 0;
      do {
        puVar13 = puVar6;
        local_34 = puVar8 + 8;
        local_38 = puVar10 + 8;
        uVar15 = *puVar10;
        HintPreloadData(puVar10 + 0xe);
        HintPreloadData(puVar13 + 6);
        puVar13[-8] = puVar13[-8] ^ uVar15;
        *puVar8 = puVar13[-0x14] ^ uVar15;
        uVar15 = local_3c + 8;
        uVar16 = puVar10[1];
        uVar19 = local_3c + 9;
        puVar13[-7] = puVar13[-7] ^ uVar16;
        puVar8[1] = puVar13[-0x13] ^ uVar16;
        uVar16 = puVar10[2];
        puVar13[-6] = puVar13[-6] ^ uVar16;
        puVar8[2] = puVar13[-0x12] ^ uVar16;
        uVar16 = puVar10[3];
        puVar13[-5] = puVar13[-5] ^ uVar16;
        puVar8[3] = puVar13[-0x11] ^ uVar16;
        uVar16 = puVar10[4];
        puVar13[-4] = puVar13[-4] ^ uVar16;
        puVar8[4] = puVar13[-0x10] ^ uVar16;
        uVar16 = puVar10[5];
        puVar13[-3] = puVar13[-3] ^ uVar16;
        puVar8[5] = puVar13[-0xf] ^ uVar16;
        uVar16 = puVar10[6];
        puVar13[-2] = puVar13[-2] ^ uVar16;
        puVar8[6] = puVar13[-0xe] ^ uVar16;
        puVar11 = puVar13 + -0xc;
        uVar16 = puVar10[7];
        puVar13[-1] = uVar16 ^ puVar13[-1];
        puVar8[7] = uVar16 ^ puVar13[-0xd];
        puVar6 = puVar13 + 8;
        puVar10 = local_38;
        puVar8 = local_34;
        local_3c = uVar15;
      } while (uVar19 < uVar12 - 7);
    }
    iVar14 = 0;
    do {
      uVar16 = *(uint *)((int)local_38 + iVar14);
      uVar15 = uVar15 + 1;
      *(uint *)((int)puVar13 + iVar14) = uVar16 ^ *(uint *)((int)puVar13 + iVar14);
      *(uint *)((int)local_34 + iVar14) = uVar16 ^ *(uint *)((int)puVar11 + iVar14);
      iVar14 = iVar14 + 4;
    } while (uVar15 < uVar12);
    iVar7 = iVar7 - uVar9;
    if (uVar9 == local_44) goto LAB_000ec582;
  }
  iVar7 = uVar9 + iVar7;
  do {
    iVar14 = param_1 + uVar9;
    bVar1 = *(byte *)((int)param_2 + uVar9);
    *(byte *)(iVar14 + 0x40) = *(byte *)(iVar14 + 0x40) ^ bVar1;
    *(byte *)((int)local_40 + uVar9) = bVar1 ^ *(byte *)(iVar14 + 0x10);
    uVar9 = uVar9 + 1;
  } while (uVar9 != iVar7 + 1U);
LAB_000ec582:
  *(uint *)(param_1 + 0x168) = local_44;
  return 0;
}


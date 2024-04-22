
undefined4 gost_cipher_do_cfb(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  size_t __n;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint *puVar15;
  byte *pbVar16;
  bool bVar17;
  bool bVar18;
  uint local_44;
  
  uVar9 = *(uint *)(param_1 + 0x50);
  if (uVar9 == 0) {
    uVar9 = 8;
    uVar10 = 0;
  }
  else {
    uVar10 = param_4;
    if (param_4 != 0) {
      uVar10 = 1;
    }
    if (7 < uVar9) {
      uVar10 = 0;
    }
    if (uVar10 == 0) {
      uVar10 = 0;
    }
    else {
      iVar12 = *(int *)(param_1 + 8);
      uVar10 = 0;
      puVar14 = param_2;
      puVar13 = (uint *)((int)param_3 + 1);
      pbVar16 = (byte *)(uVar9 + 0x2f + param_1);
      do {
        param_3 = puVar13;
        uVar10 = uVar10 + 1;
        uVar9 = uVar9 + 1;
        if (iVar12 == 0) {
          pbVar16[9] = *(byte *)((int)param_3 + -1);
        }
        bVar5 = *(byte *)((int)param_3 + -1) ^ pbVar16[1];
        param_2 = (uint *)((int)puVar14 + 1);
        *(byte *)puVar14 = bVar5;
        iVar12 = *(int *)(param_1 + 8);
        if (iVar12 != 0) {
          pbVar16[9] = bVar5;
        }
        puVar14 = param_2;
        puVar13 = (uint *)((int)param_3 + 1);
        pbVar16 = pbVar16 + 1;
      } while (uVar9 < 8 && uVar10 < param_4);
    }
    if (uVar9 != 8) {
      *(uint *)(param_1 + 0x50) = uVar9;
      return 1;
    }
    uVar9 = uVar10 + 8;
    *(undefined4 *)(param_1 + 0x50) = 0;
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 0x3c);
  }
  if (uVar9 < param_4) {
    uVar8 = (int)param_2 + -uVar9;
    puVar13 = (uint *)(param_1 + 0x20);
    puVar14 = param_3;
    uVar10 = uVar9;
    while( true ) {
      iVar12 = *(int *)(param_1 + 0x60);
      if ((*(int *)(iVar12 + 8) != 0) && (*(int *)(iVar12 + 4) == 0x400)) {
        cryptopro_key_meshing(iVar12 + 0xc,puVar13);
      }
      gostcrypt(iVar12 + 0xc,puVar13,param_1 + 0x30);
      iVar6 = *(int *)(param_1 + 8);
      *(uint *)(iVar12 + 4) = (*(uint *)(iVar12 + 4) & 0x3ff) + 8;
      if (iVar6 == 0) {
        uVar7 = puVar14[1];
        *puVar13 = *puVar14;
        *(uint *)(param_1 + 0x24) = uVar7;
      }
      *(byte *)(uVar8 + uVar10) =
           *(byte *)(param_1 + 0x30) ^ *(byte *)((int)param_3 + uVar10 + -uVar9);
      *(byte *)((int)param_2 + 1) = *(byte *)(param_1 + 0x31) ^ *(byte *)((int)puVar14 + 1);
      *(byte *)((int)param_2 + 2) = *(byte *)(param_1 + 0x32) ^ *(byte *)((int)puVar14 + 2);
      *(byte *)((int)param_2 + 3) = *(byte *)(param_1 + 0x33) ^ *(byte *)((int)puVar14 + 3);
      *(byte *)(param_2 + 1) = *(byte *)(param_1 + 0x34) ^ *(byte *)(puVar14 + 1);
      *(byte *)((int)param_2 + 5) = *(byte *)(param_1 + 0x35) ^ *(byte *)((int)puVar14 + 5);
      *(byte *)((int)param_2 + 6) = *(byte *)(param_1 + 0x36) ^ *(byte *)((int)puVar14 + 6);
      *(byte *)((int)param_2 + 7) = *(byte *)(param_1 + 0x37) ^ *(byte *)((int)puVar14 + 7);
      if (*(int *)(param_1 + 8) != 0) {
        uVar7 = *param_2;
        *(uint *)(param_1 + 0x24) = param_2[1];
        *puVar13 = uVar7;
      }
      if (param_4 <= uVar10 + 8) break;
      uVar10 = uVar10 + 8;
      puVar14 = puVar14 + 2;
      param_2 = param_2 + 2;
    }
    param_3 = puVar14 + 2;
    param_2 = param_2 + 2;
    uVar9 = uVar8;
  }
  if (param_4 <= uVar10) {
    uVar9 = 0;
  }
  if (param_4 <= uVar10) {
    *(uint *)(param_1 + 0x50) = uVar9;
    return 1;
  }
  iVar12 = *(int *)(param_1 + 0x60);
  puVar14 = (uint *)(param_1 + 0x30);
  if ((*(int *)(iVar12 + 8) != 0) && (*(int *)(iVar12 + 4) == 0x400)) {
    cryptopro_key_meshing(iVar12 + 0xc,param_1 + 0x20);
  }
  gostcrypt(iVar12 + 0xc,param_1 + 0x20,puVar14);
  iVar6 = *(int *)(param_1 + 8);
  *(uint *)(iVar12 + 4) = (*(uint *)(iVar12 + 4) & 0x3ff) + 8;
  if (iVar6 == 0) {
    memcpy((void *)(param_1 + 0x38),param_3,param_4 - uVar10);
  }
  puVar13 = param_2 + 1;
  bVar18 = param_2 <= (uint *)(param_1 + 0x34U);
  bVar17 = (uint *)(param_1 + 0x34U) == param_2;
  if (bVar18 && !bVar17) {
    bVar18 = puVar14 <= puVar13;
    bVar17 = puVar13 == puVar14;
  }
  uVar9 = param_4 - uVar10;
  uVar7 = uVar9 >> 2;
  local_44 = uVar9 & 0xfffffffc;
  uVar8 = ~uVar10;
  if (uVar7 == 0 ||
      ((((uint)param_2 | (uint)param_3) & 3) != 0 ||
      ((uVar9 < 4 || bVar18 && !bVar17) || param_2 < param_3 + 1 && param_3 < puVar13))) {
    local_44 = 0;
  }
  else {
    if (uVar7 < 9) {
      uVar4 = 0;
      puVar13 = param_2;
      puVar15 = param_3;
    }
    else {
      uVar4 = 0;
      puVar3 = (uint *)(param_1 + 0x50);
      puVar1 = param_2;
      puVar2 = param_3;
      do {
        puVar14 = puVar3;
        puVar15 = puVar2 + 8;
        puVar13 = puVar1 + 8;
        uVar11 = uVar4 + 9;
        uVar4 = uVar4 + 8;
        HintPreloadData(puVar14 + 0xc);
        *puVar1 = *puVar2 ^ puVar14[-8];
        puVar1[1] = puVar14[-7] ^ puVar2[1];
        puVar1[2] = puVar2[2] ^ puVar14[-6];
        puVar1[3] = puVar14[-5] ^ puVar2[3];
        puVar1[4] = puVar14[-4] ^ puVar2[4];
        puVar1[5] = puVar14[-3] ^ puVar2[5];
        puVar1[6] = puVar14[-2] ^ puVar2[6];
        puVar1[7] = puVar14[-1] ^ puVar2[7];
        puVar3 = puVar14 + 8;
        puVar1 = puVar13;
        puVar2 = puVar15;
      } while (uVar11 < uVar7 - 7);
    }
    iVar12 = 0;
    do {
      uVar4 = uVar4 + 1;
      *(uint *)((int)puVar13 + iVar12) =
           *(uint *)((int)puVar15 + iVar12) ^ *(uint *)((int)puVar14 + iVar12);
      iVar12 = iVar12 + 4;
    } while (uVar4 < uVar7);
    uVar10 = uVar10 + local_44;
    if (uVar9 == local_44) goto LAB_00117182;
  }
  iVar12 = local_44 - uVar10;
  do {
    *(byte *)((int)param_2 + uVar10 + iVar12) =
         *(byte *)((int)param_3 + uVar10 + iVar12) ^ *(byte *)(param_1 + iVar12 + uVar10 + 0x30);
    uVar10 = uVar10 + 1;
  } while (uVar10 < param_4);
LAB_00117182:
  __n = param_4 + 1 + uVar8;
  *(size_t *)(param_1 + 0x50) = __n;
  if (*(int *)(param_1 + 8) != 0) {
    memcpy((void *)(param_1 + 0x38),param_2,__n);
  }
  return 1;
}


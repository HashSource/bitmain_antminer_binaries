
undefined4 gost_cipher_do_cnt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte *pbVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  bool bVar17;
  uint local_40;
  
  uVar10 = *(uint *)(param_1 + 0x50);
  uVar9 = param_4;
  if (uVar10 == 0) {
    uVar10 = 8;
    uVar11 = 0;
  }
  else {
    uVar11 = param_4;
    if (param_4 != 0) {
      uVar11 = 1;
    }
    if (7 < uVar10) {
      uVar11 = 0;
    }
    if (uVar11 == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = 0;
      puVar5 = param_2;
      puVar7 = param_3;
      do {
        iVar8 = param_1 + uVar10;
        param_3 = (uint *)((int)puVar7 + 1);
        uVar10 = uVar10 + 1;
        uVar11 = uVar11 + 1;
        uVar9 = (uint)(uVar10 < 8);
        if (param_4 <= uVar11) {
          uVar9 = 0;
        }
        param_2 = (uint *)((int)puVar5 + 1);
        *(byte *)puVar5 = *(byte *)puVar7 ^ *(byte *)(iVar8 + 0x30);
        puVar5 = param_2;
        puVar7 = param_3;
      } while (uVar9 != 0);
    }
    if (uVar10 != 8) {
      *(uint *)(param_1 + 0x50) = uVar10;
      return 1;
    }
    uVar10 = uVar11 + 8;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  puVar5 = param_2;
  if (uVar10 < param_4) {
    uVar14 = -uVar10 + (int)param_3;
    uVar9 = uVar14;
    uVar15 = uVar10;
    do {
      uVar11 = uVar15;
      gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x30);
      *(byte *)((int)param_2 + uVar11 + -uVar10) =
           *(byte *)(uVar14 + uVar11) ^ *(byte *)(param_1 + 0x30);
      *(byte *)((int)puVar5 + 1) = *(byte *)((int)param_3 + 1) ^ *(byte *)(param_1 + 0x31);
      *(byte *)((int)puVar5 + 2) = *(byte *)((int)param_3 + 2) ^ *(byte *)(param_1 + 0x32);
      *(byte *)((int)puVar5 + 3) = *(byte *)((int)param_3 + 3) ^ *(byte *)(param_1 + 0x33);
      *(byte *)(puVar5 + 1) = *(byte *)(param_3 + 1) ^ *(byte *)(param_1 + 0x34);
      *(byte *)((int)puVar5 + 5) = *(byte *)((int)param_3 + 5) ^ *(byte *)(param_1 + 0x35);
      *(byte *)((int)puVar5 + 6) = *(byte *)((int)param_3 + 6) ^ *(byte *)(param_1 + 0x36);
      pbVar1 = (byte *)((int)param_3 + 7);
      param_3 = param_3 + 2;
      *(byte *)((int)puVar5 + 7) = *pbVar1 ^ *(byte *)(param_1 + 0x37);
      puVar5 = puVar5 + 2;
      uVar15 = uVar11 + 8;
    } while (uVar11 + 8 < param_4);
  }
  if (param_4 <= uVar11) {
    uVar9 = 0;
  }
  if (param_4 <= uVar11) {
    *(uint *)(param_1 + 0x50) = uVar9;
    return 1;
  }
  puVar12 = (uint *)(param_1 + 0x30);
  gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,puVar12);
  puVar7 = puVar5 + 1;
  bVar17 = puVar5 <= (uint *)(param_1 + 0x34);
  bVar16 = (uint *)(param_1 + 0x34) == puVar5;
  if (bVar17 && !bVar16) {
    bVar17 = puVar12 <= puVar7;
    bVar16 = puVar7 == puVar12;
  }
  uVar10 = param_4 - uVar11;
  uVar9 = uVar10 >> 2;
  local_40 = uVar10 & 0xfffffffc;
  uVar15 = ~uVar11;
  if (uVar9 == 0 ||
      ((((uint)puVar5 | (uint)param_3) & 3) != 0 ||
      ((uVar10 < 4 || bVar17 && !bVar16) || puVar5 < param_3 + 1 && param_3 < puVar7))) {
    local_40 = 0;
  }
  else {
    if (uVar9 < 9) {
      uVar14 = 0;
      puVar7 = param_3;
      puVar13 = puVar5;
    }
    else {
      uVar14 = 0;
      puVar4 = (uint *)(param_1 + 0x50);
      puVar2 = param_3;
      puVar3 = puVar5;
      do {
        puVar12 = puVar4;
        puVar13 = puVar3 + 8;
        puVar7 = puVar2 + 8;
        uVar6 = uVar14 + 9;
        uVar14 = uVar14 + 8;
        HintPreloadData(puVar12 + 0xc);
        *puVar3 = *puVar2 ^ puVar12[-8];
        puVar3[1] = puVar2[1] ^ puVar12[-7];
        puVar3[2] = puVar2[2] ^ puVar12[-6];
        puVar3[3] = puVar2[3] ^ puVar12[-5];
        puVar3[4] = puVar12[-4] ^ puVar2[4];
        puVar3[5] = puVar2[5] ^ puVar12[-3];
        puVar3[6] = puVar12[-2] ^ puVar2[6];
        puVar3[7] = puVar12[-1] ^ puVar2[7];
        puVar4 = puVar12 + 8;
        puVar2 = puVar7;
        puVar3 = puVar13;
      } while (uVar6 < uVar9 - 7);
    }
    iVar8 = 0;
    do {
      uVar14 = uVar14 + 1;
      *(uint *)((int)puVar13 + iVar8) =
           *(uint *)((int)puVar12 + iVar8) ^ *(uint *)((int)puVar7 + iVar8);
      iVar8 = iVar8 + 4;
    } while (uVar14 < uVar9);
    uVar11 = uVar11 + local_40;
    if (uVar10 == local_40) goto LAB_00116c0c;
  }
  iVar8 = local_40 - uVar11;
  do {
    *(byte *)((int)puVar5 + uVar11 + iVar8) =
         *(byte *)((int)param_3 + uVar11 + iVar8) ^ *(byte *)(param_1 + iVar8 + uVar11 + 0x30);
    uVar11 = uVar11 + 1;
  } while (uVar11 < param_4);
LAB_00116c0c:
  *(uint *)(param_1 + 0x50) = param_4 + 1 + uVar15;
  return 1;
}


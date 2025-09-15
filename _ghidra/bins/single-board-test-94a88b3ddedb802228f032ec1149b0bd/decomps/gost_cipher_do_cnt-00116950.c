
undefined4 gost_cipher_do_cnt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte *pbVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  uint extraout_r3;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  uint local_40;
  
  uVar11 = *(uint *)(param_1 + 0x50);
  uVar10 = param_4;
  if (uVar11 == 0) {
    uVar11 = 8;
    uVar12 = 0;
  }
  else {
    uVar12 = param_4;
    if (param_4 != 0) {
      uVar12 = 1;
    }
    if (7 < uVar11) {
      uVar12 = 0;
    }
    if (uVar12 == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = 0;
      puVar5 = param_2;
      puVar8 = param_3;
      do {
        iVar9 = param_1 + uVar11;
        param_3 = (uint *)((int)puVar8 + 1);
        uVar11 = uVar11 + 1;
        uVar12 = uVar12 + 1;
        uVar10 = (uint)(uVar11 < 8);
        if (param_4 <= uVar12) {
          uVar10 = 0;
        }
        param_2 = (uint *)((int)puVar5 + 1);
        *(byte *)puVar5 = (byte)*puVar8 ^ *(byte *)(iVar9 + 0x30);
        puVar5 = param_2;
        puVar8 = param_3;
      } while (uVar10 != 0);
    }
    if (uVar11 != 8) {
      *(uint *)(param_1 + 0x50) = uVar11;
      return 1;
    }
    uVar11 = uVar12 + 8;
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  puVar5 = param_2;
  puVar8 = param_3;
  if (uVar11 < param_4) {
    uVar16 = uVar11;
    do {
      uVar12 = uVar16;
      gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,param_1 + 0x30);
      *(byte *)((int)param_2 + uVar12 + -uVar11) =
           *(byte *)((int)param_3 + uVar12 + -uVar11) ^ *(byte *)(param_1 + 0x30);
      *(byte *)((int)puVar5 + 1) = *(byte *)((int)puVar8 + 1) ^ *(byte *)(param_1 + 0x31);
      *(byte *)((int)puVar5 + 2) = *(byte *)((int)puVar8 + 2) ^ *(byte *)(param_1 + 0x32);
      *(byte *)((int)puVar5 + 3) = *(byte *)((int)puVar8 + 3) ^ *(byte *)(param_1 + 0x33);
      *(byte *)(puVar5 + 1) = (byte)puVar8[1] ^ *(byte *)(param_1 + 0x34);
      *(byte *)((int)puVar5 + 5) = *(byte *)((int)puVar8 + 5) ^ *(byte *)(param_1 + 0x35);
      *(byte *)((int)puVar5 + 6) = *(byte *)((int)puVar8 + 6) ^ *(byte *)(param_1 + 0x36);
      pbVar1 = (byte *)((int)puVar8 + 7);
      puVar8 = puVar8 + 2;
      *(byte *)((int)puVar5 + 7) = *pbVar1 ^ *(byte *)(param_1 + 0x37);
      puVar5 = puVar5 + 2;
      uVar10 = extraout_r3;
      uVar16 = uVar12 + 8;
    } while (uVar12 + 8 < param_4);
  }
  if (param_4 <= uVar12) {
    uVar10 = 0;
  }
  if (param_4 <= uVar12) {
    *(uint *)(param_1 + 0x50) = uVar10;
    return 1;
  }
  puVar13 = (uint *)(param_1 + 0x30);
  gost_cnt_next(*(undefined4 *)(param_1 + 0x60),param_1 + 0x20,puVar13);
  puVar7 = puVar5 + 1;
  bVar18 = puVar5 <= (uint *)(param_1 + 0x34);
  bVar17 = (uint *)(param_1 + 0x34) == puVar5;
  if (bVar18 && !bVar17) {
    bVar18 = puVar13 <= puVar7;
    bVar17 = puVar7 == puVar13;
  }
  uVar11 = param_4 - uVar12;
  uVar10 = uVar11 >> 2;
  local_40 = uVar10 * 4;
  uVar16 = ~uVar12;
  if (uVar10 == 0 ||
      ((((uint)puVar5 | (uint)puVar8) & 3) != 0 ||
      ((uVar11 < 4 || bVar18 && !bVar17) || puVar5 < puVar8 + 1 && puVar8 < puVar7))) {
    local_40 = 0;
  }
  else {
    if (uVar10 < 9) {
      uVar15 = 0;
      puVar7 = puVar8;
      puVar14 = puVar5;
    }
    else {
      uVar15 = 0;
      puVar4 = (uint *)(param_1 + 0x50);
      puVar2 = puVar8;
      puVar3 = puVar5;
      do {
        puVar13 = puVar4;
        puVar14 = puVar3 + 8;
        puVar7 = puVar2 + 8;
        uVar6 = uVar15 + 9;
        uVar15 = uVar15 + 8;
        HintPreloadData(puVar13 + 0xc);
        *puVar3 = *puVar2 ^ puVar13[-8];
        puVar3[1] = puVar2[1] ^ puVar13[-7];
        puVar3[2] = puVar2[2] ^ puVar13[-6];
        puVar3[3] = puVar2[3] ^ puVar13[-5];
        puVar3[4] = puVar13[-4] ^ puVar2[4];
        puVar3[5] = puVar2[5] ^ puVar13[-3];
        puVar3[6] = puVar13[-2] ^ puVar2[6];
        puVar3[7] = puVar13[-1] ^ puVar2[7];
        puVar4 = puVar13 + 8;
        puVar2 = puVar7;
        puVar3 = puVar14;
      } while (uVar6 < uVar10 - 7);
    }
    iVar9 = 0;
    do {
      uVar15 = uVar15 + 1;
      *(uint *)((int)puVar14 + iVar9) =
           *(uint *)((int)puVar13 + iVar9) ^ *(uint *)((int)puVar7 + iVar9);
      iVar9 = iVar9 + 4;
    } while (uVar15 < uVar10);
    uVar12 = uVar12 + local_40;
    if (uVar11 == local_40) goto LAB_00116c0c;
  }
  iVar9 = local_40 - uVar12;
  do {
    *(byte *)((int)puVar5 + uVar12 + iVar9) =
         *(byte *)((int)puVar8 + uVar12 + iVar9) ^ *(byte *)(param_1 + iVar9 + uVar12 + 0x30);
    uVar12 = uVar12 + 1;
  } while (uVar12 < param_4);
LAB_00116c0c:
  *(uint *)(param_1 + 0x50) = param_4 + 1 + uVar16;
  return 1;
}



undefined4 chacha_cipher(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  int iVar10;
  bool bVar11;
  bool bVar12;
  
  iVar10 = *(int *)(param_1 + 0x60);
  uVar7 = *(uint *)(iVar10 + 0x70);
  if (uVar7 != 0) {
    uVar2 = param_4;
    if (param_4 != 0) {
      uVar2 = 1;
    }
    if (0x3f < uVar7) {
      uVar2 = 0;
    }
    if (uVar2 != 0) {
      pbVar4 = (byte *)(uVar7 + 0x2f + iVar10);
      puVar6 = param_3;
      puVar5 = param_2;
      do {
        param_4 = param_4 - 1;
        param_3 = (uint *)((int)puVar6 + 1);
        pbVar4 = pbVar4 + 1;
        uVar7 = uVar7 + 1;
        param_2 = (uint *)((int)puVar5 + 1);
        *(byte *)puVar5 = *pbVar4 ^ (byte)*puVar6;
        puVar6 = param_3;
        puVar5 = param_2;
      } while (uVar7 < 0x40 && param_4 != 0);
    }
    *(uint *)(iVar10 + 0x70) = uVar7;
    if (param_4 == 0) {
      return 1;
    }
    if (uVar7 == 0x40) {
      *(undefined4 *)(iVar10 + 0x70) = 0;
      uVar7 = *(int *)(iVar10 + 0x20) + 1;
      *(uint *)(iVar10 + 0x20) = uVar7;
      if (uVar7 == 0) {
        *(int *)(iVar10 + 0x24) = *(int *)(iVar10 + 0x24) + 1;
      }
      goto LAB_0012cf62;
    }
  }
  uVar7 = *(uint *)(iVar10 + 0x20);
LAB_0012cf62:
  uVar2 = param_4 & 0x3f;
  param_4 = param_4 - uVar2;
  if (0x3f < param_4) {
    puVar6 = param_3;
    puVar5 = param_2;
    do {
      while( true ) {
        uVar8 = param_4 >> 6;
        if (CARRY4(uVar8,uVar7)) break;
        param_4 = param_4 + uVar8 * -0x40;
        param_3 = puVar6 + uVar8 * 0x10;
        param_2 = puVar5 + uVar8 * 0x10;
        ChaCha20_ctr32(puVar5,puVar6,uVar8 * 0x40,iVar10,iVar10 + 0x20);
        *(uint *)(iVar10 + 0x20) = uVar8 + uVar7;
        puVar6 = param_3;
        puVar5 = param_2;
        uVar7 = uVar8 + uVar7;
        if (param_4 < 0x40) goto LAB_0012cfd8;
      }
      ChaCha20_ctr32(puVar5,puVar6,uVar7 * -0x40,iVar10,iVar10 + 0x20);
      param_4 = param_4 + uVar7 * 0x40;
      param_3 = puVar6 + uVar7 * -0x10;
      param_2 = puVar5 + uVar7 * -0x10;
      uVar7 = 0;
      *(undefined4 *)(iVar10 + 0x20) = 0;
      *(int *)(iVar10 + 0x24) = *(int *)(iVar10 + 0x24) + 1;
      puVar6 = param_3;
      puVar5 = param_2;
    } while (0x3f < param_4);
  }
LAB_0012cfd8:
  if (uVar2 == 0) {
    return 1;
  }
  puVar5 = (uint *)(iVar10 + 0x30);
  memset(puVar5,0,0x40);
  ChaCha20_ctr32(puVar5,puVar5,0x40,iVar10,iVar10 + 0x20);
  puVar6 = param_2 + 1;
  bVar12 = param_2 <= (uint *)(iVar10 + 0x34);
  bVar11 = (uint *)(iVar10 + 0x34) == param_2;
  if (bVar12 && !bVar11) {
    bVar12 = puVar5 <= puVar6;
    bVar11 = puVar6 == puVar5;
  }
  if ((((uint)param_2 | (uint)param_3) & 3) != 0 ||
      (uVar2 < 7 || (param_3 < puVar6 && param_2 < param_3 + 1 || bVar12 && !bVar11))) {
    pbVar9 = (byte *)((int)param_2 + -1);
    pbVar1 = (byte *)(iVar10 + 0x2f);
    pbVar4 = (byte *)((int)param_3 + -1);
    do {
      pbVar4 = pbVar4 + 1;
      pbVar1 = pbVar1 + 1;
      pbVar9 = pbVar9 + 1;
      *pbVar9 = *pbVar4 ^ *pbVar1;
    } while (pbVar4 != (byte *)((uVar2 - 1) + (int)param_3));
  }
  else {
    iVar3 = (uVar2 - 4 >> 2) + 1;
    *param_2 = *param_3 ^ *(uint *)(iVar10 + 0x30);
    uVar7 = iVar3 * 4;
    if (((((iVar3 != 1) && (param_2[1] = *(uint *)(iVar10 + 0x34) ^ param_3[1], iVar3 != 2)) &&
         (param_2[2] = *(uint *)(iVar10 + 0x38) ^ param_3[2], iVar3 != 3)) &&
        ((((param_2[3] = *(uint *)(iVar10 + 0x3c) ^ param_3[3], iVar3 != 4 &&
           (param_2[4] = *(uint *)(iVar10 + 0x40) ^ param_3[4], iVar3 != 5)) &&
          ((param_2[5] = *(uint *)(iVar10 + 0x44) ^ param_3[5], iVar3 != 6 &&
           ((param_2[6] = *(uint *)(iVar10 + 0x48) ^ param_3[6], iVar3 != 7 &&
            (param_2[7] = *(uint *)(iVar10 + 0x4c) ^ param_3[7], iVar3 != 8)))))) &&
         (param_2[8] = *(uint *)(iVar10 + 0x50) ^ param_3[8], iVar3 != 9)))) &&
       ((((param_2[9] = *(uint *)(iVar10 + 0x54) ^ param_3[9], iVar3 != 10 &&
          (param_2[10] = *(uint *)(iVar10 + 0x58) ^ param_3[10], iVar3 != 0xb)) &&
         (param_2[0xb] = *(uint *)(iVar10 + 0x5c) ^ param_3[0xb], iVar3 != 0xc)) &&
        ((param_2[0xc] = *(uint *)(iVar10 + 0x60) ^ param_3[0xc], iVar3 != 0xd &&
         (param_2[0xd] = *(uint *)(iVar10 + 100) ^ param_3[0xd], iVar3 == 0xf)))))) {
      param_2[0xe] = *(uint *)(iVar10 + 0x68) ^ param_3[0xe];
    }
    if (uVar2 != uVar7) {
      uVar8 = uVar7 + 1;
      *(byte *)(param_2 + iVar3) = *(byte *)(iVar10 + uVar7 + 0x30) ^ (byte)param_3[iVar3];
      if (uVar8 < uVar2) {
        uVar7 = uVar7 + 2;
        *(byte *)((int)param_2 + uVar8) =
             *(byte *)((int)param_3 + uVar8) ^ *(byte *)(iVar10 + uVar8 + 0x30);
        if (uVar7 < uVar2) {
          *(byte *)((int)param_2 + uVar7) =
               *(byte *)(iVar10 + uVar7 + 0x30) ^ *(byte *)((int)param_3 + uVar7);
        }
      }
    }
  }
  *(uint *)(iVar10 + 0x70) = uVar2;
  return 1;
}


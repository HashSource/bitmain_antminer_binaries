
void CRYPTO_cbc128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  byte *pbVar1;
  byte *pbVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  puVar3 = param_5;
  if ((((uint)param_5 | (uint)param_2 | (uint)param_1) & 3) == 0) {
    puVar7 = param_2;
    puVar8 = param_1;
    uVar10 = param_3;
    if (0xf < param_3) {
      do {
        puVar5 = puVar7;
        uVar10 = uVar10 - 0x10;
        *puVar5 = *puVar8 ^ *puVar3;
        puVar5[1] = puVar8[1] ^ puVar3[1];
        puVar5[2] = puVar8[2] ^ puVar3[2];
        puVar5[3] = puVar8[3] ^ puVar3[3];
        (*param_6)(puVar5,puVar5,param_4);
        puVar7 = puVar5 + 4;
        puVar8 = puVar8 + 4;
        puVar3 = puVar5;
      } while (0xf < uVar10);
LAB_00183260:
      uVar10 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      uVar10 = uVar10 >> 4;
      iVar6 = uVar10 + 1;
      puVar3 = param_2 + uVar10 * 4;
      param_1 = param_1 + iVar6 * 4;
      param_2 = param_2 + iVar6 * 4;
    }
  }
  else {
    puVar7 = param_2;
    puVar8 = param_1;
    uVar10 = param_3;
    if (0xf < param_3) {
      do {
        uVar10 = uVar10 - 0x10;
        *(byte *)puVar7 = (byte)*puVar3 ^ (byte)*puVar8;
        *(byte *)((int)puVar7 + 1) = *(byte *)((int)puVar3 + 1) ^ *(byte *)((int)puVar8 + 1);
        *(byte *)((int)puVar7 + 2) = *(byte *)((int)puVar3 + 2) ^ *(byte *)((int)puVar8 + 2);
        *(byte *)((int)puVar7 + 3) = *(byte *)((int)puVar3 + 3) ^ *(byte *)((int)puVar8 + 3);
        *(byte *)(puVar7 + 1) = (byte)puVar3[1] ^ (byte)puVar8[1];
        *(byte *)((int)puVar7 + 5) = *(byte *)((int)puVar3 + 5) ^ *(byte *)((int)puVar8 + 5);
        *(byte *)((int)puVar7 + 6) = *(byte *)((int)puVar3 + 6) ^ *(byte *)((int)puVar8 + 6);
        *(byte *)((int)puVar7 + 7) = *(byte *)((int)puVar3 + 7) ^ *(byte *)((int)puVar8 + 7);
        *(byte *)(puVar7 + 2) = (byte)puVar3[2] ^ (byte)puVar8[2];
        *(byte *)((int)puVar7 + 9) = *(byte *)((int)puVar3 + 9) ^ *(byte *)((int)puVar8 + 9);
        *(byte *)((int)puVar7 + 10) = *(byte *)((int)puVar3 + 10) ^ *(byte *)((int)puVar8 + 10);
        *(byte *)((int)puVar7 + 0xb) = *(byte *)((int)puVar3 + 0xb) ^ *(byte *)((int)puVar8 + 0xb);
        *(byte *)(puVar7 + 3) = (byte)puVar3[3] ^ (byte)puVar8[3];
        *(byte *)((int)puVar7 + 0xd) = *(byte *)((int)puVar3 + 0xd) ^ *(byte *)((int)puVar8 + 0xd);
        *(byte *)((int)puVar7 + 0xe) = *(byte *)((int)puVar3 + 0xe) ^ *(byte *)((int)puVar8 + 0xe);
        *(byte *)((int)puVar7 + 0xf) = *(byte *)((int)puVar3 + 0xf) ^ *(byte *)((int)puVar8 + 0xf);
        (*param_6)(puVar7,puVar7,param_4);
        puVar3 = puVar7;
        puVar7 = puVar7 + 4;
        puVar8 = puVar8 + 4;
      } while (0xf < uVar10);
      goto LAB_00183260;
    }
  }
  uVar10 = 0;
  if (param_3 == 0) goto LAB_0018331e;
  do {
    *(byte *)((int)param_2 + uVar10) =
         *(byte *)((int)param_1 + uVar10) ^ *(byte *)((int)puVar3 + uVar10);
    uVar10 = uVar10 + 1;
  } while (uVar10 < 0x10 && uVar10 < param_3);
  if (uVar10 < 0x10) {
    pbVar9 = (byte *)((int)puVar3 + uVar10);
    pbVar1 = (byte *)((int)param_2 + uVar10);
    uVar11 = ~uVar10 + 0x11;
    uVar12 = uVar11 >> 2;
    if (uVar12 != 0 &&
        ((((uint)pbVar1 | (uint)pbVar9) & 3) == 0 &&
        (3 < uVar11 && (pbVar1 + 4 <= pbVar9 || pbVar9 + 4 <= pbVar1)))) {
      pbVar9 = pbVar9 + -4;
      uVar4 = 0;
      pbVar2 = pbVar1 + 4;
      do {
        pbVar9 = pbVar9 + 4;
        uVar4 = uVar4 + 1;
        *(undefined4 *)pbVar1 = *(undefined4 *)pbVar9;
        pbVar1 = pbVar2;
        pbVar2 = pbVar2 + 4;
      } while (uVar4 < uVar12);
      uVar10 = uVar10 + uVar12 * 4;
      if (uVar11 == uVar12 * 4) goto LAB_00183314;
    }
    do {
      *(byte *)((int)param_2 + uVar10) = *(byte *)((int)puVar3 + uVar10);
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x10);
  }
LAB_00183314:
  (*param_6)(param_2,param_2,param_4);
  puVar3 = param_2;
LAB_0018331e:
  uVar10 = puVar3[1];
  uVar11 = puVar3[2];
  uVar12 = puVar3[3];
  *param_5 = *puVar3;
  param_5[1] = uVar10;
  param_5[2] = uVar11;
  param_5[3] = uVar12;
  return;
}


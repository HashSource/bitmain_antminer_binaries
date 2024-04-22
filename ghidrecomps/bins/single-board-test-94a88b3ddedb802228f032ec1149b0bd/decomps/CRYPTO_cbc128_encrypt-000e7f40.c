
void CRYPTO_cbc128_encrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  
  puVar7 = param_5;
  if ((((uint)param_5 | (uint)param_2 | (uint)param_1) & 3) == 0) {
    puVar6 = param_2;
    puVar8 = param_1;
    uVar10 = param_3;
    if (0xf < param_3) {
      do {
        puVar4 = puVar6;
        uVar10 = uVar10 - 0x10;
        *puVar4 = *puVar8 ^ *puVar7;
        puVar4[1] = puVar8[1] ^ puVar7[1];
        puVar4[2] = puVar8[2] ^ puVar7[2];
        puVar4[3] = puVar8[3] ^ puVar7[3];
        (*param_6)(puVar4,puVar4,param_4);
        puVar6 = puVar4 + 4;
        puVar8 = puVar8 + 4;
        puVar7 = puVar4;
      } while (0xf < uVar10);
LAB_000e7fbc:
      uVar10 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar5 = (uVar10 >> 4) + 1;
      puVar7 = (uint *)((int)param_2 + (uVar10 & 0xfffffff0));
      param_1 = param_1 + iVar5 * 4;
      param_2 = param_2 + iVar5 * 4;
    }
  }
  else {
    puVar6 = param_2;
    puVar8 = param_1;
    uVar10 = param_3;
    if (0xf < param_3) {
      do {
        uVar10 = uVar10 - 0x10;
        *(byte *)puVar6 = *(byte *)puVar7 ^ *(byte *)puVar8;
        *(byte *)((int)puVar6 + 1) = *(byte *)((int)puVar7 + 1) ^ *(byte *)((int)puVar8 + 1);
        *(byte *)((int)puVar6 + 2) = *(byte *)((int)puVar7 + 2) ^ *(byte *)((int)puVar8 + 2);
        *(byte *)((int)puVar6 + 3) = *(byte *)((int)puVar7 + 3) ^ *(byte *)((int)puVar8 + 3);
        *(byte *)(puVar6 + 1) = *(byte *)(puVar7 + 1) ^ *(byte *)(puVar8 + 1);
        *(byte *)((int)puVar6 + 5) = *(byte *)((int)puVar7 + 5) ^ *(byte *)((int)puVar8 + 5);
        *(byte *)((int)puVar6 + 6) = *(byte *)((int)puVar7 + 6) ^ *(byte *)((int)puVar8 + 6);
        *(byte *)((int)puVar6 + 7) = *(byte *)((int)puVar7 + 7) ^ *(byte *)((int)puVar8 + 7);
        *(byte *)(puVar6 + 2) = *(byte *)(puVar7 + 2) ^ *(byte *)(puVar8 + 2);
        *(byte *)((int)puVar6 + 9) = *(byte *)((int)puVar7 + 9) ^ *(byte *)((int)puVar8 + 9);
        *(byte *)((int)puVar6 + 10) = *(byte *)((int)puVar7 + 10) ^ *(byte *)((int)puVar8 + 10);
        *(byte *)((int)puVar6 + 0xb) = *(byte *)((int)puVar7 + 0xb) ^ *(byte *)((int)puVar8 + 0xb);
        *(byte *)(puVar6 + 3) = *(byte *)(puVar7 + 3) ^ *(byte *)(puVar8 + 3);
        *(byte *)((int)puVar6 + 0xd) = *(byte *)((int)puVar7 + 0xd) ^ *(byte *)((int)puVar8 + 0xd);
        *(byte *)((int)puVar6 + 0xe) = *(byte *)((int)puVar7 + 0xe) ^ *(byte *)((int)puVar8 + 0xe);
        *(byte *)((int)puVar6 + 0xf) = *(byte *)((int)puVar7 + 0xf) ^ *(byte *)((int)puVar8 + 0xf);
        (*param_6)(puVar6,puVar6,param_4);
        puVar7 = puVar6;
        puVar6 = puVar6 + 4;
        puVar8 = puVar8 + 4;
      } while (0xf < uVar10);
      goto LAB_000e7fbc;
    }
  }
  uVar10 = 0;
  if (param_3 == 0) goto LAB_000e807a;
  do {
    *(byte *)((int)param_2 + uVar10) =
         *(byte *)((int)param_1 + uVar10) ^ *(byte *)((int)puVar7 + uVar10);
    uVar10 = uVar10 + 1;
  } while (uVar10 < 0x10 && uVar10 < param_3);
  if (uVar10 < 0x10) {
    puVar9 = (undefined4 *)((int)puVar7 + uVar10);
    puVar1 = (undefined4 *)((int)param_2 + uVar10);
    uVar11 = ~uVar10 + 0x11;
    if (uVar11 >> 2 != 0 &&
        ((((uint)puVar1 | (uint)puVar9) & 3) == 0 &&
        (3 < uVar11 && (puVar1 + 1 <= puVar9 || puVar9 + 1 <= puVar1)))) {
      puVar9 = puVar9 + -1;
      uVar3 = 0;
      puVar2 = puVar1 + 1;
      do {
        puVar9 = puVar9 + 1;
        uVar3 = uVar3 + 1;
        *puVar1 = *puVar9;
        puVar1 = puVar2;
        puVar2 = puVar2 + 1;
      } while (uVar3 < uVar11 >> 2);
      uVar10 = uVar10 + (uVar11 & 0xfffffffc);
      if (uVar11 == (uVar11 & 0xfffffffc)) goto LAB_000e8070;
    }
    do {
      *(byte *)((int)param_2 + uVar10) = *(byte *)((int)puVar7 + uVar10);
      uVar10 = uVar10 + 1;
    } while (uVar10 < 0x10);
  }
LAB_000e8070:
  (*param_6)(param_2,param_2,param_4);
  puVar7 = param_2;
LAB_000e807a:
  uVar10 = puVar7[1];
  uVar11 = puVar7[2];
  uVar3 = puVar7[3];
  *param_5 = *puVar7;
  param_5[1] = uVar10;
  param_5[2] = uVar11;
  param_5[3] = uVar3;
  return;
}



undefined4 CRYPTO_gcm128_aad(int param_1,uint *param_2,uint param_3)

{
  byte *pbVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  bool bVar12;
  
  if ((*(uint *)(param_1 + 0x38) | *(uint *)(param_1 + 0x3c)) != 0) {
    return 0xfffffffe;
  }
  iVar7 = *(uint *)(param_1 + 0x30) + param_3;
  uVar8 = *(int *)(param_1 + 0x34) + (uint)CARRY4(*(uint *)(param_1 + 0x30),param_3);
  bVar12 = 0x1fffffff < uVar8;
  if (uVar8 == 0x20000000) {
    bVar12 = iVar7 != 0;
  }
  if (bVar12) {
    return 0xffffffff;
  }
  uVar6 = *(uint *)(param_1 + 0x16c);
  *(int *)(param_1 + 0x30) = iVar7;
  *(uint *)(param_1 + 0x34) = uVar8;
  puVar4 = param_2;
  if (uVar6 != 0) {
    if (param_3 == 0) {
LAB_000ebc34:
      *(uint *)(param_1 + 0x16c) = uVar6;
      return 0;
    }
    do {
      iVar7 = param_1 + uVar6;
      puVar4 = (uint *)((int)param_2 + 1);
      uVar8 = uVar6 + 1 & 0xf;
      uVar6 = uVar6 + 1 & 0xf;
      if (uVar8 != 0) {
        uVar8 = 1;
      }
      param_3 = param_3 - 1;
      if (param_3 == 0) {
        uVar8 = 0;
      }
      else {
        uVar8 = uVar8 & 1;
      }
      *(byte *)(iVar7 + 0x40) = *(byte *)param_2 ^ *(byte *)(iVar7 + 0x40);
      param_2 = puVar4;
    } while (uVar8 != 0);
    if (uVar6 != 0) goto LAB_000ebc34;
    gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
  }
  uVar8 = param_3 & 0xfffffff0;
  if (uVar8 != 0) {
    param_3 = param_3 - uVar8;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar4);
    puVar4 = (uint *)((int)puVar4 + uVar8);
  }
  if (param_3 != 0) {
    puVar10 = (uint *)(param_1 + 0x40);
    uVar6 = param_3 >> 2;
    uVar8 = param_3 & 0xfffffffc;
    if (uVar6 == 0 ||
        (param_3 < 4 ||
        (((uint)puVar4 & 3) != 0 || puVar4 < (uint *)(param_1 + 0x44) && puVar10 < puVar4 + 1))) {
      uVar8 = 0;
    }
    else {
      if (uVar6 < 9) {
        uVar5 = 0;
        puVar11 = puVar4;
      }
      else {
        uVar5 = 0;
        puVar3 = (uint *)(param_1 + 0x60);
        puVar2 = puVar4;
        do {
          puVar10 = puVar3;
          puVar11 = puVar2 + 8;
          uVar9 = uVar5 + 9;
          uVar5 = uVar5 + 8;
          HintPreloadData(puVar10 + 0xc);
          puVar10[-8] = puVar10[-8] ^ *puVar2;
          puVar10[-7] = puVar2[1] ^ puVar10[-7];
          puVar10[-6] = puVar2[2] ^ puVar10[-6];
          puVar10[-5] = puVar2[3] ^ puVar10[-5];
          puVar10[-4] = puVar2[4] ^ puVar10[-4];
          puVar10[-3] = puVar2[5] ^ puVar10[-3];
          puVar10[-2] = puVar2[6] ^ puVar10[-2];
          puVar10[-1] = puVar2[7] ^ puVar10[-1];
          puVar3 = puVar10 + 8;
          puVar2 = puVar11;
        } while (uVar9 < uVar6 - 7);
      }
      iVar7 = 0;
      do {
        uVar5 = uVar5 + 1;
        *(uint *)((int)puVar10 + iVar7) =
             *(uint *)((int)puVar10 + iVar7) ^ *(uint *)((int)puVar11 + iVar7);
        iVar7 = iVar7 + 4;
      } while (uVar5 < uVar6);
      if (param_3 == uVar8) goto LAB_000ebd8a;
    }
    do {
      iVar7 = param_1 + uVar8;
      pbVar1 = (byte *)((int)puVar4 + uVar8);
      uVar8 = uVar8 + 1;
      *(byte *)(iVar7 + 0x40) = *(byte *)(iVar7 + 0x40) ^ *pbVar1;
    } while (uVar8 < param_3);
  }
LAB_000ebd8a:
  *(uint *)(param_1 + 0x16c) = param_3;
  return 0;
}


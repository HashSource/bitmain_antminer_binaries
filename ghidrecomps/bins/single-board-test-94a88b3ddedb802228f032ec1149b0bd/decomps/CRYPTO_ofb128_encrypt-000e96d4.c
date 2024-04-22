
void CRYPTO_ofb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,uint param_5,
               uint *param_6,code *param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  uVar5 = *param_6;
  pbVar6 = param_1;
  pbVar7 = param_2;
  if (uVar5 != 0 && param_3 != 0) {
    do {
      pbVar8 = (byte *)(param_5 + uVar5);
      param_1 = pbVar6 + 1;
      uVar1 = uVar5 + 1 & 0xf;
      if (uVar1 != 0) {
        uVar1 = 1;
      }
      param_3 = param_3 - 1;
      uVar5 = uVar5 + 1 & 0xf;
      if (param_3 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 & 1;
      }
      param_2 = pbVar7 + 1;
      *pbVar7 = *pbVar6 ^ *pbVar8;
      pbVar6 = param_1;
      pbVar7 = param_2;
    } while (uVar1 != 0);
  }
  if ((((uint)param_1 | (uint)param_2 | param_5) & 3) != 0) {
    if (param_3 != 0) {
      uVar1 = 0;
      do {
        if (uVar5 == 0) {
          (*param_7)(param_5,param_5,param_4);
        }
        pbVar6 = (byte *)(param_5 + uVar5);
        uVar5 = uVar5 + 1 & 0xf;
        param_2[uVar1] = param_1[uVar1] ^ *pbVar6;
        uVar1 = uVar1 + 1;
      } while (uVar1 != param_3);
    }
    *param_6 = uVar5;
    return;
  }
  pbVar6 = param_1;
  pbVar7 = param_2;
  uVar1 = param_3;
  if (0xf < param_3) {
    do {
      (*param_7)(param_5,param_5,param_4);
      for (; uVar5 < 0x10; uVar5 = uVar5 + 4) {
        *(uint *)(pbVar7 + uVar5) = *(uint *)(pbVar6 + uVar5) ^ *(uint *)(param_5 + uVar5);
      }
      uVar1 = uVar1 - 0x10;
      uVar5 = 0;
      pbVar6 = pbVar6 + 0x10;
      pbVar7 = pbVar7 + 0x10;
    } while (0xf < uVar1);
    uVar5 = param_3 - 0x10;
    param_3 = param_3 & 0xf;
    iVar3 = (uVar5 & 0xfffffff0) + 0x10;
    param_2 = param_2 + iVar3;
    param_1 = param_1 + iVar3;
    uVar5 = 0;
  }
  if (param_3 == 0) goto LAB_000e9798;
  pbVar6 = param_2 + uVar5;
  pbVar7 = param_1 + uVar5;
  (*param_7)(param_5,param_5,param_4);
  pbVar8 = (byte *)(param_5 + uVar5);
  uVar2 = param_3 & 0xfffffffc;
  iVar3 = param_3 - 1;
  uVar1 = uVar5;
  if (param_3 >> 2 == 0 ||
      ((((uint)pbVar8 | (uint)pbVar7 | (uint)pbVar6) & 3) != 0 ||
      (param_3 < 4 ||
      (pbVar6 < pbVar7 + 4 && pbVar7 < pbVar6 + 4 || pbVar6 < pbVar8 + 4 && pbVar8 < pbVar6 + 4))))
  {
LAB_000e986e:
    iVar3 = uVar1 + iVar3;
    do {
      param_2[uVar1] = param_1[uVar1] ^ *(byte *)(param_5 + uVar1);
      uVar1 = uVar1 + 1;
    } while (uVar1 != iVar3 + 1U);
  }
  else {
    uVar1 = 0;
    iVar4 = 0;
    do {
      uVar1 = uVar1 + 1;
      *(uint *)(pbVar6 + iVar4) = *(uint *)(pbVar8 + iVar4) ^ *(uint *)(pbVar7 + iVar4);
      iVar4 = iVar4 + 4;
    } while (uVar1 < param_3 >> 2);
    iVar3 = iVar3 - uVar2;
    uVar1 = uVar2 + uVar5;
    if (param_3 != uVar2) goto LAB_000e986e;
  }
  uVar5 = uVar5 + param_3;
LAB_000e9798:
  *param_6 = uVar5;
  return;
}


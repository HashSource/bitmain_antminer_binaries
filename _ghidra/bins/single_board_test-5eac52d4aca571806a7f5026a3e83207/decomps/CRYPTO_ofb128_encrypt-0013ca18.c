
void CRYPTO_ofb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,uint param_5,
               uint *param_6,code *param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  
  uVar6 = *param_6;
  pbVar7 = param_1;
  pbVar9 = param_2;
  if (uVar6 != 0 && param_3 != 0) {
    do {
      pbVar11 = (byte *)(param_5 + uVar6);
      uVar4 = uVar6 + 1 & 0xf;
      param_1 = pbVar7 + 1;
      if (uVar4 != 0) {
        uVar4 = 1;
      }
      param_3 = param_3 - 1;
      uVar4 = uVar4 & 1;
      if (param_3 == 0) {
        uVar4 = 0;
      }
      uVar6 = uVar6 + 1 & 0xf;
      param_2 = pbVar9 + 1;
      *pbVar9 = *pbVar7 ^ *pbVar11;
      pbVar7 = param_1;
      pbVar9 = param_2;
    } while (uVar4 != 0);
  }
  if ((((uint)param_2 | (uint)param_1 | param_5) & 3) != 0) {
    if (param_3 != 0) {
      param_2 = param_2 + -1;
      pbVar7 = param_1;
      do {
        if (uVar6 == 0) {
          (*param_7)(param_5,param_5,param_4);
        }
        pbVar11 = pbVar7 + 1;
        pbVar9 = (byte *)(param_5 + uVar6);
        uVar6 = uVar6 + 1 & 0xf;
        param_2 = param_2 + 1;
        *param_2 = *pbVar9 ^ *pbVar7;
        pbVar7 = pbVar11;
      } while (pbVar11 != param_1 + param_3);
    }
LAB_0013cb1c:
    *param_6 = uVar6;
    return;
  }
  uVar4 = uVar6;
  pbVar7 = param_1;
  pbVar9 = param_2;
  uVar8 = param_3;
  if (param_3 < 0x10) {
    if (param_3 == 0) goto LAB_0013cb1c;
    (*param_7)(param_5,param_5,param_4);
    iVar3 = param_3 - 1;
  }
  else {
    do {
      (*param_7)(param_5,param_5,param_4);
      uVar10 = uVar4 + 4;
      uVar6 = uVar4 + 8;
      uVar5 = uVar4 + 0xc;
      if ((((uVar4 < 0x10) &&
           (*(uint *)(pbVar9 + uVar4) = *(uint *)(param_5 + uVar4) ^ *(uint *)(pbVar7 + uVar4),
           uVar10 < 0x10)) &&
          (*(uint *)(pbVar9 + uVar10) = *(uint *)(param_5 + uVar10) ^ *(uint *)(pbVar7 + uVar10),
          uVar6 < 0x10)) &&
         (*(uint *)(pbVar9 + uVar6) = *(uint *)(param_5 + uVar6) ^ *(uint *)(pbVar7 + uVar6),
         uVar5 < 0x10)) {
        *(uint *)(pbVar9 + uVar5) = *(uint *)(param_5 + uVar5) ^ *(uint *)(pbVar7 + uVar5);
      }
      uVar8 = uVar8 - 0x10;
      uVar6 = 0;
      uVar4 = 0;
      pbVar7 = pbVar7 + 0x10;
      pbVar9 = pbVar9 + 0x10;
    } while (0xf < uVar8);
    uVar4 = param_3 - 0x10 >> 4;
    iVar3 = (uVar4 + 1) * 0x10;
    param_2 = param_2 + iVar3;
    param_1 = param_1 + iVar3;
    if ((param_3 & 0xf) == 0) {
      uVar6 = 0;
      goto LAB_0013cb1c;
    }
    (*param_7)(param_5,param_5,param_4);
    iVar3 = (param_3 - 0x11) + uVar4 * -0x10;
  }
  iVar2 = uVar6 + 4;
  pbVar9 = (byte *)(param_5 + uVar6);
  pbVar7 = param_1 + uVar6;
  pbVar11 = param_2 + uVar6;
  if ((((uint)pbVar11 | (uint)pbVar7 | (uint)pbVar9) & 3) == 0 &&
      (6 < iVar3 + 1U &&
      (((byte *)(param_5 + iVar2) <= pbVar11 || param_2 + iVar2 <= pbVar9) &&
      (param_1 + iVar2 <= pbVar11 || param_2 + iVar2 <= pbVar7)))) {
    uVar4 = (iVar3 - 3U >> 2) + 1;
    *(uint *)(param_2 + uVar6) = *(uint *)(param_1 + uVar6) ^ *(uint *)(param_5 + uVar6);
    if (uVar4 != 1) {
      *(uint *)(pbVar11 + 4) = *(uint *)(pbVar9 + 4) ^ *(uint *)(pbVar7 + 4);
      uVar8 = uVar4;
      if (uVar4 == 3) {
        uVar8 = *(uint *)(pbVar9 + 8) ^ *(uint *)(pbVar7 + 8);
      }
      if (uVar4 == 3) {
        *(uint *)(pbVar11 + 8) = uVar8;
      }
    }
    iVar2 = uVar6 + uVar4 * 4;
    iVar12 = iVar3 + uVar4 * -4;
    if (uVar4 * 4 == iVar3 + 1U) goto LAB_0013cc4e;
    iVar1 = iVar2 + 1;
    param_2[iVar2] = param_1[iVar2] ^ *(byte *)(param_5 + iVar2);
    if (iVar12 == 0) goto LAB_0013cc4e;
    iVar2 = iVar2 + 2;
    param_2[iVar1] = param_1[iVar1] ^ *(byte *)(param_5 + iVar1);
    if (iVar12 == 1) goto LAB_0013cc4e;
  }
  else {
    iVar12 = uVar6 + 1;
    param_2[uVar6] = *(byte *)(param_5 + uVar6) ^ param_1[uVar6];
    if (iVar3 == 0) goto LAB_0013cc4e;
    iVar1 = uVar6 + 2;
    param_2[iVar12] = param_1[iVar12] ^ *(byte *)(param_5 + iVar12);
    if (iVar3 == 1) goto LAB_0013cc4e;
    iVar12 = uVar6 + 3;
    param_2[iVar1] = param_1[iVar1] ^ *(byte *)(param_5 + iVar1);
    if ((iVar3 == 2) ||
       (param_2[iVar12] = param_1[iVar12] ^ *(byte *)(param_5 + iVar12), iVar3 == 3))
    goto LAB_0013cc4e;
    iVar12 = uVar6 + 5;
    param_2[iVar2] = param_1[iVar2] ^ *(byte *)(param_5 + iVar2);
    if (iVar3 == 4) goto LAB_0013cc4e;
    iVar2 = uVar6 + 6;
    param_2[iVar12] = param_1[iVar12] ^ *(byte *)(param_5 + iVar12);
    if (iVar3 == 5) goto LAB_0013cc4e;
    iVar12 = uVar6 + 7;
    param_2[iVar2] = param_1[iVar2] ^ *(byte *)(param_5 + iVar2);
    if (iVar3 == 6) goto LAB_0013cc4e;
    iVar2 = uVar6 + 8;
    param_2[iVar12] = param_1[iVar12] ^ *(byte *)(param_5 + iVar12);
    if (iVar3 == 7) goto LAB_0013cc4e;
    iVar12 = uVar6 + 9;
    param_2[iVar2] = param_1[iVar2] ^ *(byte *)(param_5 + iVar2);
    if (iVar3 == 8) goto LAB_0013cc4e;
    iVar2 = uVar6 + 10;
    param_2[iVar12] = param_1[iVar12] ^ *(byte *)(param_5 + iVar12);
    if (iVar3 == 9) goto LAB_0013cc4e;
    iVar12 = uVar6 + 0xb;
    param_2[iVar2] = param_1[iVar2] ^ *(byte *)(param_5 + iVar2);
    if (iVar3 == 10) goto LAB_0013cc4e;
    iVar2 = uVar6 + 0xc;
    param_2[iVar12] = param_1[iVar12] ^ *(byte *)(param_5 + iVar12);
    if (iVar3 == 0xb) goto LAB_0013cc4e;
    iVar12 = uVar6 + 0xd;
    param_2[iVar2] = param_1[iVar2] ^ *(byte *)(param_5 + iVar2);
    if (iVar3 == 0xc) goto LAB_0013cc4e;
    iVar2 = uVar6 + 0xe;
    param_2[iVar12] = param_1[iVar12] ^ *(byte *)(param_5 + iVar12);
    if (iVar3 == 0xd) goto LAB_0013cc4e;
  }
  param_2[iVar2] = *(byte *)(param_5 + iVar2) ^ param_1[iVar2];
LAB_0013cc4e:
  *param_6 = uVar6 + iVar3 + 1;
  return;
}


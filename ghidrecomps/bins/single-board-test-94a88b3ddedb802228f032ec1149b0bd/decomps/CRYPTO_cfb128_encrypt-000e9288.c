
void CRYPTO_cfb128_encrypt
               (byte *param_1,byte *param_2,uint param_3,undefined4 param_4,uint param_5,
               uint *param_6,int param_7,code *param_8)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  byte bVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  int local_30;
  
  uVar7 = *param_6;
  if (param_7 == 0) {
    pbVar2 = param_1;
    pbVar4 = param_2;
    if (uVar7 != 0 && param_3 != 0) {
      do {
        pbVar2 = param_1 + 1;
        bVar10 = *param_1;
        uVar1 = uVar7 + 1 & 0xf;
        if (uVar1 != 0) {
          uVar1 = 1;
        }
        param_3 = param_3 - 1;
        if (param_3 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = uVar1 & 1;
        }
        pbVar4 = param_2 + 1;
        *param_2 = bVar10 ^ *(byte *)(param_5 + uVar7);
        *(byte *)(param_5 + uVar7) = bVar10;
        uVar7 = uVar7 + 1 & 0xf;
        param_1 = pbVar2;
        param_2 = pbVar4;
      } while (uVar1 != 0);
    }
    if ((((uint)pbVar2 | (uint)pbVar4 | param_5) & 3) != 0) {
      if (param_3 != 0) {
        uVar1 = 0;
        do {
          if (uVar7 == 0) {
            (*param_8)(param_5,param_5,param_4);
          }
          bVar10 = pbVar2[uVar1];
          pbVar4[uVar1] = *(byte *)(param_5 + uVar7) ^ bVar10;
          uVar1 = uVar1 + 1;
          *(byte *)(param_5 + uVar7) = bVar10;
          uVar7 = uVar7 + 1 & 0xf;
        } while (uVar1 != param_3);
      }
LAB_000e94f0:
      *param_6 = uVar7;
      return;
    }
    uVar1 = uVar7;
    uVar9 = param_3;
    pbVar11 = pbVar4;
    pbVar12 = pbVar2;
    if (0xf < param_3) {
      do {
        (*param_8)(param_5,param_5,param_4);
        for (; uVar7 < 0x10; uVar7 = uVar7 + 4) {
          uVar1 = *(uint *)(pbVar12 + uVar7);
          *(uint *)(pbVar11 + uVar7) = *(uint *)(param_5 + uVar7) ^ uVar1;
          *(uint *)(param_5 + uVar7) = uVar1;
        }
        uVar9 = uVar9 - 0x10;
        uVar7 = 0;
        uVar1 = 0;
        pbVar11 = pbVar11 + 0x10;
        pbVar12 = pbVar12 + 0x10;
      } while (0xf < uVar9);
      uVar7 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar5 = (uVar7 & 0xfffffff0) + 0x10;
      pbVar4 = pbVar4 + iVar5;
      pbVar2 = pbVar2 + iVar5;
    }
    if (param_3 != 0) {
      pbVar11 = (byte *)(param_5 + uVar1);
      pbVar13 = pbVar4 + uVar1;
      (*param_8)(param_5,param_5,param_4);
      pbVar12 = pbVar2 + uVar1;
      uVar9 = param_3 & 0xfffffffc;
      local_30 = param_3 - 1;
      uVar7 = uVar1;
      if (param_3 >> 2 != 0 &&
          ((((uint)pbVar12 | (uint)pbVar11 | (uint)pbVar13) & 3) == 0 &&
          ((3 < param_3 &&
           ((pbVar11 + 4 <= pbVar13 || pbVar13 + 4 <= pbVar11) &&
           (pbVar12 + 4 <= pbVar13 || pbVar13 + 4 <= pbVar12))) &&
          (pbVar12 + 4 <= pbVar11 || pbVar11 + 4 <= pbVar12)))) {
        uVar7 = 0;
        iVar5 = 0;
        do {
          uVar3 = *(uint *)(pbVar12 + iVar5);
          uVar7 = uVar7 + 1;
          *(uint *)(pbVar13 + iVar5) = uVar3 ^ *(uint *)(pbVar11 + iVar5);
          *(uint *)(pbVar11 + iVar5) = uVar3;
          iVar5 = iVar5 + 4;
        } while (uVar7 < param_3 >> 2);
        local_30 = local_30 - uVar9;
        uVar7 = uVar9 + uVar1;
        if (param_3 == uVar9) goto LAB_000e94c2;
      }
      local_30 = uVar7 + local_30;
      do {
        bVar10 = pbVar2[uVar7];
        pbVar4[uVar7] = *(byte *)(param_5 + uVar7) ^ bVar10;
        *(byte *)(param_5 + uVar7) = bVar10;
        uVar7 = uVar7 + 1;
      } while (uVar7 != local_30 + 1U);
LAB_000e94c2:
      *param_6 = uVar1 + param_3;
      return;
    }
  }
  else {
    pbVar2 = param_1;
    pbVar4 = param_2;
    if (uVar7 != 0 && param_3 != 0) {
      do {
        pbVar2 = param_1 + 1;
        uVar1 = uVar7 + 1 & 0xf;
        if (uVar1 != 0) {
          uVar1 = 1;
        }
        param_3 = param_3 - 1;
        if (param_3 == 0) {
          uVar1 = 0;
        }
        else {
          uVar1 = uVar1 & 1;
        }
        bVar10 = *param_1 ^ *(byte *)(param_5 + uVar7);
        *(byte *)(param_5 + uVar7) = bVar10;
        uVar7 = uVar7 + 1 & 0xf;
        pbVar4 = param_2 + 1;
        *param_2 = bVar10;
        param_1 = pbVar2;
        param_2 = pbVar4;
      } while (uVar1 != 0);
    }
    if ((((uint)pbVar2 | (uint)pbVar4 | param_5) & 3) != 0) {
      if (param_3 != 0) {
        uVar1 = 0;
        do {
          if (uVar7 == 0) {
            (*param_8)(param_5,param_5,param_4);
          }
          bVar10 = pbVar2[uVar1] ^ *(byte *)(param_5 + uVar7);
          *(byte *)(param_5 + uVar7) = bVar10;
          uVar7 = uVar7 + 1 & 0xf;
          pbVar4[uVar1] = bVar10;
          uVar1 = uVar1 + 1;
        } while (uVar1 != param_3);
      }
      goto LAB_000e94f0;
    }
    uVar1 = uVar7;
    uVar9 = param_3;
    pbVar11 = pbVar4;
    pbVar12 = pbVar2;
    if (0xf < param_3) {
      do {
        (*param_8)(param_5,param_5,param_4);
        for (; uVar7 < 0x10; uVar7 = uVar7 + 4) {
          uVar1 = *(uint *)(param_5 + uVar7) ^ *(uint *)(pbVar12 + uVar7);
          *(uint *)(param_5 + uVar7) = uVar1;
          *(uint *)(pbVar11 + uVar7) = uVar1;
        }
        uVar9 = uVar9 - 0x10;
        uVar7 = 0;
        uVar1 = 0;
        pbVar11 = pbVar11 + 0x10;
        pbVar12 = pbVar12 + 0x10;
      } while (0xf < uVar9);
      uVar7 = param_3 - 0x10;
      param_3 = param_3 & 0xf;
      iVar5 = (uVar7 & 0xfffffff0) + 0x10;
      pbVar4 = pbVar4 + iVar5;
      pbVar2 = pbVar2 + iVar5;
    }
    if (param_3 != 0) {
      pbVar11 = (byte *)(param_5 + uVar1);
      pbVar13 = pbVar4 + uVar1;
      (*param_8)(param_5,param_5,param_4);
      pbVar12 = pbVar2 + uVar1;
      iVar5 = param_3 - 1;
      uVar9 = param_3 & 0xfffffffc;
      uVar7 = uVar1;
      if (param_3 >> 2 != 0 &&
          ((((uint)pbVar12 | (uint)pbVar11 | (uint)pbVar13) & 3) == 0 &&
          ((3 < param_3 &&
           ((pbVar11 + 4 <= pbVar13 || pbVar13 + 4 <= pbVar11) &&
           (pbVar12 + 4 <= pbVar11 || pbVar11 + 4 <= pbVar12))) &&
          (pbVar12 + 4 <= pbVar13 || pbVar13 + 4 <= pbVar12)))) {
        uVar7 = 0;
        iVar6 = 0;
        do {
          uVar8 = *(uint *)(pbVar12 + iVar6);
          uVar7 = uVar7 + 1;
          uVar3 = *(uint *)(pbVar11 + iVar6);
          *(uint *)(pbVar11 + iVar6) = uVar8 ^ uVar3;
          *(uint *)(pbVar13 + iVar6) = uVar8 ^ uVar3;
          iVar6 = iVar6 + 4;
        } while (uVar7 < param_3 >> 2);
        iVar5 = iVar5 - uVar9;
        uVar7 = uVar9 + uVar1;
        if (param_3 == uVar9) goto LAB_000e94c2;
      }
      iVar5 = uVar7 + iVar5;
      do {
        bVar10 = *(byte *)(param_5 + uVar7) ^ pbVar2[uVar7];
        *(byte *)(param_5 + uVar7) = bVar10;
        pbVar4[uVar7] = bVar10;
        uVar7 = uVar7 + 1;
      } while (uVar7 != iVar5 + 1U);
      goto LAB_000e94c2;
    }
  }
  *param_6 = uVar1;
  return;
}


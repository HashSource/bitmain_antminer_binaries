
void CRYPTO_cbc128_encrypt
               (uint param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint local_30;
  
  if (param_3 == 0) {
    return;
  }
  puVar3 = param_5;
  local_30 = param_1;
  if (((param_1 | (uint)param_2 | (uint)param_5) & 3) == 0) {
    if (0xf < param_3) {
      puVar3 = param_2;
      iVar6 = param_1 + 0x10;
      uVar9 = param_3;
      puVar5 = param_5;
      do {
        puVar7 = puVar3;
        uVar9 = uVar9 - 0x10;
        *puVar7 = *puVar5 ^ *(uint *)(iVar6 + -0x10);
        puVar7[1] = puVar5[1] ^ *(uint *)(iVar6 + -0xc);
        puVar7[2] = puVar5[2] ^ *(uint *)(iVar6 + -8);
        puVar7[3] = puVar5[3] ^ *(uint *)(iVar6 + -4);
        (*param_6)(puVar7,puVar7,param_4);
        puVar3 = puVar7 + 4;
        iVar6 = iVar6 + 0x10;
        puVar5 = puVar7;
      } while (0xf < uVar9);
      goto LAB_0013579a;
    }
  }
  else if (0xf < param_3) {
    puVar5 = param_2;
    iVar6 = param_1 + 0x10;
    uVar9 = param_3;
    do {
      uVar9 = uVar9 - 0x10;
      *(byte *)puVar5 = (byte)*puVar3 ^ *(byte *)(iVar6 + -0x10);
      *(byte *)((int)puVar5 + 1) = *(byte *)(iVar6 + -0xf) ^ *(byte *)((int)puVar3 + 1);
      *(byte *)((int)puVar5 + 2) = *(byte *)(iVar6 + -0xe) ^ *(byte *)((int)puVar3 + 2);
      *(byte *)((int)puVar5 + 3) = *(byte *)(iVar6 + -0xd) ^ *(byte *)((int)puVar3 + 3);
      *(byte *)(puVar5 + 1) = *(byte *)(iVar6 + -0xc) ^ (byte)puVar3[1];
      *(byte *)((int)puVar5 + 5) = *(byte *)(iVar6 + -0xb) ^ *(byte *)((int)puVar3 + 5);
      *(byte *)((int)puVar5 + 6) = *(byte *)(iVar6 + -10) ^ *(byte *)((int)puVar3 + 6);
      *(byte *)((int)puVar5 + 7) = *(byte *)(iVar6 + -9) ^ *(byte *)((int)puVar3 + 7);
      *(byte *)(puVar5 + 2) = *(byte *)(iVar6 + -8) ^ (byte)puVar3[2];
      *(byte *)((int)puVar5 + 9) = *(byte *)(iVar6 + -7) ^ *(byte *)((int)puVar3 + 9);
      *(byte *)((int)puVar5 + 10) = *(byte *)(iVar6 + -6) ^ *(byte *)((int)puVar3 + 10);
      *(byte *)((int)puVar5 + 0xb) = *(byte *)(iVar6 + -5) ^ *(byte *)((int)puVar3 + 0xb);
      *(byte *)(puVar5 + 3) = *(byte *)(iVar6 + -4) ^ (byte)puVar3[3];
      *(byte *)((int)puVar5 + 0xd) = *(byte *)(iVar6 + -3) ^ *(byte *)((int)puVar3 + 0xd);
      *(byte *)((int)puVar5 + 0xe) = *(byte *)(iVar6 + -2) ^ *(byte *)((int)puVar3 + 0xe);
      *(byte *)((int)puVar5 + 0xf) = *(byte *)((int)puVar3 + 0xf) ^ *(byte *)(iVar6 + -1);
      (*param_6)(puVar5,puVar5,param_4);
      puVar3 = puVar5;
      puVar5 = puVar5 + 4;
      iVar6 = iVar6 + 0x10;
    } while (0xf < uVar9);
LAB_0013579a:
    uVar9 = param_3 - 0x10 >> 4;
    param_3 = param_3 & 0xf;
    iVar6 = uVar9 + 1;
    puVar5 = param_2 + uVar9 * 4;
    local_30 = param_1 + iVar6 * 0x10;
    param_2 = param_2 + iVar6 * 4;
    puVar3 = puVar5;
    if (param_3 == 0) goto LAB_00135888;
  }
  puVar5 = param_2;
  pbVar11 = (byte *)((int)puVar3 + -1);
  pbVar8 = (byte *)((int)puVar5 + -1);
  pbVar10 = (byte *)(local_30 - 1);
  uVar9 = 0;
  do {
    uVar2 = uVar9;
    pbVar10 = pbVar10 + 1;
    uVar9 = uVar2 + 1;
    pbVar11 = pbVar11 + 1;
    pbVar8 = pbVar8 + 1;
    *pbVar8 = *pbVar11 ^ *pbVar10;
  } while (uVar9 < param_3);
  iVar6 = uVar2 + 2;
  *(byte *)((int)puVar5 + uVar9) = *(byte *)((int)puVar3 + uVar9);
  if (iVar6 != 0x10) {
    iVar1 = uVar2 + 3;
    *(byte *)((int)puVar5 + iVar6) = *(byte *)((int)puVar3 + iVar6);
    if (iVar1 != 0x10) {
      iVar6 = uVar2 + 4;
      *(byte *)((int)puVar5 + iVar1) = *(byte *)((int)puVar3 + iVar1);
      if (iVar6 != 0x10) {
        iVar1 = uVar2 + 5;
        *(byte *)((int)puVar5 + iVar6) = *(byte *)((int)puVar3 + iVar6);
        if (iVar1 != 0x10) {
          iVar6 = uVar2 + 6;
          *(byte *)((int)puVar5 + iVar1) = *(byte *)((int)puVar3 + iVar1);
          if (iVar6 != 0x10) {
            iVar1 = uVar2 + 7;
            *(byte *)((int)puVar5 + iVar6) = *(byte *)((int)puVar3 + iVar6);
            if (iVar1 != 0x10) {
              iVar6 = uVar2 + 8;
              *(byte *)((int)puVar5 + iVar1) = *(byte *)((int)puVar3 + iVar1);
              if (iVar6 != 0x10) {
                iVar1 = uVar2 + 9;
                *(byte *)((int)puVar5 + iVar6) = *(byte *)((int)puVar3 + iVar6);
                if (iVar1 != 0x10) {
                  iVar6 = uVar2 + 10;
                  *(byte *)((int)puVar5 + iVar1) = *(byte *)((int)puVar3 + iVar1);
                  if (iVar6 != 0x10) {
                    iVar1 = uVar2 + 0xb;
                    *(byte *)((int)puVar5 + iVar6) = *(byte *)((int)puVar3 + iVar6);
                    if (iVar1 != 0x10) {
                      iVar6 = uVar2 + 0xc;
                      *(byte *)((int)puVar5 + iVar1) = *(byte *)((int)puVar3 + iVar1);
                      if (iVar6 != 0x10) {
                        iVar1 = uVar2 + 0xd;
                        *(byte *)((int)puVar5 + iVar6) = *(byte *)((int)puVar3 + iVar6);
                        if (iVar1 != 0x10) {
                          uVar9 = uVar2 + 0xe;
                          *(byte *)((int)puVar5 + iVar1) = *(byte *)((int)puVar3 + iVar1);
                          if (uVar9 != 0x10) {
                            *(byte *)((int)puVar5 + uVar9) = *(byte *)((int)puVar3 + uVar9);
                            if (uVar2 != 1) {
                              uVar9 = (uint)*(byte *)((int)puVar3 + 0xf);
                            }
                            if (uVar2 != 1) {
                              *(byte *)((int)puVar5 + 0xf) = (byte)uVar9;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  (*param_6)(puVar5,puVar5,param_4);
LAB_00135888:
  if (puVar5 != param_5) {
    uVar9 = puVar5[1];
    uVar2 = puVar5[2];
    uVar4 = puVar5[3];
    *param_5 = *puVar5;
    param_5[1] = uVar9;
    param_5[2] = uVar2;
    param_5[3] = uVar4;
  }
  return;
}


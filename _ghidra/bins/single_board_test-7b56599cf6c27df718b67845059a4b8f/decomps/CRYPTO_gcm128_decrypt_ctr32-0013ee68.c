
undefined4
CRYPTO_gcm128_decrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  byte *pbVar13;
  byte *pbVar14;
  bool bVar15;
  uint *local_30;
  
  uVar3 = *(uint *)(param_1 + 0x38) + param_4;
  uVar7 = *(undefined4 *)(param_1 + 0x174);
  uVar4 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar15 = uVar4 < 0x10;
  if (uVar4 == 0xf) {
    bVar15 = uVar3 < 0xffffffe1;
  }
  if (!bVar15) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar3;
  *(uint *)(param_1 + 0x3c) = uVar4;
  if (*(int *)(param_1 + 0x16c) == 0) {
    pbVar13 = *(byte **)(param_1 + 0x168);
    uVar3 = *(uint *)(param_1 + 0xc);
    uVar4 = (uint)pbVar13 & 0xf;
    uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18;
    if (uVar4 == 0) goto LAB_0013eee6;
    if (param_4 == 0) {
LAB_0013efe4:
      *(byte **)(param_1 + 0x168) = pbVar13;
      return 0;
    }
    pbVar14 = pbVar13 + param_1 + 0x177;
    iVar11 = (int)pbVar13 - (int)param_3;
    puVar5 = param_2;
    do {
      param_2 = (uint *)((int)puVar5 + 1);
      uVar2 = *puVar5;
      iVar10 = param_1 + uVar4;
      local_30 = (uint *)((int)param_3 + 1);
      uVar4 = uVar4 + 1 & 0xf;
      pbVar13 = (byte *)((int)local_30 + iVar11);
      pbVar14 = pbVar14 + 1;
      *pbVar14 = (byte)uVar2;
      uVar8 = uVar4;
      if (uVar4 != 0) {
        uVar8 = 1;
      }
      param_4 = param_4 - 1;
      uVar8 = uVar8 & 1;
      if (param_4 == 0) {
        uVar8 = 0;
      }
      *(byte *)param_3 = *(byte *)(iVar10 + 0x10) ^ (byte)uVar2;
      param_3 = local_30;
      puVar5 = param_2;
    } while (uVar8 != 0);
    if (uVar4 != 0) goto LAB_0013efe4;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178,pbVar13);
    pbVar14 = (byte *)0x0;
  }
  else {
    if (param_4 == 0) {
      gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x16c) = 0;
      return 0;
    }
    pbVar13 = (byte *)0x10;
    *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0x48);
    uVar3 = *(uint *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0x40);
    uVar3 = uVar3 << 0x18 | (uVar3 >> 8 & 0xff) << 0x10 | (uVar3 >> 0x10 & 0xff) << 8 |
            uVar3 >> 0x18;
    *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
LAB_0013eee6:
    pbVar14 = pbVar13;
    local_30 = param_3;
    if (pbVar13 != (byte *)0x0 && 0xf < param_4) {
      pbVar14 = (byte *)0x0;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178,pbVar13);
    }
  }
  if (0xbff < param_4) {
    puVar5 = local_30;
    do {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,0xc00);
      uVar3 = uVar3 + 0xc0;
      param_4 = param_4 - 0xc00;
      local_30 = puVar5 + 0x300;
      (*param_5)(param_2,puVar5,0xc0,uVar7,param_1);
      *(char *)(param_1 + 0xf) = (char)uVar3;
      *(char *)(param_1 + 0xc) = (char)(uVar3 >> 0x18);
      param_2 = param_2 + 0x300;
      *(char *)(param_1 + 0xd) = (char)(uVar3 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar3 >> 8);
      puVar5 = local_30;
    } while (0xbff < param_4);
  }
  uVar4 = param_4 & 0xfffffff0;
  if (uVar4 != 0) {
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_2,uVar4);
    uVar2 = param_4 >> 4;
    uVar3 = uVar3 + uVar2;
    param_4 = param_4 - uVar4;
    (*param_5)(param_2,local_30,uVar2,uVar7,param_1);
    *(char *)(param_1 + 0xf) = (char)uVar3;
    *(char *)(param_1 + 0xc) = (char)(uVar3 >> 0x18);
    *(char *)(param_1 + 0xd) = (char)(uVar3 >> 0x10);
    *(char *)(param_1 + 0xe) = (char)(uVar3 >> 8);
    local_30 = (uint *)((int)local_30 + uVar4);
    param_2 = (uint *)((int)param_2 + uVar4);
  }
  pbVar13 = pbVar14;
  if (param_4 == 0) goto LAB_0013ef74;
  puVar12 = (uint *)(param_1 + 0x10);
  (**(code **)(param_1 + 0x170))(param_1,puVar12,uVar7);
  puVar5 = (uint *)(pbVar14 + param_1 + 0x178);
  puVar9 = (uint *)(pbVar14 + param_1 + 0x17c);
  iVar11 = uVar3 + 1;
  *(char *)(param_1 + 0xf) = (char)iVar11;
  puVar6 = local_30 + 1;
  *(char *)(param_1 + 0xc) = (char)((uint)iVar11 >> 0x18);
  uVar3 = param_4 - 1;
  *(char *)(param_1 + 0xd) = (char)((uint)iVar11 >> 0x10);
  *(char *)(param_1 + 0xe) = (char)((uint)iVar11 >> 8);
  if ((((uint)local_30 | (uint)param_2 | (uint)puVar5) & 3) == 0 &&
      ((param_2 + 1 <= local_30 || puVar6 <= param_2) &&
      ((((6 < param_4 && (puVar9 <= puVar12 || (uint *)(param_1 + 0x14) <= puVar5)) &&
        (param_2 + 1 <= puVar5 || puVar9 <= param_2)) &&
       (puVar6 <= puVar12 || (uint *)(param_1 + 0x14) <= local_30)) &&
      (puVar6 <= puVar5 || puVar9 <= local_30)))) {
    iVar11 = (param_4 - 4 >> 2) + 1;
    uVar4 = iVar11 * 4;
    if (uVar3 < 3) {
      uVar4 = 0;
    }
    else {
      uVar2 = *param_2;
      *(uint *)(pbVar14 + param_1 + 0x178) = uVar2;
      *local_30 = uVar2 ^ *(uint *)(param_1 + 0x10);
      if (iVar11 != 1) {
        uVar2 = param_2[1];
        puVar5[1] = uVar2;
        local_30[1] = uVar2 ^ *(uint *)(param_1 + 0x14);
        if (iVar11 != 2) {
          uVar2 = param_2[2];
          puVar5[2] = uVar2;
          local_30[2] = uVar2 ^ *(uint *)(param_1 + 0x18);
          if (iVar11 != 3) {
            uVar2 = param_2[3];
            puVar5[3] = uVar2;
            local_30[3] = *(uint *)(param_1 + 0x1c) ^ uVar2;
          }
        }
      }
      uVar3 = uVar3 + iVar11 * -4;
      pbVar13 = pbVar14 + uVar4;
      if (param_4 == uVar4) goto LAB_0013f1d4;
    }
    bVar1 = *(byte *)((int)param_2 + uVar4);
    pbVar13[param_1 + 0x178] = bVar1;
    iVar11 = uVar4 + 1;
    *(byte *)((int)local_30 + uVar4) = bVar1 ^ *(byte *)(param_1 + uVar4 + 0x10);
    if (uVar3 != 0) {
      bVar1 = *(byte *)((int)param_2 + iVar11);
      iVar10 = uVar4 + 2;
      pbVar13[param_1 + 0x179] = bVar1;
      *(byte *)((int)local_30 + iVar11) = bVar1 ^ *(byte *)(param_1 + iVar11 + 0x10);
      if (uVar3 != 1) {
        bVar1 = *(byte *)((int)param_2 + iVar10);
        pbVar13[param_1 + 0x17a] = bVar1;
        *(byte *)((int)local_30 + iVar10) = *(byte *)(param_1 + iVar10 + 0x10) ^ bVar1;
      }
    }
  }
  else {
    uVar4 = *param_2;
    pbVar14[param_1 + 0x178] = (byte)uVar4;
    *(byte *)local_30 = *(byte *)(param_1 + 0x10) ^ (byte)uVar4;
    if (uVar3 != 0) {
      bVar1 = *(byte *)((int)param_2 + 1);
      pbVar14[param_1 + 0x179] = bVar1;
      *(byte *)((int)local_30 + 1) = *(byte *)(param_1 + 0x11) ^ bVar1;
      if (param_4 != 2) {
        bVar1 = *(byte *)((int)param_2 + 2);
        pbVar14[param_1 + 0x17a] = bVar1;
        *(byte *)((int)local_30 + 2) = *(byte *)(param_1 + 0x12) ^ bVar1;
        if (param_4 != 3) {
          bVar1 = *(byte *)((int)param_2 + 3);
          pbVar14[param_1 + 0x17b] = bVar1;
          *(byte *)((int)local_30 + 3) = *(byte *)(param_1 + 0x13) ^ bVar1;
          if (param_4 != 4) {
            uVar3 = param_2[1];
            pbVar14[param_1 + 0x17c] = (byte)uVar3;
            *(byte *)(local_30 + 1) = *(byte *)(param_1 + 0x14) ^ (byte)uVar3;
            if (param_4 != 5) {
              bVar1 = *(byte *)((int)param_2 + 5);
              pbVar14[param_1 + 0x17d] = bVar1;
              *(byte *)((int)local_30 + 5) = *(byte *)(param_1 + 0x15) ^ bVar1;
              if (param_4 != 6) {
                bVar1 = *(byte *)((int)param_2 + 6);
                pbVar14[param_1 + 0x17e] = bVar1;
                *(byte *)((int)local_30 + 6) = *(byte *)(param_1 + 0x16) ^ bVar1;
                if (param_4 != 7) {
                  bVar1 = *(byte *)((int)param_2 + 7);
                  pbVar14[param_1 + 0x17f] = bVar1;
                  *(byte *)((int)local_30 + 7) = *(byte *)(param_1 + 0x17) ^ bVar1;
                  if (param_4 != 8) {
                    uVar3 = param_2[2];
                    pbVar14[param_1 + 0x180] = (byte)uVar3;
                    *(byte *)(local_30 + 2) = *(byte *)(param_1 + 0x18) ^ (byte)uVar3;
                    if (param_4 != 9) {
                      bVar1 = *(byte *)((int)param_2 + 9);
                      pbVar14[param_1 + 0x181] = bVar1;
                      *(byte *)((int)local_30 + 9) = *(byte *)(param_1 + 0x19) ^ bVar1;
                      if (param_4 != 10) {
                        bVar1 = *(byte *)((int)param_2 + 10);
                        pbVar14[param_1 + 0x182] = bVar1;
                        *(byte *)((int)local_30 + 10) = *(byte *)(param_1 + 0x1a) ^ bVar1;
                        if (param_4 != 0xb) {
                          bVar1 = *(byte *)((int)param_2 + 0xb);
                          pbVar14[param_1 + 0x183] = bVar1;
                          *(byte *)((int)local_30 + 0xb) = *(byte *)(param_1 + 0x1b) ^ bVar1;
                          if (param_4 != 0xc) {
                            uVar3 = param_2[3];
                            pbVar14[param_1 + 0x184] = (byte)uVar3;
                            *(byte *)(local_30 + 3) = *(byte *)(param_1 + 0x1c) ^ (byte)uVar3;
                            if (param_4 != 0xd) {
                              bVar1 = *(byte *)((int)param_2 + 0xd);
                              pbVar14[param_1 + 0x185] = bVar1;
                              *(byte *)((int)local_30 + 0xd) = *(byte *)(param_1 + 0x1d) ^ bVar1;
                              if (param_4 != 0xe) {
                                bVar1 = *(byte *)((int)param_2 + 0xe);
                                pbVar14[param_1 + 0x186] = bVar1;
                                *(byte *)((int)local_30 + 0xe) = *(byte *)(param_1 + 0x1e) ^ bVar1;
                                if (param_4 != 0xf) {
                                  bVar1 = *(byte *)((int)param_2 + 0xf);
                                  pbVar13 = pbVar14 + param_4;
                                  pbVar14[param_1 + 0x187] = bVar1;
                                  *(byte *)((int)local_30 + 0xf) = *(byte *)(param_1 + 0x1f) ^ bVar1
                                  ;
                                  goto LAB_0013ef74;
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
    }
  }
LAB_0013f1d4:
  pbVar13 = pbVar14 + param_4;
LAB_0013ef74:
  *(byte **)(param_1 + 0x168) = pbVar13;
  return 0;
}


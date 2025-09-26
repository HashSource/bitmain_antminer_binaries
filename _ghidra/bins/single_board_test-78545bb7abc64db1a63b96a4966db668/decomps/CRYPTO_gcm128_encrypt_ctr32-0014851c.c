
undefined4
CRYPTO_gcm128_encrypt_ctr32(int param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  bool bVar14;
  uint *local_30;
  
  uVar4 = *(undefined4 *)(param_1 + 0x174);
  uVar8 = *(uint *)(param_1 + 0x38) + param_4;
  uVar9 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar14 = uVar9 < 0x10;
  if (uVar9 == 0xf) {
    bVar14 = uVar8 < 0xffffffe1;
  }
  if (!bVar14) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar8;
  *(uint *)(param_1 + 0x3c) = uVar9;
  if (*(int *)(param_1 + 0x16c) == 0) {
    uVar8 = *(uint *)(param_1 + 0x168);
    uVar9 = *(uint *)(param_1 + 0xc);
    uVar2 = uVar8 & 0xf;
    uVar9 = uVar9 << 0x18 | (uVar9 >> 8 & 0xff) << 0x10 | (uVar9 >> 0x10 & 0xff) << 8 |
            uVar9 >> 0x18;
    uVar11 = uVar8;
    if (uVar2 == 0) goto LAB_0014859c;
    if (param_4 == 0) goto LAB_00148812;
    pbVar1 = (byte *)(uVar8 + 0x177 + param_1);
    puVar7 = param_3;
    do {
      uVar11 = uVar2 + 1 & 0xf;
      local_30 = (uint *)((int)param_2 + 1);
      if (uVar11 != 0) {
        uVar11 = 1;
      }
      param_4 = param_4 - 1;
      uVar11 = uVar11 & 1;
      if (param_4 == 0) {
        uVar11 = 0;
      }
      uVar8 = uVar8 + 1;
      bVar3 = *(byte *)(param_1 + uVar2 + 0x10) ^ (byte)*param_2;
      uVar2 = uVar2 + 1 & 0xf;
      param_3 = (uint *)((int)puVar7 + 1);
      *(byte *)puVar7 = bVar3;
      pbVar1 = pbVar1 + 1;
      *pbVar1 = bVar3;
      puVar7 = param_3;
      param_2 = local_30;
    } while (uVar11 != 0);
    if (uVar2 != 0) goto LAB_00148812;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178,uVar8);
    uVar8 = 0;
  }
  else {
    if (param_4 == 0) {
      gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x16c) = 0;
      return 0;
    }
    *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0x48);
    uVar8 = *(uint *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0x40);
    uVar9 = uVar8 << 0x18 | (uVar8 >> 8 & 0xff) << 0x10 | (uVar8 >> 0x10 & 0xff) << 8 |
            uVar8 >> 0x18;
    *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
    uVar11 = 0x10;
LAB_0014859c:
    uVar8 = uVar11;
    local_30 = param_2;
    if (uVar11 != 0 && 0xf < param_4) {
      uVar8 = 0;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178,uVar11);
    }
  }
  if (0xbff < param_4) {
    puVar7 = param_3;
    do {
      uVar9 = uVar9 + 0xc0;
      (*param_5)(local_30,puVar7,0xc0,uVar4,param_1);
      *(char *)(param_1 + 0xf) = (char)uVar9;
      *(char *)(param_1 + 0xc) = (char)(uVar9 >> 0x18);
      param_4 = param_4 - 0xc00;
      *(char *)(param_1 + 0xd) = (char)(uVar9 >> 0x10);
      *(char *)(param_1 + 0xe) = (char)(uVar9 >> 8);
      local_30 = local_30 + 0x300;
      param_3 = puVar7 + 0x300;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,puVar7);
      puVar7 = param_3;
    } while (0xbff < param_4);
  }
  uVar11 = param_4 & 0xfffffff0;
  if (uVar11 != 0) {
    uVar9 = uVar9 + (param_4 >> 4);
    (*param_5)(local_30,param_3,param_4 >> 4,uVar4,param_1);
    *(char *)(param_1 + 0xf) = (char)uVar9;
    *(char *)(param_1 + 0xc) = (char)(uVar9 >> 0x18);
    local_30 = (uint *)((int)local_30 + uVar11);
    param_4 = param_4 - uVar11;
    *(char *)(param_1 + 0xd) = (char)(uVar9 >> 0x10);
    *(char *)(param_1 + 0xe) = (char)(uVar9 >> 8);
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_3,uVar11);
    param_3 = (uint *)((int)param_3 + uVar11);
  }
  if (param_4 == 0) goto LAB_00148812;
  puVar12 = (uint *)(param_1 + 0x10);
  (**(code **)(param_1 + 0x170))(param_1,puVar12,uVar4);
  puVar5 = (uint *)(uVar8 + 0x17c + param_1);
  puVar13 = (uint *)(param_1 + uVar8 + 0x178);
  iVar10 = uVar9 + 1;
  puVar7 = param_3 + 1;
  *(char *)(param_1 + 0xf) = (char)iVar10;
  *(char *)(param_1 + 0xc) = (char)((uint)iVar10 >> 0x18);
  uVar9 = param_4 - 1;
  *(char *)(param_1 + 0xd) = (char)((uint)iVar10 >> 0x10);
  *(char *)(param_1 + 0xe) = (char)((uint)iVar10 >> 8);
  if ((((uint)puVar13 | (uint)param_3 | (uint)local_30) & 3) == 0 &&
      ((local_30 + 1 <= param_3 || puVar7 <= local_30) &&
      ((((6 < param_4 && ((uint *)(param_1 + 0x14) <= puVar13 || puVar5 <= puVar12)) &&
        (local_30 + 1 <= puVar13 || puVar5 <= local_30)) &&
       (puVar7 <= puVar12 || (uint *)(param_1 + 0x14) <= param_3)) &&
      (puVar7 <= puVar13 || puVar5 <= param_3)))) {
    iVar10 = (param_4 - 4 >> 2) + 1;
    uVar11 = iVar10 * 4;
    if (uVar9 < 3) {
      uVar11 = 0;
      uVar2 = uVar8;
    }
    else {
      uVar2 = *local_30 ^ *(uint *)(param_1 + 0x10);
      *param_3 = uVar2;
      *(uint *)(param_1 + uVar8 + 0x178) = uVar2;
      if (iVar10 != 1) {
        uVar2 = *(uint *)(param_1 + 0x14) ^ local_30[1];
        param_3[1] = uVar2;
        puVar13[1] = uVar2;
        if (iVar10 != 2) {
          uVar2 = *(uint *)(param_1 + 0x18) ^ local_30[2];
          param_3[2] = uVar2;
          puVar13[2] = uVar2;
          if (iVar10 != 3) {
            uVar2 = *(uint *)(param_1 + 0x1c) ^ local_30[3];
            param_3[3] = uVar2;
            puVar13[3] = uVar2;
          }
        }
      }
      uVar9 = uVar9 + iVar10 * -4;
      uVar2 = uVar8 + uVar11;
      if (param_4 == uVar11) goto LAB_001487b4;
    }
    bVar3 = *(byte *)((int)local_30 + uVar11) ^ *(byte *)(param_1 + uVar11 + 0x10);
    *(byte *)((int)param_3 + uVar11) = bVar3;
    *(byte *)(param_1 + uVar2 + 0x178) = bVar3;
    iVar10 = uVar11 + 1;
    if (uVar9 != 0) {
      iVar6 = uVar11 + 2;
      bVar3 = *(byte *)((int)local_30 + iVar10) ^ *(byte *)(param_1 + iVar10 + 0x10);
      *(byte *)((int)param_3 + iVar10) = bVar3;
      *(byte *)(uVar2 + param_1 + 0x179) = bVar3;
      if (uVar9 != 1) {
        bVar3 = *(byte *)(param_1 + iVar6 + 0x10) ^ *(byte *)((int)local_30 + iVar6);
        *(byte *)((int)param_3 + iVar6) = bVar3;
        *(byte *)(uVar2 + param_1 + 0x17a) = bVar3;
      }
    }
  }
  else {
    bVar3 = *(byte *)(param_1 + 0x10) ^ (byte)*local_30;
    *(byte *)param_3 = bVar3;
    *(byte *)(param_1 + uVar8 + 0x178) = bVar3;
    if (uVar9 != 0) {
      bVar3 = *(byte *)(param_1 + 0x11) ^ *(byte *)((int)local_30 + 1);
      *(byte *)((int)param_3 + 1) = bVar3;
      *(byte *)(uVar8 + param_1 + 0x179) = bVar3;
      if (param_4 != 2) {
        bVar3 = *(byte *)(param_1 + 0x12) ^ *(byte *)((int)local_30 + 2);
        *(byte *)((int)param_3 + 2) = bVar3;
        *(byte *)(uVar8 + param_1 + 0x17a) = bVar3;
        if (param_4 != 3) {
          bVar3 = *(byte *)(param_1 + 0x13) ^ *(byte *)((int)local_30 + 3);
          *(byte *)((int)param_3 + 3) = bVar3;
          *(byte *)(uVar8 + param_1 + 0x17b) = bVar3;
          if (param_4 != 4) {
            bVar3 = *(byte *)(param_1 + 0x14) ^ (byte)local_30[1];
            *(byte *)(param_3 + 1) = bVar3;
            *(byte *)(uVar8 + param_1 + 0x17c) = bVar3;
            if (param_4 != 5) {
              bVar3 = *(byte *)(param_1 + 0x15) ^ *(byte *)((int)local_30 + 5);
              *(byte *)((int)param_3 + 5) = bVar3;
              *(byte *)(uVar8 + param_1 + 0x17d) = bVar3;
              if (param_4 != 6) {
                bVar3 = *(byte *)(param_1 + 0x16) ^ *(byte *)((int)local_30 + 6);
                *(byte *)((int)param_3 + 6) = bVar3;
                *(byte *)(uVar8 + param_1 + 0x17e) = bVar3;
                if (param_4 != 7) {
                  bVar3 = *(byte *)(param_1 + 0x17) ^ *(byte *)((int)local_30 + 7);
                  *(byte *)((int)param_3 + 7) = bVar3;
                  *(byte *)(uVar8 + param_1 + 0x17f) = bVar3;
                  if (param_4 != 8) {
                    bVar3 = *(byte *)(param_1 + 0x18) ^ (byte)local_30[2];
                    *(byte *)(param_3 + 2) = bVar3;
                    *(byte *)(uVar8 + param_1 + 0x180) = bVar3;
                    if (param_4 != 9) {
                      bVar3 = *(byte *)(param_1 + 0x19) ^ *(byte *)((int)local_30 + 9);
                      *(byte *)((int)param_3 + 9) = bVar3;
                      *(byte *)(uVar8 + param_1 + 0x181) = bVar3;
                      if (param_4 != 10) {
                        bVar3 = *(byte *)(param_1 + 0x1a) ^ *(byte *)((int)local_30 + 10);
                        *(byte *)((int)param_3 + 10) = bVar3;
                        *(byte *)(uVar8 + param_1 + 0x182) = bVar3;
                        if (param_4 != 0xb) {
                          bVar3 = *(byte *)(param_1 + 0x1b) ^ *(byte *)((int)local_30 + 0xb);
                          *(byte *)((int)param_3 + 0xb) = bVar3;
                          *(byte *)(uVar8 + param_1 + 0x183) = bVar3;
                          if (param_4 != 0xc) {
                            bVar3 = *(byte *)(param_1 + 0x1c) ^ (byte)local_30[3];
                            *(byte *)(param_3 + 3) = bVar3;
                            *(byte *)(uVar8 + param_1 + 0x184) = bVar3;
                            if (param_4 != 0xd) {
                              bVar3 = *(byte *)(param_1 + 0x1d) ^ *(byte *)((int)local_30 + 0xd);
                              *(byte *)((int)param_3 + 0xd) = bVar3;
                              *(byte *)(uVar8 + param_1 + 0x185) = bVar3;
                              if (param_4 != 0xe) {
                                bVar3 = *(byte *)(param_1 + 0x1e) ^ *(byte *)((int)local_30 + 0xe);
                                *(byte *)((int)param_3 + 0xe) = bVar3;
                                *(byte *)(uVar8 + param_1 + 0x186) = bVar3;
                                if (param_4 != 0xf) {
                                  iVar10 = uVar8 + param_1;
                                  uVar8 = uVar8 + param_4;
                                  bVar3 = *(byte *)(param_1 + 0x1f) ^ *(byte *)((int)local_30 + 0xf)
                                  ;
                                  *(byte *)((int)param_3 + 0xf) = bVar3;
                                  *(byte *)(iVar10 + 0x187) = bVar3;
                                  goto LAB_00148812;
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
LAB_001487b4:
  uVar8 = uVar8 + param_4;
LAB_00148812:
  *(uint *)(param_1 + 0x168) = uVar8;
  return 0;
}


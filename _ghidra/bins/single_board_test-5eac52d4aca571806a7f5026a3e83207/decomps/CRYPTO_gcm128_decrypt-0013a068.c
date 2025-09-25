
undefined4 CRYPTO_gcm128_decrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint *puVar10;
  undefined4 uVar11;
  code *pcVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  bool bVar16;
  uint local_44;
  uint *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  
  uVar14 = *(uint *)(param_1 + 0x38) + param_4;
  uVar15 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar16 = uVar15 < 0x10;
  pcVar12 = *(code **)(param_1 + 0x170);
  if (uVar15 == 0xf) {
    bVar16 = uVar14 < 0xffffffe1;
  }
  uVar13 = *(undefined4 *)(param_1 + 0x174);
  if (!bVar16) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar14;
  *(uint *)(param_1 + 0x3c) = uVar15;
  if (*(int *)(param_1 + 0x16c) == 0) {
    uVar14 = *(uint *)(param_1 + 0xc);
    local_38 = *(uint *)(param_1 + 0x168);
    local_34 = uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
               uVar14 >> 0x18;
    uVar14 = local_38 & 0xf;
    if (uVar14 == 0) goto LAB_0013a16a;
    if (param_4 == 0) {
      *(uint *)(param_1 + 0x168) = local_38;
      return 0;
    }
    pbVar2 = (byte *)(local_38 + 0x177 + param_1);
    puVar5 = param_3;
    do {
      local_3c = (uint *)((int)param_2 + 1);
      uVar15 = *param_2;
      iVar4 = param_1 + uVar14;
      local_40 = (uint *)((int)puVar5 + 1);
      uVar14 = uVar14 + 1 & 0xf;
      pbVar2 = pbVar2 + 1;
      *pbVar2 = (byte)uVar15;
      uVar7 = uVar14;
      if (uVar14 != 0) {
        uVar7 = 1;
      }
      param_4 = param_4 - 1;
      uVar7 = uVar7 & 1;
      if (param_4 == 0) {
        uVar7 = 0;
      }
      *(byte *)puVar5 = (byte)uVar15 ^ *(byte *)(iVar4 + 0x10);
      puVar5 = local_40;
      param_2 = local_3c;
    } while (uVar7 != 0);
    if (uVar14 != 0) {
      *(byte **)(param_1 + 0x168) = (byte *)((int)local_40 + (local_38 - (int)param_3));
      return 0;
    }
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178);
    local_38 = 0;
    local_44 = param_4;
    if ((((uint)local_3c | (uint)local_40) & 3) != 0) goto LAB_0013a254;
LAB_0013a2f4:
    local_38 = 0;
  }
  else {
    if (param_4 == 0) {
      gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x16c) = 0;
      return 0;
    }
    uVar11 = *(undefined4 *)(param_1 + 0x40);
    uVar3 = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0x44);
    local_38 = 0x10;
    *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    uVar14 = *(uint *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x178) = uVar11;
    local_34 = uVar14 << 0x18 | (uVar14 >> 8 & 0xff) << 0x10 | (uVar14 >> 0x10 & 0xff) << 8 |
               uVar14 >> 0x18;
    *(undefined4 *)(param_1 + 0x180) = uVar3;
    *(undefined4 *)(param_1 + 0x16c) = 0;
LAB_0013a16a:
    local_44 = param_4;
    local_40 = param_3;
    local_3c = param_2;
    if ((((uint)param_3 | (uint)param_2) & 3) != 0) {
LAB_0013a254:
      if (local_44 != 0) {
        uVar14 = 0;
        pbVar2 = (byte *)((int)local_40 + -1);
        puVar5 = local_3c;
        do {
          if (uVar14 == 0) {
            local_34 = local_34 + 1;
            (*pcVar12)(param_1,param_1 + 0x10,uVar13);
            *(char *)(param_1 + 0xf) = (char)local_34;
            *(char *)(param_1 + 0xc) = (char)(local_34 >> 0x18);
            *(char *)(param_1 + 0xd) = (char)(local_34 >> 0x10);
            *(char *)(param_1 + 0xe) = (char)(local_34 >> 8);
          }
          puVar6 = (uint *)((int)puVar5 + 1);
          uVar15 = *puVar5;
          iVar8 = param_1 + local_38;
          iVar4 = param_1 + uVar14;
          local_38 = local_38 + 1;
          *(byte *)(iVar8 + 0x178) = (byte)uVar15;
          uVar14 = uVar14 + 1 & 0xf;
          pbVar2 = pbVar2 + 1;
          *pbVar2 = *(byte *)(iVar4 + 0x10) ^ (byte)uVar15;
          if (local_38 == 0x30) {
            gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178);
            local_38 = 0;
          }
          puVar5 = puVar6;
        } while (puVar6 != (uint *)(local_44 + (int)local_3c));
      }
      *(uint *)(param_1 + 0x168) = local_38;
      return 0;
    }
    if ((local_38 == 0 || 0xe < param_4) && (local_38 != 0 && param_4 != 0xf)) {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178,local_38);
      goto LAB_0013a2f4;
    }
  }
  if (0xbff < local_44) {
    do {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,local_3c,0xc00);
      puVar5 = local_40 + 4;
      uVar14 = local_34;
      puVar6 = local_3c;
      do {
        uVar14 = uVar14 + 1;
        (*pcVar12)(param_1,param_1 + 0x10,uVar13);
        *(char *)(param_1 + 0xf) = (char)uVar14;
        *(char *)(param_1 + 0xe) = (char)(uVar14 >> 8);
        puVar9 = puVar5 + 4;
        *(char *)(param_1 + 0xc) = (char)(uVar14 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(uVar14 >> 0x10);
        puVar5[-4] = *(uint *)(param_1 + 0x10) ^ *puVar6;
        puVar5[-3] = *(uint *)(param_1 + 0x14) ^ puVar6[1];
        puVar5[-2] = *(uint *)(param_1 + 0x18) ^ puVar6[2];
        puVar5[-1] = *(uint *)(param_1 + 0x1c) ^ puVar6[3];
        puVar5 = puVar9;
        puVar6 = puVar6 + 4;
      } while (puVar9 != local_40 + 0x304);
      local_34 = local_34 + 0xc0;
      local_44 = local_44 - 0xc00;
      local_40 = local_40 + 0x300;
      local_3c = local_3c + 0x300;
    } while (0xbff < local_44);
  }
  if ((local_44 & 0xfffffff0) != 0) {
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,local_3c);
    uVar15 = local_44 - 0x10 >> 4;
    local_34 = local_34 + 1;
    uVar14 = local_34 + uVar15;
    puVar6 = local_3c;
    puVar5 = local_40;
    while( true ) {
      (*pcVar12)(param_1,param_1 + 0x10,uVar13);
      *(char *)(param_1 + 0xf) = (char)local_34;
      *(char *)(param_1 + 0xd) = (char)(local_34 >> 0x10);
      *(char *)(param_1 + 0xc) = (char)(local_34 >> 0x18);
      *(char *)(param_1 + 0xe) = (char)(local_34 >> 8);
      *puVar5 = *puVar6 ^ *(uint *)(param_1 + 0x10);
      puVar5[1] = *(uint *)(param_1 + 0x14) ^ puVar6[1];
      puVar5[2] = *(uint *)(param_1 + 0x18) ^ puVar6[2];
      puVar5[3] = *(uint *)(param_1 + 0x1c) ^ puVar6[3];
      if (local_34 == uVar14) break;
      local_34 = local_34 + 1;
      puVar6 = puVar6 + 4;
      puVar5 = puVar5 + 4;
    }
    iVar4 = uVar15 + 1;
    local_44 = local_44 & 0xf;
    local_40 = local_40 + iVar4 * 4;
    local_3c = local_3c + iVar4 * 4;
  }
  if (local_44 == 0) goto LAB_0013a246;
  puVar10 = (uint *)(param_1 + 0x10);
  (*pcVar12)(param_1,puVar10,uVar13);
  puVar6 = (uint *)(local_38 + 0x17c + param_1);
  puVar5 = (uint *)(param_1 + local_38 + 0x178);
  puVar9 = local_40 + 1;
  iVar4 = local_34 + 1;
  *(char *)(param_1 + 0xc) = (char)((uint)iVar4 >> 0x18);
  *(char *)(param_1 + 0xf) = (char)iVar4;
  *(char *)(param_1 + 0xd) = (char)((uint)iVar4 >> 0x10);
  uVar14 = local_44 - 1;
  *(char *)(param_1 + 0xe) = (char)((uint)iVar4 >> 8);
  if ((((uint)local_40 | (uint)local_3c | (uint)puVar5) & 3) == 0 &&
      ((local_3c + 1 <= local_40 || puVar9 <= local_3c) &&
      ((((6 < local_44 && (puVar6 <= puVar10 || (uint *)(param_1 + 0x14) <= puVar5)) &&
        (puVar6 <= local_3c || local_3c + 1 <= puVar5)) &&
       ((uint *)(param_1 + 0x14) <= local_40 || puVar9 <= puVar10)) &&
      (puVar9 <= puVar5 || puVar6 <= local_40)))) {
    iVar4 = (local_44 - 4 >> 2) + 1;
    uVar15 = iVar4 * 4;
    if (uVar14 < 3) {
      uVar15 = 0;
      uVar7 = local_38;
    }
    else {
      uVar7 = *local_3c;
      *(uint *)(param_1 + local_38 + 0x178) = uVar7;
      *local_40 = *(uint *)(param_1 + 0x10) ^ uVar7;
      if (iVar4 != 1) {
        uVar7 = local_3c[1];
        puVar5[1] = uVar7;
        local_40[1] = *(uint *)(param_1 + 0x14) ^ uVar7;
        if (iVar4 == 3) {
          uVar7 = local_3c[2];
          puVar5[2] = uVar7;
          local_40[2] = *(uint *)(param_1 + 0x18) ^ uVar7;
        }
      }
      uVar14 = uVar14 + iVar4 * -4;
      uVar7 = local_38 + uVar15;
      if (local_44 == uVar15) goto LAB_0013a56c;
    }
    bVar1 = *(byte *)((int)local_3c + uVar15);
    *(byte *)(param_1 + uVar7 + 0x178) = bVar1;
    iVar4 = uVar15 + 1;
    *(byte *)((int)local_40 + uVar15) = *(byte *)(param_1 + uVar15 + 0x10) ^ bVar1;
    if (uVar14 != 0) {
      iVar8 = uVar15 + 2;
      bVar1 = *(byte *)((int)local_3c + iVar4);
      *(byte *)(uVar7 + param_1 + 0x179) = bVar1;
      *(byte *)((int)local_40 + iVar4) = *(byte *)(param_1 + iVar4 + 0x10) ^ bVar1;
      if (uVar14 != 1) {
        bVar1 = *(byte *)((int)local_3c + iVar8);
        *(byte *)(uVar7 + param_1 + 0x17a) = bVar1;
        *(byte *)((int)local_40 + iVar8) = *(byte *)(param_1 + iVar8 + 0x10) ^ bVar1;
      }
    }
  }
  else {
    uVar15 = *local_3c;
    *(byte *)(param_1 + local_38 + 0x178) = (byte)uVar15;
    *(byte *)local_40 = *(byte *)(param_1 + 0x10) ^ (byte)uVar15;
    if (uVar14 != 0) {
      bVar1 = *(byte *)((int)local_3c + 1);
      *(byte *)(local_38 + param_1 + 0x179) = bVar1;
      *(byte *)((int)local_40 + 1) = *(byte *)(param_1 + 0x11) ^ bVar1;
      if (local_44 != 2) {
        bVar1 = *(byte *)((int)local_3c + 2);
        *(byte *)(local_38 + param_1 + 0x17a) = bVar1;
        *(byte *)((int)local_40 + 2) = *(byte *)(param_1 + 0x12) ^ bVar1;
        if (local_44 != 3) {
          bVar1 = *(byte *)((int)local_3c + 3);
          *(byte *)(local_38 + param_1 + 0x17b) = bVar1;
          *(byte *)((int)local_40 + 3) = *(byte *)(param_1 + 0x13) ^ bVar1;
          if (local_44 != 4) {
            uVar14 = local_3c[1];
            *(byte *)(local_38 + param_1 + 0x17c) = (byte)uVar14;
            *(byte *)(local_40 + 1) = *(byte *)(param_1 + 0x14) ^ (byte)uVar14;
            if (local_44 != 5) {
              bVar1 = *(byte *)((int)local_3c + 5);
              *(byte *)(local_38 + param_1 + 0x17d) = bVar1;
              *(byte *)((int)local_40 + 5) = *(byte *)(param_1 + 0x15) ^ bVar1;
              if (local_44 != 6) {
                bVar1 = *(byte *)((int)local_3c + 6);
                *(byte *)(local_38 + param_1 + 0x17e) = bVar1;
                *(byte *)((int)local_40 + 6) = *(byte *)(param_1 + 0x16) ^ bVar1;
                if (local_44 != 7) {
                  bVar1 = *(byte *)((int)local_3c + 7);
                  *(byte *)(local_38 + param_1 + 0x17f) = bVar1;
                  *(byte *)((int)local_40 + 7) = *(byte *)(param_1 + 0x17) ^ bVar1;
                  if (local_44 != 8) {
                    uVar14 = local_3c[2];
                    *(byte *)(local_38 + param_1 + 0x180) = (byte)uVar14;
                    *(byte *)(local_40 + 2) = *(byte *)(param_1 + 0x18) ^ (byte)uVar14;
                    if (local_44 != 9) {
                      bVar1 = *(byte *)((int)local_3c + 9);
                      *(byte *)(local_38 + param_1 + 0x181) = bVar1;
                      *(byte *)((int)local_40 + 9) = *(byte *)(param_1 + 0x19) ^ bVar1;
                      if (local_44 != 10) {
                        bVar1 = *(byte *)((int)local_3c + 10);
                        *(byte *)(local_38 + param_1 + 0x182) = bVar1;
                        *(byte *)((int)local_40 + 10) = *(byte *)(param_1 + 0x1a) ^ bVar1;
                        if (local_44 != 0xb) {
                          bVar1 = *(byte *)((int)local_3c + 0xb);
                          *(byte *)(local_38 + param_1 + 0x183) = bVar1;
                          *(byte *)((int)local_40 + 0xb) = *(byte *)(param_1 + 0x1b) ^ bVar1;
                          if (local_44 != 0xc) {
                            uVar14 = local_3c[3];
                            *(byte *)(local_38 + param_1 + 0x184) = (byte)uVar14;
                            *(byte *)(local_40 + 3) = *(byte *)(param_1 + 0x1c) ^ (byte)uVar14;
                            if (local_44 != 0xd) {
                              bVar1 = *(byte *)((int)local_3c + 0xd);
                              *(byte *)(local_38 + param_1 + 0x185) = bVar1;
                              *(byte *)((int)local_40 + 0xd) = *(byte *)(param_1 + 0x1d) ^ bVar1;
                              if (local_44 != 0xe) {
                                bVar1 = *(byte *)((int)local_3c + 0xe);
                                *(byte *)(local_38 + param_1 + 0x186) = bVar1;
                                *(byte *)((int)local_40 + 0xe) = *(byte *)(param_1 + 0x1e) ^ bVar1;
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
LAB_0013a56c:
  local_38 = local_38 + local_44;
LAB_0013a246:
  *(uint *)(param_1 + 0x168) = local_38;
  return 0;
}


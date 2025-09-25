
undefined4 CRYPTO_gcm128_encrypt(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte *pbVar1;
  byte bVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  code *pcVar9;
  uint *puVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  uint local_44;
  uint *local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  
  uVar12 = *(uint *)(param_1 + 0x38) + param_4;
  uVar13 = *(int *)(param_1 + 0x3c) + (uint)CARRY4(*(uint *)(param_1 + 0x38),param_4);
  bVar15 = uVar13 < 0x10;
  pcVar9 = *(code **)(param_1 + 0x170);
  if (uVar13 == 0xf) {
    bVar15 = uVar12 < 0xffffffe1;
  }
  uVar11 = *(undefined4 *)(param_1 + 0x174);
  if (!bVar15) {
    return 0xffffffff;
  }
  *(uint *)(param_1 + 0x38) = uVar12;
  *(uint *)(param_1 + 0x3c) = uVar13;
  if (*(int *)(param_1 + 0x16c) == 0) {
    local_38 = *(uint *)(param_1 + 0x168);
    uVar12 = *(uint *)(param_1 + 0xc);
    uVar13 = local_38 & 0xf;
    local_34 = uVar12 << 0x18 | (uVar12 >> 8 & 0xff) << 0x10 | (uVar12 >> 0x10 & 0xff) << 8 |
               uVar12 >> 0x18;
    if (uVar13 == 0) goto LAB_00139ac8;
    if (param_4 == 0) goto LAB_00139a78;
    pbVar1 = (byte *)(local_38 + 0x177 + param_1);
    do {
      uVar12 = uVar13 + 1 & 0xf;
      local_3c = (uint *)((int)param_2 + 1);
      if (uVar12 != 0) {
        uVar12 = 1;
      }
      param_4 = param_4 - 1;
      uVar12 = uVar12 & 1;
      if (param_4 == 0) {
        uVar12 = 0;
      }
      local_38 = local_38 + 1;
      bVar2 = (byte)*param_2 ^ *(byte *)(param_1 + uVar13 + 0x10);
      uVar13 = uVar13 + 1 & 0xf;
      local_40 = (uint *)((int)param_3 + 1);
      *(byte *)param_3 = bVar2;
      pbVar1 = pbVar1 + 1;
      *pbVar1 = bVar2;
      param_3 = local_40;
      param_2 = local_3c;
    } while (uVar12 != 0);
    if (uVar13 != 0) goto LAB_00139a78;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178,local_38);
    local_38 = 0;
    local_44 = param_4;
    if ((((uint)local_40 | (uint)local_3c) & 3) != 0) goto LAB_00139d82;
LAB_00139e22:
    local_38 = 0;
  }
  else {
    if (param_4 == 0) {
      gcm_gmult_4bit(param_1 + 0x40,param_1 + 0x60);
      *(undefined4 *)(param_1 + 0x16c) = 0;
      return 0;
    }
    uVar7 = *(undefined4 *)(param_1 + 0x40);
    *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 *)(param_1 + 0x184) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    uVar12 = *(uint *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x178) = uVar7;
    local_34 = uVar12 << 0x18 | (uVar12 >> 8 & 0xff) << 0x10 | (uVar12 >> 0x10 & 0xff) << 8 |
               uVar12 >> 0x18;
    local_38 = 0x10;
    *(undefined4 *)(param_1 + 0x16c) = 0;
LAB_00139ac8:
    local_44 = param_4;
    local_40 = param_3;
    local_3c = param_2;
    if ((((uint)param_3 | (uint)param_2) & 3) != 0) {
LAB_00139d82:
      if (local_44 != 0) {
        uVar13 = 0;
        pbVar1 = (byte *)((int)local_40 + -1);
        uVar12 = local_38;
        puVar3 = local_3c;
        do {
          if (uVar13 == 0) {
            local_34 = local_34 + 1;
            (*pcVar9)(param_1,param_1 + 0x10,uVar11);
            *(char *)(param_1 + 0xf) = (char)local_34;
            *(char *)(param_1 + 0xc) = (char)(local_34 >> 0x18);
            *(char *)(param_1 + 0xd) = (char)(local_34 >> 0x10);
            *(char *)(param_1 + 0xe) = (char)(local_34 >> 8);
          }
          puVar4 = (uint *)((int)puVar3 + 1);
          local_38 = uVar12 + 1;
          bVar2 = (byte)*puVar3 ^ *(byte *)(param_1 + uVar13 + 0x10);
          uVar13 = uVar13 + 1 & 0xf;
          pbVar1 = pbVar1 + 1;
          *pbVar1 = bVar2;
          *(byte *)(param_1 + uVar12 + 0x178) = bVar2;
          if (local_38 == 0x30) {
            gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178);
            local_38 = 0;
          }
          uVar12 = local_38;
          puVar3 = puVar4;
        } while (puVar4 != (uint *)(local_44 + (int)local_3c));
      }
      *(uint *)(param_1 + 0x168) = local_38;
      return 0;
    }
    if ((local_38 == 0 || 0xe < param_4) && (local_38 != 0 && param_4 != 0xf)) {
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,param_1 + 0x178,local_38);
      goto LAB_00139e22;
    }
  }
  if (0xbff < local_44) {
    do {
      puVar4 = local_40 + 4;
      uVar12 = local_34;
      puVar3 = local_3c;
      do {
        uVar12 = uVar12 + 1;
        (*pcVar9)(param_1,param_1 + 0x10,uVar11);
        *(char *)(param_1 + 0xf) = (char)uVar12;
        *(char *)(param_1 + 0xe) = (char)(uVar12 >> 8);
        puVar6 = puVar4 + 4;
        *(char *)(param_1 + 0xc) = (char)(uVar12 >> 0x18);
        *(char *)(param_1 + 0xd) = (char)(uVar12 >> 0x10);
        puVar4[-4] = *(uint *)(param_1 + 0x10) ^ *puVar3;
        puVar4[-3] = *(uint *)(param_1 + 0x14) ^ puVar3[1];
        puVar4[-2] = *(uint *)(param_1 + 0x18) ^ puVar3[2];
        puVar4[-1] = *(uint *)(param_1 + 0x1c) ^ puVar3[3];
        puVar4 = puVar6;
        puVar3 = puVar3 + 4;
      } while (local_40 + 0x304 != puVar6);
      local_34 = local_34 + 0xc0;
      puVar3 = local_40 + 0x300;
      local_44 = local_44 - 0xc00;
      local_3c = local_3c + 0x300;
      gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,local_40);
      local_40 = puVar3;
    } while (0xbff < local_44);
  }
  uVar12 = local_44 & 0xfffffff0;
  if (uVar12 != 0) {
    uVar14 = local_44 - 0x10 >> 4;
    local_34 = local_34 + 1;
    uVar13 = local_34 + uVar14;
    puVar3 = local_3c;
    puVar4 = local_40;
    while( true ) {
      (*pcVar9)(param_1,param_1 + 0x10,uVar11);
      *(char *)(param_1 + 0xf) = (char)local_34;
      *(char *)(param_1 + 0xe) = (char)(local_34 >> 8);
      *(char *)(param_1 + 0xc) = (char)(local_34 >> 0x18);
      *(char *)(param_1 + 0xd) = (char)(local_34 >> 0x10);
      *puVar4 = *(uint *)(param_1 + 0x10) ^ *puVar3;
      puVar4[1] = *(uint *)(param_1 + 0x14) ^ puVar3[1];
      puVar4[2] = *(uint *)(param_1 + 0x18) ^ puVar3[2];
      puVar4[3] = *(uint *)(param_1 + 0x1c) ^ puVar3[3];
      if (local_34 == uVar13) break;
      local_34 = local_34 + 1;
      puVar3 = puVar3 + 4;
      puVar4 = puVar4 + 4;
    }
    local_44 = local_44 & 0xf;
    iVar8 = uVar14 + 1;
    local_3c = local_3c + iVar8 * 4;
    local_40 = local_40 + iVar8 * 4;
    gcm_ghash_4bit(param_1 + 0x40,param_1 + 0x60,(int)local_40 - uVar12);
  }
  if (local_44 == 0) goto LAB_00139a78;
  puVar6 = (uint *)(param_1 + 0x10);
  (*pcVar9)(param_1,puVar6,uVar11);
  puVar4 = (uint *)(local_38 + 0x17c + param_1);
  puVar3 = (uint *)(param_1 + local_38 + 0x178);
  puVar10 = local_40 + 1;
  iVar8 = local_34 + 1;
  *(char *)(param_1 + 0xf) = (char)iVar8;
  *(char *)(param_1 + 0xc) = (char)((uint)iVar8 >> 0x18);
  uVar12 = local_44 - 1;
  *(char *)(param_1 + 0xd) = (char)((uint)iVar8 >> 0x10);
  *(char *)(param_1 + 0xe) = (char)((uint)iVar8 >> 8);
  if ((((uint)local_40 | (uint)local_3c | (uint)puVar3) & 3) == 0 &&
      ((puVar10 <= local_3c || local_3c + 1 <= local_40) &&
      ((((6 < local_44 && ((uint *)(param_1 + 0x14) <= puVar3 || puVar4 <= puVar6)) &&
        (local_3c + 1 <= puVar3 || puVar4 <= local_3c)) &&
       (puVar10 <= puVar6 || (uint *)(param_1 + 0x14) <= local_40)) &&
      (puVar10 <= puVar3 || puVar4 <= local_40)))) {
    iVar8 = (local_44 - 4 >> 2) + 1;
    uVar13 = iVar8 * 4;
    if (uVar12 < 3) {
      uVar13 = 0;
      uVar14 = local_38;
    }
    else {
      uVar14 = *(uint *)(param_1 + 0x10) ^ *local_3c;
      *local_40 = uVar14;
      *(uint *)(param_1 + local_38 + 0x178) = uVar14;
      if (iVar8 != 1) {
        uVar14 = *(uint *)(param_1 + 0x14) ^ local_3c[1];
        local_40[1] = uVar14;
        puVar3[1] = uVar14;
        if (iVar8 == 3) {
          uVar14 = *(uint *)(param_1 + 0x18) ^ local_3c[2];
          local_40[2] = uVar14;
          puVar3[2] = uVar14;
        }
      }
      uVar12 = uVar12 + iVar8 * -4;
      uVar14 = local_38 + uVar13;
      if (local_44 == uVar13) goto LAB_00139ed0;
    }
    bVar2 = *(byte *)(param_1 + uVar13 + 0x10) ^ *(byte *)((int)local_3c + uVar13);
    *(byte *)((int)local_40 + uVar13) = bVar2;
    *(byte *)(param_1 + uVar14 + 0x178) = bVar2;
    iVar8 = uVar13 + 1;
    if (uVar12 != 0) {
      iVar5 = uVar13 + 2;
      bVar2 = *(byte *)(param_1 + iVar8 + 0x10) ^ *(byte *)((int)local_3c + iVar8);
      *(byte *)((int)local_40 + iVar8) = bVar2;
      *(byte *)(uVar14 + param_1 + 0x179) = bVar2;
      if (uVar12 != 1) {
        bVar2 = *(byte *)(param_1 + iVar5 + 0x10) ^ *(byte *)((int)local_3c + iVar5);
        *(byte *)((int)local_40 + iVar5) = bVar2;
        *(byte *)(uVar14 + param_1 + 0x17a) = bVar2;
      }
    }
  }
  else {
    bVar2 = (byte)*local_3c ^ *(byte *)(param_1 + 0x10);
    *(byte *)local_40 = bVar2;
    *(byte *)(param_1 + local_38 + 0x178) = bVar2;
    if (uVar12 != 0) {
      bVar2 = *(byte *)(param_1 + 0x11) ^ *(byte *)((int)local_3c + 1);
      *(byte *)((int)local_40 + 1) = bVar2;
      *(byte *)(local_38 + param_1 + 0x179) = bVar2;
      if (local_44 != 2) {
        bVar2 = *(byte *)(param_1 + 0x12) ^ *(byte *)((int)local_3c + 2);
        *(byte *)((int)local_40 + 2) = bVar2;
        *(byte *)(local_38 + param_1 + 0x17a) = bVar2;
        if (local_44 != 3) {
          bVar2 = *(byte *)(param_1 + 0x13) ^ *(byte *)((int)local_3c + 3);
          *(byte *)((int)local_40 + 3) = bVar2;
          *(byte *)(local_38 + param_1 + 0x17b) = bVar2;
          if (local_44 != 4) {
            bVar2 = *(byte *)(param_1 + 0x14) ^ (byte)local_3c[1];
            *(byte *)(local_40 + 1) = bVar2;
            *(byte *)(local_38 + param_1 + 0x17c) = bVar2;
            if (local_44 != 5) {
              bVar2 = *(byte *)(param_1 + 0x15) ^ *(byte *)((int)local_3c + 5);
              *(byte *)((int)local_40 + 5) = bVar2;
              *(byte *)(local_38 + param_1 + 0x17d) = bVar2;
              if (local_44 != 6) {
                bVar2 = *(byte *)(param_1 + 0x16) ^ *(byte *)((int)local_3c + 6);
                *(byte *)((int)local_40 + 6) = bVar2;
                *(byte *)(local_38 + param_1 + 0x17e) = bVar2;
                if (local_44 != 7) {
                  bVar2 = *(byte *)(param_1 + 0x17) ^ *(byte *)((int)local_3c + 7);
                  *(byte *)((int)local_40 + 7) = bVar2;
                  *(byte *)(local_38 + param_1 + 0x17f) = bVar2;
                  if (local_44 != 8) {
                    bVar2 = *(byte *)(param_1 + 0x18) ^ (byte)local_3c[2];
                    *(byte *)(local_40 + 2) = bVar2;
                    *(byte *)(local_38 + param_1 + 0x180) = bVar2;
                    if (local_44 != 9) {
                      bVar2 = *(byte *)(param_1 + 0x19) ^ *(byte *)((int)local_3c + 9);
                      *(byte *)((int)local_40 + 9) = bVar2;
                      *(byte *)(local_38 + param_1 + 0x181) = bVar2;
                      if (local_44 != 10) {
                        bVar2 = *(byte *)(param_1 + 0x1a) ^ *(byte *)((int)local_3c + 10);
                        *(byte *)((int)local_40 + 10) = bVar2;
                        *(byte *)(local_38 + param_1 + 0x182) = bVar2;
                        if (local_44 != 0xb) {
                          bVar2 = *(byte *)(param_1 + 0x1b) ^ *(byte *)((int)local_3c + 0xb);
                          *(byte *)((int)local_40 + 0xb) = bVar2;
                          *(byte *)(local_38 + param_1 + 0x183) = bVar2;
                          if (local_44 != 0xc) {
                            bVar2 = *(byte *)(param_1 + 0x1c) ^ (byte)local_3c[3];
                            *(byte *)(local_40 + 3) = bVar2;
                            *(byte *)(local_38 + param_1 + 0x184) = bVar2;
                            if (local_44 != 0xd) {
                              bVar2 = *(byte *)(param_1 + 0x1d) ^ *(byte *)((int)local_3c + 0xd);
                              *(byte *)((int)local_40 + 0xd) = bVar2;
                              *(byte *)(local_38 + param_1 + 0x185) = bVar2;
                              if (local_44 != 0xe) {
                                bVar2 = *(byte *)(param_1 + 0x1e) ^ *(byte *)((int)local_3c + 0xe);
                                *(byte *)((int)local_40 + 0xe) = bVar2;
                                *(byte *)(local_38 + param_1 + 0x186) = bVar2;
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
LAB_00139ed0:
  local_38 = local_38 + local_44;
LAB_00139a78:
  *(uint *)(param_1 + 0x168) = local_38;
  return 0;
}


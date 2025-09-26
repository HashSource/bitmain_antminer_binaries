
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 CRYPTO_ccm128_decrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  byte bVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  code *pcVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  undefined4 *local_54;
  uint local_4c;
  uint *local_48;
  uint *local_44;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  pcVar9 = *(code **)(param_1 + 0x28);
  bVar1 = *param_1;
  uVar10 = *(undefined4 *)(param_1 + 0x2c);
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar9)(param_1,param_1 + 0x10,uVar10);
  }
  uVar8 = bVar1 & 7;
  iVar11 = 0xf - uVar8;
  *param_1 = (byte)uVar8;
  if ((bVar1 & 7) == 0) {
    local_4c = 0;
  }
  else {
    bVar5 = param_1[iVar11];
    iVar14 = 0x10 - uVar8;
    param_1[iVar11] = 0;
    local_4c = (uint)bVar5 << 8;
    if (iVar14 != 0xf) {
      bVar2 = param_1[iVar14];
      iVar15 = 0x11 - uVar8;
      param_1[iVar14] = 0;
      uVar3 = CONCAT11(bVar5,bVar2);
      local_4c = (uint)uVar3 << 8;
      if (iVar15 != 0xf) {
        bVar5 = param_1[iVar15];
        iVar14 = 0x12 - uVar8;
        param_1[iVar15] = 0;
        uVar4 = CONCAT21(uVar3,bVar5);
        local_4c = (uint)uVar4 << 8;
        if (iVar14 != 0xf) {
          bVar5 = param_1[iVar14];
          iVar15 = 0x13 - uVar8;
          param_1[iVar14] = 0;
          local_4c = CONCAT31(uVar4,bVar5) << 8;
          if (iVar15 != 0xf) {
            bVar5 = param_1[iVar15];
            iVar14 = 0x14 - uVar8;
            param_1[iVar15] = 0;
            local_4c = (local_4c | bVar5) << 8;
            if (iVar14 != 0xf) {
              bVar5 = param_1[iVar14];
              param_1[iVar14] = 0;
              local_4c = (local_4c | bVar5) << 8;
              if (uVar8 != 6) {
                bVar5 = param_1[0xe];
                param_1[0xe] = 0;
                local_4c = (local_4c | bVar5) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar5 = param_1[0xf];
  param_1[0xf] = 1;
  local_4c = local_4c | bVar5;
  if (local_4c != param_4) {
    return 0xffffffff;
  }
  local_48 = param_2;
  local_44 = param_3;
  if (0xf < param_4) {
    puVar13 = param_2;
    puVar7 = param_3;
    do {
      param_4 = param_4 - 0x10;
      HintPreloadData(puVar13 + 8);
      HintPreloadData(puVar13 + 10);
      (*pcVar9)(param_1,&local_38,uVar10);
      bVar2 = param_1[0xf];
      param_1[0xf] = bVar2 + 1;
      if (((((byte)(bVar2 + 1) == 0) &&
           (bVar2 = param_1[0xe], param_1[0xe] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
          (bVar2 = param_1[0xd], param_1[0xd] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
         (((bVar2 = param_1[0xc], param_1[0xc] = bVar2 + 1, (byte)(bVar2 + 1) == 0 &&
           (bVar2 = param_1[0xb], param_1[0xb] = bVar2 + 1, (byte)(bVar2 + 1) == 0)) &&
          ((bVar2 = param_1[10], param_1[10] = bVar2 + 1, (byte)(bVar2 + 1) == 0 &&
           (bVar2 = param_1[9], param_1[9] = bVar2 + 1, (byte)(bVar2 + 1) == 0)))))) {
        param_1[8] = param_1[8] + 1;
      }
      local_38 = *puVar13 ^ local_38;
      local_34 = puVar13[1] ^ local_34;
      local_30 = puVar13[2] ^ local_30;
      local_2c = puVar13[3] ^ local_2c;
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_30;
      *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_2c;
      *(uint *)(param_1 + 0x10) = local_38 ^ *(uint *)(param_1 + 0x10);
      *(uint *)(param_1 + 0x14) = local_34 ^ *(uint *)(param_1 + 0x14);
      *puVar7 = local_38;
      puVar7[1] = local_34;
      puVar7[2] = local_30;
      puVar7[3] = local_2c;
      (*pcVar9)(param_1 + 0x10,param_1 + 0x10,uVar10);
      puVar13 = puVar13 + 4;
      puVar7 = puVar7 + 4;
    } while (0xf < param_4);
    uVar8 = local_4c - 0x10;
    local_4c = bVar5 & 0xf;
    iVar14 = (uVar8 & 0xfffffff0) + 0x10;
    local_48 = (uint *)((int)param_2 + iVar14);
    local_44 = (uint *)((int)param_3 + iVar14);
  }
  local_54 = &local_38;
  if (local_4c == 0) goto LAB_001447d4;
  puVar13 = (uint *)(param_1 + 0x14);
  bVar5 = (*pcVar9)(param_1,local_54,uVar10);
  puVar7 = (uint *)(param_1 + 0x10);
  if (local_44 < puVar13) {
    bVar5 = 0;
  }
  if (local_44 >= puVar13) {
    bVar5 = 1;
  }
  if (local_44 + 1 <= puVar7) {
    bVar5 = bVar5 | 1;
  }
  bVar5 = bVar5 & (puVar13 <= local_48 || local_48 + 1 <= puVar7);
  if (local_4c < 5) {
    bVar5 = 0;
  }
  bVar5 = (local_44 + 1 <= local_48 || local_48 + 1 <= local_44) & bVar5;
  if ((((uint)local_48 | (uint)local_44) & 3) != 0) {
    bVar5 = 0;
  }
  if (bVar5 == 0) {
    bVar5 = (byte)local_38 ^ (byte)*local_48;
    *(byte *)local_44 = bVar5;
    param_1[0x10] = bVar5 ^ param_1[0x10];
    if (local_4c != 1) {
      bVar5 = *(byte *)((int)local_48 + 1) ^ local_38._1_1_;
      *(byte *)((int)local_44 + 1) = bVar5;
      param_1[0x11] = bVar5 ^ param_1[0x11];
      if (local_4c != 2) {
        bVar5 = *(byte *)((int)local_48 + 2) ^ local_38._2_1_;
        *(byte *)((int)local_44 + 2) = bVar5;
        param_1[0x12] = bVar5 ^ param_1[0x12];
        if (local_4c != 3) {
          bVar5 = *(byte *)((int)local_48 + 3) ^ local_38._3_1_;
          *(byte *)((int)local_44 + 3) = bVar5;
          param_1[0x13] = bVar5 ^ param_1[0x13];
          if (4 < local_4c) {
            bVar5 = (byte)local_48[1] ^ (byte)local_34;
            *(byte *)(local_44 + 1) = bVar5;
            param_1[0x14] = bVar5 ^ param_1[0x14];
            if (5 < local_4c) {
              bVar5 = *(byte *)((int)local_48 + 5) ^ local_34._1_1_;
              *(byte *)((int)local_44 + 5) = bVar5;
              param_1[0x15] = bVar5 ^ param_1[0x15];
              if (local_4c != 6) {
                bVar5 = *(byte *)((int)local_48 + 6) ^ local_34._2_1_;
                *(byte *)((int)local_44 + 6) = bVar5;
                param_1[0x16] = bVar5 ^ param_1[0x16];
                if (local_4c != 7) {
                  bVar5 = *(byte *)((int)local_48 + 7) ^ local_34._3_1_;
                  *(byte *)((int)local_44 + 7) = bVar5;
                  param_1[0x17] = bVar5 ^ param_1[0x17];
                  if (local_4c != 8) {
                    bVar5 = (byte)local_48[2] ^ (byte)local_30;
                    *(byte *)(local_44 + 2) = bVar5;
                    param_1[0x18] = bVar5 ^ param_1[0x18];
                    if (local_4c != 9) {
                      bVar5 = *(byte *)((int)local_48 + 9) ^ local_30._1_1_;
                      *(byte *)((int)local_44 + 9) = bVar5;
                      param_1[0x19] = bVar5 ^ param_1[0x19];
                      if (local_4c != 10) {
                        bVar5 = *(byte *)((int)local_48 + 10) ^ local_30._2_1_;
                        *(byte *)((int)local_44 + 10) = bVar5;
                        param_1[0x1a] = bVar5 ^ param_1[0x1a];
                        if (local_4c != 0xb) {
                          bVar5 = *(byte *)((int)local_48 + 0xb) ^ local_30._3_1_;
                          *(byte *)((int)local_44 + 0xb) = bVar5;
                          param_1[0x1b] = bVar5 ^ param_1[0x1b];
                          if (local_4c != 0xc) {
                            bVar5 = (byte)local_48[3] ^ (byte)local_2c;
                            *(byte *)(local_44 + 3) = bVar5;
                            param_1[0x1c] = bVar5 ^ param_1[0x1c];
                            if (local_4c != 0xd) {
                              bVar5 = *(byte *)((int)local_48 + 0xd) ^ local_2c._1_1_;
                              *(byte *)((int)local_44 + 0xd) = bVar5;
                              param_1[0x1d] = bVar5 ^ param_1[0x1d];
                              if (local_4c == 0xf) {
                                bVar5 = *(byte *)((int)local_48 + 0xe) ^ local_2c._2_1_;
                                *(byte *)((int)local_44 + 0xe) = bVar5;
                                param_1[0x1e] = bVar5 ^ param_1[0x1e];
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
  else {
    iVar14 = (local_4c - 4 >> 2) + 1;
    uVar8 = iVar14 * 4;
    if (local_4c - 1 < 3) {
      uVar8 = 0;
    }
    else {
      uVar6 = *local_48;
      *local_44 = local_38 ^ uVar6;
      *(uint *)(param_1 + 0x10) = local_38 ^ uVar6 ^ *(uint *)(param_1 + 0x10);
      if (iVar14 != 1) {
        uVar6 = local_48[1];
        local_44[1] = uVar6 ^ local_34;
        *(uint *)(param_1 + 0x14) = uVar6 ^ local_34 ^ *(uint *)(param_1 + 0x14);
        if (iVar14 != 2) {
          uVar6 = local_48[2];
          local_44[2] = uVar6 ^ local_30;
          *(uint *)(param_1 + 0x18) = uVar6 ^ local_30 ^ *(uint *)(param_1 + 0x18);
          if (iVar14 != 3) {
            uVar6 = local_48[3];
            local_44[3] = uVar6 ^ local_2c;
            *(uint *)(param_1 + 0x1c) = uVar6 ^ local_2c ^ *(uint *)(param_1 + 0x1c);
          }
        }
      }
      if (local_4c == uVar8) goto LAB_0014497c;
    }
    uVar6 = uVar8 + 1;
    bVar5 = *(byte *)((int)local_48 + uVar8) ^ *(byte *)((int)&local_38 + uVar8);
    *(byte *)((int)local_44 + uVar8) = bVar5;
    param_1[uVar8 + 0x10] = bVar5 ^ param_1[uVar8 + 0x10];
    if (uVar6 < local_4c) {
      uVar12 = uVar8 + 2;
      bVar5 = *(byte *)((int)&local_38 + uVar8 + 1) ^ *(byte *)((int)local_48 + uVar6);
      *(byte *)((int)local_44 + uVar6) = bVar5;
      param_1[uVar8 + 0x11] = bVar5 ^ param_1[uVar8 + 0x11];
      if (uVar12 < local_4c) {
        bVar5 = *(byte *)((int)&local_38 + uVar8 + 2) ^ *(byte *)((int)local_48 + uVar12);
        *(byte *)((int)local_44 + uVar12) = bVar5;
        param_1[uVar8 + 0x12] = bVar5 ^ param_1[uVar8 + 0x12];
      }
    }
  }
LAB_0014497c:
  (*pcVar9)(puVar7,puVar7,uVar10);
LAB_001447d4:
  memset(param_1 + iVar11,0,0x10 - iVar11);
  (*pcVar9)(param_1,local_54,uVar10);
  *(uint *)(param_1 + 0x10) = local_38 ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_34 ^ *(uint *)(param_1 + 0x14);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_30;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_2c;
  return 0;
}


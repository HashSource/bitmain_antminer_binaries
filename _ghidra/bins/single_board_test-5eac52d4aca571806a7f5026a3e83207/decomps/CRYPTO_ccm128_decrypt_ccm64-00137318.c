
undefined4
CRYPTO_ccm128_decrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  uint3 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  int iVar10;
  uint *puVar11;
  undefined4 uVar12;
  int iVar13;
  byte bVar14;
  int iVar15;
  uint *local_48;
  uint *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  bVar1 = *param_1;
  pcVar8 = *(code **)(param_1 + 0x28);
  uVar12 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar1 & 0x40) == 0) {
    (*pcVar8)(param_1,param_1 + 0x10,uVar12);
  }
  uVar6 = bVar1 & 7;
  *param_1 = (byte)uVar6;
  iVar10 = 0xf - uVar6;
  if ((bVar1 & 7) == 0) {
    uVar9 = 0;
  }
  else {
    bVar14 = param_1[iVar10];
    iVar15 = 0x10 - uVar6;
    param_1[iVar10] = 0;
    uVar9 = (uint)bVar14 << 8;
    if (iVar15 != 0xf) {
      bVar2 = param_1[iVar15];
      iVar13 = 0x11 - uVar6;
      param_1[iVar15] = 0;
      uVar3 = CONCAT11(bVar14,bVar2);
      uVar9 = (uint)uVar3 << 8;
      if (iVar13 != 0xf) {
        bVar14 = param_1[iVar13];
        iVar15 = 0x12 - uVar6;
        param_1[iVar13] = 0;
        uVar4 = CONCAT21(uVar3,bVar14);
        uVar9 = (uint)uVar4 << 8;
        if (iVar15 != 0xf) {
          bVar14 = param_1[iVar15];
          iVar13 = 0x13 - uVar6;
          param_1[iVar15] = 0;
          uVar9 = CONCAT31(uVar4,bVar14) << 8;
          if (iVar13 != 0xf) {
            bVar14 = param_1[iVar13];
            iVar15 = 0x14 - uVar6;
            param_1[iVar13] = 0;
            uVar9 = (uVar9 | bVar14) << 8;
            if (iVar15 != 0xf) {
              bVar14 = param_1[iVar15];
              param_1[iVar15] = 0;
              uVar9 = (uVar9 | bVar14) << 8;
              if (uVar6 != 6) {
                bVar14 = param_1[0xe];
                param_1[0xe] = 0;
                uVar9 = (uVar9 | bVar14) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar14 = param_1[0xf];
  param_1[0xf] = 1;
  uVar9 = uVar9 | bVar14;
  if (uVar9 != param_4) {
    return 0xffffffff;
  }
  uVar6 = param_4 >> 4;
  if (uVar6 == 0) {
    local_48 = param_2;
    if (param_4 == 0) goto LAB_00137400;
  }
  else {
    uVar7 = uVar6 * 0x10;
    puVar11 = param_3 + uVar6 * 4;
    (*param_5)(param_2,param_3,uVar6,uVar12,param_1,param_1 + 0x10);
    local_48 = param_2 + uVar6 * 4;
    uVar9 = param_4 + uVar6 * -0x10;
    if (uVar9 == 0) goto LAB_00137400;
    uVar5 = (uVar6 & 0xff) + (uint)param_1[0xf];
    uVar6 = uVar5 >> 8;
    param_1[0xf] = (byte)uVar5;
    param_3 = puVar11;
    if (uVar6 != 0 || uVar7 >> 0xc != 0) {
      uVar6 = (uint)param_1[0xe] + (uVar7 >> 0xc & 0xff) + uVar6;
      uVar5 = uVar6 >> 8;
      param_1[0xe] = (byte)uVar6;
      if (uVar5 != 0 || uVar7 >> 0x14 != 0) {
        uVar5 = uVar5 + (uint)param_1[0xd] + (uVar7 >> 0x14 & 0xff);
        uVar6 = uVar5 >> 8;
        param_1[0xd] = (byte)uVar5;
        if (uVar6 != 0 || uVar7 >> 0x1c != 0) {
          uVar6 = uVar6 + (uVar7 >> 0x1c) + (uint)param_1[0xc];
          param_1[0xc] = (byte)uVar6;
          uVar6 = uVar6 >> 8;
          if (uVar6 != 0) {
            uVar6 = uVar6 + param_1[0xb];
            uVar7 = uVar6 >> 8;
            param_1[0xb] = (byte)uVar6;
            if (uVar7 != 0) {
              uVar7 = param_1[10] + uVar7;
              uVar6 = uVar7 >> 8;
              param_1[10] = (byte)uVar7;
              if (uVar6 != 0) {
                uVar6 = param_1[9] + uVar6;
                param_1[9] = (byte)uVar6;
                if (uVar6 >> 8 != 0) {
                  param_1[8] = (char)(uVar6 >> 8) + param_1[8];
                }
              }
            }
          }
        }
      }
    }
  }
  local_40 = (uint *)(param_1 + 0x10);
  (*pcVar8)(param_1,&local_38,uVar12);
  if ((((uint)param_3 | (uint)local_48) & 3) == 0 &&
      ((local_48 + 1 <= param_3 || param_3 + 1 <= local_48) &&
      (4 < uVar9 &&
      ((param_3 + 1 <= local_40 || param_1 + 0x14 <= param_3) &&
      (param_1 + 0x14 <= local_48 || local_48 + 1 <= local_40))))) {
    uVar6 = uVar9;
    if (uVar9 == 0) {
      uVar6 = 1;
    }
    iVar15 = (uVar6 - 4 >> 2) + 1;
    uVar7 = iVar15 * 4;
    if (uVar9 < 4) {
      uVar7 = 0;
    }
    else {
      uVar5 = *local_48;
      *param_3 = uVar5 ^ local_38;
      *(uint *)(param_1 + 0x10) = uVar5 ^ local_38 ^ *(uint *)(param_1 + 0x10);
      if (iVar15 != 1) {
        uVar5 = local_48[1];
        param_3[1] = local_34 ^ uVar5;
        *(uint *)(param_1 + 0x14) = local_34 ^ uVar5 ^ *(uint *)(param_1 + 0x14);
        if (iVar15 != 2) {
          uVar5 = local_48[2];
          param_3[2] = local_30 ^ uVar5;
          *(uint *)(param_1 + 0x18) = local_30 ^ uVar5 ^ *(uint *)(param_1 + 0x18);
          if (iVar15 != 3) {
            uVar5 = local_48[3];
            param_3[3] = local_2c ^ uVar5;
            *(uint *)(param_1 + 0x1c) = local_2c ^ uVar5 ^ *(uint *)(param_1 + 0x1c);
          }
        }
      }
      if (uVar6 == uVar7) goto LAB_0013764e;
    }
    uVar6 = uVar7 + 1;
    bVar14 = *(byte *)((int)local_48 + uVar7) ^ *(byte *)((int)&local_38 + uVar7);
    *(byte *)((int)param_3 + uVar7) = bVar14;
    param_1[uVar7 + 0x10] = bVar14 ^ param_1[uVar7 + 0x10];
    if (uVar6 < uVar9) {
      uVar5 = uVar7 + 2;
      bVar14 = *(byte *)((int)local_48 + uVar6) ^ *(byte *)((int)&local_38 + uVar7 + 1);
      *(byte *)((int)param_3 + uVar6) = bVar14;
      param_1[uVar7 + 0x11] = bVar14 ^ param_1[uVar7 + 0x11];
      if (uVar5 < uVar9) {
        bVar14 = *(byte *)((int)&local_38 + uVar7 + 2) ^ *(byte *)((int)local_48 + uVar5);
        *(byte *)((int)param_3 + uVar5) = bVar14;
        param_1[uVar7 + 0x12] = bVar14 ^ param_1[uVar7 + 0x12];
      }
    }
  }
  else {
    bVar14 = (byte)*local_48 ^ (byte)local_38;
    *(byte *)param_3 = bVar14;
    param_1[0x10] = bVar14 ^ param_1[0x10];
    if (uVar9 != 1) {
      bVar14 = *(byte *)((int)local_48 + 1) ^ local_38._1_1_;
      *(byte *)((int)param_3 + 1) = bVar14;
      param_1[0x11] = bVar14 ^ param_1[0x11];
      if (uVar9 != 2) {
        bVar14 = *(byte *)((int)local_48 + 2) ^ local_38._2_1_;
        *(byte *)((int)param_3 + 2) = bVar14;
        param_1[0x12] = bVar14 ^ param_1[0x12];
        if (uVar9 != 3) {
          bVar14 = *(byte *)((int)local_48 + 3) ^ local_38._3_1_;
          *(byte *)((int)param_3 + 3) = bVar14;
          param_1[0x13] = bVar14 ^ param_1[0x13];
          if (4 < uVar9) {
            bVar14 = (byte)local_48[1] ^ (byte)local_34;
            *(byte *)(param_3 + 1) = bVar14;
            param_1[0x14] = bVar14 ^ param_1[0x14];
            if (5 < uVar9) {
              bVar14 = *(byte *)((int)local_48 + 5) ^ local_34._1_1_;
              *(byte *)((int)param_3 + 5) = bVar14;
              param_1[0x15] = bVar14 ^ param_1[0x15];
              if (uVar9 != 6) {
                bVar14 = *(byte *)((int)local_48 + 6) ^ local_34._2_1_;
                *(byte *)((int)param_3 + 6) = bVar14;
                param_1[0x16] = bVar14 ^ param_1[0x16];
                if (uVar9 != 7) {
                  bVar14 = *(byte *)((int)local_48 + 7) ^ local_34._3_1_;
                  *(byte *)((int)param_3 + 7) = bVar14;
                  param_1[0x17] = bVar14 ^ param_1[0x17];
                  if (uVar9 != 8) {
                    bVar14 = (byte)local_48[2] ^ (byte)local_30;
                    *(byte *)(param_3 + 2) = bVar14;
                    param_1[0x18] = bVar14 ^ param_1[0x18];
                    if (uVar9 != 9) {
                      bVar14 = *(byte *)((int)local_48 + 9) ^ local_30._1_1_;
                      *(byte *)((int)param_3 + 9) = bVar14;
                      param_1[0x19] = bVar14 ^ param_1[0x19];
                      if (uVar9 != 10) {
                        bVar14 = *(byte *)((int)local_48 + 10) ^ local_30._2_1_;
                        *(byte *)((int)param_3 + 10) = bVar14;
                        param_1[0x1a] = bVar14 ^ param_1[0x1a];
                        if (uVar9 != 0xb) {
                          bVar14 = *(byte *)((int)local_48 + 0xb) ^ local_30._3_1_;
                          *(byte *)((int)param_3 + 0xb) = bVar14;
                          param_1[0x1b] = bVar14 ^ param_1[0x1b];
                          if (uVar9 != 0xc) {
                            bVar14 = (byte)local_48[3] ^ (byte)local_2c;
                            *(byte *)(param_3 + 3) = bVar14;
                            param_1[0x1c] = bVar14 ^ param_1[0x1c];
                            if (uVar9 != 0xd) {
                              bVar14 = *(byte *)((int)local_48 + 0xd) ^ local_2c._1_1_;
                              *(byte *)((int)param_3 + 0xd) = bVar14;
                              param_1[0x1d] = bVar14 ^ param_1[0x1d];
                              if (uVar9 != 0xe) {
                                bVar14 = *(byte *)((int)local_48 + 0xe) ^ local_2c._2_1_;
                                *(byte *)((int)param_3 + 0xe) = bVar14;
                                param_1[0x1e] = bVar14 ^ param_1[0x1e];
                                if (uVar9 != 0xf) {
                                  bVar14 = *(byte *)((int)local_48 + 0xf) ^ local_2c._3_1_;
                                  *(byte *)((int)param_3 + 0xf) = bVar14;
                                  param_1[0x1f] = bVar14 ^ param_1[0x1f];
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
LAB_0013764e:
  (*pcVar8)(local_40,local_40,uVar12);
LAB_00137400:
  memset(param_1 + iVar10,0,0x10 - iVar10);
  (*pcVar8)(param_1,&local_38,uVar12);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x10) = local_38 ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_34 ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = local_30 ^ *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x1c) = local_2c ^ *(uint *)(param_1 + 0x1c);
  return 0;
}


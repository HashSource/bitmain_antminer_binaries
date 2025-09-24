
undefined4
CRYPTO_ccm128_encrypt_ccm64(byte *param_1,uint *param_2,uint *param_3,uint param_4,code *param_5)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint3 uVar5;
  int iVar6;
  uint uVar7;
  code *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  bool bVar17;
  uint *local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  pcVar8 = *(code **)(param_1 + 0x28);
  bVar2 = *param_1;
  uVar9 = *(undefined4 *)(param_1 + 0x2c);
  if ((bVar2 & 0x40) == 0) {
    (*pcVar8)(param_1,param_1 + 0x10,uVar9);
    uVar10 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar10 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar10);
  }
  uVar10 = bVar2 & 7;
  *param_1 = (byte)uVar10;
  iVar15 = 0xf - uVar10;
  if ((bVar2 & 7) == 0) {
    uVar12 = 0;
  }
  else {
    bVar3 = param_1[iVar15];
    iVar6 = 0x10 - uVar10;
    param_1[iVar15] = 0;
    uVar12 = (uint)bVar3 << 8;
    if (iVar6 != 0xf) {
      bVar1 = param_1[iVar6];
      iVar16 = 0x11 - uVar10;
      param_1[iVar6] = 0;
      uVar4 = CONCAT11(bVar3,bVar1);
      uVar12 = (uint)uVar4 << 8;
      if (iVar16 != 0xf) {
        bVar3 = param_1[iVar16];
        iVar6 = 0x12 - uVar10;
        param_1[iVar16] = 0;
        uVar5 = CONCAT21(uVar4,bVar3);
        uVar12 = (uint)uVar5 << 8;
        if (iVar6 != 0xf) {
          bVar3 = param_1[iVar6];
          iVar16 = 0x13 - uVar10;
          param_1[iVar6] = 0;
          uVar12 = CONCAT31(uVar5,bVar3) << 8;
          if (iVar16 != 0xf) {
            bVar3 = param_1[iVar16];
            iVar6 = 0x14 - uVar10;
            param_1[iVar16] = 0;
            uVar12 = (uVar12 | bVar3) << 8;
            if (iVar6 != 0xf) {
              bVar3 = param_1[iVar6];
              param_1[iVar6] = 0;
              uVar12 = (uVar12 | bVar3) << 8;
              if (uVar10 != 6) {
                bVar3 = param_1[0xe];
                param_1[0xe] = 0;
                uVar12 = (uVar12 | bVar3) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar3 = param_1[0xf];
  param_1[0xf] = 1;
  uVar12 = uVar12 | bVar3;
  if (uVar12 != param_4) {
    return 0xffffffff;
  }
  uVar10 = param_4 + 0xf >> 3 | 1;
  iVar6 = *(uint *)(param_1 + 0x20) + uVar10;
  uVar10 = *(int *)(param_1 + 0x24) + (uint)CARRY4(*(uint *)(param_1 + 0x20),uVar10);
  bVar17 = 0x1fffffff < uVar10;
  *(int *)(param_1 + 0x20) = iVar6;
  *(uint *)(param_1 + 0x24) = uVar10;
  if (uVar10 == 0x20000000) {
    bVar17 = iVar6 != 0;
  }
  if (bVar17) {
    return 0xfffffffe;
  }
  uVar10 = param_4 >> 4;
  if (uVar10 == 0) {
    if (param_4 == 0) goto LAB_0013b234;
  }
  else {
    uVar7 = uVar10 * 0x10;
    puVar13 = param_2 + uVar10 * 4;
    puVar14 = param_3 + uVar10 * 4;
    (*param_5)(param_2,param_3,uVar10,uVar9,param_1,param_1 + 0x10);
    uVar12 = param_4 + uVar10 * -0x10;
    if (uVar12 == 0) goto LAB_0013b234;
    uVar11 = (uVar10 & 0xff) + (uint)param_1[0xf];
    uVar10 = uVar11 >> 8;
    param_1[0xf] = (byte)uVar11;
    param_2 = puVar13;
    param_3 = puVar14;
    if (uVar10 != 0 || uVar7 >> 0xc != 0) {
      uVar10 = uVar10 + (uint)param_1[0xe] + (uVar7 >> 0xc & 0xff);
      uVar11 = uVar10 >> 8;
      param_1[0xe] = (byte)uVar10;
      if (uVar11 != 0 || uVar7 >> 0x14 != 0) {
        uVar11 = uVar11 + (uVar7 >> 0x14 & 0xff) + (uint)param_1[0xd];
        uVar10 = uVar11 >> 8;
        param_1[0xd] = (byte)uVar11;
        if (uVar10 != 0 || uVar7 >> 0x1c != 0) {
          uVar10 = uVar10 + (uVar7 >> 0x1c) + (uint)param_1[0xc];
          param_1[0xc] = (byte)uVar10;
          uVar10 = uVar10 >> 8;
          if (uVar10 != 0) {
            uVar10 = uVar10 + param_1[0xb];
            uVar7 = uVar10 >> 8;
            param_1[0xb] = (byte)uVar10;
            if (uVar7 != 0) {
              uVar7 = param_1[10] + uVar7;
              uVar10 = uVar7 >> 8;
              param_1[10] = (byte)uVar7;
              if (uVar10 != 0) {
                uVar10 = param_1[9] + uVar10;
                param_1[9] = (byte)uVar10;
                if (uVar10 >> 8 != 0) {
                  param_1[8] = (char)(uVar10 >> 8) + param_1[8];
                }
              }
            }
          }
        }
      }
    }
  }
  local_40 = (uint *)(param_1 + 0x10);
  if (((uint)param_2 & 3) != 0 || (param_2 < param_1 + 0x14 && local_40 < param_2 + 1 || uVar12 < 6)
     ) {
    param_1[0x10] = (byte)*param_2 ^ param_1[0x10];
    if (((((uVar12 != 1) &&
          (param_1[0x11] = *(byte *)((int)param_2 + 1) ^ param_1[0x11], uVar12 != 2)) &&
         (param_1[0x12] = *(byte *)((int)param_2 + 2) ^ param_1[0x12], uVar12 != 3)) &&
        (((((param_1[0x13] = *(byte *)((int)param_2 + 3) ^ param_1[0x13], uVar12 != 4 &&
            (param_1[0x14] = (byte)param_2[1] ^ param_1[0x14], 5 < uVar12)) &&
           ((param_1[0x15] = *(byte *)((int)param_2 + 5) ^ param_1[0x15], 6 < uVar12 &&
            ((param_1[0x16] = *(byte *)((int)param_2 + 6) ^ param_1[0x16], uVar12 != 7 &&
             (param_1[0x17] = *(byte *)((int)param_2 + 7) ^ param_1[0x17], uVar12 != 8)))))) &&
          (param_1[0x18] = (byte)param_2[2] ^ param_1[0x18], uVar12 != 9)) &&
         (((param_1[0x19] = *(byte *)((int)param_2 + 9) ^ param_1[0x19], uVar12 != 10 &&
           (param_1[0x1a] = *(byte *)((int)param_2 + 10) ^ param_1[0x1a], uVar12 != 0xb)) &&
          (param_1[0x1b] = *(byte *)((int)param_2 + 0xb) ^ param_1[0x1b], uVar12 != 0xc)))))) &&
       (((param_1[0x1c] = (byte)param_2[3] ^ param_1[0x1c], uVar12 != 0xd &&
         (param_1[0x1d] = *(byte *)((int)param_2 + 0xd) ^ param_1[0x1d], uVar12 != 0xe)) &&
        (param_1[0x1e] = *(byte *)((int)param_2 + 0xe) ^ param_1[0x1e], uVar12 != 0xf)))) {
      param_1[0x1f] = *(byte *)((int)param_2 + 0xf) ^ param_1[0x1f];
    }
  }
  else {
    uVar10 = uVar12;
    if (uVar12 == 0) {
      uVar10 = 1;
    }
    iVar6 = (uVar10 - 4 >> 2) + 1;
    uVar7 = iVar6 * 4;
    if (uVar12 < 4) {
      uVar7 = 0;
    }
    else {
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ *param_2;
      if (((iVar6 != 1) &&
          (*(uint *)(param_1 + 0x14) = param_2[1] ^ *(uint *)(param_1 + 0x14), iVar6 != 2)) &&
         (*(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ param_2[2], iVar6 != 3)) {
        *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ param_2[3];
      }
      if (uVar10 == uVar7) goto LAB_0013b128;
    }
    param_1[uVar7 + 0x10] = param_1[uVar7 + 0x10] ^ *(byte *)((int)param_2 + uVar7);
    if (uVar7 + 1 < uVar12) {
      param_1[uVar7 + 0x11] = param_1[uVar7 + 0x11] ^ *(byte *)((int)param_2 + uVar7 + 1);
      if (uVar7 + 2 < uVar12) {
        param_1[uVar7 + 0x12] = param_1[uVar7 + 0x12] ^ *(byte *)((int)param_2 + uVar7 + 2);
      }
    }
  }
LAB_0013b128:
  (*pcVar8)(local_40,local_40,uVar9);
  (*pcVar8)(param_1,&local_38,uVar9);
  if ((((uint)param_3 | (uint)param_2) & 3) != 0 ||
      (uVar12 < 6 || param_3 < param_2 + 1 && param_2 < param_3 + 1)) {
    *(byte *)param_3 = (byte)*param_2 ^ (byte)local_38;
    if (uVar12 != 1) {
      *(byte *)((int)param_3 + 1) = *(byte *)((int)param_2 + 1) ^ local_38._1_1_;
      if (uVar12 != 2) {
        *(byte *)((int)param_3 + 2) = *(byte *)((int)param_2 + 2) ^ local_38._2_1_;
        if (uVar12 != 3) {
          *(byte *)((int)param_3 + 3) = *(byte *)((int)param_2 + 3) ^ local_38._3_1_;
          if (uVar12 != 4) {
            *(byte *)(param_3 + 1) = (byte)param_2[1] ^ (byte)local_34;
            if (5 < uVar12) {
              *(byte *)((int)param_3 + 5) = *(byte *)((int)param_2 + 5) ^ local_34._1_1_;
              if (6 < uVar12) {
                *(byte *)((int)param_3 + 6) = *(byte *)((int)param_2 + 6) ^ local_34._2_1_;
                if (uVar12 != 7) {
                  *(byte *)((int)param_3 + 7) = *(byte *)((int)param_2 + 7) ^ local_34._3_1_;
                  if (uVar12 != 8) {
                    *(byte *)(param_3 + 2) = (byte)param_2[2] ^ (byte)local_30;
                    if (uVar12 != 9) {
                      *(byte *)((int)param_3 + 9) = *(byte *)((int)param_2 + 9) ^ local_30._1_1_;
                      if (uVar12 != 10) {
                        *(byte *)((int)param_3 + 10) = *(byte *)((int)param_2 + 10) ^ local_30._2_1_
                        ;
                        if (uVar12 != 0xb) {
                          *(byte *)((int)param_3 + 0xb) =
                               *(byte *)((int)param_2 + 0xb) ^ local_30._3_1_;
                          if (uVar12 != 0xc) {
                            *(byte *)(param_3 + 3) = (byte)param_2[3] ^ (byte)local_2c;
                            if (uVar12 != 0xd) {
                              *(byte *)((int)param_3 + 0xd) =
                                   *(byte *)((int)param_2 + 0xd) ^ local_2c._1_1_;
                              if (uVar12 != 0xe) {
                                *(byte *)((int)param_3 + 0xe) =
                                     *(byte *)((int)param_2 + 0xe) ^ local_2c._2_1_;
                                if (uVar12 != 0xf) {
                                  *(byte *)((int)param_3 + 0xf) =
                                       local_2c._3_1_ ^ *(byte *)((int)param_2 + 0xf);
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
  else {
    uVar10 = uVar12;
    if (uVar12 == 0) {
      uVar10 = 1;
    }
    iVar6 = (uVar10 - 4 >> 2) + 1;
    uVar7 = iVar6 * 4;
    if (uVar12 < 4) {
      uVar7 = 0;
    }
    else {
      *param_3 = local_38 ^ *param_2;
      if (((iVar6 != 1) && (param_3[1] = local_34 ^ param_2[1], iVar6 != 2)) &&
         (param_3[2] = local_30 ^ param_2[2], iVar6 != 3)) {
        param_3[3] = local_2c ^ param_2[3];
      }
      if (uVar7 == uVar10) goto LAB_0013b234;
    }
    uVar10 = uVar7 + 1;
    *(byte *)((int)param_3 + uVar7) =
         *(byte *)((int)&local_38 + uVar7) ^ *(byte *)((int)param_2 + uVar7);
    if (uVar10 < uVar12) {
      uVar11 = uVar7 + 2;
      *(byte *)((int)param_3 + uVar10) =
           *(byte *)((int)&local_38 + uVar7 + 1) ^ *(byte *)((int)param_2 + uVar10);
      if (uVar11 < uVar12) {
        *(byte *)((int)param_3 + uVar11) =
             *(byte *)((int)&local_38 + uVar7 + 2) ^ *(byte *)((int)param_2 + uVar11);
      }
    }
  }
LAB_0013b234:
  memset(param_1 + iVar15,0,0x10 - iVar15);
  (*pcVar8)(param_1,&local_38,uVar9);
  *param_1 = bVar2;
  *(uint *)(param_1 + 0x10) = local_38 ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_34 ^ *(uint *)(param_1 + 0x14);
  *(uint *)(param_1 + 0x18) = local_30 ^ *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x1c) = local_2c ^ *(uint *)(param_1 + 0x1c);
  return 0;
}



void CRYPTO_cbc128_decrypt
               (uint *param_1,uint *param_2,uint param_3,undefined4 param_4,uint *param_5,
               code *param_6)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  int iVar10;
  uint unaff_r8;
  uint *puVar11;
  uint *puVar12;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_3 == 0) {
    return;
  }
  if (param_1 == param_2) {
    if ((((uint)param_2 | (uint)param_5) & 3) == 0) {
      if (0xf < param_3) {
        param_2 = param_1 + 4;
        unaff_r8 = param_3;
      }
      puVar9 = param_2;
      if (param_3 < 0x10) goto LAB_00139c30;
      do {
        unaff_r8 = unaff_r8 - 0x10;
        (*param_6)(param_2 + -4,&local_38,param_4);
        uVar7 = param_2[-4];
        param_2[-4] = *param_5 ^ local_38;
        *param_5 = uVar7;
        uVar7 = param_2[-3];
        param_2[-3] = param_5[1] ^ local_34;
        param_5[1] = uVar7;
        uVar7 = param_2[-2];
        param_2[-2] = param_5[2] ^ local_30;
        param_5[2] = uVar7;
        uVar7 = param_2[-1];
        param_2[-1] = param_5[3] ^ local_2c;
        param_5[3] = uVar7;
        param_2 = param_2 + 4;
      } while (0xf < unaff_r8);
    }
    else {
      puVar9 = param_2;
      if (param_3 < 0x10) goto LAB_00139c30;
      puVar9 = param_1 + 4;
      uVar7 = param_3;
      do {
        uVar7 = uVar7 - 0x10;
        (*param_6)(puVar9 + -4,&local_38,param_4);
        uVar3 = puVar9[-4];
        *(byte *)(puVar9 + -4) = (byte)*param_5 ^ (byte)local_38;
        *(byte *)param_5 = (byte)uVar3;
        bVar1 = *(byte *)((int)puVar9 + -0xf);
        *(byte *)((int)puVar9 + -0xf) = *(byte *)((int)param_5 + 1) ^ local_38._1_1_;
        *(byte *)((int)param_5 + 1) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -0xe);
        *(byte *)((int)puVar9 + -0xe) = *(byte *)((int)param_5 + 2) ^ local_38._2_1_;
        *(byte *)((int)param_5 + 2) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -0xd);
        *(byte *)((int)puVar9 + -0xd) = *(byte *)((int)param_5 + 3) ^ local_38._3_1_;
        *(byte *)((int)param_5 + 3) = bVar1;
        uVar3 = puVar9[-3];
        *(byte *)(puVar9 + -3) = (byte)param_5[1] ^ (byte)local_34;
        *(byte *)(param_5 + 1) = (byte)uVar3;
        bVar1 = *(byte *)((int)puVar9 + -0xb);
        *(byte *)((int)puVar9 + -0xb) = *(byte *)((int)param_5 + 5) ^ local_34._1_1_;
        *(byte *)((int)param_5 + 5) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -10);
        *(byte *)((int)puVar9 + -10) = *(byte *)((int)param_5 + 6) ^ local_34._2_1_;
        *(byte *)((int)param_5 + 6) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -9);
        *(byte *)((int)puVar9 + -9) = *(byte *)((int)param_5 + 7) ^ local_34._3_1_;
        *(byte *)((int)param_5 + 7) = bVar1;
        uVar3 = puVar9[-2];
        *(byte *)(puVar9 + -2) = (byte)param_5[2] ^ (byte)local_30;
        *(byte *)(param_5 + 2) = (byte)uVar3;
        bVar1 = *(byte *)((int)puVar9 + -7);
        *(byte *)((int)puVar9 + -7) = *(byte *)((int)param_5 + 9) ^ local_30._1_1_;
        *(byte *)((int)param_5 + 9) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -6);
        *(byte *)((int)puVar9 + -6) = *(byte *)((int)param_5 + 10) ^ local_30._2_1_;
        *(byte *)((int)param_5 + 10) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -5);
        *(byte *)((int)puVar9 + -5) = *(byte *)((int)param_5 + 0xb) ^ local_30._3_1_;
        *(byte *)((int)param_5 + 0xb) = bVar1;
        uVar3 = puVar9[-1];
        *(byte *)(puVar9 + -1) = (byte)param_5[3] ^ (byte)local_2c;
        *(byte *)(param_5 + 3) = (byte)uVar3;
        bVar1 = *(byte *)((int)puVar9 + -3);
        *(byte *)((int)puVar9 + -3) = *(byte *)((int)param_5 + 0xd) ^ local_2c._1_1_;
        *(byte *)((int)param_5 + 0xd) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -2);
        *(byte *)((int)puVar9 + -2) = *(byte *)((int)param_5 + 0xe) ^ local_2c._2_1_;
        *(byte *)((int)param_5 + 0xe) = bVar1;
        bVar1 = *(byte *)((int)puVar9 + -1);
        *(byte *)((int)puVar9 + -1) = *(byte *)((int)param_5 + 0xf) ^ local_2c._3_1_;
        *(byte *)((int)param_5 + 0xf) = bVar1;
        puVar9 = puVar9 + 4;
      } while (0xf < uVar7);
    }
    param_2 = (uint *)((int)param_1 + (param_3 - 0x10 & 0xfffffff0) + 0x10);
    puVar9 = param_2;
  }
  else {
    puVar9 = param_1;
    if ((((uint)param_2 | (uint)param_5 | (uint)param_1) & 3) == 0) {
      if (param_3 < 0x10) goto LAB_00139c30;
      uVar7 = param_3;
      puVar9 = param_2 + 4;
      puVar11 = param_5;
      puVar12 = param_1;
      do {
        uVar7 = uVar7 - 0x10;
        (*param_6)(puVar12,puVar9 + -4,param_4);
        puVar9[-4] = *puVar11 ^ puVar9[-4];
        puVar9[-3] = puVar11[1] ^ puVar9[-3];
        puVar9[-2] = puVar11[2] ^ puVar9[-2];
        puVar9[-1] = puVar9[-1] ^ puVar11[3];
        puVar9 = puVar9 + 4;
        puVar11 = puVar12;
        puVar12 = puVar12 + 4;
      } while (0xf < uVar7);
    }
    else {
      if (param_3 < 0x10) goto LAB_00139c30;
      uVar7 = param_3;
      puVar9 = param_2 + 4;
      puVar11 = param_5;
      puVar12 = param_1;
      do {
        uVar7 = uVar7 - 0x10;
        (*param_6)(puVar12,puVar9 + -4,param_4);
        *(byte *)(puVar9 + -4) = (byte)*puVar11 ^ (byte)puVar9[-4];
        *(byte *)((int)puVar9 + -0xf) = *(byte *)((int)puVar11 + 1) ^ *(byte *)((int)puVar9 + -0xf);
        *(byte *)((int)puVar9 + -0xe) = *(byte *)((int)puVar11 + 2) ^ *(byte *)((int)puVar9 + -0xe);
        *(byte *)((int)puVar9 + -0xd) = *(byte *)((int)puVar9 + -0xd) ^ *(byte *)((int)puVar11 + 3);
        *(byte *)(puVar9 + -3) = (byte)puVar11[1] ^ (byte)puVar9[-3];
        *(byte *)((int)puVar9 + -0xb) = *(byte *)((int)puVar11 + 5) ^ *(byte *)((int)puVar9 + -0xb);
        *(byte *)((int)puVar9 + -10) = *(byte *)((int)puVar9 + -10) ^ *(byte *)((int)puVar11 + 6);
        *(byte *)((int)puVar9 + -9) = *(byte *)((int)puVar11 + 7) ^ *(byte *)((int)puVar9 + -9);
        *(byte *)(puVar9 + -2) = (byte)puVar11[2] ^ (byte)puVar9[-2];
        *(byte *)((int)puVar9 + -7) = *(byte *)((int)puVar9 + -7) ^ *(byte *)((int)puVar11 + 9);
        *(byte *)((int)puVar9 + -6) = *(byte *)((int)puVar11 + 10) ^ *(byte *)((int)puVar9 + -6);
        *(byte *)((int)puVar9 + -5) = *(byte *)((int)puVar11 + 0xb) ^ *(byte *)((int)puVar9 + -5);
        *(byte *)(puVar9 + -1) = (byte)puVar11[3] ^ (byte)puVar9[-1];
        *(byte *)((int)puVar9 + -3) = *(byte *)((int)puVar11 + 0xd) ^ *(byte *)((int)puVar9 + -3);
        *(byte *)((int)puVar9 + -2) = *(byte *)((int)puVar9 + -2) ^ *(byte *)((int)puVar11 + 0xe);
        *(byte *)((int)puVar9 + -1) = *(byte *)((int)puVar11 + 0xf) ^ *(byte *)((int)puVar9 + -1);
        puVar9 = puVar9 + 4;
        puVar11 = puVar12;
        puVar12 = puVar12 + 4;
      } while (0xf < uVar7);
    }
    uVar7 = param_3 - 0x10 >> 4;
    iVar10 = uVar7 + 1;
    puVar11 = param_1 + uVar7 * 4;
    param_2 = param_2 + iVar10 * 4;
    puVar9 = param_1 + iVar10 * 4;
    if (puVar11 != param_5) {
      uVar7 = puVar11[1];
      uVar3 = puVar11[2];
      uVar5 = puVar11[3];
      *param_5 = *puVar11;
      param_5[1] = uVar7;
      param_5[2] = uVar3;
      param_5[3] = uVar5;
    }
  }
  param_3 = param_3 & 0xf;
  if (param_3 == 0) {
    return;
  }
LAB_00139c30:
  (*param_6)(puVar9,&local_38,param_4);
  uVar7 = *puVar9;
  *(byte *)param_2 = (byte)*param_5 ^ (byte)local_38;
  *(byte *)param_5 = (byte)uVar7;
  if (param_3 != 1) {
    bVar1 = *(byte *)((int)puVar9 + 1);
    *(byte *)((int)param_2 + 1) = *(byte *)((int)param_5 + 1) ^ local_38._1_1_;
    *(byte *)((int)param_5 + 1) = bVar1;
    if (param_3 != 2) {
      bVar1 = *(byte *)((int)puVar9 + 2);
      *(byte *)((int)param_2 + 2) = *(byte *)((int)param_5 + 2) ^ local_38._2_1_;
      *(byte *)((int)param_5 + 2) = bVar1;
      if (param_3 != 3) {
        bVar1 = *(byte *)((int)puVar9 + 3);
        *(byte *)((int)param_2 + 3) = *(byte *)((int)param_5 + 3) ^ local_38._3_1_;
        *(byte *)((int)param_5 + 3) = bVar1;
        if (param_3 != 4) {
          uVar7 = puVar9[1];
          *(byte *)(param_2 + 1) = (byte)param_5[1] ^ (byte)local_34;
          *(byte *)(param_5 + 1) = (byte)uVar7;
          if (param_3 != 5) {
            bVar1 = *(byte *)((int)puVar9 + 5);
            *(byte *)((int)param_2 + 5) = *(byte *)((int)param_5 + 5) ^ local_34._1_1_;
            *(byte *)((int)param_5 + 5) = bVar1;
            if (param_3 != 6) {
              bVar1 = *(byte *)((int)puVar9 + 6);
              *(byte *)((int)param_2 + 6) = *(byte *)((int)param_5 + 6) ^ local_34._2_1_;
              *(byte *)((int)param_5 + 6) = bVar1;
              if (param_3 != 7) {
                bVar1 = *(byte *)((int)puVar9 + 7);
                *(byte *)((int)param_2 + 7) = *(byte *)((int)param_5 + 7) ^ local_34._3_1_;
                *(byte *)((int)param_5 + 7) = bVar1;
                if (param_3 != 8) {
                  uVar7 = puVar9[2];
                  *(byte *)(param_2 + 2) = (byte)param_5[2] ^ (byte)local_30;
                  *(byte *)(param_5 + 2) = (byte)uVar7;
                  if (param_3 != 9) {
                    bVar1 = *(byte *)((int)puVar9 + 9);
                    *(byte *)((int)param_2 + 9) = *(byte *)((int)param_5 + 9) ^ local_30._1_1_;
                    *(byte *)((int)param_5 + 9) = bVar1;
                    if (param_3 == 10) {
                      param_3 = 10;
                    }
                    else {
                      bVar1 = *(byte *)((int)puVar9 + 10);
                      *(byte *)((int)param_2 + 10) = *(byte *)((int)param_5 + 10) ^ local_30._2_1_;
                      *(byte *)((int)param_5 + 10) = bVar1;
                      if (param_3 != 0xb) {
                        bVar1 = *(byte *)((int)puVar9 + 0xb);
                        *(byte *)((int)param_2 + 0xb) =
                             *(byte *)((int)param_5 + 0xb) ^ local_30._3_1_;
                        *(byte *)((int)param_5 + 0xb) = bVar1;
                        if (param_3 != 0xc) {
                          uVar7 = puVar9[3];
                          *(byte *)(param_2 + 3) = (byte)param_5[3] ^ (byte)local_2c;
                          *(byte *)(param_5 + 3) = (byte)uVar7;
                          if (param_3 != 0xd) {
                            bVar1 = *(byte *)((int)puVar9 + 0xd);
                            *(byte *)((int)param_2 + 0xd) =
                                 *(byte *)((int)param_5 + 0xd) ^ local_2c._1_1_;
                            *(byte *)((int)param_5 + 0xd) = bVar1;
                            if (param_3 == 0xf) {
                              bVar1 = *(byte *)((int)puVar9 + 0xe);
                              *(byte *)((int)param_2 + 0xe) =
                                   *(byte *)((int)param_5 + 0xe) ^ local_2c._2_1_;
                              *(byte *)((int)param_5 + 0xe) = bVar1;
                              *(byte *)((int)param_5 + 0xf) = *(byte *)((int)puVar9 + 0xf);
                              return;
                            }
                            param_3 = 0xe;
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
  iVar10 = param_3 + 4;
  pbVar2 = (byte *)((int)puVar9 + param_3);
  pbVar4 = (byte *)((int)param_5 + param_3);
  uVar7 = 0x10 - param_3;
  if ((((uint)pbVar2 | (uint)pbVar4) & 3) == 0 &&
      (9 < uVar7 &&
      ((byte *)((int)puVar9 + iVar10) <= pbVar4 || (byte *)((int)param_5 + iVar10) <= pbVar2))) {
    iVar10 = (0xc - param_3 >> 2) + 1;
    uVar3 = iVar10 * 4;
    if (2 < 0xf - param_3) {
      *(undefined4 *)pbVar4 = *(undefined4 *)pbVar2;
      *(undefined4 *)(pbVar4 + 4) = *(undefined4 *)(pbVar2 + 4);
      if (iVar10 == 3) {
        *(undefined4 *)(pbVar4 + 8) = *(undefined4 *)(pbVar2 + 8);
      }
      param_3 = param_3 + uVar3;
      if (uVar3 == uVar7) {
        return;
      }
    }
    iVar10 = param_3 + 1;
    *(byte *)((int)param_5 + param_3) = *(byte *)((int)puVar9 + param_3);
    if (iVar10 != 0x10) {
      iVar8 = param_3 + 2;
      *(byte *)((int)param_5 + iVar10) = *(byte *)((int)puVar9 + iVar10);
      if (iVar8 != 0x10) {
        *(byte *)((int)param_5 + iVar8) = *(byte *)((int)puVar9 + iVar8);
      }
    }
  }
  else {
    iVar8 = param_3 + 2;
    *(byte *)((int)param_5 + param_3) = *(byte *)((int)puVar9 + param_3);
    *(byte *)((int)param_5 + param_3 + 1) = *(byte *)((int)puVar9 + param_3 + 1);
    if (iVar8 != 0x10) {
      iVar6 = param_3 + 3;
      *(byte *)((int)param_5 + iVar8) = *(byte *)((int)puVar9 + iVar8);
      if ((iVar6 != 0x10) &&
         (*(byte *)((int)param_5 + iVar6) = *(byte *)((int)puVar9 + iVar6), iVar10 != 0x10)) {
        iVar8 = param_3 + 5;
        *(byte *)((int)param_5 + iVar10) = *(byte *)((int)puVar9 + iVar10);
        if (iVar8 != 0x10) {
          iVar10 = param_3 + 6;
          *(byte *)((int)param_5 + iVar8) = *(byte *)((int)puVar9 + iVar8);
          if (iVar10 != 0x10) {
            iVar8 = param_3 + 7;
            *(byte *)((int)param_5 + iVar10) = *(byte *)((int)puVar9 + iVar10);
            if (iVar8 != 0x10) {
              iVar10 = param_3 + 8;
              *(byte *)((int)param_5 + iVar8) = *(byte *)((int)puVar9 + iVar8);
              if (iVar10 != 0x10) {
                iVar8 = param_3 + 9;
                *(byte *)((int)param_5 + iVar10) = *(byte *)((int)puVar9 + iVar10);
                if (iVar8 != 0x10) {
                  iVar10 = param_3 + 10;
                  *(byte *)((int)param_5 + iVar8) = *(byte *)((int)puVar9 + iVar8);
                  if (iVar10 != 0x10) {
                    iVar8 = param_3 + 0xb;
                    *(byte *)((int)param_5 + iVar10) = *(byte *)((int)puVar9 + iVar10);
                    if (iVar8 != 0x10) {
                      iVar10 = param_3 + 0xc;
                      *(byte *)((int)param_5 + iVar8) = *(byte *)((int)puVar9 + iVar8);
                      if (iVar10 != 0x10) {
                        uVar7 = param_3 + 0xd;
                        *(byte *)((int)param_5 + iVar10) = *(byte *)((int)puVar9 + iVar10);
                        if (uVar7 != 0x10) {
                          *(byte *)((int)param_5 + uVar7) = *(byte *)((int)puVar9 + uVar7);
                          if (param_3 != 2) {
                            uVar7 = (uint)*(byte *)((int)puVar9 + 0xf);
                          }
                          if (param_3 != 2) {
                            *(byte *)((int)param_5 + 0xf) = (byte)uVar7;
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
  return;
}



undefined4
CRYPTO_xts128_encrypt
          (undefined4 *param_1,uint *param_2,uint *param_3,uint *param_4,uint param_5,int param_6)

{
  undefined1 uVar1;
  uint *puVar2;
  undefined1 uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  bool bVar12;
  uint local_70;
  uint uStack_6c;
  uint local_64;
  uint *local_50;
  uint local_48;
  uint uStack_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  if (param_5 < 0x10) {
    return 0xffffffff;
  }
  local_40 = param_2[2];
  local_48 = *param_2;
  local_3c = param_2[3];
  uStack_44 = param_2[1];
  (*(code *)param_1[3])(&local_48,&local_48,param_1[1]);
  if (((param_6 != 0) || ((param_5 & 0xf) == 0)) ||
     (param_5 = param_5 - 0x10, local_50 = param_3, 0xf < param_5)) {
    puVar4 = param_4 + 4;
    do {
      puVar2 = param_3;
      param_4 = puVar4;
      local_50 = puVar2 + 4;
      HintPreloadData(puVar2 + 0xc);
      local_38 = local_48 ^ *puVar2;
      local_34 = uStack_44 ^ puVar2[1];
      local_30 = puVar2[2] ^ local_40;
      local_2c = puVar2[3] ^ local_3c;
      (*(code *)param_1[2])(&local_38,&local_38,*param_1);
      param_5 = param_5 - 0x10;
      uVar6 = local_38 ^ local_48;
      uVar8 = local_34 ^ uStack_44;
      local_38 = uVar6;
      local_34 = uVar8;
      uVar5 = uStack_44 >> 0x1f;
      local_70 = local_40 ^ local_30;
      uStack_6c = local_3c ^ local_2c;
      local_64 = 0;
      local_30 = local_70;
      local_2c = uStack_6c;
      param_4[-4] = uVar6;
      param_4[-3] = uVar8;
      param_4[-2] = local_70;
      param_4[-1] = uStack_6c;
      if (param_5 == 0) {
        return 0;
      }
      uStack_44 = uStack_44 * 2 + (uint)CARRY4(local_48,local_48);
      uVar10 = (int)local_3c >> 0x1f;
      local_3c = local_3c * 2 + (uint)CARRY4(local_40,local_40);
      local_48 = local_48 * 2 ^ uVar10 & 0x87;
      local_40 = uVar5 | local_40 * 2;
      puVar4 = param_4 + 4;
      param_3 = local_50;
    } while (0xf < param_5);
    if (param_6 != 0) {
      bVar12 = param_4 <= puVar2 + 5;
      bVar11 = puVar2 + 5 == param_4;
      if (bVar12 && !bVar11) {
        bVar12 = local_50 <= param_4 + 1;
        bVar11 = param_4 + 1 == local_50;
      }
      if ((((uint)param_4 | (uint)local_50) & 3) != 0 || (param_5 < 6 || bVar12 && !bVar11)) {
        local_38._0_1_ = (undefined1)uVar6;
        uVar5 = *local_50;
        *(undefined1 *)param_4 = (undefined1)local_38;
        local_38._1_3_ = (undefined3)(uVar6 >> 8);
        local_38 = CONCAT31(local_38._1_3_,(char)uVar5);
        if (param_5 == 1) goto LAB_0014b1f6;
        local_38._1_1_ = (undefined1)(uVar6 >> 8);
        uVar1 = *(undefined1 *)((int)puVar2 + 0x11);
        *(undefined1 *)((int)param_4 + 1) = local_38._1_1_;
        local_38._2_2_ = (undefined2)(uVar6 >> 0x10);
        local_38._0_2_ = CONCAT11(uVar1,(char)uVar5);
        if (param_5 == 2) goto LAB_0014b1f6;
        local_38._2_1_ = (undefined1)(uVar6 >> 0x10);
        uVar1 = *(undefined1 *)((int)puVar2 + 0x12);
        *(undefined1 *)((int)param_4 + 2) = local_38._2_1_;
        local_38._3_1_ = (undefined1)(uVar6 >> 0x18);
        local_38._0_3_ = CONCAT12(uVar1,(undefined2)local_38);
        if (param_5 == 3) goto LAB_0014b1f6;
        uVar1 = *(undefined1 *)((int)puVar2 + 0x13);
        *(undefined1 *)((int)param_4 + 3) = local_38._3_1_;
        local_38 = CONCAT13(uVar1,(undefined3)local_38);
        if (param_5 == 4) goto LAB_0014b1f6;
        local_34._0_1_ = (undefined1)uVar8;
        uVar5 = puVar2[5];
        *(undefined1 *)(param_4 + 1) = (undefined1)local_34;
        local_34._1_3_ = (undefined3)(uVar8 >> 8);
        local_34 = CONCAT31(local_34._1_3_,(char)uVar5);
        if (param_5 < 6) goto LAB_0014b1f6;
        local_34._1_1_ = (undefined1)(uVar8 >> 8);
        uVar1 = *(undefined1 *)((int)puVar2 + 0x15);
        *(undefined1 *)((int)param_4 + 5) = local_34._1_1_;
        local_34._2_2_ = (undefined2)(uVar8 >> 0x10);
        local_34._0_2_ = CONCAT11(uVar1,(char)uVar5);
        if (param_5 < 7) goto LAB_0014b1f6;
        local_34._2_1_ = (undefined1)(uVar8 >> 0x10);
        uVar1 = *(undefined1 *)((int)puVar2 + 0x16);
        *(undefined1 *)((int)param_4 + 6) = local_34._2_1_;
        local_34._3_1_ = (undefined1)(uVar8 >> 0x18);
        local_34._0_3_ = CONCAT12(uVar1,(undefined2)local_34);
        if (param_5 == 7) goto LAB_0014b1f6;
        uVar1 = *(undefined1 *)((int)puVar2 + 0x17);
        *(undefined1 *)((int)param_4 + 7) = local_34._3_1_;
        local_34 = CONCAT13(uVar1,(undefined3)local_34);
        if (param_5 == 8) goto LAB_0014b1f6;
        local_30._0_1_ = (undefined1)local_70;
        uVar5 = puVar2[6];
        *(undefined1 *)(param_4 + 2) = (undefined1)local_30;
        local_30._1_3_ = (undefined3)(local_70 >> 8);
        local_30 = CONCAT31(local_30._1_3_,(char)uVar5);
        if (param_5 != 9) {
          local_30._1_1_ = (undefined1)(local_70 >> 8);
          uVar1 = *(undefined1 *)((int)puVar2 + 0x19);
          *(undefined1 *)((int)param_4 + 9) = local_30._1_1_;
          local_30._2_2_ = (undefined2)(local_70 >> 0x10);
          local_30._0_2_ = CONCAT11(uVar1,(char)uVar5);
          if (param_5 != 10) {
            local_30._2_1_ = (undefined1)(local_70 >> 0x10);
            uVar1 = *(undefined1 *)((int)puVar2 + 0x1a);
            *(undefined1 *)((int)param_4 + 10) = local_30._2_1_;
            local_30._3_1_ = (undefined1)(local_70 >> 0x18);
            local_30._0_3_ = CONCAT12(uVar1,(undefined2)local_30);
            if (param_5 != 0xb) {
              uVar1 = *(undefined1 *)((int)puVar2 + 0x1b);
              *(undefined1 *)((int)param_4 + 0xb) = local_30._3_1_;
              local_30 = CONCAT13(uVar1,(undefined3)local_30);
              if (param_5 != 0xc) {
                local_2c._0_1_ = (undefined1)uStack_6c;
                uVar5 = puVar2[7];
                *(undefined1 *)(param_4 + 3) = (undefined1)local_2c;
                local_2c._1_3_ = (undefined3)(uStack_6c >> 8);
                local_2c = CONCAT31(local_2c._1_3_,(char)uVar5);
                if (param_5 != 0xd) {
                  local_2c._1_1_ = (undefined1)(uStack_6c >> 8);
                  uVar1 = *(undefined1 *)((int)puVar2 + 0x1d);
                  *(undefined1 *)((int)param_4 + 0xd) = local_2c._1_1_;
                  local_2c._2_2_ = (undefined2)(uStack_6c >> 0x10);
                  local_2c._0_2_ = CONCAT11(uVar1,(char)uVar5);
                  if (param_5 == 0xf) {
                    local_2c._2_1_ = (undefined1)(uStack_6c >> 0x10);
                    uVar1 = local_2c._2_1_;
                    local_2c._3_1_ = (undefined1)(uStack_6c >> 0x18);
                    local_2c._0_3_ =
                         CONCAT12(*(undefined1 *)((int)puVar2 + 0x1e),(undefined2)local_2c);
                    *(undefined1 *)((int)param_4 + 0xe) = uVar1;
                    local_70 = local_30;
                    uStack_6c = local_2c;
                    goto LAB_0014b1f6;
                  }
                }
              }
            }
          }
        }
      }
      else {
        uVar5 = param_5;
        if (param_5 == 0) {
          uVar5 = 1;
        }
        iVar7 = (uVar5 - 4 >> 2) + 1;
        if (3 < param_5) {
          local_38 = *local_50;
          *param_4 = uVar6;
          if (iVar7 != 1) {
            local_34 = puVar2[5];
            param_4[1] = uVar8;
            if (iVar7 != 2) {
              local_30 = puVar2[6];
              param_4[2] = local_70;
              if (iVar7 != 3) {
                local_2c = puVar2[7];
                param_4[3] = uStack_6c;
              }
            }
          }
          local_64 = iVar7 * 4;
          if (iVar7 * 4 == uVar5) goto LAB_0014b260;
        }
        uVar5 = local_64 + 1;
        uVar1 = *(undefined1 *)((int)&local_38 + local_64);
        *(undefined1 *)((int)&local_38 + local_64) = *(undefined1 *)((int)local_50 + local_64);
        *(undefined1 *)((int)param_4 + local_64) = uVar1;
        if (uVar5 < param_5) {
          uVar6 = local_64 + 2;
          uVar1 = *(undefined1 *)((int)&local_38 + local_64 + 1);
          *(undefined1 *)((int)&local_38 + local_64 + 1) = *(undefined1 *)((int)local_50 + uVar5);
          *(undefined1 *)((int)param_4 + uVar5) = uVar1;
          if (uVar6 < param_5) {
            uVar1 = *(undefined1 *)((int)&local_38 + local_64 + 2);
            *(undefined1 *)((int)&local_38 + local_64 + 2) = *(undefined1 *)((int)local_50 + uVar6);
            *(undefined1 *)((int)param_4 + uVar6) = uVar1;
            local_70 = local_30;
            uStack_6c = local_2c;
            goto LAB_0014b1f6;
          }
        }
      }
LAB_0014b260:
      local_70 = local_30;
      uStack_6c = local_2c;
LAB_0014b1f6:
      local_30 = local_70 ^ local_40;
      local_2c = uStack_6c ^ local_3c;
      local_38 = local_38 ^ local_48;
      local_34 = local_34 ^ uStack_44;
      (*(code *)param_1[2])(&local_38,&local_38,*param_1);
      param_4[-4] = local_48 ^ local_38;
      param_4[-3] = uStack_44 ^ local_34;
      param_4[-2] = local_40 ^ local_30;
      param_4[-1] = local_3c ^ local_2c;
      return 0;
    }
  }
  uVar5 = local_3c * 2 + (uint)CARRY4(local_40,local_40);
  uVar6 = uStack_44 * 2 + (uint)CARRY4(local_48,local_48);
  uVar9 = local_48 * 2 ^ (int)local_3c >> 0x1f & 0x87U;
  uVar8 = 0;
  uVar10 = local_40 * 2 | uStack_44 >> 0x1f;
  local_38 = *local_50 ^ uVar9;
  local_34 = local_50[1] ^ uVar6;
  local_2c = uVar5 ^ local_50[3];
  local_30 = uVar10 ^ local_50[2];
  (*(code *)param_1[2])(&local_38,&local_38,*param_1);
  uVar9 = uVar9 ^ local_38;
  uVar6 = uVar6 ^ local_34;
  local_38 = uVar9;
  local_34 = uVar6;
  uVar10 = uVar10 ^ local_30;
  uVar5 = uVar5 ^ local_2c;
  local_30 = uVar10;
  local_2c = uVar5;
  if (param_5 != 0) {
    if ((((uint)(param_4 + 4) | (uint)(local_50 + 4)) & 3) == 0 &&
        (5 < param_5 && (param_4 + 5 <= local_50 + 4 || local_50 + 5 <= param_4 + 4))) {
      iVar7 = (param_5 - 4 >> 2) + 1;
      if (2 < param_5 - 1) {
        local_38 = local_50[4];
        param_4[4] = uVar9;
        if (iVar7 != 1) {
          local_34 = local_50[5];
          param_4[5] = uVar6;
          if (iVar7 != 2) {
            local_30 = local_50[6];
            param_4[6] = uVar10;
            if (iVar7 != 3) {
              local_2c = local_50[7];
              param_4[7] = uVar5;
            }
          }
        }
        uVar8 = iVar7 * 4;
        if (param_5 == iVar7 * 4) goto LAB_0014b400;
      }
      uVar1 = *(undefined1 *)((int)local_50 + uVar8 + 0x10);
      *(undefined1 *)((int)param_4 + uVar8 + 0x10) = *(undefined1 *)((int)&local_38 + uVar8);
      *(undefined1 *)((int)&local_38 + uVar8) = uVar1;
      if (uVar8 + 1 < param_5) {
        uVar1 = *(undefined1 *)((int)&local_38 + uVar8 + 1);
        *(undefined1 *)((int)&local_38 + uVar8 + 1) = *(undefined1 *)((int)local_50 + uVar8 + 0x11);
        *(undefined1 *)((int)param_4 + uVar8 + 0x11) = uVar1;
        if (uVar8 + 2 < param_5) {
          uVar1 = *(undefined1 *)((int)&local_38 + uVar8 + 2);
          *(undefined1 *)((int)&local_38 + uVar8 + 2) =
               *(undefined1 *)((int)local_50 + uVar8 + 0x12);
          *(undefined1 *)((int)param_4 + uVar8 + 0x12) = uVar1;
        }
      }
    }
    else {
      local_38._0_1_ = (undefined1)uVar9;
      uVar8 = local_50[4];
      *(undefined1 *)(param_4 + 4) = (undefined1)local_38;
      local_38._1_3_ = (undefined3)(uVar9 >> 8);
      local_38 = CONCAT31(local_38._1_3_,(char)uVar8);
      if (param_5 != 1) {
        local_38._1_1_ = (undefined1)(uVar9 >> 8);
        uVar1 = *(undefined1 *)((int)local_50 + 0x11);
        *(undefined1 *)((int)param_4 + 0x11) = local_38._1_1_;
        local_38._2_2_ = (undefined2)(uVar9 >> 0x10);
        local_38._0_2_ = CONCAT11(uVar1,(char)uVar8);
        if (param_5 != 2) {
          local_38._2_1_ = (undefined1)(uVar9 >> 0x10);
          uVar1 = *(undefined1 *)((int)local_50 + 0x12);
          *(undefined1 *)((int)param_4 + 0x12) = local_38._2_1_;
          local_38._3_1_ = (undefined1)(uVar9 >> 0x18);
          local_38._0_3_ = CONCAT12(uVar1,(undefined2)local_38);
          if (param_5 != 3) {
            uVar1 = *(undefined1 *)((int)local_50 + 0x13);
            *(undefined1 *)((int)param_4 + 0x13) = local_38._3_1_;
            local_38 = CONCAT13(uVar1,(undefined3)local_38);
            if (param_5 != 4) {
              local_34._0_1_ = (undefined1)uVar6;
              uVar8 = local_50[5];
              *(undefined1 *)(param_4 + 5) = (undefined1)local_34;
              local_34._1_3_ = (undefined3)(uVar6 >> 8);
              local_34 = CONCAT31(local_34._1_3_,(char)uVar8);
              if (5 < param_5) {
                local_34._1_1_ = (undefined1)(uVar6 >> 8);
                uVar1 = *(undefined1 *)((int)local_50 + 0x15);
                *(undefined1 *)((int)param_4 + 0x15) = local_34._1_1_;
                local_34._2_2_ = (undefined2)(uVar6 >> 0x10);
                local_34._0_2_ = CONCAT11(uVar1,(char)uVar8);
                if (6 < param_5) {
                  local_34._2_1_ = (undefined1)(uVar6 >> 0x10);
                  uVar1 = *(undefined1 *)((int)local_50 + 0x16);
                  *(undefined1 *)((int)param_4 + 0x16) = local_34._2_1_;
                  local_34._3_1_ = (undefined1)(uVar6 >> 0x18);
                  local_34._0_3_ = CONCAT12(uVar1,(undefined2)local_34);
                  if (param_5 != 7) {
                    uVar1 = *(undefined1 *)((int)local_50 + 0x17);
                    *(undefined1 *)((int)param_4 + 0x17) = local_34._3_1_;
                    local_34 = CONCAT13(uVar1,(undefined3)local_34);
                    if (param_5 != 8) {
                      local_30._0_1_ = (undefined1)uVar10;
                      uVar6 = local_50[6];
                      *(undefined1 *)(param_4 + 6) = (undefined1)local_30;
                      local_30._1_3_ = (undefined3)(uVar10 >> 8);
                      local_30 = CONCAT31(local_30._1_3_,(char)uVar6);
                      if (param_5 != 9) {
                        local_30._1_1_ = (undefined1)(uVar10 >> 8);
                        uVar1 = *(undefined1 *)((int)local_50 + 0x19);
                        *(undefined1 *)((int)param_4 + 0x19) = local_30._1_1_;
                        local_30._2_2_ = (undefined2)(uVar10 >> 0x10);
                        local_30._0_2_ = CONCAT11(uVar1,(char)uVar6);
                        if (param_5 != 10) {
                          local_30._2_1_ = (undefined1)(uVar10 >> 0x10);
                          uVar1 = local_30._2_1_;
                          local_30._3_1_ = (undefined1)(uVar10 >> 0x18);
                          uVar3 = local_30._3_1_;
                          local_30._0_3_ =
                               CONCAT12(*(undefined1 *)((int)local_50 + 0x1a),(undefined2)local_30);
                          *(undefined1 *)((int)param_4 + 0x1a) = uVar1;
                          if (param_5 != 0xb) {
                            local_30 = CONCAT13(*(undefined1 *)((int)local_50 + 0x1b),
                                                (undefined3)local_30);
                            *(undefined1 *)((int)param_4 + 0x1b) = uVar3;
                            if (param_5 != 0xc) {
                              uVar6 = local_50[7];
                              local_2c._0_1_ = (undefined1)uVar5;
                              uVar1 = (undefined1)local_2c;
                              local_2c._1_3_ = (undefined3)(uVar5 >> 8);
                              local_2c = CONCAT31(local_2c._1_3_,(char)uVar6);
                              *(undefined1 *)(param_4 + 7) = uVar1;
                              if (param_5 != 0xd) {
                                local_2c._1_1_ = (undefined1)(uVar5 >> 8);
                                uVar1 = local_2c._1_1_;
                                local_2c._2_2_ = (undefined2)(uVar5 >> 0x10);
                                local_2c._0_2_ =
                                     CONCAT11(*(undefined1 *)((int)local_50 + 0x1d),(char)uVar6);
                                *(undefined1 *)((int)param_4 + 0x1d) = uVar1;
                                if (param_5 == 0xf) {
                                  local_2c._2_1_ = (undefined1)(uVar5 >> 0x10);
                                  uVar1 = local_2c._2_1_;
                                  local_2c._3_1_ = (undefined1)(uVar5 >> 0x18);
                                  local_2c._0_3_ =
                                       CONCAT12(*(undefined1 *)((int)local_50 + 0x1e),
                                                (undefined2)local_2c);
                                  *(undefined1 *)((int)param_4 + 0x1e) = uVar1;
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
LAB_0014b400:
  local_38 = local_48 ^ local_38;
  local_34 = uStack_44 ^ local_34;
  local_30 = local_30 ^ local_40;
  local_2c = local_2c ^ local_3c;
  (*(code *)param_1[2])(&local_38,&local_38,*param_1);
  *param_4 = local_48 ^ local_38;
  param_4[1] = uStack_44 ^ local_34;
  param_4[2] = local_30 ^ local_40;
  param_4[3] = local_2c ^ local_3c;
  return 0;
}


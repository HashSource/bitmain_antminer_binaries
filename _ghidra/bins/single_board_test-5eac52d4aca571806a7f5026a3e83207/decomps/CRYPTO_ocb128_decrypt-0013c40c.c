
undefined4 CRYPTO_ocb128_decrypt(undefined4 *param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  uint local_60;
  uint uStack_5c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar7 = param_4 >> 4;
  uVar9 = param_1[0x14];
  uVar3 = uVar9 + uVar7;
  uVar4 = param_1[0x15] + (uint)CARRY4(uVar9,uVar7);
  if (((uVar7 == 0) || (uVar4 != 0)) || (param_1[4] == 0)) {
    local_60 = uVar9 + 1;
    uStack_5c = param_1[0x15] + (uint)(0xfffffffe < uVar9);
    bVar14 = uStack_5c <= uVar4;
    if (uVar4 == uStack_5c) {
      bVar14 = local_60 <= uVar3;
    }
    if (bVar14) {
      puVar2 = param_3 + 4;
      puVar1 = param_2 + 4;
      do {
        param_2 = puVar1;
        param_3 = puVar2;
        if ((local_60 & 1) == 0) {
          iVar8 = 0;
          uVar7 = local_60;
          uVar9 = uStack_5c;
          do {
            uVar5 = uVar9 & 1;
            uVar9 = uVar9 >> 1;
            uVar6 = uVar7 >> 1;
            uVar7 = (uint)(uVar5 != 0) << 0x1f | uVar6;
            iVar8 = iVar8 + 1;
          } while ((uVar6 & 1) == 0);
        }
        else {
          iVar8 = 0;
        }
        puVar2 = (uint *)ocb_lookup_l(param_1,iVar8);
        if (puVar2 == (uint *)0x0) {
          return 0;
        }
        uVar7 = *puVar2;
        uVar5 = puVar2[1];
        uVar10 = param_1[0x1e];
        uVar12 = param_1[0x1f];
        bVar14 = 0xfffffffe < local_60;
        local_60 = local_60 + 1;
        HintPreloadData(param_2 + 4);
        uStack_5c = uStack_5c + bVar14;
        uVar11 = param_1[0x20];
        uVar13 = param_1[0x21];
        param_1[0x1e] = uVar10 ^ uVar7;
        param_1[0x1f] = uVar12 ^ uVar5;
        uVar9 = puVar2[2];
        uVar6 = puVar2[3];
        param_1[0x20] = uVar11 ^ uVar9;
        param_1[0x21] = uVar13 ^ uVar6;
        local_34 = uVar12 ^ uVar5 ^ param_2[-3];
        local_38 = uVar10 ^ uVar7 ^ param_2[-4];
        local_2c = param_2[-1] ^ uVar13 ^ uVar6;
        local_30 = param_2[-2] ^ uVar11 ^ uVar9;
        (*(code *)param_1[1])(&local_38,&local_38,param_1[3]);
        local_38 = local_38 ^ param_1[0x1e];
        local_34 = local_34 ^ param_1[0x1f];
        local_30 = local_30 ^ param_1[0x20];
        local_2c = local_2c ^ param_1[0x21];
        HintPreloadData(param_3 + 4);
        param_1[0x22] = local_38 ^ param_1[0x22];
        param_1[0x23] = local_34 ^ param_1[0x23];
        param_1[0x24] = local_30 ^ param_1[0x24];
        param_1[0x25] = local_2c ^ param_1[0x25];
        param_3[-2] = local_30;
        param_3[-1] = local_2c;
        param_3[-4] = local_38;
        param_3[-3] = local_34;
        bVar14 = uStack_5c <= uVar4;
        if (uVar4 == uStack_5c) {
          bVar14 = local_60 <= uVar3;
        }
        puVar2 = param_3 + 4;
        puVar1 = param_2 + 4;
      } while (bVar14);
    }
  }
  else {
    uVar9 = uVar3 >> 1;
    if (uVar9 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = 0;
      do {
        uVar9 = uVar9 >> 1;
        iVar8 = iVar8 + 1;
      } while (uVar9 != 0);
    }
    iVar8 = ocb_lookup_l(param_1,iVar8);
    if (iVar8 == 0) {
      return 0;
    }
    (*(code *)param_1[4])
              (param_2,param_3,uVar7,param_1[3],param_1[0x14] + 1,param_1 + 0x1e,param_1[0x10],
               param_1 + 0x22);
  }
  if ((param_4 & 0xf) == 0) goto LAB_0013c5ba;
  param_4 = param_4 & 0xf;
  param_1[0x1e] = param_1[0x1e] ^ param_1[8];
  param_1[0x1f] = param_1[0x1f] ^ param_1[9];
  param_1[0x20] = param_1[0x20] ^ param_1[10];
  param_1[0x21] = param_1[0x21] ^ param_1[0xb];
  (*(code *)*param_1)(param_1 + 0x1e,&local_38,param_1[2]);
  if ((((uint)param_3 | (uint)param_2) & 3) == 0 &&
      (5 < param_4 && (param_2 + 1 <= param_3 || param_3 + 1 <= param_2))) {
    iVar8 = (param_4 - 4 >> 2) + 1;
    uVar7 = iVar8 * 4;
    if (param_4 - 1 < 3) {
      uVar7 = 0;
    }
    else {
      *param_3 = *param_2 ^ local_38;
      if (((iVar8 != 1) && (param_3[1] = local_34 ^ param_2[1], iVar8 != 2)) &&
         (param_3[2] = local_30 ^ param_2[2], iVar8 != 3)) {
        param_3[3] = local_2c ^ param_2[3];
      }
      if (param_4 == uVar7) goto LAB_0013c6da;
    }
    uVar9 = uVar7 + 1;
    *(byte *)((int)param_3 + uVar7) =
         *(byte *)((int)&local_38 + uVar7) ^ *(byte *)((int)param_2 + uVar7);
    if (uVar9 < param_4) {
      uVar5 = uVar7 + 2;
      *(byte *)((int)param_3 + uVar9) =
           *(byte *)((int)&local_38 + uVar7 + 1) ^ *(byte *)((int)param_2 + uVar9);
      if (uVar5 < param_4) {
        *(byte *)((int)param_3 + uVar5) =
             *(byte *)((int)&local_38 + uVar7 + 2) ^ *(byte *)((int)param_2 + uVar5);
      }
    }
  }
  else {
    *(byte *)param_3 = (byte)local_38 ^ (byte)*param_2;
    if (param_4 != 1) {
      *(byte *)((int)param_3 + 1) = local_38._1_1_ ^ *(byte *)((int)param_2 + 1);
      if (param_4 != 2) {
        *(byte *)((int)param_3 + 2) = local_38._2_1_ ^ *(byte *)((int)param_2 + 2);
        if (param_4 != 3) {
          *(byte *)((int)param_3 + 3) = local_38._3_1_ ^ *(byte *)((int)param_2 + 3);
          if (param_4 != 4) {
            *(byte *)(param_3 + 1) = (byte)local_34 ^ (byte)param_2[1];
            if (5 < param_4) {
              *(byte *)((int)param_3 + 5) = local_34._1_1_ ^ *(byte *)((int)param_2 + 5);
              if (6 < param_4) {
                *(byte *)((int)param_3 + 6) = local_34._2_1_ ^ *(byte *)((int)param_2 + 6);
                if (param_4 != 7) {
                  *(byte *)((int)param_3 + 7) = local_34._3_1_ ^ *(byte *)((int)param_2 + 7);
                  if (param_4 != 8) {
                    *(byte *)(param_3 + 2) = (byte)local_30 ^ (byte)param_2[2];
                    if (param_4 != 9) {
                      *(byte *)((int)param_3 + 9) = local_30._1_1_ ^ *(byte *)((int)param_2 + 9);
                      if (param_4 != 10) {
                        *(byte *)((int)param_3 + 10) = local_30._2_1_ ^ *(byte *)((int)param_2 + 10)
                        ;
                        if (param_4 != 0xb) {
                          *(byte *)((int)param_3 + 0xb) =
                               local_30._3_1_ ^ *(byte *)((int)param_2 + 0xb);
                          if (param_4 != 0xc) {
                            *(byte *)(param_3 + 3) = (byte)local_2c ^ (byte)param_2[3];
                            if (param_4 != 0xd) {
                              *(byte *)((int)param_3 + 0xd) =
                                   local_2c._1_1_ ^ *(byte *)((int)param_2 + 0xd);
                              if (param_4 == 0xf) {
                                *(byte *)((int)param_3 + 0xe) =
                                     local_2c._2_1_ ^ *(byte *)((int)param_2 + 0xe);
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
LAB_0013c6da:
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_38,param_3,param_4);
  *(undefined1 *)((int)&local_38 + param_4) = 0x80;
  param_1[0x22] = param_1[0x22] ^ local_38;
  param_1[0x23] = param_1[0x23] ^ local_34;
  param_1[0x24] = param_1[0x24] ^ local_30;
  param_1[0x25] = param_1[0x25] ^ local_2c;
LAB_0013c5ba:
  param_1[0x14] = uVar3;
  param_1[0x15] = uVar4;
  return 1;
}


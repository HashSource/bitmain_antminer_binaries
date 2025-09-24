
undefined4 CRYPTO_ocb128_encrypt(undefined4 *param_1,uint *param_2,uint *param_3,uint param_4)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  uint local_58;
  uint uStack_54;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar10 = param_4 >> 4;
  uVar16 = param_1[0x14];
  uVar3 = uVar16 + uVar10;
  uVar6 = param_1[0x15] + (uint)CARRY4(uVar16,uVar10);
  if (((uVar10 == 0) || (uVar6 != 0)) || (param_1[4] == 0)) {
    local_58 = uVar16 + 1;
    uStack_54 = param_1[0x15] + (uint)(0xfffffffe < uVar16);
    bVar17 = uStack_54 <= uVar6;
    if (uVar6 == uStack_54) {
      bVar17 = local_58 <= uVar3;
    }
    if (bVar17) {
      puVar2 = param_3 + 4;
      puVar1 = param_2 + 4;
      do {
        param_2 = puVar1;
        param_3 = puVar2;
        if ((local_58 & 1) == 0) {
          iVar11 = 0;
          uVar10 = local_58;
          uVar16 = uStack_54;
          do {
            uVar4 = uVar16 & 1;
            uVar16 = uVar16 >> 1;
            uVar5 = uVar10 >> 1;
            uVar10 = (uint)(uVar4 != 0) << 0x1f | uVar5;
            iVar11 = iVar11 + 1;
          } while ((uVar5 & 1) == 0);
        }
        else {
          iVar11 = 0;
        }
        puVar2 = (uint *)ocb_lookup_l(param_1,iVar11);
        if (puVar2 == (uint *)0x0) {
          return 0;
        }
        uVar16 = *puVar2;
        uVar7 = puVar2[1];
        uVar12 = param_1[0x1e];
        uVar14 = param_1[0x1f];
        bVar17 = 0xfffffffe < local_58;
        local_58 = local_58 + 1;
        HintPreloadData(param_2 + 4);
        uStack_54 = uStack_54 + bVar17;
        uVar13 = param_1[0x20];
        uVar15 = param_1[0x21];
        param_1[0x1e] = uVar12 ^ uVar16;
        param_1[0x1f] = uVar14 ^ uVar7;
        uVar4 = puVar2[2];
        uVar8 = puVar2[3];
        param_1[0x20] = uVar13 ^ uVar4;
        param_1[0x21] = uVar15 ^ uVar8;
        uVar10 = param_2[-3];
        uVar5 = param_2[-2];
        uVar9 = param_2[-1];
        local_38 = uVar12 ^ uVar16 ^ param_2[-4];
        local_34 = uVar14 ^ uVar7 ^ uVar10;
        param_1[0x22] = param_1[0x22] ^ param_2[-4];
        param_1[0x23] = param_1[0x23] ^ uVar10;
        local_30 = uVar5 ^ uVar13 ^ uVar4;
        local_2c = uVar9 ^ uVar15 ^ uVar8;
        param_1[0x24] = param_1[0x24] ^ uVar5;
        param_1[0x25] = param_1[0x25] ^ uVar9;
        (*(code *)*param_1)(&local_38,&local_38,param_1[2]);
        local_38 = local_38 ^ param_1[0x1e];
        local_34 = local_34 ^ param_1[0x1f];
        HintPreloadData(param_3 + 4);
        local_30 = local_30 ^ param_1[0x20];
        local_2c = local_2c ^ param_1[0x21];
        param_3[-3] = local_34;
        param_3[-2] = local_30;
        param_3[-1] = local_2c;
        param_3[-4] = local_38;
        bVar17 = uStack_54 <= uVar6;
        if (uVar6 == uStack_54) {
          bVar17 = local_58 <= uVar3;
        }
        puVar2 = param_3 + 4;
        puVar1 = param_2 + 4;
      } while (bVar17);
    }
  }
  else {
    uVar16 = uVar3 >> 1;
    if (uVar16 == 0) {
      iVar11 = 0;
    }
    else {
      iVar11 = 0;
      do {
        uVar16 = uVar16 >> 1;
        iVar11 = iVar11 + 1;
      } while (uVar16 != 0);
    }
    iVar11 = ocb_lookup_l(param_1,iVar11);
    if (iVar11 == 0) {
      return 0;
    }
    (*(code *)param_1[4])
              (param_2,param_3,uVar10,param_1[2],param_1[0x14] + 1,param_1 + 0x1e,param_1[0x10],
               param_1 + 0x22);
  }
  if ((param_4 & 0xf) == 0) goto LAB_0014036e;
  param_4 = param_4 & 0xf;
  param_1[0x1e] = param_1[0x1e] ^ param_1[8];
  param_1[0x1f] = param_1[0x1f] ^ param_1[9];
  param_1[0x20] = param_1[0x20] ^ param_1[10];
  param_1[0x21] = param_1[0x21] ^ param_1[0xb];
  (*(code *)*param_1)(param_1 + 0x1e,&local_38,param_1[2]);
  if ((((uint)param_3 | (uint)param_2) & 3) == 0 &&
      (5 < param_4 && (param_2 + 1 <= param_3 || param_3 + 1 <= param_2))) {
    iVar11 = (param_4 - 4 >> 2) + 1;
    uVar10 = iVar11 * 4;
    if (param_4 - 1 < 3) {
      uVar10 = 0;
    }
    else {
      *param_3 = *param_2 ^ local_38;
      if (((iVar11 != 1) && (param_3[1] = local_34 ^ param_2[1], iVar11 != 2)) &&
         (param_3[2] = local_30 ^ param_2[2], iVar11 != 3)) {
        param_3[3] = local_2c ^ param_2[3];
      }
      if (param_4 == uVar10) goto LAB_0014048e;
    }
    uVar16 = uVar10 + 1;
    *(byte *)((int)param_3 + uVar10) =
         *(byte *)((int)&local_38 + uVar10) ^ *(byte *)((int)param_2 + uVar10);
    if (uVar16 < param_4) {
      uVar4 = uVar10 + 2;
      *(byte *)((int)param_3 + uVar16) =
           *(byte *)((int)&local_38 + uVar10 + 1) ^ *(byte *)((int)param_2 + uVar16);
      if (uVar4 < param_4) {
        *(byte *)((int)param_3 + uVar4) =
             *(byte *)((int)&local_38 + uVar10 + 2) ^ *(byte *)((int)param_2 + uVar4);
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
LAB_0014048e:
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  memcpy(&local_38,param_2,param_4);
  *(undefined1 *)((int)&local_38 + param_4) = 0x80;
  param_1[0x22] = param_1[0x22] ^ local_38;
  param_1[0x23] = param_1[0x23] ^ local_34;
  param_1[0x24] = param_1[0x24] ^ local_30;
  param_1[0x25] = param_1[0x25] ^ local_2c;
LAB_0014036e:
  param_1[0x14] = uVar3;
  param_1[0x15] = uVar6;
  return 1;
}


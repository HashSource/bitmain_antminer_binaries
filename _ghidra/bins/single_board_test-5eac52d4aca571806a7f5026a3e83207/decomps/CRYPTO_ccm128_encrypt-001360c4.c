
undefined4 CRYPTO_ccm128_encrypt(byte *param_1,uint *param_2,uint *param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint3 uVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  bool bVar17;
  uint local_60;
  undefined4 *local_58;
  uint *local_4c;
  uint local_48;
  uint *local_44;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  bVar1 = *param_1;
  pcVar7 = *(code **)(param_1 + 0x28);
  uVar16 = *(undefined4 *)(param_1 + 0x2c);
  if (-1 < (int)((uint)bVar1 << 0x19)) {
    (*pcVar7)(param_1,param_1 + 0x10,uVar16);
    uVar6 = *(uint *)(param_1 + 0x20);
    *(uint *)(param_1 + 0x20) = uVar6 + 1;
    *(uint *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + (uint)(0xfffffffe < uVar6);
  }
  uVar6 = bVar1 & 7;
  iVar8 = 0xf - uVar6;
  *param_1 = (byte)uVar6;
  if ((bVar1 & 7) == 0) {
    local_48 = 0;
  }
  else {
    bVar2 = param_1[iVar8];
    iVar11 = 0x10 - uVar6;
    param_1[iVar8] = 0;
    local_48 = (uint)bVar2 << 8;
    if (iVar11 != 0xf) {
      bVar3 = param_1[iVar11];
      iVar12 = 0x11 - uVar6;
      param_1[iVar11] = 0;
      uVar4 = CONCAT11(bVar2,bVar3);
      local_48 = (uint)uVar4 << 8;
      if (iVar12 != 0xf) {
        bVar2 = param_1[iVar12];
        iVar11 = 0x12 - uVar6;
        param_1[iVar12] = 0;
        uVar5 = CONCAT21(uVar4,bVar2);
        local_48 = (uint)uVar5 << 8;
        if (iVar11 != 0xf) {
          bVar2 = param_1[iVar11];
          iVar12 = 0x13 - uVar6;
          param_1[iVar11] = 0;
          local_48 = CONCAT31(uVar5,bVar2) << 8;
          if (iVar12 != 0xf) {
            bVar2 = param_1[iVar12];
            iVar11 = 0x14 - uVar6;
            param_1[iVar12] = 0;
            local_48 = (local_48 | bVar2) << 8;
            if (iVar11 != 0xf) {
              bVar2 = param_1[iVar11];
              param_1[iVar11] = 0;
              local_48 = (local_48 | bVar2) << 8;
              if (uVar6 != 6) {
                bVar2 = param_1[0xe];
                param_1[0xe] = 0;
                local_48 = (local_48 | bVar2) << 8;
              }
            }
          }
        }
      }
    }
  }
  bVar2 = param_1[0xf];
  param_1[0xf] = 1;
  local_48 = local_48 | bVar2;
  if (local_48 != param_4) {
    return 0xffffffff;
  }
  uVar6 = param_4 + 0xf >> 3 | 1;
  iVar11 = *(uint *)(param_1 + 0x20) + uVar6;
  uVar6 = *(int *)(param_1 + 0x24) + (uint)CARRY4(*(uint *)(param_1 + 0x20),uVar6);
  bVar17 = 0x1fffffff < uVar6;
  *(int *)(param_1 + 0x20) = iVar11;
  *(uint *)(param_1 + 0x24) = uVar6;
  if (uVar6 == 0x20000000) {
    bVar17 = iVar11 != 0;
  }
  if (bVar17) {
    return 0xfffffffe;
  }
  local_4c = param_2;
  local_44 = param_3;
  if (0xf < param_4) {
    puVar10 = param_3;
    puVar13 = param_2;
    local_60 = param_4;
    do {
      uVar6 = puVar13[2];
      uVar14 = *puVar13;
      uVar15 = puVar13[1];
      local_60 = local_60 - 0x10;
      uVar9 = puVar13[3];
      HintPreloadData(puVar13 + 8);
      HintPreloadData(puVar13 + 10);
      puVar13 = puVar13 + 4;
      *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ uVar14;
      *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ uVar15;
      *(uint *)(param_1 + 0x18) = uVar6 ^ *(uint *)(param_1 + 0x18);
      *(uint *)(param_1 + 0x1c) = uVar9 ^ *(uint *)(param_1 + 0x1c);
      (*pcVar7)(param_1 + 0x10,param_1 + 0x10,uVar16);
      (*pcVar7)(param_1,&local_38,uVar16);
      bVar3 = param_1[0xf];
      param_1[0xf] = bVar3 + 1;
      if (((((byte)(bVar3 + 1) == 0) &&
           (bVar3 = param_1[0xe], param_1[0xe] = bVar3 + 1, (byte)(bVar3 + 1) == 0)) &&
          (bVar3 = param_1[0xd], param_1[0xd] = bVar3 + 1, (byte)(bVar3 + 1) == 0)) &&
         (((bVar3 = param_1[0xc], param_1[0xc] = bVar3 + 1, (byte)(bVar3 + 1) == 0 &&
           (bVar3 = param_1[0xb], param_1[0xb] = bVar3 + 1, (byte)(bVar3 + 1) == 0)) &&
          ((bVar3 = param_1[10], param_1[10] = bVar3 + 1, (byte)(bVar3 + 1) == 0 &&
           (bVar3 = param_1[9], param_1[9] = bVar3 + 1, (byte)(bVar3 + 1) == 0)))))) {
        param_1[8] = param_1[8] + 1;
      }
      puVar10[2] = uVar6 ^ local_30;
      puVar10[3] = uVar9 ^ local_2c;
      *puVar10 = local_38 ^ uVar14;
      puVar10[1] = local_34 ^ uVar15;
      puVar10 = puVar10 + 4;
    } while (0xf < local_60);
    uVar6 = local_48 - 0x10;
    local_48 = bVar2 & 0xf;
    iVar11 = (uVar6 & 0xfffffff0) + 0x10;
    local_4c = (uint *)((int)param_2 + iVar11);
    local_44 = (uint *)((int)param_3 + iVar11);
  }
  local_58 = &local_38;
  if (local_48 == 0) goto LAB_001364b4;
  puVar10 = (uint *)(param_1 + 0x10);
  if (((uint)local_4c & 3) != 0 ||
      (local_4c < param_1 + 0x14 && puVar10 < local_4c + 1 || local_48 < 6)) {
    param_1[0x10] = (byte)*local_4c ^ param_1[0x10];
    if (((local_48 != 1) &&
        (param_1[0x11] = *(byte *)((int)local_4c + 1) ^ param_1[0x11], local_48 != 2)) &&
       ((((param_1[0x12] = *(byte *)((int)local_4c + 2) ^ param_1[0x12], local_48 != 3 &&
          ((((param_1[0x13] = *(byte *)((int)local_4c + 3) ^ param_1[0x13], local_48 != 4 &&
             (param_1[0x14] = (byte)local_4c[1] ^ param_1[0x14], 5 < local_48)) &&
            (param_1[0x15] = *(byte *)((int)local_4c + 5) ^ param_1[0x15], 6 < local_48)) &&
           ((param_1[0x16] = *(byte *)((int)local_4c + 6) ^ param_1[0x16], local_48 != 7 &&
            (param_1[0x17] = *(byte *)((int)local_4c + 7) ^ param_1[0x17], local_48 != 8)))))) &&
         (param_1[0x18] = (byte)local_4c[2] ^ param_1[0x18], local_48 != 9)) &&
        (((param_1[0x19] = *(byte *)((int)local_4c + 9) ^ param_1[0x19], local_48 != 10 &&
          (param_1[0x1a] = *(byte *)((int)local_4c + 10) ^ param_1[0x1a], local_48 != 0xb)) &&
         ((param_1[0x1b] = *(byte *)((int)local_4c + 0xb) ^ param_1[0x1b], local_48 != 0xc &&
          (param_1[0x1c] = (byte)local_4c[3] ^ param_1[0x1c], local_48 != 0xd)))))))) {
      bVar2 = param_1[0x1d];
      bVar3 = *(byte *)((int)local_4c + 0xd) ^ bVar2;
      if (local_48 == 0xf) {
        bVar2 = param_1[0x1e];
      }
      param_1[0x1d] = bVar3;
      if (local_48 == 0xf) {
        param_1[0x1e] = *(byte *)((int)local_4c + 0xe) ^ bVar2;
      }
    }
  }
  else {
    iVar11 = (local_48 - 4 >> 2) + 1;
    uVar6 = iVar11 * 4;
    if (local_48 - 1 < 3) {
      uVar6 = 0;
    }
    else {
      *(uint *)(param_1 + 0x10) = *local_4c ^ *(uint *)(param_1 + 0x10);
      if (((iVar11 != 1) &&
          (*(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ local_4c[1], iVar11 != 2)) &&
         (*(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_4c[2], iVar11 != 3)) {
        *(uint *)(param_1 + 0x1c) = local_4c[3] ^ *(uint *)(param_1 + 0x1c);
      }
      if (local_48 == uVar6) goto LAB_001363e4;
    }
    param_1[uVar6 + 0x10] = param_1[uVar6 + 0x10] ^ *(byte *)((int)local_4c + uVar6);
    if (uVar6 + 1 < local_48) {
      param_1[uVar6 + 0x11] = param_1[uVar6 + 0x11] ^ *(byte *)((int)local_4c + uVar6 + 1);
      if (uVar6 + 2 < local_48) {
        param_1[uVar6 + 0x12] = param_1[uVar6 + 0x12] ^ *(byte *)((int)local_4c + uVar6 + 2);
      }
    }
  }
LAB_001363e4:
  (*pcVar7)(puVar10,puVar10,uVar16);
  (*pcVar7)(param_1,local_58,uVar16);
  if ((((uint)local_44 | (uint)local_4c) & 3) != 0 ||
      (local_44 < local_4c + 1 && local_4c < local_44 + 1 || local_48 < 6)) {
    *(byte *)local_44 = (byte)*local_4c ^ (byte)local_38;
    if (local_48 != 1) {
      *(byte *)((int)local_44 + 1) = *(byte *)((int)local_4c + 1) ^ local_38._1_1_;
      if (local_48 != 2) {
        *(byte *)((int)local_44 + 2) = *(byte *)((int)local_4c + 2) ^ local_38._2_1_;
        if (local_48 != 3) {
          *(byte *)((int)local_44 + 3) = *(byte *)((int)local_4c + 3) ^ local_38._3_1_;
          if (local_48 != 4) {
            *(byte *)(local_44 + 1) = (byte)local_4c[1] ^ (byte)local_34;
            if (5 < local_48) {
              *(byte *)((int)local_44 + 5) = *(byte *)((int)local_4c + 5) ^ local_34._1_1_;
              if (6 < local_48) {
                *(byte *)((int)local_44 + 6) = *(byte *)((int)local_4c + 6) ^ local_34._2_1_;
                if (local_48 != 7) {
                  *(byte *)((int)local_44 + 7) = *(byte *)((int)local_4c + 7) ^ local_34._3_1_;
                  if (local_48 != 8) {
                    *(byte *)(local_44 + 2) = (byte)local_4c[2] ^ (byte)local_30;
                    if (local_48 != 9) {
                      *(byte *)((int)local_44 + 9) = *(byte *)((int)local_4c + 9) ^ local_30._1_1_;
                      if (local_48 != 10) {
                        *(byte *)((int)local_44 + 10) =
                             *(byte *)((int)local_4c + 10) ^ local_30._2_1_;
                        if (local_48 != 0xb) {
                          *(byte *)((int)local_44 + 0xb) =
                               *(byte *)((int)local_4c + 0xb) ^ local_30._3_1_;
                          if (local_48 != 0xc) {
                            *(byte *)(local_44 + 3) = (byte)local_4c[3] ^ (byte)local_2c;
                            if (local_48 != 0xd) {
                              *(byte *)((int)local_44 + 0xd) =
                                   *(byte *)((int)local_4c + 0xd) ^ local_2c._1_1_;
                              if (local_48 == 0xf) {
                                *(byte *)((int)local_44 + 0xe) =
                                     *(byte *)((int)local_4c + 0xe) ^ local_2c._2_1_;
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
    iVar11 = (local_48 - 4 >> 2) + 1;
    uVar6 = iVar11 * 4;
    if (local_48 - 1 < 3) {
      uVar6 = 0;
    }
    else {
      *local_44 = *local_4c ^ local_38;
      if (((iVar11 != 1) && (local_44[1] = local_4c[1] ^ local_34, iVar11 != 2)) &&
         (local_44[2] = local_4c[2] ^ local_30, iVar11 != 3)) {
        local_44[3] = local_4c[3] ^ local_2c;
      }
      if (local_48 == uVar6) goto LAB_001364b4;
    }
    uVar9 = uVar6 + 1;
    *(byte *)((int)local_44 + uVar6) =
         *(byte *)((int)&local_38 + uVar6) ^ *(byte *)((int)local_4c + uVar6);
    if (uVar9 < local_48) {
      uVar14 = uVar6 + 2;
      *(byte *)((int)local_44 + uVar9) =
           *(byte *)((int)&local_38 + uVar6 + 1) ^ *(byte *)((int)local_4c + uVar9);
      if (uVar14 < local_48) {
        *(byte *)((int)local_44 + uVar14) =
             *(byte *)((int)&local_38 + uVar6 + 2) ^ *(byte *)((int)local_4c + uVar14);
      }
    }
  }
LAB_001364b4:
  memset(param_1 + iVar8,0,0x10 - iVar8);
  (*pcVar7)(param_1,local_58,uVar16);
  *(uint *)(param_1 + 0x10) = local_38 ^ *(uint *)(param_1 + 0x10);
  *(uint *)(param_1 + 0x14) = local_34 ^ *(uint *)(param_1 + 0x14);
  *param_1 = bVar1;
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) ^ local_30;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) ^ local_2c;
  return 0;
}


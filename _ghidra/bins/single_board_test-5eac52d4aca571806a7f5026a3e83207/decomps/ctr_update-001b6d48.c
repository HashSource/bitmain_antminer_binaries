
/* WARNING: Type propagation algorithm not settling */

undefined4
ctr_update(int param_1,uint *param_2,uint param_3,uint *param_4,uint param_5,int param_6,int param_7
          )

{
  undefined4 *puVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint *puVar15;
  uint *puVar16;
  uint uVar17;
  uint *puVar18;
  byte *pbVar19;
  uint *key;
  uchar *out;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  bool bVar23;
  bool bVar24;
  undefined1 local_e0;
  undefined1 local_dc;
  int local_c4;
  int local_c0;
  uint local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  uchar auStack_88 [4];
  undefined4 auStack_84 [11];
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  uVar20 = *(byte *)(param_1 + 0xab) + 1;
  uVar9 = (uint)*(byte *)(param_1 + 0xaa) + (uVar20 >> 8);
  uVar6 = (uint)*(byte *)(param_1 + 0xa9) + (uVar9 >> 8);
  uVar22 = (uint)*(byte *)(param_1 + 0xa8) + (uVar6 >> 8);
  uVar21 = (uint)*(byte *)(param_1 + 0xa7) + (uVar22 >> 8);
  puVar1 = (undefined4 *)(param_1 + 0x9c);
  local_b8 = *puVar1;
  uVar14 = (uint)*(byte *)(param_1 + 0xa6) + (uVar21 >> 8);
  uVar17 = (uint)*(byte *)(param_1 + 0xa5) + (uVar14 >> 8);
  uStack_b4 = *(undefined4 *)(param_1 + 0xa0);
  uStack_ac = *(undefined4 *)(param_1 + 0xa8);
  uVar13 = (uint)*(byte *)(param_1 + 0xa4) + (uVar17 >> 8);
  uStack_b0 = *(undefined4 *)(param_1 + 0xa4);
  *(char *)(param_1 + 0xa5) = (char)uVar17;
  uVar17 = (uint)*(byte *)(param_1 + 0xa3) + (uVar13 >> 8);
  *(char *)(param_1 + 0xa8) = (char)uVar22;
  local_dc = (undefined1)uVar6;
  *(char *)(param_1 + 0xa6) = (char)uVar14;
  uVar6 = (uint)*(byte *)(param_1 + 0xa2) + (uVar17 >> 8);
  *(char *)(param_1 + 0xa4) = (char)uVar13;
  *(undefined1 *)(param_1 + 0xa9) = local_dc;
  local_e0 = (undefined1)uVar9;
  *(char *)(param_1 + 0xa2) = (char)uVar6;
  *(char *)(param_1 + 0xa3) = (char)uVar17;
  *(char *)(param_1 + 0xa7) = (char)uVar21;
  *(undefined1 *)(param_1 + 0xaa) = local_e0;
  local_c4 = 0x10;
  puVar18 = (uint *)((uint)*(byte *)(param_1 + 0xa1) + (uVar6 >> 8));
  uVar13 = (uint)*(byte *)(param_1 + 0xa0) + ((uint)puVar18 >> 8);
  *(char *)(param_1 + 0xab) = (char)uVar20;
  uVar6 = (uint)*(byte *)(param_1 + 0x9f) + (uVar13 >> 8);
  *(char *)(param_1 + 0xa1) = (char)puVar18;
  *(char *)(param_1 + 0xa0) = (char)uVar13;
  uVar9 = (uint)*(byte *)(param_1 + 0x9e) + (uVar6 >> 8);
  *(char *)(param_1 + 0x9f) = (char)uVar6;
  iVar10 = (uint)*(byte *)(param_1 + 0x9d) + (uVar9 >> 8);
  *(char *)(param_1 + 0x9e) = (char)uVar9;
  *(char *)(param_1 + 0x9d) = (char)iVar10;
  *(char *)(param_1 + 0x9c) = *(char *)(param_1 + 0x9c) + (char)((uint)iVar10 >> 8);
  local_a8 = *puVar1;
  uStack_a4 = *(undefined4 *)(param_1 + 0xa0);
  uStack_a0 = *(undefined4 *)(param_1 + 0xa4);
  uStack_9c = *(undefined4 *)(param_1 + 0xa8);
  if (*(int *)(param_1 + 0x78) == 0x10) {
    iVar10 = 0x20;
  }
  else {
    iVar10 = 0x30;
    uVar6 = (uVar20 & 0xff) + 1;
    *(char *)(param_1 + 0xab) = (char)uVar6;
    uVar9 = (uint)*(byte *)(param_1 + 0xaa) + (uVar6 >> 8);
    uVar6 = (uint)*(byte *)(param_1 + 0xa9) + (uVar9 >> 8);
    *(char *)(param_1 + 0xaa) = (char)uVar9;
    uVar9 = (uint)*(byte *)(param_1 + 0xa8) + (uVar6 >> 8);
    *(char *)(param_1 + 0xa9) = (char)uVar6;
    uVar14 = (uVar21 & 0xff) + (uVar9 >> 8);
    *(char *)(param_1 + 0xa8) = (char)uVar9;
    uVar6 = (uint)*(byte *)(param_1 + 0xa6) + (uVar14 >> 8);
    *(char *)(param_1 + 0xa7) = (char)uVar14;
    uVar9 = (uint)*(byte *)(param_1 + 0xa5) + (uVar6 >> 8);
    *(char *)(param_1 + 0xa6) = (char)uVar6;
    uVar6 = (uint)*(byte *)(param_1 + 0xa4) + (uVar9 >> 8);
    *(char *)(param_1 + 0xa5) = (char)uVar9;
    uVar9 = (uVar17 & 0xff) + (uVar6 >> 8);
    *(char *)(param_1 + 0xa4) = (char)uVar6;
    uVar14 = (uint)*(byte *)(param_1 + 0xa2) + (uVar9 >> 8);
    *(char *)(param_1 + 0xa3) = (char)uVar9;
    uVar6 = (uint)*(byte *)(param_1 + 0xa1) + (uVar14 >> 8);
    *(char *)(param_1 + 0xa2) = (char)uVar14;
    puVar18 = (uint *)((uVar13 & 0xff) + (uVar6 >> 8));
    *(char *)(param_1 + 0xa1) = (char)uVar6;
    uVar6 = (uint)*(byte *)(param_1 + 0x9f) + ((uint)puVar18 >> 8);
    *(char *)(param_1 + 0xa0) = (char)puVar18;
    uVar9 = (uint)*(byte *)(param_1 + 0x9e) + (uVar6 >> 8);
    *(char *)(param_1 + 0x9f) = (char)uVar6;
    iVar11 = (uint)*(byte *)(param_1 + 0x9d) + (uVar9 >> 8);
    *(char *)(param_1 + 0x9e) = (char)uVar9;
    *(char *)(param_1 + 0x9d) = (char)iVar11;
    *(char *)(param_1 + 0x9c) = *(char *)(param_1 + 0x9c) + (char)((uint)iVar11 >> 8);
    local_98 = *puVar1;
    uStack_94 = *(undefined4 *)(param_1 + 0xa0);
    uStack_90 = *(undefined4 *)(param_1 + 0xa4);
    uStack_8c = *(undefined4 *)(param_1 + 0xa8);
  }
  iVar11 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 100),auStack_88,&local_c4,
                            (uchar *)&local_b8,iVar10);
  if (iVar11 == 0) {
    return 0;
  }
  if (local_c4 != iVar10) {
    return 0;
  }
  uVar6 = *(uint *)(param_1 + 0x78);
  key = (uint *)(param_1 + 0x7c);
  memcpy(key,auStack_88,uVar6);
  uVar3 = *(undefined4 *)((int)auStack_84 + uVar6);
  uVar7 = *(undefined4 *)((int)auStack_84 + uVar6 + 4);
  uVar12 = *(undefined4 *)((int)auStack_84 + uVar6 + 8);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(auStack_88 + uVar6);
  *(undefined4 *)(param_1 + 0xa0) = uVar3;
  *(undefined4 *)(param_1 + 0xa4) = uVar7;
  *(undefined4 *)(param_1 + 0xa8) = uVar12;
  uVar9 = *(ushort *)(param_1 + 0x14) & 1;
  if ((*(ushort *)(param_1 + 0x14) & 1) == 0) {
    bVar24 = param_2 != (uint *)0x0 || (param_4 != (uint *)0x0 || param_6 != 0);
    if (param_2 != (uint *)0x0 || (param_4 != (uint *)0x0 || param_6 != 0)) {
      out = (uchar *)(param_1 + 0xc0);
      local_c0 = 0x10;
      memset(&local_58,uVar9,0x30);
      memset(out,uVar9,0x30);
      uVar9 = 1;
      bVar23 = uVar6 == 0x10;
      local_48 = CONCAT13(1,(undefined3)local_48);
      if (!bVar23) {
        uVar9 = 0xc;
      }
      if (bVar23) {
        uVar9 = 8;
      }
      local_bc = 0x10;
      *(uint *)(param_1 + 0xd0) = local_48 ^ *(uint *)(param_1 + 0xd0);
      *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) ^ local_58;
      *(uint *)(param_1 + 0xc4) = local_54 ^ *(uint *)(param_1 + 0xc4);
      uVar6 = *(uint *)(param_1 + 200) ^ local_50;
      *(uint *)(param_1 + 200) = uVar6;
      if (!bVar23) {
        uVar6 = 0x30;
      }
      *(uint *)(param_1 + 0xd4) = local_44 ^ *(uint *)(param_1 + 0xd4);
      if (bVar23) {
        uVar6 = 0x20;
      }
      *(uint *)(param_1 + 0xcc) = *(uint *)(param_1 + 0xcc) ^ local_4c;
      *(uint *)(param_1 + 0xd8) = local_40 ^ *(uint *)(param_1 + 0xd8);
      local_38 = CONCAT13(2,(undefined3)local_38);
      *(uint *)(param_1 + 0xdc) = local_3c ^ *(uint *)(param_1 + 0xdc);
      if (((uVar9 != 8) &&
          (*(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) ^ local_38, uVar9 != 9)) &&
         (*(uint *)(param_1 + 0xe4) = *(uint *)(param_1 + 0xe4) ^ local_34, uVar9 != 10)) {
        bVar23 = uVar9 == 0xc;
        if (bVar23) {
          uVar9 = *(uint *)(param_1 + 0xec);
        }
        *(uint *)(param_1 + 0xe8) = *(uint *)(param_1 + 0xe8) ^ local_30;
        if (bVar23) {
          uVar9 = uVar9 ^ local_2c;
        }
        if (bVar23) {
          *(uint *)(param_1 + 0xec) = uVar9;
        }
      }
      iVar10 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 0x6c),out,(int *)&local_bc,out,uVar6)
      ;
      if (iVar10 == 0) {
        return 0;
      }
      if (local_bc != uVar6) {
        return 0;
      }
      if (param_2 == (uint *)0x0) {
        uVar6 = 0;
      }
      else {
        bVar24 = param_3 == 0;
        uVar6 = param_3;
      }
      if (param_6 == 0) {
        param_7 = 0;
      }
      *(char *)(param_1 + 0xb3) = (char)*(undefined4 *)(param_1 + 0x78) + '\x10';
      *(undefined1 *)(param_1 + 0xb0) = 0;
      *(undefined1 *)(param_1 + 0xb1) = 0;
      if (param_4 == (uint *)0x0) {
        param_5 = 0;
      }
      *(undefined1 *)(param_1 + 0xb2) = 0;
      iVar10 = uVar6 + param_7 + param_5;
      *(char *)(param_1 + 0xaf) = (char)iVar10;
      *(char *)(param_1 + 0xad) = (char)((uint)iVar10 >> 0x10);
      *(char *)(param_1 + 0xac) = (char)((uint)iVar10 >> 0x18);
      iVar11 = param_1 + 100;
      *(char *)(param_1 + 0xae) = (char)((uint)iVar10 >> 8);
      *(undefined4 *)(param_1 + 0xbc) = 8;
      if ((!bVar24) && (iVar10 = ctr_BCC_update_part_2(iVar11,param_2), iVar10 == 0)) {
        return 0;
      }
      if ((param_7 != 0 && param_6 != 0) &&
         (iVar10 = ctr_BCC_update_part_2(iVar11,param_6), iVar10 == 0)) {
        return 0;
      }
      if ((param_5 != 0 && param_4 != (uint *)0x0) &&
         (iVar10 = ctr_BCC_update_part_2(iVar11,param_4), iVar10 == 0)) {
        return 0;
      }
      iVar10 = ctr_BCC_update_part_2(iVar11,&c80_14177,1);
      if (iVar10 == 0) {
        return 0;
      }
      iVar10 = *(int *)(param_1 + 0xbc);
      if (iVar10 != 0) {
        memset((void *)(iVar10 + param_1 + 0xac),0,0x10 - iVar10);
        local_48 = *(uint *)(param_1 + 0xac);
        local_44 = *(uint *)(param_1 + 0xb0);
        local_40 = *(uint *)(param_1 + 0xb4);
        local_3c = *(uint *)(param_1 + 0xb8);
        if (*(int *)(param_1 + 0x78) == 0x10) {
          uVar6 = 0x20;
        }
        else {
          uVar6 = 0x30;
          local_38 = local_48;
          local_34 = local_44;
          local_30 = local_40;
          local_2c = local_3c;
        }
        uVar9 = uVar6 - 4 >> 2;
        *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) ^ local_48;
        *(uint *)(param_1 + 0xc4) = *(uint *)(param_1 + 0xc4) ^ local_44;
        *(uint *)(param_1 + 200) = *(uint *)(param_1 + 200) ^ local_40;
        *(uint *)(param_1 + 0xcc) = *(uint *)(param_1 + 0xcc) ^ local_3c;
        *(uint *)(param_1 + 0xd0) = *(uint *)(param_1 + 0xd0) ^ local_48;
        local_bc = 0x10;
        *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) ^ local_44;
        *(uint *)(param_1 + 0xd8) = *(uint *)(param_1 + 0xd8) ^ local_40;
        *(uint *)(param_1 + 0xdc) = *(uint *)(param_1 + 0xdc) ^ local_3c;
        if (((uVar9 != 7) &&
            (*(uint *)(param_1 + 0xe0) = *(uint *)(param_1 + 0xe0) ^ local_38, uVar9 != 8)) &&
           (*(uint *)(param_1 + 0xe4) = *(uint *)(param_1 + 0xe4) ^ local_34, uVar9 != 9)) {
          bVar24 = uVar9 == 0xb;
          uVar13 = local_30 ^ *(uint *)(param_1 + 0xe8);
          uVar9 = *(uint *)(param_1 + 0xe8);
          if (bVar24) {
            uVar9 = local_2c;
          }
          *(uint *)(param_1 + 0xe8) = uVar13;
          if (bVar24) {
            uVar13 = *(uint *)(param_1 + 0xec) ^ uVar9;
          }
          if (bVar24) {
            *(uint *)(param_1 + 0xec) = uVar13;
          }
        }
        iVar10 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 0x6c),out,(int *)&local_bc,out,
                                  uVar6);
        if (iVar10 == 0) {
          return 0;
        }
        if (local_bc != uVar6) {
          return 0;
        }
      }
      iVar10 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(param_1 + 100),(EVP_CIPHER *)0x0,(ENGINE *)0x0
                                 ,out,(uchar *)0x0,-1);
      if (iVar10 == 0) {
        return 0;
      }
      iVar10 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 100),out,&local_c0,
                                out + *(int *)(param_1 + 0x78),0x10);
      if (iVar10 == 0) {
        return 0;
      }
      if (local_c0 != 0x10) {
        return 0;
      }
      iVar10 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 100),(uchar *)(param_1 + 0xd0),
                                &local_c0,out,0x10);
      if (iVar10 == 0) {
        return 0;
      }
      if (local_c0 != 0x10) {
        return 0;
      }
      if (*(int *)(param_1 + 0x78) != 0x10) {
        iVar10 = EVP_CipherUpdate(*(EVP_CIPHER_CTX **)(param_1 + 100),(uchar *)(param_1 + 0xe0),
                                  &local_c0,(uchar *)(param_1 + 0xd0),0x10);
        if (iVar10 == 0) {
          return 0;
        }
        if (local_c0 != 0x10) {
          return 0;
        }
      }
    }
    if ((param_3 != 0) && (uVar6 = *(uint *)(param_1 + 0x58), uVar6 != 0)) {
      uVar13 = *(uint *)(param_1 + 0x78);
      uVar14 = param_1 + 0xc0;
      uVar9 = uVar6;
      if (uVar13 <= uVar6) {
        uVar9 = uVar13;
      }
      if (uVar9 != 0) {
        if (uVar9 < 6 || key < (uint *)(param_1 + 0xc4) && uVar14 < param_1 + 0x80U) {
          pbVar19 = (byte *)(param_1 + 0xbf);
          puVar18 = key;
          do {
            pbVar19 = pbVar19 + 1;
            puVar16 = (uint *)((int)puVar18 + 1);
            *(byte *)puVar18 = (byte)*puVar18 ^ *pbVar19;
            puVar18 = puVar16;
          } while (puVar16 != (uint *)(uVar9 + 0x7c + param_1));
        }
        else {
          iVar10 = (uVar9 - 4 >> 2) + 1;
          *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0xc0) ^ *(uint *)(param_1 + 0x7c);
          uVar17 = iVar10 * 4;
          if (((iVar10 != 1) &&
              (*(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0xc4) ^ *(uint *)(param_1 + 0x80),
              iVar10 != 2)) &&
             ((*(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) ^ *(uint *)(param_1 + 200),
              iVar10 != 3 &&
              ((((*(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) ^ *(uint *)(param_1 + 0xcc),
                 iVar10 != 4 &&
                 (*(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) ^ *(uint *)(param_1 + 0xd0),
                 iVar10 != 5)) &&
                (*(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0xd4) ^ *(uint *)(param_1 + 0x90),
                iVar10 != 6)) &&
               (*(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) ^ *(uint *)(param_1 + 0xd8),
               iVar10 != 7)))))) {
            *(uint *)(param_1 + 0x98) = *(uint *)(param_1 + 0x98) ^ *(uint *)(param_1 + 0xdc);
          }
          if (uVar17 != uVar9) {
            uVar20 = uVar17 + 1;
            *(byte *)(param_1 + uVar17 + 0x7c) =
                 *(byte *)(uVar14 + iVar10 * 4) ^ *(byte *)(param_1 + uVar17 + 0x7c);
            if (uVar20 < uVar9) {
              uVar17 = uVar17 + 2;
              *(byte *)(param_1 + uVar20 + 0x7c) =
                   *(byte *)(param_1 + uVar20 + 0x7c) ^ *(byte *)(uVar14 + uVar20);
              if (uVar17 < uVar9) {
                *(byte *)(param_1 + uVar17 + 0x7c) =
                     *(byte *)(param_1 + uVar17 + 0x7c) ^ *(byte *)(uVar14 + uVar17);
              }
            }
          }
        }
      }
      if (uVar13 < uVar6) {
        uVar6 = uVar6 - uVar13;
        iVar10 = param_1 + 100;
        uVar9 = iVar10 + uVar13 + 0x5c;
        if (0xf < uVar6) {
          uVar6 = 0x10;
        }
        if (uVar9 < param_1 + 0xa0U && puVar1 < (undefined4 *)(uVar13 + 0x60 + iVar10) ||
            ((uVar9 & 3) != 0 || uVar6 < 6)) {
          *(byte *)(param_1 + 0x9c) = *(byte *)(param_1 + 0x9c) ^ *(byte *)(uVar14 + uVar13);
          if (uVar6 != 1) {
            iVar10 = uVar13 + uVar14;
            *(byte *)(param_1 + 0x9d) = *(byte *)(param_1 + 0x9d) ^ *(byte *)(iVar10 + 1);
            if ((((uVar6 != 2) &&
                 (*(byte *)(param_1 + 0x9e) = *(byte *)(param_1 + 0x9e) ^ *(byte *)(iVar10 + 2),
                 uVar6 != 3)) &&
                ((*(byte *)(param_1 + 0x9f) = *(byte *)(param_1 + 0x9f) ^ *(byte *)(iVar10 + 3),
                 uVar6 != 4 &&
                 ((*(byte *)(param_1 + 0xa0) = *(byte *)(param_1 + 0xa0) ^ *(byte *)(iVar10 + 4),
                  5 < uVar6 &&
                  (*(byte *)(param_1 + 0xa1) = *(byte *)(param_1 + 0xa1) ^ *(byte *)(iVar10 + 5),
                  6 < uVar6)))))) &&
               ((*(byte *)(param_1 + 0xa2) = *(byte *)(param_1 + 0xa2) ^ *(byte *)(iVar10 + 6),
                uVar6 != 7 &&
                ((((*(byte *)(param_1 + 0xa3) = *(byte *)(param_1 + 0xa3) ^ *(byte *)(iVar10 + 7),
                   uVar6 != 8 &&
                   (*(byte *)(param_1 + 0xa4) = *(byte *)(param_1 + 0xa4) ^ *(byte *)(iVar10 + 8),
                   uVar6 != 9)) &&
                  (*(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) ^ *(byte *)(iVar10 + 9),
                  uVar6 != 10)) &&
                 (((*(byte *)(param_1 + 0xa6) = *(byte *)(param_1 + 0xa6) ^ *(byte *)(iVar10 + 10),
                   uVar6 != 0xb &&
                   (*(byte *)(param_1 + 0xa7) = *(byte *)(param_1 + 0xa7) ^ *(byte *)(iVar10 + 0xb),
                   uVar6 != 0xc)) &&
                  ((*(byte *)(param_1 + 0xa8) = *(byte *)(param_1 + 0xa8) ^ *(byte *)(iVar10 + 0xc),
                   uVar6 != 0xd &&
                   ((*(byte *)(param_1 + 0xa9) = *(byte *)(param_1 + 0xa9) ^ *(byte *)(iVar10 + 0xd)
                    , uVar6 != 0xe &&
                    (*(byte *)(param_1 + 0xaa) = *(byte *)(param_1 + 0xaa) ^ *(byte *)(iVar10 + 0xe)
                    , uVar6 == 0x10)))))))))))) {
              *(byte *)(param_1 + 0xab) = *(byte *)(param_1 + 0xab) ^ *(byte *)(iVar10 + 0xf);
            }
          }
        }
        else {
          uVar17 = uVar6;
          if (uVar6 == 0) {
            uVar17 = 1;
          }
          iVar11 = (uVar17 - 4 >> 2) + 1;
          uVar20 = iVar11 * 4;
          if (uVar6 < 4) {
            uVar20 = 0;
          }
          else {
            *(uint *)(param_1 + 0x9c) =
                 *(uint *)(param_1 + 0x9c) ^ *(uint *)(iVar10 + uVar13 + 0x5c);
            if (((iVar11 != 1) &&
                (*(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) ^ *(uint *)(uVar9 + 4),
                iVar11 != 2)) &&
               (*(uint *)(param_1 + 0xa4) = *(uint *)(param_1 + 0xa4) ^ *(uint *)(uVar9 + 8),
               iVar11 != 3)) {
              *(uint *)(param_1 + 0xa8) = *(uint *)(param_1 + 0xa8) ^ *(uint *)(uVar9 + 0xc);
            }
            if (uVar20 == uVar17) goto LAB_001b7416;
          }
          iVar10 = uVar13 + uVar14;
          uVar9 = uVar20 + 1;
          *(byte *)(param_1 + uVar20 + 0x9c) =
               *(byte *)(param_1 + uVar20 + 0x9c) ^ *(byte *)(iVar10 + uVar20);
          if (uVar9 < uVar6) {
            uVar20 = uVar20 + 2;
            *(byte *)(param_1 + uVar9 + 0x9c) =
                 *(byte *)(param_1 + uVar9 + 0x9c) ^ *(byte *)(iVar10 + uVar9);
            if (uVar20 < uVar6) {
              *(byte *)(param_1 + uVar20 + 0x9c) =
                   *(byte *)(param_1 + uVar20 + 0x9c) ^ *(byte *)(iVar10 + uVar20);
            }
          }
        }
      }
    }
    goto LAB_001b7416;
  }
  if (param_3 != 0 && param_2 != (uint *)0x0) {
    uVar9 = param_3;
    if (uVar6 <= param_3) {
      uVar9 = uVar6;
    }
    if (uVar9 != 0) {
      if (key < param_2 + 1 && param_2 < (uint *)(param_1 + 0x80) ||
          (((uint)param_2 & 3) != 0 || uVar9 < 6)) {
        pbVar19 = (byte *)((int)param_2 + -1);
        puVar16 = key;
        do {
          pbVar19 = pbVar19 + 1;
          puVar5 = (uint *)((int)puVar16 + 1);
          *(byte *)puVar16 = *pbVar19 ^ (byte)*puVar16;
          puVar16 = puVar5;
          puVar18 = param_2;
        } while (puVar5 != (uint *)(param_1 + uVar9 + 0x7c));
      }
      else {
        iVar10 = (uVar9 - 4 >> 2) + 1;
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) ^ *param_2;
        uVar13 = iVar10 * 4;
        if ((((iVar10 != 1) &&
             (*(uint *)(param_1 + 0x80) = param_2[1] ^ *(uint *)(param_1 + 0x80), iVar10 != 2)) &&
            (*(uint *)(param_1 + 0x84) = param_2[2] ^ *(uint *)(param_1 + 0x84), iVar10 != 3)) &&
           (((*(uint *)(param_1 + 0x88) = param_2[3] ^ *(uint *)(param_1 + 0x88), iVar10 != 4 &&
             (*(uint *)(param_1 + 0x8c) = param_2[4] ^ *(uint *)(param_1 + 0x8c), iVar10 != 5)) &&
            ((*(uint *)(param_1 + 0x90) = param_2[5] ^ *(uint *)(param_1 + 0x90), iVar10 != 6 &&
             (*(uint *)(param_1 + 0x94) = param_2[6] ^ *(uint *)(param_1 + 0x94), iVar10 != 7))))))
        {
          *(uint *)(param_1 + 0x98) = param_2[7] ^ *(uint *)(param_1 + 0x98);
        }
        puVar18 = param_2;
        if (uVar9 != uVar13) {
          puVar18 = (uint *)(uint)(byte)param_2[iVar10];
          uVar14 = uVar13 + 1;
          *(byte *)(param_1 + uVar13 + 0x7c) =
               *(byte *)(param_1 + uVar13 + 0x7c) ^ (byte)param_2[iVar10];
          if (uVar14 < uVar9) {
            uVar13 = uVar13 + 2;
            *(byte *)(param_1 + uVar14 + 0x7c) =
                 *(byte *)(param_1 + uVar14 + 0x7c) ^ *(byte *)((int)param_2 + uVar14);
            if (uVar13 < uVar9) {
              *(byte *)(param_1 + uVar13 + 0x7c) =
                   *(byte *)(param_1 + uVar13 + 0x7c) ^ *(byte *)((int)param_2 + uVar13);
            }
          }
        }
      }
    }
    if (uVar6 < param_3) {
      puVar16 = (uint *)(param_3 - uVar6);
      if ((uint *)0xf < puVar16) {
        puVar16 = (uint *)0x10;
      }
      puVar8 = (undefined1 *)((int)param_2 + uVar6);
      puVar4 = (undefined4 *)((int)param_2 + uVar6 + 4);
      bVar23 = puVar8 <= (undefined1 *)(param_1 + 0xa0);
      bVar24 = (undefined1 *)(param_1 + 0xa0) == puVar8;
      if (bVar23 && !bVar24) {
        bVar23 = puVar1 <= puVar4;
        bVar24 = puVar4 == puVar1;
      }
      if (bVar23 && !bVar24 || (((uint)puVar8 & 3) != 0 || puVar16 < &DAT_00000006)) {
        *(byte *)(param_1 + 0x9c) = *(byte *)((int)param_2 + uVar6) ^ *(byte *)(param_1 + 0x9c);
        puVar18 = param_2;
        if (((((puVar16 != (uint *)0x1) &&
              (*(byte *)(param_1 + 0x9d) = *(byte *)(param_1 + 0x9d) ^ puVar8[1],
              puVar16 != (uint *)0x2)) &&
             (((*(byte *)(param_1 + 0x9e) = *(byte *)(param_1 + 0x9e) ^ puVar8[2],
               puVar16 != (uint *)0x3 &&
               (((*(byte *)(param_1 + 0x9f) = *(byte *)(param_1 + 0x9f) ^ puVar8[3],
                 puVar16 != (uint *)&DAT_00000004 &&
                 (*(byte *)(param_1 + 0xa0) =
                       *(byte *)((int)param_2 + uVar6 + 4) ^ *(byte *)(param_1 + 0xa0),
                 &DAT_00000005 < puVar16)) &&
                (*(byte *)(param_1 + 0xa1) = *(byte *)(param_1 + 0xa1) ^ puVar8[5],
                &DAT_00000006 < puVar16)))) &&
              (((*(byte *)(param_1 + 0xa2) = *(byte *)(param_1 + 0xa2) ^ puVar8[6],
                puVar16 != (uint *)&DAT_00000007 &&
                (*(byte *)(param_1 + 0xa3) = *(byte *)(param_1 + 0xa3) ^ puVar8[7],
                puVar16 != (uint *)0x8)) &&
               (*(byte *)(param_1 + 0xa4) = *(byte *)(param_1 + 0xa4) ^ puVar8[8],
               puVar16 != (uint *)&DAT_00000009)))))) &&
            ((*(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) ^ puVar8[9],
             puVar16 != (uint *)0xa &&
             (*(byte *)(param_1 + 0xa6) = *(byte *)(param_1 + 0xa6) ^ puVar8[10],
             puVar16 != (uint *)0xb)))) &&
           ((*(byte *)(param_1 + 0xa7) = *(byte *)(param_1 + 0xa7) ^ puVar8[0xb],
            puVar16 != (uint *)0xc &&
            (((*(byte *)(param_1 + 0xa8) = *(byte *)(param_1 + 0xa8) ^ puVar8[0xc],
              puVar16 != (uint *)0xd &&
              (*(byte *)(param_1 + 0xa9) = *(byte *)(param_1 + 0xa9) ^ puVar8[0xd],
              puVar16 != (uint *)0xe)) &&
             (*(byte *)(param_1 + 0xaa) = *(byte *)(param_1 + 0xaa) ^ puVar8[0xe],
             puVar16 == (uint *)0x10)))))) {
          *(byte *)(param_1 + 0xab) = *(byte *)(param_1 + 0xab) ^ puVar8[0xf];
        }
      }
      else {
        puVar18 = puVar16;
        if (puVar16 == (uint *)0x0) {
          puVar18 = (uint *)0x1;
        }
        iVar10 = ((uint)(puVar18 + -1) >> 2) + 1;
        puVar5 = (uint *)(iVar10 * 4);
        if (puVar16 < &DAT_00000004) {
          puVar5 = (uint *)0x0;
        }
        else {
          *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) ^ *(uint *)((int)param_2 + uVar6);
          if (((iVar10 != 1) &&
              (*(uint *)(param_1 + 0xa0) = *(uint *)(puVar8 + 4) ^ *(uint *)(param_1 + 0xa0),
              iVar10 != 2)) &&
             (*(uint *)(param_1 + 0xa4) = *(uint *)(puVar8 + 8) ^ *(uint *)(param_1 + 0xa4),
             iVar10 != 3)) {
            *(uint *)(param_1 + 0xa8) = *(uint *)(puVar8 + 0xc) ^ *(uint *)(param_1 + 0xa8);
          }
          if (puVar18 == puVar5) goto LAB_001b7458;
        }
        puVar15 = (uint *)((int)puVar5 + 1);
        bVar2 = puVar8[(int)puVar5] ^ *(byte *)((int)puVar5 + param_1 + 0x9c);
        *(byte *)((int)puVar5 + param_1 + 0x9c) = bVar2;
        puVar18 = (uint *)(uint)bVar2;
        if (puVar15 < puVar16) {
          puVar18 = (uint *)(param_1 + (int)puVar15);
          puVar5 = (uint *)((int)puVar5 + 2);
          *(byte *)(puVar18 + 0x27) = (byte)puVar18[0x27] ^ puVar8[(int)puVar15];
          if (puVar5 < puVar16) {
            *(byte *)((int)puVar5 + param_1 + 0x9c) =
                 *(byte *)((int)puVar5 + param_1 + 0x9c) ^ puVar8[(int)puVar5];
          }
        }
      }
    }
  }
LAB_001b7458:
  if (param_5 != 0 && param_4 != (uint *)0x0) {
    uVar9 = param_5;
    if (uVar6 <= param_5) {
      uVar9 = uVar6;
    }
    if (uVar9 != 0) {
      puVar18 = param_4;
      if (key < param_4 + 1 && param_4 < (uint *)(param_1 + 0x80) ||
          (((uint)param_4 & 3) != 0 || uVar9 < 6)) {
        pbVar19 = (byte *)((int)param_4 + -1);
        puVar16 = key;
        do {
          pbVar19 = pbVar19 + 1;
          puVar5 = (uint *)((int)puVar16 + 1);
          *(byte *)puVar16 = *pbVar19 ^ (byte)*puVar16;
          puVar16 = puVar5;
        } while (puVar5 != (uint *)(param_1 + uVar9 + 0x7c));
      }
      else {
        iVar10 = (uVar9 - 4 >> 2) + 1;
        *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) ^ *param_4;
        uVar13 = iVar10 * 4;
        if (((iVar10 != 1) &&
            (*(uint *)(param_1 + 0x80) = param_4[1] ^ *(uint *)(param_1 + 0x80), iVar10 != 2)) &&
           ((*(uint *)(param_1 + 0x84) = param_4[2] ^ *(uint *)(param_1 + 0x84), iVar10 != 3 &&
            ((((*(uint *)(param_1 + 0x88) = param_4[3] ^ *(uint *)(param_1 + 0x88), iVar10 != 4 &&
               (*(uint *)(param_1 + 0x8c) = param_4[4] ^ *(uint *)(param_1 + 0x8c), iVar10 != 5)) &&
              (*(uint *)(param_1 + 0x90) = param_4[5] ^ *(uint *)(param_1 + 0x90), iVar10 != 6)) &&
             (*(uint *)(param_1 + 0x94) = param_4[6] ^ *(uint *)(param_1 + 0x94), iVar10 != 7))))))
        {
          *(uint *)(param_1 + 0x98) = param_4[7] ^ *(uint *)(param_1 + 0x98);
        }
        if (uVar9 != uVar13) {
          puVar18 = (uint *)(uint)(byte)param_4[iVar10];
          uVar14 = uVar13 + 1;
          *(byte *)(param_1 + uVar13 + 0x7c) =
               *(byte *)(param_1 + uVar13 + 0x7c) ^ (byte)param_4[iVar10];
          if (uVar14 < uVar9) {
            uVar13 = uVar13 + 2;
            *(byte *)(param_1 + uVar14 + 0x7c) =
                 *(byte *)(param_1 + uVar14 + 0x7c) ^ *(byte *)((int)param_4 + uVar14);
            if (uVar13 < uVar9) {
              *(byte *)(param_1 + uVar13 + 0x7c) =
                   *(byte *)(param_1 + uVar13 + 0x7c) ^ *(byte *)((int)param_4 + uVar13);
            }
          }
        }
      }
    }
    if (uVar6 < param_5) {
      param_5 = param_5 - uVar6;
      if (0xf < param_5) {
        param_5 = 0x10;
      }
      puVar8 = (undefined1 *)((int)param_4 + uVar6);
      if (param_5 < 6) {
        puVar18 = (uint *)0x0;
      }
      if (5 < param_5) {
        puVar18 = (uint *)0x1;
      }
      puVar4 = (undefined4 *)((int)param_4 + uVar6 + 4);
      if (((uint)puVar8 & 3) != 0) {
        puVar18 = (uint *)0x0;
      }
      bVar23 = puVar8 <= (undefined1 *)(param_1 + 0xa0);
      bVar24 = (undefined1 *)(param_1 + 0xa0) == puVar8;
      if (bVar23 && !bVar24) {
        bVar23 = puVar1 <= puVar4;
        bVar24 = puVar4 == puVar1;
      }
      if (((uint)(!bVar23 || bVar24) & (uint)puVar18) == 0) {
        *(byte *)(param_1 + 0x9c) = *(byte *)((int)param_4 + uVar6) ^ *(byte *)(param_1 + 0x9c);
        if (((param_5 != 1) &&
            (*(byte *)(param_1 + 0x9d) = *(byte *)(param_1 + 0x9d) ^ puVar8[1], param_5 != 2)) &&
           ((((*(byte *)(param_1 + 0x9e) = *(byte *)(param_1 + 0x9e) ^ puVar8[2], param_5 != 3 &&
              ((*(byte *)(param_1 + 0x9f) = *(byte *)(param_1 + 0x9f) ^ puVar8[3], param_5 != 4 &&
               (*(byte *)(param_1 + 0xa0) =
                     *(byte *)((int)param_4 + uVar6 + 4) ^ *(byte *)(param_1 + 0xa0), 5 < param_5)))
              ) && (*(byte *)(param_1 + 0xa1) = *(byte *)(param_1 + 0xa1) ^ puVar8[5], 6 < param_5))
            && (((((*(byte *)(param_1 + 0xa2) = *(byte *)(param_1 + 0xa2) ^ puVar8[6], param_5 != 7
                   && (*(byte *)(param_1 + 0xa3) = *(byte *)(param_1 + 0xa3) ^ puVar8[7],
                      param_5 != 8)) &&
                  (*(byte *)(param_1 + 0xa4) = *(byte *)(param_1 + 0xa4) ^ puVar8[8], param_5 != 9))
                 && (((*(byte *)(param_1 + 0xa5) = *(byte *)(param_1 + 0xa5) ^ puVar8[9],
                      param_5 != 10 &&
                      (*(byte *)(param_1 + 0xa6) = *(byte *)(param_1 + 0xa6) ^ puVar8[10],
                      param_5 != 0xb)) &&
                     ((*(byte *)(param_1 + 0xa7) = *(byte *)(param_1 + 0xa7) ^ puVar8[0xb],
                      param_5 != 0xc &&
                      ((*(byte *)(param_1 + 0xa8) = *(byte *)(param_1 + 0xa8) ^ puVar8[0xc],
                       param_5 != 0xd &&
                       (*(byte *)(param_1 + 0xa9) = *(byte *)(param_1 + 0xa9) ^ puVar8[0xd],
                       param_5 != 0xe)))))))) &&
                (*(byte *)(param_1 + 0xaa) = *(byte *)(param_1 + 0xaa) ^ puVar8[0xe],
                param_5 == 0x10)))))) {
          *(byte *)(param_1 + 0xab) = *(byte *)(param_1 + 0xab) ^ puVar8[0xf];
        }
      }
      else {
        uVar9 = param_5;
        if (param_5 == 0) {
          uVar9 = 1;
        }
        iVar10 = (uVar9 - 4 >> 2) + 1;
        uVar13 = iVar10 * 4;
        if (param_5 < 4) {
          uVar13 = 0;
        }
        else {
          *(uint *)(param_1 + 0x9c) = *(uint *)(param_1 + 0x9c) ^ *(uint *)((int)param_4 + uVar6);
          if (((iVar10 != 1) &&
              (*(uint *)(param_1 + 0xa0) = *(uint *)(puVar8 + 4) ^ *(uint *)(param_1 + 0xa0),
              iVar10 != 2)) &&
             (*(uint *)(param_1 + 0xa4) = *(uint *)(puVar8 + 8) ^ *(uint *)(param_1 + 0xa4),
             iVar10 != 3)) {
            *(uint *)(param_1 + 0xa8) = *(uint *)(puVar8 + 0xc) ^ *(uint *)(param_1 + 0xa8);
          }
          if (uVar9 == uVar13) goto LAB_001b7416;
        }
        uVar6 = uVar13 + 1;
        *(byte *)(param_1 + uVar13 + 0x9c) = *(byte *)(param_1 + uVar13 + 0x9c) ^ puVar8[uVar13];
        if (uVar6 < param_5) {
          uVar13 = uVar13 + 2;
          *(byte *)(param_1 + uVar6 + 0x9c) = *(byte *)(param_1 + uVar6 + 0x9c) ^ puVar8[uVar6];
          if (uVar13 < param_5) {
            *(byte *)(param_1 + uVar13 + 0x9c) = *(byte *)(param_1 + uVar13 + 0x9c) ^ puVar8[uVar13]
            ;
          }
        }
      }
    }
  }
LAB_001b7416:
  iVar10 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(param_1 + 100),(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                             (uchar *)key,(uchar *)0x0,-1);
  if (iVar10 == 0) {
    return 0;
  }
  iVar10 = EVP_CipherInit_ex(*(EVP_CIPHER_CTX **)(param_1 + 0x68),(EVP_CIPHER *)0x0,(ENGINE *)0x0,
                             (uchar *)key,(uchar *)0x0,-1);
  if (iVar10 != 0) {
    return 1;
  }
  return 0;
}


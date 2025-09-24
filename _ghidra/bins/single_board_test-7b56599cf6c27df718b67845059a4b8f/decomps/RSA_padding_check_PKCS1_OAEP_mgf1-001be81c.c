
uint RSA_padding_check_PKCS1_OAEP_mgf1
               (byte *param_1,uint param_2,int param_3,uint param_4,int param_5,void *param_6,
               size_t param_7,EVP_MD *param_8,EVP_MD *param_9)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  size_t len;
  uint *mask;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  size_t sVar7;
  uint *puVar8;
  byte *pbVar9;
  int iVar10;
  uint num;
  uint uVar11;
  uint uVar12;
  byte *pbVar13;
  uint *puVar14;
  byte *pbVar15;
  byte *pbVar16;
  uint *puVar17;
  uint uVar18;
  uint *puVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  bool bVar24;
  bool bVar25;
  uint local_f8;
  uint local_ec;
  undefined4 local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uchar auStack_68 [68];
  
  if (param_8 == (EVP_MD *)0x0) {
    param_8 = EVP_sha1();
  }
  if (param_9 == (EVP_MD *)0x0) {
    param_9 = param_8;
  }
  len = EVP_MD_size(param_8);
  bVar24 = (int)param_4 < 0;
  bVar25 = param_4 == 0;
  if (0 < (int)param_4) {
    bVar24 = (int)param_2 < 0;
    bVar25 = param_2 == 0;
  }
  if (bVar25 || bVar24) {
    return 0xffffffff;
  }
  if ((param_5 < (int)param_4) ||
     (iVar10 = len + 1, param_5 + iVar10 * -2 < 0 != SBORROW4(param_5,iVar10 * 2))) {
    ERR_put_error(4,0x99,0x79,"crypto/rsa/rsa_oaep.c",0x98);
    return 0xffffffff;
  }
  iVar20 = param_5 - len;
  num = iVar20 - 1;
  mask = (uint *)CRYPTO_malloc(num,"crypto/rsa/rsa_oaep.c",0x9d);
  if (mask == (uint *)0x0) {
    uVar6 = 0xffffffff;
    ERR_put_error(4,0x99,0x41,"crypto/rsa/rsa_oaep.c",0x9f);
    uVar11 = 0xffffffff;
    pbVar16 = (byte *)0x0;
    local_f8 = 0;
  }
  else {
    pvVar4 = CRYPTO_malloc(param_5,"crypto/rsa/rsa_oaep.c",0xa3);
    if (pvVar4 == (void *)0x0) {
      ERR_put_error(4,0x99,0x41,"crypto/rsa/rsa_oaep.c",0xa6);
      uVar6 = 0xffffffff;
      uVar11 = 0xffffffff;
      pbVar16 = (byte *)0x0;
      local_f8 = 0;
    }
    else {
      pbVar13 = (byte *)(param_3 + param_4);
      pbVar9 = (byte *)((int)pvVar4 + param_5);
      if (param_5 < 1) {
        uVar11 = (uint)*(byte *)((int)pvVar4 + param_5);
        pbVar16 = pbVar9;
      }
      else {
        pbVar16 = pbVar9 + -param_5;
        do {
          uVar11 = ~((int)(param_4 - 1 & ~param_4) >> 0x1f);
          uVar6 = uVar11 & 1;
          pbVar13 = pbVar13 + -uVar6;
          param_4 = param_4 - uVar6;
          uVar11 = uVar11 & *pbVar13;
          pbVar9 = pbVar9 + -1;
          *pbVar9 = (byte)uVar11;
        } while (pbVar9 != pbVar16);
      }
      uVar11 = uVar11 - 1 & ~uVar11;
      local_f8 = (int)uVar11 >> 0x1f;
      puVar14 = (uint *)(pbVar16 + iVar10);
      iVar5 = PKCS1_MGF1((uchar *)&local_a8,len,(uchar *)puVar14,num,param_9);
      if (iVar5 == 0) {
        if (0 < (int)len) {
          if (((uint)(pbVar16 + 1) & 3) == 0 &&
              (5 < len && (&local_a4 <= pbVar16 + 1 || pbVar16 + 5 <= &local_a8))) {
            iVar5 = (len - 4 >> 2) + 1;
            local_a8 = local_a8 ^ *(uint *)(pbVar16 + 1);
            sVar7 = iVar5 * 4;
            if ((((((((iVar5 != 1) && (local_a4 = local_a4 ^ *(uint *)(pbVar16 + 5), iVar5 != 2)) &&
                    (local_a0 = local_a0 ^ *(uint *)(pbVar16 + 9), iVar5 != 3)) &&
                   ((local_9c = local_9c ^ *(uint *)(pbVar16 + 0xd), iVar5 != 4 &&
                    (local_98 = local_98 ^ *(uint *)(pbVar16 + 0x11), iVar5 != 5)))) &&
                  ((local_94 = local_94 ^ *(uint *)(pbVar16 + 0x15), iVar5 != 6 &&
                   ((local_90 = *(uint *)(pbVar16 + 0x19) ^ local_90, iVar5 != 7 &&
                    (local_8c = *(uint *)(pbVar16 + 0x1d) ^ local_8c, iVar5 != 8)))))) &&
                 (local_88 = *(uint *)(pbVar16 + 0x21) ^ local_88, iVar5 != 9)) &&
                (((local_84 = *(uint *)(pbVar16 + 0x25) ^ local_84, iVar5 != 10 &&
                  (local_80 = *(uint *)(pbVar16 + 0x29) ^ local_80, iVar5 != 0xb)) &&
                 (local_7c = *(uint *)(pbVar16 + 0x2d) ^ local_7c, iVar5 != 0xc)))) &&
               (((local_78 = *(uint *)(pbVar16 + 0x31) ^ local_78, iVar5 != 0xd &&
                 (local_74 = *(uint *)(pbVar16 + 0x35) ^ local_74, iVar5 != 0xe)) &&
                (local_70 = *(uint *)(pbVar16 + 0x39) ^ local_70, iVar5 != 0xf)))) {
              local_6c = *(uint *)(pbVar16 + 0x3d) ^ local_6c;
            }
            if (((len != sVar7) &&
                (*(byte *)(&local_a8 + iVar5) = *(byte *)(&local_a8 + iVar5) ^ pbVar16[sVar7 + 1],
                (int)(sVar7 + 1) < (int)len)) &&
               (*(byte *)((int)&local_a8 + sVar7 + 1) =
                     *(byte *)((int)&local_a8 + sVar7 + 1) ^ pbVar16[sVar7 + 2],
               (int)(sVar7 + 2) < (int)len)) {
              *(byte *)((int)&local_a8 + sVar7 + 2) =
                   *(byte *)((int)&local_a8 + sVar7 + 2) ^ pbVar16[sVar7 + 3];
            }
          }
          else {
            pbVar9 = pbVar16;
            pbVar13 = (byte *)&local_a8;
            do {
              pbVar9 = pbVar9 + 1;
              pbVar15 = pbVar13 + 1;
              *pbVar13 = *pbVar13 ^ *pbVar9;
              pbVar13 = pbVar15;
            } while (pbVar15 != (byte *)((int)&local_a8 + len));
          }
        }
        iVar5 = PKCS1_MGF1((uchar *)mask,num,(uchar *)&local_a8,len,param_9);
        if (iVar5 == 0) {
          if (0 < (int)num) {
            if ((((uint)mask | (uint)puVar14) & 3) == 0 &&
                (6 < num && (mask + 1 <= puVar14 || pbVar16 + len + 5 <= mask))) {
              uVar6 = iVar20 - 5U >> 2;
              uVar23 = uVar6 + 1;
              uVar6 = uVar6 - 8;
              uVar21 = uVar23 * 4;
              if (uVar6 < 0xfffffff7) {
                uVar6 = (uVar6 & 0xfffffff8) + 8;
                uVar18 = 0;
                puVar19 = mask;
                puVar1 = puVar14;
                do {
                  puVar8 = puVar1 + 8;
                  puVar17 = puVar19 + 8;
                  uVar18 = uVar18 + 8;
                  HintPreloadData(puVar19 + 0x14);
                  *puVar19 = *puVar1 ^ *puVar19;
                  puVar19[1] = puVar1[1] ^ puVar19[1];
                  puVar19[2] = puVar1[2] ^ puVar19[2];
                  puVar19[3] = puVar1[3] ^ puVar19[3];
                  puVar19[4] = puVar1[4] ^ puVar19[4];
                  puVar19[5] = puVar1[5] ^ puVar19[5];
                  puVar19[6] = puVar1[6] ^ puVar19[6];
                  puVar19[7] = puVar1[7] ^ puVar19[7];
                  puVar19 = puVar17;
                  puVar1 = puVar8;
                } while (uVar18 != uVar6);
              }
              else {
                uVar6 = 0;
                puVar17 = mask;
                puVar8 = puVar14;
              }
              puVar8 = puVar8 + -1;
              puVar19 = puVar17 + -1;
              do {
                puVar19 = puVar19 + 1;
                uVar6 = uVar6 + 1;
                puVar8 = puVar8 + 1;
                *puVar17 = *puVar8 ^ *puVar19;
                puVar17 = puVar17 + 1;
              } while (uVar6 < uVar23);
              if (uVar21 != num) {
                iVar5 = uVar21 + 1;
                *(byte *)(mask + uVar23) = (byte)mask[uVar23] ^ (byte)puVar14[uVar23];
                if (iVar5 < (int)num) {
                  iVar22 = uVar21 + 2;
                  *(byte *)((int)mask + iVar5) =
                       *(byte *)((int)mask + iVar5) ^ *(byte *)((int)puVar14 + iVar5);
                  if (iVar22 < (int)num) {
                    *(byte *)((int)mask + iVar22) =
                         *(byte *)((int)mask + iVar22) ^ *(byte *)((int)puVar14 + iVar22);
                  }
                }
              }
            }
            else {
              pbVar9 = (byte *)((int)puVar14 + -1);
              puVar14 = mask;
              do {
                pbVar9 = pbVar9 + 1;
                puVar8 = (uint *)((int)puVar14 + 1);
                *(byte *)puVar14 = (byte)*puVar14 ^ *pbVar9;
                puVar14 = puVar8;
              } while (puVar8 != (uint *)((int)mask + num));
            }
          }
          uVar6 = 0;
          iVar5 = EVP_Digest(param_6,param_7,auStack_68,(uint *)0x0,param_8,(ENGINE *)0x0);
          if (iVar5 != 0) {
            uVar21 = CRYPTO_memcmp(mask,auStack_68,len);
            uVar21 = (int)(uVar11 & uVar21 - 1 & ~uVar21) >> 0x1f;
            if ((int)len < (int)num) {
              uVar11 = 0;
              sVar7 = len;
              pbVar9 = (byte *)((int)mask + len);
              do {
                uVar18 = (uint)*pbVar9;
                uVar12 = (int)((uVar18 ^ 1) - 1 & ~(uVar18 ^ 1)) >> 0x1f;
                uVar23 = uVar12 & ~uVar6;
                uVar6 = uVar6 | uVar12;
                uVar21 = uVar21 & (uVar6 | (int)(uVar18 - 1 & ~uVar18) >> 0x1f);
                uVar18 = sVar7 & uVar23;
                sVar7 = sVar7 + 1;
                uVar11 = uVar11 & ~uVar23 | uVar18;
                pbVar9 = pbVar9 + 1;
              } while (sVar7 != num);
              uVar11 = num - (uVar11 + 1);
              local_f8 = uVar6 & uVar21 &
                         ~((int)((param_2 ^ uVar11 | param_2 - uVar11 ^ uVar11) ^ param_2) >> 0x1f);
              uVar6 = ~local_f8;
              local_ec = local_f8 & 1;
            }
            else {
              uVar11 = iVar20 - 2;
              local_f8 = 0;
              uVar6 = 0xffffffff;
              local_ec = 0;
            }
            uVar23 = (num - len) - 1;
            uVar21 = (int)((uVar23 ^ param_2 | uVar23 - param_2 ^ param_2) ^ uVar23) >> 0x1f;
            uVar21 = uVar23 & uVar21 | ~uVar21 & param_2;
            if (1 < (int)uVar23) {
              uVar18 = 1;
              do {
                uVar12 = uVar18 & uVar23 - uVar11;
                bVar2 = (char)((byte)(uVar12 - 1 >> 0x18) & ~(byte)(uVar12 >> 0x18)) >> 7;
                if (iVar10 < (int)(num - uVar18)) {
                  pbVar9 = (byte *)((int)mask + iVar10);
                  pbVar13 = (byte *)(iVar10 + uVar18 + (int)mask);
                  do {
                    pbVar15 = pbVar9 + 1;
                    *pbVar9 = bVar2 & *pbVar9 | *pbVar13 & ~bVar2;
                    pbVar9 = pbVar15;
                    pbVar13 = pbVar13 + 1;
                  } while ((byte *)((num - uVar18) + (int)mask) != pbVar15);
                }
                uVar12 = uVar18 * 2;
                iVar20 = uVar18 * -2;
                uVar18 = uVar12;
              } while (uVar23 != uVar12 && (int)(uVar23 + iVar20) < 0 == SBORROW4(uVar23,uVar12));
            }
            if (0 < (int)uVar21) {
              uVar23 = 0;
              pbVar9 = (byte *)((int)mask + len);
              do {
                iVar10 = uVar23 - uVar11;
                bVar2 = (byte)(uVar23 >> 0x18);
                bVar3 = (byte)(uVar11 >> 0x18);
                pbVar9 = pbVar9 + 1;
                uVar23 = uVar23 + 1;
                bVar2 = (byte)local_f8 &
                        (char)((bVar2 ^ bVar3 | (byte)((uint)iVar10 >> 0x18) ^ bVar3) ^ bVar2) >> 7;
                *param_1 = *param_1 & ~bVar2 | *pbVar9 & bVar2;
                param_1 = param_1 + 1;
              } while (uVar23 != uVar21);
            }
            ERR_put_error(4,0x99,0x79,"crypto/rsa/rsa_oaep.c",0x107);
            err_clear_last_constant_time(local_ec);
            goto LAB_001bedf2;
          }
        }
        uVar11 = 0xffffffff;
        uVar6 = ~local_f8;
      }
      else {
        uVar6 = ~local_f8;
        uVar11 = 0xffffffff;
      }
    }
  }
LAB_001bedf2:
  OPENSSL_cleanse(&local_a8,0x40);
  CRYPTO_clear_free(mask,num,"crypto/rsa/rsa_oaep.c",0x10b);
  CRYPTO_clear_free(pbVar16,param_5,"crypto/rsa/rsa_oaep.c",0x10c);
  return uVar6 | uVar11 & local_f8;
}



/* WARNING: Type propagation algorithm not settling */

void ssl3_cbc_digest_record
               (EVP_MD_CTX *param_1,uchar *param_2,uint *param_3,undefined4 *param_4,void *param_5,
               int param_6,uint param_7,void *param_8,uint param_9,char param_10)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  EVP_MD_CTX *pEVar4;
  EVP_MD *pEVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  uint extraout_r1;
  uint uVar9;
  uint extraout_r1_00;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  byte bVar13;
  byte bVar14;
  size_t sVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  EVP_MD_CTX *pEVar20;
  uint uVar21;
  byte bVar22;
  int iVar23;
  uint uVar24;
  uint cnt;
  bool bVar25;
  uint local_354;
  size_t local_350;
  size_t local_34c;
  size_t local_348;
  uint local_344;
  uint local_340;
  uint local_33c;
  uint local_338;
  SHA512_CTX *local_334;
  code *local_328;
  code *local_320;
  uint local_31c;
  uint local_318;
  size_t local_2e8;
  byte abStack_2d8 [4];
  undefined4 local_2d4;
  byte abStack_2d0 [16];
  uint auStack_2c0 [16];
  uint auStack_280 [32];
  undefined4 local_200;
  undefined4 uStack_1fc;
  undefined4 uStack_1f8;
  undefined local_1f4;
  undefined auStack_1f3 [115];
  EVP_MD_CTX local_180;
  EVP_PKEY_CTX *pEStack_168;
  _func_1230 *ap_Stack_164 [25];
  SHA512_CTX SStack_100;
  
  if (param_7 < 0x100000) {
    pEVar5 = EVP_MD_CTX_md(param_1);
    iVar6 = EVP_MD_type(pEVar5);
    bVar25 = iVar6 == 0x2a0;
    if (!bVar25) goto LAB_0006dfce;
LAB_0006e336:
    iVar6 = 0x200;
    iVar23 = 0x200;
    local_348 = 0x33;
    uVar18 = 0x20;
    cnt = 0x20;
    SHA256_Init((SHA256_CTX *)&SStack_100);
    bVar25 = true;
    local_320 = DAT_0006e41c;
    local_2e8 = 0x28;
    local_328 = DAT_0006e420;
    local_350 = 8;
    local_34c = 0x40;
    if (param_10 == '\0') goto LAB_0006e378;
LAB_0006e050:
    local_354 = param_9 + 0xb + local_2e8;
    local_344 = local_354 + param_7;
    local_33c = __aeabi_uidiv(((local_34c + local_350 + -1) - uVar18) + local_344,local_34c);
    local_340 = 2;
    param_6 = (local_354 - uVar18) + param_6;
    __aeabi_uidivmod(param_6,local_34c);
    local_318 = __aeabi_uidiv(param_6,local_34c);
    local_31c = __aeabi_uidiv(param_6 + local_350,local_34c);
    uVar11 = 3;
    iVar23 = iVar6;
    uVar21 = extraout_r1;
    cnt = uVar18;
  }
  else {
    OpenSSLDie(DAT_0006e418,0x1c6,DAT_0006e414);
    pEVar5 = EVP_MD_CTX_md(param_1);
    iVar6 = EVP_MD_type(pEVar5);
    bVar25 = iVar6 == 0x2a0;
    if (bVar25) goto LAB_0006e336;
LAB_0006dfce:
    if (bVar25 || iVar6 < 0x2a0) {
      if (iVar6 == 4) {
        local_348 = 0x33;
        MD5_Init((MD5_CTX *)&SStack_100);
        local_350 = 8;
        bVar25 = false;
        local_34c = 0x40;
        iVar23 = 0x200;
        cnt = 0x10;
        local_2e8 = 0x30;
        local_328 = DAT_0006e95c;
        local_320 = DAT_0006e960;
      }
      else {
        if (iVar6 != 0x40) {
LAB_0006dfdc:
          OpenSSLDie(DAT_0006e270,0x202,DAT_0006e274);
          if (param_3 == (uint *)0x0) {
            return;
          }
          *param_3 = 0xffffffff;
          return;
        }
        local_348 = 0x33;
        iVar23 = 0x200;
        SHA1_Init((SHA_CTX *)&SStack_100);
        bVar25 = true;
        local_2e8 = 0x28;
        local_328 = DAT_0006e954;
        cnt = 0x14;
        local_320 = DAT_0006e958;
        local_350 = 8;
        local_34c = 0x40;
      }
    }
    else if (iVar6 == 0x2a2) {
      local_348 = 0x73;
      SHA512_Init(&SStack_100);
      bVar25 = true;
      local_2e8 = 0x28;
      iVar23 = 0x400;
      cnt = 0x40;
      local_350 = 0x10;
      local_34c = 0x80;
      local_328 = DAT_0006e94c;
      local_320 = DAT_0006e950;
    }
    else if (iVar6 < 0x2a2) {
      local_348 = 0x73;
      SHA384_Init(&SStack_100);
      bVar25 = true;
      local_2e8 = 0x28;
      iVar23 = 0x400;
      cnt = 0x30;
      local_350 = 0x10;
      local_34c = 0x80;
      local_328 = DAT_0006e424;
      local_320 = DAT_0006e428;
    }
    else {
      if (iVar6 != 0x2a3) goto LAB_0006dfdc;
      local_348 = 0x33;
      SHA224_Init((SHA256_CTX *)&SStack_100);
      bVar25 = true;
      local_2e8 = 0x28;
      iVar23 = 0x200;
      cnt = 0x1c;
      local_350 = 8;
      local_34c = 0x40;
      local_328 = DAT_0006e278;
      local_320 = DAT_0006e27c;
    }
    iVar6 = iVar23;
    uVar18 = cnt;
    if (param_10 != '\0') goto LAB_0006e050;
LAB_0006e378:
    param_6 = (param_6 + 0xd) - cnt;
    local_344 = param_7 + 0xd;
    local_354 = 0xd;
    local_33c = __aeabi_uidiv((param_7 + 0xc + local_34c + local_350) - cnt);
    __aeabi_uidivmod(param_6,local_34c);
    local_318 = __aeabi_uidiv(param_6,local_34c);
    local_31c = __aeabi_uidiv(param_6 + local_350,local_34c);
    uVar11 = 6;
    local_340 = 6;
    uVar21 = extraout_r1_00;
  }
  local_334 = &SStack_100;
  param_6 = param_6 * 8;
  if (uVar11 < local_33c) {
    local_33c = local_33c - local_340;
    local_338 = local_33c * local_34c;
  }
  else {
    local_33c = 0;
    local_338 = 0;
  }
  if (param_10 == '\0') {
    memset(auStack_280,0,local_34c);
    param_6 = param_6 + iVar23;
    if (0x80 < param_9) {
      OpenSSLDie(DAT_0006e964,0x26a,DAT_0006e968);
    }
    memcpy(auStack_280,param_8,param_9);
    sVar15 = local_34c;
    if (local_34c == 0) {
      sVar15 = 1;
    }
    uVar11 = sVar15 >> 2;
    uVar18 = sVar15 & 0xfffffffc;
    if (uVar11 == 0) {
LAB_0006e7e6:
      do {
        *(byte *)((int)auStack_280 + uVar18) = *(byte *)((int)auStack_280 + uVar18) ^ 0x36;
        uVar18 = uVar18 + 1;
      } while (uVar18 < local_34c);
    }
    else {
      if (uVar11 < 9) {
        uVar24 = 0;
        puVar8 = auStack_280;
      }
      else {
        puVar8 = auStack_280;
        uVar19 = 0;
        do {
          puVar8 = puVar8 + 8;
          uVar24 = uVar19 + 8;
          uVar9 = uVar19 + 9;
          puVar8[-8] = puVar8[-8] ^ 0x36363636;
          puVar8[-7] = puVar8[-7] ^ 0x36363636;
          HintPreloadData(puVar8 + 0x11);
          puVar8[-4] = puVar8[-4] ^ 0x36363636;
          puVar8[-6] = puVar8[-6] ^ 0x36363636;
          puVar8[-5] = puVar8[-5] ^ 0x36363636;
          puVar8[-2] = puVar8[-2] ^ 0x36363636;
          puVar8[-1] = puVar8[-1] ^ 0x36363636;
          puVar8[-3] = puVar8[-3] ^ 0x36363636;
          uVar19 = uVar24;
        } while (uVar9 < uVar11 - 7);
      }
      puVar7 = puVar8 + -1;
      do {
        puVar7 = puVar7 + 1;
        uVar24 = uVar24 + 1;
        *puVar8 = *puVar7 ^ 0x36363636;
        puVar8 = puVar8 + 1;
      } while (uVar24 < uVar11);
      if (sVar15 != uVar18) goto LAB_0006e7e6;
    }
    (*local_328)(local_334,auStack_280);
  }
  bVar2 = (byte)((uint)param_6 >> 8);
  bVar13 = (byte)((uint)param_6 >> 0x10);
  bVar1 = (byte)((uint)param_6 >> 0x18);
  if (bVar25) {
    memset(abStack_2d0,0,local_350 - 4);
    abStack_2d0[local_350 - 4] = bVar1;
    abStack_2d0[local_350 - 1] = (byte)param_6;
    abStack_2d0[local_350 - 3] = bVar13;
    abStack_2d0[local_350 - 2] = bVar2;
  }
  else {
    memset(abStack_2d0,0,local_350);
    abStack_2d8[local_350] = (byte)param_6;
    abStack_2d8[local_350 + 3] = bVar1;
    abStack_2d8[local_350 + 2] = bVar13;
    abStack_2d8[local_350 + 1] = bVar2;
  }
  if (local_338 != 0) {
    if (param_10 == '\0') {
      local_200 = *param_4;
      uStack_1fc = param_4[1];
      uStack_1f8 = param_4[2];
      local_1f4 = *(undefined *)(param_4 + 3);
      memcpy(auStack_1f3,param_5,local_348);
      (*local_328)(local_334,&local_200);
      uVar18 = __aeabi_uidiv(local_338,local_34c);
      if (1 < uVar18) {
        uVar11 = 1;
        iVar6 = (int)param_5 + (local_34c - 0xd);
        do {
          uVar11 = uVar11 + 1;
          (*local_328)(local_334,iVar6);
          iVar6 = iVar6 + local_34c;
        } while (uVar11 != uVar18);
      }
    }
    else {
      if (local_354 <= local_34c) {
        return;
      }
      sVar15 = local_354 - local_34c;
      (*local_328)(local_334,param_4);
      memcpy(&local_200,(void *)((int)param_4 + local_34c),sVar15);
      memcpy((void *)((int)&local_200 + sVar15),param_5,local_34c - sVar15);
      (*local_328)(local_334,&local_200);
      iVar6 = __aeabi_uidiv(local_338,local_34c);
      if (1 < iVar6 - 1U) {
        uVar18 = 1;
        iVar23 = (int)param_5 + (local_34c - sVar15);
        do {
          uVar18 = uVar18 + 1;
          (*local_328)(local_334,iVar23);
          iVar23 = iVar23 + local_34c;
        } while (uVar18 != iVar6 - 1U);
      }
    }
  }
  memset(auStack_2c0,0,0x40);
  uVar18 = local_33c + local_340;
  if (CARRY4(local_33c,local_340) == false) {
    uVar11 = cnt;
    if (cnt == 0) {
      uVar11 = 1;
    }
    uVar24 = uVar11 >> 2;
    iVar6 = 1 - uVar24;
    if (1 < uVar24) {
      iVar6 = 0;
    }
    sVar15 = local_34c;
    if (local_34c == 0) {
      sVar15 = 1;
    }
    uVar19 = uVar11 & 0xfffffffc;
    if (iVar6 != 0) {
      uVar19 = 0;
    }
    do {
      bVar2 = (char)((byte)((local_33c ^ local_31c) - 1 >> 0x18) &
                    ~(byte)((local_33c ^ local_31c) >> 0x18)) >> 7;
      bVar1 = (char)((byte)((local_33c ^ local_318) - 1 >> 0x18) &
                    ~(byte)((local_33c ^ local_318) >> 0x18)) >> 7;
      uVar12 = 0;
      uVar9 = local_338;
      uVar10 = -uVar21;
      do {
        bVar22 = (byte)(uVar21 >> 0x18);
        bVar13 = (byte)(uVar12 >> 0x18);
        if (uVar9 < local_354) {
          bVar14 = bVar1 & ~((char)((bVar13 ^ bVar22 | bVar22 ^ (byte)(uVar10 >> 0x18)) ^ bVar13) >>
                            7);
          bVar22 = *(byte *)((int)param_4 + uVar12 + local_338) & ~bVar14;
        }
        else {
          uVar16 = (uVar21 ^ uVar10 | uVar12 ^ uVar21) ^ uVar12;
          bVar22 = 0;
          if (uVar9 < local_344) {
            bVar14 = bVar1 & ~(byte)((int)uVar16 >> 0x1f);
            bVar22 = *(byte *)((int)param_5 + uVar12 + (local_338 - local_354)) & ~bVar14;
          }
          else {
            uVar17 = uVar16;
            if (-1 < (int)uVar16) {
              uVar17 = (uint)bVar1;
            }
            bVar14 = (byte)uVar17;
            if (-1 >= (int)uVar16) {
              bVar14 = 0;
            }
          }
        }
        bVar3 = (byte)(uVar21 + 1 >> 0x18);
        uVar9 = uVar9 + 1;
        bVar13 = (~bVar2 | bVar1) &
                 ~(bVar1 & ~((char)(((byte)(uVar10 - 1 >> 0x18) ^ bVar3 | bVar13 ^ bVar3) ^ bVar13)
                            >> 7)) & (bVar22 | bVar14 & 0x80);
        bVar22 = bVar13 & ~bVar2;
        bVar25 = local_34c - local_350 <= uVar12;
        if (bVar25) {
          bVar13 = abStack_2d0[uVar10 + (local_350 - local_34c) + uVar21];
        }
        uVar10 = uVar10 + 1;
        if (bVar25) {
          bVar13 = bVar22 | bVar13 & bVar2;
        }
        *(byte *)((int)&local_180.digest + uVar12) = bVar13;
        uVar12 = uVar12 + 1;
      } while (uVar12 < local_34c);
      (*local_328)(local_334,&local_180);
      (*local_320)(local_334,&local_180);
      uVar9 = uVar19;
      if (iVar6 == 0) {
        uVar10 = CONCAT13(bVar2,CONCAT12(bVar2,CONCAT11(bVar2,bVar2)));
        if (uVar24 < 9) {
          uVar12 = 0;
          puVar8 = auStack_2c0;
          pEVar20 = &local_180;
        }
        else {
          puVar8 = auStack_2c0;
          uVar12 = 0;
          pEVar4 = (EVP_MD_CTX *)(&pEStack_168 + 2);
          do {
            pEVar20 = pEVar4;
            puVar8 = puVar8 + 8;
            uVar16 = uVar12 + 9;
            uVar12 = uVar12 + 8;
            HintPreloadData(puVar8 + 0xb);
            HintPreloadData(&pEVar20[1].update);
            puVar8[-8] = uVar10 & (uint)pEVar20[-2].pctx | puVar8[-8];
            puVar8[-7] = uVar10 & (uint)pEVar20[-2].update | puVar8[-7];
            puVar8[-6] = uVar10 & (uint)pEVar20[-1].digest | puVar8[-6];
            puVar8[-5] = uVar10 & (uint)pEVar20[-1].engine | puVar8[-5];
            puVar8[-4] = uVar10 & pEVar20[-1].flags | puVar8[-4];
            puVar8[-3] = uVar10 & (uint)pEVar20[-1].md_data | puVar8[-3];
            puVar8[-2] = uVar10 & (uint)pEVar20[-1].pctx | puVar8[-2];
            puVar8[-1] = uVar10 & (uint)pEVar20[-1].update | puVar8[-1];
            pEVar4 = (EVP_MD_CTX *)&pEVar20[1].flags;
          } while (uVar16 < uVar24 - 7);
        }
        iVar23 = 0;
        do {
          uVar12 = uVar12 + 1;
          *(uint *)((int)puVar8 + iVar23) =
               uVar10 & *(uint *)((int)&pEVar20->digest + iVar23) | *(uint *)((int)puVar8 + iVar23);
          iVar23 = iVar23 + 4;
        } while (uVar12 < uVar24);
        if (uVar11 != (uVar11 & 0xfffffffc)) goto LAB_0006e566;
      }
      else {
LAB_0006e566:
        do {
          *(byte *)((int)auStack_2c0 + uVar9) =
               bVar2 & *(byte *)((int)&local_180.digest + uVar9) |
               *(byte *)((int)auStack_2c0 + uVar9);
          uVar9 = uVar9 + 1;
        } while (uVar9 < cnt);
      }
      local_33c = local_33c + 1;
      local_338 = local_338 + sVar15;
    } while (local_33c <= uVar18);
  }
  EVP_MD_CTX_init(&local_180);
  EVP_DigestInit_ex(&local_180,param_1->digest,(ENGINE *)0x0);
  if (param_10 == '\0') {
    sVar15 = local_34c;
    if (local_34c == 0) {
      sVar15 = 1;
    }
    uVar21 = sVar15 >> 2;
    uVar18 = sVar15 & 0xfffffffc;
    local_2e8 = local_34c;
    if (uVar21 != 0) {
      if (uVar21 < 9) {
        puVar8 = auStack_280;
        uVar11 = 0;
      }
      else {
        puVar8 = auStack_280;
        uVar24 = 0;
        do {
          puVar8 = puVar8 + 8;
          uVar11 = uVar24 + 8;
          uVar19 = uVar24 + 9;
          HintPreloadData(puVar8 + 0x11);
          puVar8[-8] = puVar8[-8] ^ 0x6a6a6a6a;
          puVar8[-7] = puVar8[-7] ^ 0x6a6a6a6a;
          puVar8[-6] = puVar8[-6] ^ 0x6a6a6a6a;
          puVar8[-4] = puVar8[-4] ^ 0x6a6a6a6a;
          puVar8[-5] = puVar8[-5] ^ 0x6a6a6a6a;
          puVar8[-3] = puVar8[-3] ^ 0x6a6a6a6a;
          puVar8[-1] = puVar8[-1] ^ 0x6a6a6a6a;
          puVar8[-2] = puVar8[-2] ^ 0x6a6a6a6a;
          uVar24 = uVar11;
        } while (uVar19 < uVar21 - 7);
      }
      puVar7 = puVar8 + -1;
      do {
        puVar7 = puVar7 + 1;
        uVar11 = uVar11 + 1;
        *puVar8 = *puVar7 ^ 0x6a6a6a6a;
        puVar8 = puVar8 + 1;
      } while (uVar11 < uVar21);
      if (uVar18 == sVar15) goto LAB_0006e698;
    }
    do {
      *(byte *)((int)auStack_280 + uVar18) = *(byte *)((int)auStack_280 + uVar18) ^ 0x6a;
      uVar18 = uVar18 + 1;
    } while (uVar18 < local_34c);
  }
  else {
    memset(auStack_280,0x5c,local_2e8);
    EVP_DigestUpdate(&local_180,param_8,param_9);
  }
LAB_0006e698:
  EVP_DigestUpdate(&local_180,auStack_280,local_2e8);
  EVP_DigestUpdate(&local_180,auStack_2c0,cnt);
  EVP_DigestFinal(&local_180,param_2,&local_2d4);
  if (param_3 != (uint *)0x0) {
    *param_3 = local_2d4;
  }
  EVP_MD_CTX_cleanup(&local_180);
  return;
}


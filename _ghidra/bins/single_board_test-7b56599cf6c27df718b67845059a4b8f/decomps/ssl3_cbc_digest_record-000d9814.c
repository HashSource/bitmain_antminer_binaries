
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4
ssl3_cbc_digest_record
          (EVP_MD_CTX *param_1,uchar *param_2,uint *param_3,undefined4 *param_4,void *param_5,
          int param_6,uint param_7,void *param_8,uint param_9,char param_10)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  EVP_MD *pEVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  EVP_MD_CTX *ctx;
  uint extraout_r1;
  uint uVar10;
  uint extraout_r1_00;
  byte bVar11;
  size_t extraout_r2;
  size_t sVar12;
  size_t extraout_r2_00;
  uint *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  size_t __n;
  uint uVar18;
  size_t sVar19;
  uint uVar20;
  size_t local_358;
  uint local_350;
  uint local_334;
  uint local_324;
  uint local_320;
  SHA512_CTX *local_318;
  code *local_314;
  code *local_30c;
  size_t local_304;
  uint local_300;
  uint local_2fc;
  size_t local_2ec;
  undefined4 local_2d8;
  undefined4 local_2d4;
  byte abStack_2d0 [16];
  uint local_2c0;
  uint local_2bc;
  uint local_2b8;
  uint local_2b4;
  uint local_2b0;
  uint local_2ac;
  uint local_2a8;
  uint local_2a4;
  uint local_2a0;
  uint local_29c;
  uint local_298;
  uint local_294;
  uint local_290;
  uint local_28c;
  uint local_288;
  uint local_284;
  uint local_280 [32];
  undefined4 local_200 [3];
  undefined1 local_1f4;
  undefined1 auStack_1f3 [115];
  uint local_180 [4];
  uint local_170;
  uint local_16c;
  uint local_168;
  uint local_164;
  uint local_160;
  uint local_15c;
  uint local_158;
  uint local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  uint local_144;
  SHA512_CTX SStack_100;
  
  if (0xfffff < param_7) {
    return 0;
  }
  pEVar6 = EVP_MD_CTX_md(param_1);
  iVar7 = EVP_MD_type(pEVar6);
  if (iVar7 == 0x2a0) {
    iVar7 = SHA256_Init((SHA256_CTX *)&SStack_100);
    if (iVar7 < 1) {
      return 0;
    }
    iVar8 = 0x27;
    sVar19 = 0x33;
    iVar7 = 0x200;
    uVar20 = 6;
    bVar17 = true;
    __n = 8;
    local_314 = (code *)0x1585a5;
    local_2ec = 0x28;
    local_358 = 0x40;
    local_304 = 0x20;
    local_30c = (code *)0xd95e9;
  }
  else if (iVar7 < 0x2a1) {
    if (iVar7 == 4) {
      iVar7 = MD5_Init((MD5_CTX *)&SStack_100);
      if (iVar7 < 1) {
        return 0;
      }
      iVar8 = 0x37;
      sVar19 = 0x33;
      iVar7 = 0x200;
      uVar20 = 6;
      bVar17 = false;
      __n = 8;
      local_314 = (code *)0x138341;
      local_2ec = 0x30;
      local_358 = 0x40;
      local_304 = 0x10;
      local_30c = (code *)0xd9541;
    }
    else {
      if (iVar7 != 0x40) {
LAB_000d9bb0:
        if (param_3 == (uint *)0x0) {
          return 0;
        }
        *param_3 = 0;
        return 0;
      }
      iVar7 = SHA1_Init((SHA_CTX *)&SStack_100);
      if (iVar7 < 1) {
        return 0;
      }
      iVar8 = 0x33;
      sVar19 = 0x33;
      iVar7 = 0x200;
      uVar20 = 6;
      bVar17 = true;
      __n = 8;
      local_314 = (code *)0x15736d;
      local_2ec = 0x28;
      local_304 = 0x14;
      local_30c = (code *)0xd958d;
      local_358 = 0x40;
    }
  }
  else if (iVar7 == 0x2a2) {
    iVar7 = SHA512_Init(&SStack_100);
    if (iVar7 < 1) {
      return 0;
    }
    iVar8 = 0x4f;
    sVar19 = 0x73;
    iVar7 = 0x400;
    uVar20 = 4;
    bVar17 = true;
    __n = 0x10;
    local_314 = (code *)0x15e9d9;
    local_2ec = 0x28;
    local_358 = 0x80;
    local_304 = 0x40;
    local_30c = (code *)0xd967d;
  }
  else if (iVar7 < 0x2a2) {
    iVar7 = SHA384_Init(&SStack_100);
    if (iVar7 < 1) {
      return 0;
    }
    iVar8 = 0x5f;
    sVar19 = 0x73;
    iVar7 = 0x400;
    uVar20 = 4;
    bVar17 = true;
    local_314 = (code *)0x15e9d9;
    __n = 0x10;
    local_2ec = 0x28;
    local_358 = 0x80;
    local_304 = 0x30;
    local_30c = (code *)0xd967d;
  }
  else {
    if (iVar7 != 0x2a3) goto LAB_000d9bb0;
    iVar7 = SHA224_Init((SHA256_CTX *)&SStack_100);
    if (iVar7 < 1) {
      return 0;
    }
    iVar8 = 0x2b;
    sVar19 = 0x33;
    iVar7 = 0x200;
    uVar20 = 6;
    bVar17 = true;
    __n = 8;
    local_314 = (code *)0x1585a5;
    local_2ec = 0x28;
    local_358 = 0x40;
    local_304 = 0x1c;
    local_30c = (code *)0xd95e9;
  }
  local_318 = &SStack_100;
  if (param_10 == '\0') {
    local_334 = param_7 + 0xd;
    local_350 = 0xd;
    uVar9 = __aeabi_uidiv((param_7 + 0xc + local_358 + __n) - local_304,local_358);
    param_6 = (param_6 + 0xd) - local_304;
    __aeabi_uidivmod(param_6,local_358);
    local_2fc = __aeabi_uidiv(param_6,local_358);
    local_300 = __aeabi_uidiv(__n + param_6,local_358);
    sVar12 = extraout_r2_00;
    uVar18 = extraout_r1_00;
    uVar15 = uVar20;
  }
  else {
    local_350 = param_9 + 0xb + local_2ec;
    local_334 = param_7 + local_350;
    uVar9 = __aeabi_uidiv(iVar8 + local_334,local_358);
    param_6 = (local_350 - local_304) + param_6;
    __aeabi_uidivmod(param_6,local_358);
    local_2fc = __aeabi_uidiv(param_6,local_358);
    local_300 = __aeabi_uidiv(__n + param_6,local_358);
    uVar20 = 3;
    sVar12 = extraout_r2;
    uVar18 = extraout_r1;
    uVar15 = 2;
  }
  if (uVar20 < uVar9) {
    uVar14 = uVar9 - uVar15;
    sVar12 = local_358;
    local_320 = uVar14;
  }
  else {
    uVar14 = 0;
    local_324 = 0;
  }
  param_6 = param_6 * 8;
  if (uVar20 < uVar9) {
    local_324 = sVar12 * uVar14;
    uVar14 = local_320;
  }
  local_320 = uVar14;
  if (param_10 == '\0') {
    memset(local_280,0,local_358);
    if (0x80 < param_9) {
      return 0;
    }
    memcpy(local_280,param_8,param_9);
    uVar20 = 0;
    puVar13 = local_280;
    do {
      uVar20 = uVar20 + 1;
      *puVar13 = *puVar13 ^ 0x36363636;
      puVar13 = puVar13 + 1;
    } while (uVar20 < (local_358 - 4 >> 2) + 1);
    param_6 = param_6 + iVar7;
    (*local_314)(local_318,local_280);
  }
  bVar1 = (byte)((uint)param_6 >> 8);
  bVar2 = (byte)((uint)param_6 >> 0x10);
  bVar11 = (byte)((uint)param_6 >> 0x18);
  if (bVar17) {
    memset(abStack_2d0,0,__n - 4);
    abStack_2d0[__n - 4] = bVar11;
    abStack_2d0[__n - 1] = (byte)param_6;
    abStack_2d0[__n - 3] = bVar2;
    abStack_2d0[__n - 2] = bVar1;
  }
  else {
    memset(abStack_2d0,0,__n);
    *(byte *)((int)&local_2d8 + __n) = (byte)param_6;
    *(byte *)((int)&local_2d8 + __n + 3) = bVar11;
    *(byte *)((int)&local_2d8 + __n + 2) = bVar2;
    *(byte *)((int)&local_2d8 + __n + 1) = bVar1;
  }
  if (local_324 != 0) {
    if (param_10 == '\0') {
      local_200[0] = *param_4;
      local_200[1] = param_4[1];
      local_200[2] = param_4[2];
      local_1f4 = *(undefined1 *)(param_4 + 3);
      memcpy(auStack_1f3,param_5,sVar19);
      (*local_314)(local_318,local_200);
      uVar20 = __aeabi_uidiv(local_324,local_358);
      if (1 < uVar20) {
        uVar9 = 1;
        iVar7 = (local_358 - 0xd) + (int)param_5;
        do {
          uVar9 = uVar9 + 1;
          (*local_314)(local_318,iVar7);
          iVar7 = iVar7 + local_358;
        } while (uVar20 != uVar9);
      }
    }
    else {
      if (local_350 <= local_358) {
        return 0;
      }
      sVar19 = local_350 - local_358;
      (*local_314)(local_318,param_4);
      memcpy(local_200,(void *)((int)param_4 + local_358),sVar19);
      memcpy((void *)((int)local_200 + sVar19),param_5,local_358 - sVar19);
      (*local_314)(local_318,local_200);
      iVar7 = __aeabi_uidiv(local_324,local_358);
      if (1 < iVar7 - 1U) {
        uVar20 = 1;
        iVar8 = (int)param_5 + (local_358 - sVar19);
        do {
          uVar20 = uVar20 + 1;
          (*local_314)(local_318,iVar8);
          iVar8 = iVar8 + local_358;
        } while (iVar7 - 1U != uVar20);
      }
    }
  }
  memset(&local_2c0,0,0x40);
  uVar20 = local_320 + uVar15;
  if (!CARRY4(local_320,uVar15)) {
    uVar15 = local_304 - 4 >> 2;
    do {
      uVar16 = 0;
      bVar1 = (char)((byte)((local_300 ^ local_320) - 1 >> 0x18) &
                    ~(byte)((local_300 ^ local_320) >> 0x18)) >> 7;
      bVar2 = (char)((byte)((local_320 ^ local_2fc) - 1 >> 0x18) &
                    ~(byte)((local_320 ^ local_2fc) >> 0x18)) >> 7;
      uVar10 = ~(uint)bVar1;
      uVar9 = ~uVar18;
      uVar14 = local_324;
      do {
        if (uVar14 < local_350) {
          bVar11 = *(byte *)((int)param_4 + uVar16 + local_324);
        }
        else {
          bVar11 = 0;
          if (uVar14 < local_334) {
            bVar11 = *(byte *)((int)param_5 + uVar16 + (local_324 - local_350));
          }
        }
        bVar5 = (byte)(uVar16 >> 0x18);
        bVar4 = (byte)(uVar18 >> 0x18);
        bVar3 = (byte)(uVar18 + 1 >> 0x18);
        bVar4 = bVar2 & ~((char)((bVar5 ^ bVar4 | (byte)(uVar9 + 1 >> 0x18) ^ bVar4) ^ bVar5) >> 7);
        uVar14 = uVar14 + 1;
        bVar11 = (bVar2 | ~bVar1) &
                 ~(bVar2 & ~((char)(((byte)(uVar9 >> 0x18) ^ bVar3 | bVar5 ^ bVar3) ^ bVar5) >> 7))
                 & (bVar11 & ~bVar4 | bVar4 & 0x80);
        if (local_358 - __n <= uVar16) {
          bVar11 = bVar11 & (byte)uVar10 | bVar1 & abStack_2d0[uVar16 + (__n - local_358)];
          local_2d8 = (uint)bVar1;
          local_2d4 = uVar10;
        }
        *(byte *)((int)local_180 + uVar16) = bVar11;
        uVar16 = uVar16 + 1;
        uVar9 = uVar9 + 1;
      } while (local_358 != uVar16);
      (*local_314)(local_318);
      (*local_30c)(local_318,local_180);
      local_324 = local_324 + local_358;
      uVar9 = CONCAT13(bVar1,CONCAT12(bVar1,CONCAT11(bVar1,bVar1)));
      local_2c0 = local_2c0 | local_180[0] & uVar9;
      local_2b8 = local_180[2] & uVar9 | local_2b8;
      local_2bc = local_180[1] & uVar9 | local_2bc;
      local_2b4 = local_2b4 | uVar9 & local_180[3];
      if ((((((uVar15 != 3) && (local_2b0 = local_2b0 | local_170 & uVar9, uVar15 != 4)) &&
            (local_2ac = local_2ac | local_16c & uVar9, uVar15 != 5)) &&
           (((local_2a8 = local_2a8 | local_168 & uVar9, uVar15 != 6 &&
             (local_2a4 = local_2a4 | local_164 & uVar9, uVar15 != 7)) &&
            ((local_2a0 = local_2a0 | local_160 & uVar9, uVar15 != 8 &&
             ((local_29c = local_29c | local_15c & uVar9, uVar15 != 9 &&
              (local_298 = local_298 | local_158 & uVar9, uVar15 != 10)))))))) &&
          (local_294 = local_294 | local_154 & uVar9, uVar15 != 0xb)) &&
         (((local_290 = local_290 | local_150 & uVar9, uVar15 != 0xc &&
           (local_28c = local_28c | local_14c & uVar9, uVar15 != 0xd)) &&
          (local_288 = local_288 | local_148 & uVar9, uVar15 == 0xf)))) {
        local_284 = local_284 | local_144 & uVar9;
      }
      local_320 = local_320 + 1;
    } while (local_320 <= uVar20);
  }
  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
  if (ctx != (EVP_MD_CTX *)0x0) {
    pEVar6 = EVP_MD_CTX_md(param_1);
    iVar7 = EVP_DigestInit_ex(ctx,pEVar6,(ENGINE *)0x0);
    if (0 < iVar7) {
      if (param_10 == '\0') {
        uVar20 = 0;
        puVar13 = local_280;
        do {
          uVar20 = uVar20 + 1;
          *puVar13 = *puVar13 ^ 0x6a6a6a6a;
          local_2ec = local_358;
          puVar13 = puVar13 + 1;
        } while (uVar20 < (local_358 - 4 >> 2) + 1);
      }
      else {
        memset(local_280,0x5c,local_2ec);
        iVar7 = EVP_DigestUpdate(ctx,param_8,param_9);
        if (iVar7 < 1) goto LAB_000d9eec;
      }
      iVar7 = EVP_DigestUpdate(ctx,local_280,local_2ec);
      if ((0 < iVar7) && (iVar7 = EVP_DigestUpdate(ctx,&local_2c0,local_304), 0 < iVar7)) {
        iVar7 = EVP_DigestFinal(ctx,param_2,local_180);
        if (iVar7 != 0 && param_3 != (uint *)0x0) {
          *param_3 = local_180[0];
        }
        EVP_MD_CTX_free(ctx);
        return 1;
      }
    }
  }
LAB_000d9eec:
  EVP_MD_CTX_free(ctx);
  return 0;
}



undefined4
EVP_PBE_scrypt(char *param_1,int param_2,uchar *param_3,int param_4,uint param_5,uint param_6,
              uint param_7,uint param_8,uint param_9,uint param_10,uint param_11,int param_12,
              uchar *param_13,int param_14)

{
  byte bVar1;
  longlong lVar2;
  ushort uVar3;
  uint3 uVar4;
  uchar *out;
  EVP_MD *pEVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uchar *puVar11;
  uint uVar12;
  int extraout_r2;
  uint *puVar13;
  undefined4 uVar14;
  uint *puVar15;
  uint uVar16;
  uint uVar17;
  uchar *puVar18;
  uchar *puVar19;
  uint *puVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uchar *puVar26;
  uint *puVar27;
  bool bVar28;
  undefined8 uVar29;
  uint local_98;
  uint uStack_94;
  uint local_70;
  uint uStack_6c;
  uchar *local_68;
  
  if (param_7 == 0 && param_8 == 0 || (param_9 == 0 && param_10 == 0 || param_6 == 0 && param_5 < 2)
     ) {
    return 0;
  }
  if ((param_6 & (param_6 - 1) + (uint)(param_5 != 0)) != 0 || (param_5 & param_5 - 1) != 0) {
    return 0;
  }
  uVar29 = __aeabi_uldivmod(0x3fffffff,0,param_7,param_8);
  uVar23 = (uint)((ulonglong)uVar29 >> 0x20);
  bVar28 = param_10 <= uVar23;
  if (uVar23 == param_10) {
    bVar28 = param_9 <= (uint)uVar29;
  }
  if (!bVar28) {
    iVar8 = 0xae;
LAB_001b35ec:
    ERR_put_error(6,0xb5,0xac,"crypto/evp/pbe_scrypt.c",iVar8);
    return 0;
  }
  uVar23 = param_7 * 0x10;
  if (((param_8 & 0xfffffff) == 0 && param_7 >> 0x1c == 0) && uVar23 < 0x40) {
    uVar6 = 1 << (uVar23 - 0x20 & 0xff) | 1U >> (param_7 * -0x10 + 0x20 & 0xff);
    bVar28 = uVar6 <= param_6;
    if (param_6 == uVar6) {
      bVar28 = (uint)(1 << (uVar23 & 0xff)) <= param_5;
    }
    if (bVar28) {
      iVar8 = 0xb9;
      goto LAB_001b35ec;
    }
  }
  lVar2 = (ulonglong)(param_9 * 0x80) * (ulonglong)param_7;
  uVar23 = (uint)lVar2;
  uVar6 = (int)((ulonglong)lVar2 >> 0x20) +
          (param_10 << 7 | param_9 >> 0x19) * param_7 + param_9 * 0x80 * param_8;
  if (uVar6 != 0 || 0x7fffffff < uVar23) {
    iVar8 = 0xcb;
LAB_001b3606:
    ERR_put_error(6,0xb5,0xac,"crypto/evp/pbe_scrypt.c",iVar8);
    return 0;
  }
  uVar24 = param_5 + 2;
  uVar25 = param_6 + (0xfffffffd < param_5);
  uVar29 = __aeabi_uldivmod(0xffffffff,0x1ffffff,param_7,param_8);
  uVar7 = (uint)((ulonglong)uVar29 >> 0x20);
  bVar28 = uVar25 <= uVar7;
  if (uVar7 == uVar25) {
    bVar28 = uVar24 <= (uint)uVar29;
  }
  if (!bVar28) {
    iVar8 = 0xd5;
    goto LAB_001b3606;
  }
  lVar2 = (ulonglong)(uVar24 * 0x80) * (ulonglong)param_7;
  uVar12 = (uint)lVar2;
  uVar24 = (int)((ulonglong)lVar2 >> 0x20) +
           (uVar25 * 0x80 | uVar24 >> 0x19) * param_7 + uVar24 * 0x80 * param_8;
  uVar7 = ~uVar24;
  bVar28 = uVar6 <= uVar7;
  if (uVar7 == uVar6) {
    bVar28 = uVar23 <= ~uVar12;
  }
  if (!bVar28) {
    iVar8 = 0xdc;
    goto LAB_001b3606;
  }
  if (param_12 == 0 && param_11 == 0) {
    param_11 = 0x2000000;
  }
  else if (param_12 != 0) {
    param_11 = 0xffffffff;
  }
  iVar8 = uVar6 + uVar24 + CARRY4(uVar23,uVar12);
  bVar28 = iVar8 == 0;
  if (iVar8 == 0) {
    bVar28 = uVar23 + uVar12 <= param_11;
  }
  if (!bVar28) {
    iVar8 = 0xe8;
    goto LAB_001b3606;
  }
  if (param_13 == (uchar *)0x0) {
    return 1;
  }
  out = (uchar *)CRYPTO_malloc(uVar23 + uVar12,"crypto/evp/pbe_scrypt.c",0xf0);
  if (out == (uchar *)0x0) {
    ERR_put_error(6,0xb5,0x41,"crypto/evp/pbe_scrypt.c",0xf2);
    return 0;
  }
  pEVar5 = EVP_sha256();
  iVar8 = PKCS5_PBKDF2_HMAC(param_1,param_2,param_3,param_4,1,pEVar5,uVar23,out);
  if (iVar8 != 0) {
    iVar8 = param_7 * 0x80;
    puVar26 = out + uVar23;
    uVar7 = param_7 * 0x20;
    puVar27 = (uint *)(puVar26 + iVar8);
    uVar24 = param_8 << 5 | param_7 >> 0x1b;
    puVar15 = puVar27 + param_7 * 0x20;
    local_68 = out + 4;
    uVar6 = (uVar24 - 1) + (uint)(8 < uVar7);
    local_70 = 0;
    uStack_6c = 0;
    do {
      puVar13 = puVar15;
      if (uVar7 != 0 || uVar24 != 0) {
        uVar25 = 0;
        uVar16 = 0;
        puVar11 = local_68;
        puVar20 = puVar15;
        do {
          bVar1 = puVar11[-4];
          bVar28 = 0xfffffffe < uVar25;
          uVar25 = uVar25 + 1;
          uVar16 = uVar16 + bVar28;
          *puVar20 = (uint)bVar1;
          uVar3 = CONCAT11(puVar11[-3],bVar1);
          *puVar20 = (uint)uVar3;
          uVar4 = CONCAT12(puVar11[-2],uVar3);
          *puVar20 = (uint)uVar4;
          *puVar20 = CONCAT13(puVar11[-1],uVar4);
          puVar11 = puVar11 + 4;
          puVar20 = puVar20 + 1;
          puVar13 = puVar15 + param_7 * 0x20;
        } while (uVar16 != uVar24 || uVar25 != uVar7);
      }
      uVar25 = 1;
      uVar16 = 0;
      do {
        bVar28 = 0xfffffffe < uVar25;
        uVar25 = uVar25 + 1;
        uVar16 = uVar16 + bVar28;
        scryptBlockMix(puVar13,puVar13 + param_7 * -0x20,param_7,param_8);
        bVar28 = param_6 <= uVar16;
        if (uVar16 == param_6) {
          bVar28 = param_5 <= uVar25;
        }
        puVar13 = puVar13 + param_7 * 0x20;
      } while (!bVar28);
      uVar25 = uVar7 - 9 >> 3 | uVar6 * 0x20000000;
      scryptBlockMix(puVar26,(uint *)((param_5 - 1) * 0x80 * param_7 + (int)puVar15),param_7,param_8
                    );
      local_98 = 0;
      uStack_94 = 0;
      uVar16 = uVar25 + 1;
      uVar17 = uVar16 * 8;
      uVar25 = ((uVar6 >> 3) + (uint)(0xfffffffe < uVar25)) * 8 | uVar16 >> 0x1d;
      do {
        __aeabi_uldivmod(*(undefined4 *)(puVar26 + iVar8 + -0x40),0,param_5,param_6);
        puVar13 = (uint *)(extraout_r2 * iVar8 + (int)puVar15);
        if (uVar7 != 0 || uVar24 != 0) {
          if (uVar24 == 0 && uVar7 < 9) {
            uVar16 = 0;
            uVar10 = 0;
          }
          else {
            uVar21 = 0;
            uVar22 = 0;
            puVar9 = puVar27;
            puVar11 = puVar26 + 0x4c;
            puVar20 = puVar13;
            do {
              puVar13 = puVar20 + 8;
              HintPreloadData(puVar20 + 0x13);
              bVar28 = 0xfffffff7 < uVar21;
              uVar21 = uVar21 + 8;
              uVar22 = uVar22 + bVar28;
              HintPreloadData(puVar11);
              *puVar9 = *puVar20 ^ *(uint *)(puVar11 + -0x4c);
              puVar9[1] = puVar20[1] ^ *(uint *)(puVar11 + -0x48);
              puVar9[2] = *(uint *)(puVar11 + -0x44) ^ puVar20[2];
              puVar9[3] = *(uint *)(puVar11 + -0x40) ^ puVar20[3];
              puVar9[4] = puVar20[4] ^ *(uint *)(puVar11 + -0x3c);
              puVar9[5] = puVar20[5] ^ *(uint *)(puVar11 + -0x38);
              puVar9[6] = puVar20[6] ^ *(uint *)(puVar11 + -0x34);
              puVar9[7] = *(uint *)(puVar11 + -0x30) ^ puVar20[7];
              uVar16 = uVar17;
              uVar10 = uVar25;
              puVar9 = puVar9 + 8;
              puVar11 = puVar11 + 0x20;
              puVar20 = puVar13;
            } while (uVar22 != uVar25 || uVar21 != uVar17);
          }
          do {
            uVar10 = uVar10 + (0xfffffffe < uVar16);
            bVar28 = uVar24 <= uVar10;
            if (uVar10 == uVar24) {
              bVar28 = uVar7 <= uVar16 + 1;
            }
            puVar27[uVar16] = *(uint *)(puVar26 + uVar16 * 4) ^ *puVar13;
            uVar16 = uVar16 + 1;
            puVar13 = puVar13 + 1;
          } while (!bVar28);
        }
        bVar28 = 0xfffffffe < local_98;
        local_98 = local_98 + 1;
        uStack_94 = uStack_94 + bVar28;
        scryptBlockMix(puVar26,puVar27,param_7,param_8);
        bVar28 = param_6 <= uStack_94;
        if (uStack_94 == param_6) {
          bVar28 = param_5 <= local_98;
        }
      } while (!bVar28);
      if (uVar7 != 0 || uVar24 != 0) {
        puVar11 = puVar26 + -4;
        puVar18 = local_68;
        do {
          puVar11 = puVar11 + 4;
          uVar14 = *(undefined4 *)puVar11;
          puVar19 = puVar18 + 4;
          puVar18[-4] = (uchar)uVar14;
          puVar18[-3] = (uchar)((uint)uVar14 >> 8);
          puVar18[-2] = (uchar)((uint)uVar14 >> 0x10);
          puVar18[-1] = (uchar)((uint)uVar14 >> 0x18);
          puVar18 = puVar19;
        } while (local_68 + (uVar7 + 1) * 4 + -4 != puVar19);
      }
      bVar28 = 0xfffffffe < local_70;
      local_70 = local_70 + 1;
      uStack_6c = uStack_6c + bVar28;
      local_68 = local_68 + iVar8;
      bVar28 = param_10 <= uStack_6c;
      if (uStack_6c == param_10) {
        bVar28 = param_9 <= local_70;
      }
    } while (!bVar28);
    pEVar5 = EVP_sha256();
    uVar14 = 1;
    iVar8 = PKCS5_PBKDF2_HMAC(param_1,param_2,out,uVar23,1,pEVar5,param_14,param_13);
    if (iVar8 != 0) goto LAB_001b35d2;
  }
  uVar14 = 0;
  ERR_put_error(6,0xb5,0xb5,"crypto/evp/pbe_scrypt.c",0x105);
LAB_001b35d2:
  CRYPTO_clear_free(out,uVar23 + uVar12,"crypto/evp/pbe_scrypt.c",0x107);
  return uVar14;
}


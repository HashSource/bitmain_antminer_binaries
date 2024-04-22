
undefined4 ssl3_send_server_key_exchange(int param_1)

{
  uchar *ptr;
  BIGNUM *pBVar1;
  undefined4 uVar2;
  DH *dh;
  size_t sVar3;
  EC_POINT *pEVar4;
  EC_GROUP *group;
  EVP_PKEY *pkey;
  int iVar5;
  int iVar6;
  uint uVar7;
  uchar *puVar8;
  RSA *r;
  size_t sVar9;
  EC_KEY *src;
  uint uVar10;
  int iVar11;
  BIGNUM *pBVar12;
  char *__s;
  BN_CTX *ctx;
  DH *pDVar13;
  uchar uVar14;
  BUF_MEM *str;
  uchar *d;
  uchar *puVar15;
  uchar *local_98;
  size_t local_94;
  uint local_90;
  EVP_MD *local_8c;
  uint local_88;
  BIGNUM *local_84;
  int local_80;
  int local_7c;
  int local_78;
  int aiStack_74 [4];
  EVP_MD_CTX EStack_64;
  uchar auStack_4c [40];
  
  local_8c = (EVP_MD *)0x0;
  EVP_MD_CTX_init(&EStack_64);
  if (*(int *)(param_1 + 0x34) != 0x2150) goto LAB_0008623c;
  iVar6 = *(int *)(param_1 + 0x58);
  local_78 = 0;
  local_7c = 0;
  iVar5 = *(int *)(iVar6 + 0x344);
  local_80 = 0;
  local_84 = (BIGNUM *)0x0;
  uVar10 = *(uint *)(iVar5 + 0xc);
  iVar11 = *(int *)(param_1 + 0x98);
  str = *(BUF_MEM **)(param_1 + 0x3c);
  if ((int)(uVar10 << 0x1f) < 0) {
    r = *(RSA **)(iVar11 + 0x1c);
    if (r == (RSA *)0x0) {
      if (*(code **)(iVar11 + 0x20) == (code *)0x0) {
        ERR_put_error(0x14,0x9b,0xac,DAT_00086958,0x673);
        uVar2 = 0x28;
        local_98 = (uchar *)0x0;
      }
      else {
        if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
          uVar2 = 0x400;
        }
        else {
          uVar2 = 0x200;
        }
        r = (RSA *)(**(code **)(iVar11 + 0x20))(param_1,*(uint *)(iVar5 + 0x20) & 2,uVar2);
        if (r != (RSA *)0x0) {
          RSA_up_ref(r);
          *(RSA **)(iVar11 + 0x1c) = r;
          iVar6 = *(int *)(param_1 + 0x58);
          goto LAB_0008605e;
        }
        ERR_put_error(0x14,0x9b,0x11a,DAT_00086958,0x66a);
        uVar2 = 0x28;
        local_98 = (uchar *)0x0;
      }
      goto LAB_00086800;
    }
LAB_0008605e:
    pBVar12 = *(BIGNUM **)&r->field_0x10;
    local_80 = *(int *)&r->field_0x14;
    *(undefined4 *)(iVar6 + 0x370) = 1;
LAB_0008606c:
    local_88 = 0;
    local_84 = pBVar12;
    if (pBVar12 == (BIGNUM *)0x0) {
      iVar6 = *(int *)(param_1 + 0x58);
      sVar9 = 0;
      uVar14 = '\0';
      local_98 = (uchar *)0x0;
      local_94 = 0;
    }
    else {
      iVar6 = local_80;
      iVar5 = local_7c;
      iVar11 = local_78;
      if ((uVar10 & 0x400) == 0) {
        sVar9 = 0;
        pBVar1 = pBVar12;
        iVar6 = 0;
        do {
          iVar11 = BN_num_bits(pBVar1);
          iVar5 = iVar11 + 7;
          if (iVar11 + 7 < 0) {
            iVar5 = iVar11 + 0xe;
          }
          uVar7 = local_88 + 1;
          *(int *)((int)aiStack_74 + iVar6) = iVar5 >> 3;
          sVar9 = sVar9 + aiStack_74[local_88] + 2;
          local_88 = uVar7;
        } while (((int)uVar7 < 4) &&
                (pBVar1 = (&local_84)[uVar7], iVar6 = uVar7 * 4, pBVar1 != (BIGNUM *)0x0));
      }
      else {
LAB_00086370:
        local_78 = iVar11;
        local_7c = iVar5;
        local_80 = iVar6;
        local_84 = pBVar12;
        pBVar12 = local_84;
        local_88 = 0;
        sVar9 = 0;
        iVar6 = 0;
        pBVar1 = local_84;
        do {
          iVar11 = BN_num_bits(pBVar1);
          iVar5 = iVar11 + 7;
          if (iVar11 + 7 < 0) {
            iVar5 = iVar11 + 0xe;
          }
          uVar7 = local_88 + 1;
          *(int *)((int)aiStack_74 + iVar6) = iVar5 >> 3;
          if (local_88 == 2) {
            local_88 = 3;
            sVar9 = sVar9 + aiStack_74[2] + 1;
          }
          else {
            sVar9 = sVar9 + aiStack_74[local_88] + 2;
            local_88 = uVar7;
            if (3 < (int)uVar7) break;
          }
          iVar6 = local_88 * 4;
          pBVar1 = (&local_84)[local_88];
        } while (pBVar1 != (BIGNUM *)0x0);
      }
      iVar6 = *(int *)(param_1 + 0x58);
      uVar14 = '\0';
      local_94 = 0;
      local_98 = (uchar *)0x0;
    }
LAB_000860d4:
    ptr = local_98;
    iVar6 = *(int *)(iVar6 + 0x344);
    if ((*(uint *)(iVar6 + 0x10) & 0x404) == 0) {
      if (*(int *)(iVar6 + 0xc) << 0x17 < 0) {
        iVar6 = 0;
        pkey = (EVP_PKEY *)0x0;
      }
      else {
        pkey = (EVP_PKEY *)ssl_get_sign_pkey(param_1,iVar6,&local_8c);
        if (pkey == (EVP_PKEY *)0x0) {
          uVar2 = 0x32;
          goto LAB_00086800;
        }
        iVar6 = EVP_PKEY_size(pkey);
      }
    }
    else {
      iVar6 = 0;
      pkey = (EVP_PKEY *)0x0;
    }
    iVar6 = BUF_MEM_grow_clean(str,sVar9 + *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c) +
                                   iVar6);
    if (iVar6 == 0) {
      ERR_put_error(0x14,0x9b,7,DAT_00086958,0x761);
      ctx = (BN_CTX *)0x0;
      goto LAB_000867c8;
    }
    local_88 = 0;
    d = (uchar *)(*(int *)(*(int *)(param_1 + 0x3c) + 4) +
                 *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c));
    puVar15 = d;
    if (pBVar12 != (BIGNUM *)0x0) {
      if ((uVar10 & 0x400) == 0) {
        iVar6 = 0;
        do {
          *puVar15 = (uchar)((uint)*(undefined4 *)((int)aiStack_74 + iVar6) >> 8);
          puVar15[1] = (uchar)aiStack_74[local_88];
          BN_bn2bin((&local_84)[local_88],puVar15 + 2);
          uVar7 = local_88 + 1;
          iVar6 = uVar7 * 4;
          puVar15 = puVar15 + 2 + aiStack_74[local_88];
          local_88 = uVar7;
          if (3 < (int)uVar7) break;
        } while ((&local_84)[uVar7] != (BIGNUM *)0x0);
      }
      else {
        do {
          puVar8 = puVar15 + 2;
          if (local_88 == 2) {
            puVar8 = puVar15 + 1;
            *puVar15 = (uchar)aiStack_74[2];
          }
          else {
            *puVar15 = (uchar)((uint)aiStack_74[local_88] >> 8);
            puVar15[1] = (uchar)aiStack_74[local_88];
          }
          BN_bn2bin((&local_84)[local_88],puVar8);
          uVar7 = local_88 + 1;
          puVar15 = puVar8 + aiStack_74[local_88];
          local_88 = uVar7;
        } while (((int)uVar7 < 4) && ((&local_84)[uVar7] != (BIGNUM *)0x0));
      }
    }
    if ((int)(uVar10 << 0x18) < 0) {
      puVar8 = puVar15 + 4;
      puVar15[2] = uVar14;
      puVar15[3] = (uchar)local_94;
      *puVar15 = '\x03';
      puVar15[1] = '\0';
      puVar15 = puVar8 + local_94;
      memcpy(puVar8,local_98,local_94);
      local_98 = (uchar *)0x0;
      CRYPTO_free(ptr);
    }
    if ((int)(uVar10 << 0x17) < 0) {
      sVar3 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      *puVar15 = (uchar)(sVar3 >> 8);
      sVar3 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      puVar15[1] = (uchar)sVar3;
      __s = *(char **)(*(int *)(param_1 + 0xe4) + 0x14c);
      sVar3 = strlen(__s);
      strncpy((char *)(puVar15 + 2),__s,sVar3);
      sVar3 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      puVar15 = puVar15 + 2 + sVar3;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      iVar6 = *(int *)(*(int *)(param_1 + 8) + 100);
    }
    else {
      if ((pkey->type != 6) || ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) & 2) != 0))
      {
        if (local_8c == (EVP_MD *)0x0) {
          ERR_put_error(0x14,0x9b,0xfb,DAT_00086958,0x7d7);
          uVar2 = 0x28;
LAB_00086800:
          ctx = (BN_CTX *)0x0;
          ssl3_send_alert(param_1,2,uVar2);
        }
        else {
          if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e < 0) {
            iVar6 = tls12_get_sigandhash(puVar15,pkey,local_8c);
            if (iVar6 == 0) {
              ERR_put_error(0x14,0x9b,0x44,DAT_00086958,0x7bc);
              uVar2 = 0x50;
              goto LAB_00086800;
            }
            puVar15 = puVar15 + 2;
          }
          EVP_DigestInit_ex(&EStack_64,local_8c,(ENGINE *)0x0);
          EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
          EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
          EVP_DigestUpdate(&EStack_64,d,sVar9);
          iVar6 = EVP_SignFinal(&EStack_64,puVar15 + 2,&local_88,pkey);
          if (iVar6 != 0) {
            *puVar15 = (uchar)(local_88 >> 8);
            puVar15[1] = (uchar)local_88;
            iVar6 = *(int *)(*(int *)(param_1 + 8) + 100);
            sVar9 = local_88 + 2 + sVar9;
            if (*(int *)(iVar6 + 0x38) << 0x1e < 0) {
              sVar9 = sVar9 + 2;
            }
            goto LAB_00086234;
          }
          ERR_put_error(0x14,0x9b,6,DAT_00086958,0x7cc);
          ctx = (BN_CTX *)0x0;
        }
LAB_000867c8:
        if (local_98 == (uchar *)0x0) goto LAB_0008672c;
LAB_000867ce:
        CRYPTO_free(local_98);
        goto LAB_0008672c;
      }
      EVP_MD_CTX_set_flags(&EStack_64,8);
      EVP_DigestInit_ex(&EStack_64,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
      EVP_DigestUpdate(&EStack_64,d,sVar9);
      EVP_DigestFinal_ex(&EStack_64,auStack_4c,&local_88);
      uVar10 = local_88;
      EVP_MD_CTX_set_flags(&EStack_64,8);
      EVP_DigestInit_ex(&EStack_64,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
      EVP_DigestUpdate(&EStack_64,d,sVar9);
      EVP_DigestFinal_ex(&EStack_64,auStack_4c + uVar10,&local_88);
      iVar6 = RSA_sign(0x72,auStack_4c,uVar10 + local_88,puVar15 + 2,&local_90,(pkey->pkey).rsa);
      if (iVar6 < 1) {
        ERR_put_error(0x14,0x9b,4,DAT_00086958,0x7ae);
        ctx = (BN_CTX *)0x0;
        goto LAB_000867c8;
      }
      *puVar15 = (uchar)(local_90 >> 8);
      puVar15[1] = (uchar)local_90;
      sVar9 = sVar9 + local_90 + 2;
      iVar6 = *(int *)(*(int *)(param_1 + 8) + 100);
    }
LAB_00086234:
    (**(code **)(iVar6 + 0x40))(param_1,0xc,sVar9);
LAB_0008623c:
    *(undefined4 *)(param_1 + 0x34) = 0x2151;
    EVP_MD_CTX_cleanup(&EStack_64);
    uVar2 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
    return uVar2;
  }
  if ((int)(uVar10 << 0x1c) < 0) {
    pDVar13 = *(DH **)(iVar11 + 0x24);
    if (pDVar13 == (DH *)0x0) {
      if (*(code **)(iVar11 + 0x28) != (code *)0x0) {
        if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
          uVar2 = 0x400;
        }
        else {
          uVar2 = 0x200;
        }
        pDVar13 = (DH *)(**(code **)(iVar11 + 0x28))(param_1,*(uint *)(iVar5 + 0x20) & 2,uVar2);
        if (pDVar13 != (DH *)0x0) {
          iVar6 = *(int *)(param_1 + 0x58);
          goto LAB_0008626a;
        }
      }
      ERR_put_error(0x14,0x9b,0xab,DAT_00086958,0x687);
      local_98 = (uchar *)0x0;
      uVar2 = 0x28;
      goto LAB_00086800;
    }
LAB_0008626a:
    if (*(int *)(iVar6 + 0x348) != 0) {
      iVar6 = 0x68d;
      goto LAB_0008671c;
    }
    dh = DHparams_dup(pDVar13);
    iVar6 = 0x692;
    if (dh != (DH *)0x0) {
      pBVar12 = *(BIGNUM **)&pDVar13->field_0x14;
      *(DH **)(*(int *)(param_1 + 0x58) + 0x348) = dh;
      if (((pBVar12 == (BIGNUM *)0x0) || (*(int *)&pDVar13->field_0x18 == 0)) ||
         (*(int *)(param_1 + 0x100) << 0xb < 0)) {
        iVar5 = DH_generate_key(dh);
        iVar6 = 0x69b;
        if (iVar5 != 0) {
          iVar6 = *(int *)&dh->field_0x14;
          goto LAB_000862b4;
        }
      }
      else {
        pBVar12 = BN_dup(pBVar12);
        *(BIGNUM **)&dh->field_0x14 = pBVar12;
        pBVar12 = BN_dup(*(BIGNUM **)&pDVar13->field_0x18);
        iVar6 = *(int *)&dh->field_0x14;
        *(BIGNUM **)&dh->field_0x18 = pBVar12;
        if ((iVar6 != 0) && (pBVar12 != (BIGNUM *)0x0)) {
LAB_000862b4:
          pBVar12 = *(BIGNUM **)&dh->field_0x8;
          local_80 = *(int *)&dh->field_0xc;
          local_7c = iVar6;
          goto LAB_0008606c;
        }
        iVar6 = 0x6a2;
      }
    }
    ERR_put_error(0x14,0x9b,5,DAT_000867b0,iVar6);
    goto LAB_0008672a;
  }
  if ((uVar10 & 0x80) == 0) {
    if (-1 < (int)(uVar10 << 0x17)) {
      if ((uVar10 & 0x400) == 0) {
        ERR_put_error(0x14,0x9b,0xfa,DAT_00086958,0x746);
        uVar2 = 0x28;
        local_98 = (uchar *)0x0;
        goto LAB_00086800;
      }
      if (((*(BIGNUM **)(param_1 + 0x1a8) == (BIGNUM *)0x0) || (*(int *)(param_1 + 0x1ac) == 0)) ||
         ((*(int *)(param_1 + 0x1b0) == 0 ||
          (pBVar12 = *(BIGNUM **)(param_1 + 0x1a8), iVar6 = *(int *)(param_1 + 0x1ac),
          iVar5 = *(int *)(param_1 + 0x1b0), iVar11 = *(int *)(param_1 + 0x1b4),
          *(int *)(param_1 + 0x1b4) == 0)))) {
        ERR_put_error(0x14,0x9b,0x166,DAT_00086958,0x73a);
        goto LAB_0008672a;
      }
      goto LAB_00086370;
    }
    sVar9 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
    sVar9 = sVar9 + 2;
    iVar5 = 0;
    local_98 = (uchar *)0x0;
    local_94 = 0;
LAB_00086548:
    uVar14 = (uchar)iVar5;
    pBVar12 = (BIGNUM *)0x0;
    local_88 = 0;
    goto LAB_000860d4;
  }
  src = *(EC_KEY **)(iVar11 + 0x2c);
  if (*(int *)(iVar11 + 0x34) == 0) {
    if (src == (EC_KEY *)0x0) {
      if (*(code **)(iVar11 + 0x30) != (code *)0x0) {
        if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
          uVar2 = 0x400;
        }
        else {
          uVar2 = 0x200;
        }
        src = (EC_KEY *)(**(code **)(iVar11 + 0x30))(param_1,*(uint *)(iVar5 + 0x20) & 2,uVar2);
        goto LAB_000866d4;
      }
      goto LAB_00086898;
    }
  }
  else {
    iVar6 = tls1_shared_curve(param_1,0xfffffffe);
    if (iVar6 != 0) {
      src = EC_KEY_new_by_curve_name(iVar6);
    }
LAB_000866d4:
    if (src == (EC_KEY *)0x0) {
LAB_00086898:
      ERR_put_error(0x14,0x9b,0x137,DAT_00086958,0x6bf);
      local_98 = (uchar *)0x0;
      uVar2 = 0x28;
      goto LAB_00086800;
    }
    iVar6 = *(int *)(param_1 + 0x58);
  }
  if (*(int *)(iVar6 + 0x34c) != 0) {
    iVar6 = 0x6c5;
LAB_0008671c:
    ERR_put_error(0x14,0x9b,0x44,DAT_000867b0,iVar6);
    goto LAB_0008672a;
  }
  if (*(int *)(*(int *)(param_1 + 0x98) + 0x34) == 0) {
    src = EC_KEY_dup(src);
    if (src != (EC_KEY *)0x0) {
      iVar6 = *(int *)(param_1 + 0x58);
      goto LAB_00086452;
    }
    iVar6 = 0x6d1;
LAB_00086870:
    ERR_put_error(0x14,0x9b,0x2b,DAT_00086958,iVar6);
  }
  else {
LAB_00086452:
    *(EC_KEY **)(iVar6 + 0x34c) = src;
    pEVar4 = EC_KEY_get0_public_key(src);
    if ((((pEVar4 == (EC_POINT *)0x0) ||
         (pBVar12 = EC_KEY_get0_private_key(src), pBVar12 == (BIGNUM *)0x0)) ||
        (*(int *)(param_1 + 0x100) << 0xc < 0)) && (iVar6 = EC_KEY_generate_key(src), iVar6 == 0)) {
      iVar6 = 0x6db;
      goto LAB_00086870;
    }
    group = EC_KEY_get0_group(src);
    if (((group == (EC_GROUP *)0x0) ||
        (pEVar4 = EC_KEY_get0_public_key(src), pEVar4 == (EC_POINT *)0x0)) ||
       (pBVar12 = EC_KEY_get0_private_key(src), pBVar12 == (BIGNUM *)0x0)) {
      iVar6 = 0x6e3;
      goto LAB_00086870;
    }
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) << 0x1e < 0) &&
       (iVar6 = EC_GROUP_get_degree(group), 0xa3 < iVar6)) {
      ERR_put_error(0x14,0x9b,0x136,DAT_00086958,0x6ea);
    }
    else {
      EC_GROUP_get_curve_name(group);
      iVar5 = tls1_ec_nid2curve_id();
      if (iVar5 != 0) {
        pEVar4 = EC_KEY_get0_public_key(src);
        sVar9 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                   (BN_CTX *)0x0);
        local_98 = (uchar *)CRYPTO_malloc(sVar9,DAT_000867b0,0x705);
        ctx = BN_CTX_new();
        if (local_98 == (uchar *)0x0 || ctx == (BN_CTX *)0x0) {
          ERR_put_error(0x14,0x9b,0x41,DAT_00086958,0x709);
          goto LAB_000867c8;
        }
        pEVar4 = EC_KEY_get0_public_key(src);
        local_94 = EC_POINT_point2oct(group,pEVar4,POINT_CONVERSION_UNCOMPRESSED,local_98,sVar9,ctx)
        ;
        if (local_94 != 0) {
          BN_CTX_free(ctx);
          iVar6 = *(int *)(param_1 + 0x58);
          sVar9 = local_94 + 4;
          local_84 = (BIGNUM *)0x0;
          local_80 = 0;
          local_7c = 0;
          local_78 = 0;
          goto LAB_00086548;
        }
        ERR_put_error(0x14,0x9b,0x2b,DAT_00086958,0x713);
        goto LAB_000867ce;
      }
      ERR_put_error(0x14,0x9b,0x13b,DAT_00086958,0x6f7);
    }
  }
LAB_0008672a:
  ctx = (BN_CTX *)0x0;
LAB_0008672c:
  BN_CTX_free(ctx);
  EVP_MD_CTX_cleanup(&EStack_64);
  *(undefined4 *)(param_1 + 0x34) = 5;
  return 0xffffffff;
}



undefined4 ssl3_send_server_key_exchange(int param_1)

{
  uchar *ptr;
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  undefined4 uVar3;
  DH *dh;
  size_t sVar4;
  EC_POINT *pEVar5;
  EC_GROUP *group;
  EVP_PKEY *pkey;
  int iVar6;
  int iVar7;
  uint uVar8;
  uchar *puVar9;
  RSA *r;
  size_t sVar10;
  EC_KEY *src;
  uint uVar11;
  int iVar12;
  BIGNUM *pBVar13;
  char *__s;
  BN_CTX *ctx;
  DH *pDVar14;
  uchar uVar15;
  BUF_MEM *str;
  uchar *d;
  uchar *puVar16;
  uchar *local_98;
  size_t local_94;
  uint local_90;
  EVP_MD *local_8c;
  uint local_88;
  BIGNUM *local_84 [3];
  int local_78;
  int aiStack_74 [4];
  EVP_MD_CTX EStack_64;
  uchar auStack_4c [40];
  
  local_8c = (EVP_MD *)0x0;
  EVP_MD_CTX_init(&EStack_64);
  if (*(int *)(param_1 + 0x34) != 0x2150) goto LAB_00131ce4;
  iVar7 = *(int *)(param_1 + 0x58);
  local_78 = 0;
  local_84[2] = (BIGNUM *)0x0;
  iVar6 = *(int *)(iVar7 + 0x344);
  local_84[1] = (BIGNUM *)0x0;
  local_84[0] = (BIGNUM *)0x0;
  uVar11 = *(uint *)(iVar6 + 0xc);
  iVar12 = *(int *)(param_1 + 0x98);
  str = *(BUF_MEM **)(param_1 + 0x3c);
  if ((int)(uVar11 << 0x1f) < 0) {
    r = *(RSA **)(iVar12 + 0x1c);
    if (r == (RSA *)0x0) {
      if (*(code **)(iVar12 + 0x20) == (code *)0x0) {
        ERR_put_error(0x14,0x9b,0xac,"s3_srvr.c",0x673);
        uVar3 = 0x28;
        local_98 = (uchar *)0x0;
      }
      else {
        if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
          uVar3 = 0x400;
        }
        else {
          uVar3 = 0x200;
        }
        r = (RSA *)(**(code **)(iVar12 + 0x20))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar3);
        if (r != (RSA *)0x0) {
          RSA_up_ref(r);
          *(RSA **)(iVar12 + 0x1c) = r;
          iVar7 = *(int *)(param_1 + 0x58);
          goto LAB_00131b06;
        }
        ERR_put_error(0x14,0x9b,0x11a,"s3_srvr.c",0x66a);
        uVar3 = 0x28;
        local_98 = (uchar *)0x0;
      }
      goto LAB_001322a8;
    }
LAB_00131b06:
    pBVar13 = r->n;
    local_84[1] = r->e;
    *(undefined4 *)(iVar7 + 0x370) = 1;
LAB_00131b14:
    local_88 = 0;
    local_84[0] = pBVar13;
    if (pBVar13 == (BIGNUM *)0x0) {
      iVar7 = *(int *)(param_1 + 0x58);
      sVar10 = 0;
      uVar15 = '\0';
      local_98 = (uchar *)0x0;
      local_94 = 0;
    }
    else {
      pBVar2 = local_84[1];
      pBVar1 = local_84[2];
      iVar7 = local_78;
      if ((uVar11 & 0x400) == 0) {
        sVar10 = 0;
        pBVar2 = pBVar13;
        iVar7 = 0;
        do {
          iVar12 = BN_num_bits(pBVar2);
          iVar6 = iVar12 + 7;
          if (iVar12 + 7 < 0) {
            iVar6 = iVar12 + 0xe;
          }
          uVar8 = local_88 + 1;
          *(int *)((int)aiStack_74 + iVar7) = iVar6 >> 3;
          sVar10 = sVar10 + aiStack_74[local_88] + 2;
          local_88 = uVar8;
        } while (((int)uVar8 < 4) &&
                (pBVar2 = local_84[uVar8], iVar7 = uVar8 * 4, pBVar2 != (BIGNUM *)0x0));
      }
      else {
LAB_00131e18:
        local_78 = iVar7;
        local_84[2] = pBVar1;
        local_84[1] = pBVar2;
        local_84[0] = pBVar13;
        pBVar13 = local_84[0];
        local_88 = 0;
        sVar10 = 0;
        iVar7 = 0;
        pBVar2 = local_84[0];
        do {
          iVar12 = BN_num_bits(pBVar2);
          iVar6 = iVar12 + 7;
          if (iVar12 + 7 < 0) {
            iVar6 = iVar12 + 0xe;
          }
          uVar8 = local_88 + 1;
          *(int *)((int)aiStack_74 + iVar7) = iVar6 >> 3;
          if (local_88 == 2) {
            local_88 = 3;
            sVar10 = sVar10 + aiStack_74[2] + 1;
          }
          else {
            sVar10 = sVar10 + aiStack_74[local_88] + 2;
            local_88 = uVar8;
            if (3 < (int)uVar8) break;
          }
          iVar7 = local_88 * 4;
          pBVar2 = local_84[local_88];
        } while (pBVar2 != (BIGNUM *)0x0);
      }
      iVar7 = *(int *)(param_1 + 0x58);
      uVar15 = '\0';
      local_94 = 0;
      local_98 = (uchar *)0x0;
    }
LAB_00131b7c:
    ptr = local_98;
    iVar7 = *(int *)(iVar7 + 0x344);
    if ((*(uint *)(iVar7 + 0x10) & 0x404) == 0) {
      if (*(int *)(iVar7 + 0xc) << 0x17 < 0) {
        iVar7 = 0;
        pkey = (EVP_PKEY *)0x0;
      }
      else {
        pkey = (EVP_PKEY *)ssl_get_sign_pkey(param_1,iVar7,&local_8c);
        if (pkey == (EVP_PKEY *)0x0) {
          uVar3 = 0x32;
          goto LAB_001322a8;
        }
        iVar7 = EVP_PKEY_size(pkey);
      }
    }
    else {
      iVar7 = 0;
      pkey = (EVP_PKEY *)0x0;
    }
    iVar7 = BUF_MEM_grow_clean(str,sVar10 + *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c) +
                                   iVar7);
    if (iVar7 == 0) {
      ERR_put_error(0x14,0x9b,7,"s3_srvr.c",0x761);
      ctx = (BN_CTX *)0x0;
      goto LAB_00132270;
    }
    local_88 = 0;
    d = (uchar *)(*(int *)(*(int *)(param_1 + 0x3c) + 4) +
                 *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c));
    puVar16 = d;
    if (pBVar13 != (BIGNUM *)0x0) {
      if ((uVar11 & 0x400) == 0) {
        iVar7 = 0;
        do {
          *puVar16 = (uchar)((uint)*(undefined4 *)((int)aiStack_74 + iVar7) >> 8);
          puVar16[1] = (uchar)aiStack_74[local_88];
          BN_bn2bin(local_84[local_88],puVar16 + 2);
          uVar8 = local_88 + 1;
          iVar7 = uVar8 * 4;
          puVar16 = puVar16 + 2 + aiStack_74[local_88];
          local_88 = uVar8;
          if (3 < (int)uVar8) break;
        } while (local_84[uVar8] != (BIGNUM *)0x0);
      }
      else {
        do {
          puVar9 = puVar16 + 2;
          if (local_88 == 2) {
            puVar9 = puVar16 + 1;
            *puVar16 = (uchar)aiStack_74[2];
          }
          else {
            *puVar16 = (uchar)((uint)aiStack_74[local_88] >> 8);
            puVar16[1] = (uchar)aiStack_74[local_88];
          }
          BN_bn2bin(local_84[local_88],puVar9);
          uVar8 = local_88 + 1;
          puVar16 = puVar9 + aiStack_74[local_88];
          local_88 = uVar8;
        } while (((int)uVar8 < 4) && (local_84[uVar8] != (BIGNUM *)0x0));
      }
    }
    if ((int)(uVar11 << 0x18) < 0) {
      puVar9 = puVar16 + 4;
      puVar16[2] = uVar15;
      puVar16[3] = (uchar)local_94;
      *puVar16 = '\x03';
      puVar16[1] = '\0';
      puVar16 = puVar9 + local_94;
      memcpy(puVar9,local_98,local_94);
      local_98 = (uchar *)0x0;
      CRYPTO_free(ptr);
    }
    if ((int)(uVar11 << 0x17) < 0) {
      sVar4 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      *puVar16 = (uchar)(sVar4 >> 8);
      sVar4 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      puVar16[1] = (uchar)sVar4;
      __s = *(char **)(*(int *)(param_1 + 0xe4) + 0x14c);
      sVar4 = strlen(__s);
      strncpy((char *)(puVar16 + 2),__s,sVar4);
      sVar4 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
      puVar16 = puVar16 + 2 + sVar4;
    }
    if (pkey == (EVP_PKEY *)0x0) {
      iVar7 = *(int *)(*(int *)(param_1 + 8) + 100);
    }
    else {
      if ((pkey->type != 6) || ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) & 2) != 0))
      {
        if (local_8c == (EVP_MD *)0x0) {
          ERR_put_error(0x14,0x9b,0xfb,"s3_srvr.c",0x7d7);
          uVar3 = 0x28;
LAB_001322a8:
          ctx = (BN_CTX *)0x0;
          ssl3_send_alert(param_1,2,uVar3);
        }
        else {
          if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e < 0) {
            iVar7 = tls12_get_sigandhash(puVar16,pkey,local_8c);
            if (iVar7 == 0) {
              ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",0x7bc);
              uVar3 = 0x50;
              goto LAB_001322a8;
            }
            puVar16 = puVar16 + 2;
          }
          EVP_DigestInit_ex(&EStack_64,local_8c,(ENGINE *)0x0);
          EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
          EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
          EVP_DigestUpdate(&EStack_64,d,sVar10);
          iVar7 = EVP_SignFinal(&EStack_64,puVar16 + 2,&local_88,pkey);
          if (iVar7 != 0) {
            *puVar16 = (uchar)(local_88 >> 8);
            puVar16[1] = (uchar)local_88;
            iVar7 = *(int *)(*(int *)(param_1 + 8) + 100);
            sVar10 = local_88 + 2 + sVar10;
            if (*(int *)(iVar7 + 0x38) << 0x1e < 0) {
              sVar10 = sVar10 + 2;
            }
            goto LAB_00131cdc;
          }
          ERR_put_error(0x14,0x9b,6,"s3_srvr.c",0x7cc);
          ctx = (BN_CTX *)0x0;
        }
LAB_00132270:
        if (local_98 == (uchar *)0x0) goto LAB_001321d4;
LAB_00132276:
        CRYPTO_free(local_98);
        goto LAB_001321d4;
      }
      EVP_MD_CTX_set_flags(&EStack_64,8);
      EVP_DigestInit_ex(&EStack_64,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
      EVP_DigestUpdate(&EStack_64,d,sVar10);
      EVP_DigestFinal_ex(&EStack_64,auStack_4c,&local_88);
      uVar11 = local_88;
      EVP_MD_CTX_set_flags(&EStack_64,8);
      EVP_DigestInit_ex(&EStack_64,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),(ENGINE *)0x0);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
      EVP_DigestUpdate(&EStack_64,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
      EVP_DigestUpdate(&EStack_64,d,sVar10);
      EVP_DigestFinal_ex(&EStack_64,auStack_4c + uVar11,&local_88);
      iVar7 = RSA_sign(0x72,auStack_4c,uVar11 + local_88,puVar16 + 2,&local_90,(pkey->pkey).rsa);
      if (iVar7 < 1) {
        ERR_put_error(0x14,0x9b,4,"s3_srvr.c",0x7ae);
        ctx = (BN_CTX *)0x0;
        goto LAB_00132270;
      }
      *puVar16 = (uchar)(local_90 >> 8);
      puVar16[1] = (uchar)local_90;
      sVar10 = sVar10 + local_90 + 2;
      iVar7 = *(int *)(*(int *)(param_1 + 8) + 100);
    }
LAB_00131cdc:
    (**(code **)(iVar7 + 0x40))(param_1,0xc,sVar10);
LAB_00131ce4:
    *(undefined4 *)(param_1 + 0x34) = 0x2151;
    EVP_MD_CTX_cleanup(&EStack_64);
    uVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x44))(param_1);
    return uVar3;
  }
  if ((int)(uVar11 << 0x1c) < 0) {
    pDVar14 = *(DH **)(iVar12 + 0x24);
    if (pDVar14 == (DH *)0x0) {
      if (*(code **)(iVar12 + 0x28) != (code *)0x0) {
        if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
          uVar3 = 0x400;
        }
        else {
          uVar3 = 0x200;
        }
        pDVar14 = (DH *)(**(code **)(iVar12 + 0x28))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar3);
        if (pDVar14 != (DH *)0x0) {
          iVar7 = *(int *)(param_1 + 0x58);
          goto LAB_00131d12;
        }
      }
      ERR_put_error(0x14,0x9b,0xab,"s3_srvr.c",0x687);
      local_98 = (uchar *)0x0;
      uVar3 = 0x28;
      goto LAB_001322a8;
    }
LAB_00131d12:
    if (*(int *)(iVar7 + 0x348) != 0) {
      iVar7 = 0x68d;
      goto LAB_001321c4;
    }
    dh = DHparams_dup(pDVar14);
    iVar7 = 0x692;
    if (dh != (DH *)0x0) {
      pBVar2 = pDVar14->pub_key;
      *(DH **)(*(int *)(param_1 + 0x58) + 0x348) = dh;
      if (((pBVar2 == (BIGNUM *)0x0) || (pDVar14->priv_key == (BIGNUM *)0x0)) ||
         (*(int *)(param_1 + 0x100) << 0xb < 0)) {
        iVar6 = DH_generate_key(dh);
        iVar7 = 0x69b;
        if (iVar6 != 0) {
          pBVar2 = dh->pub_key;
          goto LAB_00131d5c;
        }
      }
      else {
        pBVar2 = BN_dup(pBVar2);
        dh->pub_key = pBVar2;
        pBVar13 = BN_dup(pDVar14->priv_key);
        pBVar2 = dh->pub_key;
        dh->priv_key = pBVar13;
        if ((pBVar2 != (BIGNUM *)0x0) && (pBVar13 != (BIGNUM *)0x0)) {
LAB_00131d5c:
          pBVar13 = dh->p;
          local_84[1] = dh->g;
          local_84[2] = pBVar2;
          goto LAB_00131b14;
        }
        iVar7 = 0x6a2;
      }
    }
    ERR_put_error(0x14,0x9b,5,"s3_srvr.c",iVar7);
    goto LAB_001321d2;
  }
  if ((uVar11 & 0x80) == 0) {
    if (-1 < (int)(uVar11 << 0x17)) {
      if ((uVar11 & 0x400) == 0) {
        ERR_put_error(0x14,0x9b,0xfa,"s3_srvr.c",0x746);
        uVar3 = 0x28;
        local_98 = (uchar *)0x0;
        goto LAB_001322a8;
      }
      if (((*(BIGNUM **)(param_1 + 0x1a8) == (BIGNUM *)0x0) ||
          (*(BIGNUM **)(param_1 + 0x1ac) == (BIGNUM *)0x0)) ||
         ((*(BIGNUM **)(param_1 + 0x1b0) == (BIGNUM *)0x0 ||
          (pBVar13 = *(BIGNUM **)(param_1 + 0x1a8), pBVar2 = *(BIGNUM **)(param_1 + 0x1ac),
          pBVar1 = *(BIGNUM **)(param_1 + 0x1b0), iVar7 = *(int *)(param_1 + 0x1b4),
          *(int *)(param_1 + 0x1b4) == 0)))) {
        ERR_put_error(0x14,0x9b,0x166,"s3_srvr.c",0x73a);
        goto LAB_001321d2;
      }
      goto LAB_00131e18;
    }
    sVar10 = strlen(*(char **)(*(int *)(param_1 + 0xe4) + 0x14c));
    sVar10 = sVar10 + 2;
    iVar6 = 0;
    local_98 = (uchar *)0x0;
    local_94 = 0;
LAB_00131ff0:
    uVar15 = (uchar)iVar6;
    pBVar13 = (BIGNUM *)0x0;
    local_88 = 0;
    goto LAB_00131b7c;
  }
  src = *(EC_KEY **)(iVar12 + 0x2c);
  if (*(int *)(iVar12 + 0x34) == 0) {
    if (src == (EC_KEY *)0x0) {
      if (*(code **)(iVar12 + 0x30) != (code *)0x0) {
        if ((*(uint *)(iVar6 + 0x20) & 8) == 0) {
          uVar3 = 0x400;
        }
        else {
          uVar3 = 0x200;
        }
        src = (EC_KEY *)(**(code **)(iVar12 + 0x30))(param_1,*(uint *)(iVar6 + 0x20) & 2,uVar3);
        goto LAB_0013217c;
      }
      goto LAB_00132340;
    }
  }
  else {
    iVar7 = tls1_shared_curve(param_1,0xfffffffe);
    if (iVar7 != 0) {
      src = EC_KEY_new_by_curve_name(iVar7);
    }
LAB_0013217c:
    if (src == (EC_KEY *)0x0) {
LAB_00132340:
      ERR_put_error(0x14,0x9b,0x137,"s3_srvr.c",0x6bf);
      local_98 = (uchar *)0x0;
      uVar3 = 0x28;
      goto LAB_001322a8;
    }
    iVar7 = *(int *)(param_1 + 0x58);
  }
  if (*(int *)(iVar7 + 0x34c) != 0) {
    iVar7 = 0x6c5;
LAB_001321c4:
    ERR_put_error(0x14,0x9b,0x44,"s3_srvr.c",iVar7);
    goto LAB_001321d2;
  }
  if (*(int *)(*(int *)(param_1 + 0x98) + 0x34) == 0) {
    src = EC_KEY_dup(src);
    if (src != (EC_KEY *)0x0) {
      iVar7 = *(int *)(param_1 + 0x58);
      goto LAB_00131efa;
    }
    iVar7 = 0x6d1;
LAB_00132318:
    ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",iVar7);
  }
  else {
LAB_00131efa:
    *(EC_KEY **)(iVar7 + 0x34c) = src;
    pEVar5 = EC_KEY_get0_public_key(src);
    if ((((pEVar5 == (EC_POINT *)0x0) ||
         (pBVar2 = EC_KEY_get0_private_key(src), pBVar2 == (BIGNUM *)0x0)) ||
        (*(int *)(param_1 + 0x100) << 0xc < 0)) && (iVar7 = EC_KEY_generate_key(src), iVar7 == 0)) {
      iVar7 = 0x6db;
      goto LAB_00132318;
    }
    group = EC_KEY_get0_group(src);
    if (((group == (EC_GROUP *)0x0) ||
        (pEVar5 = EC_KEY_get0_public_key(src), pEVar5 == (EC_POINT *)0x0)) ||
       (pBVar2 = EC_KEY_get0_private_key(src), pBVar2 == (BIGNUM *)0x0)) {
      iVar7 = 0x6e3;
      goto LAB_00132318;
    }
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) << 0x1e < 0) &&
       (iVar7 = EC_GROUP_get_degree(group), 0xa3 < iVar7)) {
      ERR_put_error(0x14,0x9b,0x136,"s3_srvr.c",0x6ea);
    }
    else {
      EC_GROUP_get_curve_name(group);
      iVar6 = tls1_ec_nid2curve_id();
      if (iVar6 != 0) {
        pEVar5 = EC_KEY_get0_public_key(src);
        sVar10 = EC_POINT_point2oct(group,pEVar5,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                    (BN_CTX *)0x0);
        local_98 = (uchar *)CRYPTO_malloc(sVar10,"s3_srvr.c",0x705);
        ctx = BN_CTX_new();
        if (local_98 == (uchar *)0x0 || ctx == (BN_CTX *)0x0) {
          ERR_put_error(0x14,0x9b,0x41,"s3_srvr.c",0x709);
          goto LAB_00132270;
        }
        pEVar5 = EC_KEY_get0_public_key(src);
        local_94 = EC_POINT_point2oct(group,pEVar5,POINT_CONVERSION_UNCOMPRESSED,local_98,sVar10,ctx
                                     );
        if (local_94 != 0) {
          BN_CTX_free(ctx);
          iVar7 = *(int *)(param_1 + 0x58);
          sVar10 = local_94 + 4;
          local_84[0] = (BIGNUM *)0x0;
          local_84[1] = (BIGNUM *)0x0;
          local_84[2] = (BIGNUM *)0x0;
          local_78 = 0;
          goto LAB_00131ff0;
        }
        ERR_put_error(0x14,0x9b,0x2b,"s3_srvr.c",0x713);
        goto LAB_00132276;
      }
      ERR_put_error(0x14,0x9b,0x13b,"s3_srvr.c",0x6f7);
    }
  }
LAB_001321d2:
  ctx = (BN_CTX *)0x0;
LAB_001321d4:
  BN_CTX_free(ctx);
  EVP_MD_CTX_cleanup(&EStack_64);
  *(undefined4 *)(param_1 + 0x34) = 5;
  return 0xffffffff;
}


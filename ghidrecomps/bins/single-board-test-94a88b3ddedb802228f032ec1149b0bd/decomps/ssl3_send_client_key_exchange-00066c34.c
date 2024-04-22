
undefined4 ssl3_send_client_key_exchange(int *param_1)

{
  uchar uVar1;
  undefined4 uVar2;
  EC_GROUP *group;
  EC_POINT *pEVar3;
  EC_KEY *key;
  size_t sVar4;
  uchar *puVar5;
  BN_CTX *c;
  dh_st *dh;
  char *pcVar6;
  X509 *x;
  EVP_PKEY_CTX *ctx;
  EVP_MD_CTX *ctx_00;
  EVP_MD *type;
  EVP_PKEY *pEVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  uchar *key_00;
  int iVar13;
  int iVar14;
  RSA *rsa;
  code *pcVar15;
  rsa_st *key_01;
  dh_st *dh_00;
  EVP_PKEY *local_2e0;
  uint local_2d8;
  uint uStack_2d4;
  uchar auStack_2d0 [32];
  uchar auStack_2b0 [129];
  undefined local_22f;
  uchar local_22c [520];
  
  if (param_1[0xd] != 0x1180) goto LAB_00066d1a;
  piVar8 = (int *)param_1[0x16];
  iVar14 = *(int *)(param_1[0xf] + 4);
  iVar13 = *(int *)(*(int *)(param_1[2] + 100) + 0x3c);
  uVar9 = *(uint *)(piVar8[0xd1] + 0xc);
  key_00 = (uchar *)(iVar14 + iVar13);
  if ((int)(uVar9 << 0x1f) < 0) {
    iVar10 = *(int *)(param_1[0x30] + 0x98);
    if (iVar10 == 0) {
      iVar13 = 0x99d;
LAB_000672da:
      ERR_put_error(0x14,0x98,0x44,DAT_00067464,iVar13);
    }
    else {
      rsa = *(RSA **)(iVar10 + 0xec);
      if (rsa == (RSA *)0x0) {
        pEVar7 = X509_get_pubkey(*(X509 **)(iVar10 + 0xc));
        if (((pEVar7 == (EVP_PKEY *)0x0) || (pEVar7->type != 6)) ||
           (rsa = (pEVar7->pkey).rsa, rsa == (rsa_st *)0x0)) {
          iVar13 = 0x9ab;
          goto LAB_000672da;
        }
        EVP_PKEY_free(pEVar7);
      }
      local_22c[1] = (uchar)param_1[0x44];
      local_22c[0] = (uchar)((uint)param_1[0x44] >> 8);
      iVar10 = RAND_bytes(local_22c + 2,0x2e);
      if (0 < iVar10) {
        iVar10 = *param_1;
        *(undefined4 *)(param_1[0x30] + 0x10) = 0x30;
        puVar5 = key_00;
        if (0x300 < iVar10) {
          puVar5 = key_00 + 2;
        }
        iVar10 = RSA_public_encrypt(0x30,local_22c,puVar5,rsa,1);
        if (0 < iVar10) {
          iVar11 = *param_1;
          iVar12 = iVar11;
          if (0x300 < iVar11) {
            iVar12 = iVar10 >> 8;
          }
          if (0x300 < iVar11) {
            *(char *)(iVar14 + iVar13) = (char)iVar12;
            key_00[1] = (uchar)iVar10;
            iVar10 = iVar10 + 2;
          }
          iVar13 = param_1[0x30];
          uVar2 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar13 + 0x14,local_22c,0x30);
          *(undefined4 *)(iVar13 + 0x10) = uVar2;
          OPENSSL_cleanse(local_22c,0x30);
LAB_00066d02:
          (**(code **)(*(int *)(param_1[2] + 100) + 0x40))(param_1,0x10,iVar10);
          param_1[0xd] = 0x1181;
LAB_00066d1a:
          uVar2 = (**(code **)(*(int *)(param_1[2] + 100) + 0x44))(param_1);
          return uVar2;
        }
        ERR_put_error(0x14,0x98,0x77,DAT_00067584,0x9c7);
      }
    }
LAB_00066fa8:
    local_2e0 = (EVP_PKEY *)0x0;
  }
  else if ((uVar9 & 0xe) == 0) {
    if ((uVar9 & 0xe0) == 0) {
      if ((int)(uVar9 << 0x16) < 0) {
        x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xd0);
        if ((x == (X509 *)0x0) &&
           (x = *(X509 **)(*(int *)(param_1[0x30] + 0x98) + 0xb4), x == (X509 *)0x0)) {
          ERR_put_error(0x14,0x98,0x14a,DAT_00067464,0xb77);
        }
        else {
          pEVar7 = X509_get_pubkey(x);
          ctx = EVP_PKEY_CTX_new(pEVar7,(ENGINE *)0x0);
          EVP_PKEY_encrypt_init(ctx);
          iVar10 = RAND_bytes(auStack_2d0,0x20);
          if (iVar10 < 1) {
            EVP_PKEY_CTX_free(ctx);
          }
          else {
            if (((*(int *)(param_1[0x16] + 0x358) != 0) &&
                (*(EVP_PKEY **)(*(int *)param_1[0x26] + 4) != (EVP_PKEY *)0x0)) &&
               (iVar10 = EVP_PKEY_derive_set_peer(ctx,*(EVP_PKEY **)(*(int *)param_1[0x26] + 4)),
               iVar10 < 1)) {
              ERR_clear_error();
            }
            ctx_00 = EVP_MD_CTX_create();
            pcVar6 = OBJ_nid2sn(0x329);
            type = EVP_get_digestbyname(pcVar6);
            EVP_DigestInit(ctx_00,type);
            EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xc0),0x20);
            EVP_DigestUpdate(ctx_00,(void *)(param_1[0x16] + 0xa0),0x20);
            EVP_DigestFinal_ex(ctx_00,auStack_2b0,&uStack_2d4);
            EVP_MD_CTX_destroy(ctx_00);
            iVar10 = EVP_PKEY_CTX_ctrl(ctx,-1,0x100,8,8,auStack_2b0);
            if (iVar10 < 0) {
              iVar13 = 0xbaa;
            }
            else {
              *(undefined *)(iVar14 + iVar13) = 0x30;
              local_2d8 = 0xff;
              iVar13 = EVP_PKEY_encrypt(ctx,local_22c,&local_2d8,auStack_2d0,0x20);
              if (-1 < iVar13) {
                if (local_2d8 < 0x80) {
                  key_00[1] = (uchar)local_2d8;
                  puVar5 = key_00 + 2;
                  iVar10 = local_2d8 + 2;
                }
                else {
                  puVar5 = key_00 + 3;
                  key_00[1] = 0x81;
                  key_00[2] = (uchar)local_2d8;
                  iVar10 = local_2d8 + 3;
                }
                memcpy(puVar5,local_22c,local_2d8);
                iVar13 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
                if (0 < iVar13) {
                  *(uint *)param_1[0x16] = *(uint *)param_1[0x16] | 0x10;
                }
                EVP_PKEY_CTX_free(ctx);
                iVar13 = param_1[0x30];
                uVar2 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar13 + 0x14,auStack_2d0,0x20);
                *(undefined4 *)(iVar13 + 0x10) = uVar2;
                EVP_PKEY_free(pEVar7);
                goto LAB_00066d02;
              }
              iVar13 = 0xbb6;
            }
            ERR_put_error(0x14,0x98,0x112,DAT_00067584,iVar13);
          }
        }
      }
      else {
        if ((uVar9 & 0x400) != 0) {
          if ((BIGNUM *)param_1[0x6e] == (BIGNUM *)0x0) {
            iVar13 = 0xbdc;
            goto LAB_0006750e;
          }
          iVar10 = BN_num_bits((BIGNUM *)param_1[0x6e]);
          iVar12 = iVar10 + 0xe;
          if (-1 < iVar10 + 7) {
            iVar12 = iVar10 + 7;
          }
          *(char *)(iVar14 + iVar13) = (char)(iVar12 >> 0xb);
          iVar10 = (iVar12 >> 3) + 2;
          key_00[1] = (uchar)(iVar12 >> 3);
          BN_bn2bin((BIGNUM *)param_1[0x6e],key_00 + 2);
          iVar13 = param_1[0x30];
          if (*(void **)(iVar13 + 0xf0) != (void *)0x0) {
            CRYPTO_free(*(void **)(iVar13 + 0xf0));
            iVar13 = param_1[0x30];
          }
          pcVar6 = BUF_strdup((char *)param_1[0x69]);
          iVar14 = param_1[0x30];
          *(char **)(iVar13 + 0xf0) = pcVar6;
          if (*(int *)(iVar14 + 0xf0) == 0) {
            ERR_put_error(0x14,0x98,0x41,DAT_00067584,0xbe4);
            local_2e0 = (EVP_PKEY *)0x0;
            goto LAB_00066fac;
          }
          iVar13 = SRP_generate_client_master_secret(param_1,iVar14 + 0x14);
          *(int *)(iVar14 + 0x10) = iVar13;
          if (iVar13 < 0) {
            iVar13 = 0x98;
            iVar14 = 0xbed;
            goto LAB_00066fa0;
          }
          goto LAB_00066d02;
        }
        if ((uVar9 & 0x100) == 0) {
          ssl3_send_alert(param_1,2,0x28);
          iVar13 = 0xc4e;
LAB_0006750e:
          local_2e0 = (EVP_PKEY *)0x0;
          ERR_put_error(0x14,0x98,0x44,DAT_00067584,iVar13);
          goto LAB_00066fac;
        }
        pcVar15 = (code *)param_1[0x37];
        if (pcVar15 == (code *)0x0) {
          ERR_put_error(0x14,0x98,0xe0,DAT_00067584,0xc03);
          goto LAB_00066fa8;
        }
        memset(auStack_2b0,0,0x82);
        uVar9 = (*pcVar15)(param_1,*(undefined4 *)(param_1[0x39] + 0x14c),auStack_2b0,0x81,local_22c
                           ,0x204);
        if (uVar9 < 0x101) {
          if (uVar9 == 0) {
            ERR_put_error(0x14,0x98,0xdf,DAT_00067464,0xc12);
          }
          else {
            local_22f = 0;
            sVar4 = strlen((char *)auStack_2b0);
            if (0x80 < sVar4) {
              iVar13 = 0xc19;
              goto LAB_00067202;
            }
            memmove(local_22c + uVar9 + 4,local_22c,uVar9);
            uVar1 = (uchar)(uVar9 >> 8);
            local_22c[0] = uVar1;
            local_22c[1] = (uchar)uVar9;
            memset(local_22c + 2,0,uVar9);
            iVar10 = param_1[0x30];
            (local_22c + 2)[uVar9] = uVar1;
            local_22c[uVar9 + 3] = (uchar)uVar9;
            if (*(void **)(iVar10 + 0x8c) != (void *)0x0) {
              CRYPTO_free(*(void **)(iVar10 + 0x8c));
              iVar10 = param_1[0x30];
            }
            pcVar6 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
            iVar12 = param_1[0x39];
            *(char **)(iVar10 + 0x8c) = pcVar6;
            iVar10 = param_1[0x30];
            if ((*(int *)(iVar12 + 0x14c) == 0) || (*(int *)(iVar10 + 0x8c) != 0)) {
              if (*(void **)(iVar10 + 0x90) != (void *)0x0) {
                CRYPTO_free(*(void **)(iVar10 + 0x90));
                iVar10 = param_1[0x30];
              }
              pcVar6 = BUF_strdup((char *)auStack_2b0);
              iVar12 = param_1[0x30];
              *(char **)(iVar10 + 0x90) = pcVar6;
              if (*(int *)(iVar12 + 0x90) != 0) {
                iVar10 = sVar4 + 2;
                uVar2 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                  (param_1,iVar12 + 0x14,local_22c,uVar9 * 2 + 4);
                *(undefined4 *)(iVar12 + 0x10) = uVar2;
                *(undefined *)(iVar14 + iVar13) = 0;
                key_00[1] = (uchar)sVar4;
                memcpy(key_00 + 2,auStack_2b0,sVar4);
                OPENSSL_cleanse(auStack_2b0,0x82);
                OPENSSL_cleanse(local_22c,0x204);
                goto LAB_00066d02;
              }
              iVar13 = 0xc35;
            }
            else {
              iVar13 = 0xc2c;
            }
            ERR_put_error(0x14,0x98,0x41,DAT_00067584,iVar13);
          }
        }
        else {
          iVar13 = 0xc0e;
LAB_00067202:
          ERR_put_error(0x14,0x98,0x44,DAT_00067464,iVar13);
        }
        OPENSSL_cleanse(auStack_2b0,0x82);
        OPENSSL_cleanse(local_22c,0x204);
        ssl3_send_alert(param_1,2,0x28);
      }
      goto LAB_00066fa8;
    }
    iVar10 = *(int *)(param_1[0x30] + 0x98);
    if (iVar10 == 0) {
      ssl3_send_alert(param_1,2,10);
      iVar13 = 0xab8;
      goto LAB_000674f0;
    }
    key_01 = *(rsa_st **)(iVar10 + 0xf4);
    if (key_01 == (rsa_st *)0x0) {
      local_2e0 = X509_get_pubkey(*(X509 **)(iVar10 + 0x98));
      if (((local_2e0 != (EVP_PKEY *)0x0) && (local_2e0->type == 0x198)) &&
         (key_01 = (local_2e0->pkey).rsa, key_01 != (rsa_st *)0x0)) goto LAB_00066d5a;
      iVar13 = 0xae3;
    }
    else {
      local_2e0 = (EVP_PKEY *)0x0;
LAB_00066d5a:
      group = EC_KEY_get0_group((EC_KEY *)key_01);
      pEVar3 = EC_KEY_get0_public_key((EC_KEY *)key_01);
      if (group != (EC_GROUP *)0x0 && pEVar3 != (EC_POINT *)0x0) {
        key = EC_KEY_new();
        if (key == (EC_KEY *)0x0) {
          ERR_put_error(0x14,0x98,0x41,DAT_00067584,0xaf5);
          goto LAB_00066fac;
        }
        iVar10 = EC_KEY_set_group(key,group);
        if (iVar10 == 0) {
          ERR_put_error(0x14,0x98,0x10,DAT_00067464,0xafa);
LAB_000672fc:
          BN_CTX_free((BN_CTX *)0x0);
        }
        else {
          iVar10 = EC_KEY_generate_key(key);
          iVar12 = 0xb12;
          if (iVar10 == 0) {
LAB_000672ee:
            ERR_put_error(0x14,0x98,0x2b,DAT_00067464,iVar12);
            goto LAB_000672fc;
          }
          iVar10 = EC_GROUP_get_degree(group);
          if (iVar10 < 1) {
            iVar12 = 0xb1e;
            goto LAB_000672ee;
          }
          sVar4 = ECDH_compute_key(key_00,iVar10 + 7 >> 3,pEVar3,key,(KDF *)0x0);
          if ((int)sVar4 < 1) {
            iVar12 = 0xb24;
            goto LAB_000672ee;
          }
          iVar10 = param_1[0x30];
          uVar2 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar10 + 0x14,key_00,sVar4);
          *(undefined4 *)(iVar10 + 0x10) = uVar2;
          memset(key_00,0,sVar4);
          pEVar3 = EC_KEY_get0_public_key(key);
          sVar4 = EC_POINT_point2oct(group,pEVar3,POINT_CONVERSION_UNCOMPRESSED,(uchar *)0x0,0,
                                     (BN_CTX *)0x0);
          puVar5 = (uchar *)CRYPTO_malloc(sVar4,DAT_0006710c,0xb40);
          c = BN_CTX_new();
          if (puVar5 != (uchar *)0x0 && c != (BN_CTX *)0x0) {
            pEVar3 = EC_KEY_get0_public_key(key);
            sVar4 = EC_POINT_point2oct(group,pEVar3,POINT_CONVERSION_UNCOMPRESSED,puVar5,sVar4,c);
            *(char *)(iVar14 + iVar13) = (char)sVar4;
            iVar10 = sVar4 + 1;
            memcpy(key_00 + 1,puVar5,sVar4);
            BN_CTX_free(c);
            CRYPTO_free(puVar5);
            EC_KEY_free(key);
            EVP_PKEY_free(local_2e0);
            goto LAB_00066d02;
          }
          ERR_put_error(0x14,0x98,0x41,DAT_00067464,0xb44);
          BN_CTX_free(c);
          if (puVar5 != (uchar *)0x0) {
            CRYPTO_free(puVar5);
          }
        }
        EC_KEY_free(key);
        goto LAB_00066fb2;
      }
      iVar13 = 0xaef;
    }
    ERR_put_error(0x14,0x98,0x44,DAT_00067464,iVar13);
  }
  else {
    iVar10 = *(int *)(param_1[0x30] + 0x98);
    if (iVar10 == 0) {
      ssl3_send_alert(param_1,2,10);
      iVar13 = 0xa64;
LAB_000674f0:
      local_2e0 = (EVP_PKEY *)0x0;
      ERR_put_error(0x14,0x98,0xf4,DAT_00067584,iVar13);
    }
    else {
      dh_00 = *(dh_st **)(iVar10 + 0xf0);
      if (dh_00 == (dh_st *)0x0) {
        if ((-1 < *(int *)(iVar10 + 4)) &&
           (pEVar7 = X509_get_pubkey(*(X509 **)(iVar10 + *(int *)(iVar10 + 4) * 0x1c + 0xc)),
           pEVar7 != (EVP_PKEY *)0x0)) {
          dh_00 = EVP_PKEY_get1_DH(pEVar7);
          EVP_PKEY_free(pEVar7);
          if (dh_00 != (dh_st *)0x0) {
            piVar8 = (int *)param_1[0x16];
            goto LAB_00066e98;
          }
        }
        iVar14 = 0x971;
        iVar13 = 0x154;
LAB_00066fa0:
        ERR_put_error(0x14,iVar13,0x44,DAT_0006710c,iVar14);
        goto LAB_00066fa8;
      }
LAB_00066e98:
      if (*piVar8 << 0x1b < 0) {
        if ((*(EVP_PKEY **)(*(int *)param_1[0x26] + 4) == (EVP_PKEY *)0x0) ||
           (dh = EVP_PKEY_get1_DH(*(EVP_PKEY **)(*(int *)param_1[0x26] + 4)), dh == (dh_st *)0x0)) {
          iVar14 = 0xa78;
          iVar13 = 0x98;
          goto LAB_00066fa0;
        }
LAB_00066eba:
        sVar4 = DH_compute_key(key_00,dh_00->pub_key,dh);
        if (*(int *)(iVar10 + 0xf0) == 0) {
          DH_free(dh_00);
        }
        if (0 < (int)sVar4) {
          iVar10 = param_1[0x30];
          uVar2 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,iVar10 + 0x14,key_00,sVar4);
          *(undefined4 *)(iVar10 + 0x10) = uVar2;
          memset(key_00,0,sVar4);
          if (*(int *)param_1[0x16] << 0x1b < 0) {
            iVar10 = 0;
          }
          else {
            iVar10 = BN_num_bits(dh->pub_key);
            iVar12 = iVar10 + 0xe;
            if (-1 < iVar10 + 7) {
              iVar12 = iVar10 + 7;
            }
            *(char *)(iVar14 + iVar13) = (char)(iVar12 >> 0xb);
            iVar10 = (iVar12 >> 3) + 2;
            key_00[1] = (uchar)(iVar12 >> 3);
            BN_bn2bin(dh->pub_key,key_00 + 2);
          }
          DH_free(dh);
          goto LAB_00066d02;
        }
        ERR_put_error(0x14,0x98,5,DAT_00067584,0xa92);
        DH_free(dh);
        local_2e0 = (EVP_PKEY *)0x0;
      }
      else {
        dh = DHparams_dup(dh_00);
        if (dh == (dh_st *)0x0) {
          ERR_put_error(0x14,0x98,5,DAT_00067584,0xa7e);
          local_2e0 = (EVP_PKEY *)0x0;
        }
        else {
          iVar12 = DH_generate_key(dh);
          if (iVar12 != 0) goto LAB_00066eba;
          ERR_put_error(0x14,0x98,5,DAT_00067464,0xa82);
          DH_free(dh);
          local_2e0 = (EVP_PKEY *)0x0;
        }
      }
    }
  }
LAB_00066fac:
  BN_CTX_free((BN_CTX *)0x0);
LAB_00066fb2:
  EVP_PKEY_free(local_2e0);
  param_1[0xd] = 5;
  return 0xffffffff;
}


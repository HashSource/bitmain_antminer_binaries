
uint ssl3_get_client_key_exchange(uint *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  EVP_PKEY *a;
  size_t sVar5;
  EVP_PKEY_CTX *ctx;
  BN_CTX *ctx_00;
  dh_st *dh;
  EC_KEY *key;
  EC_GROUP *group;
  EC_POINT *p;
  EC_POINT *src;
  char *pcVar6;
  uint len;
  byte *pbVar7;
  uint uVar8;
  int *piVar9;
  byte *s;
  uint uVar10;
  RSA *rsa;
  EVP_PKEY *pEVar11;
  BIGNUM *pBVar12;
  code *pcVar13;
  rsa_st *dh_00;
  EC_KEY *key_00;
  byte *local_2c8;
  int local_2c4;
  size_t local_2c0;
  int local_2bc;
  int local_2b8;
  size_t local_2b4;
  undefined auStack_2b0 [132];
  byte local_22c [520];
  
  uVar2 = (**(code **)(param_1[2] + 0x30))(param_1,0x2190,0x2191,0x10,0x800,&local_2c4);
  if (local_2c4 == 0) {
    return uVar2;
  }
  uVar8 = param_1[0x16];
  local_2c8 = (byte *)param_1[0x10];
  uVar10 = *(uint *)(*(int *)(uVar8 + 0x344) + 0xc);
  if ((int)(uVar10 << 0x1f) < 0) {
    if (*(int *)(uVar8 + 0x370) == 0) {
      piVar9 = *(int **)(param_1[0x26] + 0x40);
      if (((piVar9 != (int *)0x0) && (*piVar9 == 6)) && (rsa = (RSA *)piVar9[5], rsa != (RSA *)0x0))
      goto LAB_00086ba2;
      iVar3 = 0x88c;
LAB_00086ff4:
      uVar4 = 0x28;
      ERR_put_error(0x14,0x8b,0xa8,DAT_00087008,iVar3);
    }
    else {
      if ((param_1[0x26] == 0) || (rsa = *(RSA **)(param_1[0x26] + 0x1c), rsa == (RSA *)0x0)) {
        ERR_put_error(0x14,0x8b,0xad,DAT_00087008,0x882);
        uVar4 = 0x28;
        goto LAB_00086dba;
      }
LAB_00086ba2:
      uVar8 = uVar2;
      pbVar7 = local_2c8;
      if (0x300 < (int)*param_1) {
        uVar8 = (uint)CONCAT11(*local_2c8,local_2c8[1]);
        pbVar7 = local_2c8 + 2;
        if ((CONCAT11(*local_2c8,local_2c8[1]) + 2 != uVar2) &&
           (uVar8 = uVar2, pbVar7 = local_2c8, -1 < (int)(param_1[0x40] << 0x17))) {
          local_2c8 = local_2c8 + 2;
          ERR_put_error(0x14,0x8b,0xea,DAT_0008746c,0x899);
          uVar4 = 0x32;
          goto LAB_00086dba;
        }
      }
      local_2c8 = pbVar7;
      if (0x2f < (int)uVar8) {
        iVar3 = RAND_pseudo_bytes(local_22c,0x30);
        if (0 < iVar3) {
          uVar2 = RSA_private_decrypt(uVar8,local_2c8,local_2c8,rsa,1);
          ERR_clear_error();
          uVar8 = param_1[0x44];
          bVar1 = (byte)(((uint)*local_2c8 ^ (int)uVar8 >> 8) - 1 >> 0x18) &
                  ~(byte)((int)uVar8 >> 0x1f) &
                  (byte)((uVar8 & 0xff ^ (uint)local_2c8[1]) - 1 >> 0x18);
          if ((int)(param_1[0x40] << 8) < 0) {
            uVar8 = *param_1;
            bVar1 = bVar1 | (byte)(((uint)*local_2c8 ^ (int)uVar8 >> 8) - 1 >> 0x18) &
                            ~(byte)((int)uVar8 >> 0x1f) &
                            (byte)(((uint)local_2c8[1] ^ uVar8 & 0xff) - 1 >> 0x18);
          }
          bVar1 = (char)(bVar1 & (byte)((uVar2 ^ 0x30) - 1 >> 0x18) & ~(byte)(uVar2 >> 0x18)) >> 7;
          iVar3 = 0;
          do {
            local_2c8[iVar3] = local_22c[iVar3] & ~bVar1 | local_2c8[iVar3] & bVar1;
            iVar3 = iVar3 + 1;
          } while (iVar3 != 0x30);
          uVar2 = param_1[0x30];
          uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,uVar2 + 0x14,local_2c8,0x30);
          *(undefined4 *)(uVar2 + 0x10) = uVar4;
          OPENSSL_cleanse(local_2c8,0x30);
          return 1;
        }
        goto LAB_00086ece;
      }
      ERR_put_error(0x14,0x8b,0xea,DAT_0008746c,0x8ab);
      uVar4 = 0x33;
    }
LAB_00086dba:
    ctx_00 = (BN_CTX *)0x0;
    ssl3_send_alert(param_1,2,uVar4);
    EVP_PKEY_free((EVP_PKEY *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
  }
  else {
    if ((uVar10 & 0xe) == 0) {
      if ((uVar10 & 0xe0) != 0) {
        key = EC_KEY_new();
        iVar3 = 0xa28;
        if (key == (EC_KEY *)0x0) {
LAB_00087474:
          ERR_put_error(0x14,0x8b,0x41,DAT_00087524,iVar3);
          goto LAB_00086ece;
        }
        if ((uVar10 & 0x60) == 0) {
          key_00 = *(EC_KEY **)(param_1[0x16] + 0x34c);
        }
        else {
          key_00 = *(EC_KEY **)(*(int *)(param_1[0x26] + 0xcc) + 0x14);
        }
        group = EC_KEY_get0_group(key_00);
        pBVar12 = EC_KEY_get0_private_key(key_00);
        iVar3 = EC_KEY_set_group(key,group);
        if ((iVar3 == 0) || (iVar3 = EC_KEY_set_private_key(key,pBVar12), iVar3 == 0)) {
          ctx_00 = (BN_CTX *)0x0;
          p = (EC_POINT *)0x0;
          pEVar11 = (EVP_PKEY *)0x0;
          ERR_put_error(0x14,0x8b,0x10,DAT_0008746c,0xa3d);
        }
        else {
          p = EC_POINT_new(group);
          if (p == (EC_POINT *)0x0) {
            ERR_put_error(0x14,0x8b,0x41,DAT_0008746c,0xa43);
            ctx_00 = (BN_CTX *)0x0;
            pEVar11 = (EVP_PKEY *)0x0;
          }
          else if (uVar2 == 0) {
            if ((int)(uVar10 << 0x18) < 0) {
              ERR_put_error(0x14,0x8b,0x137,DAT_0008746c,0xa4d);
              pEVar11 = (EVP_PKEY *)0x0;
            }
            else {
              pEVar11 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
              if ((pEVar11 != (EVP_PKEY *)0x0) && (pEVar11->type == 0x198)) {
                src = EC_KEY_get0_public_key((EC_KEY *)(pEVar11->pkey).rsa);
                iVar3 = EC_POINT_copy(p,src);
                ctx_00 = (BN_CTX *)0x0;
                if (iVar3 == 0) {
                  ERR_put_error(0x14,0x8b,0x10,DAT_00087524,0xa63);
                }
                else {
                  uVar2 = 2;
LAB_000870b2:
                  iVar3 = EC_GROUP_get_degree(group);
                  if (iVar3 < 1) {
                    iVar3 = 0xa87;
                  }
                  else {
                    sVar5 = ECDH_compute_key(local_2c8,iVar3 + 7 >> 3,p,key,(KDF *)0x0);
                    if (0 < (int)sVar5) {
                      EVP_PKEY_free(pEVar11);
                      EC_POINT_free(p);
                      EC_KEY_free(key);
                      BN_CTX_free(ctx_00);
                      EC_KEY_free(*(EC_KEY **)(param_1[0x16] + 0x34c));
                      uVar8 = param_1[0x30];
                      iVar3 = *(int *)(param_1[2] + 100);
                      *(undefined4 *)(param_1[0x16] + 0x34c) = 0;
                      uVar4 = (**(code **)(iVar3 + 0xc))(param_1,uVar8 + 0x14,local_2c8,sVar5);
                      *(undefined4 *)(uVar8 + 0x10) = uVar4;
                      OPENSSL_cleanse(local_2c8,sVar5);
                      return uVar2;
                    }
                    iVar3 = 0xa8d;
                  }
                  ERR_put_error(0x14,0x8b,0x2b,DAT_00087524,iVar3);
                }
                goto LAB_000872c0;
              }
              ERR_put_error(0x14,0x8b,0x139,DAT_0008746c,0xa5c);
            }
            ctx_00 = (BN_CTX *)0x0;
            ssl3_send_alert(param_1,2,0x28);
          }
          else {
            ctx_00 = BN_CTX_new();
            if (ctx_00 == (BN_CTX *)0x0) {
              ERR_put_error(0x14,0x8b,0x41,DAT_00087524,0xa6e);
              pEVar11 = (EVP_PKEY *)0x0;
            }
            else {
              pbVar7 = local_2c8 + 1;
              bVar1 = *local_2c8;
              local_2c8 = pbVar7;
              if (bVar1 + 1 == uVar2) {
                iVar3 = EC_POINT_oct2point(group,p,pbVar7,(uint)bVar1,ctx_00);
                if (iVar3 != 0) {
                  uVar2 = 1;
                  pEVar11 = (EVP_PKEY *)0x0;
                  local_2c8 = *(byte **)(param_1[0xf] + 4);
                  goto LAB_000870b2;
                }
                ERR_put_error(0x14,0x8b,0x10,DAT_00087524,0xa7a);
                pEVar11 = (EVP_PKEY *)0x0;
              }
              else {
                ERR_put_error(0x14,0x8b,0x10,DAT_0008746c,0xa76);
                pEVar11 = (EVP_PKEY *)0x0;
              }
            }
          }
        }
LAB_000872c0:
        EVP_PKEY_free(pEVar11);
        EC_POINT_free(p);
        EC_KEY_free(key);
        goto LAB_00086dd2;
      }
      if ((uVar10 & 0x100) != 0) {
        pbVar7 = local_2c8 + 2;
        uVar8 = (uint)CONCAT11(*local_2c8,local_2c8[1]);
        local_2c8 = pbVar7;
        if (uVar8 + 2 == uVar2) {
          if (uVar8 < 0x81) {
            pcVar13 = (code *)param_1[0x38];
            if (pcVar13 == (code *)0x0) {
              ERR_put_error(0x14,0x8b,0xe1,DAT_0008746c,0xab9);
              uVar4 = 0x28;
            }
            else {
              memcpy(auStack_2b0,pbVar7,uVar8);
              memset(auStack_2b0 + uVar8,0,0x81 - uVar8);
              uVar2 = (*pcVar13)(param_1,auStack_2b0,local_22c,0x204);
              OPENSSL_cleanse(auStack_2b0,0x81);
              if (uVar2 < 0x101) {
                if (uVar2 == 0) {
                  ERR_put_error(0x14,0x8b,0xdf,DAT_00087008,0xacf);
                  uVar4 = 0x73;
                }
                else {
                  memmove(local_22c + uVar2 + 4,local_22c,uVar2);
                  bVar1 = (byte)(uVar2 >> 8);
                  local_22c[0] = bVar1;
                  local_22c[1] = (byte)uVar2;
                  memset(local_22c + 2,0,uVar2);
                  uVar8 = param_1[0x30];
                  (local_22c + 2)[uVar2] = bVar1;
                  local_22c[uVar2 + 3] = (byte)uVar2;
                  if (*(void **)(uVar8 + 0x90) != (void *)0x0) {
                    CRYPTO_free(*(void **)(uVar8 + 0x90));
                    uVar8 = param_1[0x30];
                  }
                  pcVar6 = BUF_strdup((char *)local_2c8);
                  uVar10 = param_1[0x30];
                  *(char **)(uVar8 + 0x90) = pcVar6;
                  if (*(int *)(uVar10 + 0x90) == 0) {
                    iVar3 = 0xae1;
                  }
                  else {
                    if (*(void **)(uVar10 + 0x8c) != (void *)0x0) {
                      CRYPTO_free(*(void **)(uVar10 + 0x8c));
                      uVar10 = param_1[0x30];
                    }
                    pcVar6 = BUF_strdup(*(char **)(param_1[0x39] + 0x14c));
                    uVar8 = param_1[0x39];
                    *(char **)(uVar10 + 0x8c) = pcVar6;
                    uVar10 = param_1[0x30];
                    if ((*(int *)(uVar8 + 0x14c) == 0) || (*(int *)(uVar10 + 0x8c) != 0)) {
                      uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                        (param_1,uVar10 + 0x14,local_22c,uVar2 * 2 + 4);
                      *(undefined4 *)(uVar10 + 0x10) = uVar4;
                      OPENSSL_cleanse(local_22c,0x204);
                      return 1;
                    }
                    iVar3 = 0xaea;
                  }
                  uVar4 = 0x28;
                  ERR_put_error(0x14,0x8b,0x41,DAT_00087524,iVar3);
                }
              }
              else {
                ERR_put_error(0x14,0x8b,0x44,DAT_0008746c,0xac8);
                uVar4 = 0x28;
              }
            }
          }
          else {
            ERR_put_error(0x14,0x8b,0x92,DAT_0008746c,0xab4);
            uVar4 = 0x28;
          }
        }
        else {
          uVar4 = 0x28;
          ERR_put_error(0x14,0x8b,0x9f,DAT_00087008,0xaaf);
        }
        OPENSSL_cleanse(local_22c,0x204);
        goto LAB_00086dba;
      }
      if (-1 < (int)(uVar10 << 0x15)) {
        if ((int)(uVar10 << 0x16) < 0) {
          uVar8 = *(uint *)(*(int *)(uVar8 + 0x344) + 0x10);
          local_2c0 = 0x20;
          if ((int)(uVar8 << 0x17) < 0) {
            pEVar11 = *(EVP_PKEY **)(param_1[0x26] + 0xe8);
          }
          else if ((uVar8 & 0x200) == 0) {
            pEVar11 = (EVP_PKEY *)0x0;
          }
          else {
            pEVar11 = *(EVP_PKEY **)(param_1[0x26] + 0x104);
          }
          ctx = EVP_PKEY_CTX_new(pEVar11,(ENGINE *)0x0);
          EVP_PKEY_decrypt_init(ctx);
          pEVar11 = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
          if ((pEVar11 != (EVP_PKEY *)0x0) &&
             (iVar3 = EVP_PKEY_derive_set_peer(ctx,pEVar11), iVar3 < 1)) {
            ERR_clear_error();
          }
          iVar3 = ASN1_get_object(&local_2c8,(long *)&local_2b4,&local_2bc,&local_2b8,uVar2);
          if (((iVar3 == 0x20) && (local_2bc == 0x10)) && (local_2b8 == 0)) {
            iVar3 = EVP_PKEY_decrypt(ctx,local_22c,&local_2c0,local_2c8,local_2b4);
            if (0 < iVar3) {
              uVar2 = param_1[0x30];
              uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                                (param_1,uVar2 + 0x14,local_22c,0x20);
              *(undefined4 *)(uVar2 + 0x10) = uVar4;
              OPENSSL_cleanse(local_22c,0x20);
              iVar3 = EVP_PKEY_CTX_ctrl(ctx,-1,-1,2,2,(void *)0x0);
              if (iVar3 < 1) {
                uVar2 = 1;
              }
              else {
                uVar2 = 2;
              }
              EVP_PKEY_free(pEVar11);
              EVP_PKEY_CTX_free(ctx);
              return uVar2;
            }
            iVar3 = 0xb50;
          }
          else {
            iVar3 = 0xb48;
          }
          ERR_put_error(0x14,0x8b,0x93,DAT_00087008,iVar3);
          EVP_PKEY_free(pEVar11);
          EVP_PKEY_CTX_free(ctx);
          goto LAB_00086ece;
        }
        ERR_put_error(0x14,0x8b,0xf9,DAT_00087524,0xb69);
        uVar4 = 0x28;
        goto LAB_00086dba;
      }
      bVar1 = *local_2c8;
      s = local_2c8 + 2;
      pbVar7 = local_2c8 + 1;
      local_2c8 = s;
      if ((int)uVar2 < (int)(CONCAT11(bVar1,*pbVar7) + 2)) {
        ERR_put_error(0x14,0x8b,0x15b,DAT_0008746c,0xb04);
        uVar4 = 0x32;
        goto LAB_00086dba;
      }
      pBVar12 = BN_bin2bn(s,(uint)CONCAT11(bVar1,*pbVar7),(BIGNUM *)0x0);
      param_1[0x6e] = (uint)pBVar12;
      if (pBVar12 == (BIGNUM *)0x0) {
        ERR_put_error(0x14,0x8b,3,DAT_00087524,0xb08);
      }
      else {
        iVar3 = BN_ucmp(pBVar12,(BIGNUM *)param_1[0x6a]);
        if ((-1 < iVar3) || (*(int *)(param_1[0x6e] + 4) == 0)) {
          ERR_put_error(0x14,0x8b,0x173,DAT_0008746c,0xb0f);
          uVar4 = 0x2f;
          goto LAB_00086dba;
        }
        uVar2 = param_1[0x30];
        if (*(void **)(uVar2 + 0xf0) != (void *)0x0) {
          CRYPTO_free(*(void **)(uVar2 + 0xf0));
          uVar2 = param_1[0x30];
        }
        pcVar6 = BUF_strdup((char *)param_1[0x69]);
        uVar8 = param_1[0x30];
        *(char **)(uVar2 + 0xf0) = pcVar6;
        if (*(int *)(uVar8 + 0xf0) == 0) {
          iVar3 = 0xb16;
          goto LAB_00087474;
        }
        iVar3 = SRP_generate_server_master_secret(param_1,uVar8 + 0x14);
        *(int *)(uVar8 + 0x10) = iVar3;
        if (-1 < iVar3) {
          return 1;
        }
        ERR_put_error(0x14,0x8b,0x44,DAT_00087008,0xb1d);
      }
    }
    else {
      if ((int)uVar2 < 2) {
        if ((int)(uVar10 << 0x1c) < 0) {
          ERR_put_error(0x14,0x8b,0x94,DAT_0008746c,0x90c);
          uVar4 = 0x28;
          goto LAB_00086dba;
        }
        len = uVar2;
        if (uVar2 != 0) goto LAB_00086ccc;
      }
      else {
        pbVar7 = local_2c8 + 1;
        bVar1 = *local_2c8;
        local_2c8 = local_2c8 + 2;
        len = (uint)CONCAT11(bVar1,*pbVar7);
        if (uVar2 != CONCAT11(bVar1,*pbVar7) + 2) {
LAB_00086ccc:
          if (-1 < (int)(param_1[0x40] << 0x18)) {
            ERR_put_error(0x14,0x8b,0x94,DAT_0008746c,0x914);
            goto LAB_00086ece;
          }
          local_2c8 = local_2c8 + -2;
          len = uVar2;
        }
      }
      if (-1 < (int)(uVar10 << 0x1e)) {
        if ((uVar10 & 4) != 0) {
          iVar3 = 4;
          goto LAB_00086d64;
        }
        dh_00 = *(rsa_st **)(uVar8 + 0x348);
        pEVar11 = (EVP_PKEY *)0x0;
        if (dh_00 != (rsa_st *)0x0) goto LAB_00086d88;
        iVar3 = 0x92c;
LAB_00086daa:
        uVar4 = 0x28;
        ERR_put_error(0x14,0x8b,0xab,DAT_00087008,iVar3);
        goto LAB_00086dba;
      }
      iVar3 = 3;
LAB_00086d64:
      pEVar11 = *(EVP_PKEY **)(param_1[0x26] + iVar3 * 0x1c + 0x40);
      if (((pEVar11 == (EVP_PKEY *)0x0) || (pEVar11->type != 0x1c)) ||
         (dh_00 = (pEVar11->pkey).rsa, dh_00 == (rsa_st *)0x0)) {
        iVar3 = 0x925;
        goto LAB_00086ff4;
      }
LAB_00086d88:
      if (uVar2 == 0) {
        a = X509_get_pubkey(*(X509 **)(param_1[0x30] + 0x9c));
        if (((a == (EVP_PKEY *)0x0) || (iVar3 = EVP_PKEY_cmp_parameters(a,pEVar11), iVar3 != 1)) ||
           (dh = EVP_PKEY_get1_DH(a), dh == (dh_st *)0x0)) {
          iVar3 = 0x93b;
          goto LAB_00086daa;
        }
        EVP_PKEY_free(a);
        pBVar12 = dh->pub_key;
      }
      else {
        dh = (dh_st *)0x0;
        pBVar12 = BN_bin2bn(local_2c8,len,(BIGNUM *)0x0);
      }
      if (pBVar12 == (BIGNUM *)0x0) {
        ERR_put_error(0x14,0x8b,0x82,DAT_0008746c,0x943);
      }
      else {
        sVar5 = DH_compute_key(local_2c8,pBVar12,(DH *)dh_00);
        if (0 < (int)sVar5) {
          DH_free(*(DH **)(param_1[0x16] + 0x348));
          *(undefined4 *)(param_1[0x16] + 0x348) = 0;
          if (dh == (dh_st *)0x0) {
            uVar2 = 1;
            BN_clear_free(pBVar12);
          }
          else {
            uVar2 = 2;
            DH_free(dh);
          }
          uVar8 = param_1[0x30];
          uVar4 = (**(code **)(*(int *)(param_1[2] + 100) + 0xc))
                            (param_1,uVar8 + 0x14,local_2c8,sVar5);
          *(undefined4 *)(uVar8 + 0x10) = uVar4;
          OPENSSL_cleanse(local_2c8,sVar5);
          return uVar2;
        }
        ERR_put_error(0x14,0x8b,5,DAT_0008746c,0x94a);
        BN_clear_free(pBVar12);
      }
    }
LAB_00086ece:
    ctx_00 = (BN_CTX *)0x0;
    EVP_PKEY_free((EVP_PKEY *)0x0);
    EC_POINT_free((EC_POINT *)0x0);
  }
LAB_00086dd2:
  BN_CTX_free(ctx_00);
  param_1[0xd] = 5;
  return 0xffffffff;
}



undefined4 tls_process_key_exchange(int param_1,int *param_2)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  char cVar4;
  undefined1 uVar5;
  EVP_PKEY *pEVar6;
  char *pcVar7;
  uint uVar8;
  void *pvVar9;
  uchar *puVar10;
  uint uVar11;
  int iVar12;
  uint len;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uchar *puVar16;
  BIGNUM *pBVar17;
  int iVar18;
  uint uVar19;
  undefined1 *puVar20;
  uint uVar21;
  BIGNUM *a;
  EVP_MD_CTX *ctx;
  uchar *puVar22;
  BIGNUM *a_00;
  int iVar23;
  uchar *puVar24;
  undefined4 uVar25;
  DH *local_44;
  EVP_PKEY_CTX *local_34;
  EVP_MD *local_30;
  void *local_2c [2];
  
  iVar23 = *param_2;
  uVar15 = *(uint *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x10);
  uVar19 = param_2[1];
  local_34 = (EVP_PKEY_CTX *)0x0;
  EVP_PKEY_free(*(EVP_PKEY **)(*(int *)(param_1 + 0x7c) + 0x358));
  *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x358) = 0;
  if ((uVar15 & 0x1c8) == 0) goto LAB_000fac94;
  if ((uint)param_2[1] < 2) {
LAB_000facf0:
    ossl_statem_fatal(param_1,0x32,0x1a5,0x9f,"ssl/statem/statem_clnt.c",0x7d2);
  }
  else {
    puVar20 = (undefined1 *)*param_2;
    uVar11 = param_2[1] - 2;
    uVar14 = (uint)CONCAT11(*puVar20,puVar20[1]);
    if (uVar11 < uVar14) goto LAB_000facf0;
    *param_2 = (int)(puVar20 + 2 + uVar14);
    param_2[1] = uVar11 - uVar14;
    if (0x80 < uVar14) {
      ossl_statem_fatal(param_1,0x28,0x1a5,0x92,"ssl/statem/statem_clnt.c",0x7df);
      goto LAB_000fad0c;
    }
    if (uVar14 == 0) {
      CRYPTO_free(*(void **)(*(int *)(param_1 + 0x474) + 400));
      *(undefined4 *)(*(int *)(param_1 + 0x474) + 400) = 0;
    }
    else {
      iVar18 = *(int *)(param_1 + 0x474);
      CRYPTO_free(*(void **)(iVar18 + 400));
      iVar12 = CRYPTO_strndup(puVar20 + 2,uVar14,"ssl/statem/../packet_local.h",0x1e5);
      *(int *)(iVar18 + 400) = iVar12;
      if (iVar12 == 0) {
        ossl_statem_fatal(param_1,0x50,0x1a5,0x44,"ssl/statem/statem_clnt.c",0x7e9);
        goto LAB_000fad0c;
      }
    }
LAB_000fac94:
    if ((uVar15 & 0x48) == 0) {
      pvVar9 = (void *)(uVar15 & 0x20);
      if (pvVar9 == (void *)0x0) {
        if ((uVar15 & 0x102) == 0) {
          if ((uVar15 & 0x84) == 0) {
            if (uVar15 != 0) {
              ossl_statem_fatal(param_1,10,0x16d,0xf4,"ssl/statem/statem_clnt.c",0x8ff);
              ctx = (EVP_MD_CTX *)0x0;
              goto LAB_000fad10;
            }
            goto LAB_000facb8;
          }
          iVar12 = param_2[1];
          if (iVar12 != 0) {
            pcVar7 = (char *)*param_2;
            cVar4 = *pcVar7;
            *param_2 = (int)(pcVar7 + 1);
            param_2[1] = iVar12 - 1U;
            if (1 < iVar12 - 1U) {
              cVar2 = pcVar7[1];
              cVar1 = pcVar7[2];
              *param_2 = (int)(pcVar7 + 3);
              param_2[1] = iVar12 + -3;
              if (cVar4 == '\x03') {
                iVar12 = tls1_check_group_id(param_1,CONCAT11(cVar2,cVar1),1);
                if (iVar12 != 0) {
                  iVar18 = *(int *)(param_1 + 0x7c);
                  iVar12 = ssl_generate_param_group(CONCAT11(cVar2,cVar1));
                  *(int *)(iVar18 + 0x358) = iVar12;
                  if (iVar12 == 0) {
                    ossl_statem_fatal(param_1,0x50,0x1a4,0x13a,"ssl/statem/statem_clnt.c",0x8af);
                    goto LAB_000fad0c;
                  }
                  if (param_2[1] != 0) {
                    uVar14 = param_2[1] - 1;
                    uVar11 = (uint)*(byte *)*param_2;
                    if (uVar11 <= uVar14) {
                      *param_2 = (int)((byte *)*param_2 + uVar11 + 1);
                      param_2[1] = uVar14 - uVar11;
                      iVar12 = EVP_PKEY_set1_tls_encodedpoint
                                         (*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x358));
                      if (iVar12 == 0) {
                        ossl_statem_fatal(param_1,0x2f,0x1a4,0x132,"ssl/statem/statem_clnt.c",0x8bd)
                        ;
                        goto LAB_000fad0c;
                      }
                      iVar12 = *(int *)(param_1 + 0x7c);
                      iVar18 = *(int *)(*(int *)(iVar12 + 0x210) + 0x14);
                      if ((-1 < iVar18 << 0x1c) && (-1 < iVar18 << 0x1f)) goto LAB_000facba;
LAB_000faf22:
                      pEVar6 = (EVP_PKEY *)
                               X509_get0_pubkey(*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x19c));
                      if (pEVar6 == (EVP_PKEY *)0x0) goto LAB_000facb8;
                      uVar15 = param_2[1];
                      ctx = (EVP_MD_CTX *)0x0;
                      local_30 = (EVP_MD *)0x0;
                      uVar11 = uVar19 - uVar15;
                      if ((uVar19 < uVar11) || ((int)uVar11 < 0)) {
                        uVar25 = 0x914;
                        uVar13 = 0x44;
                        goto LAB_000fb14a;
                      }
                      if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1e < 0) {
                        if (uVar15 < 2) {
                          ossl_statem_fatal(param_1,0x32,0x16d,0xa0,"ssl/statem/statem_clnt.c",0x91d
                                           );
                          goto LAB_000fad10;
                        }
                        puVar20 = (undefined1 *)*param_2;
                        uVar3 = *puVar20;
                        uVar5 = puVar20[1];
                        param_2[1] = uVar15 - 2;
                        *param_2 = (int)(puVar20 + 2);
                        iVar12 = tls12_check_peer_sigalg(param_1,CONCAT11(uVar3,uVar5),pEVar6);
                        if (iVar12 < 1) goto LAB_000fad10;
LAB_000faf84:
                        iVar12 = tls1_lookup_md(*(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x278),
                                                &local_30);
                        if (iVar12 != 0) {
                          if (1 < (uint)param_2[1]) {
                            puVar20 = (undefined1 *)*param_2;
                            uVar15 = param_2[1] - 2;
                            uVar19 = (uint)CONCAT11(*puVar20,puVar20[1]);
                            if (uVar19 <= uVar15) {
                              iVar12 = uVar15 - uVar19;
                              *param_2 = (int)(puVar20 + 2 + uVar19);
                              param_2[1] = iVar12;
                              if (iVar12 == 0) {
                                iVar12 = EVP_PKEY_size(pEVar6);
                                if (iVar12 < 0) {
                                  ossl_statem_fatal(param_1,0x50,0x16d,0x44,
                                                    "ssl/statem/statem_clnt.c",0x93e);
                                  ctx = (EVP_MD_CTX *)0x0;
                                }
                                else {
                                  ctx = (EVP_MD_CTX *)EVP_MD_CTX_new();
                                  if (ctx == (EVP_MD_CTX *)0x0) {
                                    ossl_statem_fatal(param_1,0x50,0x16d,0x41,
                                                      "ssl/statem/statem_clnt.c",0x94f);
                                  }
                                  else {
                                    iVar12 = EVP_DigestVerifyInit
                                                       (ctx,&local_34,local_30,(ENGINE *)0x0,pEVar6)
                                    ;
                                    if (iVar12 < 1) {
                                      uVar13 = 0x955;
                                    }
                                    else {
                                      iVar12 = *(int *)(*(int *)(param_1 + 0x7c) + 0x278);
                                      if (((iVar12 == 0) || (*(int *)(iVar12 + 0x10) != 0x390)) ||
                                         ((iVar12 = RSA_pkey_ctx_ctrl(local_34,0xffffffff,0x1001,6,0
                                                                     ), 0 < iVar12 &&
                                          (iVar12 = RSA_pkey_ctx_ctrl(local_34,0x18,0x1002,
                                                                      0xffffffff,0), 0 < iVar12))))
                                      {
                                        iVar23 = construct_key_exchange_tbs
                                                           (param_1,local_2c,iVar23,uVar11);
                                        if (iVar23 != 0) {
                                          EVP_DigestVerify(ctx,puVar20 + 2,uVar19,local_2c[0],iVar23
                                                          );
                                          CRYPTO_free(local_2c[0]);
                                          EVP_MD_CTX_free(ctx);
                                          return 3;
                                        }
                                        goto LAB_000fad10;
                                      }
                                      uVar13 = 0x95d;
                                    }
                                    ossl_statem_fatal(param_1,0x50,0x16d,6,
                                                      "ssl/statem/statem_clnt.c",uVar13);
                                  }
                                }
                                goto LAB_000fad10;
                              }
                            }
                          }
                          uVar25 = 0x938;
                          uVar13 = 0x9f;
                          goto LAB_000fb14a;
                        }
                        uVar13 = 0x92c;
                      }
                      else {
                        iVar12 = tls1_set_peer_legacy_sigalg(param_1,pEVar6);
                        if (iVar12 != 0) goto LAB_000faf84;
                        uVar13 = 0x926;
                      }
                      ctx = (EVP_MD_CTX *)0x0;
                      ossl_statem_fatal(param_1,0x50,0x16d,0x44,"ssl/statem/statem_clnt.c",uVar13);
                      goto LAB_000fad10;
                    }
                  }
                  ossl_statem_fatal(param_1,0x32,0x1a4,0x9f,"ssl/statem/statem_clnt.c",0x8b5);
                  goto LAB_000fad0c;
                }
              }
              ossl_statem_fatal(param_1,0x2f,0x1a4,0x17a,"ssl/statem/statem_clnt.c",0x8a9);
              goto LAB_000fad0c;
            }
          }
          ossl_statem_fatal(param_1,0x32,0x1a4,0xa0,"ssl/statem/statem_clnt.c",0x89f);
        }
        else {
          local_2c[0] = pvVar9;
          if (1 < (uint)param_2[1]) {
            puVar20 = (undefined1 *)*param_2;
            uVar14 = param_2[1] - 2;
            puVar22 = puVar20 + 2;
            uVar11 = (uint)CONCAT11(*puVar20,puVar20[1]);
            if (uVar11 <= uVar14) {
              uVar14 = uVar14 - uVar11;
              puVar16 = puVar22 + uVar11;
              param_2[1] = uVar14;
              *param_2 = (int)puVar16;
              if (1 < uVar14) {
                uVar21 = (uint)CONCAT11(puVar22[uVar11],puVar16[1]);
                if (uVar21 <= uVar14 - 2) {
                  uVar14 = (uVar14 - 2) - uVar21;
                  puVar16 = puVar16 + 2;
                  puVar10 = puVar16 + uVar21;
                  *param_2 = (int)puVar10;
                  param_2[1] = uVar14;
                  if (1 < uVar14) {
                    uVar8 = (uint)CONCAT11(puVar16[uVar21],puVar10[1]);
                    if (uVar8 <= uVar14 - 2) {
                      *param_2 = (int)(puVar10 + 2 + uVar8);
                      param_2[1] = (uVar14 - 2) - uVar8;
                      pEVar6 = EVP_PKEY_new();
                      local_44 = DH_new();
                      if (local_44 == (DH *)0x0 || pEVar6 == (EVP_PKEY *)0x0) {
                        a = (BIGNUM *)0x0;
                        pBVar17 = (BIGNUM *)0x0;
                        a_00 = (BIGNUM *)0x0;
                        ossl_statem_fatal(param_1,0x50,0x1a3,0x41,"ssl/statem/statem_clnt.c",0x83e);
                      }
                      else {
                        a_00 = BN_bin2bn(puVar22,uVar11,(BIGNUM *)0x0);
                        pBVar17 = BN_bin2bn(puVar16,uVar21,(BIGNUM *)0x0);
                        a = BN_bin2bn(puVar10 + 2,uVar8,(BIGNUM *)0x0);
                        if (a == (BIGNUM *)0x0 ||
                            (pBVar17 == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0)) {
                          uVar13 = 0x84a;
LAB_000fb374:
                          ossl_statem_fatal(param_1,0x50,0x1a3,3,"ssl/statem/statem_clnt.c",uVar13);
                        }
                        else {
                          iVar12 = BN_is_zero();
                          if (iVar12 == 0) {
                            iVar12 = DH_set0_pqg(local_44,a_00,0,pBVar17);
                            if (iVar12 == 0) {
                              uVar13 = 0x857;
                              goto LAB_000fb374;
                            }
                            iVar12 = DH_check_params(local_44,local_2c);
                            if ((iVar12 == 0) || (local_2c[0] != (void *)0x0)) {
                              pBVar17 = (BIGNUM *)0x0;
                              ossl_statem_fatal(param_1,0x2f,0x1a3,0x66,"ssl/statem/statem_clnt.c",
                                                0x85e);
                              a_00 = (BIGNUM *)0x0;
                            }
                            else {
                              iVar12 = DH_set0_key(local_44,a,0);
                              if (iVar12 == 0) {
                                ossl_statem_fatal(param_1,0x50,0x1a3,3,"ssl/statem/statem_clnt.c",
                                                  0x864);
                                pBVar17 = (BIGNUM *)0x0;
                                a_00 = (BIGNUM *)0x0;
                              }
                              else {
                                iVar12 = EVP_PKEY_assign(pEVar6,0x1c,local_44);
                                if (iVar12 == 0) {
                                  ossl_statem_fatal(param_1,0x50,0x1a3,6,"ssl/statem/statem_clnt.c",
                                                    0x86b);
                                  pBVar17 = (BIGNUM *)0x0;
                                  a = (BIGNUM *)0x0;
                                  a_00 = (BIGNUM *)0x0;
                                }
                                else {
                                  uVar13 = EVP_PKEY_security_bits(pEVar6);
                                  iVar12 = ssl_security(param_1,0x40007,uVar13,0,pEVar6);
                                  if (iVar12 != 0) {
                                    iVar12 = *(int *)(param_1 + 0x7c);
                                    *(EVP_PKEY **)(iVar12 + 0x358) = pEVar6;
                                    uVar11 = *(uint *)(*(int *)(iVar12 + 0x210) + 0x14);
                                    goto joined_r0x000faf1e;
                                  }
                                  ossl_statem_fatal(param_1,0x28,0x1a3,0x18a,
                                                    "ssl/statem/statem_clnt.c",0x873);
                                  pBVar17 = (BIGNUM *)0x0;
                                  a = (BIGNUM *)0x0;
                                  a_00 = (BIGNUM *)0x0;
                                  local_44 = (DH *)0x0;
                                }
                              }
                            }
                          }
                          else {
                            ossl_statem_fatal(param_1,0x2f,0x1a3,0x66,"ssl/statem/statem_clnt.c",
                                              0x851);
                          }
                        }
                      }
                      BN_free(a_00);
                      BN_free(pBVar17);
                      BN_free(a);
                      DH_free(local_44);
                      EVP_PKEY_free(pEVar6);
                      goto LAB_000fad0c;
                    }
                  }
                }
              }
            }
          }
          ossl_statem_fatal(param_1,0x32,0x1a3,0x9f,"ssl/statem/statem_clnt.c",0x835);
        }
      }
      else {
        if (1 < (uint)param_2[1]) {
          puVar20 = (undefined1 *)*param_2;
          uVar14 = param_2[1] - 2;
          puVar22 = puVar20 + 2;
          uVar11 = (uint)CONCAT11(*puVar20,puVar20[1]);
          if (uVar11 <= uVar14) {
            uVar14 = uVar14 - uVar11;
            puVar16 = puVar22 + uVar11;
            param_2[1] = uVar14;
            *param_2 = (int)puVar16;
            if (1 < uVar14) {
              uVar21 = (uint)CONCAT11(puVar22[uVar11],puVar16[1]);
              if (uVar21 <= uVar14 - 2) {
                puVar16 = puVar16 + 2;
                iVar12 = (uVar14 - 2) - uVar21;
                param_2[1] = iVar12;
                *param_2 = (int)(puVar16 + uVar21);
                if (iVar12 != 0) {
                  uVar14 = (uint)puVar16[uVar21];
                  if (uVar14 <= iVar12 - 1U) {
                    uVar8 = (iVar12 - 1U) - uVar14;
                    puVar10 = puVar16 + uVar21 + 1;
                    puVar24 = puVar10 + uVar14;
                    param_2[1] = uVar8;
                    *param_2 = (int)puVar24;
                    if (1 < uVar8) {
                      len = (uint)CONCAT11(puVar10[uVar14],puVar24[1]);
                      if (len <= uVar8 - 2) {
                        *param_2 = (int)(puVar24 + 2 + len);
                        param_2[1] = (uVar8 - 2) - len;
                        pBVar17 = BN_bin2bn(puVar22,uVar11,(BIGNUM *)0x0);
                        *(BIGNUM **)(param_1 + 0x620) = pBVar17;
                        if (pBVar17 != (BIGNUM *)0x0) {
                          pBVar17 = BN_bin2bn(puVar16,uVar21,(BIGNUM *)0x0);
                          *(BIGNUM **)(param_1 + 0x624) = pBVar17;
                          if (pBVar17 != (BIGNUM *)0x0) {
                            pBVar17 = BN_bin2bn(puVar10,uVar14,(BIGNUM *)0x0);
                            *(BIGNUM **)(param_1 + 0x628) = pBVar17;
                            if (pBVar17 != (BIGNUM *)0x0) {
                              pBVar17 = BN_bin2bn(puVar24 + 2,len,(BIGNUM *)0x0);
                              *(BIGNUM **)(param_1 + 0x62c) = pBVar17;
                              if (pBVar17 != (BIGNUM *)0x0) {
                                iVar12 = srp_verify_server_param(param_1);
                                if (iVar12 != 0) {
                                  iVar12 = *(int *)(param_1 + 0x7c);
                                  uVar11 = *(uint *)(*(int *)(iVar12 + 0x210) + 0x14);
joined_r0x000faf1e:
                                  if ((uVar11 & 3) != 0) goto LAB_000faf22;
                                  goto LAB_000facba;
                                }
                                goto LAB_000fad0c;
                              }
                            }
                          }
                        }
                        ossl_statem_fatal(param_1,0x50,0x1a6,3,"ssl/statem/statem_clnt.c",0x811);
                        goto LAB_000fad0c;
                      }
                    }
                  }
                }
              }
            }
          }
        }
        ossl_statem_fatal(param_1,0x32,0x1a6,0x9f,"ssl/statem/statem_clnt.c",0x7ff);
      }
    }
    else {
LAB_000facb8:
      iVar12 = *(int *)(param_1 + 0x7c);
LAB_000facba:
      if (((*(uint *)(*(int *)(iVar12 + 0x210) + 0x14) & 0x44) == 0) && ((uVar15 & 0x1c8) == 0)) {
        iVar23 = ssl3_check_cert_and_algorithm(param_1);
        ctx = (EVP_MD_CTX *)0x0;
        if (iVar23 != 0) {
          ossl_statem_fatal(param_1,0x32,0x16d,0x186,"ssl/statem/statem_clnt.c",0x979);
        }
        goto LAB_000fad10;
      }
      if (param_2[1] == 0) {
        return 3;
      }
      uVar25 = 0x981;
      uVar13 = 0x99;
LAB_000fb14a:
      ossl_statem_fatal(param_1,0x32,0x16d,uVar13,"ssl/statem/statem_clnt.c",uVar25);
    }
  }
LAB_000fad0c:
  ctx = (EVP_MD_CTX *)0x0;
LAB_000fad10:
  EVP_MD_CTX_free(ctx);
  return 0;
}


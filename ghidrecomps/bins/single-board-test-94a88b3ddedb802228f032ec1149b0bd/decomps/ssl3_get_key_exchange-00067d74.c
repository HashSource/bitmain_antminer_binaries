
DH * ssl3_get_key_exchange(int param_1)

{
  uchar uVar1;
  uchar uVar2;
  DH *pDVar3;
  char *pcVar4;
  undefined4 uVar5;
  BIGNUM *pBVar6;
  RSA *r;
  undefined *puVar7;
  DH *pkey;
  EC_GROUP *pEVar8;
  DH *p;
  int iVar9;
  int iVar10;
  undefined *siglen;
  undefined *d;
  uint uVar11;
  uint uVar12;
  uchar *puVar13;
  uint uVar14;
  size_t cnt;
  uchar *puVar15;
  DH *local_e4;
  DH *local_e0;
  DH *local_dc;
  undefined4 local_d4;
  int local_d0;
  EVP_MD *local_cc;
  uint local_c8;
  EVP_MD_CTX EStack_c4;
  uchar auStack_ac [136];
  
  local_cc = (EVP_MD *)0x0;
  EVP_MD_CTX_init(&EStack_c4);
  pDVar3 = (DH *)(**(code **)(*(int *)(param_1 + 8) + 0x30))
                           (param_1,0x1140,0x1141,0xffffffff,*(undefined4 *)(param_1 + 0x108),
                            &local_d0);
  if (local_d0 == 0) {
    return pDVar3;
  }
  iVar10 = *(int *)(param_1 + 0x58);
  uVar11 = *(uint *)(*(int *)(iVar10 + 0x344) + 0xc);
  if (*(int *)(iVar10 + 0x340) == 0xc) {
    iVar10 = *(int *)(param_1 + 0xc0);
    d = *(undefined **)(param_1 + 0x40);
    iVar9 = *(int *)(iVar10 + 0x98);
    if (iVar9 == 0) {
      uVar5 = ssl_sess_cert_new();
      *(undefined4 *)(iVar10 + 0x98) = uVar5;
    }
    else {
      if (*(RSA **)(iVar9 + 0xec) != (RSA *)0x0) {
        RSA_free(*(RSA **)(iVar9 + 0xec));
        iVar9 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
        *(undefined4 *)(iVar9 + 0xec) = 0;
      }
      if (*(DH **)(iVar9 + 0xf0) != (DH *)0x0) {
        DH_free(*(DH **)(iVar9 + 0xf0));
        iVar9 = *(int *)(*(int *)(param_1 + 0xc0) + 0x98);
        *(undefined4 *)(iVar9 + 0xf0) = 0;
      }
      if (*(EC_KEY **)(iVar9 + 0xf4) != (EC_KEY *)0x0) {
        EC_KEY_free(*(EC_KEY **)(iVar9 + 0xf4));
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc0) + 0x98) + 0xf4) = 0;
      }
    }
    local_d4 = 0x32;
    iVar10 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
    uVar12 = *(uint *)(iVar10 + 0x10);
    if ((uVar11 & 0x100) != 0) {
      if ((int)pDVar3 < 2) {
        ERR_put_error(0x14,0x8d,0xa0,DAT_000688d4,0x5b7);
      }
      else {
        uVar11 = (uint)CONCAT11(*d,d[1]);
        if (uVar11 < 0x81) {
          if ((int)&pDVar3[-1].field_0x4a < (int)uVar11) {
            ERR_put_error(0x14,0x8d,0x13c,DAT_000688d4,0x5c9);
          }
          else {
            memcpy(auStack_ac,d + 2,uVar11);
            memset(auStack_ac + uVar11,0,0x81 - uVar11);
            iVar10 = *(int *)(param_1 + 0xe4);
            if (*(void **)(iVar10 + 0x14c) != (void *)0x0) {
              CRYPTO_free(*(void **)(iVar10 + 0x14c));
              iVar10 = *(int *)(param_1 + 0xe4);
            }
            pDVar3 = (DH *)((int)pDVar3 - (uVar11 + 2));
            pcVar4 = BUF_strdup((char *)auStack_ac);
            iVar9 = *(int *)(param_1 + 0xe4);
            *(char **)(iVar10 + 0x14c) = pcVar4;
            if (*(int *)(iVar9 + 0x14c) != 0) {
LAB_00067eaa:
              pkey = pDVar3;
              if (pDVar3 == (DH *)0x0) goto LAB_00067eb2;
              iVar10 = 0x99;
              iVar9 = 1999;
              goto LAB_000682c8;
            }
            local_d4 = 0x28;
            ERR_put_error(0x14,0x8d,0x41,DAT_000688d4,0x5da);
          }
        }
        else {
          local_d4 = 0x28;
          ERR_put_error(0x14,0x8d,0x92,DAT_000688d4,0x5c4);
        }
      }
      local_dc = (DH *)0x0;
      local_e0 = (DH *)0x0;
      local_e4 = (DH *)0x0;
      pkey = (DH *)0x0;
      p = (DH *)0x0;
      goto LAB_000682ac;
    }
    if ((uVar11 & 0x400) != 0) {
      if ((int)pDVar3 < 2) {
        iVar10 = 0x5e6;
LAB_000686f8:
        iVar9 = 0xa0;
        pcVar4 = DAT_000688d4;
LAB_00068382:
        local_e0 = (DH *)0x0;
        ERR_put_error(0x14,0x8d,iVar9,pcVar4,iVar10);
        pkey = local_e0;
        p = local_e0;
        local_e4 = local_e0;
        local_dc = local_e0;
        goto LAB_000682ac;
      }
      puVar13 = d + 2;
      uVar11 = (uint)CONCAT11(*d,d[1]);
      if ((int)&pDVar3[-1].field_0x4a < (int)uVar11) {
        iVar10 = 0x5ec;
        iVar9 = 0x15e;
        pcVar4 = DAT_000688d4;
        goto LAB_00068382;
      }
      local_e4 = (DH *)BN_bin2bn(puVar13,uVar11,(BIGNUM *)0x0);
      iVar10 = 0x5f2;
      *(DH **)(param_1 + 0x1a8) = local_e4;
      if (local_e4 == (DH *)0x0) {
LAB_0006879a:
        iVar9 = 3;
        goto LAB_000687a4;
      }
      if ((int)((int)pDVar3 - (uVar11 + 2)) < 2) {
        iVar10 = 0x5f8;
        goto LAB_000686f8;
      }
      puVar15 = puVar13 + uVar11 + 2;
      uVar14 = (uint)CONCAT11(puVar13[uVar11],puVar13[uVar11 + 1]);
      if ((int)((int)pDVar3 - (uVar11 + 4)) < (int)uVar14) {
        iVar10 = 0x600;
        iVar9 = 0x15d;
        pcVar4 = DAT_000688d4;
        goto LAB_00068382;
      }
      iVar9 = uVar11 + 4 + uVar14;
      pBVar6 = BN_bin2bn(puVar15,uVar14,(BIGNUM *)0x0);
      *(BIGNUM **)(param_1 + 0x1ac) = pBVar6;
      if (pBVar6 == (BIGNUM *)0x0) {
        iVar10 = 0x606;
        local_e4 = (DH *)0x0;
        goto LAB_0006879a;
      }
      if ((int)pDVar3 - iVar9 < 1) {
        iVar10 = 0x60c;
        goto LAB_000686f8;
      }
      uVar11 = (uint)puVar15[uVar14];
      iVar9 = iVar9 + 1;
      puVar15 = puVar15 + uVar14 + 1;
      if ((int)pDVar3 - iVar9 < (int)uVar11) {
        iVar9 = 0x615;
        iVar10 = 0x15f;
        goto LAB_000682c8;
      }
      iVar9 = iVar9 + uVar11;
      local_e4 = (DH *)BN_bin2bn(puVar15,uVar11,(BIGNUM *)0x0);
      iVar10 = 0x61b;
      *(DH **)(param_1 + 0x1b0) = local_e4;
      if (local_e4 == (DH *)0x0) goto LAB_0006879a;
      if ((int)pDVar3 - iVar9 < 2) {
        iVar9 = 0x621;
        iVar10 = 0xa0;
      }
      else {
        iVar9 = iVar9 + 2;
        uVar14 = (uint)CONCAT11(puVar15[uVar11],puVar15[uVar11 + 1]);
        if ((int)uVar14 <= (int)pDVar3 - iVar9) {
          cnt = iVar9 + uVar14;
          local_e4 = (DH *)BN_bin2bn(puVar15 + uVar11 + 2,uVar14,(BIGNUM *)0x0);
          iVar10 = 0x62f;
          *(DH **)(param_1 + 0x1b4) = local_e4;
          if (local_e4 == (DH *)0x0) goto LAB_0006879a;
          iVar10 = srp_verify_server_param(param_1,&local_d4);
          puVar13 = puVar15 + uVar11 + 2 + uVar14;
          pDVar3 = (DH *)((int)pDVar3 - cnt);
          if (iVar10 == 0) {
            iVar10 = 0x636;
            iVar9 = 0x173;
            pcVar4 = DAT_000688d4;
            goto LAB_00068382;
          }
          if ((uVar12 & 1) == 0) {
            if ((uVar12 & 2) == 0) goto LAB_00068012;
            pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x98) + 0x44
                                                   ));
          }
          else {
            pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x98) + 0xc)
                                        );
          }
LAB_0006815c:
          if (pkey == (DH *)0x0) goto LAB_00068012;
          if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1e < 0) {
            if (1 < (int)pDVar3) {
              iVar10 = tls12_check_peer_sigalg(&local_cc,param_1,puVar13,pkey);
              if (iVar10 == -1) {
                local_e0 = (DH *)0x0;
                local_e4 = (DH *)0x0;
                p = (DH *)0x0;
                goto LAB_00068034;
              }
              if (iVar10 == 0) {
                local_e0 = (DH *)0x0;
                p = (DH *)0x0;
                local_e4 = (DH *)0x0;
                local_dc = (DH *)0x0;
                goto LAB_000682ac;
              }
              puVar13 = puVar13 + 2;
              pDVar3 = (DH *)&pDVar3[-1].field_0x4a;
              goto LAB_00068192;
            }
            iVar9 = 0x773;
            iVar10 = 0xa0;
          }
          else {
            local_cc = EVP_sha1();
LAB_00068192:
            if ((int)pDVar3 < 2) {
              iVar9 = 0x785;
              iVar10 = 0xa0;
            }
            else {
              uVar1 = *puVar13;
              siglen = &pDVar3[-1].field_0x4a;
              uVar2 = puVar13[1];
              puVar7 = (undefined *)EVP_PKEY_size((EVP_PKEY *)pkey);
              if ((int)siglen <= (int)puVar7) {
                puVar7 = (undefined *)(uint)CONCAT11(uVar1,uVar2);
              }
              if ((siglen == puVar7) && (0 < (int)siglen)) {
                if ((*(int *)pkey == 6) &&
                   ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) & 2) == 0)) {
                  EVP_MD_CTX_set_flags(&EStack_c4,8);
                  EVP_DigestInit_ex(&EStack_c4,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x8c),
                                    (ENGINE *)0x0);
                  EVP_DigestUpdate(&EStack_c4,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
                  EVP_DigestUpdate(&EStack_c4,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
                  EVP_DigestUpdate(&EStack_c4,d,cnt);
                  EVP_DigestFinal_ex(&EStack_c4,auStack_ac,&local_c8);
                  uVar11 = local_c8;
                  EVP_MD_CTX_set_flags(&EStack_c4,8);
                  EVP_DigestInit_ex(&EStack_c4,*(EVP_MD **)(*(int *)(param_1 + 0xe4) + 0x90),
                                    (ENGINE *)0x0);
                  EVP_DigestUpdate(&EStack_c4,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
                  EVP_DigestUpdate(&EStack_c4,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
                  EVP_DigestUpdate(&EStack_c4,d,cnt);
                  EVP_DigestFinal_ex(&EStack_c4,auStack_ac + uVar11,&local_c8);
                  iVar10 = RSA_verify(0x72,auStack_ac,local_c8 + uVar11,puVar13 + 2,(uint)siglen,
                                      *(RSA **)&pkey->field_0x14);
                  if (iVar10 < 0) {
                    local_d4 = 0x33;
                    ERR_put_error(0x14,0x8d,0x76,DAT_000688d4,0x7ab);
                  }
                  else {
                    if (iVar10 != 0) goto LAB_00067eb2;
                    local_d4 = 0x33;
                    ERR_put_error(0x14,0x8d,0x7b,DAT_000684e0,0x7b1);
                  }
                  local_dc = (DH *)0x0;
                  local_e0 = (DH *)0x0;
                  local_e4 = (DH *)0x0;
                  p = (DH *)0x0;
                }
                else {
                  EVP_DigestInit_ex(&EStack_c4,local_cc,(ENGINE *)0x0);
                  EVP_DigestUpdate(&EStack_c4,(void *)(*(int *)(param_1 + 0x58) + 0xc0),0x20);
                  EVP_DigestUpdate(&EStack_c4,(void *)(*(int *)(param_1 + 0x58) + 0xa0),0x20);
                  EVP_DigestUpdate(&EStack_c4,d,cnt);
                  iVar10 = EVP_VerifyFinal(&EStack_c4,puVar13 + 2,(uint)siglen,(EVP_PKEY *)pkey);
                  if (0 < iVar10) {
LAB_00067eb2:
                    EVP_PKEY_free((EVP_PKEY *)pkey);
                    EVP_MD_CTX_cleanup(&EStack_c4);
                    return (DH *)0x1;
                  }
                  local_d4 = 0x33;
                  local_dc = (DH *)0x0;
                  ERR_put_error(0x14,0x8d,0x7b,DAT_000684e0,0x7c0);
                  local_e0 = (DH *)0x0;
                  local_e4 = (DH *)0x0;
                  p = (DH *)0x0;
                }
                goto LAB_000682ac;
              }
              iVar10 = 0x108;
              iVar9 = 0x791;
            }
          }
          ERR_put_error(0x14,0x8d,iVar10,DAT_000688d4,iVar9);
          local_dc = (DH *)0x0;
          local_e0 = (DH *)0x0;
          local_e4 = (DH *)0x0;
          p = (DH *)0x0;
          goto LAB_000682ac;
        }
        iVar9 = 0x629;
        iVar10 = 0x15c;
      }
LAB_000682c8:
      ERR_put_error(0x14,0x8d,iVar10,DAT_000684e0,iVar9);
      local_dc = (DH *)0x0;
      local_e0 = (DH *)0x0;
      local_e4 = (DH *)0x0;
      pkey = (DH *)0x0;
      p = (DH *)0x0;
      goto LAB_000682ac;
    }
    pcVar4 = DAT_000684e0;
    if ((uVar11 & 1) != 0) {
      if ((*(uint *)(iVar10 + 0x20) & 2) == 0) {
        iVar10 = 0x651;
LAB_00068376:
        local_d4 = 10;
        iVar9 = 0xf4;
        goto LAB_00068382;
      }
      r = RSA_new();
      if (r == (RSA *)0x0) {
        iVar10 = 0x655;
        iVar9 = 0x41;
        local_e4 = (DH *)0x0;
LAB_000687a4:
        ERR_put_error(0x14,0x8d,iVar9,DAT_000688d4,iVar10);
        pkey = local_e4;
        p = local_e4;
        local_e0 = local_e4;
        goto LAB_00068034;
      }
      pkey = (DH *)0x0;
      if ((int)pDVar3 < 2) {
        iVar10 = 0x65b;
LAB_00068848:
        ERR_put_error(0x14,0x8d,0xa0,DAT_000688d4,iVar10);
LAB_0006871a:
        ssl3_send_alert(param_1,2,local_d4);
        EVP_PKEY_free((EVP_PKEY *)pkey);
      }
      else {
        puVar13 = d + 2;
        uVar11 = (uint)CONCAT11(*d,d[1]);
        if ((int)&pDVar3[-1].field_0x4a < (int)uVar11) {
          ERR_put_error(0x14,0x8d,0x79,DAT_000688d4,0x661);
          goto LAB_0006871a;
        }
        pBVar6 = BN_bin2bn(puVar13,uVar11,*(BIGNUM **)&r->field_0x10);
        *(BIGNUM **)&r->field_0x10 = pBVar6;
        if (pBVar6 != (BIGNUM *)0x0) {
          if ((int)((int)pDVar3 - (uVar11 + 2)) < 2) {
            iVar10 = 0x66d;
            goto LAB_00068848;
          }
          uVar14 = (uint)CONCAT11(puVar13[uVar11],puVar13[uVar11 + 1]);
          if ((int)((int)pDVar3 - (uVar11 + 4)) < (int)uVar14) {
            pkey = (DH *)0x0;
            ERR_put_error(0x14,0x8d,0x78,DAT_000688d4,0x675);
          }
          else {
            cnt = uVar11 + 4 + uVar14;
            pBVar6 = BN_bin2bn(puVar13 + uVar11 + 2,uVar14,*(BIGNUM **)&r->field_0x14);
            *(BIGNUM **)&r->field_0x14 = pBVar6;
            if (pBVar6 == (BIGNUM *)0x0) {
              iVar10 = 0x67b;
              goto LAB_00068930;
            }
            puVar13 = puVar13 + uVar11 + 2 + uVar14;
            pDVar3 = (DH *)((int)pDVar3 - cnt);
            if ((uVar12 & 1) == 0) {
              ERR_put_error(0x14,0x8d,0x44,DAT_000688d4,0x687);
              goto LAB_0006877a;
            }
            pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x98) + 0xc)
                                        );
            iVar10 = EVP_PKEY_bits((EVP_PKEY *)pkey);
            if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) & 8) == 0) {
              iVar9 = 0x400;
            }
            else {
              iVar9 = 0x200;
            }
            if (iVar9 < iVar10) {
              *(RSA **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x98) + 0xec) = r;
              goto LAB_0006815c;
            }
            local_d4 = 10;
            ERR_put_error(0x14,0x8d,0xf4,DAT_000688d4,0x68d);
          }
          goto LAB_0006871a;
        }
        iVar10 = 0x667;
LAB_00068930:
        ERR_put_error(0x14,0x8d,3,DAT_00068a3c,iVar10);
LAB_0006877a:
        EVP_PKEY_free((EVP_PKEY *)0x0);
      }
      RSA_free(r);
      BN_CTX_free((BN_CTX *)0x0);
      EC_POINT_free((EC_POINT *)0x0);
      goto LAB_0006805e;
    }
    if ((uVar11 & 8) == 0) {
      if ((uVar11 & 6) != 0) {
        iVar10 = 0x6f0;
        local_d4 = 0x2f;
        iVar9 = 0xeb;
        goto LAB_00068382;
      }
      if ((uVar11 & 0x80) == 0) {
        if (uVar11 != 0) {
          iVar10 = 0x767;
          goto LAB_00068376;
        }
LAB_00068012:
        if ((uVar12 & 0x404) != 0) goto LAB_00067eaa;
        iVar10 = ssl3_check_cert_and_algorithm(param_1);
        if (iVar10 == 0) {
          local_e4 = (DH *)0x0;
          pkey = (DH *)0x0;
          p = (DH *)0x0;
          local_e0 = (DH *)0x0;
        }
        else {
          ERR_put_error(0x14,0x8d,0x44,DAT_00068a3c,0x7ca);
          local_e0 = (DH *)0x0;
          local_e4 = (DH *)0x0;
          pkey = (DH *)0x0;
          p = (DH *)0x0;
        }
      }
      else {
        local_e0 = (DH *)EC_KEY_new();
        if (local_e0 != (DH *)0x0) {
          if ((int)pDVar3 < 4) {
            iVar9 = 0x70c;
            iVar10 = 0xa0;
          }
          else {
            iVar10 = tls1_check_curve(param_1,d,3);
            if (iVar10 == 0) {
              iVar9 = 0x714;
              iVar10 = 0x17a;
            }
            else {
              iVar10 = tls1_ec_curve_id2nid(d[2]);
              if (iVar10 != 0) {
                pEVar8 = EC_GROUP_new_by_curve_name(iVar10);
                if (pEVar8 == (EC_GROUP *)0x0) {
                  ERR_put_error(0x14,0x8d,0x10,DAT_00068a3c,0x721);
                  pkey = (DH *)0x0;
                  local_e4 = (DH *)0x0;
                  p = (DH *)0x0;
                }
                else {
                  iVar10 = EC_KEY_set_group((EC_KEY *)local_e0,pEVar8);
                  if (iVar10 == 0) {
                    ERR_put_error(0x14,0x8d,0x10,DAT_000688d4,0x725);
                    pkey = (DH *)0x0;
                    local_e4 = (DH *)0x0;
                    p = (DH *)0x0;
                  }
                  else {
                    EC_GROUP_free(pEVar8);
                    pEVar8 = EC_KEY_get0_group((EC_KEY *)local_e0);
                    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x20) << 0x1e < 0) &&
                       (iVar10 = EC_GROUP_get_degree(pEVar8), 0xa3 < iVar10)) {
                      local_d4 = 0x3c;
                      iVar9 = 0x730;
                      iVar10 = 0x136;
                      goto LAB_0006880c;
                    }
                    p = (DH *)EC_POINT_new(pEVar8);
                    if ((p != (DH *)0x0) && (local_dc = (DH *)BN_CTX_new(), local_dc != (DH *)0x0))
                    {
                      uVar11 = (uint)(byte)d[3];
                      if (((int)uVar11 <= (int)&pDVar3[-1].field_0x48) &&
                         (iVar10 = EC_POINT_oct2point(pEVar8,(EC_POINT *)p,d + 4,uVar11,
                                                      (BN_CTX *)local_dc), iVar10 != 0)) {
                        cnt = uVar11 + 4;
                        pDVar3 = (DH *)((int)pDVar3 - cnt);
                        puVar13 = d + 4 + uVar11;
                        if ((uVar12 & 1) == 0) {
                          pkey = (DH *)(uVar12 & 0x40);
                          if (pkey != (DH *)0x0) {
                            pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(*(int *)(param_1 + 0xc0
                                                                                     ) + 0x98) +
                                                                   0x98));
                          }
                        }
                        else {
                          pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(*(int *)(param_1 + 0xc0)
                                                                          + 0x98) + 0xc));
                        }
                        EC_KEY_set_public_key((EC_KEY *)local_e0,(EC_POINT *)p);
                        *(DH **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x98) + 0xf4) = local_e0;
                        BN_CTX_free((BN_CTX *)local_dc);
                        EC_POINT_free((EC_POINT *)p);
                        goto LAB_0006815c;
                      }
                      local_e4 = (DH *)0x0;
                      ERR_put_error(0x14,0x8d,0x132,DAT_000688d4,0x743);
                      pkey = local_e4;
                      goto LAB_000682ac;
                    }
                    local_e4 = (DH *)0x0;
                    ERR_put_error(0x14,0x8d,0x41,DAT_00068a3c,0x739);
                    pkey = local_e4;
                  }
                }
                goto LAB_00068034;
              }
              local_d4 = 0x50;
              iVar10 = 0x13a;
              iVar9 = 0x71b;
            }
          }
LAB_0006880c:
          pkey = (DH *)0x0;
          ERR_put_error(0x14,0x8d,iVar10,DAT_000688d4,iVar9);
          p = pkey;
          local_e4 = pkey;
          local_dc = pkey;
          goto LAB_000682ac;
        }
        ERR_put_error(0x14,0x8d,0x41,DAT_00068a3c,0x6fb);
        pkey = (DH *)0x0;
        local_e4 = (DH *)0x0;
        p = (DH *)0x0;
      }
    }
    else {
      local_e4 = DH_new();
      if (local_e4 != (DH *)0x0) {
        if ((int)pDVar3 < 2) {
          iVar10 = 0x6a0;
LAB_000689b4:
          iVar9 = 0xa0;
        }
        else {
          puVar13 = d + 2;
          uVar11 = (uint)CONCAT11(*d,d[1]);
          if ((int)uVar11 <= (int)&pDVar3[-1].field_0x4a) {
            pkey = (DH *)BN_bin2bn(puVar13,uVar11,(BIGNUM *)0x0);
            iVar10 = 0x6ac;
            *(DH **)&local_e4->field_0x8 = pkey;
            if (pkey == (DH *)0x0) goto LAB_00068996;
            if ((int)((int)pDVar3 - (uVar11 + 2)) < 2) {
              iVar10 = 0x6b2;
              goto LAB_000689b4;
            }
            puVar15 = puVar13 + uVar11 + 2;
            uVar14 = (uint)CONCAT11(puVar13[uVar11],puVar13[uVar11 + 1]);
            if ((int)((int)pDVar3 - (uVar11 + 4)) < (int)uVar14) {
              iVar9 = 0x6ba;
              iVar10 = 0x6c;
            }
            else {
              iVar9 = uVar11 + 4 + uVar14;
              pkey = (DH *)BN_bin2bn(puVar15,uVar14,(BIGNUM *)0x0);
              *(DH **)&local_e4->field_0xc = pkey;
              iVar10 = 0x6c0;
              if (pkey == (DH *)0x0) {
LAB_00068996:
                ERR_put_error(0x14,0x8d,3,DAT_00068a3c,iVar10);
                p = pkey;
                local_e0 = pkey;
                goto LAB_00068034;
              }
              if ((int)pDVar3 - iVar9 < 2) {
                iVar9 = 0x6c6;
                iVar10 = 0xa0;
              }
              else {
                iVar9 = iVar9 + 2;
                uVar11 = (uint)CONCAT11(puVar15[uVar14],puVar15[uVar14 + 1]);
                if ((int)uVar11 <= (int)pDVar3 - iVar9) {
                  cnt = iVar9 + uVar11;
                  pBVar6 = BN_bin2bn(puVar15 + uVar14 + 2,uVar11,(BIGNUM *)0x0);
                  *(BIGNUM **)&local_e4->field_0x14 = pBVar6;
                  if (pBVar6 != (BIGNUM *)0x0) {
                    puVar13 = puVar15 + uVar14 + 2 + uVar11;
                    pDVar3 = (DH *)((int)pDVar3 - cnt);
                    if ((uVar12 & 1) == 0) {
                      pkey = (DH *)(uVar12 & 2);
                      if (pkey != (DH *)0x0) {
                        pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(*(int *)(param_1 + 0xc0) +
                                                                        0x98) + 0x44));
                      }
                    }
                    else {
                      pkey = (DH *)X509_get_pubkey(*(X509 **)(*(int *)(*(int *)(param_1 + 0xc0) +
                                                                      0x98) + 0xc));
                    }
                    *(DH **)(*(int *)(*(int *)(param_1 + 0xc0) + 0x98) + 0xf0) = local_e4;
                    goto LAB_0006815c;
                  }
                  iVar10 = 0x6d4;
                  pkey = (DH *)0x0;
                  goto LAB_00068996;
                }
                iVar10 = 0x6d;
                iVar9 = 0x6ce;
              }
            }
            p = (DH *)0x0;
            ERR_put_error(0x14,0x8d,iVar10,DAT_00068a3c,iVar9);
            pkey = (DH *)0x0;
            local_dc = (DH *)0x0;
            local_e0 = (DH *)0x0;
            goto LAB_000682ac;
          }
          iVar9 = 0x6e;
          iVar10 = 0x6a6;
        }
        ERR_put_error(0x14,0x8d,iVar9,DAT_00068a3c,iVar10);
        pkey = (DH *)0x0;
        p = (DH *)0x0;
        local_e0 = (DH *)0x0;
        local_dc = (DH *)0x0;
        goto LAB_000682ac;
      }
      ERR_put_error(0x14,0x8d,5,DAT_00068a3c,0x69a);
      pkey = (DH *)0x0;
      p = (DH *)0x0;
      local_e0 = (DH *)0x0;
    }
LAB_00068034:
    local_dc = (DH *)0x0;
    EVP_PKEY_free((EVP_PKEY *)pkey);
  }
  else {
    if ((uVar11 & 0x88) == 0) {
      if ((int)(uVar11 << 0x17) < 0) {
        iVar10 = *(int *)(param_1 + 0xc0);
        uVar5 = ssl_sess_cert_new();
        iVar9 = *(int *)(param_1 + 0xe4);
        *(undefined4 *)(iVar10 + 0x98) = uVar5;
        if (*(void **)(iVar9 + 0x14c) != (void *)0x0) {
          CRYPTO_free(*(void **)(iVar9 + 0x14c));
          iVar9 = *(int *)(param_1 + 0xe4);
        }
        iVar10 = *(int *)(param_1 + 0x58);
        *(undefined4 *)(iVar9 + 0x14c) = 0;
      }
      *(undefined4 *)(iVar10 + 0x354) = 1;
      return (DH *)0x1;
    }
    ERR_put_error(0x14,0x8d,0xf4,DAT_000684e0,0x57d);
    local_dc = (DH *)0x0;
    local_e0 = (DH *)0x0;
    local_e4 = (DH *)0x0;
    local_d4 = 10;
    pkey = (DH *)0x0;
    p = (DH *)0x0;
LAB_000682ac:
    ssl3_send_alert(param_1,2,local_d4);
    EVP_PKEY_free((EVP_PKEY *)pkey);
  }
  if (local_e4 != (DH *)0x0) {
    DH_free(local_e4);
  }
  BN_CTX_free((BN_CTX *)local_dc);
  EC_POINT_free((EC_POINT *)p);
  if (local_e0 != (DH *)0x0) {
    EC_KEY_free((EC_KEY *)local_e0);
  }
LAB_0006805e:
  EVP_MD_CTX_cleanup(&EStack_c4);
  *(undefined4 *)(param_1 + 0x34) = 5;
  return (DH *)0xffffffff;
}


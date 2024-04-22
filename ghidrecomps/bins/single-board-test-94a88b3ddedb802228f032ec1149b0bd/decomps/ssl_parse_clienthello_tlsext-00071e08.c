
undefined4 ssl_parse_clienthello_tlsext(SSL *param_1,uchar **param_2,int param_3,int param_4)

{
  uchar *puVar1;
  uchar uVar2;
  byte bVar3;
  short sVar4;
  bool bVar5;
  void *pvVar6;
  size_t sVar7;
  stack_st_SRTP_PROTECTION_PROFILE *psVar8;
  BIO *__dest;
  uint uVar9;
  X509_EXTENSIONS *pXVar10;
  OCSP_RESPID *a;
  _STACK *st;
  int iVar11;
  uint uVar12;
  _func_3296 *p_Var13;
  ssl3_state_st *psVar14;
  ssl3_state_st *psVar15;
  uchar *puVar16;
  cert_st *pcVar17;
  uchar *puVar18;
  uchar *puVar19;
  int iVar20;
  code *pcVar21;
  uchar *puVar22;
  uint uVar23;
  SSL_SESSION *pSVar24;
  char *__s;
  uchar *puVar25;
  uchar *puVar26;
  char *pcVar27;
  uint uVar28;
  undefined4 local_34;
  uchar *local_30;
  uint local_2c [2];
  
  psVar15 = param_1->s3;
  pvVar6 = (void *)psVar15[1].delay_buf_pop_ret;
  local_34 = 0xffffffff;
  puVar22 = *param_2;
  param_1->tlsext_hostname = (char *)0x0;
  param_1->servername_done = -1;
  psVar15->next_proto_neg_seen = 0;
  if (pvVar6 != (void *)0x0) {
    CRYPTO_free(pvVar6);
    psVar15 = param_1->s3;
    psVar15[1].delay_buf_pop_ret = 0;
  }
  param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffc);
  if (((param_1->references << 0x19 < 0) && (puVar22 < (uchar *)(param_3 + param_4 + -2))) &&
     (puVar22 + 2 <= (uchar *)(param_3 + param_4 + -4))) {
    if (CONCAT11(puVar22[2],puVar22[3]) == 0) {
      puVar25 = (uchar *)(param_3 + param_4);
      puVar26 = puVar22 + CONCAT11(puVar22[4],puVar22[5]) + 6;
      if (puVar26 <= puVar25) {
        if ((param_1->first_packet >> 8 == 3) && (0x302 < param_1->first_packet)) {
          if ((puVar25 == puVar26 + 0x22) &&
             (iVar20 = memcmp(puVar26,DAT_00072584,0x12), iVar20 == 0)) {
            iVar20 = memcmp(puVar26 + 0x12,DAT_00072588,0x10);
joined_r0x00072090:
            if (iVar20 == 0) {
              *(undefined *)&psVar15[1].flags = 1;
            }
          }
        }
        else if (puVar25 == puVar26 + 0x12) {
          iVar20 = memcmp(puVar26,DAT_0007219c,0x12);
          goto joined_r0x00072090;
        }
      }
    }
  }
  puVar25 = (uchar *)(param_3 + param_4);
  if (*(void **)(param_1->cert + 0x124) != (void *)0x0) {
    CRYPTO_free(*(void **)(param_1->cert + 0x124));
    *(undefined4 *)(param_1->cert + 0x124) = 0;
  }
  if (param_1[1].rbio != (BIO *)0x0) {
    CRYPTO_free(param_1[1].rbio);
    param_1[1].rbio = (BIO *)0x0;
  }
  param_1->srtp_profiles = (stack_st_SRTP_PROTECTION_PROFILE *)0x0;
  if (puVar22 != puVar25) {
    if ((puVar22 <= (uchar *)(param_3 + param_4 + -2)) &&
       (puVar26 = puVar22 + 2,
       puVar26 <= (uchar *)(param_3 + (param_4 - (uint)CONCAT11(*puVar22,puVar22[1]))))) {
      puVar18 = (uchar *)(param_3 + param_4 + -4);
      if (puVar18 < puVar26) {
        bVar5 = false;
LAB_000721a8:
        if (puVar26 == puVar25) {
          *param_2 = puVar25;
          if (!bVar5) goto LAB_000721b8;
          goto LAB_000721c8;
        }
      }
      else {
        puVar19 = puVar22 + 6;
        uVar28 = (uint)CONCAT11(puVar22[4],puVar22[5]);
        sVar4 = CONCAT11(puVar22[2],puVar22[3]);
        if (puVar19 + uVar28 <= puVar25) {
          bVar5 = false;
          puVar1 = puVar19 + uVar28;
          puVar16 = puVar26;
LAB_00071ef6:
          puVar26 = puVar1;
          if ((code *)param_1->max_send_fragment != (code *)0x0) {
            (*(code *)param_1->max_send_fragment)
                      (param_1,0,sVar4,puVar19,uVar28,param_1->tlsext_debug_cb);
          }
          if (sVar4 == 0) {
            if (uVar28 < 2) goto LAB_00071fe2;
            uVar23 = uVar28 - 2 & 0xffff;
            uVar28 = (uint)CONCAT11(puVar16[4],puVar16[5]);
            if (uVar23 < uVar28) goto LAB_00071fe2;
            if (3 < uVar28) {
              iVar20 = uVar28 - 3;
              puVar26 = puVar16 + 9;
              uVar2 = puVar16[6];
              uVar28 = (uint)CONCAT11(puVar16[7],puVar16[8]);
              if (iVar20 < (int)uVar28) goto LAB_00071fe2;
              pcVar27 = param_1->tlsext_hostname;
              while( true ) {
                if ((pcVar27 == (char *)0x0) && (uVar2 == '\0')) {
                  if (param_1->hit == 0) {
                    pSVar24 = param_1->session;
                    if (*(int *)(pSVar24->krb5_client_princ + 0x40) != 0) goto LAB_00071fe2;
                    if (0xff < uVar28) {
                      local_34 = 0x70;
                      goto LAB_00071fe6;
                    }
                    pvVar6 = CRYPTO_malloc(uVar28 + 1,DAT_00072198,0x833);
                    *(void **)(pSVar24->krb5_client_princ + 0x40) = pvVar6;
                    if (pvVar6 == (void *)0x0) {
                      local_34 = 0x50;
                      goto LAB_00071fe6;
                    }
                    memcpy(*(void **)(param_1->session->krb5_client_princ + 0x40),puVar26,uVar28);
                    *(undefined *)(*(int *)(param_1->session->krb5_client_princ + 0x40) + uVar28) =
                         0;
                    pcVar27 = *(char **)(param_1->session->krb5_client_princ + 0x40);
                    sVar7 = strlen(pcVar27);
                    if (uVar28 != sVar7) {
                      CRYPTO_free(pcVar27);
                      local_34 = 0x70;
                      *(undefined4 *)(param_1->session->krb5_client_princ + 0x40) = 0;
                      goto LAB_00071fe6;
                    }
                    pcVar27 = (char *)0x1;
                    param_1->tlsext_hostname = (char *)0x1;
                  }
                  else {
                    __s = *(char **)(param_1->session->krb5_client_princ + 0x40);
                    if ((__s != (char *)0x0) && (sVar7 = strlen(__s), sVar7 == uVar28)) {
                      uVar9 = strncmp(__s,(char *)puVar26,uVar28);
                      pcVar27 = (char *)(1 - uVar9);
                      if (1 < uVar9) {
                        pcVar27 = (char *)0x0;
                      }
                    }
                    param_1->tlsext_hostname = pcVar27;
                  }
                }
                uVar28 = iVar20 - uVar28;
                if ((int)uVar28 < 4) break;
                puVar19 = puVar26 + 1;
                iVar20 = uVar28 - 3;
                puVar1 = puVar26 + 2;
                uVar2 = *puVar26;
                puVar26 = puVar26 + 3;
                uVar28 = (uint)CONCAT11(*puVar19,*puVar1);
                if (iVar20 < (int)uVar28) goto LAB_00071fe2;
              }
            }
            if (uVar28 == 0) {
              puVar26 = puVar16 + uVar23 + 6;
              goto LAB_00072158;
            }
            goto LAB_00071fe2;
          }
          if (sVar4 == 0xc) {
            if (((uVar28 != 0) && (uVar23 = (uint)puVar16[4], uVar23 == uVar28 - 1)) &&
               (param_1[1].rbio == (BIO *)0x0)) {
              __dest = (BIO *)CRYPTO_malloc(uVar28,DAT_00072198,0x859);
              param_1[1].rbio = __dest;
              if (__dest == (BIO *)0x0) goto LAB_00071fe6;
              memcpy(__dest,puVar16 + 5,uVar23);
              *(undefined *)((int)&(param_1[1].rbio)->method + uVar23) = 0;
              sVar7 = strlen((char *)param_1[1].rbio);
              if (uVar23 == sVar7) goto LAB_00072158;
            }
            goto LAB_00071fe2;
          }
          if (sVar4 == 0xb) {
            uVar23 = (uint)puVar16[4];
            if ((uVar23 == uVar28 - 1) && (uVar23 != 0)) {
              if (param_1->hit == 0) {
                pSVar24 = param_1->session;
                if (*(void **)(pSVar24->krb5_client_princ + 0x48) != (void *)0x0) {
                  CRYPTO_free(*(void **)(pSVar24->krb5_client_princ + 0x48));
                  pSVar24 = param_1->session;
                  *(undefined4 *)(pSVar24->krb5_client_princ + 0x48) = 0;
                }
                *(undefined4 *)(pSVar24->krb5_client_princ + 0x44) = 0;
                pvVar6 = CRYPTO_malloc(uVar23,DAT_00072580,0x872);
                *(void **)(pSVar24->krb5_client_princ + 0x48) = pvVar6;
                if (pvVar6 == (void *)0x0) goto LAB_0007244a;
                pSVar24 = param_1->session;
                *(uint *)(pSVar24->krb5_client_princ + 0x44) = uVar23;
                memcpy(*(void **)(pSVar24->krb5_client_princ + 0x48),puVar16 + 5,uVar23);
              }
              goto LAB_00072158;
            }
            goto LAB_00071fe2;
          }
          if (sVar4 == 10) {
            sVar7 = (uint)puVar16[5] + (uint)puVar16[4] * 0x100;
            if (((sVar7 != uVar28 - 2) || (sVar7 == 0)) || ((int)((uint)puVar16[5] << 0x1f) < 0))
            goto LAB_00071fe2;
            if (param_1->hit == 0) {
              pSVar24 = param_1->session;
              if (*(int *)(pSVar24->krb5_client_princ + 0x50) == 0) {
                *(undefined4 *)(pSVar24->krb5_client_princ + 0x4c) = 0;
                pvVar6 = CRYPTO_malloc(sVar7,DAT_00072580,0x895);
                *(void **)(pSVar24->krb5_client_princ + 0x50) = pvVar6;
                if (pvVar6 == (void *)0x0) goto LAB_0007244a;
                pSVar24 = param_1->session;
                *(size_t *)(pSVar24->krb5_client_princ + 0x4c) = sVar7;
                memcpy(*(void **)(pSVar24->krb5_client_princ + 0x50),puVar16 + 6,sVar7);
                goto LAB_00072158;
              }
              goto LAB_00071fe2;
            }
          }
          else {
            if (sVar4 == 0x23) {
              if ((param_1->tlsext_session_ticket == (TLS_SESSION_TICKET_EXT *)0x0) ||
                 (iVar20 = (*(code *)param_1->tlsext_session_ticket)
                                     (param_1,puVar19,uVar28,param_1->tls_session_ticket_ext_cb),
                 iVar20 != 0)) goto LAB_00072158;
LAB_0007244a:
              local_34 = 0x50;
              goto LAB_00071fe6;
            }
            if (sVar4 == -0xff) {
              iVar20 = ssl_parse_clienthello_renegotiate_ext(param_1,puVar19,uVar28,&local_34);
              if (iVar20 != 0) {
                bVar5 = true;
                goto LAB_00072158;
              }
              goto LAB_00071fe6;
            }
            if (sVar4 == 0xd) {
              pcVar17 = param_1->cert;
              if ((*(int *)(pcVar17 + 0x124) == 0) && (1 < uVar28)) {
                uVar23 = uVar28 - 2 & 0xffff;
                puVar19 = puVar16 + 6;
                uVar28 = (uint)CONCAT11(puVar16[4],puVar16[5]);
                if ((uVar28 == uVar23) && ((-1 < (int)(uVar28 << 0x1f) && (uVar28 != 0)))) {
                  if (-1 < *(int *)(param_1->method->ssl3_enc + 0x38) << 0x1e) goto LAB_0007255c;
                  pvVar6 = CRYPTO_malloc(uVar28,DAT_00072580,0xe70);
                  *(void **)(pcVar17 + 0x124) = pvVar6;
                  if (pvVar6 != (void *)0x0) {
                    *(uint *)(pcVar17 + 0x128) = uVar28;
                    puVar26 = puVar19 + uVar23;
                    memcpy(pvVar6,puVar19,uVar28);
                    goto LAB_00072158;
                  }
                }
              }
              goto LAB_00071fe2;
            }
            if (sVar4 == 5) {
              if (4 < uVar28) {
                bVar3 = puVar16[4];
                param_1->servername_done = (uint)bVar3;
                if (bVar3 != 1) {
                  puVar26 = puVar16 + (uVar28 - 1 & 0xffff) + 5;
                  param_1->servername_done = -1;
                  goto LAB_00072158;
                }
                uVar23 = uVar28 - 3 & 0xffff;
                uVar9 = (uint)CONCAT11(puVar16[5],puVar16[6]);
                if (uVar9 <= uVar23) {
                  if (uVar9 == 0) {
                    puVar16 = puVar16 + 7;
                    goto LAB_00072510;
                  }
                  if (3 < uVar9) {
                    puVar26 = puVar16 + 9;
                    uVar12 = (uint)CONCAT11(puVar16[7],puVar16[8]);
                    uVar23 = (uVar28 - 5) - uVar12;
                    iVar20 = uVar9 + (-2 - uVar12);
                    if (-1 < iVar20) {
                      do {
                        uVar23 = uVar23 & 0xffff;
                        puVar16 = puVar26 + uVar12;
                        local_30 = puVar26;
                        a = d2i_OCSP_RESPID((OCSP_RESPID **)0x0,&local_30,uVar12);
                        if (a == (OCSP_RESPID *)0x0) break;
                        if (puVar16 != local_30) {
                          OCSP_RESPID_free(a);
                          break;
                        }
                        st = (_STACK *)param_1->tlsext_status_expected;
                        if (st == (_STACK *)0x0) {
                          st = sk_new_null();
                          param_1->tlsext_status_expected = (int)st;
                          if (st != (_STACK *)0x0) goto LAB_000726b8;
LAB_00072712:
                          OCSP_RESPID_free(a);
                          local_34 = 0x50;
                          goto LAB_00071fe6;
                        }
LAB_000726b8:
                        iVar11 = sk_push(st,a);
                        if (iVar11 == 0) goto LAB_00072712;
                        puVar26 = puVar16 + 2;
                        if (iVar20 < 1) goto LAB_0007272a;
                        if (iVar20 < 4) break;
                        uVar12 = (uint)CONCAT11(*puVar16,puVar16[1]);
                        iVar20 = iVar20 + (-2 - uVar12);
                        uVar23 = uVar23 + (-2 - uVar12);
                        if (iVar20 < 0) break;
                      } while( true );
                    }
                  }
                }
              }
              goto LAB_00071fe2;
            }
            if (sVar4 == 0xf) {
              if (puVar16[4] == '\x01') {
                param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1)
                ;
                goto LAB_00072158;
              }
              if (puVar16[4] != '\x02') {
                local_34 = 0x2f;
                goto LAB_00071fe6;
              }
              param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
            }
            else {
              if (sVar4 == 0x3374) {
                psVar15 = param_1->s3;
                if (((psVar15->tmp).finish_md_len == 0) && (psVar15[1].delay_buf_pop_ret == 0)) {
                  psVar15->next_proto_neg_seen = 1;
                  goto LAB_00072158;
                }
              }
              else if (sVar4 == 0x10) {
                pcVar21 = *(code **)(param_1->psk_server_callback + 0x1b8);
                if ((pcVar21 != (code *)0x0) && ((param_1->s3->tmp).finish_md_len == 0)) {
                  if ((1 < uVar28) &&
                     ((uVar23 = (uint)CONCAT11(puVar16[4],puVar16[5]), uVar23 == uVar28 - 2 &&
                      (1 < uVar23)))) {
                    uVar28 = 0;
                    do {
                      uVar9 = (uint)(puVar16 + 6)[uVar28];
                      uVar12 = uVar28 + 1;
                      if (((uVar9 == 0) || (uVar28 = uVar9 + uVar12, CARRY4(uVar9,uVar12) != false))
                         || (uVar23 < uVar28)) goto LAB_00071fe2;
                    } while (uVar28 < uVar23);
                    iVar20 = (*pcVar21)(param_1,&local_30,local_2c,puVar16 + 6,uVar23,
                                        *(undefined4 *)(param_1->psk_server_callback + 0x1bc));
                    psVar15 = param_1->s3;
                    if (iVar20 == 0) {
                      if ((void *)psVar15[1].delay_buf_pop_ret != (void *)0x0) {
                        CRYPTO_free((void *)psVar15[1].delay_buf_pop_ret);
                        psVar15 = param_1->s3;
                      }
                      pvVar6 = CRYPTO_malloc(local_2c[0] & 0xff,DAT_00072734,0x7a9);
                      psVar14 = param_1->s3;
                      psVar15[1].delay_buf_pop_ret = (int)pvVar6;
                      pvVar6 = (void *)psVar14[1].delay_buf_pop_ret;
                      if (pvVar6 == (void *)0x0) goto LAB_0007244a;
                      memcpy(pvVar6,local_30,local_2c[0] & 0xff);
                      psVar15 = param_1->s3;
                      *(uint *)psVar15[1].read_sequence = local_2c[0] & 0xff;
                    }
                    psVar15->next_proto_neg_seen = 0;
                    goto LAB_00072158;
                  }
                  goto LAB_00071fe2;
                }
              }
              if (((*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c < 0) &&
                  (psVar8 = SSL_get_srtp_profiles(param_1),
                  psVar8 != (stack_st_SRTP_PROTECTION_PROFILE *)0x0)) &&
                 ((sVar4 == 0xe &&
                  (iVar20 = ssl_parse_clienthello_use_srtp_ext(param_1,puVar19,uVar28,&local_34),
                  iVar20 != 0)))) goto LAB_00071fe6;
            }
          }
LAB_00072158:
          if (puVar18 < puVar26) goto LAB_000721a8;
          puVar19 = puVar26 + 4;
          uVar28 = (uint)CONCAT11(puVar26[2],puVar26[3]);
          sVar4 = CONCAT11(*puVar26,puVar26[1]);
          puVar1 = puVar19 + uVar28;
          puVar16 = puVar26;
          if (puVar25 < puVar19 + uVar28) goto LAB_00071fe2;
          goto LAB_00071ef6;
        }
      }
    }
LAB_00071fe2:
    local_34 = 0x32;
LAB_00071fe6:
    ssl3_send_alert(param_1,2,local_34);
    return 0;
  }
LAB_000721b8:
  if ((param_1->tlsext_hb_seq != 0) && (-1 < param_1->references << 0xd)) {
    local_34 = 0x28;
    ERR_put_error(0x14,0x140,0x152,DAT_00072580,0x975);
    goto LAB_00071fe6;
  }
LAB_000721c8:
  p_Var13 = param_1->psk_server_callback;
  local_2c[0] = 0x70;
  if ((p_Var13 == (_func_3296 *)0x0) || (*(code **)(p_Var13 + 0x100) == (code *)0x0)) {
    pvVar6 = param_1->tls_session_secret_cb_arg;
    if ((pvVar6 != (void *)0x0) && (*(code **)((int)pvVar6 + 0x100) != (code *)0x0)) {
      iVar20 = (**(code **)((int)pvVar6 + 0x100))
                         (param_1,local_2c,*(undefined4 *)((int)pvVar6 + 0x104));
      goto joined_r0x000722a4;
    }
  }
  else {
    iVar20 = (**(code **)(p_Var13 + 0x100))(param_1,local_2c,*(undefined4 *)(p_Var13 + 0x104));
joined_r0x000722a4:
    if (iVar20 == 2) {
      ssl3_send_alert(param_1,2,local_2c[0]);
      ERR_put_error(0x14,0x12e,0xe2,DAT_00072580,0x9b5);
      return 0;
    }
    if (iVar20 != 3) {
      if (iVar20 == 1) {
        ssl3_send_alert(param_1,1,local_2c[0]);
      }
      goto LAB_000721fc;
    }
  }
  param_1->tlsext_hostname = (char *)0x0;
LAB_000721fc:
  custom_ext_init(param_1->cert + 0x164);
  if ((((param_1->hit == 0) && (*(int *)(param_1->cert + 0x168) != 0)) && (puVar22 < puVar25 + -2))
     && (puVar26 = puVar22 + 2, puVar26 <= puVar25 + -(uint)CONCAT11(*puVar22,puVar22[1]))) {
    while (puVar22 = puVar26 + 4, puVar26 <= puVar25 + -4) {
      puVar18 = puVar26 + 2;
      puVar19 = puVar26 + 3;
      uVar2 = *puVar26;
      puVar1 = puVar26 + 1;
      puVar26 = puVar22 + CONCAT11(*puVar18,*puVar19);
      if (puVar25 < puVar26) {
        return 1;
      }
      iVar20 = custom_ext_parse(param_1,1,CONCAT11(uVar2,*puVar1),puVar22,
                                (uint)CONCAT11(*puVar18,*puVar19),&local_34);
      if (iVar20 < 1) {
        ssl3_send_alert(param_1,2,local_34);
        return 0;
      }
    }
  }
  return 1;
LAB_0007272a:
  if (uVar23 < 2) goto LAB_00071fe2;
LAB_00072510:
  uVar23 = uVar23 - 2 & 0xffff;
  puVar26 = puVar16 + 2;
  uVar28 = (uint)CONCAT11(*puVar16,puVar16[1]);
  if (uVar28 != uVar23) goto LAB_00071fe2;
  local_30 = puVar26;
  if (uVar28 != 0) {
    if (&param_1->tlsext_ocsp_ids->stack != (_STACK *)0x0) {
      sk_pop_free(&param_1->tlsext_ocsp_ids->stack,DAT_0007258c);
    }
    pXVar10 = d2i_X509_EXTENSIONS((X509_EXTENSIONS **)0x0,&local_30,uVar28);
    param_1->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)pXVar10;
    if ((pXVar10 == (X509_EXTENSIONS *)0x0) || (puVar19 = puVar26, local_30 != puVar26 + uVar28))
    goto LAB_00071fe2;
LAB_0007255c:
    puVar26 = puVar19 + uVar23;
  }
  goto LAB_00072158;
}


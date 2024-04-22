
SSL_COMP * ssl3_get_client_hello(SSL *param_1)

{
  _STACK *p_Var1;
  SSL_COMP *pSVar2;
  stack_st_SSL_CIPHER *psVar3;
  SSL_CIPHER *pSVar4;
  long lVar5;
  int iVar6;
  void *pvVar7;
  int iVar8;
  SSL_CIPHER *pSVar9;
  SSL_METHOD *pSVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  SSL_SESSION *pSVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  dtls1_state_st *pdVar17;
  SSL_COMP *unaff_r5;
  _func_3206 *p_Var18;
  _STACK *p_Var19;
  undefined4 *puVar20;
  code *pcVar21;
  SSL_CIPHER *pSVar22;
  undefined4 *puVar23;
  tls_session_secret_cb_fn ptVar24;
  uint uVar25;
  ssl3_state_st *psVar26;
  int iVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  bool bVar30;
  undefined4 *local_38;
  int local_34;
  _STACK *local_30;
  _STACK *local_2c [2];
  
  iVar14 = param_1->state;
  local_30 = (_STACK *)0x0;
  if (iVar14 == 0x2112) {
    if (param_1->max_cert_list != 0) goto LAB_000856b4;
    iVar14 = -1;
LAB_0008578c:
    pcVar21 = *(code **)(param_1->cert + 0x144);
    if (pcVar21 != (code *)0x0) {
      iVar6 = (*pcVar21)(param_1,*(undefined4 *)(param_1->cert + 0x148));
      if (iVar6 == 0) {
        ERR_put_error(0x14,0x8a,0x179,DAT_00085d18,0x578);
        uVar12 = 0x50;
        goto LAB_00085760;
      }
      if (iVar6 < 0) {
        pcVar21 = (code *)0x4;
        unaff_r5 = (SSL_COMP *)0xffffffff;
      }
      if (iVar6 < 0) {
        param_1->rwstate = (int)pcVar21;
        return unaff_r5;
      }
      param_1->rwstate = 1;
    }
    uVar12 = *(undefined4 *)(param_1->session->krb5_client_princ + 0x2c);
    psVar3 = SSL_get_ciphers(param_1);
    pSVar4 = (SSL_CIPHER *)ssl3_choose_cipher(param_1,uVar12,psVar3);
    if (pSVar4 == (SSL_CIPHER *)0x0) {
      iVar14 = 0x585;
LAB_00085a46:
      ERR_put_error(0x14,0x8a,0xc1,DAT_00085d18,iVar14);
      uVar12 = 0x28;
    }
    else {
      (param_1->s3->tmp).new_cipher = pSVar4;
LAB_000857d8:
      if (((*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1e < 0) &&
          (param_1->verify_mode << 0x1f < 0)) ||
         (iVar6 = ssl3_digest_cached_records(param_1), iVar6 != 0)) {
        if ((param_1->version < 0x300) ||
           (iVar6 = ssl_check_clienthello_tlsext_late(param_1), 0 < iVar6)) {
          pSVar2 = (SSL_COMP *)(-iVar14 | -iVar14 >> 0x1f);
          goto LAB_00085770;
        }
        iVar14 = 0x5b8;
LAB_000859f8:
        ERR_put_error(0x14,0x8a,0xe2,DAT_00085a08,iVar14);
        goto LAB_00085768;
      }
LAB_000857f8:
      uVar12 = 0x50;
    }
LAB_00085760:
    ssl3_send_alert(param_1,2,uVar12);
  }
  else {
    bVar30 = iVar14 == 0x2110;
    if (bVar30) {
      iVar14 = 0x2111;
    }
    if (bVar30) {
      param_1->state = iVar14;
    }
LAB_000856b4:
    p_Var18 = param_1->method->ssl_get_message;
    param_1->max_cert_list = 1;
    pSVar2 = (SSL_COMP *)(*p_Var18)(param_1,0x2111,0x2112,1,0x4000,&local_34);
    if (local_34 == 0) {
      return pSVar2;
    }
    puVar20 = (undefined4 *)param_1->init_msg;
    param_1->max_cert_list = 0;
    if ((int)pSVar2 < 0x23) {
      iVar14 = 0x3b3;
      local_38 = puVar20;
      goto LAB_00085750;
    }
    local_38 = (undefined4 *)((int)puVar20 + 2);
    iVar14 = *(int *)(param_1->method->ssl3_enc + 0x38);
    uVar15 = (uint)CONCAT11(*(byte *)puVar20,*(byte *)((int)puVar20 + 1));
    param_1->first_packet = uVar15;
    if (-1 < iVar14 << 0x1c) {
      if (param_1->version <= (int)uVar15) goto LAB_0008580a;
LAB_00085728:
      ERR_put_error(0x14,0x8a,0x10b,DAT_00085a08,0x3c1);
      if (((param_1->first_packet >> 8 == 3) && (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0))
         && (param_1->write_hash == (EVP_MD_CTX *)0x0)) {
        param_1->version = param_1->first_packet;
        uVar12 = 0x46;
      }
      else {
        uVar12 = 0x46;
      }
      goto LAB_00085760;
    }
    if (param_1->version < (int)uVar15) {
      iVar14 = param_1->method->version + -0x1ffff;
      if (iVar14 != 0) {
        iVar14 = 1;
      }
      if (iVar14 != 0) goto LAB_00085728;
    }
LAB_0008580a:
    lVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
    puVar23 = (undefined4 *)((int)puVar20 + (int)pSVar2);
    if (lVar5 << 0x12 < 0) {
      if (puVar23 <= (undefined4 *)((int)local_38 + *(byte *)(local_38 + 8) + 0x21)) {
        iVar14 = 0x3da;
        goto LAB_00085750;
      }
      if (*(byte *)((int)local_38 + *(byte *)(local_38 + 8) + 0x21) == 0) {
        return (SSL_COMP *)0x1;
      }
    }
    puVar11 = (undefined4 *)((int)local_38 + 0x21);
    uVar28 = local_38[1];
    uVar29 = local_38[2];
    uVar12 = local_38[3];
    psVar26 = param_1->s3;
    *(undefined4 *)psVar26->client_random = *local_38;
    *(undefined4 *)(psVar26->client_random + 4) = uVar28;
    *(undefined4 *)(psVar26->client_random + 8) = uVar29;
    *(undefined4 *)(psVar26->client_random + 0xc) = uVar12;
    uVar12 = local_38[4];
    uVar28 = local_38[5];
    uVar29 = local_38[6];
    *(undefined4 *)(psVar26->client_random + 0x1c) = local_38[7];
    *(undefined4 *)(psVar26->client_random + 0x10) = uVar12;
    *(undefined4 *)(psVar26->client_random + 0x14) = uVar28;
    *(undefined4 *)(psVar26->client_random + 0x18) = uVar29;
    uVar15 = (uint)*(byte *)(local_38 + 8);
    local_38 = puVar11;
    if (puVar23 < (undefined4 *)((int)puVar11 + uVar15)) {
      iVar14 = 0x3ec;
      goto LAB_00085750;
    }
    param_1->hit = 0;
    if ((param_1->new_session == 0) || (-1 < param_1->references << 0xf)) {
      iVar14 = ssl_get_prev_session(param_1,puVar11,uVar15,puVar23);
      if (iVar14 == 1) {
        if (param_1->version != param_1->session->ssl_version) goto LAB_000858b6;
        param_1->hit = 1;
        goto LAB_000858c2;
      }
      if (iVar14 != -1) goto LAB_000858b6;
    }
    else {
LAB_000858b6:
      iVar14 = ssl_get_new_session(param_1,1);
      if (iVar14 != 0) {
LAB_000858c2:
        puVar11 = (undefined4 *)((int)local_38 + uVar15);
        if (*(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c < 0) {
          puVar16 = (undefined4 *)((int)puVar11 + 1);
          if (puVar23 < puVar16) {
            iVar14 = 0x41e;
            local_38 = puVar11;
          }
          else {
            uVar15 = (uint)*(byte *)((int)local_38 + uVar15);
            local_38 = puVar16;
            if ((undefined4 *)((int)puVar16 + uVar15) <= puVar23) {
              lVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
              if ((lVar5 << 0x12 < 0) && (uVar15 != 0)) {
                memcpy(param_1->d1->rcvd_cookie,local_38,uVar15);
                if (*(code **)(param_1->psk_server_callback + 0x7c) == (code *)0x0) {
                  pdVar17 = param_1->d1;
                  iVar14 = memcmp(pdVar17->rcvd_cookie,pdVar17->cookie,pdVar17->cookie_len);
                  if (iVar14 != 0) {
                    iVar14 = 0x447;
                    goto LAB_00085dbc;
                  }
                }
                else {
                  iVar14 = (**(code **)(param_1->psk_server_callback + 0x7c))
                                     (param_1,param_1->d1->rcvd_cookie,uVar15);
                  if (iVar14 == 0) {
                    iVar14 = 0x43e;
LAB_00085dbc:
                    ERR_put_error(0x14,0x8a,0x134,DAT_00085ea0,iVar14);
                    uVar12 = 0x28;
                    goto LAB_00085760;
                  }
                }
                iVar14 = -2;
              }
              else {
                iVar14 = -1;
              }
              local_38 = (undefined4 *)((int)local_38 + uVar15);
              if (param_1->method->version != 0x1ffff) goto LAB_0008592c;
              if ((0xfefd < param_1->first_packet) || (param_1->references << 4 < 0)) {
                if ((*(uint *)(param_1->cert + 0x38) & 0x30000) == 0) {
                  if ((param_1->first_packet < 0xff00) && (-1 < param_1->references << 5)) {
                    param_1->version = 0xfeff;
                    pSVar10 = DTLSv1_server_method();
                    param_1->method = pSVar10;
                    goto LAB_00085de2;
                  }
                  iVar14 = 0x10b;
                  iVar6 = 0x461;
                }
                else {
                  iVar6 = 0x457;
                  iVar14 = 0x183;
                }
                ERR_put_error(0x14,0x8a,iVar14,DAT_00085d18,iVar6);
                uVar12 = 0x46;
                param_1->version = param_1->first_packet;
                goto LAB_00085760;
              }
              param_1->version = 0xfefd;
              pSVar10 = (SSL_METHOD *)DTLSv1_2_server_method();
              param_1->method = pSVar10;
LAB_00085de2:
              param_1->session->ssl_version = param_1->version;
              goto LAB_0008592c;
            }
            iVar14 = 0x425;
          }
        }
        else {
          iVar14 = -1;
          local_38 = puVar11;
LAB_0008592c:
          puVar11 = (undefined4 *)((int)local_38 + 2);
          if (puVar11 <= puVar23) {
            uVar15 = (uint)CONCAT11(*(byte *)local_38,*(byte *)((int)local_38 + 1));
            local_38 = puVar11;
            if (uVar15 == 0) {
              ERR_put_error(0x14,0x8a,0xb7,DAT_00085d18,0x473);
              uVar12 = 0x2f;
            }
            else if (puVar23 < (undefined4 *)((int)puVar11 + uVar15 + 1)) {
              iVar14 = 0x47b;
LAB_00085a5c:
              ERR_put_error(0x14,0x8a,0x9f,DAT_00085d18,iVar14);
              uVar12 = 0x32;
            }
            else {
              iVar6 = ssl_bytes_to_cipher_list(param_1,puVar11,uVar15,&local_30);
              if (iVar6 == 0) goto LAB_00085768;
              local_38 = (undefined4 *)(uVar15 + (int)local_38);
              puVar11 = local_38;
              if (param_1->hit != 0) {
                iVar27 = *(int *)(*(int *)(param_1->session->krb5_client_princ + 0x24) + 8);
                iVar6 = 0;
                do {
                  iVar8 = sk_num(local_30);
                  if (iVar8 <= iVar6) {
                    ERR_put_error(0x14,0x8a,0xd7,DAT_00085a08,0x4b3);
                    uVar12 = 0x2f;
                    goto LAB_00085760;
                  }
                  pvVar7 = sk_value(local_30,iVar6);
                  puVar11 = local_38;
                  iVar6 = iVar6 + 1;
                } while (*(int *)((int)pvVar7 + 8) != iVar27);
              }
              puVar16 = (undefined4 *)((int)puVar11 + 1);
              uVar15 = (uint)*(byte *)puVar11;
              local_38 = (undefined4 *)((int)puVar16 + uVar15);
              if (puVar23 < local_38) {
                iVar14 = 0x4bd;
                local_38 = puVar16;
                goto LAB_00085a5c;
              }
              if (uVar15 == 0) {
LAB_00085ab4:
                ERR_put_error(0x14,0x8a,0xbb,DAT_00085d18,0x4cc);
                uVar12 = 0x32;
                goto LAB_00085760;
              }
              if (*(byte *)((int)puVar11 + 1) != 0) {
                do {
                  if (puVar16 == (undefined4 *)((int)puVar11 + uVar15)) goto LAB_00085ab4;
                  puVar16 = (undefined4 *)((int)puVar16 + 1);
                } while (*(byte *)puVar16 != 0);
              }
              if ((0x2ff < param_1->version) &&
                 (iVar6 = ssl_parse_clienthello_tlsext(param_1,&local_38,puVar20,pSVar2), iVar6 == 0
                 )) {
                ERR_put_error(0x14,0x8a,0xe3,DAT_00085ea0,0x4d3);
                goto LAB_00085768;
              }
              iVar6 = ssl_fill_hello_random(param_1,1,param_1->s3->server_random,0x20);
              if (iVar6 < 1) goto LAB_000857f8;
              p_Var19 = (_STACK *)param_1->hit;
              if (((p_Var19 == (_STACK *)0x0) && (0x300 < param_1->version)) &&
                 (pcVar21 = (code *)param_1->tls_session_ticket_ext_cb_arg, pcVar21 != (code *)0x0))
              {
                pSVar13 = param_1->session;
                ptVar24 = param_1->tls_session_secret_cb;
                pSVar13->master_key_length = 0x30;
                local_2c[0] = p_Var19;
                iVar6 = (*pcVar21)(param_1,pSVar13->master_key,&pSVar13->master_key_length,local_30,
                                   local_2c,ptVar24);
                p_Var1 = local_30;
                if (iVar6 == 0) goto LAB_00085b86;
                pSVar13 = param_1->session;
                param_1->hit = 1;
                *(undefined4 *)(pSVar13->krb5_client_princ + 0x10) = 0;
                *(_STACK **)(pSVar13->krb5_client_princ + 0x2c) = local_30;
                local_30 = p_Var19;
                if (local_2c[0] != (_STACK *)0x0) {
LAB_00085b56:
                  p_Var19 = &param_1->cipher_list->stack;
                  *(_STACK **)(pSVar13->krb5_client_princ + 0x24) = local_2c[0];
                  if (p_Var19 != (_STACK *)0x0) {
                    sk_free(p_Var19);
                  }
                  if (&param_1->cipher_list_by_id->stack != (_STACK *)0x0) {
                    sk_free(&param_1->cipher_list_by_id->stack);
                  }
                  p_Var19 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                  param_1->cipher_list = (stack_st_SSL_CIPHER *)p_Var19;
                  p_Var19 = sk_dup(*(_STACK **)(param_1->session->krb5_client_princ + 0x2c));
                  param_1->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var19;
                  goto LAB_00085b86;
                }
                psVar3 = SSL_get_ciphers(param_1);
                local_2c[0] = (_STACK *)ssl3_choose_cipher(param_1,p_Var1,psVar3);
                if (local_2c[0] != (_STACK *)0x0) {
                  pSVar13 = param_1->session;
                  goto LAB_00085b56;
                }
                iVar14 = 0x4fd;
                goto LAB_00085a46;
              }
LAB_00085b86:
              pSVar13 = param_1->session;
              uVar25 = *(uint *)(pSVar13->krb5_client_princ + 0x20);
              (param_1->s3->tmp).new_compression = (SSL_COMP *)0x0;
              if (uVar25 != 0) {
                if ((param_1->references & 0x20000U) == 0) {
                  unaff_r5 = (SSL_COMP *)0x0;
                  iVar6 = 0;
                  do {
                    iVar27 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                    if (iVar27 <= iVar6) {
                      psVar26 = param_1->s3;
                      goto LAB_00085bdc;
                    }
                    unaff_r5 = (SSL_COMP *)
                               sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar6);
                    iVar6 = iVar6 + 1;
                  } while (unaff_r5->id != uVar25);
                  psVar26 = param_1->s3;
                  (psVar26->tmp).new_compression = unaff_r5;
LAB_00085bdc:
                  if ((psVar26->tmp).new_compression == (SSL_COMP *)0x0) {
                    ERR_put_error(0x14,0x8a,0x155,DAT_00085ea0,0x52a);
                    uVar12 = 0x50;
                  }
                  else {
                    iVar6 = 0;
                    do {
                      puVar11 = (undefined4 *)((int)puVar11 + 1);
                      if (*(byte *)puVar11 == uVar25) {
                        if (iVar6 < (int)uVar15) goto LAB_00085c00;
                        break;
                      }
                      iVar6 = iVar6 + 1;
                    } while (iVar6 < (int)uVar15);
                    ERR_put_error(0x14,0x8a,0x156,DAT_00085ea0,0x535);
                    uVar12 = 0x2f;
                  }
                }
                else {
                  ERR_put_error(0x14,0x8a,0x154,DAT_00085ea0,0x51d);
                  uVar12 = 0x50;
                }
                goto LAB_00085760;
              }
              if (param_1->hit != 0) {
LAB_00085d20:
                if (param_1->references << 1 < 0) {
                  p_Var19 = *(_STACK **)(pSVar13->krb5_client_princ + 0x2c);
                  pSVar22 = (SSL_CIPHER *)0x0;
                  pSVar4 = (SSL_CIPHER *)0x0;
                  iVar6 = 0;
                  while( true ) {
                    iVar27 = sk_num(p_Var19);
                    iVar8 = iVar6 + 1;
                    if (iVar27 <= iVar6) break;
                    pSVar9 = (SSL_CIPHER *)sk_value(p_Var19,iVar6);
                    if ((pSVar9->algorithm_enc & 0x20) != 0) {
                      pSVar22 = pSVar9;
                    }
                    iVar6 = iVar8;
                    if ((pSVar9->algo_strength & 2) != 0) {
                      pSVar4 = pSVar9;
                    }
                  }
                  if (pSVar22 == (SSL_CIPHER *)0x0) {
                    if (pSVar4 == (SSL_CIPHER *)0x0) {
                      (param_1->s3->tmp).new_cipher =
                           *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24);
                    }
                    else {
                      (param_1->s3->tmp).new_cipher = pSVar4;
                    }
                  }
                  else {
                    (param_1->s3->tmp).new_cipher = pSVar22;
                  }
                }
                else {
                  (param_1->s3->tmp).new_cipher =
                       *(SSL_CIPHER **)(pSVar13->krb5_client_princ + 0x24);
                }
                goto LAB_000857d8;
              }
              if (((param_1->references & 0x20000U) == 0) &&
                 (*(_STACK **)(param_1->psk_server_callback + 0x98) != (_STACK *)0x0)) {
                iVar27 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
                for (iVar6 = 0; iVar6 < iVar27; iVar6 = iVar6 + 1) {
                  unaff_r5 = (SSL_COMP *)
                             sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar6);
                  puVar20 = puVar11;
                  do {
                    puVar20 = (undefined4 *)((int)puVar20 + 1);
                    if ((uint)*(byte *)puVar20 == unaff_r5->id) {
                      (param_1->s3->tmp).new_compression = unaff_r5;
                      goto LAB_00085c00;
                    }
                  } while (puVar20 != (undefined4 *)(uVar15 + (int)puVar11));
                }
                unaff_r5 = (SSL_COMP *)0x0;
LAB_00085c00:
                if (param_1->hit != 0) {
                  pSVar13 = param_1->session;
                  goto LAB_00085d20;
                }
                pSVar13 = param_1->session;
                if (unaff_r5 != (SSL_COMP *)0x0) {
                  unaff_r5 = (SSL_COMP *)unaff_r5->id;
                }
              }
              else {
                unaff_r5 = (SSL_COMP *)0x0;
              }
              *(SSL_COMP **)(pSVar13->krb5_client_princ + 0x20) = unaff_r5;
              if (*(_STACK **)(pSVar13->krb5_client_princ + 0x2c) != (_STACK *)0x0) {
                sk_free(*(_STACK **)(pSVar13->krb5_client_princ + 0x2c));
                pSVar13 = param_1->session;
              }
              *(_STACK **)(pSVar13->krb5_client_princ + 0x2c) = local_30;
              if (local_30 != (_STACK *)0x0) {
                local_30 = (_STACK *)0x0;
                iVar6 = tls1_set_server_sigalgs(param_1);
                if (iVar6 != 0) goto LAB_0008578c;
                iVar14 = 0x56f;
                goto LAB_000859f8;
              }
              ERR_put_error(0x14,0x8a,0x44,DAT_00085ea0,0x56a);
              uVar12 = 0x50;
            }
            goto LAB_00085760;
          }
          iVar14 = 0x46c;
        }
LAB_00085750:
        ERR_put_error(0x14,0x8a,0xa0,DAT_00085a08,iVar14);
        uVar12 = 0x32;
        goto LAB_00085760;
      }
    }
  }
LAB_00085768:
  pSVar2 = (SSL_COMP *)0xffffffff;
  param_1->state = 5;
LAB_00085770:
  if (local_30 != (_STACK *)0x0) {
    sk_free(local_30);
  }
  return pSVar2;
}


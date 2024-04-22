
undefined4 ssl_parse_serverhello_tlsext(SSL *param_1,undefined4 *param_2,int param_3,int param_4)

{
  short sVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  long lVar7;
  SSL_CTX *__dest;
  char *pcVar8;
  uint uVar9;
  uint uVar10;
  ssl3_state_st *psVar11;
  SSL_SESSION *pSVar12;
  undefined *puVar13;
  code *pcVar14;
  uint uVar15;
  SSL_SESSION *pSVar16;
  ssl3_state_st *psVar17;
  undefined *puVar18;
  undefined *puVar19;
  undefined *puVar20;
  byte local_31;
  undefined4 local_30;
  void *local_2c [2];
  
  local_30 = 0xffffffff;
  if (param_1->version < 0x300) {
LAB_00072900:
    uVar4 = 1;
  }
  else {
    puVar18 = (undefined *)*param_2;
    pvVar5 = (void *)param_1->s3[1].delay_buf_pop_ret;
    param_1->s3->next_proto_neg_seen = 0;
    param_1->tlsext_ocsp_resplen = 0;
    if (pvVar5 != (void *)0x0) {
      CRYPTO_free(pvVar5);
      param_1->s3[1].delay_buf_pop_ret = 0;
    }
    param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile & 0xfffffffc);
    if (puVar18 < (undefined *)(param_3 + param_4 + -2)) {
      puVar20 = puVar18 + 2 + CONCAT11(*puVar18,puVar18[1]);
      if (puVar20 == (undefined *)(param_3 + param_4)) {
        bVar3 = false;
        bVar2 = false;
        puVar18 = puVar18 + 2;
LAB_000729dc:
        puVar13 = puVar18;
        if ((undefined *)(param_3 + param_4 + -4) < puVar13) {
          if (puVar20 != puVar13) goto LAB_00072954;
          if (((param_1->hit == 0) && (bVar2)) && ((char *)param_1->tlsext_debug_arg != (char *)0x0)
             ) {
            pSVar16 = param_1->session;
            if (*(int *)(pSVar16->krb5_client_princ + 0x40) != 0) goto LAB_00072954;
            pcVar8 = BUF_strdup((char *)param_1->tlsext_debug_arg);
            pSVar12 = param_1->session;
            *(char **)(pSVar16->krb5_client_princ + 0x40) = pcVar8;
            if (*(int *)(pSVar12->krb5_client_princ + 0x40) == 0) goto LAB_00072c60;
          }
          *param_2 = puVar20;
LAB_0007297c:
          if (!bVar3) goto LAB_00072980;
          goto LAB_0007298a;
        }
        puVar19 = puVar13 + 4;
        uVar9 = (uint)CONCAT11(puVar13[2],puVar13[3]);
        puVar18 = puVar19 + uVar9;
        sVar1 = CONCAT11(*puVar13,puVar13[1]);
        if (puVar20 < puVar18) goto LAB_0007297c;
        if ((code *)param_1->max_send_fragment != (code *)0x0) {
          (*(code *)param_1->max_send_fragment)
                    (param_1,1,sVar1,puVar19,uVar9,param_1->tlsext_debug_cb);
        }
        if (sVar1 == 0) {
          if ((param_1->tlsext_debug_arg == (void *)0x0) || (uVar9 != 0)) {
LAB_00072c60:
            local_30 = 0x70;
            goto LAB_00072958;
          }
          bVar2 = true;
          goto LAB_000729dc;
        }
        if (sVar1 == 0xb) {
          uVar15 = (uint)(byte)puVar13[4];
          if (uVar15 != uVar9 - 1) goto LAB_00072954;
          if (param_1->hit == 0) {
            pSVar16 = param_1->session;
            *(undefined4 *)(pSVar16->krb5_client_princ + 0x44) = 0;
            if (*(void **)(pSVar16->krb5_client_princ + 0x48) != (void *)0x0) {
              CRYPTO_free(*(void **)(pSVar16->krb5_client_princ + 0x48));
              pSVar16 = param_1->session;
            }
            pvVar5 = CRYPTO_malloc(uVar15,DAT_00072c68,0xa17);
            *(void **)(pSVar16->krb5_client_princ + 0x48) = pvVar5;
            if (pvVar5 == (void *)0x0) {
LAB_00072cba:
              local_30 = 0x50;
              goto LAB_00072958;
            }
            pSVar16 = param_1->session;
            *(uint *)(pSVar16->krb5_client_princ + 0x44) = uVar15;
            memcpy(*(void **)(pSVar16->krb5_client_princ + 0x48),puVar13 + 5,uVar15);
          }
          goto LAB_000729dc;
        }
        if (sVar1 == 0x23) {
          if ((param_1->tlsext_session_ticket != (TLS_SESSION_TICKET_EXT *)0x0) &&
             (iVar6 = (*(code *)param_1->tlsext_session_ticket)
                                (param_1,puVar19,uVar9,param_1->tls_session_ticket_ext_cb),
             iVar6 == 0)) goto LAB_00072cba;
          lVar7 = SSL_ctrl(param_1,0x20,0,(void *)0x0);
          if ((lVar7 << 0x11 < 0) || (uVar9 != 0)) goto LAB_00072ca0;
          param_1->tlsext_ocsp_resplen = 1;
          goto LAB_000729dc;
        }
        if (sVar1 == 5) {
          if ((param_1->servername_done == -1) || (uVar9 != 0)) {
LAB_00072ca0:
            local_30 = 0x6e;
            goto LAB_00072958;
          }
          param_1->tlsext_status_type = 1;
          goto LAB_000729dc;
        }
        if (sVar1 == 0x3374) {
          if ((param_1->s3->tmp).finish_md_len != 0) {
LAB_00072a70:
            iVar6 = custom_ext_parse(param_1,0,sVar1,puVar19,uVar9,&local_30);
            if (iVar6 < 1) goto LAB_00072958;
            goto LAB_000729dc;
          }
          pcVar14 = *(code **)(param_1->psk_server_callback + 0x1ac);
          if (pcVar14 == (code *)0x0) {
            local_30 = 0x6e;
            goto LAB_00072958;
          }
          if (uVar9 != 0) {
            uVar10 = (uint)(byte)puVar13[4];
            uVar15 = 0;
            if (uVar10 != 0) {
              while( true ) {
                uVar15 = uVar15 + uVar10 + 1;
                if (uVar9 <= uVar15) break;
                uVar10 = (uint)(byte)puVar19[uVar15];
                if (uVar10 == 0) goto LAB_00072ccc;
              }
              if (uVar9 == uVar15) goto LAB_00072b6e;
            }
LAB_00072ccc:
            local_30 = 0x32;
            goto LAB_00072958;
          }
LAB_00072b6e:
          iVar6 = (*pcVar14)(param_1,local_2c,&local_31,puVar19,uVar9,
                             *(undefined4 *)(param_1->psk_server_callback + 0x1b0));
          if (iVar6 == 0) {
            __dest = (SSL_CTX *)CRYPTO_malloc((uint)local_31,DAT_00072c68,0xa7e);
            param_1->initial_ctx = __dest;
            if (__dest != (SSL_CTX *)0x0) {
              memcpy(__dest,local_2c[0],(uint)local_31);
              *(byte *)&param_1->next_proto_negotiated = local_31;
              param_1->s3->next_proto_neg_seen = 1;
              goto LAB_000729dc;
            }
          }
          local_30 = 0x50;
          goto LAB_00072958;
        }
        if (sVar1 == 0x10) {
          if (param_1[1].init_buf == (BUF_MEM *)0x0) goto LAB_00072ca0;
          if (((uVar9 < 4) || ((uint)CONCAT11(puVar13[4],puVar13[5]) != uVar9 - 2)) ||
             (uVar15 = (uint)(byte)puVar13[6], uVar15 != uVar9 - 3)) goto LAB_00072954;
          psVar17 = param_1->s3;
          if ((void *)psVar17[1].delay_buf_pop_ret != (void *)0x0) {
            CRYPTO_free((void *)psVar17[1].delay_buf_pop_ret);
            psVar17 = param_1->s3;
          }
          pvVar5 = CRYPTO_malloc(uVar15,DAT_00072c68,0xaa9);
          psVar11 = param_1->s3;
          psVar17[1].delay_buf_pop_ret = (int)pvVar5;
          pvVar5 = (void *)psVar11[1].delay_buf_pop_ret;
          if (pvVar5 == (void *)0x0) goto LAB_00072cba;
          memcpy(pvVar5,puVar13 + 7,uVar15);
          *(uint *)param_1->s3[1].read_sequence = uVar15;
          goto LAB_000729dc;
        }
        if (sVar1 == -0xff) {
          iVar6 = ssl_parse_serverhello_renegotiate_ext(param_1,puVar19,uVar9,&local_30);
          if (iVar6 == 0) goto LAB_00072958;
          bVar3 = true;
          goto LAB_000729dc;
        }
        if (sVar1 == 0xf) {
          if (puVar13[4] == '\x01') {
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 1);
          }
          else {
            if (puVar13[4] != '\x02') {
              local_30 = 0x2f;
              goto LAB_00072958;
            }
            param_1->srtp_profile = (SRTP_PROTECTION_PROFILE *)((uint)param_1->srtp_profile | 3);
          }
          goto LAB_000729dc;
        }
        if ((-1 < *(int *)(param_1->method->ssl3_enc + 0x38) << 0x1c) || (sVar1 != 0xe))
        goto LAB_00072a70;
        iVar6 = ssl_parse_serverhello_use_srtp_ext(param_1,puVar19,uVar9,&local_30);
        if (iVar6 == 0) goto LAB_000729dc;
      }
      else {
LAB_00072954:
        local_30 = 0x32;
      }
    }
    else {
LAB_00072980:
      if ((param_1->references & 0x40004U) != 0) {
LAB_0007298a:
        iVar6 = ssl_check_serverhello_tlsext(param_1);
        if (iVar6 < 1) {
          ERR_put_error(0x14,0x12f,0x113,DAT_00072c68,0xc8f);
          return 0;
        }
        goto LAB_00072900;
      }
      local_30 = 0x28;
      ERR_put_error(0x14,0x141,0x152,DAT_00072c68,0xafb);
    }
LAB_00072958:
    ssl3_send_alert(param_1,2,local_30);
    uVar4 = 0;
  }
  return uVar4;
}


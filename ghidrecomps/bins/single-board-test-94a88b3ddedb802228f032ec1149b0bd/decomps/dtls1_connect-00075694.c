
int dtls1_connect(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  BIO *pBVar5;
  BUF_MEM *str;
  SSL_CIPHER *pSVar6;
  SSL_METHOD *pSVar7;
  dtls1_state_st *pdVar8;
  SSL_COMP *pSVar9;
  uint uVar10;
  ssl3_state_st *psVar11;
  SSL_SESSION *pSVar12;
  _func_3296 *p_Var13;
  _func_3294 *p_Var14;
  int iVar15;
  _func_3206 *p_Var16;
  ssl3_enc_method *psVar17;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  int local_34;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var14 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var14 == (_func_3294 *)0x0) {
    p_Var14 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
    uVar2 = param_1->tlsext_heartbeat;
  }
  else {
    uVar2 = param_1->tlsext_heartbeat;
  }
  if (uVar2 != 0) {
    dtls1_stop_timer(param_1);
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar3 = param_1->state;
LAB_000756fc:
  iVar15 = iVar3;
  if (0x1173 < iVar15) goto LAB_00075764;
LAB_00075704:
  if (iVar15 < 0x1170) {
    if (iVar15 < 0x1128) {
      if (0x1125 < iVar15) {
        local_2c[0] = 0;
        p_Var16 = param_1->method->ssl_get_message;
        param_1->max_cert_list = 1;
        local_34 = (*p_Var16)(param_1,0x1126,0x1127,-1,param_1->mode,local_2c);
        param_1->max_cert_list = 0;
        if (local_2c[0] == 0) {
          if (local_34 < 1) goto LAB_0007587a;
        }
        else {
          psVar11 = param_1->s3;
          if ((psVar11->tmp).message_type == 3) {
            uVar2 = (uint)*(byte *)((int)param_1->init_msg + 2);
            memcpy(param_1->d1->cookie,(void *)((int)param_1->init_msg + 3),uVar2);
            pdVar8 = param_1->d1;
            pdVar8->send_cookie = 1;
            pdVar8->cookie_len = uVar2;
          }
          else {
            param_1->d1->send_cookie = 0;
            (psVar11->tmp).reuse_message = 1;
          }
        }
        dtls1_stop_timer(param_1);
        uVar2 = 0;
        psVar11 = param_1->s3;
        uVar10 = param_1->d1->send_cookie;
        param_1->init_num = 0;
        if (uVar10 == 0) {
          iVar3 = 0x1130;
        }
        else {
          iVar3 = 0x1110;
        }
        param_1->state = iVar3;
        goto LAB_00075a30;
      }
      if (iVar15 == 0x1100) {
        param_1->rwstate = 2;
        lVar4 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar4) {
          psVar11 = param_1->s3;
          param_1->rwstate = 1;
          uVar2 = 0;
          param_1->state = (psVar11->tmp).next_state;
          goto LAB_00075a30;
        }
        iVar3 = BIO_test_flags(param_1->wbio,8);
        local_34 = -1;
        if (iVar3 == 0) {
          param_1->rwstate = 1;
          local_34 = -1;
          param_1->state = (param_1->s3->tmp).next_state;
        }
        goto LAB_0007587a;
      }
      if (iVar15 < 0x1101) {
        if (iVar15 == 0x1000) goto LAB_000759b0;
        if (iVar15 == 0x1003) goto LAB_000759b0;
        if (iVar15 == 3) {
          ssl3_cleanup_key_block(param_1);
          if (-1 < param_1->s3->flags << 0x1d) {
            ssl_free_wbio_buffer(param_1);
          }
          param_1->init_num = 0;
          param_1->tlsext_hb_seq = 0;
          param_1->new_session = 0;
          ssl_update_cache(param_1,1);
          if (param_1->hit == 0) {
            p_Var13 = param_1->psk_server_callback;
          }
          else {
            p_Var13 = param_1->psk_server_callback;
            *(int *)(p_Var13 + 0x58) = *(int *)(p_Var13 + 0x58) + 1;
          }
          iVar3 = *(int *)(p_Var13 + 0x3c);
          param_1->handshake_func = DAT_00075da8;
          *(int *)(p_Var13 + 0x3c) = iVar3 + 1;
          if (p_Var14 != (_func_3294 *)0x0) {
            (*p_Var14)(param_1,0x20,1);
          }
          pdVar8 = param_1->d1;
          local_34 = 1;
          pdVar8->handshake_read_seq = 0;
          pdVar8->next_handshake_write_seq = 0;
          goto LAB_0007587a;
        }
      }
      else if (0x110f < iVar15) {
        if (iVar15 < 0x1112) {
          param_1->shutdown = 0;
          ssl3_init_finished_mac(param_1);
          dtls1_start_timer(param_1);
          local_34 = ssl3_client_hello(param_1);
          if (0 < local_34) {
            if (param_1->d1->send_cookie == 0) {
              param_1->state = 0x1120;
            }
            else {
              param_1->state = 0x1100;
              (param_1->s3->tmp).next_state = 0x1120;
            }
            param_1->init_num = 0;
            if (param_1->bbio != param_1->wbio) {
              pBVar5 = BIO_push(param_1->bbio,param_1->wbio);
              psVar11 = param_1->s3;
              uVar2 = 0;
              param_1->wbio = pBVar5;
              goto LAB_00075a30;
            }
            goto LAB_00075b8a;
          }
          goto LAB_0007587a;
        }
        if (iVar15 - 0x1120U < 2) {
          local_34 = ssl3_get_server_hello(param_1);
          if (0 < local_34) {
            uVar2 = 0;
            param_1->init_num = 0;
            if (param_1->hit == 0) {
              iVar3 = 0x1126;
            }
            else {
              iVar3 = 0x11d0;
            }
            psVar11 = param_1->s3;
            param_1->state = iVar3;
            goto LAB_00075a30;
          }
          goto LAB_0007587a;
        }
      }
    }
    else if (iVar15 < 0x1142) {
      if (0x113f < iVar15) {
        local_34 = ssl3_get_key_exchange(param_1);
        if (0 < local_34) {
          param_1->init_num = 0;
          param_1->state = 0x1150;
          iVar3 = ssl3_check_cert_and_algorithm(param_1);
          if (iVar3 != 0) {
LAB_00075b8a:
            psVar11 = param_1->s3;
            uVar2 = 0;
            goto LAB_00075a30;
          }
LAB_00075d60:
          local_34 = -1;
          param_1->state = 5;
        }
        goto LAB_0007587a;
      }
      if (iVar15 - 0x1130U < 2) {
        psVar11 = param_1->s3;
        pSVar6 = (psVar11->tmp).new_cipher;
        if (((int)(pSVar6->algorithm_auth << 0x1d) < 0) ||
           ((int)(pSVar6->algorithm_mkey << 0x17) < 0)) {
          uVar2 = 1;
          param_1->state = 0x1140;
        }
        else {
          local_34 = ssl3_get_server_certificate(param_1);
          if (local_34 < 1) goto LAB_0007587a;
          if (param_1->tlsext_status_type == 0) {
            psVar11 = param_1->s3;
            param_1->state = 0x1140;
            uVar2 = 0;
          }
          else {
            psVar11 = param_1->s3;
            param_1->state = 0x11f0;
            uVar2 = 0;
          }
        }
        param_1->init_num = 0;
        goto LAB_00075a30;
      }
    }
    else if (0x114f < iVar15) {
      if (iVar15 < 0x1152) {
        local_34 = ssl3_get_certificate_request(param_1);
        if (0 < local_34) {
          param_1->init_num = 0;
          param_1->state = 0x1160;
          uVar2 = 0;
          psVar11 = param_1->s3;
          goto LAB_00075a30;
        }
        goto LAB_0007587a;
      }
      if (iVar15 - 0x1160U < 2) {
        local_34 = ssl3_get_server_done(param_1);
        if (0 < local_34) {
          dtls1_stop_timer(param_1);
          psVar11 = param_1->s3;
          uVar2 = 0;
          if ((psVar11->tmp).cert_req == 0) {
            iVar3 = 0x1180;
          }
          else {
            iVar3 = 0x1170;
          }
          (psVar11->tmp).next_state = iVar3;
          param_1->state = iVar3;
          param_1->init_num = 0;
          goto LAB_00075a30;
        }
        goto LAB_0007587a;
      }
    }
LAB_00075864:
    ERR_put_error(0x14,0xf9,0xff,DAT_00075980,0x2fc);
    local_34 = -1;
  }
  else {
    dtls1_start_timer(param_1);
    local_34 = ssl3_send_client_certificate(param_1);
    if (0 < local_34) {
      param_1->state = 0x1180;
      param_1->init_num = 0;
      uVar2 = (param_1->s3->tmp).reuse_message;
      iVar3 = iVar15;
      do {
        if (uVar2 != 0) {
LAB_00075a3a:
          iVar3 = param_1->state;
          goto LAB_000756fc;
        }
        if ((param_1->ctx != (SSL_CTX *)0x0) &&
           (local_34 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), local_34 < 1)) break;
        if (p_Var14 == (_func_3294 *)0x0) goto LAB_00075a3a;
        iVar15 = param_1->state;
        if (iVar3 == iVar15) goto LAB_000756fc;
        param_1->state = iVar3;
        (*p_Var14)(param_1,0x1001,1);
        param_1->state = iVar15;
        if (iVar15 < 0x1174) goto LAB_00075704;
LAB_00075764:
        if (iVar15 < 0x11d2) {
          if (iVar15 < 0x11d0) {
            if (iVar15 < 0x1192) {
              if (iVar15 < 0x1190) {
                if (1 < iVar15 - 0x1180U) goto LAB_00075864;
                dtls1_start_timer(param_1);
                local_34 = ssl3_send_client_key_exchange(param_1);
                if (local_34 < 1) break;
                psVar11 = param_1->s3;
                uVar2 = 0;
                iVar3 = (psVar11->tmp).cert_req;
                param_1->init_num = 0;
                if (iVar3 == 1) {
                  iVar3 = 0x1190;
                }
                else {
                  iVar3 = 0x11a0;
                }
                param_1->state = iVar3;
              }
              else {
                dtls1_start_timer(param_1);
                local_34 = ssl3_send_client_verify(param_1);
                if (local_34 < 1) break;
                param_1->init_num = 0;
                param_1->state = 0x11a0;
                uVar2 = 0;
                psVar11 = param_1->s3;
              }
            }
            else {
              if (iVar15 < 0x11a0) goto LAB_00075864;
              if (iVar15 < 0x11a2) {
                if (param_1->hit == 0) {
                  dtls1_start_timer(param_1);
                }
                local_34 = dtls1_send_change_cipher_spec(param_1,0x11a0,0x11a1);
                if (local_34 < 1) break;
                pSVar12 = param_1->session;
                param_1->init_num = 0;
                pSVar6 = (param_1->s3->tmp).new_cipher;
                pSVar9 = (param_1->s3->tmp).new_compression;
                param_1->state = 0x11b0;
                *(SSL_CIPHER **)(pSVar12->krb5_client_princ + 0x24) = pSVar6;
                if (pSVar9 != (SSL_COMP *)0x0) {
                  pSVar9 = (SSL_COMP *)pSVar9->id;
                }
                pSVar7 = param_1->method;
                *(SSL_COMP **)(pSVar12->krb5_client_princ + 0x20) = pSVar9;
                iVar3 = (**(code **)(pSVar7->ssl3_enc + 8))(param_1);
                if ((iVar3 == 0) ||
                   (iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12),
                   iVar3 == 0)) goto LAB_00075d60;
                dtls1_reset_seq_numbers(param_1,2);
                psVar11 = param_1->s3;
                uVar2 = 0;
              }
              else {
                if (1 < iVar15 - 0x11b0U) goto LAB_00075864;
                if (param_1->hit == 0) {
                  dtls1_start_timer(param_1);
                }
                psVar17 = param_1->method->ssl3_enc;
                local_34 = ssl3_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar17 + 0x20),
                                              *(undefined4 *)(psVar17 + 0x24));
                if (local_34 < 1) break;
                psVar11 = param_1->s3;
                param_1->state = 0x1100;
                iVar3 = param_1->hit;
                uVar10 = psVar11->flags;
                uVar2 = uVar10 & 0xfffffffb;
                psVar11->flags = uVar2;
                if (iVar3 == 0) {
                  if (param_1->tlsext_ocsp_resplen == 0) {
                    (psVar11->tmp).next_state = 0x11d0;
                  }
                  else {
                    (psVar11->tmp).next_state = 0x11e0;
                  }
                }
                else {
                  (psVar11->tmp).next_state = 3;
                  if ((int)(uVar10 << 0x1e) < 0) {
                    param_1->state = 3;
                    psVar11->flags = uVar2 | 4;
                    psVar11->delay_buf_pop_ret = 0;
                  }
                }
                param_1->init_num = 0;
                uVar2 = 0;
              }
            }
          }
          else {
            param_1->d1[1].send_cookie = 1;
            local_34 = ssl3_get_finished(param_1);
            if (local_34 < 1) break;
            dtls1_stop_timer(param_1);
            uVar2 = 0;
            param_1->init_num = 0;
            psVar11 = param_1->s3;
            if (param_1->hit == 0) {
              iVar3 = 3;
            }
            else {
              iVar3 = 0x11a0;
            }
            param_1->state = iVar3;
          }
        }
        else if (iVar15 < 0x11f2) {
          if (iVar15 < 0x11f0) {
            if (1 < iVar15 - 0x11e0U) goto LAB_00075864;
            local_34 = ssl3_get_new_session_ticket(param_1);
            if (local_34 < 1) break;
            param_1->init_num = 0;
            param_1->state = 0x11d0;
            uVar2 = 0;
            psVar11 = param_1->s3;
          }
          else {
            local_34 = ssl3_get_cert_status(param_1);
            if (local_34 < 1) break;
            param_1->init_num = 0;
            param_1->state = 0x1140;
            uVar2 = 0;
            psVar11 = param_1->s3;
          }
        }
        else {
          if ((iVar15 != 0x4000) && (iVar15 != 0x5000)) {
            if (iVar15 != 0x3004) goto LAB_00075864;
            param_1->state = 0x1000;
            param_1->tlsext_hb_seq = 1;
            *(int *)(param_1->psk_server_callback + 0x38) =
                 *(int *)(param_1->psk_server_callback + 0x38) + 1;
          }
LAB_000759b0:
          param_1->server = 0;
          if (p_Var14 != (_func_3294 *)0x0) {
            (*p_Var14)(param_1,0x10,1);
          }
          uVar2 = param_1->version & 0xff00;
          if (uVar2 != 0x100 && uVar2 != 0xfe00) {
            ERR_put_error(0x14,0xf9,0x44,DAT_00075e04,0xe5);
            local_34 = -1;
            param_1->state = 5;
            break;
          }
          param_1->type = 0x1000;
          if (param_1->init_buf == (BUF_MEM *)0x0) {
            str = BUF_MEM_new();
            if (str == (BUF_MEM *)0x0) goto LAB_00075d60;
            iVar3 = BUF_MEM_grow(str,0x4000);
            if (iVar3 == 0) {
              param_1->state = 5;
              param_1->in_handshake = param_1->in_handshake + -1;
              local_34 = -1;
              BUF_MEM_free(str);
              goto LAB_00075880;
            }
            param_1->init_buf = str;
          }
          iVar3 = ssl3_setup_buffers(param_1);
          if ((iVar3 == 0) || (iVar3 = ssl_init_wbio_buffer(param_1,0), iVar3 == 0))
          goto LAB_00075d60;
          param_1->state = 0x1110;
          psVar11 = param_1->s3;
          *(int *)(param_1->psk_server_callback + 0x34) =
               *(int *)(param_1->psk_server_callback + 0x34) + 1;
          param_1->init_num = 0;
          memset(psVar11->client_random,0,0x20);
          pdVar8 = param_1->d1;
          uVar2 = 0;
          psVar11 = param_1->s3;
          pdVar8->send_cookie = 0;
          param_1->hit = 0;
          pdVar8[1].send_cookie = 0;
          psVar11->change_cipher_spec = 0;
        }
LAB_00075a30:
        uVar2 = uVar2 | (psVar11->tmp).reuse_message;
        iVar3 = iVar15;
      } while( true );
    }
  }
LAB_0007587a:
  param_1->in_handshake = param_1->in_handshake + -1;
LAB_00075880:
  if (p_Var14 != (_func_3294 *)0x0) {
    (*p_Var14)(param_1,0x1002,local_34);
  }
  return local_34;
}


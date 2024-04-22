
int ssl3_connect(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int val;
  long lVar4;
  BIO *pBVar5;
  BUF_MEM *str;
  SSL_CIPHER *pSVar6;
  SSL_METHOD *pSVar7;
  uint uVar8;
  SSL_SESSION *pSVar9;
  ssl3_state_st *psVar10;
  _func_3296 *p_Var11;
  SSL_COMP *pSVar12;
  ulong max;
  int iVar13;
  char *pcVar14;
  _func_3294 *p_Var15;
  size_t __n;
  ssl3_enc_method *psVar16;
  bool bVar17;
  undefined4 in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,(double)CONCAT44(in_stack_ffffffbc,in_stack_ffffffb8));
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var15 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var15 == (_func_3294 *)0x0) {
    p_Var15 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar3 = param_1->state;
LAB_00068ab2:
  iVar13 = iVar3;
  if (0x1181 < iVar13) goto LAB_00068b2e;
LAB_00068aba:
  if (iVar13 < 0x1180) {
    if (iVar13 < 0x1132) {
      if (0x112f < iVar13) {
        local_2c[0] = 0;
        if (((param_1->version < 0x301) || (param_1->tls_session_ticket_ext_cb_arg == (void *)0x0))
           || (*(int *)(param_1->session->krb5_client_princ + 0x54) == 0)) {
          psVar10 = param_1->s3;
LAB_00068f54:
          pSVar6 = (psVar10->tmp).new_cipher;
          if (((pSVar6->algorithm_auth & 0x404) == 0) && ((pSVar6->algorithm_mkey & 0x100) == 0)) {
            val = ssl3_get_server_certificate(param_1);
            if (val < 1) goto LAB_00068d3e;
            if (param_1->tlsext_status_type == 0) {
              param_1->state = 0x1140;
              psVar10 = param_1->s3;
              uVar2 = 0;
            }
            else {
              param_1->state = 0x11f0;
              psVar10 = param_1->s3;
              uVar2 = 0;
            }
          }
          else {
            uVar2 = 1;
            param_1->state = 0x1140;
          }
          param_1->init_num = 0;
          goto LAB_00068de4;
        }
        pSVar7 = param_1->method;
        max = param_1->mode;
        param_1->s3->flags = param_1->s3->flags | 0x80;
        (*pSVar7->ssl_get_message)(param_1,0x1130,0x1131,-1,max,local_2c);
        psVar10 = param_1->s3;
        psVar10->flags = psVar10->flags & 0xffffff7f;
        if (local_2c[0] != 0) {
          (psVar10->tmp).reuse_message = 1;
          if ((psVar10->tmp).message_type == 0x14) {
            param_1->hit = 1;
            param_1->init_num = 0;
            uVar2 = 0;
            param_1->state = 0x11d0;
            goto LAB_00068de4;
          }
          if (psVar10->change_cipher_spec == 0) goto LAB_00068f54;
          ERR_put_error(0x14,0x153,0x85,DAT_00068d10,0xe4e);
          ssl3_send_alert(param_1,2,10);
        }
LAB_00068c0c:
        val = -1;
        goto LAB_00068d3e;
      }
      if (iVar13 == 0x1100) {
        param_1->rwstate = 2;
        lVar4 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
        if (0 < lVar4) {
          psVar10 = param_1->s3;
          param_1->rwstate = 1;
          uVar2 = 0;
          param_1->state = (psVar10->tmp).next_state;
          goto LAB_00068de4;
        }
        goto LAB_00068c0c;
      }
      if (iVar13 < 0x1101) {
        if (iVar13 == 0x1000) goto LAB_00068d72;
        if (iVar13 == 0x1003) goto LAB_00068d72;
        if (iVar13 == 3) {
          ssl3_cleanup_key_block(param_1);
          if (param_1->init_buf != (BUF_MEM *)0x0) {
            BUF_MEM_free(param_1->init_buf);
            param_1->init_buf = (BUF_MEM *)0x0;
          }
          if (-1 < param_1->s3->flags << 0x1d) {
            ssl_free_wbio_buffer(param_1);
          }
          param_1->init_num = 0;
          param_1->tlsext_hb_seq = 0;
          param_1->new_session = 0;
          ssl_update_cache(param_1,1);
          if (param_1->hit == 0) {
            p_Var11 = param_1->psk_server_callback;
          }
          else {
            p_Var11 = param_1->psk_server_callback;
            *(int *)(p_Var11 + 0x58) = *(int *)(p_Var11 + 0x58) + 1;
          }
          iVar3 = *(int *)(p_Var11 + 0x3c);
          val = 1;
          param_1->handshake_func = DAT_00068ff0;
          *(int *)(p_Var11 + 0x3c) = iVar3 + 1;
          if (p_Var15 != (_func_3294 *)0x0) {
            val = 1;
            (*p_Var15)(param_1,0x20,1);
          }
          goto LAB_00068d3e;
        }
      }
      else if (0x110f < iVar13) {
        if (iVar13 < 0x1112) {
          param_1->shutdown = 0;
          val = ssl3_client_hello(param_1);
          if (0 < val) {
            param_1->init_num = 0;
            param_1->state = 0x1120;
            if (param_1->bbio == param_1->wbio) goto LAB_00068e20;
            pBVar5 = BIO_push(param_1->bbio,param_1->wbio);
            psVar10 = param_1->s3;
            uVar2 = 0;
            param_1->wbio = pBVar5;
            goto LAB_00068de4;
          }
          goto LAB_00068d3e;
        }
        if (iVar13 - 0x1120U < 2) {
          val = ssl3_get_server_hello(param_1);
          if (0 < val) {
            if (param_1->hit == 0) {
              param_1->state = 0x1130;
            }
            else {
              param_1->state = 0x11d0;
              if (param_1->tlsext_ocsp_resplen != 0) {
                param_1->state = 0x11e0;
              }
            }
            param_1->init_num = 0;
            uVar2 = 0;
            psVar10 = param_1->s3;
            goto LAB_00068de4;
          }
          goto LAB_00068d3e;
        }
      }
    }
    else if (iVar13 < 0x1152) {
      if (0x114f < iVar13) {
        val = ssl3_get_certificate_request(param_1);
        if (0 < val) {
          param_1->init_num = 0;
          param_1->state = 0x1160;
          uVar2 = 0;
          psVar10 = param_1->s3;
          goto LAB_00068de4;
        }
        goto LAB_00068d3e;
      }
      if (iVar13 - 0x1140U < 2) {
        val = ssl3_get_key_exchange(param_1);
        if (0 < val) {
          param_1->state = 0x1150;
          param_1->init_num = 0;
          iVar3 = ssl3_check_cert_and_algorithm(param_1);
          if (iVar3 != 0) goto LAB_00068e20;
LAB_00068fca:
          val = -1;
          param_1->state = 5;
        }
        goto LAB_00068d3e;
      }
    }
    else if (0x115f < iVar13) {
      if (iVar13 < 0x1162) {
        val = (*param_1->method->ssl_get_message)(param_1,0x1160,0x1161,0xe,0x1e,local_2c);
        if (local_2c[0] == 0) {
          if (val < 1) goto LAB_00068d3e;
        }
        else if (0 < val) {
          val = -1;
          ssl3_send_alert(param_1,2,0x32);
          ERR_put_error(0x14,0x91,0x9f,DAT_00069268,0x95b);
          param_1->state = 5;
          goto LAB_00068d3e;
        }
        psVar10 = param_1->s3;
        if ((int)(((psVar10->tmp).new_cipher)->algorithm_mkey << 0x15) < 0) {
          val = SRP_Calc_A_param(param_1);
          if (val < 1) {
            ERR_put_error(0x14,0x84,0x169,DAT_00069268,0x192);
            ssl3_send_alert(param_1,2,0x50);
            param_1->state = 5;
            goto LAB_00068d3e;
          }
          psVar10 = param_1->s3;
        }
        iVar3 = (psVar10->tmp).cert_req;
        uVar2 = 0;
        param_1->init_num = 0;
        if (iVar3 == 0) {
          iVar3 = 0x1180;
        }
        else {
          iVar3 = 0x1170;
        }
        param_1->state = iVar3;
        goto LAB_00068de4;
      }
      if (iVar13 - 0x1170U < 4) {
        val = ssl3_send_client_certificate(param_1);
        if (0 < val) {
          param_1->init_num = 0;
          param_1->state = 0x1180;
          uVar2 = 0;
          psVar10 = param_1->s3;
          goto LAB_00068de4;
        }
        goto LAB_00068d3e;
      }
    }
LAB_00068d28:
    val = -1;
    ERR_put_error(0x14,0x84,0xff,DAT_00068fec,0x281);
  }
  else {
    val = ssl3_send_client_key_exchange(param_1);
    if (0 < val) {
      psVar10 = param_1->s3;
      iVar3 = 0x1190;
      if ((psVar10->tmp).cert_req != 1) {
        iVar3 = 0x11a0;
      }
      bVar17 = psVar10->flags << 0x1b < 0;
      param_1->state = iVar3;
      if (bVar17) {
        val = 0x11a0;
      }
      if (bVar17) {
        param_1->state = val;
      }
LAB_00068aec:
      uVar2 = (psVar10->tmp).reuse_message;
      param_1->init_num = 0;
      iVar3 = iVar13;
      if (uVar2 == 0) {
        do {
          if ((param_1->ctx != (SSL_CTX *)0x0) &&
             (val = BIO_ctrl(param_1->wbio,0xb,uVar2,(void *)uVar2), val < 1)) goto LAB_00068d3e;
          if (p_Var15 == (_func_3294 *)0x0) break;
          iVar13 = param_1->state;
          if (iVar3 == iVar13) goto LAB_00068ab2;
          param_1->state = iVar3;
          (*p_Var15)(param_1,0x1001,1);
          param_1->state = iVar13;
          if (iVar13 < 0x1182) goto LAB_00068aba;
LAB_00068b2e:
          if (iVar13 < 0x11e2) {
            if (iVar13 < 0x11e0) {
              if (iVar13 < 0x11a2) {
                if (iVar13 < 0x11a0) {
                  if (1 < iVar13 - 0x1190U) goto LAB_00068d28;
                  val = ssl3_send_client_verify(param_1);
                  if (val < 1) goto LAB_00068d3e;
                  uVar2 = 0;
                  param_1->state = 0x11a0;
                  param_1->init_num = 0;
                  psVar10 = param_1->s3;
                }
                else {
                  val = ssl3_send_change_cipher_spec(param_1,0x11a0);
                  if (val < 1) goto LAB_00068d3e;
                  psVar10 = param_1->s3;
                  iVar3 = 0x11b0;
                  pSVar9 = param_1->session;
                  pSVar12 = (psVar10->tmp).new_compression;
                  if (psVar10->next_proto_neg_seen != 0) {
                    iVar3 = 0x1200;
                  }
                  *(SSL_CIPHER **)(pSVar9->krb5_client_princ + 0x24) = (psVar10->tmp).new_cipher;
                  param_1->init_num = 0;
                  param_1->state = iVar3;
                  if (pSVar12 != (SSL_COMP *)0x0) {
                    pSVar12 = (SSL_COMP *)pSVar12->id;
                  }
                  pSVar7 = param_1->method;
                  *(SSL_COMP **)(pSVar9->krb5_client_princ + 0x20) = pSVar12;
                  iVar3 = (**(code **)(pSVar7->ssl3_enc + 8))(param_1);
                  if ((iVar3 == 0) ||
                     (iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x12),
                     iVar3 == 0)) goto LAB_00068fca;
LAB_00068e20:
                  psVar10 = param_1->s3;
                  uVar2 = 0;
                }
              }
              else {
                if (iVar13 < 0x11b0) goto LAB_00068d28;
                if (iVar13 < 0x11b2) goto LAB_00068f06;
                if (1 < iVar13 - 0x11d0U) goto LAB_00068d28;
                psVar10 = param_1->s3;
                if (psVar10->change_cipher_spec == 0) {
                  psVar10->flags = psVar10->flags | 0x80;
                }
                val = ssl3_get_finished(param_1,0x11d0,0x11d1);
                if (val < 1) goto LAB_00068d3e;
                uVar2 = 0;
                param_1->init_num = 0;
                psVar10 = param_1->s3;
                if (param_1->hit == 0) {
                  iVar3 = 3;
                }
                else {
                  iVar3 = 0x11a0;
                }
                param_1->state = iVar3;
              }
            }
            else {
              val = ssl3_get_new_session_ticket(param_1);
              if (val < 1) goto LAB_00068d3e;
              param_1->init_num = 0;
              param_1->state = 0x11d0;
              uVar2 = 0;
              psVar10 = param_1->s3;
            }
          }
          else if (iVar13 < 0x1202) {
            if (iVar13 < 0x1200) {
              if (1 < iVar13 - 0x11f0U) goto LAB_00068d28;
              val = ssl3_get_cert_status(param_1);
              if (val < 1) goto LAB_00068d3e;
              param_1->init_num = 0;
              param_1->state = 0x1140;
              uVar2 = 0;
              psVar10 = param_1->s3;
            }
            else {
              if (iVar13 == 0x1200) {
                uVar2 = (uint)*(byte *)&param_1->next_proto_negotiated;
                pcVar14 = param_1->init_buf->data;
                pcVar14[4] = *(byte *)&param_1->next_proto_negotiated;
                __n = 0x20 - (uVar2 + 2 & 0x1f);
                memcpy(pcVar14 + 5,param_1->initial_ctx,uVar2);
                pcVar14[uVar2 + 5] = (char)__n;
                memset(pcVar14 + uVar2 + 6,0,__n);
                pcVar14[1] = '\0';
                pcVar14[3] = (char)__n + (char)(uVar2 + 2);
                *pcVar14 = 'C';
                pcVar14[2] = (char)(uVar2 + __n + 2 >> 8);
                param_1->init_num = uVar2 + __n + 6;
                param_1->state = 0x1201;
                param_1->init_off = 0;
              }
              val = ssl3_do_write(param_1,0x16);
              if (val < 1) goto LAB_00068d3e;
              psVar10 = param_1->s3;
              param_1->state = 0x11b0;
              uVar2 = 0;
            }
          }
          else {
            if ((iVar13 != 0x4000) && (iVar13 != 0x5000)) {
              if (iVar13 != 0x3004) goto LAB_00068d28;
              param_1->state = 0x1000;
              param_1->tlsext_hb_seq = 1;
              *(int *)(param_1->psk_server_callback + 0x38) =
                   *(int *)(param_1->psk_server_callback + 0x38) + 1;
            }
LAB_00068d72:
            param_1->server = 0;
            if (p_Var15 != (_func_3294 *)0x0) {
              (*p_Var15)(param_1,0x10,1);
            }
            if ((param_1->version & 0xff00U) != 0x300) {
              ERR_put_error(0x14,0x84,0x44,DAT_00069268,0xf0);
              val = -1;
              param_1->state = 5;
              goto LAB_00068d3e;
            }
            param_1->type = 0x1000;
            if (param_1->init_buf == (BUF_MEM *)0x0) {
              str = BUF_MEM_new();
              if (str == (BUF_MEM *)0x0) goto LAB_00068fca;
              iVar3 = BUF_MEM_grow(str,0x4000);
              if (iVar3 == 0) {
                val = -1;
                param_1->state = 5;
                param_1->in_handshake = param_1->in_handshake + -1;
                BUF_MEM_free(str);
                goto LAB_00068d44;
              }
              param_1->init_buf = str;
            }
            iVar3 = ssl3_setup_buffers(param_1);
            if (iVar3 == 0) goto LAB_00068c0c;
            iVar3 = ssl_init_wbio_buffer(param_1,0);
            if (iVar3 == 0) goto LAB_00068fca;
            ssl3_init_finished_mac(param_1);
            psVar10 = param_1->s3;
            uVar2 = 0;
            param_1->state = 0x1110;
            uVar8 = psVar10->flags;
            *(int *)(param_1->psk_server_callback + 0x34) =
                 *(int *)(param_1->psk_server_callback + 0x34) + 1;
            param_1->init_num = 0;
            psVar10->change_cipher_spec = 0;
            psVar10->flags = uVar8 & 0xffffff7f;
          }
LAB_00068de4:
          uVar2 = uVar2 | (psVar10->tmp).reuse_message;
          iVar3 = iVar13;
          if (uVar2 != 0) break;
        } while( true );
      }
      iVar3 = param_1->state;
      goto LAB_00068ab2;
    }
  }
LAB_00068d3e:
  param_1->in_handshake = param_1->in_handshake + -1;
LAB_00068d44:
  if (p_Var15 != (_func_3294 *)0x0) {
    (*p_Var15)(param_1,0x1002,val);
  }
  return val;
LAB_00068f06:
  psVar16 = param_1->method->ssl3_enc;
  val = ssl3_send_finished(param_1,0x11b0,0x11b1,*(undefined4 *)(psVar16 + 0x20),
                           *(undefined4 *)(psVar16 + 0x24));
  if (val < 1) goto LAB_00068d3e;
  psVar10 = param_1->s3;
  param_1->state = 0x1100;
  iVar3 = param_1->hit;
  uVar8 = psVar10->flags;
  uVar2 = uVar8 & 0xfffffffb;
  psVar10->flags = uVar2;
  if (iVar3 == 0) {
    if (param_1->tlsext_ocsp_resplen == 0) {
      (psVar10->tmp).next_state = 0x11d0;
    }
    else {
      (psVar10->tmp).next_state = 0x11e0;
    }
  }
  else {
    (psVar10->tmp).next_state = 3;
    if ((int)(uVar8 << 0x1e) < 0) {
      param_1->state = 3;
      psVar10->flags = uVar2 | 4;
      psVar10->delay_buf_pop_ret = 0;
    }
  }
  goto LAB_00068aec;
}


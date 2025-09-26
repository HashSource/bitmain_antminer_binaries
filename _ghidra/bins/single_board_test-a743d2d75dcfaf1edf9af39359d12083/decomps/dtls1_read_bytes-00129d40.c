
size_t dtls1_read_bytes(SSL *param_1,int param_2,void *param_3,uint param_4,int param_5)

{
  uchar uVar1;
  byte bVar2;
  ushort uVar3;
  pitem *item;
  BIO *pBVar4;
  uint uVar5;
  int iVar6;
  uchar *puVar7;
  uint uVar9;
  int iVar10;
  SSL3_RECORD *pSVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  dtls1_state_st *pdVar15;
  int *piVar16;
  _func_3294 *p_Var17;
  dtls1_state_st *pdVar18;
  ssl3_state_st *psVar19;
  int *piVar20;
  undefined4 uVar21;
  size_t sVar22;
  _func_3292 *p_Var23;
  uint *puVar24;
  ssl3_state_st *psVar25;
  _func_3294 *local_6c;
  undefined1 auStack_5c [4];
  char local_58 [52];
  uchar *puVar8;
  
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar6 = ssl3_setup_buffers(), iVar6 == 0)) {
    return 0xffffffff;
  }
  uVar14 = param_2 - 0x17;
  if (uVar14 != 0) {
    uVar14 = 1;
  }
  if (param_2 == 0 || param_2 == 0x17) {
    if (param_5 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = uVar14 & 1;
    }
    if (uVar14 != 0) goto LAB_0012a2d8;
    if (param_2 != 0x16) goto LAB_00129dbe;
  }
  else {
    if (param_2 != 0x16) {
LAB_0012a2d8:
      iVar6 = 0x312;
LAB_0012a2dc:
      ERR_put_error(0x14,0x102,0x44,"d1_pkt.c",iVar6);
      return 0xffffffff;
    }
    if (param_5 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = uVar14 & 1;
    }
    if (uVar14 != 0) goto LAB_0012a2d8;
  }
  pdVar15 = param_1->d1;
  if (pdVar15->change_cipher_spec_ok != 0) {
    puVar7 = pdVar15->handshake_fragment + 8;
    if ((int)param_4 < 1) {
      uVar14 = 0;
LAB_0012a140:
      uVar5 = 0;
      do {
        uVar12 = uVar5 + 1;
        pdVar15->handshake_fragment[uVar5 + 8] = puVar7[uVar5];
        pdVar15 = param_1->d1;
        uVar5 = uVar12;
        uVar9 = uVar14;
      } while (uVar12 < pdVar15->change_cipher_spec_ok);
    }
    else {
      uVar9 = 0;
      puVar8 = puVar7;
      do {
        puVar7 = puVar8 + 1;
        *(uchar *)((int)param_3 + uVar9) = *puVar8;
        uVar9 = uVar9 + 1;
        pdVar15 = param_1->d1;
        uVar5 = pdVar15->change_cipher_spec_ok - 1;
        pdVar15->change_cipher_spec_ok = uVar5;
        if (uVar9 == param_4) {
          uVar14 = param_4;
          if (uVar5 == 0) {
            return uVar9;
          }
          goto LAB_0012a140;
        }
        puVar8 = puVar7;
      } while (uVar5 != 0);
    }
    if (uVar9 != 0) {
      return uVar9;
    }
  }
LAB_00129dbe:
  if ((param_1->in_handshake == 0) && (uVar14 = SSL_state(param_1), (uVar14 & 0x3000) != 0)) {
    sVar22 = (*param_1->handshake_func)(param_1);
    if ((int)sVar22 < 0) {
      return sVar22;
    }
    if (sVar22 == 0) {
      iVar6 = 0x333;
LAB_0012a19c:
      ERR_put_error(0x14,0x102,0xe5,"d1_pkt.c",iVar6);
      return 0xffffffff;
    }
  }
  local_6c = (_func_3294 *)0x0;
  psVar19 = param_1->s3;
LAB_00129dde:
  param_1->rwstate = 1;
  if (((param_1->state == 3) && ((psVar19->rrec).length == 0)) &&
     (item = pqueue_pop((param_1->d1->buffered_app_data).q), item != (pitem *)0x0)) {
    psVar25 = param_1->s3;
    piVar20 = (int *)item->data;
    puVar7 = (psVar25->rbuf).buf;
    if (puVar7 != (uchar *)0x0) {
      CRYPTO_free(puVar7);
      psVar25 = param_1->s3;
    }
    uVar14 = piVar20[1];
    param_1->packet = (uchar *)*piVar20;
    param_1->packet_length = uVar14;
    piVar16 = piVar20 + 6;
    sVar22 = piVar20[3];
    iVar6 = piVar20[4];
    iVar10 = piVar20[5];
    (psVar25->rbuf).buf = (uchar *)piVar20[2];
    (psVar25->rbuf).len = sVar22;
    (psVar25->rbuf).offset = iVar6;
    (psVar25->rbuf).left = iVar10;
    pSVar11 = &param_1->s3->rrec;
    do {
      iVar6 = *piVar16;
      uVar9 = piVar16[1];
      uVar14 = piVar16[2];
      puVar7 = (uchar *)piVar16[3];
      piVar16 = piVar16 + 4;
      pSVar11->type = iVar6;
      pSVar11->length = uVar9;
      pSVar11->off = uVar14;
      pSVar11->data = puVar7;
      pSVar11 = (SSL3_RECORD *)&pSVar11->input;
    } while (piVar16 != piVar20 + 0xe);
    *(uchar **)pSVar11 = (uchar *)*piVar16;
    iVar6 = *piVar20;
    psVar25 = param_1->s3;
    *(undefined4 *)(psVar25->read_sequence + 2) = *(undefined4 *)(iVar6 + 5);
    *(undefined2 *)(psVar25->read_sequence + 6) = *(undefined2 *)(iVar6 + 9);
    CRYPTO_free(item->data);
    pitem_free(item);
    iVar6 = dtls1_handle_timeout(param_1);
    if (0 < iVar6) goto LAB_00129ddc;
LAB_00129e94:
    if ((((psVar19->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
       (iVar6 = dtls1_get_record(param_1), iVar6 < 1)) {
      sVar22 = dtls1_read_failed(param_1);
      if ((int)sVar22 < 1) {
        return sVar22;
      }
      goto LAB_00129ddc;
    }
    pdVar15 = param_1->d1;
    if ((pdVar15->mtu != 0) && ((psVar19->rrec).type != 0x16)) {
LAB_00129eb0:
      (psVar19->rrec).length = 0;
      psVar19 = param_1->s3;
      goto LAB_00129dde;
    }
    psVar25 = param_1->s3;
    if ((psVar25->change_cipher_spec != 0) && ((psVar19->rrec).type != 0x16)) {
      iVar6 = pqueue_size((pdVar15->buffered_app_data).q);
      if ((99 < iVar6) ||
         (iVar6 = dtls1_buffer_record_part_1
                            (param_1,&pdVar15->buffered_app_data,(psVar19->rrec).seq_num),
         -1 < iVar6)) goto LAB_00129eb0;
      iVar6 = 0x37d;
      goto LAB_0012a2dc;
    }
    if ((param_1->shutdown & 2U) != 0) {
      (psVar19->rrec).length = 0;
      param_1->rwstate = 1;
      return 0;
    }
    iVar6 = (psVar19->rrec).type;
    if (iVar6 == param_2) {
      uVar14 = SSL_state(param_1);
      if ((((uVar14 & 0x3000) == 0) || (param_2 != 0x17)) ||
         (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
        if ((int)param_4 < 1) {
          return param_4;
        }
        uVar14 = (psVar19->rrec).length;
        if (uVar14 <= param_4) {
          param_4 = uVar14;
        }
        memcpy(param_3,(psVar19->rrec).data + (psVar19->rrec).off,param_4);
        if (param_5 == 0) {
          uVar14 = (psVar19->rrec).length - param_4;
          (psVar19->rrec).length = uVar14;
          (psVar19->rrec).off = (psVar19->rrec).off + param_4;
          if (uVar14 == 0) {
            param_1->rstate = 0xf0;
            (psVar19->rrec).off = 0;
            return param_4;
          }
          return param_4;
        }
        return param_4;
      }
      ERR_put_error(0x14,0x102,100,"d1_pkt.c",0x397);
      uVar13 = 10;
      goto LAB_0012a344;
    }
    if (iVar6 != 0x16) {
      if (iVar6 == 0x15) {
        puVar7 = pdVar15->handshake_fragment + 2;
        puVar24 = (uint *)(pdVar15->handshake_fragment + 4);
        uVar14 = 2;
        goto LAB_00129fc8;
      }
      if (iVar6 == 0x18) {
        dtls1_process_heartbeat(param_1);
        (psVar19->rrec).length = 0;
        param_1->rwstate = 3;
        pBVar4 = SSL_get_rbio(param_1);
        BIO_clear_flags(pBVar4,0xf);
        pBVar4 = SSL_get_rbio(param_1);
        BIO_set_flags(pBVar4,9);
        return 0xffffffff;
      }
      if (iVar6 == 0x14) goto LAB_00129f48;
      if (iVar6 == 0x17) {
        psVar25->in_read_app_data = 2;
        pBVar4 = SSL_get_rbio(param_1);
        param_1->rwstate = 3;
        BIO_clear_flags(pBVar4,0xf);
        BIO_set_flags(pBVar4,9);
        return 0xffffffff;
      }
      iVar6 = 0x3fe;
LAB_0012a360:
      ERR_put_error(0x14,0x102,0xf5,"d1_pkt.c",iVar6);
      uVar13 = 10;
LAB_0012a344:
      ssl3_send_alert(param_1,2,uVar13);
      return 0xffffffff;
    }
    puVar7 = pdVar15->handshake_fragment + 8;
    puVar24 = &pdVar15->change_cipher_spec_ok;
    uVar14 = 0xc;
LAB_00129fc8:
    if ((psVar19->rrec).length < uVar14) {
      param_1->rstate = 0xf0;
      (psVar19->rrec).length = 0;
      psVar19 = psVar25;
      goto LAB_00129dde;
    }
    uVar5 = (psVar19->rrec).off;
    uVar9 = uVar5;
    do {
      puVar7[uVar9 - uVar5] = (psVar19->rrec).data[uVar9];
      uVar9 = uVar9 + 1;
      (psVar19->rrec).off = uVar9;
      (psVar19->rrec).length = (psVar19->rrec).length - 1;
    } while (uVar9 - uVar5 < uVar14);
    pdVar15 = param_1->d1;
    *puVar24 = uVar14;
LAB_00129f48:
    if (((param_1->server != 0) || (pdVar15->change_cipher_spec_ok < 0xc)) ||
       ((pdVar15->handshake_fragment[8] != '\0' ||
        ((param_1->session == (SSL_SESSION *)0x0 ||
         (*(int *)(param_1->session->krb5_client_princ + 0x24) == 0)))))) {
      if (*(uint *)(pdVar15->handshake_fragment + 4) < 2) {
        if (param_1->shutdown << 0x1f < 0) {
          param_1->rwstate = 1;
          (psVar19->rrec).length = 0;
          return 0;
        }
        iVar6 = (psVar19->rrec).type;
        if (iVar6 == 0x14) {
          dtls1_get_ccs_header((psVar19->rrec).data,auStack_5c);
          iVar6 = param_1->version;
          if (iVar6 == 0x100) {
            uVar14 = 3;
          }
          else {
            uVar14 = 1;
          }
          if ((((psVar19->rrec).length != uVar14) || ((psVar19->rrec).off != 0)) ||
             (puVar7 = (psVar19->rrec).data, *puVar7 != '\x01')) {
            ERR_put_error(0x14,0x102,0x67,"d1_pkt.c",0x4d7);
            return 0xffffffff;
          }
          p_Var23 = param_1->msg_callback;
          (psVar19->rrec).length = 0;
          if (p_Var23 != (_func_3292 *)0x0) {
            (*p_Var23)(0,iVar6,0x14,puVar7,1,param_1,param_1->msg_callback_arg);
          }
          if (param_1->d1[1].send_cookie != 0) {
            psVar19 = param_1->s3;
            param_1->d1[1].send_cookie = 0;
            psVar19->change_cipher_spec = 1;
            iVar6 = ssl3_do_change_cipher_spec(param_1);
            if (iVar6 == 0) {
              return 0xffffffff;
            }
            pdVar15 = param_1->d1;
            psVar19 = param_1->s3;
            uVar13 = *(undefined4 *)((pdVar15->next_bitmap).max_seq_num + 4);
            uVar21 = *(undefined4 *)(pdVar15->next_bitmap).max_seq_num;
            uVar3 = pdVar15->r_epoch;
            (pdVar15->bitmap).map = (pdVar15->next_bitmap).map;
            *(undefined4 *)(pdVar15->bitmap).max_seq_num = uVar21;
            *(undefined4 *)((pdVar15->bitmap).max_seq_num + 4) = uVar13;
            pdVar18 = param_1->d1;
            pdVar15->r_epoch = uVar3 + 1;
            *(undefined1 *)&(pdVar18->next_bitmap).map = 0;
            *(undefined1 *)((int)&(pdVar18->next_bitmap).map + 1) = 0;
            *(undefined1 *)((int)&(pdVar18->next_bitmap).map + 2) = 0;
            *(undefined1 *)((int)&(pdVar18->next_bitmap).map + 3) = 0;
            (pdVar18->next_bitmap).max_seq_num[0] = '\0';
            (pdVar18->next_bitmap).max_seq_num[1] = '\0';
            (pdVar18->next_bitmap).max_seq_num[2] = '\0';
            (pdVar18->next_bitmap).max_seq_num[3] = '\0';
            (pdVar18->next_bitmap).max_seq_num[4] = '\0';
            (pdVar18->next_bitmap).max_seq_num[5] = '\0';
            (pdVar18->next_bitmap).max_seq_num[6] = '\0';
            (pdVar18->next_bitmap).max_seq_num[7] = '\0';
            psVar19->read_sequence[0] = '\0';
            psVar19->read_sequence[1] = '\0';
            psVar19->read_sequence[2] = '\0';
            psVar19->read_sequence[3] = '\0';
            psVar19->read_sequence[4] = '\0';
            psVar19->read_sequence[5] = '\0';
            psVar19->read_sequence[6] = '\0';
            psVar19->read_sequence[7] = '\0';
            if (param_1->version == 0x100) {
              param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
            }
          }
          goto LAB_00129ddc;
        }
        if ((pdVar15->change_cipher_spec_ok < 0xc) || (param_1->in_handshake != 0)) {
          if (0x13 < iVar6) {
            if (iVar6 < 0x17) {
              ERR_put_error(0x14,0x102,0x44,"d1_pkt.c",0x55a);
              uVar13 = 10;
              goto LAB_0012a344;
            }
            if (iVar6 == 0x17) {
              psVar19 = param_1->s3;
              if (((psVar19->in_read_app_data != 0) && (psVar19->total_renegotiations != 0)) &&
                 (((iVar6 = param_1->state, iVar6 << 0x13 < 0 &&
                   ((0x110f < iVar6 && (iVar6 < 0x1121)))) ||
                  ((iVar6 << 0x12 < 0 && ((iVar6 < 0x2121 && (0x210f < iVar6)))))))) {
                psVar19->in_read_app_data = 2;
                return 0xffffffff;
              }
              iVar6 = 0x572;
              goto LAB_0012a360;
            }
          }
          if (param_1->version == 0x301) goto LAB_00129eb0;
          iVar6 = 0x54f;
          goto LAB_0012a360;
        }
        dtls1_get_message_header((psVar19->rrec).data,local_58);
        if ((psVar19->rrec).epoch == (uint)param_1->d1->r_epoch) {
          if (local_58[0] != '\x14') {
            if (((param_1->state & 0xfffU) == 3) && (-1 < param_1->s3->flags << 0x1f)) {
              param_1->tlsext_hb_seq = 1;
              param_1->new_session = 1;
              if (param_1->server == 0) {
                iVar6 = 0x1000;
              }
              else {
                iVar6 = 0x2000;
              }
              param_1->state = iVar6;
            }
            sVar22 = (*param_1->handshake_func)(param_1);
            if ((int)sVar22 < 0) {
              return sVar22;
            }
            if (sVar22 == 0) {
              iVar6 = 0x52e;
              goto LAB_0012a19c;
            }
            if ((int)(param_1->options << 0x1d) < 0) goto LAB_00129ddc;
            psVar19 = param_1->s3;
            if ((param_1->s3->rbuf).left == 0) {
              param_1->rwstate = 3;
              goto LAB_0012a0fc;
            }
            goto LAB_00129dde;
          }
          iVar6 = dtls1_check_timeout_num(param_1);
          if (iVar6 < 0) {
            return 0xffffffff;
          }
          dtls1_retransmit_buffered_messages(param_1);
        }
        (psVar19->rrec).length = 0;
        psVar19 = param_1->s3;
        goto LAB_00129dde;
      }
      p_Var23 = param_1->msg_callback;
      uVar1 = pdVar15->handshake_fragment[2];
      pdVar15->handshake_fragment[4] = '\0';
      pdVar15->handshake_fragment[5] = '\0';
      pdVar15->handshake_fragment[6] = '\0';
      pdVar15->handshake_fragment[7] = '\0';
      bVar2 = pdVar15->handshake_fragment[3];
      uVar14 = (uint)bVar2;
      if (p_Var23 != (_func_3292 *)0x0) {
        (*p_Var23)(0,param_1->version,0x15,pdVar15->handshake_fragment + 2,2,param_1,
                   param_1->msg_callback_arg);
      }
      p_Var17 = param_1->info_callback;
      if (((param_1->info_callback != (_func_3294 *)0x0) ||
          (p_Var17 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c),
          *(_func_3294 **)(param_1->psk_server_callback + 0x9c) != (_func_3294 *)0x0)) ||
         (p_Var17 = local_6c, local_6c != (_func_3294 *)0x0)) {
        (*p_Var17)(param_1,0x4004,(int)CONCAT11(uVar1,bVar2));
        local_6c = p_Var17;
      }
      if (uVar1 != '\x01') {
        if (uVar1 == '\x02') {
          param_1->rwstate = 1;
          param_1->s3->fatal_alert = uVar14;
          ERR_put_error(0x14,0x102,uVar14 + 1000,"d1_pkt.c",0x4b0);
          BIO_snprintf(local_58,0x10,"%d",uVar14);
          ERR_add_error_data(2,"SSL alert number ",local_58);
          param_1->shutdown = param_1->shutdown | 2;
          SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
          return 0;
        }
        ERR_put_error(0x14,0x102,0xf6,"d1_pkt.c",0x4b8);
        uVar13 = 0x2f;
        goto LAB_0012a344;
      }
      psVar19 = param_1->s3;
      psVar19->warn_alert = uVar14;
      if (uVar14 == 0) {
        param_1->shutdown = param_1->shutdown | 2;
        return 0;
      }
      goto LAB_00129dde;
    }
    uVar14 = *(uint *)(pdVar15->handshake_fragment + 8);
    pdVar15->change_cipher_spec_ok = 0;
    if ((uVar14 & 0xffffff00) != 0) {
      ERR_put_error(0x14,0x102,0x69,"d1_pkt.c",0x42f);
      uVar13 = 0x32;
      goto LAB_0012a344;
    }
    if (param_1->msg_callback != (_func_3292 *)0x0) {
      (*param_1->msg_callback)
                (0,param_1->version,0x16,pdVar15->handshake_fragment + 8,4,param_1,
                 param_1->msg_callback_arg);
    }
    iVar6 = SSL_state(param_1);
    if (iVar6 != 3) goto LAB_00129ddc;
    psVar19 = param_1->s3;
    if ((psVar19->flags << 0x1f < 0) || (psVar19->renegotiate != 0)) goto LAB_00129dde;
    param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
    param_1->new_session = 1;
    ssl3_renegotiate(param_1);
    iVar6 = ssl3_renegotiate_check(param_1);
    if (iVar6 != 0) {
      sVar22 = (*param_1->handshake_func)(param_1);
      if ((int)sVar22 < 0) {
        return sVar22;
      }
      if (sVar22 == 0) {
        iVar6 = 0x448;
        goto LAB_0012a19c;
      }
      if (-1 < (int)(param_1->options << 0x1d)) {
        psVar19 = param_1->s3;
        if ((param_1->s3->rbuf).left == 0) {
          param_1->rwstate = 3;
LAB_0012a0fc:
          pBVar4 = SSL_get_rbio(param_1);
          BIO_clear_flags(pBVar4,0xf);
          BIO_set_flags(pBVar4,9);
          return 0xffffffff;
        }
        goto LAB_00129dde;
      }
    }
  }
  else {
    iVar6 = dtls1_handle_timeout(param_1);
    if (iVar6 < 1) goto LAB_00129e94;
  }
LAB_00129ddc:
  psVar19 = param_1->s3;
  goto LAB_00129dde;
}


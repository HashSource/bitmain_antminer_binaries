
size_t dtls1_read_bytes(SSL *param_1,int param_2,void *param_3,uint param_4,int param_5)

{
  uchar uVar1;
  byte bVar2;
  ushort uVar3;
  pitem *item;
  int iVar4;
  BIO *pBVar5;
  uint uVar6;
  size_t sVar7;
  uchar *puVar8;
  uint uVar9;
  uchar *puVar10;
  SSL3_RECORD *pSVar11;
  uint uVar12;
  undefined4 uVar13;
  uint uVar14;
  dtls1_state_st *pdVar15;
  uchar **ppuVar16;
  _func_3294 *p_Var17;
  dtls1_state_st *pdVar18;
  ssl3_state_st *psVar19;
  uchar **ppuVar20;
  undefined4 uVar21;
  uchar *puVar22;
  uchar *puVar23;
  _func_3292 *p_Var24;
  uint *puVar25;
  ssl3_state_st *psVar26;
  _func_3294 *local_6c;
  undefined auStack_5c [4];
  char local_58 [52];
  
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar4 = ssl3_setup_buffers(), iVar4 == 0)) {
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
    if (uVar14 != 0) goto LAB_00077710;
    if (param_2 != 0x16) goto LAB_000771f6;
  }
  else {
    if (param_2 != 0x16) {
LAB_00077710:
      iVar4 = 0x312;
LAB_00077714:
      ERR_put_error(0x14,0x102,0x44,DAT_000778bc,iVar4);
      return 0xffffffff;
    }
    if (param_5 == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = uVar14 & 1;
    }
    if (uVar14 != 0) goto LAB_00077710;
  }
  pdVar15 = param_1->d1;
  if (pdVar15->change_cipher_spec_ok != 0) {
    puVar8 = pdVar15->handshake_fragment + 8;
    if ((int)param_4 < 1) {
      uVar14 = 0;
LAB_00077578:
      uVar6 = 0;
      do {
        uVar12 = uVar6 + 1;
        pdVar15->handshake_fragment[uVar6 + 8] = puVar8[uVar6];
        pdVar15 = param_1->d1;
        uVar6 = uVar12;
        uVar9 = uVar14;
      } while (uVar12 < pdVar15->change_cipher_spec_ok);
    }
    else {
      uVar9 = 0;
      puVar10 = puVar8;
      do {
        puVar8 = puVar10 + 1;
        *(uchar *)((int)param_3 + uVar9) = *puVar10;
        uVar9 = uVar9 + 1;
        pdVar15 = param_1->d1;
        uVar6 = pdVar15->change_cipher_spec_ok - 1;
        pdVar15->change_cipher_spec_ok = uVar6;
        if (uVar9 == param_4) {
          uVar14 = param_4;
          if (uVar6 == 0) {
            return uVar9;
          }
          goto LAB_00077578;
        }
        puVar10 = puVar8;
      } while (uVar6 != 0);
    }
    if (uVar9 != 0) {
      return uVar9;
    }
  }
LAB_000771f6:
  if ((param_1->in_handshake == 0) && (uVar14 = SSL_state(param_1), (uVar14 & 0x3000) != 0)) {
    sVar7 = (*param_1->handshake_func)(param_1);
    if ((int)sVar7 < 0) {
      return sVar7;
    }
    if (sVar7 == 0) {
      iVar4 = 0x333;
LAB_000775d4:
      ERR_put_error(0x14,0x102,0xe5,DAT_000778bc,iVar4);
      return 0xffffffff;
    }
  }
  local_6c = (_func_3294 *)0x0;
  psVar19 = param_1->s3;
LAB_00077216:
  param_1->rwstate = 1;
  if (((param_1->state == 3) && ((psVar19->rrec).length == 0)) &&
     (item = pqueue_pop((param_1->d1->buffered_app_data).q), item != (pitem *)0x0)) {
    psVar26 = param_1->s3;
    ppuVar20 = (uchar **)item->data;
    puVar8 = (psVar26->rbuf).buf;
    if (puVar8 != (uchar *)0x0) {
      CRYPTO_free(puVar8);
      psVar26 = param_1->s3;
    }
    puVar8 = ppuVar20[1];
    param_1->packet = *ppuVar20;
    param_1->packet_length = (uint)puVar8;
    ppuVar16 = ppuVar20 + 6;
    puVar22 = ppuVar20[3];
    puVar8 = ppuVar20[4];
    puVar10 = ppuVar20[5];
    (psVar26->rbuf).buf = ppuVar20[2];
    (psVar26->rbuf).len = (size_t)puVar22;
    (psVar26->rbuf).offset = (int)puVar8;
    (psVar26->rbuf).left = (int)puVar10;
    pSVar11 = &param_1->s3->rrec;
    do {
      puVar22 = *ppuVar16;
      puVar23 = ppuVar16[1];
      puVar8 = ppuVar16[2];
      puVar10 = ppuVar16[3];
      ppuVar16 = ppuVar16 + 4;
      pSVar11->type = (int)puVar22;
      pSVar11->length = (uint)puVar23;
      pSVar11->off = (uint)puVar8;
      pSVar11->data = puVar10;
      pSVar11 = (SSL3_RECORD *)&pSVar11->input;
    } while (ppuVar16 != ppuVar20 + 0xe);
    *(uchar **)pSVar11 = *ppuVar16;
    puVar8 = *ppuVar20;
    psVar26 = param_1->s3;
    *(undefined4 *)(psVar26->read_sequence + 2) = *(undefined4 *)(puVar8 + 5);
    *(undefined2 *)(psVar26->read_sequence + 6) = *(undefined2 *)(puVar8 + 9);
    CRYPTO_free(item->data);
    pitem_free(item);
    iVar4 = dtls1_handle_timeout(param_1);
    if (0 < iVar4) goto LAB_00077214;
LAB_000772cc:
    if ((((psVar19->rrec).length == 0) || (param_1->rstate == 0xf1)) &&
       (iVar4 = dtls1_get_record(param_1), iVar4 < 1)) {
      sVar7 = dtls1_read_failed(param_1);
      if ((int)sVar7 < 1) {
        return sVar7;
      }
      goto LAB_00077214;
    }
    pdVar15 = param_1->d1;
    if ((pdVar15->mtu != 0) && ((psVar19->rrec).type != 0x16)) {
LAB_000772e8:
      (psVar19->rrec).length = 0;
      psVar19 = param_1->s3;
      goto LAB_00077216;
    }
    psVar26 = param_1->s3;
    if ((psVar26->change_cipher_spec != 0) && ((psVar19->rrec).type != 0x16)) {
      iVar4 = pqueue_size((pdVar15->buffered_app_data).q);
      if ((99 < iVar4) ||
         (iVar4 = dtls1_buffer_record_part_1
                            (param_1,&pdVar15->buffered_app_data,(psVar19->rrec).seq_num),
         -1 < iVar4)) goto LAB_000772e8;
      iVar4 = 0x37d;
      goto LAB_00077714;
    }
    if ((param_1->shutdown & 2U) != 0) {
      (psVar19->rrec).length = 0;
      param_1->rwstate = 1;
      return 0;
    }
    iVar4 = (psVar19->rrec).type;
    if (iVar4 == param_2) {
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
      ERR_put_error(0x14,0x102,100,DAT_000778bc,0x397);
      uVar13 = 10;
      goto LAB_0007777c;
    }
    if (iVar4 != 0x16) {
      if (iVar4 == 0x15) {
        puVar8 = pdVar15->handshake_fragment + 2;
        puVar25 = (uint *)(pdVar15->handshake_fragment + 4);
        uVar14 = 2;
        goto LAB_00077400;
      }
      if (iVar4 == 0x18) {
        dtls1_process_heartbeat(param_1);
        (psVar19->rrec).length = 0;
        param_1->rwstate = 3;
        pBVar5 = SSL_get_rbio(param_1);
        BIO_clear_flags(pBVar5,0xf);
        pBVar5 = SSL_get_rbio(param_1);
        BIO_set_flags(pBVar5,9);
        return 0xffffffff;
      }
      if (iVar4 == 0x14) goto LAB_00077380;
      if (iVar4 == 0x17) {
        psVar26->in_read_app_data = 2;
        pBVar5 = SSL_get_rbio(param_1);
        param_1->rwstate = 3;
        BIO_clear_flags(pBVar5,0xf);
        BIO_set_flags(pBVar5,9);
        return 0xffffffff;
      }
      iVar4 = 0x3fe;
LAB_00077798:
      ERR_put_error(0x14,0x102,0xf5,DAT_000778bc,iVar4);
      uVar13 = 10;
LAB_0007777c:
      ssl3_send_alert(param_1,2,uVar13);
      return 0xffffffff;
    }
    puVar8 = pdVar15->handshake_fragment + 8;
    puVar25 = &pdVar15->change_cipher_spec_ok;
    uVar14 = 0xc;
LAB_00077400:
    if ((psVar19->rrec).length < uVar14) {
      param_1->rstate = 0xf0;
      (psVar19->rrec).length = 0;
      psVar19 = psVar26;
      goto LAB_00077216;
    }
    uVar6 = (psVar19->rrec).off;
    uVar9 = uVar6;
    do {
      puVar8[uVar9 - uVar6] = (psVar19->rrec).data[uVar9];
      uVar9 = uVar9 + 1;
      (psVar19->rrec).off = uVar9;
      (psVar19->rrec).length = (psVar19->rrec).length - 1;
    } while (uVar9 - uVar6 < uVar14);
    pdVar15 = param_1->d1;
    *puVar25 = uVar14;
LAB_00077380:
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
        iVar4 = (psVar19->rrec).type;
        if (iVar4 == 0x14) {
          dtls1_get_ccs_header((psVar19->rrec).data,auStack_5c);
          iVar4 = param_1->version;
          if (iVar4 == 0x100) {
            uVar14 = 3;
          }
          else {
            uVar14 = 1;
          }
          if ((((psVar19->rrec).length != uVar14) || ((psVar19->rrec).off != 0)) ||
             (puVar8 = (psVar19->rrec).data, *puVar8 != '\x01')) {
            ERR_put_error(0x14,0x102,0x67,DAT_000779e4,0x4d7);
            return 0xffffffff;
          }
          p_Var24 = param_1->msg_callback;
          (psVar19->rrec).length = 0;
          if (p_Var24 != (_func_3292 *)0x0) {
            (*p_Var24)(0,iVar4,0x14,puVar8,1,param_1,param_1->msg_callback_arg);
          }
          if (param_1->d1[1].send_cookie != 0) {
            psVar19 = param_1->s3;
            param_1->d1[1].send_cookie = 0;
            psVar19->change_cipher_spec = 1;
            iVar4 = ssl3_do_change_cipher_spec(param_1);
            if (iVar4 == 0) {
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
            *(undefined *)&(pdVar18->next_bitmap).map = 0;
            *(undefined *)((int)&(pdVar18->next_bitmap).map + 1) = 0;
            *(undefined *)((int)&(pdVar18->next_bitmap).map + 2) = 0;
            *(undefined *)((int)&(pdVar18->next_bitmap).map + 3) = 0;
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
          goto LAB_00077214;
        }
        if ((pdVar15->change_cipher_spec_ok < 0xc) || (param_1->in_handshake != 0)) {
          if (0x13 < iVar4) {
            if (iVar4 < 0x17) {
              ERR_put_error(0x14,0x102,0x44,DAT_000778bc,0x55a);
              uVar13 = 10;
              goto LAB_0007777c;
            }
            if (iVar4 == 0x17) {
              psVar19 = param_1->s3;
              if (((psVar19->in_read_app_data != 0) && (psVar19->total_renegotiations != 0)) &&
                 (((iVar4 = param_1->state, iVar4 << 0x13 < 0 &&
                   ((0x110f < iVar4 && (iVar4 < 0x1121)))) ||
                  ((iVar4 << 0x12 < 0 && ((iVar4 < 0x2121 && (0x210f < iVar4)))))))) {
                psVar19->in_read_app_data = 2;
                return 0xffffffff;
              }
              iVar4 = 0x572;
              goto LAB_00077798;
            }
          }
          if (param_1->version == 0x301) goto LAB_000772e8;
          iVar4 = 0x54f;
          goto LAB_00077798;
        }
        dtls1_get_message_header((psVar19->rrec).data,local_58);
        if ((psVar19->rrec).epoch == (uint)param_1->d1->r_epoch) {
          if (local_58[0] != '\x14') {
            if (((param_1->state & 0xfffU) == 3) && (-1 < param_1->s3->flags << 0x1f)) {
              param_1->tlsext_hb_seq = 1;
              param_1->new_session = 1;
              if (param_1->server == 0) {
                iVar4 = 0x1000;
              }
              else {
                iVar4 = 0x2000;
              }
              param_1->state = iVar4;
            }
            sVar7 = (*param_1->handshake_func)(param_1);
            if ((int)sVar7 < 0) {
              return sVar7;
            }
            if (sVar7 == 0) {
              iVar4 = 0x52e;
              goto LAB_000775d4;
            }
            if ((int)(param_1->options << 0x1d) < 0) goto LAB_00077214;
            psVar19 = param_1->s3;
            if ((param_1->s3->rbuf).left == 0) {
              param_1->rwstate = 3;
              goto LAB_00077534;
            }
            goto LAB_00077216;
          }
          iVar4 = dtls1_check_timeout_num(param_1);
          if (iVar4 < 0) {
            return 0xffffffff;
          }
          dtls1_retransmit_buffered_messages(param_1);
        }
        (psVar19->rrec).length = 0;
        psVar19 = param_1->s3;
        goto LAB_00077216;
      }
      p_Var24 = param_1->msg_callback;
      uVar1 = pdVar15->handshake_fragment[2];
      *(undefined4 *)(pdVar15->handshake_fragment + 4) = 0;
      bVar2 = pdVar15->handshake_fragment[3];
      uVar14 = (uint)bVar2;
      if (p_Var24 != (_func_3292 *)0x0) {
        (*p_Var24)(0,param_1->version,0x15,pdVar15->handshake_fragment + 2,2,param_1,
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
          ERR_put_error(0x14,0x102,uVar14 + 1000,DAT_000779e4,0x4b0);
          BIO_snprintf(local_58,0x10,DAT_000779e8,uVar14);
          ERR_add_error_data(2,DAT_000779ec,local_58);
          param_1->shutdown = param_1->shutdown | 2;
          SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
          return 0;
        }
        ERR_put_error(0x14,0x102,0xf6,DAT_000779e4,0x4b8);
        uVar13 = 0x2f;
        goto LAB_0007777c;
      }
      psVar19 = param_1->s3;
      psVar19->warn_alert = uVar14;
      if (uVar14 == 0) {
        param_1->shutdown = param_1->shutdown | 2;
        return 0;
      }
      goto LAB_00077216;
    }
    uVar14 = *(uint *)(pdVar15->handshake_fragment + 8);
    pdVar15->change_cipher_spec_ok = 0;
    if ((uVar14 & 0xffffff00) != 0) {
      ERR_put_error(0x14,0x102,0x69,DAT_000779e4,0x42f);
      uVar13 = 0x32;
      goto LAB_0007777c;
    }
    if (param_1->msg_callback != (_func_3292 *)0x0) {
      (*param_1->msg_callback)
                (0,param_1->version,0x16,pdVar15->handshake_fragment + 8,4,param_1,
                 param_1->msg_callback_arg);
    }
    iVar4 = SSL_state(param_1);
    if (iVar4 != 3) goto LAB_00077214;
    psVar19 = param_1->s3;
    if ((psVar19->flags << 0x1f < 0) || (psVar19->renegotiate != 0)) goto LAB_00077216;
    param_1->d1->handshake_read_seq = param_1->d1->handshake_read_seq + 1;
    param_1->new_session = 1;
    ssl3_renegotiate(param_1);
    iVar4 = ssl3_renegotiate_check(param_1);
    if (iVar4 != 0) {
      sVar7 = (*param_1->handshake_func)(param_1);
      if ((int)sVar7 < 0) {
        return sVar7;
      }
      if (sVar7 == 0) {
        iVar4 = 0x448;
        goto LAB_000775d4;
      }
      if (-1 < (int)(param_1->options << 0x1d)) {
        psVar19 = param_1->s3;
        if ((param_1->s3->rbuf).left == 0) {
          param_1->rwstate = 3;
LAB_00077534:
          pBVar5 = SSL_get_rbio(param_1);
          BIO_clear_flags(pBVar5,0xf);
          BIO_set_flags(pBVar5,9);
          return 0xffffffff;
        }
        goto LAB_00077216;
      }
    }
  }
  else {
    iVar4 = dtls1_handle_timeout(param_1);
    if (iVar4 < 1) goto LAB_000772cc;
  }
LAB_00077214:
  psVar19 = param_1->s3;
  goto LAB_00077216;
}


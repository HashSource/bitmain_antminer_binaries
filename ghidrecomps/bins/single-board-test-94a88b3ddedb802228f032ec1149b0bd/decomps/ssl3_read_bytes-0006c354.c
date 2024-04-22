
size_t ssl3_read_bytes(SSL *param_1,int param_2,void *param_3,uint param_4,int param_5)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  EVP_MD *pEVar4;
  uint *puVar5;
  BIO *pBVar6;
  int iVar7;
  size_t sVar8;
  uint uVar9;
  uchar *puVar10;
  uint uVar12;
  SSL_SESSION *pSVar13;
  SSL_METHOD *pSVar14;
  uint uVar15;
  ssl3_state_st *psVar16;
  int iVar17;
  _func_3294 *p_Var18;
  int iVar19;
  uint uVar20;
  ulong uVar21;
  uchar uVar22;
  ssl3_state_st *psVar23;
  byte *buf;
  int iVar24;
  _func_3292 *p_Var25;
  uint local_c8;
  uchar *local_bc;
  _func_3294 *local_b4;
  undefined auStack_a8 [64];
  uchar auStack_68 [68];
  uchar *puVar11;
  
  if (((param_1->s3->rbuf).buf == (uchar *)0x0) && (iVar17 = ssl3_setup_read_buffer(), iVar17 == 0))
  {
    return 0xffffffff;
  }
  uVar15 = param_2 - 0x17;
  if (uVar15 != 0) {
    uVar15 = 1;
  }
  if (param_2 == 0 || param_2 == 0x17) {
    if (param_5 == 0) {
      uVar15 = 0;
    }
    else {
      uVar15 = uVar15 & 1;
    }
    if (uVar15 != 0) goto LAB_0006cbf2;
    if (param_2 != 0x16) goto LAB_0006c40c;
  }
  else if ((param_2 != 0x16) || (param_5 != 0)) {
LAB_0006cbf2:
    ERR_put_error(0x14,0x94,0x44,DAT_0006cc70,0x497);
    return 0xffffffff;
  }
  psVar16 = param_1->s3;
  if (psVar16->handshake_fragment_len != 0) {
    puVar10 = psVar16->handshake_fragment;
    if ((int)param_4 < 1) {
      uVar15 = 0;
    }
    else {
      uVar15 = 0;
      puVar11 = puVar10;
      while( true ) {
        puVar10 = puVar11 + 1;
        *(uchar *)((int)param_3 + uVar15) = *puVar11;
        uVar15 = uVar15 + 1;
        psVar16 = param_1->s3;
        uVar9 = psVar16->handshake_fragment_len - 1;
        psVar16->handshake_fragment_len = uVar9;
        if (uVar15 == param_4) break;
        puVar11 = puVar10;
        if (uVar9 == 0) {
          return uVar15;
        }
      }
      if (uVar9 == 0) {
        return uVar15;
      }
    }
    uVar9 = 0;
    do {
      uVar12 = uVar9 + 1;
      psVar16->handshake_fragment[uVar9] = puVar10[uVar9];
      psVar16 = param_1->s3;
      uVar9 = uVar12;
    } while (uVar12 < psVar16->handshake_fragment_len);
    return uVar15;
  }
LAB_0006c40c:
  if ((param_1->in_handshake == 0) && (uVar15 = SSL_state(param_1), (uVar15 & 0x3000) != 0)) {
    sVar8 = (*param_1->handshake_func)(param_1);
    if ((int)sVar8 < 0) {
      return sVar8;
    }
    if (sVar8 == 0) {
      iVar17 = 0x4ba;
LAB_0006caf4:
      ERR_put_error(0x14,0x94,0xe5,DAT_0006cc70,iVar17);
      return 0xffffffff;
    }
  }
  local_b4 = (_func_3294 *)0x0;
  psVar16 = param_1->s3;
LAB_0006c41e:
  uVar15 = (psVar16->rrec).length;
  param_1->rwstate = 1;
  if ((uVar15 == 0) || (psVar23 = psVar16, param_1->rstate == 0xf1)) {
    pSVar13 = param_1->session;
    if ((param_1->references & 0x20U) == 0) {
      local_c8 = 0x4540;
      iVar17 = 0;
    }
    else {
      if (psVar16->init_extra == 0) {
        ERR_put_error(0x14,0x8f,0x44,DAT_0006cf70,0x14b);
        return 0xffffffff;
      }
      iVar17 = 0x4000;
      local_c8 = 0x8540;
    }
    iVar24 = 0x21;
    do {
      if ((param_1->rstate != 0xf1) || (uVar9 = param_1->packet_length, uVar9 < 5)) {
        sVar8 = ssl3_read_n(param_1,5,(param_1->s3->rbuf).len,0);
        if ((int)sVar8 < 1) {
          return sVar8;
        }
        param_1->rstate = 0xf1;
        buf = param_1->packet;
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)(0,0,0x100,buf,5,param_1,param_1->msg_callback_arg);
        }
        iVar19 = param_1->max_cert_list;
        (psVar16->rrec).type = (uint)*buf;
        bVar1 = buf[1];
        uVar15 = (uint)CONCAT11(buf[3],buf[4]);
        uVar2 = CONCAT11(bVar1,buf[2]);
        (psVar16->rrec).length = uVar15;
        if ((iVar19 == 0) && ((int)(short)uVar2 != param_1->version)) {
          ERR_put_error(0x14,0x8f,0x10b,DAT_0006cf70,0x16a);
          if ((((param_1->version ^ (int)(short)uVar2) & 0xff00U) == 0) &&
             ((param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0 &&
              (param_1->write_hash == (EVP_MD_CTX *)0x0)))) {
            if ((psVar16->rrec).type == 0x15) {
              return 0xffffffff;
            }
            param_1->version = (uint)uVar2;
            uVar3 = 0x46;
          }
          else {
            uVar3 = 0x46;
          }
          goto LAB_0006c526;
        }
        if (bVar1 != 3) {
          ERR_put_error(0x14,0x8f,0x10b,DAT_0006cc70,0x182);
          return 0xffffffff;
        }
        if ((param_1->s3->rbuf).len - 5 < uVar15) {
          ERR_put_error(0x14,0x8f,0xc6,DAT_0006cf70,0x188);
          uVar3 = 0x16;
          goto LAB_0006c526;
        }
        uVar9 = param_1->packet_length;
      }
      if ((uVar9 - 5 < uVar15) && (sVar8 = ssl3_read_n(param_1,uVar15,uVar15,1), (int)sVar8 < 1)) {
        return sVar8;
      }
      uVar15 = (psVar16->rrec).length;
      puVar10 = param_1->packet;
      param_1->rstate = 0xf0;
      (psVar16->rrec).input = puVar10 + 5;
      if (local_c8 < uVar15) {
        ERR_put_error(0x14,0x8f,0x96,DAT_0006cc70,0x1b4);
        uVar3 = 0x16;
        goto LAB_0006c526;
      }
      pSVar14 = param_1->method;
      (psVar16->rrec).data = puVar10 + 5;
      iVar19 = (**(code **)pSVar14->ssl3_enc)(param_1,0);
      if (iVar19 == 0) {
        ERR_put_error(0x14,0x8f,0x81,DAT_0006cc70,0x1c4);
        uVar3 = 0x15;
        goto LAB_0006c526;
      }
      if (((pSVar13 != (SSL_SESSION *)0x0) && (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) &&
         (pEVar4 = EVP_MD_CTX_md(param_1->read_hash), pEVar4 != (EVP_MD *)0x0)) {
        pEVar4 = EVP_MD_CTX_md(param_1->read_hash);
        uVar15 = EVP_MD_size(pEVar4);
        if (0x40 < uVar15) {
          OpenSSLDie(DAT_0006cc70,0x1d8,DAT_0006cc74);
        }
        uVar9 = (psVar16->rrec).length + ((uint)(psVar16->rrec).type >> 8);
        if ((uVar9 < uVar15) ||
           ((uVar21 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx), (uVar21 & 0xf0007) == 2 &&
            (uVar9 < uVar15 + 1)))) {
          ERR_put_error(0x14,0x8f,0xa0,DAT_0006cf70,0x1ea);
          uVar3 = 0x32;
        }
        else {
          uVar21 = EVP_CIPHER_CTX_flags(param_1->enc_read_ctx);
          if ((uVar21 & 0xf0007) == 2) {
            local_bc = auStack_68;
            uVar12 = 0;
            ssl3_cbc_copy_mac(local_bc,&psVar16->rrec,uVar15,uVar9);
            (psVar16->rrec).length = (psVar16->rrec).length - uVar15;
          }
          else {
            uVar9 = (psVar16->rrec).length - uVar15;
            local_bc = (psVar16->rrec).data + uVar9;
            (psVar16->rrec).length = uVar9;
            uVar12 = (uint)(local_bc == (uchar *)0x0);
          }
          uVar9 = (**(code **)(param_1->method->ssl3_enc + 4))(param_1,auStack_a8,0);
          if ((uVar12 | uVar9 >> 0x1f) == 0) {
            iVar7 = CRYPTO_memcmp(auStack_a8,local_bc,uVar15);
            if (iVar7 != 0) {
              iVar19 = -1;
            }
          }
          else {
            iVar19 = -1;
          }
          if ((psVar16->rrec).length <= iVar17 + 0x4400 + uVar15) goto LAB_0006c776;
LAB_0006c75e:
          ERR_put_error(0x14,0x8f,0x119,DAT_0006c808,0x214);
          uVar3 = 0x14;
        }
        goto LAB_0006c526;
      }
LAB_0006c776:
      if (iVar19 < 0) goto LAB_0006c75e;
      if (param_1->expand != (COMP_CTX *)0x0) {
        if (iVar17 + 0x4400U < (psVar16->rrec).length) {
          ERR_put_error(0x14,0x8f,0x8c,DAT_0006cc70,0x21c);
          uVar3 = 0x16;
          goto LAB_0006c526;
        }
        psVar23 = param_1->s3;
        uVar15 = COMP_expand_block(param_1->expand,(psVar23->rrec).comp,0x4000,(psVar23->rrec).data,
                                   (psVar23->rrec).length);
        if ((int)uVar15 < 0) {
          ERR_put_error(0x14,0x8f,0x6b,DAT_0006cc70,0x221);
          uVar3 = 0x1e;
          goto LAB_0006c526;
        }
        (psVar23->rrec).length = uVar15;
        (psVar23->rrec).data = (psVar23->rrec).comp;
      }
      uVar15 = (psVar16->rrec).length;
      if (iVar17 + 0x4000U < uVar15) {
        ERR_put_error(0x14,0x8f,0x92,DAT_0006cc70,0x228);
        uVar3 = 0x16;
        goto LAB_0006c526;
      }
      (psVar16->rrec).off = 0;
      param_1->packet_length = 0;
      if (uVar15 != 0) goto LAB_0006cc36;
      iVar24 = iVar24 + -1;
      uVar15 = 0;
      if (iVar24 == 0) {
        ERR_put_error(0x14,0x8f,0x12a,DAT_0006c808,0x23e);
        uVar3 = 10;
        goto LAB_0006c526;
      }
    } while( true );
  }
  goto LAB_0006c43c;
LAB_0006cc36:
  psVar23 = param_1->s3;
LAB_0006c43c:
  if ((psVar23->change_cipher_spec != 0) && ((psVar16->rrec).type != 0x16)) {
    ERR_put_error(0x14,0x94,0x91,DAT_0006cf70,0x4d6);
    uVar3 = 10;
    goto LAB_0006c526;
  }
  if ((param_1->shutdown & 2U) != 0) {
    (psVar16->rrec).length = 0;
    param_1->rwstate = 1;
    return 0;
  }
  iVar17 = (psVar16->rrec).type;
  if (iVar17 == param_2) {
    uVar15 = SSL_state(param_1);
    if ((((uVar15 & 0x3000) == 0) || (param_2 != 0x17)) ||
       (param_1->enc_read_ctx != (EVP_CIPHER_CTX *)0x0)) {
      if ((int)param_4 < 1) {
        return param_4;
      }
      uVar15 = (psVar16->rrec).length;
      if (param_4 < uVar15) {
        uVar15 = param_4;
      }
      memcpy(param_3,(psVar16->rrec).data + (psVar16->rrec).off,uVar15);
      if (param_5 != 0) {
        return uVar15;
      }
      uVar9 = (psVar16->rrec).length - uVar15;
      (psVar16->rrec).length = uVar9;
      (psVar16->rrec).off = (psVar16->rrec).off + uVar15;
      if (uVar9 != 0) {
        return uVar15;
      }
      uVar21 = param_1->options;
      param_1->rstate = 0xf0;
      (psVar16->rrec).off = 0;
      if ((int)(uVar21 << 0x1b) < 0) {
        if ((param_1->s3->rbuf).left == 0) {
          ssl3_release_read_buffer(param_1);
          return uVar15;
        }
        return uVar15;
      }
      return uVar15;
    }
    ERR_put_error(0x14,0x94,100,DAT_0006cf70,0x4ed);
    uVar3 = 10;
    goto LAB_0006c526;
  }
  if (iVar17 == 0x16) {
    puVar10 = psVar23->handshake_fragment;
    uVar9 = 4;
    puVar5 = &psVar23->handshake_fragment_len;
LAB_0006c80c:
    uVar12 = *puVar5;
    if (uVar9 - uVar12 < uVar15) {
      uVar15 = uVar9 - uVar12;
    }
    if (uVar15 != 0) {
      uVar20 = (psVar16->rrec).off;
      uVar15 = uVar15 + uVar20;
      do {
        puVar11 = (psVar16->rrec).data + uVar20;
        uVar20 = uVar20 + 1;
        puVar10[uVar12] = *puVar11;
        *puVar5 = uVar12 + 1;
        (psVar16->rrec).off = uVar20;
        (psVar16->rrec).length = (psVar16->rrec).length - 1;
        uVar12 = *puVar5;
      } while (uVar20 != uVar15);
    }
    if (uVar12 < uVar9) goto LAB_0006c848;
  }
  else {
    if (iVar17 == 0x15) {
      puVar10 = psVar23->alert_fragment;
      uVar9 = 2;
      puVar5 = &psVar23->alert_fragment_len;
      goto LAB_0006c80c;
    }
    if (iVar17 == 0x18) {
      tls1_process_heartbeat(param_1);
      (psVar16->rrec).length = 0;
      param_1->rwstate = 3;
      pBVar6 = SSL_get_rbio(param_1);
      BIO_clear_flags(pBVar6,0xf);
      pBVar6 = SSL_get_rbio(param_1);
      BIO_set_flags(pBVar6,9);
      return 0xffffffff;
    }
  }
  if (param_1->server == 0) {
    psVar23 = param_1->s3;
    if (((3 < psVar23->handshake_fragment_len) && (psVar23->handshake_fragment[0] == '\0')) &&
       ((param_1->session != (SSL_SESSION *)0x0 &&
        (*(int *)(param_1->session->krb5_client_princ + 0x24) != 0)))) {
      psVar23->handshake_fragment_len = 0;
      if ((*(uint *)psVar23->handshake_fragment & 0xffffff00) == 0) {
        if (param_1->msg_callback != (_func_3292 *)0x0) {
          (*param_1->msg_callback)
                    (0,param_1->version,0x16,psVar23->handshake_fragment,4,param_1,
                     param_1->msg_callback_arg);
        }
        iVar17 = SSL_state(param_1);
        if (iVar17 == 3) {
          psVar16 = param_1->s3;
          if ((psVar16->flags << 0x1f < 0) || (psVar16->renegotiate != 0)) goto LAB_0006c41e;
          ssl3_renegotiate(param_1);
          iVar17 = ssl3_renegotiate_check(param_1);
          if (iVar17 != 0) {
            sVar8 = (*param_1->handshake_func)(param_1);
            if ((int)sVar8 < 0) {
              return sVar8;
            }
            if (sVar8 == 0) {
              iVar17 = 0x560;
              goto LAB_0006caf4;
            }
            if (-1 < (int)(param_1->options << 0x1d)) {
              psVar16 = param_1->s3;
              if ((psVar16->rbuf).left == 0) {
                param_1->rwstate = 3;
LAB_0006c90c:
                pBVar6 = SSL_get_rbio(param_1);
                BIO_clear_flags(pBVar6,0xf);
                BIO_set_flags(pBVar6,9);
                return 0xffffffff;
              }
              goto LAB_0006c41e;
            }
          }
        }
        goto LAB_0006c848;
      }
      ERR_put_error(0x14,0x94,0x69,DAT_0006cf70,0x54d);
      uVar3 = 0x32;
      goto LAB_0006c526;
    }
  }
  else {
    iVar17 = SSL_state(param_1);
    psVar23 = param_1->s3;
    if (((((iVar17 == 3) && (psVar23->send_connection_binding == 0)) && (0x300 < param_1->version))
        && ((3 < psVar23->handshake_fragment_len && (psVar23->handshake_fragment[0] == '\x01')))) &&
       ((param_1->session != (SSL_SESSION *)0x0 &&
        ((*(int *)(param_1->session->krb5_client_princ + 0x24) != 0 &&
         ((*(uint *)(param_1->psk_server_callback + 0xa4) & 0x40000) == 0)))))) {
      pSVar14 = param_1->method;
      (psVar16->rrec).length = 0;
      iVar17 = (**(code **)(pSVar14->ssl3_enc + 0x30))(100);
      if ((param_1->version == 0x300) && (iVar17 == 0x46)) {
        uVar22 = '(';
      }
      else {
        if (iVar17 < 0) goto LAB_0006c848;
        uVar22 = (uchar)iVar17;
      }
      psVar23 = param_1->s3;
      psVar23->send_alert[0] = '\x01';
      psVar16 = param_1->s3;
      psVar23->alert_dispatch = 1;
      psVar16->send_alert[1] = uVar22;
      psVar16 = param_1->s3;
      if ((psVar16->wbuf).left == 0) {
        (*param_1->method->ssl_dispatch_alert)(param_1);
        psVar16 = param_1->s3;
      }
      goto LAB_0006c41e;
    }
  }
  if (1 < psVar23->alert_fragment_len) {
    p_Var25 = param_1->msg_callback;
    psVar23->alert_fragment_len = 0;
    uVar22 = psVar23->alert_fragment[0];
    bVar1 = psVar23->alert_fragment[1];
    uVar15 = (uint)bVar1;
    if (p_Var25 != (_func_3292 *)0x0) {
      (*p_Var25)(0,param_1->version,0x15,psVar23->alert_fragment,2,param_1,param_1->msg_callback_arg
                );
    }
    p_Var18 = param_1->info_callback;
    if (((param_1->info_callback != (_func_3294 *)0x0) ||
        (p_Var18 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c),
        *(_func_3294 **)(param_1->psk_server_callback + 0x9c) != (_func_3294 *)0x0)) ||
       (p_Var18 = local_b4, local_b4 != (_func_3294 *)0x0)) {
      (*p_Var18)(param_1,0x4004,(int)CONCAT11(uVar22,bVar1));
      local_b4 = p_Var18;
    }
    if (uVar22 == '\x01') {
      psVar16 = param_1->s3;
      psVar16->warn_alert = uVar15;
      if (uVar15 == 0) {
        param_1->shutdown = param_1->shutdown | 2;
        return 0;
      }
      if (uVar15 != 100) goto LAB_0006c41e;
      ERR_put_error(0x14,0x94,0x153,DAT_0006c808,0x5b4);
      uVar3 = 0x28;
    }
    else {
      if (uVar22 == '\x02') {
        param_1->rwstate = 1;
        param_1->s3->fatal_alert = uVar15;
        ERR_put_error(0x14,0x94,uVar15 + 1000,DAT_0006cf70,0x5c0);
        BIO_snprintf((char *)auStack_68,0x10,DAT_0006cf74,uVar15);
        ERR_add_error_data(2,DAT_0006cf78,auStack_68);
        param_1->shutdown = param_1->shutdown | 2;
        SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
        return 0;
      }
      ERR_put_error(0x14,0x94,0xf6,DAT_0006cf70,0x5c8);
      uVar3 = 0x2f;
    }
    goto LAB_0006c526;
  }
  if (param_1->shutdown << 0x1f < 0) {
    param_1->rwstate = 1;
    (psVar16->rrec).length = 0;
    return 0;
  }
  iVar17 = (psVar16->rrec).type;
  if (iVar17 == 0x14) {
    if ((((psVar16->rrec).length == 1) && ((psVar16->rrec).off == 0)) &&
       (puVar10 = (psVar16->rrec).data, *puVar10 == '\x01')) {
      if ((psVar23->tmp).new_cipher == (SSL_CIPHER *)0x0) {
        iVar17 = 0x5e5;
      }
      else {
        if ((psVar23->flags & 0x80U) != 0) {
          p_Var25 = param_1->msg_callback;
          psVar23->flags = psVar23->flags & 0xffffff7f;
          (psVar16->rrec).length = 0;
          if (p_Var25 != (_func_3292 *)0x0) {
            (*p_Var25)(0,param_1->version,0x14,puVar10,1,param_1,param_1->msg_callback_arg);
            psVar23 = param_1->s3;
          }
          psVar23->change_cipher_spec = 1;
          iVar17 = ssl3_do_change_cipher_spec(param_1);
          if (iVar17 == 0) {
            return 0xffffffff;
          }
          goto LAB_0006c848;
        }
        iVar17 = 0x5eb;
      }
      ERR_put_error(0x14,0x94,0x85,DAT_0006cf70,iVar17);
      uVar3 = 10;
    }
    else {
      ERR_put_error(0x14,0x94,0x67,DAT_0006cf70,0x5de);
      uVar3 = 0x2f;
    }
    goto LAB_0006c526;
  }
  if ((3 < psVar23->handshake_fragment_len) && (param_1->in_handshake == 0)) {
    if (((param_1->state & 0xfffU) == 3) && (-1 < psVar23->flags << 0x1f)) {
      param_1->tlsext_hb_seq = 1;
      param_1->new_session = 1;
      if (param_1->server == 0) {
        iVar17 = 0x1000;
      }
      else {
        iVar17 = 0x2000;
      }
      param_1->state = iVar17;
    }
    sVar8 = (*param_1->handshake_func)(param_1);
    if ((int)sVar8 < 0) {
      return sVar8;
    }
    if (sVar8 == 0) {
      ERR_put_error(0x14,0x94,0xe5,DAT_0006cf70,0x614);
      return 0xffffffff;
    }
    if (-1 < (int)(param_1->options << 0x1d)) {
      psVar16 = param_1->s3;
      if ((psVar16->rbuf).left == 0) {
        param_1->rwstate = 3;
        goto LAB_0006c90c;
      }
      goto LAB_0006c41e;
    }
LAB_0006c848:
    psVar16 = param_1->s3;
    goto LAB_0006c41e;
  }
  if (iVar17 < 0x14) {
LAB_0006c980:
    if (param_1->version - 0x301U < 2) {
      (psVar16->rrec).length = 0;
      psVar16 = psVar23;
      goto LAB_0006c41e;
    }
    iVar17 = 0x638;
  }
  else {
    if (iVar17 < 0x17) {
      ERR_put_error(0x14,0x94,0x44,DAT_0006cc70,0x643);
      uVar3 = 10;
      goto LAB_0006c526;
    }
    if (iVar17 != 0x17) goto LAB_0006c980;
    if (((psVar23->in_read_app_data != 0) && (psVar23->total_renegotiations != 0)) &&
       (((iVar17 = param_1->state, iVar17 << 0x13 < 0 && ((0x110f < iVar17 && (iVar17 < 0x1121))))
        || ((iVar17 << 0x12 < 0 && ((iVar17 < 0x2121 && (0x210f < iVar17)))))))) {
      psVar23->in_read_app_data = 2;
      return 0xffffffff;
    }
    iVar17 = 0x65b;
  }
  ERR_put_error(0x14,0x94,0xf5,DAT_0006cf70,iVar17);
  uVar3 = 10;
LAB_0006c526:
  iVar17 = (**(code **)(param_1->method->ssl3_enc + 0x30))(uVar3);
  if ((param_1->version == 0x300) && (iVar17 == 0x46)) {
    uVar22 = '(';
  }
  else {
    if (iVar17 < 0) {
      return 0xffffffff;
    }
    uVar22 = (uchar)iVar17;
  }
  if (param_1->session != (SSL_SESSION *)0x0) {
    SSL_CTX_remove_session((SSL_CTX *)param_1->psk_server_callback,param_1->session);
  }
  psVar23 = param_1->s3;
  psVar23->send_alert[0] = '\x02';
  psVar16 = param_1->s3;
  psVar23->alert_dispatch = 1;
  psVar16->send_alert[1] = uVar22;
  if ((param_1->s3->wbuf).left != 0) {
    return 0xffffffff;
  }
  (*param_1->method->ssl_dispatch_alert)(param_1);
  return 0xffffffff;
}


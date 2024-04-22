
int ssl23_connect(SSL *param_1)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  byte *pbVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  stack_st_SSL_CIPHER *psVar9;
  byte *pbVar10;
  _STACK *p_Var11;
  void *pvVar12;
  SSL_METHOD *pSVar13;
  BUF_MEM *str;
  time_t tVar14;
  int iVar15;
  undefined4 *puVar16;
  ssl2_state_st *psVar17;
  uint uVar18;
  undefined4 uVar19;
  _func_3199 *p_Var20;
  size_t __n;
  uint uVar21;
  SSL_CTX *pSVar22;
  _func_3291 *p_Var23;
  int iVar24;
  _func_3294 *p_Var25;
  ssl3_state_st *psVar26;
  byte *pbVar27;
  undefined4 uVar28;
  int iVar29;
  byte *pbVar30;
  _func_3294 *p_Var31;
  int iVar32;
  _func_3292 *p_Var33;
  uint uVar34;
  undefined4 uVar35;
  bool bVar36;
  bool bVar37;
  undefined4 in_stack_ffffff98;
  undefined4 in_stack_ffffff9c;
  byte local_4c;
  byte *local_44;
  time_t local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined2 local_2c;
  byte local_2a;
  
  local_38 = time((time_t *)0x0);
  RAND_add(&local_38,4,(double)CONCAT44(in_stack_ffffff9c,in_stack_ffffff98));
  ERR_clear_error();
  piVar5 = __errno_location();
  p_Var31 = param_1->info_callback;
  *piVar5 = 0;
  if (p_Var31 == (_func_3294 *)0x0) {
    p_Var31 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar6 = SSL_state(param_1);
  if (((uVar6 & 0x3000) == 0) || (iVar7 = SSL_state(param_1), iVar7 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  iVar7 = param_1->state;
  do {
    iVar32 = iVar7;
    if (iVar32 < 0x1212) {
      if (iVar32 < 0x1210) {
        if ((iVar32 != 0x1000) && (iVar32 != 0x1003)) goto LAB_0006f486;
        goto LAB_0006f3fa;
      }
      uVar6 = param_1->references;
      param_1->shutdown = 0;
      local_34 = 0;
      iVar7 = iVar32;
      if ((uVar6 & 0x1000000) == 0) {
        p_Var11 = &SSL_get_ciphers(param_1)->stack;
        iVar7 = 0;
        do {
          iVar24 = sk_num(p_Var11);
          if (iVar24 <= iVar7) {
            iVar7 = param_1->state;
            goto LAB_0006f21a;
          }
          pvVar12 = sk_value(p_Var11,iVar7);
          iVar7 = iVar7 + 1;
        } while (*(int *)((int)pvVar12 + 0x1c) != 1);
        iVar7 = param_1->state;
        uVar21 = 0x1000000;
        uVar34 = 0x3000000;
        uVar8 = 0x7000000;
        uVar18 = 0x17000000;
        bVar37 = true;
      }
      else {
LAB_0006f21a:
        uVar21 = 0;
        uVar34 = 0x2000000;
        bVar37 = false;
        uVar8 = 0x6000000;
        uVar18 = 0x16000000;
      }
      if ((int)(uVar6 << 4) < 0) {
        iVar24 = 0x303;
        if (uVar18 != (uVar18 & uVar6)) {
          iVar24 = 0x302;
        }
      }
      else {
        iVar24 = 0x303;
      }
      if (((int)(uVar6 << 3) < 0) && ((uVar8 & uVar6) != uVar8)) {
        iVar24 = 0x301;
      }
      if (((int)(uVar6 << 5) < 0) && ((uVar34 & uVar6) != uVar34)) {
        iVar24 = 0x300;
      }
      if (((int)(uVar6 << 6) < 0) && ((uVar6 & uVar21) != uVar21)) {
        iVar24 = 2;
        pbVar30 = (byte *)param_1->init_buf->data;
        if (iVar7 != 0x1210) goto LAB_0006f508;
LAB_0006f28a:
        psVar26 = param_1->s3;
        if ((int)(param_1->options << 0x1a) < 0) {
          tVar14 = time((time_t *)0x0);
          psVar26->client_random[3] = (uchar)tVar14;
          psVar26->client_random[0] = (uchar)((uint)tVar14 >> 0x18);
          psVar26->client_random[1] = (uchar)((uint)tVar14 >> 0x10);
          psVar26->client_random[2] = (uchar)((uint)tVar14 >> 8);
          iVar7 = RAND_pseudo_bytes(psVar26->client_random + 4,0x1c);
        }
        else {
          iVar7 = RAND_pseudo_bytes(psVar26->client_random,0x20);
        }
        if (iVar7 < 1) goto LAB_0006f72c;
        if (iVar24 == 0x303) {
          bVar1 = 3;
          local_4c = 3;
        }
        else {
          if ((*(uint *)(param_1->cert + 0x38) & 0x30000) != 0) {
            ERR_put_error(0x14,0x74,0x17b,DAT_0006fb60,0x18a);
            goto LAB_0006f72c;
          }
          if (iVar24 == 0x302) {
            bVar1 = 2;
            local_4c = 3;
          }
          else if (iVar24 == 0x301) {
            bVar1 = 1;
            local_4c = 3;
          }
          else if (iVar24 == 0x300) {
            local_4c = 3;
            bVar1 = 0;
          }
          else {
            if (iVar24 != 2) {
              ERR_put_error(0x14,0x74,0xbf,DAT_0006fb60,0x1a1);
              goto LAB_0006f72c;
            }
            local_4c = 0;
            bVar1 = 2;
          }
        }
        param_1->first_packet = iVar24;
        if (!bVar37) {
          pbVar30[9] = local_4c;
          pbVar30[10] = bVar1;
          pbVar27 = pbVar30 + 0x2e;
          psVar26 = param_1->s3;
          uVar35 = *(undefined4 *)(psVar26->client_random + 4);
          uVar28 = *(undefined4 *)(psVar26->client_random + 8);
          uVar19 = *(undefined4 *)(psVar26->client_random + 0xc);
          *(undefined4 *)(pbVar30 + 0xb) = *(undefined4 *)psVar26->client_random;
          *(undefined4 *)(pbVar30 + 0xf) = uVar35;
          *(undefined4 *)(pbVar30 + 0x13) = uVar28;
          *(undefined4 *)(pbVar30 + 0x17) = uVar19;
          uVar35 = *(undefined4 *)(psVar26->client_random + 0x14);
          uVar19 = *(undefined4 *)(psVar26->client_random + 0x1c);
          uVar28 = *(undefined4 *)(psVar26->client_random + 0x18);
          *(undefined4 *)(pbVar30 + 0x1b) = *(undefined4 *)(psVar26->client_random + 0x10);
          *(undefined4 *)(pbVar30 + 0x1f) = uVar35;
          *(undefined4 *)(pbVar30 + 0x27) = uVar19;
          *(undefined4 *)(pbVar30 + 0x23) = uVar28;
          pbVar30[0x2b] = 0;
          psVar9 = SSL_get_ciphers(param_1);
          iVar7 = ssl_cipher_list_to_bytes(param_1,psVar9,pbVar27,DAT_0006fa6c);
          if (iVar7 == 0) {
            iVar7 = 0x1fe;
LAB_0006fae0:
            ERR_put_error(0x14,0x74,0xb5,DAT_0006fb60,iVar7);
          }
          else {
            pbVar30[0x2d] = (byte)iVar7;
            pbVar30[0x2c] = (byte)((uint)iVar7 >> 8);
            pbVar10 = pbVar27 + iVar7;
            if ((param_1->references << 0xe < 0) ||
               (*(_STACK **)(param_1->psk_server_callback + 0x98) == (_STACK *)0x0)) {
              local_44 = pbVar10 + 1;
              pbVar27[iVar7] = 1;
            }
            else {
              local_44 = pbVar10 + 1;
              iVar15 = sk_num(*(_STACK **)(param_1->psk_server_callback + 0x98));
              pbVar27[iVar7] = (char)iVar15 + 1;
              if (0 < iVar15) {
                iVar7 = 0;
                do {
                  iVar29 = iVar7 + 1;
                  puVar16 = (undefined4 *)
                            sk_value(*(_STACK **)(param_1->psk_server_callback + 0x98),iVar7);
                  pbVar10 = pbVar10 + 1;
                  *pbVar10 = (byte)*puVar16;
                  iVar7 = iVar29;
                } while (iVar29 != iVar15);
                local_44 = local_44 + iVar29;
              }
            }
            *local_44 = 0;
            iVar7 = ssl_prepare_clienthello_tlsext(param_1);
            if (iVar7 < 1) {
              ERR_put_error(0x14,0x74,0xe2,DAT_0006fb60,0x222);
            }
            else {
              iVar7 = ssl_add_clienthello_tlsext(param_1,local_44 + 1,pbVar30 + 0x4000,&local_34);
              if (iVar7 == 0) {
                ssl3_send_alert(param_1,2,local_34);
                iVar7 = 0x22a;
              }
              else {
                pbVar30[5] = 1;
                iVar15 = iVar7 - (int)(pbVar30 + 9);
                pbVar30[8] = (byte)iVar15;
                uVar6 = iVar15 + 4;
                pbVar30[6] = (byte)((uint)iVar15 >> 0x10);
                pbVar30[7] = (byte)((uint)iVar15 >> 8);
                if (uVar6 < 0x4001) {
                  *pbVar30 = 0x16;
                  pbVar30[1] = local_4c;
                  if ((param_1->first_packet >> 8 == 3) && (0x301 < param_1->first_packet)) {
                    bVar1 = 1;
                  }
                  pbVar30[2] = bVar1;
                  pbVar30[4] = (byte)uVar6;
                  pbVar30[3] = (byte)(uVar6 >> 8);
                  param_1->init_num = iVar7 - (int)pbVar30;
                  param_1->init_off = 0;
                  ssl3_finish_mac(param_1,pbVar30 + 5);
                  goto LAB_0006f3ac;
                }
                iVar7 = 0x239;
              }
              ERR_put_error(0x14,0x74,0x44,DAT_0006fb60,iVar7);
            }
          }
          goto LAB_0006f72c;
        }
        pbVar30[2] = 1;
        pbVar30[3] = local_4c;
        pbVar30[4] = bVar1;
        pbVar27 = pbVar30 + 0xb;
        psVar9 = SSL_get_ciphers(param_1);
        iVar7 = ssl_cipher_list_to_bytes(param_1,psVar9,pbVar27,0);
        if (iVar7 == 0) {
          iVar7 = 0x1b7;
          goto LAB_0006fae0;
        }
        pbVar30[6] = (byte)iVar7;
        pbVar10 = pbVar27 + iVar7;
        pbVar30[7] = 0;
        pbVar30[8] = 0;
        pbVar30[5] = (byte)((uint)iVar7 >> 8);
        uVar6 = param_1->references;
        pbVar30[9] = 0;
        bVar36 = (uVar6 & 2) != 0;
        if (bVar36) {
          pbVar27 = (byte *)0x10;
          pbVar3 = pbVar27;
          pbVar4 = pbVar27;
        }
        else {
          pbVar3 = (byte *)0x0;
          pbVar4 = (byte *)0x20;
        }
        pbVar30[10] = (byte)pbVar4;
        if (!bVar36) {
          pbVar27 = pbVar4;
        }
        memset(param_1->s3->client_random,0,0x20);
        iVar7 = RAND_pseudo_bytes(pbVar3 + 0xc0 + (int)(param_1->s3->read_sequence + -8),
                                  (int)pbVar27);
        if (iVar7 < 1) goto LAB_0006f72c;
        memcpy(pbVar10,pbVar3 + 0xc0 + (int)(param_1->s3->read_sequence + -8),(size_t)pbVar27);
        iVar7 = (int)(pbVar10 + (int)pbVar27) - (int)(pbVar30 + 2);
        pbVar30[1] = (byte)iVar7;
        *pbVar30 = (byte)((uint)iVar7 >> 8) | 0x80;
        param_1->init_off = 0;
        param_1->init_num = iVar7 + 2;
        ssl3_finish_mac(param_1);
LAB_0006f3ac:
        param_1->state = 0x1211;
        param_1->init_off = 0;
        iVar7 = ssl23_write_bytes(param_1);
        if (1 < iVar7) goto LAB_0006f516;
LAB_0006f3c2:
        if (iVar7 != 1) goto LAB_0006f49a;
LAB_0006f3c4:
        param_1->init_num = 0;
        param_1->state = 0x1220;
      }
      else {
        if (param_1->tlsext_debug_arg != (void *)0x0) {
          bVar37 = false;
        }
        if (param_1->servername_done != -1) {
          bVar37 = false;
        }
        if (*(int *)(param_1->cert + 0x160) != 0) {
          bVar37 = false;
        }
        pbVar30 = (byte *)param_1->init_buf->data;
        if (iVar7 == 0x1210) goto LAB_0006f28a;
LAB_0006f508:
        iVar7 = ssl23_write_bytes(param_1);
        if (iVar7 < 2) goto LAB_0006f3c2;
LAB_0006f516:
        p_Var33 = param_1->msg_callback;
        if (p_Var33 == (_func_3292 *)0x0) goto LAB_0006f3c4;
        if (bVar37) {
          (*p_Var33)(1,2,0,param_1->init_buf->data + 2,iVar7 - 2,param_1,param_1->msg_callback_arg);
          param_1->init_num = 0;
          param_1->state = 0x1220;
        }
        else {
          (*p_Var33)(1,iVar24,0x100,param_1->init_buf->data,5,param_1,param_1->msg_callback_arg);
          (*param_1->msg_callback)
                    (1,iVar24,0x16,param_1->init_buf->data + 5,iVar7 - 5,param_1,
                     param_1->msg_callback_arg);
          param_1->init_num = 0;
          param_1->state = 0x1220;
        }
      }
      pSVar22 = param_1->ctx;
    }
    else {
      if (iVar32 != 0x4000) {
        if (iVar32 < 0x4001) {
          if (iVar32 - 0x1220U < 2) {
            iVar7 = ssl23_read_bytes(param_1,7);
            if (iVar7 == 7) {
              puVar16 = (undefined4 *)param_1->packet;
              local_30 = *puVar16;
              bVar1 = *(byte *)puVar16;
              local_2a = *(byte *)((int)puVar16 + 6);
              local_2c = *(undefined2 *)(puVar16 + 1);
              if ((((-1 < (int)((uint)bVar1 << 0x18)) || (*(byte *)((int)puVar16 + 2) != 4)) ||
                  (*(byte *)((int)puVar16 + 5) != 0)) || (*(byte *)((int)puVar16 + 6) != 2)) {
                if ((*(byte *)((int)puVar16 + 1) == 3) &&
                   (bVar2 = *(byte *)((int)puVar16 + 2), bVar2 < 4)) {
                  if (bVar1 == 0x16) {
                    bVar1 = *(byte *)((int)puVar16 + 5);
                  }
                  else {
                    if ((bVar1 != 0x15) || (*(byte *)((int)puVar16 + 3) != 0)) goto LAB_0006f79a;
                    bVar1 = *(byte *)(puVar16 + 1);
                  }
                  if (bVar1 == 2) {
                    if (bVar2 == 0) {
                      if (param_1->references << 6 < 0) goto LAB_0006f772;
                      param_1->version = 0x300;
                      pSVar13 = SSLv3_client_method();
                      param_1->method = pSVar13;
                    }
                    else if (bVar2 == 1) {
                      if (param_1->references << 5 < 0) goto LAB_0006f772;
                      param_1->version = 0x301;
                      pSVar13 = TLSv1_client_method();
                      param_1->method = pSVar13;
                    }
                    else if (bVar2 == 2) {
                      if (param_1->references << 3 < 0) {
LAB_0006f772:
                        iVar7 = 0x2e1;
                        goto LAB_0006f776;
                      }
                      param_1->version = 0x302;
                      pSVar13 = TLSv1_1_client_method();
                      param_1->method = pSVar13;
                    }
                    else {
                      if ((bVar2 != 3) || (param_1->references << 4 < 0)) goto LAB_0006f772;
                      param_1->version = 0x303;
                      pSVar13 = TLSv1_2_client_method();
                      param_1->method = pSVar13;
                    }
                    if (0x303 < param_1->version) {
                      OpenSSLDie(DAT_0006fa68,0x2e6,DAT_0006fa70);
                    }
                    if ((*(byte *)puVar16 != 0x15) || (*(byte *)((int)puVar16 + 5) == 1)) {
                      iVar7 = ssl_init_wbio_buffer(param_1,1);
                      if (iVar7 == 0) goto LAB_0006f72c;
                      param_1->state = 0x1120;
                      puVar16 = (undefined4 *)(param_1->s3->rbuf).buf;
                      param_1->rstate = 0xf0;
                      param_1->packet_length = 7;
                      if (puVar16 == (undefined4 *)0x0) {
                        iVar7 = ssl3_setup_read_buffer(param_1);
                        if (iVar7 == 0) goto LAB_0006f72c;
                        puVar16 = (undefined4 *)(param_1->s3->rbuf).buf;
                      }
                      param_1->packet = (uchar *)puVar16;
                      *puVar16 = local_30;
                      *(byte *)((int)puVar16 + 6) = local_2a;
                      *(undefined2 *)(puVar16 + 1) = local_2c;
                      psVar26 = param_1->s3;
                      p_Var20 = param_1->method->ssl_connect;
                      (psVar26->rbuf).left = 7;
                      (psVar26->rbuf).offset = 0;
                      param_1->handshake_func = (_func_3291 *)p_Var20;
                      goto LAB_0006f682;
                    }
                    p_Var25 = param_1->info_callback;
                    if ((p_Var25 != (_func_3294 *)0x0) ||
                       (p_Var25 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c),
                       p_Var25 != (_func_3294 *)0x0)) {
                      (*p_Var25)(param_1,0x4004,
                                 (uint)CONCAT11(*(byte *)((int)puVar16 + 5),
                                                *(byte *)((int)puVar16 + 6)));
                    }
                    if (param_1->msg_callback != (_func_3292 *)0x0) {
                      (*param_1->msg_callback)
                                (0,param_1->version,0x100,puVar16,5,param_1,
                                 param_1->msg_callback_arg);
                      (*param_1->msg_callback)
                                (0,param_1->version,0x15,(byte *)((int)puVar16 + 5),2,param_1,
                                 param_1->msg_callback_arg);
                    }
                    param_1->rwstate = 1;
                    ERR_put_error(0x14,0x77,*(byte *)((int)puVar16 + 6) + 1000,DAT_0006f734,0x301);
                    goto LAB_0006f72c;
                  }
                }
LAB_0006f79a:
                ERR_put_error(0x14,0x77,0xfc,DAT_0006fa68,0x31a);
                goto LAB_0006f72c;
              }
              if (param_1->references << 7 < 0) {
                iVar7 = 0x287;
LAB_0006f776:
                ERR_put_error(0x14,0x77,0x102,DAT_0006fa68,iVar7);
                goto LAB_0006f72c;
              }
              if (param_1->s2 == (ssl2_state_st *)0x0) {
                iVar7 = ssl2_new(param_1);
                if (iVar7 == 0) goto LAB_0006f72c;
              }
              else {
                ssl2_clear();
              }
              psVar26 = param_1->s3;
              psVar17 = param_1->s2;
              if ((param_1->references & 2U) == 0) {
                __n = 0x20;
              }
              else {
                __n = 0x10;
              }
              psVar17->challenge_length = __n;
              memcpy(psVar17->challenge,(void *)((int)psVar26 + (0xe0 - __n)),__n);
              if (param_1->s3 != (ssl3_state_st *)0x0) {
                ssl3_free(param_1);
              }
              iVar7 = BUF_MEM_grow_clean(param_1->init_buf,0x3fff);
              if (iVar7 == 0) {
                ERR_put_error(0x14,0x77,7,DAT_0006fb60,0x2a6);
                goto LAB_0006f72c;
              }
              iVar7 = 0x1020;
              param_1->state = 0x1020;
              bVar37 = param_1->first_packet != 2;
              psVar17 = param_1->s2;
              if (bVar37) {
                iVar7 = 1;
              }
              if (bVar37) {
                psVar17->ssl2_rollback = iVar7;
              }
              puVar16 = (undefined4 *)psVar17->rbuf;
              param_1->rstate = 0xf0;
              param_1->packet_length = 7;
              param_1->packet = (uchar *)puVar16;
              *puVar16 = local_30;
              *(undefined2 *)(puVar16 + 1) = local_2c;
              *(byte *)((int)puVar16 + 6) = local_2a;
              psVar17 = param_1->s2;
              psVar17->rbuf_left = 7;
              psVar17->rbuf_offs = 0;
              psVar17->write_sequence = 1;
              pSVar13 = SSLv2_client_method();
              p_Var23 = (_func_3291 *)pSVar13->ssl_connect;
              param_1->method = pSVar13;
              param_1->handshake_func = p_Var23;
LAB_0006f682:
              param_1->init_num = 0;
              iVar7 = ssl_get_new_session(param_1);
              if (iVar7 == 0) {
LAB_0006f72c:
                iVar7 = -1;
LAB_0006f49a:
                param_1->in_handshake = param_1->in_handshake + -1;
LAB_0006f4a0:
                if (p_Var31 != (_func_3294 *)0x0) {
                  (*p_Var31)(param_1,0x1002,iVar7);
                }
                return iVar7;
              }
              iVar7 = SSL_connect(param_1);
            }
            p_Var31 = (_func_3294 *)((uint)p_Var31 & iVar7 >> 0x1f);
            goto LAB_0006f49a;
          }
        }
        else if (iVar32 == 0x5000) goto LAB_0006f3fa;
LAB_0006f486:
        iVar7 = -1;
        ERR_put_error(0x14,0x75,0xff,DAT_0006f734,0xeb);
        goto LAB_0006f49a;
      }
LAB_0006f3fa:
      if (param_1->session != (SSL_SESSION *)0x0) {
        ERR_put_error(0x14,0x75,0xdd,DAT_0006fa68,0xb2);
        iVar7 = -1;
        goto LAB_0006f49a;
      }
      param_1->server = 0;
      if (p_Var31 != (_func_3294 *)0x0) {
        (*p_Var31)(param_1,0x10,1);
      }
      param_1->type = 0x1000;
      if (param_1->init_buf == (BUF_MEM *)0x0) {
        str = BUF_MEM_new();
        if (str == (BUF_MEM *)0x0) goto LAB_0006f72c;
        iVar7 = BUF_MEM_grow(str,0x4000);
        if (iVar7 == 0) {
          iVar7 = -1;
          param_1->in_handshake = param_1->in_handshake + -1;
          BUF_MEM_free(str);
          goto LAB_0006f4a0;
        }
        param_1->init_buf = str;
      }
      iVar7 = ssl3_setup_buffers(param_1);
      if (iVar7 == 0) goto LAB_0006f72c;
      ssl3_init_finished_mac(param_1);
      param_1->state = 0x1210;
      *(int *)(param_1->psk_server_callback + 0x34) =
           *(int *)(param_1->psk_server_callback + 0x34) + 1;
      param_1->init_num = 0;
      pSVar22 = param_1->ctx;
    }
    if (pSVar22 != (SSL_CTX *)0x0) {
      BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
    }
    iVar7 = param_1->state;
    if ((p_Var31 != (_func_3294 *)0x0) && (iVar7 != iVar32)) {
      param_1->state = iVar32;
      (*p_Var31)(param_1,0x1001,1);
      param_1->state = iVar7;
    }
  } while( true );
}


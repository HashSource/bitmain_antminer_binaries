
int dtls1_accept(SSL *param_1)

{
  _func_3291 *p_Var1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  BUF_MEM *str;
  long lVar5;
  int iVar6;
  ssl3_enc_method *psVar7;
  undefined4 uVar8;
  ssl3_state_st *psVar9;
  uint uVar10;
  dtls1_state_st *pdVar11;
  uint uVar12;
  cert_st *pcVar13;
  SSL_METHOD *pSVar14;
  SSL_CIPHER *pSVar15;
  _func_3294 *p_Var16;
  int iVar17;
  char *pcVar18;
  char *__dest;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  time_t local_2c [2];
  
  local_2c[0] = time((time_t *)0x0);
  RAND_add(local_2c,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  ERR_clear_error();
  piVar2 = __errno_location();
  p_Var16 = param_1->info_callback;
  *piVar2 = 0;
  if (p_Var16 == (_func_3294 *)0x0) {
    p_Var16 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  uVar12 = param_1->d1->mtu;
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar3 = SSL_state(param_1);
  if (((uVar3 & 0x3000) == 0) || (iVar4 = SSL_state(param_1), iVar4 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  pcVar13 = param_1->cert;
  param_1->d1->mtu = uVar12;
  if (pcVar13 == (cert_st *)0x0) {
    ERR_put_error(0x14,0xf6,0xb3,DAT_000894fc,0xc9);
    iVar4 = -1;
  }
  else {
    if (param_1->tlsext_heartbeat != 0) {
      dtls1_stop_timer(param_1);
      param_1->tlsext_heartbeat = 0;
      param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
    }
    iVar6 = param_1->state;
LAB_00088bb4:
    iVar17 = iVar6;
    if (0x2171 < iVar17) goto LAB_00088c28;
LAB_00088bbc:
    if (iVar17 < 0x2170) {
      if (iVar17 < 0x2122) {
        if (iVar17 < 0x2120) {
          if (iVar17 == 0x2100) {
            param_1->rwstate = 2;
            lVar5 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
            if (0 < lVar5) {
              psVar9 = param_1->s3;
              param_1->rwstate = 1;
              uVar10 = 0;
              param_1->state = (psVar9->tmp).next_state;
              goto LAB_00088da0;
            }
            iVar6 = BIO_test_flags(param_1->wbio,8);
            iVar4 = -1;
            if (iVar6 == 0) {
              param_1->rwstate = 1;
              iVar4 = -1;
              param_1->state = (param_1->s3->tmp).next_state;
            }
          }
          else if (iVar17 < 0x2101) {
            if (iVar17 == 0x2000) goto LAB_00088e98;
            if (iVar17 == 0x2003) goto LAB_00088e98;
            if (iVar17 != 3) goto LAB_00088e48;
            ssl3_cleanup_key_block(param_1);
            ssl_free_wbio_buffer(param_1);
            param_1->init_num = 0;
            if (param_1->tlsext_hb_seq == 2) {
              param_1->tlsext_hb_seq = 0;
              param_1->new_session = 0;
              ssl_update_cache(param_1,2);
              p_Var1 = DAT_000894f8;
              *(int *)(param_1->psk_server_callback + 0x48) =
                   *(int *)(param_1->psk_server_callback + 0x48) + 1;
              param_1->handshake_func = p_Var1;
              if (p_Var16 != (_func_3294 *)0x0) {
                (*p_Var16)(param_1,0x20,1);
              }
            }
            pdVar11 = param_1->d1;
            iVar4 = 1;
            pdVar11->handshake_read_seq = 0;
            pdVar11->handshake_write_seq = 0;
            pdVar11->next_handshake_write_seq = 0;
          }
          else {
            if (iVar17 < 0x2110) goto LAB_00088e48;
            if (iVar17 < 0x2113) {
              param_1->shutdown = 0;
              iVar4 = ssl3_get_client_hello(param_1);
              if (0 < iVar4) {
                dtls1_stop_timer(param_1);
                if ((iVar4 == 1) &&
                   (lVar5 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar5 << 0x12 < 0)) {
                  iVar4 = 0x2113;
                }
                else {
                  iVar4 = 0x2130;
                }
                param_1->state = iVar4;
                uVar10 = 0;
                param_1->init_num = 0;
                if (uVar12 == 0) {
                  psVar9 = param_1->s3;
                  uVar10 = 0;
                  goto LAB_00088da0;
                }
                psVar9 = param_1->s3;
                uVar8 = *(undefined4 *)(psVar9->read_sequence + 4);
                *(undefined4 *)psVar9->write_sequence = *(undefined4 *)psVar9->read_sequence;
                *(undefined4 *)(psVar9->write_sequence + 4) = uVar8;
                if (param_1->state != 0x2130) goto LAB_00089064;
                pdVar11 = param_1->d1;
                iVar4 = 2;
                pdVar11->mtu = 0;
                pdVar11->handshake_read_seq = 2;
                pdVar11->handshake_write_seq = 1;
                pdVar11->next_handshake_write_seq = 1;
              }
            }
            else {
              if (0x2114 < iVar17) goto LAB_00088e48;
              if (iVar17 == 0x2113) {
                pcVar18 = param_1->init_buf->data;
                pcVar18[0xc] = -2;
                pcVar18[0xd] = -1;
                if ((*(code **)(param_1->psk_server_callback + 0x78) == (code *)0x0) ||
                   (iVar4 = (**(code **)(param_1->psk_server_callback + 0x78))
                                      (param_1,param_1->d1->cookie,&param_1->d1->cookie_len),
                   iVar4 == 0)) {
                  iVar4 = 0;
                  ERR_put_error(0x14,0x108,0x44,DAT_00088e30,0x3a7);
                  param_1->state = 5;
                  goto LAB_00088d14;
                }
                __dest = pcVar18 + 0xf;
                pcVar18[0xe] = (char)param_1->d1->cookie_len;
                memcpy(__dest,param_1->d1->cookie,param_1->d1->cookie_len);
                uVar3 = param_1->d1->cookie_len;
                dtls1_set_message_header
                          (param_1,pcVar18,3,__dest + (uVar3 - (int)(pcVar18 + 0xc)),0,
                           __dest + (uVar3 - (int)(pcVar18 + 0xc)));
                param_1->init_off = 0;
                param_1->state = 0x2114;
                param_1->init_num = (int)(__dest + (uVar3 - (int)pcVar18));
              }
              iVar4 = dtls1_do_write(param_1,0x16);
              if (0 < iVar4) {
                iVar4 = param_1->version;
                psVar9 = param_1->s3;
                param_1->state = 0x2100;
                (psVar9->tmp).next_state = 0x2110;
                if (iVar4 == 0x100) {
                  uVar10 = 0;
                  goto LAB_00088da0;
                }
                ssl3_init_finished_mac(param_1);
                psVar9 = param_1->s3;
                uVar10 = 0;
                goto LAB_00088da0;
              }
            }
          }
        }
        else {
          param_1->shutdown = 0;
          dtls1_clear_record_buffer(param_1);
          dtls1_start_timer(param_1);
          iVar4 = ssl3_send_hello_request(param_1);
          if (0 < iVar4) {
            (param_1->s3->tmp).next_state = 0x2110;
            param_1->state = 0x2100;
            param_1->init_num = 0;
            ssl3_init_finished_mac(param_1);
            psVar9 = param_1->s3;
            uVar10 = 0;
            goto LAB_00088da0;
          }
        }
      }
      else if (iVar17 < 0x2142) {
        if (iVar17 < 0x2140) {
          if (iVar17 == 0x2122) {
            psVar9 = param_1->s3;
            param_1->state = 3;
            uVar10 = 0;
            goto LAB_00088da0;
          }
          if (1 < iVar17 - 0x2130U) goto LAB_00088e48;
          param_1->tlsext_hb_seq = 2;
          dtls1_start_timer(param_1);
          iVar4 = ssl3_send_server_hello(param_1);
          if (0 < iVar4) {
            if (param_1->hit == 0) {
              param_1->state = 0x2140;
            }
            else if (param_1->tlsext_ocsp_resplen == 0) {
              param_1->state = 0x21d0;
            }
            else {
              param_1->state = 0x21f0;
            }
            uVar10 = 0;
            param_1->init_num = 0;
            goto LAB_00089064;
          }
        }
        else {
          psVar9 = param_1->s3;
          pSVar15 = (psVar9->tmp).new_cipher;
          if (((int)(pSVar15->algorithm_auth << 0x1d) < 0) ||
             ((pSVar15->algorithm_mkey & 0x100) != 0)) {
            uVar3 = 1;
            param_1->state = 0x2150;
LAB_00088be8:
            uVar10 = (psVar9->tmp).reuse_message;
            param_1->init_num = 0;
            uVar10 = uVar10 | uVar3;
            iVar6 = iVar17;
            do {
              if (uVar10 != 0) {
LAB_00088daa:
                iVar6 = param_1->state;
                goto LAB_00088bb4;
              }
              if ((param_1->ctx != (SSL_CTX *)0x0) &&
                 (iVar4 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar4 < 1)) goto LAB_00088d14;
              if (p_Var16 == (_func_3294 *)0x0) goto LAB_00088daa;
              iVar17 = param_1->state;
              if (iVar6 == iVar17) goto LAB_00088bb4;
              param_1->state = iVar6;
              (*p_Var16)(param_1,0x2001,1);
              param_1->state = iVar17;
              if (iVar17 < 0x2172) goto LAB_00088bbc;
LAB_00088c28:
              if (iVar17 < 0x21d2) {
                if (0x21cf < iVar17) {
                  pSVar14 = param_1->method;
                  *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) =
                       (param_1->s3->tmp).new_cipher;
                  iVar4 = (**(code **)(pSVar14->ssl3_enc + 8))(param_1);
                  if (iVar4 != 0) {
                    iVar4 = dtls1_send_change_cipher_spec(param_1,0x21d0,0x21d1);
                    if (iVar4 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21e0;
                    iVar4 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
                    if (iVar4 != 0) {
                      dtls1_reset_seq_numbers(param_1,2);
LAB_00088c8e:
                      psVar9 = param_1->s3;
                      uVar10 = 0;
                      goto LAB_00088da0;
                    }
                  }
LAB_00089470:
                  iVar4 = -1;
                  param_1->state = 5;
                  goto LAB_00088d14;
                }
                if (iVar17 < 0x2192) {
                  if (iVar17 < 0x2190) {
                    if (1 < iVar17 - 0x2180U) goto LAB_00088e48;
                    psVar9 = param_1->s3;
                    if ((psVar9->tmp).cert_request != 0) {
                      iVar4 = ssl3_get_client_certificate(param_1);
                      if (iVar4 < 1) goto LAB_00088d14;
                      psVar9 = param_1->s3;
                    }
                    param_1->init_num = 0;
                    param_1->state = 0x2190;
                    uVar10 = 0;
                  }
                  else {
                    iVar4 = ssl3_get_client_key_exchange(param_1);
                    if (iVar4 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21a0;
                    if (iVar4 == 2) {
                      psVar9 = param_1->s3;
                      param_1->state = 0x21c0;
                      uVar10 = 0;
                    }
                    else {
                      psVar7 = param_1->method->ssl3_enc;
                      if ((*(uint *)(psVar7 + 0x38) & 2) == 0) {
                        (**(code **)(psVar7 + 0x1c))(param_1,4,&param_1->s3->tmp);
                        (**(code **)(param_1->method->ssl3_enc + 0x1c))
                                  (param_1,0x40,(param_1->s3->tmp).cert_verify_md + 0x10);
                        psVar9 = param_1->s3;
                        uVar10 = 0;
                      }
                      else {
                        uVar10 = *(uint *)(param_1->session->krb5_client_princ + 0xc);
                        if (uVar10 != 0) {
                          psVar9 = param_1->s3;
                          if (psVar9->handshake_buffer == (BIO *)0x0) {
                            ERR_put_error(0x14,0xf6,0x44,DAT_000894fc,0x29b);
                            param_1->state = 5;
                            return -1;
                          }
                          psVar9->flags = psVar9->flags | 0x20;
                          iVar4 = ssl3_digest_cached_records(param_1);
                          if (iVar4 == 0) {
                            param_1->state = 5;
                            return -1;
                          }
                          goto LAB_00088c8e;
                        }
LAB_00089064:
                        psVar9 = param_1->s3;
                      }
                    }
                  }
                }
                else {
                  if (iVar17 < 0x21a0) goto LAB_00088e48;
                  if (iVar17 < 0x21a2) {
                    iVar4 = ssl3_get_cert_verify(param_1);
                    if (iVar4 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21c0;
                    uVar10 = 0;
                    psVar9 = param_1->s3;
                  }
                  else {
                    if (1 < iVar17 - 0x21c0U) goto LAB_00088e48;
                    if (param_1->s3->change_cipher_spec == 0) {
                      param_1->d1[1].send_cookie = 1;
                    }
                    iVar4 = ssl3_get_finished(param_1,0x21c0,0x21c1);
                    if (iVar4 < 1) goto LAB_00088d14;
                    dtls1_stop_timer(param_1);
                    if (param_1->hit == 0) {
                      if (param_1->tlsext_ocsp_resplen == 0) {
                        param_1->state = 0x21d0;
                      }
                      else {
                        param_1->state = 0x21f0;
                      }
                    }
                    else {
                      param_1->state = 3;
                    }
                    param_1->init_num = 0;
                    uVar10 = 0;
                    psVar9 = param_1->s3;
                  }
                }
              }
              else if (iVar17 < 0x2202) {
                if (iVar17 < 0x2200) {
                  if (iVar17 < 0x21e0) goto LAB_00088e48;
                  if (iVar17 < 0x21e2) {
                    psVar7 = param_1->method->ssl3_enc;
                    iVar4 = ssl3_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar7 + 0x28),
                                               *(undefined4 *)(psVar7 + 0x2c));
                    if (iVar4 < 1) goto LAB_00088d14;
                    param_1->state = 0x2100;
                    psVar9 = param_1->s3;
                    if (param_1->hit == 0) {
                      (psVar9->tmp).next_state = 3;
                    }
                    else {
                      (psVar9->tmp).next_state = 0x21c0;
                    }
                    param_1->init_num = 0;
                    uVar10 = 0;
                  }
                  else {
                    if (1 < iVar17 - 0x21f0U) goto LAB_00088e48;
                    iVar4 = ssl3_send_newsession_ticket(param_1);
                    if (iVar4 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21d0;
                    uVar10 = 0;
                    psVar9 = param_1->s3;
                  }
                }
                else {
                  iVar4 = ssl3_send_cert_status(param_1);
                  if (iVar4 < 1) goto LAB_00088d14;
                  psVar9 = param_1->s3;
                  param_1->state = 0x2150;
                  uVar10 = 0;
                  param_1->init_num = 0;
                }
              }
              else {
                if ((iVar17 != 0x4000) && (iVar17 != 0x6000)) {
                  if (iVar17 != 0x3004) goto LAB_00088e48;
                  param_1->tlsext_hb_seq = 1;
                }
LAB_00088e98:
                param_1->server = 1;
                if (p_Var16 != (_func_3294 *)0x0) {
                  (*p_Var16)(param_1,0x10,1);
                }
                if ((param_1->version & 0xff00U) != 0xfe00) {
                  ERR_put_error(0x14,0xf6,0x44,DAT_000894fc,0xeb);
                  return -1;
                }
                param_1->type = 0x2000;
                if (param_1->init_buf == (BUF_MEM *)0x0) {
                  str = BUF_MEM_new();
                  if (str == (BUF_MEM *)0x0) goto LAB_00089470;
                  iVar4 = BUF_MEM_grow(str,0x4000);
                  if (iVar4 == 0) {
                    iVar4 = -1;
                    BUF_MEM_free(str);
                    param_1->state = 5;
                    goto LAB_00088d14;
                  }
                  param_1->init_buf = str;
                }
                iVar4 = ssl3_setup_buffers(param_1);
                if (iVar4 == 0) goto LAB_00089470;
                iVar4 = param_1->state;
                psVar9 = param_1->s3;
                param_1->init_num = 0;
                param_1->d1[1].send_cookie = 0;
                psVar9->change_cipher_spec = 0;
                if (iVar4 == 0x3004) {
                  uVar10 = 0;
                  *(int *)(param_1->psk_server_callback + 0x44) =
                       *(int *)(param_1->psk_server_callback + 0x44) + 1;
                  param_1->state = 0x2120;
                }
                else {
                  iVar4 = ssl_init_wbio_buffer(param_1,1);
                  if (iVar4 == 0) goto LAB_00089470;
                  ssl3_init_finished_mac(param_1);
                  param_1->state = 0x2110;
                  uVar10 = 0;
                  psVar9 = param_1->s3;
                  *(int *)(param_1->psk_server_callback + 0x40) =
                       *(int *)(param_1->psk_server_callback + 0x40) + 1;
                }
              }
LAB_00088da0:
              uVar10 = (psVar9->tmp).reuse_message | uVar10;
              iVar6 = iVar17;
            } while( true );
          }
          dtls1_start_timer(param_1);
          iVar4 = ssl3_send_server_certificate(param_1);
          if (0 < iVar4) {
            if (param_1->tlsext_status_type == 0) {
              param_1->state = 0x2150;
              psVar9 = param_1->s3;
              uVar3 = 0;
            }
            else {
              param_1->state = 0x2200;
              psVar9 = param_1->s3;
              uVar3 = 0;
            }
            goto LAB_00088be8;
          }
        }
      }
      else {
        if (0x214f < iVar17) {
          if (iVar17 < 0x2152) {
            psVar9 = param_1->s3;
            pSVar15 = (psVar9->tmp).new_cipher;
            uVar3 = pSVar15->algorithm_mkey;
            (psVar9->tmp).use_rsa_tmp = 0;
            if (((-1 < (int)(uVar3 << 0x17)) ||
                (*(int *)(param_1->psk_server_callback + 0x14c) == 0)) && ((uVar3 & 0x88) == 0)) {
              if ((int)(uVar3 << 0x1f) < 0) {
                if (*(EVP_PKEY **)(param_1->cert + 0x40) == (EVP_PKEY *)0x0) goto LAB_000890e8;
                if ((int)(pSVar15->algo_strength << 0x1e) < 0) {
                  iVar4 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x40));
                  psVar9 = param_1->s3;
                  if ((((psVar9->tmp).new_cipher)->algo_strength & 8) == 0) {
                    iVar6 = 0x400;
                  }
                  else {
                    iVar6 = 0x200;
                  }
                  if (iVar6 + iVar4 * -8 < 0 != SBORROW4(iVar6,iVar4 * 8)) goto LAB_000890e8;
                }
              }
              uVar10 = 1;
LAB_00089100:
              param_1->init_num = 0;
              param_1->state = 0x2160;
              goto LAB_00088da0;
            }
LAB_000890e8:
            dtls1_start_timer(param_1);
            iVar4 = ssl3_send_server_key_exchange(param_1);
            if (0 < iVar4) {
              psVar9 = param_1->s3;
              uVar10 = 0;
              goto LAB_00089100;
            }
            goto LAB_00088d14;
          }
          if (iVar17 - 0x2160U < 2) {
            iVar4 = param_1->verify_mode;
            if ((-1 < iVar4 << 0x1f) ||
               ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 && (iVar4 << 0x1d < 0))))
            {
              psVar9 = param_1->s3;
              uVar10 = 1;
              (psVar9->tmp).cert_request = 0;
              param_1->state = 0x2170;
              goto LAB_00088da0;
            }
            psVar9 = param_1->s3;
            pSVar15 = (psVar9->tmp).new_cipher;
            uVar3 = pSVar15->algorithm_auth;
            if ((((uVar3 & 4) != 0) && (-1 < iVar4 << 0x1e)) ||
               (((int)(uVar3 << 0x1a) < 0 || ((pSVar15->algorithm_mkey & 0x100) != 0)))) {
              (psVar9->tmp).cert_request = 0;
              uVar10 = 1;
              param_1->state = 0x2170;
              goto LAB_00088da0;
            }
            (psVar9->tmp).cert_request = 1;
            dtls1_start_timer(param_1);
            iVar4 = ssl3_send_certificate_request(param_1);
            if (0 < iVar4) {
              param_1->state = 0x2170;
              param_1->init_num = 0;
              psVar9 = param_1->s3;
              uVar10 = 0;
              goto LAB_00088da0;
            }
            goto LAB_00088d14;
          }
        }
LAB_00088e48:
        ERR_put_error(0x14,0xf6,0xff,DAT_00089150,0x36f);
        iVar4 = -1;
      }
    }
    else {
      dtls1_start_timer(param_1);
      iVar4 = ssl3_send_server_done(param_1);
      if (0 < iVar4) {
        psVar9 = param_1->s3;
        uVar3 = 0;
        (psVar9->tmp).next_state = 0x2180;
        param_1->state = 0x2100;
        goto LAB_00088be8;
      }
    }
LAB_00088d14:
    param_1->in_handshake = param_1->in_handshake + -1;
    if (p_Var16 != (_func_3294 *)0x0) {
      (*p_Var16)(param_1,0x2002,iVar4);
    }
  }
  return iVar4;
}



int dtls1_accept(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  BUF_MEM *str;
  long lVar4;
  int iVar5;
  ssl3_enc_method *psVar6;
  undefined4 uVar7;
  ssl3_state_st *psVar8;
  uint uVar9;
  dtls1_state_st *pdVar10;
  uint uVar11;
  cert_st *pcVar12;
  SSL_METHOD *pSVar13;
  SSL_CIPHER *pSVar14;
  _func_3294 *p_Var15;
  int iVar16;
  char *pcVar17;
  char *__dest;
  time_t local_2c [2];
  
  local_2c[0] = time((time_t *)0x0);
  RAND_add(local_2c,4,0.0);
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var15 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var15 == (_func_3294 *)0x0) {
    p_Var15 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  uVar11 = param_1->d1->mtu;
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  pcVar12 = param_1->cert;
  param_1->d1->mtu = uVar11;
  if (pcVar12 == (cert_st *)0x0) {
    ERR_put_error(0x14,0xf6,0xb3,"d1_srvr.c",0xc9);
    iVar3 = -1;
  }
  else {
    if (param_1->tlsext_heartbeat != 0) {
      dtls1_stop_timer(param_1);
      param_1->tlsext_heartbeat = 0;
      param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
    }
    iVar5 = param_1->state;
LAB_00088bb4:
    iVar16 = iVar5;
    if (0x2171 < iVar16) goto LAB_00088c28;
LAB_00088bbc:
    if (iVar16 < 0x2170) {
      if (iVar16 < 0x2122) {
        if (iVar16 < 0x2120) {
          if (iVar16 == 0x2100) {
            param_1->rwstate = 2;
            lVar4 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
            if (0 < lVar4) {
              psVar8 = param_1->s3;
              param_1->rwstate = 1;
              uVar9 = 0;
              param_1->state = (psVar8->tmp).next_state;
              goto LAB_00088da0;
            }
            iVar5 = BIO_test_flags(param_1->wbio,8);
            iVar3 = -1;
            if (iVar5 == 0) {
              param_1->rwstate = 1;
              iVar3 = -1;
              param_1->state = (param_1->s3->tmp).next_state;
            }
          }
          else if (iVar16 < 0x2101) {
            if (iVar16 == 0x2000) goto LAB_00088e98;
            if (iVar16 == 0x2003) goto LAB_00088e98;
            if (iVar16 != 3) goto LAB_00088e48;
            ssl3_cleanup_key_block(param_1);
            ssl_free_wbio_buffer(param_1);
            param_1->init_num = 0;
            if (param_1->tlsext_hb_seq == 2) {
              param_1->tlsext_hb_seq = 0;
              param_1->new_session = 0;
              ssl_update_cache(param_1,2);
              *(int *)(param_1->psk_server_callback + 0x48) =
                   *(int *)(param_1->psk_server_callback + 0x48) + 1;
              param_1->handshake_func = dtls1_accept;
              if (p_Var15 != (_func_3294 *)0x0) {
                (*p_Var15)(param_1,0x20,1);
              }
            }
            pdVar10 = param_1->d1;
            iVar3 = 1;
            pdVar10->handshake_read_seq = 0;
            pdVar10->handshake_write_seq = 0;
            pdVar10->next_handshake_write_seq = 0;
          }
          else {
            if (iVar16 < 0x2110) goto LAB_00088e48;
            if (iVar16 < 0x2113) {
              param_1->shutdown = 0;
              iVar3 = ssl3_get_client_hello(param_1);
              if (0 < iVar3) {
                dtls1_stop_timer(param_1);
                if ((iVar3 == 1) &&
                   (lVar4 = SSL_ctrl(param_1,0x20,0,(void *)0x0), lVar4 << 0x12 < 0)) {
                  iVar3 = 0x2113;
                }
                else {
                  iVar3 = 0x2130;
                }
                param_1->state = iVar3;
                uVar9 = 0;
                param_1->init_num = 0;
                if (uVar11 == 0) {
                  psVar8 = param_1->s3;
                  uVar9 = 0;
                  goto LAB_00088da0;
                }
                psVar8 = param_1->s3;
                uVar7 = *(undefined4 *)(psVar8->read_sequence + 4);
                *(undefined4 *)psVar8->write_sequence = *(undefined4 *)psVar8->read_sequence;
                *(undefined4 *)(psVar8->write_sequence + 4) = uVar7;
                if (param_1->state != 0x2130) goto LAB_00089064;
                pdVar10 = param_1->d1;
                iVar3 = 2;
                pdVar10->mtu = 0;
                pdVar10->handshake_read_seq = 2;
                pdVar10->handshake_write_seq = 1;
                pdVar10->next_handshake_write_seq = 1;
              }
            }
            else {
              if (0x2114 < iVar16) goto LAB_00088e48;
              if (iVar16 == 0x2113) {
                pcVar17 = param_1->init_buf->data;
                pcVar17[0xc] = -2;
                pcVar17[0xd] = -1;
                if ((*(code **)(param_1->psk_server_callback + 0x78) == (code *)0x0) ||
                   (iVar3 = (**(code **)(param_1->psk_server_callback + 0x78))
                                      (param_1,param_1->d1->cookie,&param_1->d1->cookie_len),
                   iVar3 == 0)) {
                  iVar3 = 0;
                  ERR_put_error(0x14,0x108,0x44,"d1_srvr.c",0x3a7);
                  param_1->state = 5;
                  goto LAB_00088d14;
                }
                __dest = pcVar17 + 0xf;
                pcVar17[0xe] = (char)param_1->d1->cookie_len;
                memcpy(__dest,param_1->d1->cookie,param_1->d1->cookie_len);
                uVar2 = param_1->d1->cookie_len;
                dtls1_set_message_header
                          (param_1,pcVar17,3,__dest + (uVar2 - (int)(pcVar17 + 0xc)),0,
                           __dest + (uVar2 - (int)(pcVar17 + 0xc)));
                param_1->init_off = 0;
                param_1->state = 0x2114;
                param_1->init_num = (int)(__dest + (uVar2 - (int)pcVar17));
              }
              iVar3 = dtls1_do_write(param_1,0x16);
              if (0 < iVar3) {
                iVar3 = param_1->version;
                psVar8 = param_1->s3;
                param_1->state = 0x2100;
                (psVar8->tmp).next_state = 0x2110;
                if (iVar3 == 0x100) {
                  uVar9 = 0;
                  goto LAB_00088da0;
                }
                ssl3_init_finished_mac(param_1);
                psVar8 = param_1->s3;
                uVar9 = 0;
                goto LAB_00088da0;
              }
            }
          }
        }
        else {
          param_1->shutdown = 0;
          dtls1_clear_record_buffer(param_1);
          dtls1_start_timer(param_1);
          iVar3 = ssl3_send_hello_request(param_1);
          if (0 < iVar3) {
            (param_1->s3->tmp).next_state = 0x2110;
            param_1->state = 0x2100;
            param_1->init_num = 0;
            ssl3_init_finished_mac(param_1);
            psVar8 = param_1->s3;
            uVar9 = 0;
            goto LAB_00088da0;
          }
        }
      }
      else if (iVar16 < 0x2142) {
        if (iVar16 < 0x2140) {
          if (iVar16 == 0x2122) {
            psVar8 = param_1->s3;
            param_1->state = 3;
            uVar9 = 0;
            goto LAB_00088da0;
          }
          if (1 < iVar16 - 0x2130U) goto LAB_00088e48;
          param_1->tlsext_hb_seq = 2;
          dtls1_start_timer(param_1);
          iVar3 = ssl3_send_server_hello(param_1);
          if (0 < iVar3) {
            if (param_1->hit == 0) {
              param_1->state = 0x2140;
            }
            else if (param_1->tlsext_ocsp_resplen == 0) {
              param_1->state = 0x21d0;
            }
            else {
              param_1->state = 0x21f0;
            }
            uVar9 = 0;
            param_1->init_num = 0;
            goto LAB_00089064;
          }
        }
        else {
          psVar8 = param_1->s3;
          pSVar14 = (psVar8->tmp).new_cipher;
          if (((int)(pSVar14->algorithm_auth << 0x1d) < 0) ||
             ((pSVar14->algorithm_mkey & 0x100) != 0)) {
            uVar2 = 1;
            param_1->state = 0x2150;
LAB_00088be8:
            uVar9 = (psVar8->tmp).reuse_message;
            param_1->init_num = 0;
            uVar9 = uVar9 | uVar2;
            iVar5 = iVar16;
            do {
              if (uVar9 != 0) {
LAB_00088daa:
                iVar5 = param_1->state;
                goto LAB_00088bb4;
              }
              if ((param_1->ctx != (SSL_CTX *)0x0) &&
                 (iVar3 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0), iVar3 < 1)) goto LAB_00088d14;
              if (p_Var15 == (_func_3294 *)0x0) goto LAB_00088daa;
              iVar16 = param_1->state;
              if (iVar5 == iVar16) goto LAB_00088bb4;
              param_1->state = iVar5;
              (*p_Var15)(param_1,0x2001,1);
              param_1->state = iVar16;
              if (iVar16 < 0x2172) goto LAB_00088bbc;
LAB_00088c28:
              if (iVar16 < 0x21d2) {
                if (0x21cf < iVar16) {
                  pSVar13 = param_1->method;
                  *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) =
                       (param_1->s3->tmp).new_cipher;
                  iVar3 = (**(code **)(pSVar13->ssl3_enc + 8))(param_1);
                  if (iVar3 != 0) {
                    iVar3 = dtls1_send_change_cipher_spec(param_1,0x21d0,0x21d1);
                    if (iVar3 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21e0;
                    iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
                    if (iVar3 != 0) {
                      dtls1_reset_seq_numbers(param_1,2);
LAB_00088c8e:
                      psVar8 = param_1->s3;
                      uVar9 = 0;
                      goto LAB_00088da0;
                    }
                  }
LAB_00089470:
                  iVar3 = -1;
                  param_1->state = 5;
                  goto LAB_00088d14;
                }
                if (iVar16 < 0x2192) {
                  if (iVar16 < 0x2190) {
                    if (1 < iVar16 - 0x2180U) goto LAB_00088e48;
                    psVar8 = param_1->s3;
                    if ((psVar8->tmp).cert_request != 0) {
                      iVar3 = ssl3_get_client_certificate(param_1);
                      if (iVar3 < 1) goto LAB_00088d14;
                      psVar8 = param_1->s3;
                    }
                    param_1->init_num = 0;
                    param_1->state = 0x2190;
                    uVar9 = 0;
                  }
                  else {
                    iVar3 = ssl3_get_client_key_exchange(param_1);
                    if (iVar3 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21a0;
                    if (iVar3 == 2) {
                      psVar8 = param_1->s3;
                      param_1->state = 0x21c0;
                      uVar9 = 0;
                    }
                    else {
                      psVar6 = param_1->method->ssl3_enc;
                      if ((*(uint *)(psVar6 + 0x38) & 2) == 0) {
                        (**(code **)(psVar6 + 0x1c))(param_1,4,&param_1->s3->tmp);
                        (**(code **)(param_1->method->ssl3_enc + 0x1c))
                                  (param_1,0x40,(param_1->s3->tmp).cert_verify_md + 0x10);
                        psVar8 = param_1->s3;
                        uVar9 = 0;
                      }
                      else {
                        uVar9 = *(uint *)(param_1->session->krb5_client_princ + 0xc);
                        if (uVar9 != 0) {
                          psVar8 = param_1->s3;
                          if (psVar8->handshake_buffer == (BIO *)0x0) {
                            ERR_put_error(0x14,0xf6,0x44,"d1_srvr.c",0x29b);
                            param_1->state = 5;
                            return -1;
                          }
                          psVar8->flags = psVar8->flags | 0x20;
                          iVar3 = ssl3_digest_cached_records(param_1);
                          if (iVar3 == 0) {
                            param_1->state = 5;
                            return -1;
                          }
                          goto LAB_00088c8e;
                        }
LAB_00089064:
                        psVar8 = param_1->s3;
                      }
                    }
                  }
                }
                else {
                  if (iVar16 < 0x21a0) goto LAB_00088e48;
                  if (iVar16 < 0x21a2) {
                    iVar3 = ssl3_get_cert_verify(param_1);
                    if (iVar3 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21c0;
                    uVar9 = 0;
                    psVar8 = param_1->s3;
                  }
                  else {
                    if (1 < iVar16 - 0x21c0U) goto LAB_00088e48;
                    if (param_1->s3->change_cipher_spec == 0) {
                      param_1->d1[1].send_cookie = 1;
                    }
                    iVar3 = ssl3_get_finished(param_1,0x21c0,0x21c1);
                    if (iVar3 < 1) goto LAB_00088d14;
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
                    uVar9 = 0;
                    psVar8 = param_1->s3;
                  }
                }
              }
              else if (iVar16 < 0x2202) {
                if (iVar16 < 0x2200) {
                  if (iVar16 < 0x21e0) goto LAB_00088e48;
                  if (iVar16 < 0x21e2) {
                    psVar6 = param_1->method->ssl3_enc;
                    iVar3 = ssl3_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar6 + 0x28),
                                               *(undefined4 *)(psVar6 + 0x2c));
                    if (iVar3 < 1) goto LAB_00088d14;
                    param_1->state = 0x2100;
                    psVar8 = param_1->s3;
                    if (param_1->hit == 0) {
                      (psVar8->tmp).next_state = 3;
                    }
                    else {
                      (psVar8->tmp).next_state = 0x21c0;
                    }
                    param_1->init_num = 0;
                    uVar9 = 0;
                  }
                  else {
                    if (1 < iVar16 - 0x21f0U) goto LAB_00088e48;
                    iVar3 = ssl3_send_newsession_ticket(param_1);
                    if (iVar3 < 1) goto LAB_00088d14;
                    param_1->init_num = 0;
                    param_1->state = 0x21d0;
                    uVar9 = 0;
                    psVar8 = param_1->s3;
                  }
                }
                else {
                  iVar3 = ssl3_send_cert_status(param_1);
                  if (iVar3 < 1) goto LAB_00088d14;
                  psVar8 = param_1->s3;
                  param_1->state = 0x2150;
                  uVar9 = 0;
                  param_1->init_num = 0;
                }
              }
              else {
                if ((iVar16 != 0x4000) && (iVar16 != 0x6000)) {
                  if (iVar16 != 0x3004) goto LAB_00088e48;
                  param_1->tlsext_hb_seq = 1;
                }
LAB_00088e98:
                param_1->server = 1;
                if (p_Var15 != (_func_3294 *)0x0) {
                  (*p_Var15)(param_1,0x10,1);
                }
                if ((param_1->version & 0xff00U) != 0xfe00) {
                  ERR_put_error(0x14,0xf6,0x44,"d1_srvr.c",0xeb);
                  return -1;
                }
                param_1->type = 0x2000;
                if (param_1->init_buf == (BUF_MEM *)0x0) {
                  str = BUF_MEM_new();
                  if (str == (BUF_MEM *)0x0) goto LAB_00089470;
                  iVar3 = BUF_MEM_grow(str,0x4000);
                  if (iVar3 == 0) {
                    iVar3 = -1;
                    BUF_MEM_free(str);
                    param_1->state = 5;
                    goto LAB_00088d14;
                  }
                  param_1->init_buf = str;
                }
                iVar3 = ssl3_setup_buffers(param_1);
                if (iVar3 == 0) goto LAB_00089470;
                iVar3 = param_1->state;
                psVar8 = param_1->s3;
                param_1->init_num = 0;
                param_1->d1[1].send_cookie = 0;
                psVar8->change_cipher_spec = 0;
                if (iVar3 == 0x3004) {
                  uVar9 = 0;
                  *(int *)(param_1->psk_server_callback + 0x44) =
                       *(int *)(param_1->psk_server_callback + 0x44) + 1;
                  param_1->state = 0x2120;
                }
                else {
                  iVar3 = ssl_init_wbio_buffer(param_1,1);
                  if (iVar3 == 0) goto LAB_00089470;
                  ssl3_init_finished_mac(param_1);
                  param_1->state = 0x2110;
                  uVar9 = 0;
                  psVar8 = param_1->s3;
                  *(int *)(param_1->psk_server_callback + 0x40) =
                       *(int *)(param_1->psk_server_callback + 0x40) + 1;
                }
              }
LAB_00088da0:
              uVar9 = (psVar8->tmp).reuse_message | uVar9;
              iVar5 = iVar16;
            } while( true );
          }
          dtls1_start_timer(param_1);
          iVar3 = ssl3_send_server_certificate(param_1);
          if (0 < iVar3) {
            if (param_1->tlsext_status_type == 0) {
              param_1->state = 0x2150;
              psVar8 = param_1->s3;
              uVar2 = 0;
            }
            else {
              param_1->state = 0x2200;
              psVar8 = param_1->s3;
              uVar2 = 0;
            }
            goto LAB_00088be8;
          }
        }
      }
      else {
        if (0x214f < iVar16) {
          if (iVar16 < 0x2152) {
            psVar8 = param_1->s3;
            pSVar14 = (psVar8->tmp).new_cipher;
            uVar2 = pSVar14->algorithm_mkey;
            (psVar8->tmp).use_rsa_tmp = 0;
            if (((-1 < (int)(uVar2 << 0x17)) ||
                (*(int *)(param_1->psk_server_callback + 0x14c) == 0)) && ((uVar2 & 0x88) == 0)) {
              if ((int)(uVar2 << 0x1f) < 0) {
                if (*(EVP_PKEY **)(param_1->cert + 0x40) == (EVP_PKEY *)0x0) goto LAB_000890e8;
                if ((int)(pSVar14->algo_strength << 0x1e) < 0) {
                  iVar3 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x40));
                  psVar8 = param_1->s3;
                  if ((((psVar8->tmp).new_cipher)->algo_strength & 8) == 0) {
                    iVar5 = 0x400;
                  }
                  else {
                    iVar5 = 0x200;
                  }
                  if (iVar5 + iVar3 * -8 < 0 != SBORROW4(iVar5,iVar3 * 8)) goto LAB_000890e8;
                }
              }
              uVar9 = 1;
LAB_00089100:
              param_1->init_num = 0;
              param_1->state = 0x2160;
              goto LAB_00088da0;
            }
LAB_000890e8:
            dtls1_start_timer(param_1);
            iVar3 = ssl3_send_server_key_exchange(param_1);
            if (0 < iVar3) {
              psVar8 = param_1->s3;
              uVar9 = 0;
              goto LAB_00089100;
            }
            goto LAB_00088d14;
          }
          if (iVar16 - 0x2160U < 2) {
            iVar3 = param_1->verify_mode;
            if ((-1 < iVar3 << 0x1f) ||
               ((*(int *)(param_1->session->krb5_client_princ + 0xc) != 0 && (iVar3 << 0x1d < 0))))
            {
              psVar8 = param_1->s3;
              uVar9 = 1;
              (psVar8->tmp).cert_request = 0;
              param_1->state = 0x2170;
              goto LAB_00088da0;
            }
            psVar8 = param_1->s3;
            pSVar14 = (psVar8->tmp).new_cipher;
            uVar2 = pSVar14->algorithm_auth;
            if ((((uVar2 & 4) != 0) && (-1 < iVar3 << 0x1e)) ||
               (((int)(uVar2 << 0x1a) < 0 || ((pSVar14->algorithm_mkey & 0x100) != 0)))) {
              (psVar8->tmp).cert_request = 0;
              uVar9 = 1;
              param_1->state = 0x2170;
              goto LAB_00088da0;
            }
            (psVar8->tmp).cert_request = 1;
            dtls1_start_timer(param_1);
            iVar3 = ssl3_send_certificate_request(param_1);
            if (0 < iVar3) {
              param_1->state = 0x2170;
              param_1->init_num = 0;
              psVar8 = param_1->s3;
              uVar9 = 0;
              goto LAB_00088da0;
            }
            goto LAB_00088d14;
          }
        }
LAB_00088e48:
        ERR_put_error(0x14,0xf6,0xff,"d1_srvr.c",0x36f);
        iVar3 = -1;
      }
    }
    else {
      dtls1_start_timer(param_1);
      iVar3 = ssl3_send_server_done(param_1);
      if (0 < iVar3) {
        psVar8 = param_1->s3;
        uVar2 = 0;
        (psVar8->tmp).next_state = 0x2180;
        param_1->state = 0x2100;
        goto LAB_00088be8;
      }
    }
LAB_00088d14:
    param_1->in_handshake = param_1->in_handshake + -1;
    if (p_Var15 != (_func_3294 *)0x0) {
      (*p_Var15)(param_1,0x2002,iVar3);
    }
  }
  return iVar3;
}


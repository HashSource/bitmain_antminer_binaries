
int ssl3_accept(SSL *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  EVP_MD *pEVar5;
  int iVar6;
  BUF_MEM *str;
  long lVar7;
  SSL_CIPHER *pSVar8;
  EVP_MD_CTX **ppEVar9;
  BIO *pBVar10;
  ssl3_state_st *psVar11;
  _func_3294 *p_Var12;
  int iVar13;
  code *pcVar14;
  ssl3_enc_method *psVar15;
  int local_34;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,0.0);
  ERR_clear_error();
  piVar1 = __errno_location();
  p_Var12 = param_1->info_callback;
  *piVar1 = 0;
  if (p_Var12 == (_func_3294 *)0x0) {
    p_Var12 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar2 = SSL_state(param_1);
  if (((uVar2 & 0x3000) == 0) || (iVar3 = SSL_state(param_1), iVar3 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x80,0xb3,"s3_srvr.c",0xeb);
    return -1;
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar3 = param_1->state;
LAB_00130ff2:
  iVar13 = iVar3;
  if (0x2181 < iVar13) goto LAB_00131050;
LAB_00130ff6:
  if (0x217f < iVar13) goto code_r0x00130ffc;
  if (iVar13 == 0x2122) {
    uVar2 = 0;
    param_1->state = 3;
    psVar11 = param_1->s3;
    goto LAB_0013129a;
  }
  if (iVar13 < 0x2123) {
    if (0x2112 < iVar13) {
      if (iVar13 == 0x2115) goto LAB_001313ca;
      if ((iVar13 < 0x2115) || (iVar13 < 0x2120)) goto LAB_0013118a;
      param_1->shutdown = 0;
      if (iVar13 == 0x2120) {
        (**(code **)(param_1->method->ssl3_enc + 0x40))(param_1,0,0);
        param_1->state = 0x2121;
      }
      local_34 = (**(code **)(param_1->method->ssl3_enc + 0x44))(param_1);
      if (0 < local_34) {
        (param_1->s3->tmp).next_state = 0x2122;
        param_1->state = 0x2100;
        param_1->init_num = 0;
        ssl3_init_finished_mac(param_1);
        psVar11 = param_1->s3;
        uVar2 = 0;
        goto LAB_0013129a;
      }
      goto LAB_001311a0;
    }
    if (0x210f < iVar13) {
      param_1->shutdown = 0;
      local_34 = ssl3_get_client_hello(param_1);
      if (local_34 < 1) goto LAB_001311a0;
      param_1->state = 0x2115;
LAB_001313ca:
      psVar11 = param_1->s3;
      local_2c[0] = 0x70;
      uVar4 = ((psVar11->tmp).new_cipher)->algorithm_mkey & 0x400;
      if ((uVar4 != 0) && (uVar4 = param_1[1].version, uVar4 != 0)) {
        if (param_1[1].rbio == (BIO *)0x0) {
          local_2c[0] = 0x73;
        }
        else {
          local_34 = SSL_srp_server_param_with_username(param_1,local_2c);
          if (local_34 < 0) {
            param_1->rwstate = 4;
            goto LAB_001311a0;
          }
          if (local_34 == 0) {
            psVar11 = param_1->s3;
            uVar4 = 0;
            goto LAB_00131400;
          }
        }
        ssl3_send_alert(param_1,2,local_2c[0]);
        if (local_2c[0] != 0x73) {
          ERR_put_error(0x14,0x80,0xe2,"s3_srvr.c",0x181);
        }
LAB_00131608:
        local_34 = -1;
        param_1->state = 5;
        goto LAB_001311a0;
      }
LAB_00131400:
      param_1->tlsext_hb_seq = 2;
      uVar2 = 0;
      param_1->init_num = uVar4;
      param_1->state = 0x2130;
LAB_0013129a:
      uVar2 = uVar2 | (psVar11->tmp).reuse_message;
      iVar3 = iVar13;
      if (uVar2 != 0) goto LAB_001312a4;
LAB_0013101c:
      if ((param_1->ctx != (SSL_CTX *)0x0) &&
         (local_34 = BIO_ctrl(param_1->wbio,0xb,uVar2,(void *)uVar2), local_34 < 1))
      goto LAB_001311a0;
      if (p_Var12 == (_func_3294 *)0x0) goto LAB_001312a4;
      iVar13 = param_1->state;
      if (iVar3 == iVar13) goto LAB_00130ff2;
      param_1->state = iVar3;
      (*p_Var12)(param_1,0x2001,1);
      param_1->state = iVar13;
      if (iVar13 < 0x2182) goto LAB_00130ff6;
LAB_00131050:
      if (0x21e1 < iVar13) {
        if (iVar13 < 0x2212) {
          if (iVar13 < 0x2210) {
            if (iVar13 < 0x21f0) goto LAB_0013118a;
            if (iVar13 < 0x21f2) {
              local_34 = ssl3_send_newsession_ticket(param_1);
              if (local_34 < 1) goto LAB_001311a0;
              param_1->init_num = 0;
              param_1->state = 0x21d0;
              uVar2 = 0;
              psVar11 = param_1->s3;
            }
            else {
              if (1 < iVar13 - 0x2200U) goto LAB_0013118a;
              local_34 = ssl3_send_cert_status(param_1);
              if (local_34 < 1) goto LAB_001311a0;
              param_1->init_num = 0;
              param_1->state = 0x2150;
              uVar2 = 0;
              psVar11 = param_1->s3;
            }
          }
          else {
            psVar11 = param_1->s3;
            if (psVar11->change_cipher_spec == 0) {
              psVar11->flags = psVar11->flags | 0x80;
            }
            local_34 = ssl3_get_next_proto(param_1);
            if (local_34 < 1) goto LAB_001311a0;
            param_1->init_num = 0;
            param_1->state = 0x21c0;
            uVar2 = 0;
            psVar11 = param_1->s3;
          }
        }
        else {
          if ((iVar13 != 0x4000) && (iVar13 != 0x6000)) {
            if (iVar13 != 0x3004) goto LAB_0013118a;
            param_1->tlsext_hb_seq = 1;
          }
LAB_00131222:
          param_1->server = 1;
          if (p_Var12 != (_func_3294 *)0x0) {
            (*p_Var12)(param_1,0x10,1);
          }
          if (param_1->version >> 8 != 3) {
            iVar3 = 0x10c;
LAB_001319d0:
            ERR_put_error(0x14,0x80,0x44,"s3_srvr.c",iVar3);
            goto LAB_001317c6;
          }
          param_1->type = 0x2000;
          if (param_1->init_buf == (BUF_MEM *)0x0) {
            str = BUF_MEM_new();
            if (str == (BUF_MEM *)0x0) goto LAB_00131608;
            iVar3 = BUF_MEM_grow(str,0x4000);
            if (iVar3 == 0) {
              local_34 = -1;
              BUF_MEM_free(str);
              param_1->state = 5;
              goto LAB_001311a0;
            }
            param_1->init_buf = str;
          }
          iVar3 = ssl3_setup_buffers(param_1);
          if (iVar3 == 0) goto LAB_00131608;
          psVar11 = param_1->s3;
          iVar3 = param_1->state;
          param_1->init_num = 0;
          psVar11->change_cipher_spec = 0;
          psVar11->flags = psVar11->flags & 0xffffff6f;
          if (iVar3 == 0x3004) {
            if ((psVar11->send_connection_binding == 0) && (-1 < param_1->references << 0xd)) {
              ERR_put_error(0x14,0x80,0x152,"s3_srvr.c",0x145);
              ssl3_send_alert(param_1,2,0x28);
              local_34 = -1;
              param_1->state = 5;
              goto LAB_001311a0;
            }
            uVar2 = 0;
            *(int *)(param_1->psk_server_callback + 0x44) =
                 *(int *)(param_1->psk_server_callback + 0x44) + 1;
            param_1->state = 0x2120;
          }
          else {
            iVar3 = ssl_init_wbio_buffer(param_1,1);
            if (iVar3 == 0) goto LAB_00131608;
            ssl3_init_finished_mac(param_1);
            uVar2 = 0;
            param_1->state = 0x2110;
            psVar11 = param_1->s3;
            *(int *)(param_1->psk_server_callback + 0x40) =
                 *(int *)(param_1->psk_server_callback + 0x40) + 1;
          }
        }
        goto LAB_0013129a;
      }
      if (0x21df < iVar13) {
        psVar15 = param_1->method->ssl3_enc;
        local_34 = ssl3_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar15 + 0x28),
                                      *(undefined4 *)(psVar15 + 0x2c));
        if (local_34 < 1) goto LAB_001311a0;
        param_1->state = 0x2100;
        if (param_1->hit == 0) {
          psVar11 = param_1->s3;
          (psVar11->tmp).next_state = 3;
        }
        else {
          psVar11 = param_1->s3;
          if (psVar11->next_proto_neg_seen == 0) {
            (psVar11->tmp).next_state = 0x21c0;
          }
          else {
            (psVar11->tmp).next_state = 0x2210;
          }
        }
        param_1->init_num = 0;
        uVar2 = 0;
        goto LAB_0013129a;
      }
      if (iVar13 < 0x21a2) {
        if (iVar13 < 0x21a0) {
          if (1 < iVar13 - 0x2190U) goto LAB_0013118a;
          local_34 = ssl3_get_client_key_exchange(param_1);
          if (local_34 < 1) goto LAB_001311a0;
          if (local_34 != 2) {
            if ((*(uint *)(param_1->method->ssl3_enc + 0x38) & 2) == 0) {
              psVar11 = param_1->s3;
              param_1->init_num = 0;
              param_1->state = 0x21a0;
              if (psVar11->handshake_buffer != (BIO *)0x0) {
                iVar3 = ssl3_digest_cached_records(param_1);
                if (iVar3 == 0) goto LAB_001317c6;
                psVar11 = param_1->s3;
              }
              ppEVar9 = psVar11->handshake_dgst;
              if (*ppEVar9 == (EVP_MD_CTX *)0x0) {
                iVar3 = 0;
              }
              else {
                pcVar14 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar5 = EVP_MD_CTX_md(*ppEVar9);
                iVar3 = EVP_MD_type(pEVar5);
                (*pcVar14)(param_1,iVar3,&param_1->s3->tmp);
                pEVar5 = EVP_MD_CTX_md(*param_1->s3->handshake_dgst);
                iVar3 = EVP_MD_size(pEVar5);
                if (iVar3 < 0) goto LAB_00131608;
                psVar11 = param_1->s3;
                ppEVar9 = psVar11->handshake_dgst;
              }
              if (ppEVar9[1] != (EVP_MD_CTX *)0x0) {
                pcVar14 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar5 = EVP_MD_CTX_md(ppEVar9[1]);
                iVar6 = EVP_MD_type(pEVar5);
                (*pcVar14)(param_1,iVar6,(param_1->s3->tmp).cert_verify_md + iVar3);
                pEVar5 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[1]);
                iVar6 = EVP_MD_size(pEVar5);
                if (iVar6 < 0) goto LAB_00131608;
                psVar11 = param_1->s3;
                iVar3 = iVar3 + iVar6;
                ppEVar9 = psVar11->handshake_dgst;
              }
              if (ppEVar9[2] != (EVP_MD_CTX *)0x0) {
                pcVar14 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar5 = EVP_MD_CTX_md(ppEVar9[2]);
                iVar6 = EVP_MD_type(pEVar5);
                (*pcVar14)(param_1,iVar6,(param_1->s3->tmp).cert_verify_md + iVar3);
                pEVar5 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[2]);
                iVar6 = EVP_MD_size(pEVar5);
                if (iVar6 < 0) goto LAB_00131608;
                psVar11 = param_1->s3;
                iVar3 = iVar3 + iVar6;
                ppEVar9 = psVar11->handshake_dgst;
              }
              if (ppEVar9[3] != (EVP_MD_CTX *)0x0) {
                pcVar14 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar5 = EVP_MD_CTX_md(ppEVar9[3]);
                iVar6 = EVP_MD_type(pEVar5);
                (*pcVar14)(param_1,iVar6,(param_1->s3->tmp).cert_verify_md + iVar3);
                pEVar5 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[3]);
                iVar6 = EVP_MD_size(pEVar5);
                if (iVar6 < 0) goto LAB_00131608;
                psVar11 = param_1->s3;
                iVar3 = iVar3 + iVar6;
                ppEVar9 = psVar11->handshake_dgst;
              }
              if (ppEVar9[4] != (EVP_MD_CTX *)0x0) {
                pcVar14 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar5 = EVP_MD_CTX_md(ppEVar9[4]);
                iVar6 = EVP_MD_type(pEVar5);
                (*pcVar14)(param_1,iVar6,(param_1->s3->tmp).cert_verify_md + iVar3);
                pEVar5 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[4]);
                iVar6 = EVP_MD_size(pEVar5);
                if (iVar6 < 0) goto LAB_00131608;
                psVar11 = param_1->s3;
                iVar3 = iVar3 + iVar6;
                ppEVar9 = psVar11->handshake_dgst;
              }
              if (ppEVar9[5] == (EVP_MD_CTX *)0x0) {
                uVar2 = 0;
                goto LAB_0013129a;
              }
              pcVar14 = *(code **)(param_1->method->ssl3_enc + 0x1c);
              pEVar5 = EVP_MD_CTX_md(ppEVar9[5]);
              iVar6 = EVP_MD_type(pEVar5);
              (*pcVar14)(param_1,iVar6,(param_1->s3->tmp).cert_verify_md + iVar3);
              pEVar5 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[5]);
              iVar3 = EVP_MD_size(pEVar5);
              if (iVar3 < 0) goto LAB_00131608;
            }
            else {
              param_1->state = 0x21a0;
              param_1->init_num = 0;
              if (*(int *)(param_1->session->krb5_client_princ + 0xc) == 0) goto LAB_00131348;
              psVar11 = param_1->s3;
              if (psVar11->handshake_buffer == (BIO *)0x0) {
                iVar3 = 0x279;
                goto LAB_001319d0;
              }
              psVar11->flags = psVar11->flags | 0x20;
              iVar3 = ssl3_digest_cached_records(param_1);
              if (iVar3 == 0) goto LAB_001317c6;
            }
            goto LAB_00131348;
          }
        }
        else {
          local_34 = ssl3_get_cert_verify(param_1);
          if (local_34 < 1) goto LAB_001311a0;
        }
        psVar11 = param_1->s3;
        uVar2 = 0;
        iVar3 = psVar11->next_proto_neg_seen;
        param_1->init_num = 0;
        if (iVar3 == 0) {
          iVar3 = 0x21c0;
        }
        else {
          iVar3 = 0x2210;
        }
        param_1->state = iVar3;
        goto LAB_0013129a;
      }
      if (iVar13 < 0x21c0) goto LAB_0013118a;
      if (iVar13 < 0x21c2) {
        psVar11 = param_1->s3;
        if (psVar11->change_cipher_spec == 0) {
          psVar11->flags = psVar11->flags | 0x80;
        }
        local_34 = ssl3_get_finished(param_1,0x21c0,0x21c1);
        if (local_34 < 1) goto LAB_001311a0;
        if (param_1->hit == 0) {
LAB_001316a8:
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
LAB_001316b6:
        param_1->init_num = 0;
        uVar2 = 0;
        psVar11 = param_1->s3;
        goto LAB_0013129a;
      }
      if (1 < iVar13 - 0x21d0U) goto LAB_0013118a;
      psVar15 = param_1->method->ssl3_enc;
      *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
      iVar3 = (**(code **)(psVar15 + 8))(param_1);
      if (iVar3 == 0) goto LAB_00131608;
      local_34 = ssl3_send_change_cipher_spec(param_1,0x21d0,0x21d1);
      if (local_34 < 1) goto LAB_001311a0;
      param_1->state = 0x21e0;
      param_1->init_num = 0;
      iVar3 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
      if (iVar3 == 0) goto LAB_00131608;
LAB_00131348:
      psVar11 = param_1->s3;
      uVar2 = 0;
      goto LAB_0013129a;
    }
    if (iVar13 == 0x2000) goto LAB_00131222;
    if (iVar13 < 0x2001) {
      if (iVar13 != 3) goto LAB_0013118a;
      ssl3_cleanup_key_block(param_1);
      BUF_MEM_free(param_1->init_buf);
      param_1->init_buf = (BUF_MEM *)0x0;
      ssl_free_wbio_buffer(param_1);
      param_1->init_num = 0;
      if (param_1->tlsext_hb_seq != 2) {
        local_34 = 1;
        goto LAB_001311a0;
      }
      param_1->tlsext_hb_seq = 0;
      param_1->new_session = 0;
      ssl_update_cache(param_1,2);
      *(int *)(param_1->psk_server_callback + 0x48) =
           *(int *)(param_1->psk_server_callback + 0x48) + 1;
      param_1->handshake_func = ssl3_accept;
      if (p_Var12 == (_func_3294 *)0x0) {
        param_1->in_handshake = param_1->in_handshake + -1;
        return 1;
      }
      local_34 = 1;
      (*p_Var12)(param_1,0x20,1);
      param_1->in_handshake = param_1->in_handshake + -1;
      goto LAB_001311a8;
    }
    if (iVar13 == 0x2003) goto LAB_00131222;
    if (iVar13 == 0x2100) {
      param_1->rwstate = 2;
      lVar7 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
      if (0 < lVar7) {
        psVar11 = param_1->s3;
        param_1->rwstate = 1;
        uVar2 = 0;
        param_1->state = (psVar11->tmp).next_state;
        goto LAB_0013129a;
      }
      local_34 = -1;
      goto LAB_001311a0;
    }
  }
  else if (iVar13 < 0x2152) {
    if (0x214f < iVar13) {
      psVar11 = param_1->s3;
      pSVar8 = (psVar11->tmp).new_cipher;
      uVar2 = pSVar8->algorithm_mkey;
      (psVar11->tmp).use_rsa_tmp = 0;
      if ((((int)(uVar2 << 0x17) < 0) && (*(int *)(param_1->psk_server_callback + 0x14c) != 0)) ||
         ((uVar2 & 0x488) != 0)) {
LAB_0013162c:
        local_34 = ssl3_send_server_key_exchange(param_1);
        if (local_34 < 1) goto LAB_001311a0;
        psVar11 = param_1->s3;
        uVar2 = 0;
      }
      else {
        if ((int)(uVar2 << 0x1f) < 0) {
          if (*(EVP_PKEY **)(param_1->cert + 0x40) == (EVP_PKEY *)0x0) goto LAB_0013162c;
          if ((int)(pSVar8->algo_strength << 0x1e) < 0) {
            iVar3 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x40));
            psVar11 = param_1->s3;
            if ((((psVar11->tmp).new_cipher)->algo_strength & 8) == 0) {
              iVar6 = 0x400;
            }
            else {
              iVar6 = 0x200;
            }
            if (iVar6 + iVar3 * -8 < 0 != SBORROW4(iVar6,iVar3 * 8)) goto LAB_0013162c;
          }
        }
        uVar2 = 1;
      }
      param_1->init_num = 0;
      param_1->state = 0x2160;
      goto LAB_0013129a;
    }
    if (0x212f < iVar13) {
      if (iVar13 < 0x2132) {
        local_34 = ssl3_send_server_hello(param_1);
        if (0 < local_34) {
          if (param_1->hit != 0) goto LAB_001316a8;
          param_1->state = 0x2140;
          goto LAB_001316b6;
        }
        goto LAB_001311a0;
      }
      if (iVar13 - 0x2140U < 2) {
        psVar11 = param_1->s3;
        pSVar8 = (psVar11->tmp).new_cipher;
        if (((pSVar8->algorithm_auth & 0x424) == 0) && ((pSVar8->algorithm_mkey & 0x100) == 0)) {
          local_34 = ssl3_send_server_certificate(param_1);
          if (local_34 < 1) goto LAB_001311a0;
          if (param_1->tlsext_status_type == 0) {
            param_1->state = 0x2150;
            psVar11 = param_1->s3;
            uVar2 = 0;
          }
          else {
            param_1->state = 0x2200;
            psVar11 = param_1->s3;
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 1;
          param_1->state = 0x2150;
        }
        param_1->init_num = 0;
        goto LAB_0013129a;
      }
    }
  }
  else if (0x215f < iVar13) {
    if (0x2161 < iVar13) {
      if (1 < iVar13 - 0x2170U) goto LAB_0013118a;
      if (iVar13 == 0x2170) {
        (**(code **)(param_1->method->ssl3_enc + 0x40))(param_1,0xe,0);
        param_1->state = 0x2171;
      }
      local_34 = (**(code **)(param_1->method->ssl3_enc + 0x44))(param_1);
      if (0 < local_34) {
        psVar11 = param_1->s3;
        uVar2 = 0;
        (psVar11->tmp).next_state = 0x2180;
        param_1->init_num = 0;
        param_1->state = 0x2100;
        goto LAB_0013129a;
      }
      goto LAB_001311a0;
    }
    iVar3 = param_1->verify_mode;
    if ((iVar3 << 0x1f < 0) &&
       ((*(int *)(param_1->session->krb5_client_princ + 0xc) == 0 || (-1 < iVar3 << 0x1d)))) {
      psVar11 = param_1->s3;
      pSVar8 = (psVar11->tmp).new_cipher;
      if ((((-1 < (int)(pSVar8->algorithm_auth << 0x1d)) || (iVar3 << 0x1e < 0)) &&
          ((pSVar8->algorithm_auth & 0x420) == 0)) && ((pSVar8->algorithm_mkey & 0x100) == 0)) {
        (psVar11->tmp).cert_request = 1;
        local_34 = ssl3_send_certificate_request(param_1);
        if (0 < local_34) {
          psVar11 = param_1->s3;
          param_1->state = 0x2100;
          (psVar11->tmp).next_state = 0x2180;
          param_1->init_num = 0;
          uVar2 = 0;
          goto LAB_0013129a;
        }
        goto LAB_001311a0;
      }
    }
    else {
      psVar11 = param_1->s3;
    }
    pBVar10 = psVar11->handshake_buffer;
    (psVar11->tmp).cert_request = 0;
    param_1->state = 0x2170;
    if (pBVar10 == (BIO *)0x0) {
      uVar2 = 1;
    }
    else {
      iVar3 = ssl3_digest_cached_records(param_1);
      if (iVar3 == 0) {
LAB_001317c6:
        param_1->state = 5;
        return -1;
      }
      psVar11 = param_1->s3;
      uVar2 = 1;
    }
    goto LAB_0013129a;
  }
LAB_0013118a:
  ERR_put_error(0x14,0x80,0xff,"s3_srvr.c",0x35d);
  local_34 = -1;
  goto LAB_001311a0;
code_r0x00130ffc:
  psVar11 = param_1->s3;
  if ((psVar11->tmp).cert_request == 0) {
    param_1->init_num = 0;
    param_1->state = 0x2190;
  }
  else {
    local_34 = ssl3_get_client_certificate(param_1);
    if (local_34 < 1) {
LAB_001311a0:
      param_1->in_handshake = param_1->in_handshake + -1;
      if (p_Var12 == (_func_3294 *)0x0) {
        return local_34;
      }
LAB_001311a8:
      (*p_Var12)(param_1,0x2002,local_34);
      return local_34;
    }
    psVar11 = param_1->s3;
    param_1->init_num = 0;
    param_1->state = 0x2190;
  }
  uVar2 = (psVar11->tmp).reuse_message;
  iVar3 = iVar13;
  if (uVar2 == 0) goto LAB_0013101c;
LAB_001312a4:
  iVar3 = param_1->state;
  goto LAB_00130ff2;
}


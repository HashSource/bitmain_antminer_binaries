
int ssl3_accept(SSL *param_1)

{
  _func_3291 *p_Var1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  EVP_MD *pEVar6;
  int iVar7;
  BUF_MEM *str;
  long lVar8;
  SSL_CIPHER *pSVar9;
  EVP_MD_CTX **ppEVar10;
  BIO *pBVar11;
  ssl3_state_st *psVar12;
  _func_3294 *p_Var13;
  int iVar14;
  code *pcVar15;
  ssl3_enc_method *psVar16;
  undefined4 in_stack_ffffffc0;
  undefined4 in_stack_ffffffc4;
  int local_34;
  time_t local_30;
  int local_2c [2];
  
  local_30 = time((time_t *)0x0);
  RAND_add(&local_30,4,(double)CONCAT44(in_stack_ffffffc4,in_stack_ffffffc0));
  ERR_clear_error();
  piVar2 = __errno_location();
  p_Var13 = param_1->info_callback;
  *piVar2 = 0;
  if (p_Var13 == (_func_3294 *)0x0) {
    p_Var13 = *(_func_3294 **)(param_1->psk_server_callback + 0x9c);
  }
  param_1->in_handshake = param_1->in_handshake + 1;
  uVar3 = SSL_state(param_1);
  if (((uVar3 & 0x3000) == 0) || (iVar4 = SSL_state(param_1), iVar4 << 0x11 < 0)) {
    SSL_clear(param_1);
  }
  if (param_1->cert == (cert_st *)0x0) {
    ERR_put_error(0x14,0x80,0xb3,DAT_00088ac4,0xeb);
    return -1;
  }
  if (param_1->tlsext_heartbeat != 0) {
    param_1->tlsext_heartbeat = 0;
    param_1->tlsext_hb_pending = param_1->tlsext_hb_pending + 1;
  }
  iVar4 = param_1->state;
LAB_0008808a:
  iVar14 = iVar4;
  if (0x2181 < iVar14) goto LAB_000880e8;
LAB_0008808e:
  if (0x217f < iVar14) goto code_r0x00088094;
  if (iVar14 == 0x2122) {
    uVar3 = 0;
    param_1->state = 3;
    psVar12 = param_1->s3;
    goto LAB_00088332;
  }
  if (iVar14 < 0x2123) {
    if (0x2112 < iVar14) {
      if (iVar14 == 0x2115) goto LAB_00088462;
      if ((iVar14 < 0x2115) || (iVar14 < 0x2120)) goto LAB_00088222;
      param_1->shutdown = 0;
      if (iVar14 == 0x2120) {
        (**(code **)(param_1->method->ssl3_enc + 0x40))(param_1,0,0);
        param_1->state = 0x2121;
      }
      local_34 = (**(code **)(param_1->method->ssl3_enc + 0x44))(param_1);
      if (0 < local_34) {
        (param_1->s3->tmp).next_state = 0x2122;
        param_1->state = 0x2100;
        param_1->init_num = 0;
        ssl3_init_finished_mac(param_1);
        psVar12 = param_1->s3;
        uVar3 = 0;
        goto LAB_00088332;
      }
      goto LAB_00088238;
    }
    if (0x210f < iVar14) {
      param_1->shutdown = 0;
      local_34 = ssl3_get_client_hello(param_1);
      if (local_34 < 1) goto LAB_00088238;
      param_1->state = 0x2115;
LAB_00088462:
      psVar12 = param_1->s3;
      local_2c[0] = 0x70;
      uVar5 = ((psVar12->tmp).new_cipher)->algorithm_mkey & 0x400;
      if ((uVar5 != 0) && (uVar5 = param_1[1].version, uVar5 != 0)) {
        if (param_1[1].rbio == (BIO *)0x0) {
          local_2c[0] = 0x73;
        }
        else {
          local_34 = SSL_srp_server_param_with_username(param_1,local_2c);
          if (local_34 < 0) {
            param_1->rwstate = 4;
            goto LAB_00088238;
          }
          if (local_34 == 0) {
            psVar12 = param_1->s3;
            uVar5 = 0;
            goto LAB_00088498;
          }
        }
        ssl3_send_alert(param_1,2,local_2c[0]);
        if (local_2c[0] != 0x73) {
          ERR_put_error(0x14,0x80,0xe2,DAT_00088aa0,0x181);
        }
LAB_000886a0:
        local_34 = -1;
        param_1->state = 5;
        goto LAB_00088238;
      }
LAB_00088498:
      param_1->tlsext_hb_seq = 2;
      uVar3 = 0;
      param_1->init_num = uVar5;
      param_1->state = 0x2130;
LAB_00088332:
      uVar3 = uVar3 | (psVar12->tmp).reuse_message;
      iVar4 = iVar14;
      if (uVar3 != 0) goto LAB_0008833c;
LAB_000880b4:
      if ((param_1->ctx != (SSL_CTX *)0x0) &&
         (local_34 = BIO_ctrl(param_1->wbio,0xb,uVar3,(void *)uVar3), local_34 < 1))
      goto LAB_00088238;
      if (p_Var13 == (_func_3294 *)0x0) goto LAB_0008833c;
      iVar14 = param_1->state;
      if (iVar4 == iVar14) goto LAB_0008808a;
      param_1->state = iVar4;
      (*p_Var13)(param_1,0x2001,1);
      param_1->state = iVar14;
      if (iVar14 < 0x2182) goto LAB_0008808e;
LAB_000880e8:
      if (0x21e1 < iVar14) {
        if (iVar14 < 0x2212) {
          if (iVar14 < 0x2210) {
            if (iVar14 < 0x21f0) goto LAB_00088222;
            if (iVar14 < 0x21f2) {
              local_34 = ssl3_send_newsession_ticket(param_1);
              if (local_34 < 1) goto LAB_00088238;
              param_1->init_num = 0;
              param_1->state = 0x21d0;
              uVar3 = 0;
              psVar12 = param_1->s3;
            }
            else {
              if (1 < iVar14 - 0x2200U) goto LAB_00088222;
              local_34 = ssl3_send_cert_status(param_1);
              if (local_34 < 1) goto LAB_00088238;
              param_1->init_num = 0;
              param_1->state = 0x2150;
              uVar3 = 0;
              psVar12 = param_1->s3;
            }
          }
          else {
            psVar12 = param_1->s3;
            if (psVar12->change_cipher_spec == 0) {
              psVar12->flags = psVar12->flags | 0x80;
            }
            local_34 = ssl3_get_next_proto(param_1);
            if (local_34 < 1) goto LAB_00088238;
            param_1->init_num = 0;
            param_1->state = 0x21c0;
            uVar3 = 0;
            psVar12 = param_1->s3;
          }
        }
        else {
          if ((iVar14 != 0x4000) && (iVar14 != 0x6000)) {
            if (iVar14 != 0x3004) goto LAB_00088222;
            param_1->tlsext_hb_seq = 1;
          }
LAB_000882ba:
          param_1->server = 1;
          if (p_Var13 != (_func_3294 *)0x0) {
            (*p_Var13)(param_1,0x10,1);
          }
          if (param_1->version >> 8 != 3) {
            iVar4 = 0x10c;
LAB_00088a68:
            ERR_put_error(0x14,0x80,0x44,DAT_00088aa0,iVar4);
            goto LAB_0008885e;
          }
          param_1->type = 0x2000;
          if (param_1->init_buf == (BUF_MEM *)0x0) {
            str = BUF_MEM_new();
            if (str == (BUF_MEM *)0x0) goto LAB_000886a0;
            iVar4 = BUF_MEM_grow(str,0x4000);
            if (iVar4 == 0) {
              local_34 = -1;
              BUF_MEM_free(str);
              param_1->state = 5;
              goto LAB_00088238;
            }
            param_1->init_buf = str;
          }
          iVar4 = ssl3_setup_buffers(param_1);
          if (iVar4 == 0) goto LAB_000886a0;
          psVar12 = param_1->s3;
          iVar4 = param_1->state;
          param_1->init_num = 0;
          psVar12->change_cipher_spec = 0;
          psVar12->flags = psVar12->flags & 0xffffff6f;
          if (iVar4 == 0x3004) {
            if ((psVar12->send_connection_binding == 0) && (-1 < param_1->references << 0xd)) {
              ERR_put_error(0x14,0x80,0x152,DAT_00088aa0,0x145);
              ssl3_send_alert(param_1,2,0x28);
              local_34 = -1;
              param_1->state = 5;
              goto LAB_00088238;
            }
            uVar3 = 0;
            *(int *)(param_1->psk_server_callback + 0x44) =
                 *(int *)(param_1->psk_server_callback + 0x44) + 1;
            param_1->state = 0x2120;
          }
          else {
            iVar4 = ssl_init_wbio_buffer(param_1,1);
            if (iVar4 == 0) goto LAB_000886a0;
            ssl3_init_finished_mac(param_1);
            uVar3 = 0;
            param_1->state = 0x2110;
            psVar12 = param_1->s3;
            *(int *)(param_1->psk_server_callback + 0x40) =
                 *(int *)(param_1->psk_server_callback + 0x40) + 1;
          }
        }
        goto LAB_00088332;
      }
      if (0x21df < iVar14) {
        psVar16 = param_1->method->ssl3_enc;
        local_34 = ssl3_send_finished(param_1,0x21e0,0x21e1,*(undefined4 *)(psVar16 + 0x28),
                                      *(undefined4 *)(psVar16 + 0x2c));
        if (local_34 < 1) goto LAB_00088238;
        param_1->state = 0x2100;
        if (param_1->hit == 0) {
          psVar12 = param_1->s3;
          (psVar12->tmp).next_state = 3;
        }
        else {
          psVar12 = param_1->s3;
          if (psVar12->next_proto_neg_seen == 0) {
            (psVar12->tmp).next_state = 0x21c0;
          }
          else {
            (psVar12->tmp).next_state = 0x2210;
          }
        }
        param_1->init_num = 0;
        uVar3 = 0;
        goto LAB_00088332;
      }
      if (iVar14 < 0x21a2) {
        if (iVar14 < 0x21a0) {
          if (1 < iVar14 - 0x2190U) goto LAB_00088222;
          local_34 = ssl3_get_client_key_exchange(param_1);
          if (local_34 < 1) goto LAB_00088238;
          if (local_34 != 2) {
            if ((*(uint *)(param_1->method->ssl3_enc + 0x38) & 2) == 0) {
              psVar12 = param_1->s3;
              param_1->init_num = 0;
              param_1->state = 0x21a0;
              if (psVar12->handshake_buffer != (BIO *)0x0) {
                iVar4 = ssl3_digest_cached_records(param_1);
                if (iVar4 == 0) goto LAB_0008885e;
                psVar12 = param_1->s3;
              }
              ppEVar10 = psVar12->handshake_dgst;
              if (*ppEVar10 == (EVP_MD_CTX *)0x0) {
                iVar4 = 0;
              }
              else {
                pcVar15 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar6 = EVP_MD_CTX_md(*ppEVar10);
                iVar4 = EVP_MD_type(pEVar6);
                (*pcVar15)(param_1,iVar4,&param_1->s3->tmp);
                pEVar6 = EVP_MD_CTX_md(*param_1->s3->handshake_dgst);
                iVar4 = EVP_MD_size(pEVar6);
                if (iVar4 < 0) goto LAB_000886a0;
                psVar12 = param_1->s3;
                ppEVar10 = psVar12->handshake_dgst;
              }
              if (ppEVar10[1] != (EVP_MD_CTX *)0x0) {
                pcVar15 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar6 = EVP_MD_CTX_md(ppEVar10[1]);
                iVar7 = EVP_MD_type(pEVar6);
                (*pcVar15)(param_1,iVar7,(param_1->s3->tmp).cert_verify_md + iVar4);
                pEVar6 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[1]);
                iVar7 = EVP_MD_size(pEVar6);
                if (iVar7 < 0) goto LAB_000886a0;
                psVar12 = param_1->s3;
                iVar4 = iVar4 + iVar7;
                ppEVar10 = psVar12->handshake_dgst;
              }
              if (ppEVar10[2] != (EVP_MD_CTX *)0x0) {
                pcVar15 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar6 = EVP_MD_CTX_md(ppEVar10[2]);
                iVar7 = EVP_MD_type(pEVar6);
                (*pcVar15)(param_1,iVar7,(param_1->s3->tmp).cert_verify_md + iVar4);
                pEVar6 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[2]);
                iVar7 = EVP_MD_size(pEVar6);
                if (iVar7 < 0) goto LAB_000886a0;
                psVar12 = param_1->s3;
                iVar4 = iVar4 + iVar7;
                ppEVar10 = psVar12->handshake_dgst;
              }
              if (ppEVar10[3] != (EVP_MD_CTX *)0x0) {
                pcVar15 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar6 = EVP_MD_CTX_md(ppEVar10[3]);
                iVar7 = EVP_MD_type(pEVar6);
                (*pcVar15)(param_1,iVar7,(param_1->s3->tmp).cert_verify_md + iVar4);
                pEVar6 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[3]);
                iVar7 = EVP_MD_size(pEVar6);
                if (iVar7 < 0) goto LAB_000886a0;
                psVar12 = param_1->s3;
                iVar4 = iVar4 + iVar7;
                ppEVar10 = psVar12->handshake_dgst;
              }
              if (ppEVar10[4] != (EVP_MD_CTX *)0x0) {
                pcVar15 = *(code **)(param_1->method->ssl3_enc + 0x1c);
                pEVar6 = EVP_MD_CTX_md(ppEVar10[4]);
                iVar7 = EVP_MD_type(pEVar6);
                (*pcVar15)(param_1,iVar7,(param_1->s3->tmp).cert_verify_md + iVar4);
                pEVar6 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[4]);
                iVar7 = EVP_MD_size(pEVar6);
                if (iVar7 < 0) goto LAB_000886a0;
                psVar12 = param_1->s3;
                iVar4 = iVar4 + iVar7;
                ppEVar10 = psVar12->handshake_dgst;
              }
              if (ppEVar10[5] == (EVP_MD_CTX *)0x0) {
                uVar3 = 0;
                goto LAB_00088332;
              }
              pcVar15 = *(code **)(param_1->method->ssl3_enc + 0x1c);
              pEVar6 = EVP_MD_CTX_md(ppEVar10[5]);
              iVar7 = EVP_MD_type(pEVar6);
              (*pcVar15)(param_1,iVar7,(param_1->s3->tmp).cert_verify_md + iVar4);
              pEVar6 = EVP_MD_CTX_md(param_1->s3->handshake_dgst[5]);
              iVar4 = EVP_MD_size(pEVar6);
              if (iVar4 < 0) goto LAB_000886a0;
            }
            else {
              param_1->state = 0x21a0;
              param_1->init_num = 0;
              if (*(int *)(param_1->session->krb5_client_princ + 0xc) == 0) goto LAB_000883e0;
              psVar12 = param_1->s3;
              if (psVar12->handshake_buffer == (BIO *)0x0) {
                iVar4 = 0x279;
                goto LAB_00088a68;
              }
              psVar12->flags = psVar12->flags | 0x20;
              iVar4 = ssl3_digest_cached_records(param_1);
              if (iVar4 == 0) goto LAB_0008885e;
            }
            goto LAB_000883e0;
          }
        }
        else {
          local_34 = ssl3_get_cert_verify(param_1);
          if (local_34 < 1) goto LAB_00088238;
        }
        psVar12 = param_1->s3;
        uVar3 = 0;
        iVar4 = psVar12->next_proto_neg_seen;
        param_1->init_num = 0;
        if (iVar4 == 0) {
          iVar4 = 0x21c0;
        }
        else {
          iVar4 = 0x2210;
        }
        param_1->state = iVar4;
        goto LAB_00088332;
      }
      if (iVar14 < 0x21c0) goto LAB_00088222;
      if (iVar14 < 0x21c2) {
        psVar12 = param_1->s3;
        if (psVar12->change_cipher_spec == 0) {
          psVar12->flags = psVar12->flags | 0x80;
        }
        local_34 = ssl3_get_finished(param_1,0x21c0,0x21c1);
        if (local_34 < 1) goto LAB_00088238;
        if (param_1->hit == 0) {
LAB_00088740:
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
LAB_0008874e:
        param_1->init_num = 0;
        uVar3 = 0;
        psVar12 = param_1->s3;
        goto LAB_00088332;
      }
      if (1 < iVar14 - 0x21d0U) goto LAB_00088222;
      psVar16 = param_1->method->ssl3_enc;
      *(SSL_CIPHER **)(param_1->session->krb5_client_princ + 0x24) = (param_1->s3->tmp).new_cipher;
      iVar4 = (**(code **)(psVar16 + 8))(param_1);
      if (iVar4 == 0) goto LAB_000886a0;
      local_34 = ssl3_send_change_cipher_spec(param_1,0x21d0,0x21d1);
      if (local_34 < 1) goto LAB_00088238;
      param_1->state = 0x21e0;
      param_1->init_num = 0;
      iVar4 = (**(code **)(param_1->method->ssl3_enc + 0x10))(param_1,0x22);
      if (iVar4 == 0) goto LAB_000886a0;
LAB_000883e0:
      psVar12 = param_1->s3;
      uVar3 = 0;
      goto LAB_00088332;
    }
    if (iVar14 == 0x2000) goto LAB_000882ba;
    if (iVar14 < 0x2001) {
      if (iVar14 != 3) goto LAB_00088222;
      ssl3_cleanup_key_block(param_1);
      BUF_MEM_free(param_1->init_buf);
      param_1->init_buf = (BUF_MEM *)0x0;
      ssl_free_wbio_buffer(param_1);
      param_1->init_num = 0;
      if (param_1->tlsext_hb_seq != 2) {
        local_34 = 1;
        goto LAB_00088238;
      }
      param_1->tlsext_hb_seq = 0;
      param_1->new_session = 0;
      ssl_update_cache(param_1,2);
      p_Var1 = DAT_00088a9c;
      *(int *)(param_1->psk_server_callback + 0x48) =
           *(int *)(param_1->psk_server_callback + 0x48) + 1;
      param_1->handshake_func = p_Var1;
      if (p_Var13 == (_func_3294 *)0x0) {
        param_1->in_handshake = param_1->in_handshake + -1;
        return 1;
      }
      local_34 = 1;
      (*p_Var13)(param_1,0x20,1);
      param_1->in_handshake = param_1->in_handshake + -1;
      goto LAB_00088240;
    }
    if (iVar14 == 0x2003) goto LAB_000882ba;
    if (iVar14 == 0x2100) {
      param_1->rwstate = 2;
      lVar8 = BIO_ctrl(param_1->wbio,0xb,0,(void *)0x0);
      if (0 < lVar8) {
        psVar12 = param_1->s3;
        param_1->rwstate = 1;
        uVar3 = 0;
        param_1->state = (psVar12->tmp).next_state;
        goto LAB_00088332;
      }
      local_34 = -1;
      goto LAB_00088238;
    }
  }
  else if (iVar14 < 0x2152) {
    if (0x214f < iVar14) {
      psVar12 = param_1->s3;
      pSVar9 = (psVar12->tmp).new_cipher;
      uVar3 = pSVar9->algorithm_mkey;
      (psVar12->tmp).use_rsa_tmp = 0;
      if ((((int)(uVar3 << 0x17) < 0) && (*(int *)(param_1->psk_server_callback + 0x14c) != 0)) ||
         ((uVar3 & 0x488) != 0)) {
LAB_000886c4:
        local_34 = ssl3_send_server_key_exchange(param_1);
        if (local_34 < 1) goto LAB_00088238;
        psVar12 = param_1->s3;
        uVar3 = 0;
      }
      else {
        if ((int)(uVar3 << 0x1f) < 0) {
          if (*(EVP_PKEY **)(param_1->cert + 0x40) == (EVP_PKEY *)0x0) goto LAB_000886c4;
          if ((int)(pSVar9->algo_strength << 0x1e) < 0) {
            iVar4 = EVP_PKEY_size(*(EVP_PKEY **)(param_1->cert + 0x40));
            psVar12 = param_1->s3;
            if ((((psVar12->tmp).new_cipher)->algo_strength & 8) == 0) {
              iVar7 = 0x400;
            }
            else {
              iVar7 = 0x200;
            }
            if (iVar7 + iVar4 * -8 < 0 != SBORROW4(iVar7,iVar4 * 8)) goto LAB_000886c4;
          }
        }
        uVar3 = 1;
      }
      param_1->init_num = 0;
      param_1->state = 0x2160;
      goto LAB_00088332;
    }
    if (0x212f < iVar14) {
      if (iVar14 < 0x2132) {
        local_34 = ssl3_send_server_hello(param_1);
        if (0 < local_34) {
          if (param_1->hit != 0) goto LAB_00088740;
          param_1->state = 0x2140;
          goto LAB_0008874e;
        }
        goto LAB_00088238;
      }
      if (iVar14 - 0x2140U < 2) {
        psVar12 = param_1->s3;
        pSVar9 = (psVar12->tmp).new_cipher;
        if (((pSVar9->algorithm_auth & 0x424) == 0) && ((pSVar9->algorithm_mkey & 0x100) == 0)) {
          local_34 = ssl3_send_server_certificate(param_1);
          if (local_34 < 1) goto LAB_00088238;
          if (param_1->tlsext_status_type == 0) {
            param_1->state = 0x2150;
            psVar12 = param_1->s3;
            uVar3 = 0;
          }
          else {
            param_1->state = 0x2200;
            psVar12 = param_1->s3;
            uVar3 = 0;
          }
        }
        else {
          uVar3 = 1;
          param_1->state = 0x2150;
        }
        param_1->init_num = 0;
        goto LAB_00088332;
      }
    }
  }
  else if (0x215f < iVar14) {
    if (0x2161 < iVar14) {
      if (1 < iVar14 - 0x2170U) goto LAB_00088222;
      if (iVar14 == 0x2170) {
        (**(code **)(param_1->method->ssl3_enc + 0x40))(param_1,0xe,0);
        param_1->state = 0x2171;
      }
      local_34 = (**(code **)(param_1->method->ssl3_enc + 0x44))(param_1);
      if (0 < local_34) {
        psVar12 = param_1->s3;
        uVar3 = 0;
        (psVar12->tmp).next_state = 0x2180;
        param_1->init_num = 0;
        param_1->state = 0x2100;
        goto LAB_00088332;
      }
      goto LAB_00088238;
    }
    iVar4 = param_1->verify_mode;
    if ((iVar4 << 0x1f < 0) &&
       ((*(int *)(param_1->session->krb5_client_princ + 0xc) == 0 || (-1 < iVar4 << 0x1d)))) {
      psVar12 = param_1->s3;
      pSVar9 = (psVar12->tmp).new_cipher;
      if ((((-1 < (int)(pSVar9->algorithm_auth << 0x1d)) || (iVar4 << 0x1e < 0)) &&
          ((pSVar9->algorithm_auth & 0x420) == 0)) && ((pSVar9->algorithm_mkey & 0x100) == 0)) {
        (psVar12->tmp).cert_request = 1;
        local_34 = ssl3_send_certificate_request(param_1);
        if (0 < local_34) {
          psVar12 = param_1->s3;
          param_1->state = 0x2100;
          (psVar12->tmp).next_state = 0x2180;
          param_1->init_num = 0;
          uVar3 = 0;
          goto LAB_00088332;
        }
        goto LAB_00088238;
      }
    }
    else {
      psVar12 = param_1->s3;
    }
    pBVar11 = psVar12->handshake_buffer;
    (psVar12->tmp).cert_request = 0;
    param_1->state = 0x2170;
    if (pBVar11 == (BIO *)0x0) {
      uVar3 = 1;
    }
    else {
      iVar4 = ssl3_digest_cached_records(param_1);
      if (iVar4 == 0) {
LAB_0008885e:
        param_1->state = 5;
        return -1;
      }
      psVar12 = param_1->s3;
      uVar3 = 1;
    }
    goto LAB_00088332;
  }
LAB_00088222:
  ERR_put_error(0x14,0x80,0xff,DAT_000882b0,0x35d);
  local_34 = -1;
  goto LAB_00088238;
code_r0x00088094:
  psVar12 = param_1->s3;
  if ((psVar12->tmp).cert_request == 0) {
    param_1->init_num = 0;
    param_1->state = 0x2190;
  }
  else {
    local_34 = ssl3_get_client_certificate(param_1);
    if (local_34 < 1) {
LAB_00088238:
      param_1->in_handshake = param_1->in_handshake + -1;
      if (p_Var13 == (_func_3294 *)0x0) {
        return local_34;
      }
LAB_00088240:
      (*p_Var13)(param_1,0x2002,local_34);
      return local_34;
    }
    psVar12 = param_1->s3;
    param_1->init_num = 0;
    param_1->state = 0x2190;
  }
  uVar3 = (psVar12->tmp).reuse_message;
  iVar4 = iVar14;
  if (uVar3 == 0) goto LAB_000880b4;
LAB_0008833c:
  iVar4 = param_1->state;
  goto LAB_0008808a;
}


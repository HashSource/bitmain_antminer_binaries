
SSL * SSL_new(SSL_CTX *ctx)

{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  SSL *s;
  int iVar5;
  void *pvVar6;
  GEN_SESSION_CB pGVar7;
  uint uVar8;
  X509_VERIFY_PARAM *pXVar9;
  _func_3245 *p_Var10;
  _func_3293 *__dest;
  SSL_CTX *pSVar11;
  stack_st_X509 *psVar12;
  ulong uVar13;
  EVP_MD_CTX *pEVar14;
  stack_st_X509_NAME *psVar15;
  COMP_CTX *pCVar16;
  stack_st_SSL_CIPHER *psVar17;
  _func_3237 *p_Var18;
  ENGINE *pEVar19;
  SSL_METHOD *pSVar20;
  _func_3197 *p_Var21;
  code *pcVar22;
  cert_st *pcVar23;
  int iVar24;
  int iVar25;
  X509_EXTENSIONS *pXVar26;
  
  if (ctx == (SSL_CTX *)0x0) {
    ERR_put_error(0x14,0xba,0xc3,"ssl/ssl_lib.c",0x2ab);
    return (SSL *)0x0;
  }
  if (ctx->method == (SSL_METHOD *)0x0) {
    ERR_put_error(0x14,0xba,0xe4,"ssl/ssl_lib.c",0x2af);
    return (SSL *)0x0;
  }
  s = (SSL *)CRYPTO_zalloc(0xf90,"ssl/ssl_lib.c",0x2b3);
  if (s != (SSL *)0x0) {
    DataMemoryBarrier(0x1b);
    s[3].handshake_func = (_func_3291 *)0x1;
    DataMemoryBarrier(0x1b);
    iVar5 = CRYPTO_THREAD_lock_new();
    s[9].first_packet = iVar5;
    if (iVar5 == 0) {
      CRYPTO_free(s);
      s = (SSL *)0x0;
    }
    else {
      RECORD_LAYER_init(&s[3].tlsext_heartbeat,s);
      psVar12 = ctx[1].extra_certs;
      iVar5 = ctx->read_ahead;
      p_Var18 = ctx->msg_callback;
      pcVar23 = ctx->cert;
      s[3].server = ctx->max_cert_list;
      pvVar6 = ctx->msg_callback_arg;
      s[3].new_session = (int)pcVar23;
      *(stack_st_X509 **)(s->sid_ctx + 0x14) = psVar12;
      iVar24 = *(int *)(ctx[1].sid_ctx + 0xc);
      uVar13 = ctx[1].mode;
      s[3].quiet_shutdown = iVar5;
      psVar15 = (stack_st_X509_NAME *)ctx[1].max_cert_list;
      s[3].shutdown = (int)p_Var18;
      iVar5 = *(int *)ctx[1].sid_ctx;
      s[3].state = (int)pvVar6;
      s[3].tlsext_status_expected = iVar24;
      s[9].ex_data.dummy = uVar13;
      s[9].client_CA = psVar15;
      s[9].client_version = iVar5;
      pGVar7 = (GEN_SESSION_CB)OPENSSL_sk_dup(ctx->cert_store);
      s->generate_session_id = pGVar7;
      if (pGVar7 != (GEN_SESSION_CB)0x0) {
        iVar5 = ssl_cert_dup(ctx->verify_mode);
        s[2].error = iVar5;
        if (iVar5 != 0) {
          uVar8 = ctx->sid_ctx_length;
          pEVar14 = *(EVP_MD_CTX **)ctx->sid_ctx;
          pCVar16 = *(COMP_CTX **)(ctx->sid_ctx + 4);
          uVar1 = ctx->sid_ctx[8];
          uVar2 = ctx->sid_ctx[9];
          uVar3 = ctx->sid_ctx[10];
          uVar4 = ctx->sid_ctx[0xb];
          s[3].srtp_profile = (SRTP_PROTECTION_PROFILE *)ctx[1].info_callback;
          s[3].tlsext_hb_pending = uVar8;
          pcVar23 = ctx[1].cert;
          s->read_hash = pEVar14;
          uVar13 = ctx[1].read_ahead;
          s->expand = pCVar16;
          p_Var18 = ctx[1].msg_callback;
          s[2].next_proto_negotiated_len = uVar1;
          s[2].field_0x17d = uVar2;
          s[2].field_0x17e = uVar3;
          s[2].field_0x17f = uVar4;
          pvVar6 = *(void **)(ctx->sid_ctx + 0xc);
          s[9].options = (ulong)pcVar23;
          s[9].mode = uVar13;
          s[9].max_cert_list = (long)p_Var18;
          s[2].tlsext_debug_arg = pvVar6;
          if (pvVar6 < (void *)0x21) {
            iVar25 = *(int *)(ctx->sid_ctx + 0x14);
            iVar5 = *(int *)(ctx->sid_ctx + 0x18);
            iVar24 = *(int *)(ctx->sid_ctx + 0x1c);
            s[2].tlsext_hostname = *(char **)(ctx->sid_ctx + 0x10);
            s[2].servername_done = iVar25;
            s[2].tlsext_status_type = iVar5;
            s[2].tlsext_status_expected = iVar24;
            pXVar26 = (X509_EXTENSIONS *)ctx->generate_session_id;
            pXVar9 = ctx->param;
            iVar5 = ctx->quiet_shutdown;
            s[2].tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)ctx->default_verify_callback;
            s[2].tlsext_ocsp_exts = pXVar26;
            s[2].tlsext_ocsp_resp = (uchar *)pXVar9;
            s[2].tlsext_ocsp_resplen = iVar5;
            pEVar19 = ctx->client_cert_engine;
            s[2].srtp_profiles = (stack_st_SRTP_PROTECTION_PROFILE *)ctx->max_send_fragment;
            s[2].tlsext_ellipticcurvelist = (uchar *)pEVar19;
            pXVar9 = X509_VERIFY_PARAM_new();
            s->write_hash = (EVP_MD_CTX *)pXVar9;
            if (pXVar9 != (X509_VERIFY_PARAM *)0x0) {
              X509_VERIFY_PARAM_inherit(pXVar9,(X509_VERIFY_PARAM *)ctx->tlsext_servername_callback)
              ;
              s->server = (int)ctx->tlsext_servername_arg;
              *(undefined1 *)&s[3].ex_data.dummy = *(undefined1 *)&ctx->wbuf_freelist;
              uVar8 = *(uint *)(ctx->tlsext_tick_hmac_key + 4);
              pvVar6 = *(void **)(ctx->tlsext_tick_key_name + 0xc);
              s[3].init_num = *(int *)ctx->tlsext_tick_hmac_key;
              iVar5 = *(int *)(ctx->tlsext_tick_hmac_key + 8);
              s[3].init_msg = pvVar6;
              s[3].init_off = uVar8;
              if (1 < uVar8) {
                s[3].tlsext_hb_pending = 1;
              }
              if (iVar5 != 0) {
                SSL_set_default_read_buffer_len(s);
              }
              SSL_CTX_up_ref(ctx);
              psVar17 = (stack_st_SSL_CIPHER *)ctx->freelist_max_len;
              s[3].method = (SSL_METHOD *)ctx;
              s[3].msg_callback_arg = (void *)0x0;
              s[3].cipher_list = psVar17;
              s[3].hit = 0;
              s[3].compress = (COMP_CTX *)0x0;
              s[3].enc_read_ctx = (EVP_CIPHER_CTX *)0x0;
              s[3].read_hash = (EVP_MD_CTX *)0x0;
              s[3].expand = (COMP_CTX *)0x0;
              s[3].enc_write_ctx = (EVP_CIPHER_CTX *)0x0;
              s[3].write_hash = (EVP_MD_CTX *)0x0;
              SSL_CTX_up_ref(ctx);
              p_Var10 = ctx->next_protos_advertised_cb;
              s[3].max_send_fragment = (uint)ctx;
              if (p_Var10 != (_func_3245 *)0x0) {
                uVar8 = CRYPTO_memdup(p_Var10,ctx->rbuf_freelist,"ssl/ssl_lib.c",0x30d);
                s[3].sid_ctx_length = uVar8;
                if (uVar8 == 0) {
                  s[3].cert = (cert_st *)0x0;
                  goto LAB_000dfa0c;
                }
                s[3].cert = (cert_st *)ctx->rbuf_freelist;
              }
              if (ctx->next_proto_select_cb != (_func_3246 *)0x0) {
                iVar5 = CRYPTO_memdup(ctx->next_proto_select_cb,
                                      (int)ctx->next_protos_advertised_cb_arg << 1,"ssl/ssl_lib.c",
                                      0x319);
                *(int *)(s[3].sid_ctx + 0xc) = iVar5;
                if (iVar5 == 0) {
                  s[3].sid_ctx[8] = '\0';
                  s[3].sid_ctx[9] = '\0';
                  s[3].sid_ctx[10] = '\0';
                  s[3].sid_ctx[0xb] = '\0';
                  goto LAB_000dfa0c;
                }
                *(void **)(s[3].sid_ctx + 8) = ctx->next_protos_advertised_cb_arg;
              }
              s[3].error = 0;
              if (s[3].method[3].ssl_peek != (_func_3201 *)0x0) {
                __dest = (_func_3293 *)
                         CRYPTO_malloc((int)s[3].method[3].ssl_write,"ssl/ssl_lib.c",0x326);
                s[3].verify_callback = __dest;
                if (__dest == (_func_3293 *)0x0) {
                  s[3].info_callback = (_func_3294 *)0x0;
                  goto LAB_000dfa0c;
                }
                memcpy(__dest,s[3].method[3].ssl_peek,(size_t)s[3].method[3].ssl_write);
                s[3].info_callback = (_func_3294 *)s[3].method[3].ssl_write;
              }
              pSVar11 = (SSL_CTX *)ctx->client_cert_cb;
              pSVar20 = ctx->method;
              iVar5 = *(int *)(ctx[1].sid_ctx + 4);
              s[9].psk_server_callback = (_func_3296 *)ctx->default_passwd_callback_userdata;
              iVar24 = *(int *)(ctx[1].sid_ctx + 8);
              s[9].ctx = pSVar11;
              s->type = (int)pSVar20;
              s[9].tlsext_status_type = iVar24;
              p_Var21 = pSVar20->ssl_free;
              s[9].servername_done = iVar5;
              s[3].rbio = (BIO *)0x0;
              s[3].wbio = (BIO *)0x0;
              s[3].servername_done = -1;
              iVar5 = (*p_Var21)(s);
              if (iVar5 != 0) {
                pcVar22 = ctx->method->ssl_read + -0xdb48d;
                if (pcVar22 != (code *)0x0) {
                  pcVar22 = (code *)0x1;
                }
                s->in_handshake = (int)pcVar22;
                iVar5 = SSL_clear(s);
                if ((iVar5 != 0) &&
                   (iVar5 = CRYPTO_new_ex_data(0,s,(CRYPTO_EX_DATA *)&s[3].bbio), iVar5 != 0)) {
                  iVar5 = ctx[1].stats.sess_connect_good;
                  iVar24 = ctx[1].stats.sess_accept;
                  iVar25 = ctx[1].stats.sess_accept_renegotiate;
                  s[2].tlsext_hb_seq = ctx[1].stats.sess_connect_renegotiate;
                  s[9].debug = 0;
                  s[2].renegotiate = iVar5;
                  s[3].version = iVar24;
                  s[3].type = iVar25;
                  iVar5 = SSL_set_ct_validation_callback
                                    (s,*(undefined4 *)(ctx->tlsext_tick_key_name + 4),
                                     *(undefined4 *)(ctx->tlsext_tick_key_name + 8));
                  if (iVar5 != 0) {
                    return s;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_000dfa0c:
  SSL_free(s);
  ERR_put_error(0x14,0xba,0x41,"ssl/ssl_lib.c",0x359);
  return (SSL *)0x0;
}


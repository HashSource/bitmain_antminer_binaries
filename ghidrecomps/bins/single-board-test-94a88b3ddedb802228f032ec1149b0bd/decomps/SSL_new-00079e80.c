
SSL * SSL_new(SSL_CTX *ctx)

{
  SSL *s;
  cert_st *pcVar1;
  _func_3237 *p_Var2;
  undefined4 uVar3;
  X509_VERIFY_PARAM *to;
  BUF_MEM *__dest;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  ulong uVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  GEN_SESSION_CB pGVar11;
  SSL_METHOD *pSVar12;
  _func_3295 *p_Var13;
  undefined4 uVar14;
  
  if (ctx == (SSL_CTX *)0x0) {
    ERR_put_error(0x14,0xba,0xc3,DAT_0007a100,0x122);
    return (SSL *)0x0;
  }
  if (ctx->method == (SSL_METHOD *)0x0) {
    ERR_put_error(0x14,0xba,0xe4,DAT_0007a100,0x126);
    return (SSL *)0x0;
  }
  s = (SSL *)CRYPTO_malloc(0x1dc,DAT_0007a100,0x12a);
  if (s == (SSL *)0x0) goto LAB_0007a0aa;
  memset(s,0,0x1dc);
  pcVar1 = ctx->cert;
  uVar7 = ctx->mode;
  uVar9 = ctx->max_cert_list;
  s->references = ctx->options;
  s->options = uVar7;
  s->mode = uVar9;
  if (pcVar1 == (cert_st *)0x0) {
    s->cert = (cert_st *)0x0;
LAB_00079ede:
    p_Var2 = ctx->msg_callback;
    pvVar5 = ctx->msg_callback_arg;
    iVar8 = ctx->verify_mode;
    uVar10 = ctx->sid_ctx_length;
    s->read_ahead = ctx->read_ahead;
    s->msg_callback = (_func_3292 *)p_Var2;
    s->msg_callback_arg = pvVar5;
    s->verify_mode = iVar8;
    s->sid_ctx_length = uVar10;
    if (0x20 < uVar10) {
      OpenSSLDie(DAT_0007a100,0x150,DAT_0007a108);
    }
    uVar14 = *(undefined4 *)(ctx->sid_ctx + 4);
    uVar3 = *(undefined4 *)(ctx->sid_ctx + 8);
    uVar6 = *(undefined4 *)(ctx->sid_ctx + 0xc);
    *(undefined4 *)s->sid_ctx = *(undefined4 *)ctx->sid_ctx;
    *(undefined4 *)(s->sid_ctx + 4) = uVar14;
    *(undefined4 *)(s->sid_ctx + 8) = uVar3;
    *(undefined4 *)(s->sid_ctx + 0xc) = uVar6;
    uVar14 = *(undefined4 *)(ctx->sid_ctx + 0x14);
    uVar3 = *(undefined4 *)(ctx->sid_ctx + 0x18);
    uVar6 = *(undefined4 *)(ctx->sid_ctx + 0x1c);
    *(undefined4 *)(s->sid_ctx + 0x10) = *(undefined4 *)(ctx->sid_ctx + 0x10);
    *(undefined4 *)(s->sid_ctx + 0x14) = uVar14;
    *(undefined4 *)(s->sid_ctx + 0x18) = uVar3;
    *(undefined4 *)(s->sid_ctx + 0x1c) = uVar6;
    pGVar11 = ctx->generate_session_id;
    s->verify_callback = (_func_3293 *)ctx->default_verify_callback;
    s->generate_session_id = pGVar11;
    to = X509_VERIFY_PARAM_new();
    s->param = to;
    if (to != (X509_VERIFY_PARAM *)0x0) {
      X509_VERIFY_PARAM_inherit(to,ctx->param);
      s->quiet_shutdown = ctx->quiet_shutdown;
      s->client_version = ctx->max_send_fragment;
      CRYPTO_add_lock(&ctx->references,1,0xc,DAT_0007a100,0x160);
      s->max_send_fragment = 0;
      s->tlsext_debug_cb = (_func_3297 *)0x0;
      s->tlsext_ocsp_resplen = 0;
      s->tlsext_status_type = 0;
      s->tlsext_status_expected = 0;
      s->tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)0x0;
      s->tlsext_ocsp_exts = (X509_EXTENSIONS *)0x0;
      s->psk_server_callback = (_func_3296 *)ctx;
      s->servername_done = -1;
      s->tlsext_ocsp_resp = (uchar *)0xffffffff;
      CRYPTO_add_lock(&ctx->references,1,0xc,DAT_0007a100,0x16c);
      pvVar5 = (void *)ctx[1].stats.sess_cache_full;
      s->tls_session_secret_cb_arg = ctx;
      if (pvVar5 != (void *)0x0) {
        pvVar5 = BUF_memdup(pvVar5,ctx[1].stats.sess_timeout);
        s->tlsext_ecpointformatlist_length = (size_t)pvVar5;
        if (pvVar5 == (void *)0x0) goto LAB_0007a08a;
        s->tlsext_ticket_expected = ctx[1].stats.sess_timeout;
      }
      pvVar5 = (void *)ctx[1].stats.sess_cb_hit;
      if (pvVar5 != (void *)0x0) {
        pvVar5 = BUF_memdup(pvVar5,ctx[1].stats.sess_hit);
        s->tlsext_ellipticcurvelist_length = (size_t)pvVar5;
        if (pvVar5 == (void *)0x0) goto LAB_0007a08a;
        s->tlsext_ecpointformatlist = (uchar *)ctx[1].stats.sess_hit;
      }
      s->initial_ctx = (SSL_CTX *)0x0;
      if (*(int *)(s->psk_server_callback + 0x1c0) != 0) {
        __dest = (BUF_MEM *)
                 CRYPTO_malloc(*(int *)(s->psk_server_callback + 0x1c4),DAT_0007a100,0x188);
        s[1].init_buf = __dest;
        if (__dest == (BUF_MEM *)0x0) goto LAB_0007a08a;
        memcpy(__dest,*(void **)(s->psk_server_callback + 0x1c0),
               *(size_t *)(s->psk_server_callback + 0x1c4));
        s[1].init_msg = *(void **)(s->psk_server_callback + 0x1c4);
      }
      pSVar12 = ctx->method;
      s->debug = 0;
      s->method = pSVar12;
      iVar4 = (*pSVar12->ssl_new)(s);
      iVar8 = DAT_0007a104;
      if (iVar4 != 0) {
        pSVar12 = ctx->method;
        s->client_CA = (stack_st_X509_NAME *)0x1;
        iVar8 = (int)pSVar12->ssl_accept - iVar8;
        if (iVar8 != 0) {
          iVar8 = 1;
        }
        s->server = iVar8;
        SSL_clear(s);
        CRYPTO_new_ex_data(1,s,(CRYPTO_EX_DATA *)&s->verify_result);
        p_Var13 = (_func_3295 *)ctx->psk_server_callback;
        s->kssl_ctx = (KSSL_CTX *)ctx->psk_client_callback;
        s->psk_client_callback = p_Var13;
        return s;
      }
    }
  }
  else {
    pcVar1 = (cert_st *)ssl_cert_dup();
    s->cert = pcVar1;
    if (pcVar1 != (cert_st *)0x0) goto LAB_00079ede;
  }
LAB_0007a08a:
  iVar8 = CRYPTO_add_lock((int *)&s->client_CA,-1,0x10,DAT_0007a100,0x230);
  if (iVar8 < 1) {
    SSL_free_part_6(s);
  }
LAB_0007a0aa:
  ERR_put_error(0x14,0xba,0x41,DAT_0007a100,0x1a8);
  return (SSL *)0x0;
}


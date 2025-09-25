
SSL_CTX * SSL_set_SSL_CTX(SSL *ssl,SSL_CTX *ctx)

{
  int iVar1;
  int iVar2;
  X509_EXTENSIONS *pXVar3;
  SSL_METHOD *pSVar4;
  X509_VERIFY_PARAM *pXVar5;
  _func_3218 *__n;
  int iVar6;
  
  if ((SSL_CTX *)ssl[3].method == ctx) {
    return (SSL_CTX *)ssl[3].method;
  }
  if (ctx == (SSL_CTX *)0x0) {
    ctx = (SSL_CTX *)ssl[3].max_send_fragment;
  }
  iVar1 = ssl_cert_dup(ctx->verify_mode);
  if (iVar1 != 0) {
    iVar2 = custom_exts_copy_flags(iVar1 + 0xf0,ssl[2].error + 0xf0);
    if (iVar2 == 0) {
      ssl_cert_free(iVar1);
      return (SSL_CTX *)0x0;
    }
    ssl_cert_free(ssl[2].error);
    __n = (_func_3218 *)ssl[2].tlsext_debug_arg;
    ssl[2].error = iVar1;
    if (__n < (_func_3218 *)0x21) {
      pSVar4 = ssl[3].method;
      if (((pSVar4 != (SSL_METHOD *)0x0) && (__n == pSVar4[1].get_timeout)) &&
         (iVar1 = memcmp(&ssl[2].tlsext_hostname,&pSVar4[1].ssl3_enc,(size_t)__n), iVar1 == 0)) {
        ssl[2].tlsext_debug_arg = *(void **)(ctx->sid_ctx + 0xc);
        iVar1 = *(int *)(ctx->sid_ctx + 0x14);
        iVar2 = *(int *)(ctx->sid_ctx + 0x18);
        iVar6 = *(int *)(ctx->sid_ctx + 0x1c);
        ssl[2].tlsext_hostname = *(char **)(ctx->sid_ctx + 0x10);
        ssl[2].servername_done = iVar1;
        ssl[2].tlsext_status_type = iVar2;
        ssl[2].tlsext_status_expected = iVar6;
        pXVar3 = (X509_EXTENSIONS *)ctx->generate_session_id;
        pXVar5 = ctx->param;
        iVar1 = ctx->quiet_shutdown;
        ssl[2].tlsext_ocsp_ids = (stack_st_OCSP_RESPID *)ctx->default_verify_callback;
        ssl[2].tlsext_ocsp_exts = pXVar3;
        ssl[2].tlsext_ocsp_resp = (uchar *)pXVar5;
        ssl[2].tlsext_ocsp_resplen = iVar1;
      }
      SSL_CTX_up_ref(ctx);
      SSL_CTX_free((SSL_CTX *)ssl[3].method);
      ssl[3].method = (SSL_METHOD *)ctx;
      return ctx;
    }
  }
  return (SSL_CTX *)0x0;
}


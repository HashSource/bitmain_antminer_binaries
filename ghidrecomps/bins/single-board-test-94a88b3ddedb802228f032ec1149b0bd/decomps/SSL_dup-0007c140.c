
SSL * SSL_dup(SSL *ssl)

{
  SSL *s;
  _func_3293 *p_Var1;
  long lVar2;
  BIO *bp;
  _func_3291 *p_Var3;
  _STACK *p_Var4;
  X509_NAME *xn;
  X509_NAME *pXVar5;
  cert_st *pcVar6;
  int iVar7;
  _func_3292 *p_Var8;
  SSL_SESSION *pSVar9;
  void *pvVar10;
  size_t __n;
  SSL_METHOD *pSVar11;
  SSL_CTX *pSVar12;
  int iVar13;
  _func_3294 *p_Var14;
  ulong uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  s = SSL_new((SSL_CTX *)ssl->psk_server_callback);
  if (s == (SSL *)0x0) {
    return (SSL *)0x0;
  }
  iVar7 = ssl->type;
  pSVar11 = ssl->method;
  pSVar9 = ssl->session;
  s->version = ssl->version;
  s->type = iVar7;
  s->method = pSVar11;
  if (pSVar9 == (SSL_SESSION *)0x0) {
    (*pSVar11->ssl_free)(s);
    pSVar11 = ssl->method;
    s->method = pSVar11;
    (*pSVar11->ssl_new)(s);
    pcVar6 = ssl->cert;
    if (pcVar6 != (cert_st *)0x0) {
      if (s->cert != (cert_st *)0x0) {
        ssl_cert_free(s->cert);
        pcVar6 = ssl->cert;
      }
      pcVar6 = (cert_st *)ssl_cert_dup(pcVar6);
      s->cert = pcVar6;
      if (pcVar6 == (cert_st *)0x0) goto LAB_0007c1e6;
    }
    __n = ssl->sid_ctx_length;
    if (__n < 0x21) {
      s->sid_ctx_length = __n;
      memcpy(s->sid_ctx,ssl->sid_ctx,__n);
    }
    else {
      ERR_put_error(0x14,0xda,0x111,DAT_0007c374,0x1bf);
    }
  }
  else {
    SSL_copy_session_id(s,ssl);
  }
  uVar15 = ssl->mode;
  iVar13 = ssl->read_ahead;
  p_Var8 = ssl->msg_callback;
  pvVar10 = ssl->msg_callback_arg;
  iVar7 = ssl->references;
  s->options = ssl->options;
  p_Var1 = ssl->verify_callback;
  iVar17 = ssl->verify_mode;
  s->references = iVar7;
  s->mode = uVar15;
  s->read_ahead = iVar13;
  s->msg_callback = p_Var8;
  s->msg_callback_arg = pvVar10;
  s->verify_mode = iVar17;
  if (p_Var1 != (_func_3293 *)0x0) {
    s->verify_callback = p_Var1;
  }
  iVar7 = X509_VERIFY_PARAM_get_depth(ssl->param);
  X509_VERIFY_PARAM_set_depth(s->param,iVar7);
  p_Var14 = ssl->info_callback;
  pSVar12 = ssl->ctx;
  s->generate_session_id = ssl->generate_session_id;
  s->info_callback = p_Var14;
  s->ctx = pSVar12;
  iVar7 = CRYPTO_dup_ex_data(1,(CRYPTO_EX_DATA *)&s->verify_result,
                             (CRYPTO_EX_DATA *)&ssl->verify_result);
  if ((iVar7 != 0) &&
     ((ssl->rbio == (BIO *)0x0 || (lVar2 = BIO_ctrl(ssl->rbio,0xc,0,&s->rbio), lVar2 != 0)))) {
    bp = ssl->wbio;
    if (bp != (BIO *)0x0) {
      if (bp == ssl->rbio) {
        s->wbio = s->rbio;
      }
      else {
        lVar2 = BIO_ctrl(bp,0xc,0,&s->wbio);
        if (lVar2 == 0) goto LAB_0007c1e6;
      }
    }
    iVar13 = ssl->quiet_shutdown;
    p_Var3 = ssl->handshake_func;
    s->tlsext_hb_seq = ssl->tlsext_hb_seq;
    iVar7 = ssl->new_session;
    s->quiet_shutdown = iVar13;
    iVar18 = ssl->shutdown;
    s->new_session = iVar7;
    iVar13 = ssl->state;
    iVar7 = ssl->server;
    iVar16 = ssl->rwstate;
    iVar17 = ssl->in_handshake;
    s->shutdown = iVar18;
    s->state = iVar13;
    iVar18 = ssl->rstate;
    iVar13 = ssl->hit;
    s->handshake_func = p_Var3;
    s->server = iVar7;
    s->rwstate = iVar16;
    s->in_handshake = iVar17;
    s->rstate = iVar18;
    s->hit = iVar13;
    s->init_num = 0;
    X509_VERIFY_PARAM_inherit(s->param,ssl->param);
    if (&ssl->cipher_list->stack != (_STACK *)0x0) {
      p_Var4 = sk_dup(&ssl->cipher_list->stack);
      s->cipher_list = (stack_st_SSL_CIPHER *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_0007c1e6;
    }
    if (&ssl->cipher_list_by_id->stack != (_STACK *)0x0) {
      p_Var4 = sk_dup(&ssl->cipher_list_by_id->stack);
      s->cipher_list_by_id = (stack_st_SSL_CIPHER *)p_Var4;
      if (p_Var4 == (_STACK *)0x0) goto LAB_0007c1e6;
    }
    p_Var4 = (_STACK *)(ssl->ex_data).dummy;
    if (p_Var4 == (_STACK *)0x0) {
      return s;
    }
    p_Var4 = sk_dup(p_Var4);
    if (p_Var4 != (_STACK *)0x0) {
      (s->ex_data).dummy = (int)p_Var4;
      iVar7 = 0;
      while( true ) {
        iVar13 = sk_num(p_Var4);
        if (iVar13 <= iVar7) {
          return s;
        }
        xn = (X509_NAME *)sk_value(p_Var4,iVar7);
        pXVar5 = X509_NAME_dup(xn);
        pvVar10 = sk_set(p_Var4,iVar7,pXVar5);
        if (pvVar10 == (void *)0x0) break;
        iVar7 = iVar7 + 1;
      }
      X509_NAME_free(xn);
    }
  }
LAB_0007c1e6:
  iVar7 = CRYPTO_add_lock((int *)&s->client_CA,-1,0x10,DAT_0007c374,0x230);
  if (0 < iVar7) {
    return (SSL *)0x0;
  }
  SSL_free_part_6(s);
  return (SSL *)0x0;
}


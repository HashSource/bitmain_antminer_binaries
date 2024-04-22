
void SSL_CTX_free_part_5(SSL_CTX *param_1)

{
  void **ppvVar1;
  _STACK *p_Var2;
  void *pvVar3;
  ssl3_buf_freelist_st *psVar4;
  
  if (param_1->param != (X509_VERIFY_PARAM *)0x0) {
    X509_VERIFY_PARAM_free(param_1->param);
  }
  if (param_1->sessions != (lhash_st_SSL_SESSION *)0x0) {
    SSL_CTX_flush_sessions(param_1,0);
  }
  CRYPTO_free_ex_data(2,param_1,&param_1->ex_data);
  if ((_LHASH *)param_1->sessions != (_LHASH *)0x0) {
    lh_free((_LHASH *)param_1->sessions);
  }
  if (param_1->cert_store != (X509_STORE *)0x0) {
    X509_STORE_free(param_1->cert_store);
  }
  if (&param_1->cipher_list->stack != (_STACK *)0x0) {
    sk_free(&param_1->cipher_list->stack);
  }
  if (&param_1->cipher_list_by_id->stack != (_STACK *)0x0) {
    sk_free(&param_1->cipher_list_by_id->stack);
  }
  if (param_1->cert != (cert_st *)0x0) {
    ssl_cert_free();
  }
  if (&param_1->client_CA->stack != (_STACK *)0x0) {
    sk_pop_free(&param_1->client_CA->stack,DAT_00079af0);
  }
  if (&param_1->extra_certs->stack != (_STACK *)0x0) {
    sk_pop_free(&param_1->extra_certs->stack,DAT_00079af4);
  }
  p_Var2 = (_STACK *)param_1[1].stats.sess_connect_good;
  param_1->comp_methods = (stack_st_SSL_COMP *)0x0;
  if (p_Var2 != (_STACK *)0x0) {
    sk_free(p_Var2);
  }
  if (param_1->psk_identity_hint != (char *)0x0) {
    CRYPTO_free(param_1->psk_identity_hint);
  }
  SSL_CTX_SRP_CTX_free(param_1);
  if (param_1->client_cert_engine != (ENGINE *)0x0) {
    ENGINE_finish(param_1->client_cert_engine);
  }
  psVar4 = param_1->wbuf_freelist;
  if (psVar4 != (ssl3_buf_freelist_st *)0x0) {
    ppvVar1 = (void **)*(void **)(psVar4 + 8);
    while (ppvVar1 != (void **)0x0) {
      pvVar3 = *ppvVar1;
      CRYPTO_free(ppvVar1);
      ppvVar1 = (void **)pvVar3;
    }
    CRYPTO_free(psVar4);
  }
  psVar4 = param_1->rbuf_freelist;
  if (psVar4 != (ssl3_buf_freelist_st *)0x0) {
    ppvVar1 = (void **)*(void **)(psVar4 + 8);
    while (ppvVar1 != (void **)0x0) {
      pvVar3 = *ppvVar1;
      CRYPTO_free(ppvVar1);
      ppvVar1 = (void **)pvVar3;
    }
    CRYPTO_free(psVar4);
  }
  pvVar3 = (void *)param_1[1].stats.sess_cache_full;
  if (pvVar3 != (void *)0x0) {
    CRYPTO_free(pvVar3);
  }
  pvVar3 = (void *)param_1[1].stats.sess_cb_hit;
  if (pvVar3 != (void *)0x0) {
    CRYPTO_free(pvVar3);
  }
  pvVar3 = (void *)param_1[1].stats.sess_accept_good;
  if (pvVar3 != (void *)0x0) {
    CRYPTO_free(pvVar3);
  }
  CRYPTO_free(param_1);
  return;
}


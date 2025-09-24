
int SSL_CTX_remove_session(SSL_CTX *param_1,SSL_SESSION *c)

{
  int iVar1;
  SSL_SESSION *ses;
  stack_st_X509_NAME *psVar2;
  stack_st_void *psVar3;
  int len;
  int len_00;
  ssl_session_st *psVar4;
  _func_3231 *p_Var5;
  bool bVar6;
  
  if ((c == (SSL_SESSION *)0x0) || (*(int *)(c->krb5_client_princ + 0xb8) == 0)) {
    return 0;
  }
  CRYPTO_THREAD_write_lock(param_1[1].client_CA);
  iVar1 = OPENSSL_LH_retrieve(param_1->session_cache_size,c);
  if (iVar1 != 0) {
    ses = (SSL_SESSION *)OPENSSL_LH_delete(param_1->session_cache_size,iVar1);
    psVar4 = (ssl_session_st *)(ses->ex_data).dummy;
    if ((psVar4 != (ssl_session_st *)0x0) &&
       (psVar3 = (ses->ex_data).sk, psVar3 != (stack_st_void *)0x0)) {
      if (psVar4 == (ssl_session_st *)&param_1->session_cache_mode) {
        bVar6 = psVar3 == (stack_st_void *)&param_1->session_cache_tail;
        if (bVar6) {
          psVar4 = (ssl_session_st *)0x0;
        }
        if (!bVar6) {
          param_1->session_cache_mode = (int)psVar3;
        }
        if (bVar6) {
          param_1->session_cache_tail = psVar4;
        }
        if (bVar6) {
          param_1->session_cache_mode = (int)psVar4;
        }
        if (!bVar6) {
          psVar3[0x16].stack.comp = (_func_290 *)psVar4;
        }
      }
      else {
        bVar6 = psVar3 == (stack_st_void *)&param_1->session_cache_tail;
        if (!bVar6) {
          (psVar4->ex_data).sk = psVar3;
          psVar3 = (ses->ex_data).sk;
        }
        if (bVar6) {
          param_1->session_cache_tail = psVar4;
        }
        if (bVar6) {
          (psVar4->ex_data).sk = psVar3;
        }
        if (!bVar6) {
          psVar3[0x16].stack.comp = (_func_290 *)psVar4;
        }
      }
      (ses->ex_data).dummy = 0;
      (ses->ex_data).sk = (stack_st_void *)0x0;
    }
    psVar2 = param_1[1].client_CA;
    c->not_resumable = 1;
    CRYPTO_THREAD_unlock(psVar2);
    p_Var5 = param_1->get_session_cb;
    if (p_Var5 != (_func_3231 *)0x0) {
      (*p_Var5)((ssl_st *)param_1,(uchar *)c,len,(int *)p_Var5);
    }
    SSL_SESSION_free(ses);
    return 1;
  }
  psVar2 = param_1[1].client_CA;
  c->not_resumable = 1;
  CRYPTO_THREAD_unlock(psVar2);
  p_Var5 = param_1->get_session_cb;
  if (p_Var5 != (_func_3231 *)0x0) {
    (*p_Var5)((ssl_st *)param_1,(uchar *)c,len_00,(int *)p_Var5);
    return 0;
  }
  return 0;
}


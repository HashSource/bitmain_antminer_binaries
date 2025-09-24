
SSL_SESSION * ssl_session_dup(void *param_1,int param_2)

{
  SSL_SESSION *ses;
  int iVar1;
  X509 *pXVar2;
  char *pcVar3;
  ssl_session_st *psVar4;
  uchar *puVar5;
  ssl_session_st **ppsVar6;
  
  ses = (SSL_SESSION *)CRYPTO_malloc(0x204,"ssl/ssl_sess.c",0x6e);
  if (ses != (SSL_SESSION *)0x0) {
    memcpy(ses,param_1,0x204);
    ses->psk_identity_hint = (char *)0x0;
    ses->psk_identity = (char *)0x0;
    ses->prev = (ssl_session_st *)0x0;
    ses->next = (ssl_session_st **)0x0;
    ses->tlsext_ellipticcurvelist = (uchar *)0x0;
    ses->tlsext_tick_lifetime_hint = 0;
    ses->peer = (X509 *)0x0;
    ses->sess_cert = (sess_cert_st *)0x0;
    ses[1].ssl_version = 0;
    ses->ciphers = (stack_st_SSL_CIPHER *)0x0;
    (ses->ex_data).sk = (stack_st_void *)0x0;
    (ses->ex_data).dummy = 0;
    DataMemoryBarrier(0x1b);
    ses->references = 1;
    DataMemoryBarrier(0x1b);
    iVar1 = CRYPTO_THREAD_lock_new();
    *(int *)(ses[1].key_arg + 4) = iVar1;
    if ((iVar1 != 0) &&
       (iVar1 = CRYPTO_new_ex_data(2,ses,(CRYPTO_EX_DATA *)&ses->ciphers), iVar1 != 0)) {
      if (*(int *)((int)param_1 + 0x19c) != 0) {
        iVar1 = X509_up_ref();
        if (iVar1 == 0) goto LAB_000e573e;
        ses->sess_cert = *(sess_cert_st **)((int)param_1 + 0x19c);
      }
      if (*(int *)((int)param_1 + 0x1a0) != 0) {
        pXVar2 = (X509 *)X509_chain_up_ref();
        ses->peer = pXVar2;
        if (pXVar2 == (X509 *)0x0) goto LAB_000e573e;
      }
      if (*(char **)((int)param_1 + 400) != (char *)0x0) {
        pcVar3 = CRYPTO_strdup(*(char **)((int)param_1 + 400),"ssl/ssl_sess.c",0xa1);
        ses->psk_identity_hint = pcVar3;
        if (pcVar3 == (char *)0x0) goto LAB_000e573e;
      }
      if (*(char **)((int)param_1 + 0x194) != (char *)0x0) {
        pcVar3 = CRYPTO_strdup(*(char **)((int)param_1 + 0x194),"ssl/ssl_sess.c",0xa7);
        ses->psk_identity = pcVar3;
        if (pcVar3 == (char *)0x0) goto LAB_000e573e;
      }
      iVar1 = CRYPTO_dup_ex_data(2,(CRYPTO_EX_DATA *)&ses->ciphers,
                                 (CRYPTO_EX_DATA *)((int)param_1 + 0x1c0));
      if (iVar1 != 0) {
        if (*(char **)((int)param_1 + 0x1cc) != (char *)0x0) {
          psVar4 = (ssl_session_st *)
                   CRYPTO_strdup(*(char **)((int)param_1 + 0x1cc),"ssl/ssl_sess.c",0xb4);
          ses->prev = psVar4;
          if (psVar4 == (ssl_session_st *)0x0) goto LAB_000e573e;
        }
        if ((param_2 == 0) || (*(int *)((int)param_1 + 0x1d0) == 0)) {
          ses->tlsext_ecpointformatlist_length = 0;
          ses->tlsext_hostname = (char *)0x0;
        }
        else {
          ppsVar6 = (ssl_session_st **)
                    CRYPTO_memdup(*(int *)((int)param_1 + 0x1d0),
                                  *(undefined4 *)((int)param_1 + 0x1d4),"ssl/ssl_sess.c",0xbc);
          ses->next = ppsVar6;
          if (ppsVar6 == (ssl_session_st **)0x0) goto LAB_000e573e;
        }
        if (*(int *)((int)param_1 + 0x1e4) != 0) {
          puVar5 = (uchar *)CRYPTO_memdup(*(int *)((int)param_1 + 0x1e4),
                                          *(undefined4 *)((int)param_1 + 0x1e8),"ssl/ssl_sess.c",
                                          0xc6);
          ses->tlsext_ellipticcurvelist = puVar5;
          if (puVar5 == (uchar *)0x0) goto LAB_000e573e;
        }
        if (*(char **)((int)param_1 + 0x1f0) != (char *)0x0) {
          pcVar3 = CRYPTO_strdup(*(char **)((int)param_1 + 0x1f0),"ssl/ssl_sess.c",0xcd);
          ses->tlsext_tick_lifetime_hint = (long)pcVar3;
          if (pcVar3 == (char *)0x0) goto LAB_000e573e;
        }
        if (*(int *)((int)param_1 + 500) != 0) {
          iVar1 = CRYPTO_memdup(*(int *)((int)param_1 + 500),*(undefined4 *)((int)param_1 + 0x1f8),
                                "ssl/ssl_sess.c",0xd6);
          ses[1].ssl_version = iVar1;
          if (iVar1 == 0) goto LAB_000e573e;
        }
        return ses;
      }
    }
  }
LAB_000e573e:
  ERR_put_error(0x14,0x15c,0x41,"ssl/ssl_sess.c",0xdd);
  SSL_SESSION_free(ses);
  return (SSL_SESSION *)0x0;
}


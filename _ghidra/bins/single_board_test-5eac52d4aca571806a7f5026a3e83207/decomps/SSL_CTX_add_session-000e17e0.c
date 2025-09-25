
int SSL_CTX_add_session(SSL_CTX *s,SSL_SESSION *c)

{
  SSL_SESSION *pSVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  stack_st_void *psVar5;
  ssl_session_st *psVar6;
  int *piVar7;
  _func_3231 *p_Var8;
  uchar *data;
  ssl_session_st **ppsVar9;
  bool bVar10;
  
  SSL_SESSION_up_ref(c);
  CRYPTO_THREAD_write_lock(s[1].client_CA);
  pSVar1 = (SSL_SESSION *)OPENSSL_LH_insert(s->session_cache_size,c);
  if (pSVar1 == (SSL_SESSION *)0x0 || c == pSVar1) {
    if ((pSVar1 != (SSL_SESSION *)0x0) ||
       ((iVar4 = OPENSSL_LH_retrieve(s->session_cache_size,c), iVar4 == 0 &&
        (pSVar1 = c, c != (SSL_SESSION *)0x0)))) {
      SSL_SESSION_free(pSVar1);
      CRYPTO_THREAD_unlock(s[1].client_CA);
      return 0;
    }
  }
  else {
    psVar6 = (ssl_session_st *)(pSVar1->ex_data).dummy;
    if ((psVar6 != (ssl_session_st *)0x0) &&
       (psVar5 = (pSVar1->ex_data).sk, psVar5 != (stack_st_void *)0x0)) {
      ppsVar9 = &s->session_cache_tail;
      if (psVar6 == (ssl_session_st *)&s->session_cache_mode) {
        bVar10 = psVar5 == (stack_st_void *)ppsVar9;
        if (bVar10) {
          psVar6 = (ssl_session_st *)0x0;
        }
        if (!bVar10) {
          s->session_cache_mode = (int)psVar5;
        }
        if (bVar10) {
          s->session_cache_tail = psVar6;
        }
        if (bVar10) {
          s->session_cache_mode = (int)psVar6;
        }
        if (!bVar10) {
          psVar5[0x16].stack.comp = (_func_290 *)psVar6;
        }
      }
      else {
        bVar10 = psVar5 == (stack_st_void *)ppsVar9;
        if (!bVar10) {
          (psVar6->ex_data).sk = psVar5;
          psVar5 = (pSVar1->ex_data).sk;
        }
        if (bVar10) {
          s->session_cache_tail = psVar6;
        }
        if (bVar10) {
          (psVar6->ex_data).sk = (stack_st_void *)ppsVar9;
        }
        if (!bVar10) {
          psVar5[0x16].stack.comp = (_func_290 *)psVar6;
        }
      }
      (pSVar1->ex_data).dummy = 0;
      (pSVar1->ex_data).sk = (stack_st_void *)0x0;
    }
    SSL_SESSION_free(pSVar1);
  }
  ppsVar9 = &s->session_cache_tail;
  psVar6 = (ssl_session_st *)(c->ex_data).dummy;
  if ((psVar6 != (ssl_session_st *)0x0) &&
     (psVar5 = (c->ex_data).sk, psVar5 != (stack_st_void *)0x0)) {
    if (psVar6 == (ssl_session_st *)&s->session_cache_mode) {
      bVar10 = psVar5 == (stack_st_void *)ppsVar9;
      if (bVar10) {
        psVar6 = (ssl_session_st *)0x0;
      }
      if (!bVar10) {
        s->session_cache_mode = (int)psVar5;
      }
      if (bVar10) {
        s->session_cache_tail = psVar6;
      }
      if (bVar10) {
        s->session_cache_mode = (int)psVar6;
      }
      if (!bVar10) {
        psVar5[0x16].stack.comp = (_func_290 *)psVar6;
      }
    }
    else {
      bVar10 = psVar5 == (stack_st_void *)ppsVar9;
      if (!bVar10) {
        (psVar6->ex_data).sk = psVar5;
        psVar5 = (c->ex_data).sk;
      }
      if (bVar10) {
        s->session_cache_tail = psVar6;
      }
      if (bVar10) {
        (psVar6->ex_data).sk = (stack_st_void *)ppsVar9;
      }
      if (!bVar10) {
        psVar5[0x16].stack.comp = (_func_290 *)psVar6;
      }
    }
    (c->ex_data).dummy = 0;
    (c->ex_data).sk = (stack_st_void *)0x0;
  }
  psVar6 = s->session_cache_tail;
  if (psVar6 == (ssl_session_st *)0x0) {
    s->session_cache_tail = c;
    s->session_cache_mode = (int)c;
    (c->ex_data).sk = (stack_st_void *)ppsVar9;
    (c->ex_data).dummy = (int)&s->session_cache_mode;
  }
  else {
    (c->ex_data).dummy = (int)psVar6;
    (psVar6->ex_data).sk = (stack_st_void *)c;
    (c->ex_data).sk = (stack_st_void *)ppsVar9;
    s->session_cache_tail = c;
  }
  lVar2 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
  if (0 < lVar2) {
    while( true ) {
      lVar2 = SSL_CTX_ctrl(s,0x14,0,(void *)0x0);
      lVar3 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
      if (((lVar2 <= lVar3) || (data = (uchar *)s->session_cache_mode, data == (uchar *)0x0)) ||
         (*(int *)(data + 0x148) == 0)) goto LAB_000e197e;
      iVar4 = OPENSSL_LH_retrieve(s->session_cache_size,data);
      if (iVar4 == 0) break;
      pSVar1 = (SSL_SESSION *)OPENSSL_LH_delete(s->session_cache_size,iVar4);
      psVar6 = (ssl_session_st *)(pSVar1->ex_data).dummy;
      if ((psVar6 != (ssl_session_st *)0x0) &&
         (psVar5 = (pSVar1->ex_data).sk, psVar5 != (stack_st_void *)0x0)) {
        if (psVar6 == (ssl_session_st *)&s->session_cache_mode) {
          bVar10 = psVar5 == (stack_st_void *)ppsVar9;
          if (!bVar10) {
            s->session_cache_mode = (int)psVar5;
          }
          if (bVar10) {
            s->session_cache_tail = (ssl_session_st *)0x0;
          }
          if (bVar10) {
            s->session_cache_mode = 0;
          }
          if (!bVar10) {
            psVar5[0x16].stack.comp = (_func_290 *)psVar6;
          }
        }
        else {
          bVar10 = psVar5 == (stack_st_void *)ppsVar9;
          if (!bVar10) {
            (psVar6->ex_data).sk = psVar5;
            psVar5 = (pSVar1->ex_data).sk;
          }
          if (bVar10) {
            s->session_cache_tail = psVar6;
          }
          if (bVar10) {
            (psVar6->ex_data).sk = (stack_st_void *)ppsVar9;
          }
          if (!bVar10) {
            psVar5[0x16].stack.comp = (_func_290 *)psVar6;
          }
        }
        (pSVar1->ex_data).dummy = 0;
        (pSVar1->ex_data).sk = (stack_st_void *)0x0;
      }
      p_Var8 = s->get_session_cb;
      data[0x198] = '\x01';
      data[0x199] = '\0';
      data[0x19a] = '\0';
      data[0x19b] = '\0';
      if (p_Var8 != (_func_3231 *)0x0) {
        (*p_Var8)((ssl_st *)s,data,1,(int *)p_Var8);
      }
      SSL_SESSION_free(pSVar1);
      piVar7 = &(s->stats).sess_hit;
      do {
        ExclusiveAccess(piVar7);
        bVar10 = (bool)hasExclusiveAccess(piVar7);
      } while (!bVar10);
      *piVar7 = *piVar7 + 1;
    }
    p_Var8 = s->get_session_cb;
    data[0x198] = '\x01';
    data[0x199] = '\0';
    data[0x19a] = '\0';
    data[0x19b] = '\0';
    if (p_Var8 != (_func_3231 *)0x0) {
      (*p_Var8)((ssl_st *)s,data,1,(int *)p_Var8);
    }
  }
LAB_000e197e:
  CRYPTO_THREAD_unlock(s[1].client_CA);
  return 1;
}


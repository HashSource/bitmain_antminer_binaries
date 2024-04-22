
int SSL_CTX_add_session(SSL_CTX *s,SSL_SESSION *c)

{
  SSL_SESSION *pSVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ssl_session_st *psVar5;
  ssl_session_st *psVar6;
  ssl_session_st *psVar7;
  _func_3230 *p_Var8;
  int iVar9;
  ssl_session_st **ppsVar10;
  bool bVar11;
  
  CRYPTO_add_lock((int *)(c->krb5_client_princ + 0x14),1,0xe,DAT_0007f160,0x2ef);
  CRYPTO_lock(9,0xc,DAT_0007f160,0x2f4);
  pSVar1 = (SSL_SESSION *)lh_insert((_LHASH *)s->sessions,c);
  if (pSVar1 == c || pSVar1 == (SSL_SESSION *)0x0) {
    iVar9 = 0;
    if (pSVar1 != (SSL_SESSION *)0x0) {
      iVar2 = CRYPTO_add_lock((int *)(pSVar1->krb5_client_princ + 0x14),-1,0xe,DAT_0007f160,0x352);
      if (iVar2 < 1) {
        SSL_SESSION_free_part_0(pSVar1);
      }
      goto LAB_0007ef70;
    }
  }
  else {
    psVar7 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x3c);
    if ((psVar7 != (ssl_session_st *)0x0) &&
       (psVar5 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x38),
       psVar5 != (ssl_session_st *)0x0)) {
      ppsVar10 = &s->session_cache_head;
      if (psVar7 == (ssl_session_st *)&s->session_cache_tail) {
        bVar11 = psVar5 == (ssl_session_st *)ppsVar10;
        if (bVar11) {
          psVar7 = (ssl_session_st *)0x0;
        }
        if (!bVar11) {
          s->session_cache_tail = psVar5;
        }
        if (bVar11) {
          s->session_cache_head = psVar7;
        }
        if (bVar11) {
          s->session_cache_tail = psVar7;
        }
        if (!bVar11) {
          *(ssl_session_st **)(psVar5->krb5_client_princ + 0x3c) = psVar7;
        }
      }
      else {
        bVar11 = psVar5 == (ssl_session_st *)ppsVar10;
        if (!bVar11) {
          *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38) = psVar5;
          psVar5 = *(ssl_session_st **)(pSVar1->krb5_client_princ + 0x38);
        }
        if (bVar11) {
          s->session_cache_head = psVar7;
        }
        if (bVar11) {
          *(ssl_session_st ***)(psVar7->krb5_client_princ + 0x38) = ppsVar10;
        }
        if (!bVar11) {
          *(ssl_session_st **)(psVar5->krb5_client_princ + 0x3c) = psVar7;
        }
      }
      *(undefined4 *)(pSVar1->krb5_client_princ + 0x3c) = 0;
      *(undefined4 *)(pSVar1->krb5_client_princ + 0x38) = 0;
    }
    iVar9 = CRYPTO_add_lock((int *)(pSVar1->krb5_client_princ + 0x14),-1,0xe,DAT_0007f160,0x352);
    if (iVar9 < 1) {
      SSL_SESSION_free_part_0(pSVar1);
    }
  }
  ppsVar10 = &s->session_cache_head;
  psVar7 = *(ssl_session_st **)(c->krb5_client_princ + 0x3c);
  if ((psVar7 != (ssl_session_st *)0x0) &&
     (psVar5 = *(ssl_session_st **)(c->krb5_client_princ + 0x38), psVar5 != (ssl_session_st *)0x0))
  {
    if (psVar7 == (ssl_session_st *)&s->session_cache_tail) {
      bVar11 = psVar5 == (ssl_session_st *)ppsVar10;
      if (bVar11) {
        psVar7 = (ssl_session_st *)0x0;
      }
      if (!bVar11) {
        s->session_cache_tail = psVar5;
      }
      if (bVar11) {
        s->session_cache_head = psVar7;
      }
      if (bVar11) {
        s->session_cache_tail = psVar7;
      }
      if (!bVar11) {
        *(ssl_session_st **)(psVar5->krb5_client_princ + 0x3c) = psVar7;
      }
    }
    else {
      bVar11 = psVar5 == (ssl_session_st *)ppsVar10;
      if (!bVar11) {
        *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38) = psVar5;
        psVar5 = *(ssl_session_st **)(c->krb5_client_princ + 0x38);
      }
      if (bVar11) {
        s->session_cache_head = psVar7;
      }
      if (bVar11) {
        *(ssl_session_st ***)(psVar7->krb5_client_princ + 0x38) = ppsVar10;
      }
      if (!bVar11) {
        *(ssl_session_st **)(psVar5->krb5_client_princ + 0x3c) = psVar7;
      }
    }
    *(undefined4 *)(c->krb5_client_princ + 0x3c) = 0;
    *(undefined4 *)(c->krb5_client_princ + 0x38) = 0;
  }
  psVar7 = s->session_cache_head;
  if (psVar7 == (ssl_session_st *)0x0) {
    s->session_cache_head = c;
    s->session_cache_tail = c;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar10;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x3c) = &s->session_cache_tail;
  }
  else {
    *(SSL_SESSION **)(psVar7->krb5_client_princ + 0x38) = c;
    *(ssl_session_st **)(c->krb5_client_princ + 0x3c) = psVar7;
    *(ssl_session_st ***)(c->krb5_client_princ + 0x38) = ppsVar10;
    s->session_cache_head = c;
  }
  lVar3 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
  if (0 < lVar3) {
    while( true ) {
      lVar3 = SSL_CTX_ctrl(s,0x14,0,(void *)0x0);
      lVar4 = SSL_CTX_ctrl(s,0x2b,0,(void *)0x0);
      if ((((lVar3 <= lVar4) || (psVar7 = s->session_cache_tail, psVar7 == (ssl_session_st *)0x0))
          || (psVar7->session_id_length == 0)) ||
         (psVar5 = (ssl_session_st *)lh_retrieve((_LHASH *)s->sessions,psVar7), psVar7 != psVar5))
      break;
      pSVar1 = (SSL_SESSION *)lh_delete((_LHASH *)s->sessions,psVar7);
      psVar5 = *(ssl_session_st **)(psVar7->krb5_client_princ + 0x3c);
      if ((psVar5 != (ssl_session_st *)0x0) &&
         (psVar6 = *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38),
         psVar6 != (ssl_session_st *)0x0)) {
        if (psVar5 == (ssl_session_st *)&s->session_cache_tail) {
          bVar11 = psVar6 == (ssl_session_st *)ppsVar10;
          if (!bVar11) {
            s->session_cache_tail = psVar6;
          }
          if (bVar11) {
            s->session_cache_head = (ssl_session_st *)0x0;
          }
          if (bVar11) {
            s->session_cache_tail = (ssl_session_st *)0x0;
          }
          if (!bVar11) {
            *(ssl_session_st ***)(psVar6->krb5_client_princ + 0x3c) = &s->session_cache_tail;
          }
        }
        else {
          bVar11 = psVar6 == (ssl_session_st *)ppsVar10;
          if (!bVar11) {
            *(ssl_session_st **)(psVar5->krb5_client_princ + 0x38) = psVar6;
            psVar6 = *(ssl_session_st **)(psVar7->krb5_client_princ + 0x38);
          }
          if (bVar11) {
            s->session_cache_head = psVar5;
          }
          if (bVar11) {
            *(ssl_session_st ***)(psVar5->krb5_client_princ + 0x38) = ppsVar10;
          }
          if (!bVar11) {
            *(ssl_session_st **)(psVar6->krb5_client_princ + 0x3c) = psVar5;
          }
        }
        *(undefined4 *)(psVar7->krb5_client_princ + 0x3c) = 0;
        *(undefined4 *)(psVar7->krb5_client_princ + 0x38) = 0;
      }
      p_Var8 = s->remove_session_cb;
      *(undefined4 *)(pSVar1->krb5_client_princ + 4) = 1;
      if (p_Var8 != (_func_3230 *)0x0) {
        (*p_Var8)(s,pSVar1);
      }
      iVar9 = CRYPTO_add_lock((int *)(pSVar1->krb5_client_princ + 0x14),-1,0xe,DAT_0007f160,0x352);
      if (iVar9 < 1) {
        SSL_SESSION_free_part_0(pSVar1);
      }
      (s->stats).sess_cache_full = (s->stats).sess_cache_full + 1;
    }
  }
  iVar9 = 1;
LAB_0007ef70:
  CRYPTO_lock(10,0xc,DAT_0007f160,0x326);
  return iVar9;
}


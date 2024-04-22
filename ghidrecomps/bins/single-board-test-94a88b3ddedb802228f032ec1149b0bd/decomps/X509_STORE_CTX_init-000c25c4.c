
int X509_STORE_CTX_init(X509_STORE_CTX *ctx,X509_STORE *store,X509 *x509,stack_st_X509 *chain)

{
  char *name;
  _func_2005 *p_Var1;
  _func_2000 *p_Var2;
  X509_VERIFY_PARAM *pXVar3;
  int iVar4;
  _func_2008 *p_Var5;
  _func_2007 *p_Var6;
  _func_1999 *p_Var7;
  _func_1998 *p_Var8;
  _func_1997 *p_Var9;
  _func_2001 *p_Var10;
  _func_2003 *p_Var11;
  _func_2004 *p_Var12;
  _func_2006 *p_Var13;
  X509_VERIFY_PARAM *pXVar14;
  
  ctx->untrusted = chain;
  ctx->cert = x509;
  ctx->ctx = store;
  ctx->current_method = 0;
  ctx->crls = (stack_st_X509_CRL *)0x0;
  ctx->last_untrusted = 0;
  ctx->other_ctx = (void *)0x0;
  ctx->valid = 0;
  ctx->chain = (stack_st_X509 *)0x0;
  ctx->error = 0;
  ctx->explicit_policy = 0;
  ctx->error_depth = 0;
  ctx->current_cert = (X509 *)0x0;
  ctx->current_issuer = (X509 *)0x0;
  ctx->current_crl = (X509_CRL *)0x0;
  ctx->current_crl_score = 0;
  ctx->current_reasons = 0;
  ctx->tree = (X509_POLICY_TREE *)0x0;
  ctx->parent = (X509_STORE_CTX *)0x0;
  pXVar3 = X509_VERIFY_PARAM_new();
  iVar4 = 0x8e7;
  ctx->param = pXVar3;
  name = DAT_000c2714;
  if (pXVar3 == (X509_VERIFY_PARAM *)0x0) goto LAB_000c261a;
  if (store == (X509_STORE *)0x0) {
    pXVar3->inh_flags = pXVar3->inh_flags | 0x11;
    ctx->cleanup = (_func_2008 *)0x0;
    pXVar14 = X509_VERIFY_PARAM_lookup(name);
    iVar4 = X509_VERIFY_PARAM_inherit(pXVar3,pXVar14);
    p_Var7 = DAT_000c273c;
    p_Var2 = DAT_000c2738;
    p_Var13 = DAT_000c272c;
    p_Var12 = DAT_000c2728;
    p_Var11 = DAT_000c2724;
    p_Var10 = DAT_000c2720;
    p_Var9 = DAT_000c271c;
    p_Var8 = DAT_000c2718;
    if (iVar4 != 0) {
      ctx->get_crl = (_func_2002 *)0x0;
      ctx->check_issued = p_Var2;
      ctx->get_issuer = p_Var7;
      ctx->verify_cb = p_Var8;
      ctx->verify = p_Var9;
      ctx->check_revocation = p_Var10;
      ctx->check_crl = p_Var11;
      ctx->cert_crl = p_Var12;
      ctx->lookup_certs = p_Var13;
LAB_000c2674:
      p_Var6 = DAT_000c2730;
LAB_000c2676:
      p_Var1 = DAT_000c2734;
      ctx->lookup_crls = p_Var6;
      ctx->check_policy = p_Var1;
      iVar4 = CRYPTO_new_ex_data(5,ctx,&ctx->ex_data);
      if (iVar4 != 0) {
        return 1;
      }
      CRYPTO_free(ctx);
      iVar4 = 0x940;
      goto LAB_000c261a;
    }
  }
  else {
    iVar4 = X509_VERIFY_PARAM_inherit(pXVar3,store->param);
    p_Var5 = (_func_2008 *)store->cleanup;
    ctx->verify_cb = (_func_1998 *)store->verify_cb;
    ctx->cleanup = p_Var5;
    if (iVar4 != 0) {
      pXVar14 = ctx->param;
      pXVar3 = X509_VERIFY_PARAM_lookup(DAT_000c2714);
      iVar4 = X509_VERIFY_PARAM_inherit(pXVar14,pXVar3);
      if (iVar4 != 0) {
        if (store->check_issued == (_func_1988 *)0x0) {
          ctx->check_issued = DAT_000c2738;
        }
        else {
          ctx->check_issued = (_func_2000 *)store->check_issued;
        }
        p_Var7 = (_func_1999 *)store->get_issuer;
        if (store->get_issuer == (_func_1987 *)0x0) {
          p_Var7 = DAT_000c273c;
        }
        ctx->get_issuer = p_Var7;
        p_Var8 = (_func_1998 *)store->verify_cb;
        if (store->verify_cb == (_func_1986 *)0x0) {
          p_Var8 = DAT_000c2718;
        }
        ctx->verify_cb = p_Var8;
        p_Var9 = (_func_1997 *)store->verify;
        if (store->verify == (_func_1985 *)0x0) {
          p_Var9 = DAT_000c271c;
        }
        ctx->verify = p_Var9;
        p_Var10 = (_func_2001 *)store->check_revocation;
        if (store->check_revocation == (_func_1989 *)0x0) {
          p_Var10 = DAT_000c2720;
        }
        ctx->check_revocation = p_Var10;
        p_Var11 = (_func_2003 *)store->check_crl;
        ctx->get_crl = (_func_2002 *)store->get_crl;
        if (p_Var11 == (_func_2003 *)0x0) {
          p_Var11 = DAT_000c2724;
        }
        ctx->check_crl = p_Var11;
        p_Var12 = (_func_2004 *)store->cert_crl;
        if (store->cert_crl == (_func_1992 *)0x0) {
          p_Var12 = DAT_000c2728;
        }
        ctx->cert_crl = p_Var12;
        p_Var13 = (_func_2006 *)store->lookup_certs;
        if (store->lookup_certs == (_func_1993 *)0x0) {
          p_Var13 = DAT_000c272c;
        }
        ctx->lookup_certs = p_Var13;
        p_Var6 = (_func_2007 *)store->lookup_crls;
        if (store->lookup_crls == (_func_1994 *)0x0) goto LAB_000c2674;
        goto LAB_000c2676;
      }
    }
  }
  iVar4 = 0x8ff;
LAB_000c261a:
  ERR_put_error(0xb,0x8f,0x41,DAT_000c2710,iVar4);
  return 0;
}


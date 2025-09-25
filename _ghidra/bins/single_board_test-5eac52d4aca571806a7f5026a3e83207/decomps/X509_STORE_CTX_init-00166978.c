
int X509_STORE_CTX_init(X509_STORE_CTX *ctx,X509_STORE *store,X509 *x509,stack_st_X509 *chain)

{
  X509_VERIFY_PARAM *to;
  int iVar1;
  X509_VERIFY_PARAM *from;
  X509_PURPOSE *xp;
  _func_2004 *p_Var2;
  _func_1988 *p_Var3;
  _func_1986 *p_Var4;
  _func_1985 *p_Var5;
  code *pcVar6;
  _func_2002 *p_Var7;
  _func_1992 *p_Var8;
  stack_st_X509_CRL *psVar9;
  
  ctx->ctx = store;
  ctx->current_method = (int)x509;
  ctx->cert = (X509 *)chain;
  ctx->untrusted = (stack_st_X509 *)0x0;
  ctx->valid = 0;
  ctx->param = (X509_VERIFY_PARAM *)0x0;
  ctx->cleanup = (_func_2008 *)0x0;
  ctx->last_untrusted = 0;
  ctx->error_depth = 0;
  ctx->tree = (X509_POLICY_TREE *)0x0;
  ctx->explicit_policy = 0;
  ctx->error = 0;
  ctx->current_cert = (X509 *)0x0;
  ctx->current_issuer = (X509 *)0x0;
  ctx->current_crl = (X509_CRL *)0x0;
  ctx->current_crl_score = 0;
  ctx->chain = (stack_st_X509 *)0x0;
  ctx->current_reasons = 0;
  (ctx->ex_data).sk = (stack_st_void *)0x0;
  (ctx->ex_data).dummy = 0;
  ctx->parent = (X509_STORE_CTX *)0x0;
  if (store == (X509_STORE *)0x0) {
    ctx->lookup_crls = (_func_2007 *)0x0;
    ctx->get_issuer = (_func_1999 *)0x1642c9;
    ctx->verify_cb = (_func_1998 *)0x1633a9;
    ctx->verify = (_func_1997 *)0x16413d;
    ctx->other_ctx = (void *)0x164bd9;
    ctx->check_revocation = (_func_2001 *)0x0;
    ctx->check_issued = (_func_2000 *)0x16530d;
    ctx->get_crl = (_func_2002 *)0x166c91;
    ctx->check_crl = (_func_2003 *)0x1644ed;
    ctx->cert_crl = (_func_2004 *)0x164551;
    ctx->check_policy = (_func_2005 *)0x162ff9;
LAB_00166ad6:
    pcVar6 = (code *)0x163105;
  }
  else {
    p_Var3 = store->check_issued;
    ctx->lookup_crls = (_func_2007 *)(store->ex_data).sk;
    if (p_Var3 == (_func_1988 *)0x0) {
      ctx->get_issuer = (_func_1999 *)0x1642c9;
    }
    else {
      ctx->get_issuer = (_func_1999 *)p_Var3;
    }
    if (store->get_issuer == (_func_1987 *)0x0) {
      ctx->verify_cb = (_func_1998 *)0x1633a9;
      p_Var4 = store->verify_cb;
      if (p_Var4 != (_func_1986 *)0x0) goto LAB_001669dc;
LAB_00166b0c:
      ctx->verify = (_func_1997 *)0x16413d;
      p_Var5 = store->verify;
      if (p_Var5 != (_func_1985 *)0x0) goto LAB_001669e6;
LAB_00166b1a:
      ctx->other_ctx = (void *)0x164bd9;
      pcVar6 = store->check_revocation;
    }
    else {
      ctx->verify_cb = (_func_1998 *)store->get_issuer;
      p_Var4 = store->verify_cb;
      if (p_Var4 == (_func_1986 *)0x0) goto LAB_00166b0c;
LAB_001669dc:
      ctx->verify = (_func_1997 *)p_Var4;
      p_Var5 = store->verify;
      if (p_Var5 == (_func_1985 *)0x0) goto LAB_00166b1a;
LAB_001669e6:
      ctx->other_ctx = p_Var5;
      pcVar6 = store->check_revocation;
    }
    if (pcVar6 == (_func_2000 *)0x0) {
      pcVar6 = (code *)0x16530d;
    }
    ctx->check_issued = pcVar6;
    p_Var7 = (_func_2002 *)store->check_crl;
    ctx->check_revocation = (_func_2001 *)store->get_crl;
    if (p_Var7 == (_func_2002 *)0x0) {
      ctx->get_crl = (_func_2002 *)0x166c91;
      p_Var8 = store->cert_crl;
      if (p_Var8 != (_func_1992 *)0x0) goto LAB_00166a08;
LAB_00166b58:
      p_Var2 = (_func_2004 *)store->lookup_certs;
      ctx->check_crl = (_func_2003 *)0x1644ed;
      if (p_Var2 != (_func_2004 *)0x0) goto LAB_00166a12;
      ctx->cert_crl = (_func_2004 *)0x164551;
LAB_00166b34:
      pcVar6 = store->lookup_crls;
    }
    else {
      ctx->get_crl = p_Var7;
      p_Var8 = store->cert_crl;
      if (p_Var8 == (_func_1992 *)0x0) goto LAB_00166b58;
LAB_00166a08:
      p_Var2 = (_func_2004 *)store->lookup_certs;
      ctx->check_crl = (_func_2003 *)p_Var8;
      if (p_Var2 == (_func_2004 *)0x0) {
        ctx->cert_crl = (_func_2004 *)0x164551;
        goto LAB_00166b34;
      }
LAB_00166a12:
      pcVar6 = store->lookup_crls;
      ctx->cert_crl = p_Var2;
    }
    if (pcVar6 == (_func_1994 *)0x0) {
      pcVar6 = (code *)0x162ff9;
    }
    ctx->check_policy = pcVar6;
    pcVar6 = store->cleanup;
    if (pcVar6 == (_func_2006 *)0x0) goto LAB_00166ad6;
  }
  ctx->lookup_certs = pcVar6;
  to = X509_VERIFY_PARAM_new();
  ctx->crls = (stack_st_X509_CRL *)to;
  if (to == (X509_VERIFY_PARAM *)0x0) {
    iVar1 = 0x938;
    goto LAB_00166a4a;
  }
  if (store == (X509_STORE *)0x0) {
    to->inh_flags = to->inh_flags | 0x11;
LAB_00166a6a:
    from = X509_VERIFY_PARAM_lookup("default");
    iVar1 = X509_VERIFY_PARAM_inherit(to,from);
    if (iVar1 != 0) {
      if (ctx->crls[1].stack.num == 0) {
        iVar1 = X509_PURPOSE_get_by_id((int)(ctx->crls->stack).comp);
        xp = X509_PURPOSE_get0(iVar1);
        if (xp != (X509_PURPOSE *)0x0) {
          psVar9 = ctx->crls;
          iVar1 = X509_PURPOSE_get_trust(xp);
          psVar9[1].stack.num = iVar1;
        }
      }
      iVar1 = CRYPTO_new_ex_data(5,ctx,(CRYPTO_EX_DATA *)&ctx->parent);
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = 0x95c;
      goto LAB_00166a4a;
    }
  }
  else {
    iVar1 = X509_VERIFY_PARAM_inherit(to,store->param);
    if (iVar1 != 0) {
      to = (X509_VERIFY_PARAM *)ctx->crls;
      goto LAB_00166a6a;
    }
  }
  iVar1 = 0x949;
LAB_00166a4a:
  ERR_put_error(0xb,0x8f,0x41,"crypto/x509/x509_vfy.c",iVar1);
  X509_STORE_CTX_cleanup(ctx);
  return 0;
}


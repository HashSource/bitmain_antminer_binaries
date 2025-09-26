
int X509_STORE_CTX_init(X509_STORE_CTX *ctx,X509_STORE *store,X509 *x509,stack_st_X509 *chain)

{
  X509_VERIFY_PARAM *pXVar1;
  int iVar2;
  _func_2008 *p_Var3;
  code *pcVar4;
  X509_VERIFY_PARAM *pXVar5;
  
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
  pXVar1 = X509_VERIFY_PARAM_new();
  iVar2 = 0x8e7;
  ctx->param = pXVar1;
  if (pXVar1 == (X509_VERIFY_PARAM *)0x0) goto LAB_00160e5a;
  if (store == (X509_STORE *)0x0) {
    pXVar1->inh_flags = pXVar1->inh_flags | 0x11;
    ctx->cleanup = (_func_2008 *)0x0;
    pXVar5 = X509_VERIFY_PARAM_lookup("default");
    iVar2 = X509_VERIFY_PARAM_inherit(pXVar1,pXVar5);
    if (iVar2 != 0) {
      ctx->get_crl = (_func_2002 *)0x0;
      ctx->check_issued = (_func_2000 *)0x15f3e1;
      ctx->get_issuer = (_func_1999 *)0x16233d;
      ctx->verify_cb = (_func_1998 *)0x15f2d9;
      ctx->verify = (_func_1997 *)0x15f769;
      ctx->check_revocation = (_func_2001 *)0x15fe11;
      ctx->check_crl = (_func_2003 *)0x160f81;
      ctx->cert_crl = (_func_2004 *)0x15f4c1;
      ctx->lookup_certs = (_func_2006 *)0x161e81;
LAB_00160eb4:
      pcVar4 = (code *)0x161fad;
LAB_00160eb6:
      ctx->lookup_crls = pcVar4;
      ctx->check_policy = (_func_2005 *)0x15f415;
      iVar2 = CRYPTO_new_ex_data(5,ctx,&ctx->ex_data);
      if (iVar2 != 0) {
        return 1;
      }
      CRYPTO_free(ctx);
      iVar2 = 0x940;
      goto LAB_00160e5a;
    }
  }
  else {
    iVar2 = X509_VERIFY_PARAM_inherit(pXVar1,store->param);
    p_Var3 = (_func_2008 *)store->cleanup;
    ctx->verify_cb = (_func_1998 *)store->verify_cb;
    ctx->cleanup = p_Var3;
    if (iVar2 != 0) {
      pXVar5 = ctx->param;
      pXVar1 = X509_VERIFY_PARAM_lookup("default");
      iVar2 = X509_VERIFY_PARAM_inherit(pXVar5,pXVar1);
      if (iVar2 != 0) {
        if (store->check_issued == (_func_1988 *)0x0) {
          ctx->check_issued = (_func_2000 *)0x15f3e1;
        }
        else {
          ctx->check_issued = (_func_2000 *)store->check_issued;
        }
        pcVar4 = store->get_issuer;
        if (pcVar4 == (_func_1999 *)0x0) {
          pcVar4 = (code *)0x16233d;
        }
        ctx->get_issuer = pcVar4;
        pcVar4 = store->verify_cb;
        if (pcVar4 == (_func_1998 *)0x0) {
          pcVar4 = (code *)0x15f2d9;
        }
        ctx->verify_cb = pcVar4;
        pcVar4 = store->verify;
        if (pcVar4 == (_func_1997 *)0x0) {
          pcVar4 = (code *)0x15f769;
        }
        ctx->verify = pcVar4;
        pcVar4 = store->check_revocation;
        if (pcVar4 == (_func_2001 *)0x0) {
          pcVar4 = (code *)0x15fe11;
        }
        ctx->check_revocation = pcVar4;
        pcVar4 = store->check_crl;
        ctx->get_crl = (_func_2002 *)store->get_crl;
        if (pcVar4 == (_func_2003 *)0x0) {
          pcVar4 = (code *)0x160f81;
        }
        ctx->check_crl = pcVar4;
        pcVar4 = store->cert_crl;
        if (pcVar4 == (_func_2004 *)0x0) {
          pcVar4 = (code *)0x15f4c1;
        }
        ctx->cert_crl = pcVar4;
        pcVar4 = store->lookup_certs;
        if (pcVar4 == (_func_2006 *)0x0) {
          pcVar4 = (code *)0x161e81;
        }
        ctx->lookup_certs = pcVar4;
        pcVar4 = store->lookup_crls;
        if (pcVar4 == (_func_2007 *)0x0) goto LAB_00160eb4;
        goto LAB_00160eb6;
      }
    }
  }
  iVar2 = 0x8ff;
LAB_00160e5a:
  ERR_put_error(0xb,0x8f,0x41,"x509_vfy.c",iVar2);
  return 0;
}



void X509_STORE_CTX_cleanup(X509_STORE_CTX *ctx)

{
  X509_NAME *in_r1;
  
  if (ctx->lookup_crls != (_func_2007 *)0x0) {
    (*ctx->lookup_crls)(ctx,in_r1);
    ctx->lookup_crls = (_func_2007 *)0x0;
  }
  if ((X509_VERIFY_PARAM *)ctx->crls != (X509_VERIFY_PARAM *)0x0) {
    if (ctx->current_reasons == 0) {
      X509_VERIFY_PARAM_free((X509_VERIFY_PARAM *)ctx->crls);
    }
    ctx->crls = (stack_st_X509_CRL *)0x0;
  }
  X509_policy_tree_free((X509_POLICY_TREE *)ctx->chain);
  ctx->chain = (stack_st_X509 *)0x0;
  OPENSSL_sk_pop_free(ctx->last_untrusted,0x16a341);
  ctx->last_untrusted = 0;
  CRYPTO_free_ex_data(5,ctx,(CRYPTO_EX_DATA *)&ctx->parent);
  ctx->parent = (X509_STORE_CTX *)0x0;
  return;
}


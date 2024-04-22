
int EVP_MD_CTX_cleanup(EVP_MD_CTX *ctx)

{
  int iVar1;
  EVP_MD *pEVar2;
  
  pEVar2 = ctx->digest;
  if (pEVar2 != (EVP_MD *)0x0) {
    if (pEVar2->cleanup != (_func_1224 *)0x0) {
      iVar1 = EVP_MD_CTX_test_flags(ctx,2);
      if (iVar1 == 0) {
        (*ctx->digest->cleanup)(ctx);
      }
      pEVar2 = ctx->digest;
      if (pEVar2 == (EVP_MD *)0x0) goto LAB_000ae86c;
    }
    if (((pEVar2->ctx_size != 0) && (ctx->md_data != (void *)0x0)) &&
       (iVar1 = EVP_MD_CTX_test_flags(ctx,4), iVar1 == 0)) {
      OPENSSL_cleanse(ctx->md_data,ctx->digest->ctx_size);
      CRYPTO_free(ctx->md_data);
    }
  }
LAB_000ae86c:
  if (ctx->pctx != (EVP_PKEY_CTX *)0x0) {
    EVP_PKEY_CTX_free(ctx->pctx);
  }
  if (ctx->engine != (ENGINE *)0x0) {
    ENGINE_finish(ctx->engine);
  }
  memset(ctx,0,0x18);
  return 1;
}


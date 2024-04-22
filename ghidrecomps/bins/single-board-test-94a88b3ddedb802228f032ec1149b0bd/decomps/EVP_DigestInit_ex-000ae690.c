
/* WARNING: Type propagation algorithm not settling */

int EVP_DigestInit_ex(EVP_MD_CTX *ctx,EVP_MD *type,ENGINE *impl)

{
  char *file;
  int iVar1;
  void *pvVar2;
  EVP_MD *pEVar3;
  
  EVP_MD_CTX_clear_flags(ctx,2);
  if (ctx->engine == (ENGINE *)0x0) {
    if (type == (EVP_MD *)0x0) {
      if (ctx->digest == (EVP_MD *)0x0) goto LAB_000ae73c;
      goto LAB_000ae6f8;
    }
  }
  else {
    if (ctx->digest == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_000ae73c:
        ERR_put_error(6,0x80,0x8b,DAT_000ae7cc,0xd0);
        return 0;
      }
    }
    else if ((type == (EVP_MD *)0x0) || (type->type == ctx->digest->type)) goto LAB_000ae6f8;
    ENGINE_finish(ctx->engine);
  }
  if (impl == (ENGINE *)0x0) {
    impl = ENGINE_get_digest_engine(type->type);
    if (impl != (ENGINE *)0x0) goto LAB_000ae6cc;
  }
  else {
    iVar1 = ENGINE_init(impl);
    if (iVar1 == 0) {
      ERR_put_error(6,0x80,0x86,DAT_000ae7cc,0xb6);
      return 0;
    }
LAB_000ae6cc:
    type = ENGINE_get_digest(impl,type->type);
    if (type == (EVP_MD *)0x0) {
      ERR_put_error(6,0x80,0x86,DAT_000ae7cc,0xc1);
      ENGINE_finish(impl);
      return 0;
    }
  }
  pEVar3 = ctx->digest;
  ctx->engine = impl;
  if (pEVar3 != type) {
    if ((pEVar3 != (EVP_MD *)0x0) && (pEVar3->ctx_size != 0)) {
      CRYPTO_free(ctx->md_data);
    }
    ctx->digest = type;
    file = DAT_000ae7cc;
    if ((-1 < (int)(ctx->flags << 0x17)) && (iVar1 = type->ctx_size, iVar1 != 0)) {
      ctx->update = (_func_1230 *)type->update;
      pvVar2 = CRYPTO_malloc(iVar1,file,0xdc);
      ctx->md_data = pvVar2;
      if (pvVar2 == (void *)0x0) {
        ERR_put_error(6,0x80,0x41,DAT_000ae7cc,0xde);
        return 0;
      }
    }
  }
LAB_000ae6f8:
  if ((ctx->pctx != (EVP_PKEY_CTX *)0x0) &&
     (iVar1 = EVP_PKEY_CTX_ctrl(ctx->pctx,-1,0xf8,7,0,ctx), iVar1 != -2 && iVar1 < 1)) {
    return 0;
  }
  if ((int)(ctx->flags << 0x17) < 0) {
    return 1;
  }
  iVar1 = (*ctx->digest->init)(ctx);
  return iVar1;
}


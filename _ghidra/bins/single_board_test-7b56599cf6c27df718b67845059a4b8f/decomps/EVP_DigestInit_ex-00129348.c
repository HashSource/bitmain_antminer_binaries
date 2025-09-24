
int EVP_DigestInit_ex(EVP_MD_CTX *ctx,EVP_MD *type,ENGINE *impl)

{
  int iVar1;
  _func_1226 *p_Var2;
  EVP_PKEY_CTX *ctx_00;
  void *pvVar3;
  EVP_MD *pEVar4;
  
  EVP_MD_CTX_clear_flags(ctx,2);
  if (ctx->engine == (ENGINE *)0x0) {
    if (type != (EVP_MD *)0x0) goto LAB_00129372;
    if (ctx->digest == (EVP_MD *)0x0) goto LAB_0012948c;
LAB_00129426:
    ctx_00 = ctx->pctx;
    if (ctx_00 != (EVP_PKEY_CTX *)0x0) goto LAB_001293ec;
  }
  else {
    if (ctx->digest == (EVP_MD *)0x0) {
      if (type == (EVP_MD *)0x0) {
LAB_0012948c:
        ERR_put_error(6,0x80,0x8b,"crypto/evp/digest.c",0x7f);
        return 0;
      }
    }
    else if ((type == (EVP_MD *)0x0) || (type->type == ctx->digest->type)) goto LAB_00129426;
LAB_00129372:
    ENGINE_finish(ctx->engine);
    if (impl == (ENGINE *)0x0) {
      impl = ENGINE_get_digest_engine(type->type);
      if (impl != (ENGINE *)0x0) goto LAB_00129388;
    }
    else {
      iVar1 = ENGINE_init(impl);
      if (iVar1 == 0) {
        ERR_put_error(6,0x80,0x86,"crypto/evp/digest.c",100);
        return 0;
      }
LAB_00129388:
      type = ENGINE_get_digest(impl,type->type);
      if (type == (EVP_MD *)0x0) {
        ERR_put_error(6,0x80,0x86,"crypto/evp/digest.c",0x70);
        ENGINE_finish(impl);
        return 0;
      }
    }
    pEVar4 = ctx->digest;
    ctx->engine = impl;
    if (type == pEVar4) goto LAB_00129426;
    if (pEVar4 != (EVP_MD *)0x0) {
      if ((pEVar4->cleanup != (_func_1224 *)0x0) &&
         (iVar1 = EVP_MD_CTX_test_flags(ctx,2), iVar1 == 0)) {
        (*ctx->digest->cleanup)(ctx);
      }
      if ((ctx->md_data != (void *)0x0) && (0 < (int)ctx->digest->verify)) {
        EVP_MD_CTX_test_flags(ctx,4);
        CRYPTO_clear_free(ctx->md_data,ctx->digest->verify,"crypto/evp/digest.c",0x1c);
        ctx->md_data = (void *)0x0;
      }
    }
    ctx->digest = type;
    if ((int)(ctx->flags << 0x17) < 0) {
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) {
        return 1;
      }
    }
    else {
      p_Var2 = type->verify;
      if (p_Var2 != (_func_1226 *)0x0) {
        ctx->update = (_func_1230 *)type->update;
        pvVar3 = (void *)CRYPTO_zalloc(p_Var2,"crypto/evp/digest.c",0x8b);
        ctx->md_data = pvVar3;
        if (pvVar3 == (void *)0x0) {
          ERR_put_error(6,0x80,0x41,"crypto/evp/digest.c",0x8d);
          return 0;
        }
        goto LAB_00129426;
      }
      ctx_00 = ctx->pctx;
      if (ctx_00 == (EVP_PKEY_CTX *)0x0) goto LAB_00129430;
    }
LAB_001293ec:
    iVar1 = EVP_PKEY_CTX_ctrl(ctx_00,-1,0xf8,7,0,ctx);
    if (iVar1 != -2 && iVar1 < 1) {
      return 0;
    }
  }
  if ((int)(ctx->flags << 0x17) < 0) {
    return 1;
  }
  type = ctx->digest;
LAB_00129430:
                    /* WARNING: Could not recover jumptable at 0x0012943a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*type->init)(ctx);
  return iVar1;
}


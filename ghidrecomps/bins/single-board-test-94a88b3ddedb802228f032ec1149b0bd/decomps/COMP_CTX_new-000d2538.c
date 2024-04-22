
COMP_CTX * COMP_CTX_new(COMP_METHOD *meth)

{
  COMP_CTX *ctx;
  int iVar1;
  _func_711 *p_Var2;
  
  ctx = (COMP_CTX *)CRYPTO_malloc(0x1c,DAT_000d2570,0xb);
  if (ctx != (COMP_CTX *)0x0) {
    memset(ctx,0,0x1c);
    p_Var2 = meth->init;
    ctx->meth = meth;
    if ((p_Var2 != (_func_711 *)0x0) && (iVar1 = (*p_Var2)(ctx), iVar1 == 0)) {
      CRYPTO_free(ctx);
      return (COMP_CTX *)0x0;
    }
  }
  return ctx;
}


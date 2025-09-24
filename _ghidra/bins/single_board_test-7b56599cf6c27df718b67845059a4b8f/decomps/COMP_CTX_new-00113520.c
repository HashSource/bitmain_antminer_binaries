
COMP_CTX * COMP_CTX_new(COMP_METHOD *meth)

{
  COMP_CTX *ctx;
  int iVar1;
  _func_711 *p_Var2;
  
  ctx = (COMP_CTX *)CRYPTO_zalloc(0x18,"crypto/comp/comp_lib.c",0x16);
  if (ctx == (COMP_CTX *)0x0) {
    ERR_put_error(0x29,0x67,0x41,"crypto/comp/comp_lib.c",0x17);
  }
  else {
    p_Var2 = meth->init;
    ctx->meth = meth;
    if ((p_Var2 != (_func_711 *)0x0) && (iVar1 = (*p_Var2)(ctx), iVar1 == 0)) {
      CRYPTO_free(ctx);
      ctx = (COMP_CTX *)0x0;
    }
  }
  return ctx;
}


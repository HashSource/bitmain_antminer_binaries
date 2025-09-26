
int X509_LOOKUP_init(X509_LOOKUP *ctx)

{
  int iVar1;
  _func_1978 *p_Var2;
  
  if (ctx->method == (X509_LOOKUP_METHOD *)0x0) {
    return 0;
  }
  p_Var2 = ctx->method->init;
  if (p_Var2 != (_func_1978 *)0x0) {
    iVar1 = (*p_Var2)(ctx);
    return iVar1;
  }
  return 1;
}


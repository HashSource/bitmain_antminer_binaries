
int X509_LOOKUP_shutdown(X509_LOOKUP *ctx)

{
  int iVar1;
  _func_1979 *p_Var2;
  
  if (ctx->method == (X509_LOOKUP_METHOD *)0x0) {
    return 0;
  }
  p_Var2 = ctx->method->shutdown;
  if (p_Var2 != (_func_1979 *)0x0) {
    iVar1 = (*p_Var2)(ctx);
    return iVar1;
  }
  return 1;
}


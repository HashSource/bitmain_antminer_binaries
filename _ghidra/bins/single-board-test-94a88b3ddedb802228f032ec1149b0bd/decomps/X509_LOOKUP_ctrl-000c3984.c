
int X509_LOOKUP_ctrl(X509_LOOKUP *ctx,int cmd,char *argc,long argl,char **ret)

{
  int iVar1;
  _func_1980 *p_Var2;
  
  if (ctx->method == (X509_LOOKUP_METHOD *)0x0) {
    iVar1 = -1;
  }
  else {
    p_Var2 = ctx->method->ctrl;
    if (p_Var2 == (_func_1980 *)0x0) {
      iVar1 = 1;
    }
    else {
      iVar1 = (*p_Var2)(ctx,cmd,argc,argl,ret);
    }
  }
  return iVar1;
}


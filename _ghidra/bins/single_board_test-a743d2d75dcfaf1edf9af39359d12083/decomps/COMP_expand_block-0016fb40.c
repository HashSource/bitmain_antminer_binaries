
int COMP_expand_block(COMP_CTX *ctx,uchar *out,int olen,uchar *in,int ilen)

{
  int iVar1;
  _func_714 *p_Var2;
  
  p_Var2 = ctx->meth->expand;
  if (p_Var2 == (_func_714 *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (*p_Var2)(ctx,out,olen,in,ilen);
    if (0 < iVar1) {
      ctx->expand_in = ctx->expand_in + ilen;
      ctx->expand_out = ctx->expand_out + iVar1;
    }
  }
  return iVar1;
}


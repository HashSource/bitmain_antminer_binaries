
int COMP_compress_block(COMP_CTX *ctx,uchar *out,int olen,uchar *in,int ilen)

{
  int iVar1;
  _func_713 *p_Var2;
  
  p_Var2 = ctx->meth->compress;
  if (p_Var2 == (_func_713 *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (*p_Var2)(ctx,out,olen,in,ilen);
    if (0 < iVar1) {
      ctx->compress_in = ctx->compress_in + ilen;
      ctx->compress_out = ctx->compress_out + iVar1;
    }
  }
  return iVar1;
}


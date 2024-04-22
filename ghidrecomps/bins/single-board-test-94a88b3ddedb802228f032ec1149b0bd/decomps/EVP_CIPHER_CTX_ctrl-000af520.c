
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX *ctx,int type,int arg,void *ptr)

{
  int iVar1;
  _func_1236 *p_Var2;
  
  if (ctx->cipher == (EVP_CIPHER *)0x0) {
    ERR_put_error(6,0x7c,0x83,DAT_000af578,0x262);
    iVar1 = 0;
  }
  else {
    p_Var2 = ctx->cipher->ctrl;
    if (p_Var2 == (_func_1236 *)0x0) {
      ERR_put_error(6,0x7c,0x84,DAT_000af578,0x267);
      iVar1 = 0;
    }
    else {
      iVar1 = (*p_Var2)(ctx,type,arg,ptr);
      if (iVar1 == -1) {
        ERR_put_error(6,0x7c,0x85,DAT_000af578,0x26e);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


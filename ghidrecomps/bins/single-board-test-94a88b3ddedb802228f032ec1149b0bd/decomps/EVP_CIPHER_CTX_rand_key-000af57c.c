
int EVP_CIPHER_CTX_rand_key(EVP_CIPHER_CTX *ctx,uchar *key)

{
  int iVar1;
  _func_1236 *p_Var2;
  
  if ((int)(ctx->cipher->flags << 0x16) < 0) {
    p_Var2 = ctx->cipher->ctrl;
    if (p_Var2 == (_func_1236 *)0x0) {
      ERR_put_error(6,0x7c,0x84,DAT_000af5dc,0x267);
      iVar1 = 0;
    }
    else {
      iVar1 = (*p_Var2)(ctx,6,0,key);
      if (iVar1 == -1) {
        ERR_put_error(6,0x7c,0x85,DAT_000af5dc,0x26e);
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = RAND_bytes(key,ctx->key_len);
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}


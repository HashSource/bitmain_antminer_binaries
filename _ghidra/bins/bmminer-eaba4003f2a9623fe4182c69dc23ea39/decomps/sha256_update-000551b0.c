
void sha256_update(sha256_ctx *ctx,uchar *message,uint len)

{
  uint uVar1;
  uint __n;
  uint __n_00;
  uint len_local;
  uchar *message_local;
  sha256_ctx *ctx_local;
  uchar *shifted_message;
  uint block_nb;
  uint new_len;
  uint rem_len;
  uint tmp_len;
  
  uVar1 = 0x40 - ctx->len;
  __n = len;
  if (uVar1 < len) {
    __n = uVar1;
  }
  memcpy(ctx->block + ctx->len,message,__n);
  if (ctx->len + len < 0x40) {
    ctx->len = ctx->len + len;
  }
  else {
    uVar1 = len - __n >> 6;
    sha256_transf(ctx,ctx->block,1);
    sha256_transf(ctx,message + __n,uVar1);
    __n_00 = len - __n & 0x3f;
    memcpy(ctx->block,message + __n + uVar1 * 0x40,__n_00);
    ctx->len = __n_00;
    ctx->tot_len = ctx->tot_len + (uVar1 + 1) * 0x40;
  }
  return;
}


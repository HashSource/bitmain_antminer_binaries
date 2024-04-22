
void sha256_update(sha256_ctx *ctx,uchar *message,uint len)

{
  size_t __n;
  uint uVar1;
  uint len_local;
  uchar *message_local;
  sha256_ctx *ctx_local;
  uchar *shifted_message;
  uint block_nb;
  uint new_len;
  uint rem_len;
  uint tmp_len;
  
  __n = 0x40 - ctx->len;
  if (len <= __n) {
    __n = len;
  }
  memcpy(ctx->block + ctx->len,message,__n);
  if (ctx->len + len < 0x40) {
    ctx->len = ctx->len + len;
  }
  else {
    uVar1 = len - __n;
    sha256_transf(ctx,ctx->block,1);
    sha256_transf(ctx,message + __n,uVar1 >> 6);
    memcpy(ctx->block,message + __n + (uVar1 & 0xffffffc0),uVar1 & 0x3f);
    ctx->len = uVar1 & 0x3f;
    ctx->tot_len = ctx->tot_len + ((uVar1 >> 6) + 1) * 0x40;
  }
  return;
}


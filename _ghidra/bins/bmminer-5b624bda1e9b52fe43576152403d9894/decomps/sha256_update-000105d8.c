
/* WARNING: Unknown calling convention */

void sha256_update(sha256_ctx *ctx,uchar *message,uint len)

{
  uint uVar1;
  uchar *shifted_message;
  uint __n;
  uint block_nb;
  
  __n = 0x40 - ctx->len;
  if (len < __n) {
    __n = len;
  }
  memcpy(ctx->block + ctx->len,message,__n);
  uVar1 = len + ctx->len;
  if (uVar1 < 0x40) {
    ctx->len = uVar1;
    return;
  }
  block_nb = len - __n >> 6;
  sha256_transf(ctx,ctx->block,1);
  uVar1 = len - __n & 0x3f;
  sha256_transf(ctx,message + __n,block_nb);
  memcpy(ctx->block,message + __n + block_nb * 0x40,uVar1);
  ctx->len = uVar1;
  ctx->tot_len = ctx->tot_len + (block_nb + 1) * 0x40;
  return;
}


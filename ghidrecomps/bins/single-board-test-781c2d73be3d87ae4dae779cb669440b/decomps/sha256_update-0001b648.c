
/* WARNING: Unknown calling convention */

void sha256_update(sha256_ctx *ctx,uchar *message,uint len)

{
  uint uVar1;
  uchar *shifted_message;
  uint rem_len;
  uint new_len;
  uint block_nb;
  
  rem_len = 0x40 - ctx->len;
  if (len <= rem_len) {
    rem_len = len;
  }
  memcpy(ctx->block + ctx->len,message,rem_len);
  uVar1 = ctx->len + len;
  if (uVar1 < 0x40) {
    ctx->len = uVar1;
    return;
  }
  uVar1 = len - rem_len;
  sha256_transf(ctx,ctx->block,1);
  sha256_transf(ctx,message + rem_len,uVar1 >> 6);
  memcpy(ctx->block,message + rem_len + (uVar1 & 0xffffffc0),uVar1 & 0x3f);
  ctx->len = uVar1 & 0x3f;
  ctx->tot_len = ctx->tot_len + ((uVar1 >> 6) + 1) * 0x40;
  return;
}



void sha256_final(sha256_ctx *ctx,uchar *digest)

{
  int iVar1;
  int iVar2;
  uint block_nb_00;
  uchar *digest_local;
  sha256_ctx *ctx_local;
  uint pm_len;
  uint len_b;
  uint block_nb;
  int i;
  
  if ((ctx->len & 0x3f) < 0x38) {
    block_nb_00 = 1;
  }
  else {
    block_nb_00 = 2;
  }
  iVar1 = (ctx->tot_len + ctx->len) * 8;
  iVar2 = block_nb_00 * 0x40;
  memset(ctx->block + ctx->len,0,iVar2 - ctx->len);
  ctx->block[ctx->len] = 0x80;
  ctx->block[iVar2 + -1] = (uchar)iVar1;
  ctx->block[iVar2 + -2] = (uchar)((uint)iVar1 >> 8);
  ctx->block[iVar2 + -3] = (uchar)((uint)iVar1 >> 0x10);
  ctx->block[iVar2 + -4] = (uchar)((uint)iVar1 >> 0x18);
  sha256_transf(ctx,ctx->block,block_nb_00);
  for (i = 0; i < 8; i = i + 1) {
    digest[i * 4 + 3] = (uchar)ctx->h[i];
    digest[i * 4 + 2] = (uchar)(ctx->h[i] >> 8);
    digest[i * 4 + 1] = (uchar)(ctx->h[i] >> 0x10);
    digest[i * 4] = (uchar)(ctx->h[i] >> 0x18);
  }
  return;
}



void sha256_init(sha256_ctx *ctx)

{
  sha256_ctx *ctx_local;
  int i;
  
  for (i = 0; i < 8; i = i + 1) {
    ctx->h[i] = sha256_h0[i];
  }
  ctx->len = 0;
  ctx->tot_len = 0;
  return;
}


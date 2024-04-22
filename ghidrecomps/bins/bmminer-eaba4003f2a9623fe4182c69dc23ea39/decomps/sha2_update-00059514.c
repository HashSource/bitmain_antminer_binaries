
void sha2_update(sha2_context *ctx,uchar *input,int ilen)

{
  size_t __n;
  int ilen_local;
  uchar *input_local;
  sha2_context *ctx_local;
  int fill;
  uint left;
  
  if (0 < ilen) {
    left = ctx->total[0] & 0x3f;
    __n = 0x40 - left;
    ctx->total[0] = ctx->total[0] + ilen;
    ctx->total[0] = ctx->total[0];
    if (ctx->total[0] < (uint)ilen) {
      ctx->total[1] = ctx->total[1] + 1;
    }
    ilen_local = ilen;
    input_local = input;
    if ((left != 0) && ((int)__n <= ilen)) {
      memcpy(ctx->buffer + left,input,__n);
      sha2_process(ctx,ctx->buffer);
      input_local = input + __n;
      ilen_local = ilen - __n;
      left = 0;
    }
    for (; 0x3f < ilen_local; ilen_local = ilen_local + -0x40) {
      sha2_process(ctx,input_local);
      input_local = input_local + 0x40;
    }
    if (0 < ilen_local) {
      memcpy(ctx->buffer + left,input_local,ilen_local);
    }
  }
  return;
}


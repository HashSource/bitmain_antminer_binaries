
void LZ4_resetStream_fast(LZ4_stream_t *ctx)

{
  LZ4_stream_t *ctx_local;
  
  if (((ctx->internal_donotuse).tableType != 0) &&
     (((ctx->internal_donotuse).tableType != 2 ||
      (0x40000000 < (ctx->internal_donotuse).currentOffset)))) {
    memset(ctx,0,0x4000);
    (ctx->internal_donotuse).currentOffset = 0;
    (ctx->internal_donotuse).tableType = 0;
  }
  if ((ctx->internal_donotuse).currentOffset != 0) {
    (ctx->internal_donotuse).currentOffset = (ctx->internal_donotuse).currentOffset + 0x10000;
  }
  (ctx->internal_donotuse).dictCtx = (LZ4_stream_t_internal *)0x0;
  (ctx->internal_donotuse).dictionary = (LZ4_byte *)0x0;
  (ctx->internal_donotuse).dictSize = 0;
  return;
}


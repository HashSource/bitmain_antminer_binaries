
void EVP_DecodeInit(EVP_ENCODE_CTX *ctx)

{
  ctx->length = 0x1e;
  ctx->num = 0;
  ctx->line_num = 0;
  ctx->expect_nl = 0;
  return;
}


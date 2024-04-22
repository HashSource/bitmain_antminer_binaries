
int SSL_CTX_set_session_id_context(SSL_CTX *ctx,uchar *sid_ctx,uint sid_ctx_len)

{
  if (0x20 < sid_ctx_len) {
    ERR_put_error(0x14,0xdb,0x111,DAT_0007a13c,0x1b1);
  }
  else {
    ctx->sid_ctx_length = sid_ctx_len;
    memcpy(ctx->sid_ctx,sid_ctx,sid_ctx_len);
  }
  return (uint)(0x20 >= sid_ctx_len);
}


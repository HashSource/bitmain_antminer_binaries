
int SSL_CTX_set_session_id_context(SSL_CTX *ctx,uchar *sid_ctx,uint sid_ctx_len)

{
  if (sid_ctx_len < 0x21) {
    *(uint *)(ctx->sid_ctx + 0xc) = sid_ctx_len;
    memcpy(ctx->sid_ctx + 0x10,sid_ctx,sid_ctx_len);
    return 1;
  }
  ERR_put_error(0x14,0xdb,0x111,"ssl/ssl_lib.c",0x373);
  return 0;
}


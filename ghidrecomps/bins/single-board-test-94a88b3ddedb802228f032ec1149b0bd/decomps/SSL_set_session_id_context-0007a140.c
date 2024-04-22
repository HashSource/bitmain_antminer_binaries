
int SSL_set_session_id_context(SSL *ssl,uchar *sid_ctx,uint sid_ctx_len)

{
  if (0x20 < sid_ctx_len) {
    ERR_put_error(0x14,0xda,0x111,DAT_0007a170,0x1bf);
  }
  else {
    ssl->sid_ctx_length = sid_ctx_len;
    memcpy(ssl->sid_ctx,sid_ctx,sid_ctx_len);
  }
  return (uint)(0x20 >= sid_ctx_len);
}


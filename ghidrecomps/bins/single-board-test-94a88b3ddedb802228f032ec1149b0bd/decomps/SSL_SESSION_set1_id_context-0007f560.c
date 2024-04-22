
int SSL_SESSION_set1_id_context(SSL_SESSION *s,uchar *sid_ctx,uint sid_ctx_len)

{
  if (0x20 < sid_ctx_len) {
    ERR_put_error(0x14,0x138,0x111,DAT_0007f590,0x3e3);
  }
  else {
    s->sid_ctx_length = sid_ctx_len;
    memcpy(s->sid_ctx,sid_ctx,sid_ctx_len);
  }
  return (uint)(0x20 >= sid_ctx_len);
}



int SSL_set_session_id_context(SSL *ssl,uchar *sid_ctx,uint sid_ctx_len)

{
  if (sid_ctx_len < 0x21) {
    ssl[2].tlsext_debug_arg = (void *)sid_ctx_len;
    memcpy(&ssl[2].tlsext_hostname,sid_ctx,sid_ctx_len);
    return 1;
  }
  ERR_put_error(0x14,0xda,0x111,"ssl/ssl_lib.c",0x381);
  return 0;
}


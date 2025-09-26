
int SSL_SESSION_set1_id_context(SSL_SESSION *s,uchar *sid_ctx,uint sid_ctx_len)

{
  if (sid_ctx_len < 0x21) {
    *(uint *)(s->krb5_client_princ + 0xdc) = sid_ctx_len;
    if (s->krb5_client_princ + 0xe0 != sid_ctx) {
      memcpy(s->krb5_client_princ + 0xe0,sid_ctx,sid_ctx_len);
    }
    return 1;
  }
  ERR_put_error(0x14,0x138,0x111,"ssl/ssl_sess.c",0x3c0);
  return 0;
}


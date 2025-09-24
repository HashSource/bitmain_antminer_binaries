
void SSL_set_accept_state(SSL *s)

{
  s->in_handshake = 1;
  s->new_session = 0;
  ossl_statem_clear();
  s->rwstate = *(int *)(s->type + 0x18);
  ssl_clear_cipher_ctx(s);
  ssl_clear_hash_ctx(s[2].sid_ctx + 0x10);
  ssl_clear_hash_ctx(&s[2].info_callback);
  return;
}


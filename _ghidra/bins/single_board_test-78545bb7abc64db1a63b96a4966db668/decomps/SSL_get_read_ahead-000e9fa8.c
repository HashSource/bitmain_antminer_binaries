
int SSL_get_read_ahead(SSL *s)

{
  return s[3].tlsext_hb_pending;
}


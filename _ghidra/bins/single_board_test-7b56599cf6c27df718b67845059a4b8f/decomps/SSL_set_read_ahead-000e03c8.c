
void SSL_set_read_ahead(SSL *s,int yes)

{
  s[3].tlsext_hb_pending = yes;
  return;
}


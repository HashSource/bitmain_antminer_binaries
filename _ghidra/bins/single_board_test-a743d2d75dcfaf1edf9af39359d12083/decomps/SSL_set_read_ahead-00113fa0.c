
void SSL_set_read_ahead(SSL *s,int yes)

{
  s->read_ahead = yes;
  return;
}


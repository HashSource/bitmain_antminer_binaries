
int SSL_renegotiate(SSL *s)

{
  int iVar1;
  
  if (s->tlsext_hb_seq == 0) {
    s->tlsext_hb_seq = 1;
  }
  s->new_session = 1;
  iVar1 = (*s->method->ssl_renegotiate)(s);
  return iVar1;
}


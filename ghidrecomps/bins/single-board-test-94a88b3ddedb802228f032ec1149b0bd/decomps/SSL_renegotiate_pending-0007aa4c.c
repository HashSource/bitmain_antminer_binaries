
int SSL_renegotiate_pending(SSL *s)

{
  uint uVar1;
  
  uVar1 = s->tlsext_hb_seq;
  if (uVar1 != 0) {
    uVar1 = 1;
  }
  return uVar1;
}


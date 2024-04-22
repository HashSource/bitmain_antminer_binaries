
int SSL_do_handshake(SSL *s)

{
  int iVar1;
  
  if (s->handshake_func == (_func_3291 *)0x0) {
    ERR_put_error(0x14,0xb4,0x90,DAT_0007bf40,0xac9);
    iVar1 = -1;
  }
  else {
    (*s->method->ssl_renegotiate_check)(s);
    if ((s->state & 0x7000U) == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = (*s->handshake_func)(s);
    }
  }
  return iVar1;
}


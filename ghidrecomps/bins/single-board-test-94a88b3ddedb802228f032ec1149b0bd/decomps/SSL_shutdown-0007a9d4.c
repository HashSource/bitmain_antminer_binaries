
int SSL_shutdown(SSL *s)

{
  int iVar1;
  
  if (s->handshake_func == (_func_3291 *)0x0) {
    ERR_put_error(0x14,0xe0,0x114,DAT_0007aa10,0x423);
    iVar1 = -1;
  }
  else if ((s->state & 0x3000U) == 0) {
    iVar1 = (*s->method->ssl_shutdown)(s);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}


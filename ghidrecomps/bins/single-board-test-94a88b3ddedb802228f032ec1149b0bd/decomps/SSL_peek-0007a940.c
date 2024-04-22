
int SSL_peek(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3291 *)0x0) {
    ERR_put_error(0x14,0x10e,0x114,DAT_0007a97c,0x400);
    iVar1 = -1;
  }
  else if ((ssl->shutdown & 2U) == 0) {
    iVar1 = (*ssl->method->ssl_peek)(ssl,buf,num);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


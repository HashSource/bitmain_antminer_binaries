
int SSL_write(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3291 *)0x0) {
    ERR_put_error(0x14,0xd0,0x114,DAT_0007a9d0,0x40d);
    iVar1 = -1;
  }
  else if ((ssl->shutdown & 1U) == 0) {
    iVar1 = (*ssl->method->ssl_write)(ssl,buf,num);
  }
  else {
    ssl->rwstate = 1;
    ERR_put_error(0x14,0xd0,0xcf,DAT_0007a9d0,0x413);
    iVar1 = -1;
  }
  return iVar1;
}


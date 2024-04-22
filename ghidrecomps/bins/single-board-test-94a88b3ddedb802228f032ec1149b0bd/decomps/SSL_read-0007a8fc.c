
int SSL_read(SSL *ssl,void *buf,int num)

{
  int iVar1;
  
  if (ssl->handshake_func == (_func_3291 *)0x0) {
    ERR_put_error(0x14,0xdf,0x114,DAT_0007a93c,0x3f2);
    iVar1 = -1;
  }
  else if ((ssl->shutdown & 2U) == 0) {
    iVar1 = (*ssl->method->ssl_read)(ssl,buf,num);
  }
  else {
    iVar1 = 0;
    ssl->rwstate = 1;
  }
  return iVar1;
}


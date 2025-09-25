
int SSL_set_fd(SSL *s,int fd)

{
  BIO_METHOD *type;
  BIO *bp;
  
  type = BIO_s_socket();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_int_ctrl(bp,0x68,0,fd);
    SSL_set_bio(s,bp,bp);
    return 1;
  }
  ERR_put_error(0x14,0xc0,7,"ssl/ssl_lib.c",0x54f);
  return 0;
}


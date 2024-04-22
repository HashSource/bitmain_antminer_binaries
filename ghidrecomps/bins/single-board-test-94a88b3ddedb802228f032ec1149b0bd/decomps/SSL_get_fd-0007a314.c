
int SSL_get_fd(SSL *s)

{
  BIO *bp;
  int local_c [3];
  
  local_c[0] = -1;
  bp = BIO_find_type(s->rbio,0x100);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x69,0,local_c);
  }
  return local_c[0];
}


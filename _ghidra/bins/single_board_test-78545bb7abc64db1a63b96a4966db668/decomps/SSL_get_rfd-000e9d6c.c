
int SSL_get_rfd(SSL *s)

{
  BIO *pBVar1;
  int local_c [2];
  
  local_c[0] = -1;
  pBVar1 = SSL_get_rbio(s);
  pBVar1 = BIO_find_type(pBVar1,0x100);
  if (pBVar1 != (BIO *)0x0) {
    BIO_ctrl(pBVar1,0x69,0,local_c);
  }
  return local_c[0];
}


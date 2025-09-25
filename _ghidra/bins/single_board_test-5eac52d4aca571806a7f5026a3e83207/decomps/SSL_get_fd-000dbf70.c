
int SSL_get_fd(SSL *s)

{
  BIO *pBVar1;
  int aiStack_c [2];
  
  aiStack_c[0] = -1;
  pBVar1 = SSL_get_rbio(s);
  pBVar1 = BIO_find_type(pBVar1,0x100);
  if (pBVar1 != (BIO *)0x0) {
    BIO_ctrl(pBVar1,0x69,0,aiStack_c);
  }
  return aiStack_c[0];
}


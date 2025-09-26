
BIO * SSL_get_wbio(SSL *s)

{
  BIO *pBVar1;
  
  if (s->wbio != (BIO *)0x0) {
    pBVar1 = BIO_next(s->wbio);
    return pBVar1;
  }
  return s->rbio;
}


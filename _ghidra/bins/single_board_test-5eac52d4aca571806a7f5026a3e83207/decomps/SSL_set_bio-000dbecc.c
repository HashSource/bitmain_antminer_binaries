
void SSL_set_bio(SSL *s,BIO *rbio,BIO *wbio)

{
  BIO *pBVar1;
  BIO *pBVar2;
  
  pBVar1 = SSL_get_rbio(s);
  if ((rbio == pBVar1) && (pBVar1 = SSL_get_wbio(s), wbio == pBVar1)) {
    return;
  }
  pBVar1 = rbio;
  if (rbio != (BIO *)0x0) {
    pBVar1 = (BIO *)0x1;
  }
  if (rbio != wbio) {
    pBVar1 = (BIO *)0x0;
  }
  if (pBVar1 != (BIO *)0x0) {
    BIO_up_ref(rbio);
  }
  pBVar1 = SSL_get_rbio(s);
  if (rbio != pBVar1) {
    pBVar1 = SSL_get_wbio(s);
    if (wbio == pBVar1) {
      pBVar1 = SSL_get_rbio(s);
      pBVar2 = SSL_get_wbio(s);
      if (pBVar1 != pBVar2) {
        SSL_set0_rbio(s,rbio);
        return;
      }
    }
    SSL_set0_rbio(s,rbio);
  }
  SSL_set0_wbio(s,wbio);
  return;
}


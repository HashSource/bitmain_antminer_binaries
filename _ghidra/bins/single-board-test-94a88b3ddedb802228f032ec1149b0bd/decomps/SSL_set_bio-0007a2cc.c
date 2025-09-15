
void SSL_set_bio(SSL *s,BIO *rbio,BIO *wbio)

{
  BIO *pBVar1;
  BIO *pBVar2;
  BIO *pBVar3;
  bool bVar4;
  
  pBVar3 = s->bbio;
  if (pBVar3 != (BIO *)0x0) {
    pBVar2 = s->wbio;
    bVar4 = pBVar3 == pBVar2;
    pBVar1 = rbio;
    if (bVar4) {
      pBVar2 = pBVar3->next_bio;
      pBVar1 = (bio_st *)0x0;
    }
    if (bVar4) {
      s->wbio = pBVar2;
    }
    if (bVar4) {
      pBVar3->next_bio = pBVar1;
    }
  }
  pBVar3 = s->rbio;
  if ((pBVar3 != (BIO *)0x0) && (pBVar3 != rbio)) {
    BIO_free_all(pBVar3);
  }
  pBVar3 = s->wbio;
  if (((pBVar3 != (BIO *)0x0) && (pBVar3 != wbio)) && (pBVar3 != s->rbio)) {
    BIO_free_all(pBVar3);
  }
  s->rbio = rbio;
  s->wbio = wbio;
  return;
}


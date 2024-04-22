
int SSL_set_fd(SSL *s,int fd)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  bio_st *extraout_r1;
  bio_st *pbVar2;
  BIO *pBVar3;
  BIO *pBVar4;
  bool bVar5;
  
  type = BIO_s_socket();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x14,0xc0,7,DAT_0007a3fc,0x2db);
    iVar1 = 0;
  }
  else {
    BIO_int_ctrl(bp,0x68,0,fd);
    pBVar4 = s->bbio;
    if (pBVar4 != (BIO *)0x0) {
      pBVar3 = s->wbio;
      bVar5 = pBVar4 == pBVar3;
      pbVar2 = extraout_r1;
      if (bVar5) {
        pBVar3 = pBVar4->next_bio;
        pbVar2 = (bio_st *)0x0;
      }
      if (bVar5) {
        s->wbio = pBVar3;
      }
      if (bVar5) {
        pBVar4->next_bio = pbVar2;
      }
    }
    pBVar4 = s->rbio;
    if ((pBVar4 != (BIO *)0x0) && (bp != pBVar4)) {
      BIO_free_all(pBVar4);
    }
    pBVar4 = s->wbio;
    if (((pBVar4 != (BIO *)0x0) && (bp != pBVar4)) && (pBVar4 != s->rbio)) {
      BIO_free_all(pBVar4);
    }
    iVar1 = 1;
    s->rbio = bp;
    s->wbio = bp;
  }
  return iVar1;
}


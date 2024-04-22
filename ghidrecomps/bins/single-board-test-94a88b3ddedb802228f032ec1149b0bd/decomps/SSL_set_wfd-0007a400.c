
int SSL_set_wfd(SSL *s,int fd)

{
  int iVar1;
  BIO_METHOD *type;
  BIO *pBVar2;
  BIO *pBVar3;
  long lVar4;
  bio_st *pbVar5;
  bio_st *pbVar6;
  BIO *pBVar7;
  bool bVar8;
  
  if ((s->rbio != (BIO *)0x0) && (iVar1 = BIO_method_type(s->rbio), iVar1 == 0x505)) {
    pbVar6 = (bio_st *)0x0;
    lVar4 = BIO_ctrl(s->rbio,0x69,0,(void *)0x0);
    if (lVar4 == fd) {
      pbVar5 = s->bbio;
      pBVar3 = s->rbio;
      pBVar2 = s->wbio;
      if (pbVar5 != (BIO *)0x0) {
        bVar8 = pbVar5 == pBVar2;
        if (bVar8) {
          pbVar5 = pBVar2->next_bio;
          pbVar6 = (bio_st *)0x0;
        }
        if (bVar8) {
          s->wbio = pbVar5;
        }
        if (bVar8) {
          pBVar2->next_bio = pbVar6;
          pBVar2 = pbVar5;
        }
      }
      if ((pBVar2 != (BIO *)0x0) && (pBVar3 != pBVar2)) {
        BIO_free_all(pBVar2);
      }
      s->rbio = pBVar3;
      s->wbio = pBVar3;
      return 1;
    }
  }
  type = BIO_s_socket();
  pBVar2 = BIO_new(type);
  if (pBVar2 == (BIO *)0x0) {
    ERR_put_error(0x14,0xc4,7,DAT_0007a4b0,0x2ef);
    iVar1 = 0;
  }
  else {
    pbVar5 = (bio_st *)0x0;
    BIO_int_ctrl(pBVar2,0x68,0,fd);
    pbVar6 = s->bbio;
    pBVar7 = s->rbio;
    pBVar3 = s->wbio;
    if (pbVar6 != (BIO *)0x0) {
      bVar8 = pbVar6 == pBVar3;
      if (bVar8) {
        pbVar6 = pBVar3->next_bio;
        pbVar5 = (bio_st *)0x0;
      }
      if (bVar8) {
        s->wbio = pbVar6;
      }
      if (bVar8) {
        pBVar3->next_bio = pbVar5;
        pBVar3 = pbVar6;
      }
    }
    if (((pBVar3 != (BIO *)0x0) && (pBVar2 != pBVar3)) && (pBVar7 != pBVar3)) {
      BIO_free_all(pBVar3);
    }
    iVar1 = 1;
    s->rbio = pBVar7;
    s->wbio = pBVar2;
  }
  return iVar1;
}


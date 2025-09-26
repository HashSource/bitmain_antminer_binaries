
void asn1_bio_gets(BIO *param_1,char *param_2,int param_3)

{
  BIO *bp;
  
  bp = BIO_next(param_1);
  if (bp != (BIO *)0x0) {
    BIO_gets(bp,param_2,param_3);
    return;
  }
  return;
}


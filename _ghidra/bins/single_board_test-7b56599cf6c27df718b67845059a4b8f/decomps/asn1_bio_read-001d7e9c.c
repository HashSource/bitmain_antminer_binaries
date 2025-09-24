
void asn1_bio_read(BIO *param_1,void *param_2,int param_3)

{
  BIO *b;
  
  b = BIO_next(param_1);
  if (b != (BIO *)0x0) {
    BIO_read(b,param_2,param_3);
    return;
  }
  return;
}



void * ASN1_item_d2i_fp(ASN1_ITEM *it,FILE *in,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  void *pvVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xd,0xce,7,"crypto/asn1/a_d2i_fp.c",0x52);
    pvVar1 = (void *)0x0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,in);
    pvVar1 = ASN1_item_d2i_bio(it,bp,x);
    BIO_free(bp);
  }
  return pvVar1;
}



int ASN1_i2d_fp(undefined1 *i2d,FILE *out,void *x)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,out);
    iVar1 = ASN1_i2d_bio(i2d,bp,(uchar *)x);
    BIO_free(bp);
    return iVar1;
  }
  ERR_put_error(0xd,0x75,7,"crypto/asn1/a_i2d_fp.c",0x18);
  return 0;
}


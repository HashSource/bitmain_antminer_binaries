
void * PEM_ASN1_read(undefined1 *d2i,char *name,FILE *fp,void **x,undefined1 *cb,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  void *pvVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x66,7,DAT_000bdadc,0xac);
    pvVar1 = (void *)0x0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    pvVar1 = PEM_ASN1_read_bio(d2i,name,bp,x,cb,u);
    BIO_free(bp);
  }
  return pvVar1;
}


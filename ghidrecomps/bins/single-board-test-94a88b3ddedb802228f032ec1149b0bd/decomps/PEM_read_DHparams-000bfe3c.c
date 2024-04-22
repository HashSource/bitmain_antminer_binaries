
DH * PEM_read_DHparams(FILE *fp,DH **x,undefined1 *cb,void *u)

{
  BIO_METHOD *type;
  BIO *bp;
  DH *pDVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x8e,7,DAT_000bfe94,0x11b);
    pDVar1 = (DH *)0x0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    pDVar1 = PEM_read_bio_DHparams(bp,x,cb,u);
    BIO_free(bp);
  }
  return pDVar1;
}


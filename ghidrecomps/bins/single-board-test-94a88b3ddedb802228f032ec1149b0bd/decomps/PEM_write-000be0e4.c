
int PEM_write(FILE *fp,char *name,char *hdr,uchar *data,long len)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x71,7,DAT_000be140,0x24d);
    iVar1 = 0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    iVar1 = PEM_write_bio(bp,name,hdr,data,len);
    BIO_free(bp);
  }
  return iVar1;
}



int PEM_read(FILE *fp,char **name,char **header,uchar **data,long *len)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(9,0x6c,7,DAT_000bea0c,0x299);
    iVar1 = 0;
  }
  else {
    BIO_ctrl(bp,0x6a,0,fp);
    iVar1 = PEM_read_bio(bp,name,header,data,len);
    BIO_free(bp);
  }
  return iVar1;
}


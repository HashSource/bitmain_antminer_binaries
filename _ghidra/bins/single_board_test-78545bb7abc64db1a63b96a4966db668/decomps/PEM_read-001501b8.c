
int PEM_read(FILE *fp,char **name,char **header,uchar **data,long *len)

{
  BIO_METHOD *type;
  BIO *bp;
  int iVar1;
  
  type = BIO_s_file();
  bp = BIO_new(type);
  if (bp != (BIO *)0x0) {
    BIO_ctrl(bp,0x6a,0,fp);
    iVar1 = PEM_read_bio(bp,name,header,data,len);
    BIO_free(bp);
    return iVar1;
  }
  ERR_put_error(9,0x6c,7,"crypto/pem/pem_lib.c",0x2a0);
  return 0;
}


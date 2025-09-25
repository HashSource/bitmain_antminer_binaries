
int PEM_read_bio(BIO *bp,char **name,char **header,uchar **data,long *len)

{
  int iVar1;
  
  iVar1 = PEM_read_bio_ex(bp);
  return iVar1;
}


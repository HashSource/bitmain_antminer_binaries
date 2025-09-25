
int BIO_dump_fp(FILE *fp,char *s,int len)

{
  int iVar1;
  
  iVar1 = BIO_dump_cb((cb *)0x182c49,fp,s,len);
  return iVar1;
}


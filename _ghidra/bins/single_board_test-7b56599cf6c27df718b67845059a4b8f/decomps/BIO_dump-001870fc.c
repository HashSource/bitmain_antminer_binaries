
int BIO_dump(BIO *b,char *bytes,int len)

{
  int iVar1;
  
  iVar1 = BIO_dump_cb((cb *)0x186ea1,b,bytes,len);
  return iVar1;
}


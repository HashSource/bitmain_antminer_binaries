
int BIO_dump_cb(cb *cb,void *u,char *s,int len)

{
  int iVar1;
  
  iVar1 = BIO_dump_indent_cb(cb,u,s,len,0);
  return iVar1;
}


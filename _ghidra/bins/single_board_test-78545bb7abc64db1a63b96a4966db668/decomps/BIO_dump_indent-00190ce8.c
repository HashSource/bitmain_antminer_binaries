
int BIO_dump_indent(BIO *b,char *bytes,int len,int indent)

{
  int iVar1;
  
  iVar1 = BIO_dump_indent_cb((cb *)0x190a79,b,bytes,len,indent);
  return iVar1;
}


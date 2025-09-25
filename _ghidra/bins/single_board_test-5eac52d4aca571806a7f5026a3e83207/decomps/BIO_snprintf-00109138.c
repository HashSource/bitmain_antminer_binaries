
int BIO_snprintf(char *buf,size_t n,char *format,...)

{
  int iVar1;
  undefined4 in_r3;
  undefined4 uStack_4;
  
  uStack_4 = in_r3;
  iVar1 = BIO_vsnprintf(buf,n,format,&uStack_4);
  return iVar1;
}


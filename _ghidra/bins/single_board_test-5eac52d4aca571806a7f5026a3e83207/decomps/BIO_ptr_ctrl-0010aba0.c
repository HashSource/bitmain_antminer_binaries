
char * BIO_ptr_ctrl(BIO *bp,int cmd,long larg)

{
  long lVar1;
  char *local_c;
  
  local_c = (char *)0x0;
  lVar1 = BIO_ctrl(bp,cmd,larg,&local_c);
  if (lVar1 < 1) {
    local_c = (char *)0x0;
  }
  return local_c;
}


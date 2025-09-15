
long BIO_int_ctrl(BIO *bp,int cmd,long larg,int iarg)

{
  long lVar1;
  int local_c;
  
  local_c = iarg;
  lVar1 = BIO_ctrl(bp,cmd,larg,&local_c);
  return lVar1;
}


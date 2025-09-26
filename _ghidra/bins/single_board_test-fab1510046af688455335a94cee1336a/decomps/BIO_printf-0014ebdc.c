
int BIO_printf(BIO *bio,char *format,...)

{
  int iVar1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  iVar1 = BIO_vprintf(bio,format,&uStack_8);
  return iVar1;
}


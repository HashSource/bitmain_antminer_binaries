
bool send_bio_chars(BIO *param_1,void *param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != (BIO *)0x0) {
    iVar1 = BIO_write(param_1,param_2,param_3);
    return param_3 == iVar1;
  }
  return true;
}


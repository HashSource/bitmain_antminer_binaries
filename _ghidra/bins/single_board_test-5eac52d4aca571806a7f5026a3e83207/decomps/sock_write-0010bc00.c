
ssize_t sock_write(BIO *param_1,void *param_2,size_t param_3)

{
  int *piVar1;
  ssize_t i;
  int iVar2;
  
  piVar1 = __errno_location();
  *piVar1 = 0;
  i = write((int)param_1->ptr,param_2,param_3);
  BIO_clear_flags(param_1,0xf);
  if ((i < 1) && (iVar2 = BIO_sock_should_retry(i), iVar2 != 0)) {
    BIO_set_flags(param_1,10);
  }
  return i;
}



ssize_t sock_puts(BIO *param_1,char *param_2)

{
  size_t __n;
  int *piVar1;
  ssize_t i;
  int iVar2;
  
  __n = strlen(param_2);
  piVar1 = __errno_location();
  *piVar1 = 0;
  i = write((int)param_1->ptr,param_2,__n);
  BIO_clear_flags(param_1,0xf);
  if ((i < 1) && (iVar2 = BIO_sock_should_retry(i), iVar2 != 0)) {
    BIO_set_flags(param_1,10);
  }
  return i;
}


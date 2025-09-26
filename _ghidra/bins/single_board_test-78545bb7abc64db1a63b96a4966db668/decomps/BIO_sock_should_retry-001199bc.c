
int BIO_sock_should_retry(int i)

{
  int *piVar1;
  int iVar2;
  
  if (1 < i + 1U) {
    return 0;
  }
  piVar1 = __errno_location();
  iVar2 = BIO_sock_non_fatal_error(*piVar1);
  return iVar2;
}


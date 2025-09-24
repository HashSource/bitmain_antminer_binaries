
int BIO_sock_error(int sock)

{
  int iVar1;
  int *piVar2;
  int local_18 [3];
  
  local_18[1] = 4;
  local_18[0] = 0;
  iVar1 = getsockopt(sock,1,4,local_18,(socklen_t *)(local_18 + 1));
  if (iVar1 < 0) {
    piVar2 = __errno_location();
    return *piVar2;
  }
  return local_18[0];
}


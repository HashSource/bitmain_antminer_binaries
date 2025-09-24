
int BIO_socket_ioctl(int fd,long type,void *arg)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = ioctl(fd,type);
  if (-1 < iVar1) {
    return iVar1;
  }
  piVar2 = __errno_location();
  ERR_put_error(2,5,*piVar2,"crypto/bio/b_sock.c",0xc3);
  return iVar1;
}


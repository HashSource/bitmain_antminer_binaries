
int BIO_socket_nbio(int fd,int mode)

{
  int iVar1;
  int local_c [2];
  
  local_c[0] = mode;
  iVar1 = BIO_socket_ioctl(fd,0x5421,local_c);
  return (uint)(iVar1 == 0);
}


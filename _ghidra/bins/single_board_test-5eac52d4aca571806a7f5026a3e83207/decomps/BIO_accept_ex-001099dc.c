
int BIO_accept_ex(int param_1,undefined1 *param_2,int param_3)

{
  sockaddr *__addr;
  int fd;
  int iVar1;
  int *piVar2;
  socklen_t local_84;
  undefined1 auStack_80 [112];
  
  if (param_2 == (undefined1 *)0x0) {
    param_2 = auStack_80;
  }
  local_84 = 0x70;
  __addr = (sockaddr *)BIO_ADDR_sockaddr_noconst(param_2);
  fd = accept(param_1,__addr,&local_84);
  if (fd == -1) {
    iVar1 = BIO_sock_should_retry(-1);
    if (iVar1 != 0) {
      return -1;
    }
    piVar2 = __errno_location();
    ERR_put_error(2,8,*piVar2,"crypto/bio/b_sock2.c",0x126);
    ERR_put_error(0x20,0x89,100,"crypto/bio/b_sock2.c",0x127);
  }
  else {
    iVar1 = BIO_socket_nbio(fd,(uint)(param_3 << 0x1c) >> 0x1f);
    if (iVar1 == 0) {
      close(fd);
      return -1;
    }
  }
  return fd;
}


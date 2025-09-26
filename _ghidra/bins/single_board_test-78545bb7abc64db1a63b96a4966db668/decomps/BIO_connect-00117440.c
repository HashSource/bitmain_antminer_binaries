
undefined4 BIO_connect(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  sockaddr *__addr;
  socklen_t __len;
  int *piVar2;
  undefined4 local_1c [2];
  
  local_1c[0] = 1;
  if (param_1 == -1) {
    ERR_put_error(0x20,0x8a,0x87,"crypto/bio/b_sock2.c",0x52);
    return 0;
  }
  iVar1 = BIO_socket_nbio(param_1,(uint)(param_3 << 0x1c) >> 0x1f);
  if (iVar1 != 0) {
    if ((param_3 << 0x1d < 0) && (iVar1 = setsockopt(param_1,1,9,local_1c,4), iVar1 != 0)) {
      piVar2 = __errno_location();
      ERR_put_error(2,0xe,*piVar2,"crypto/bio/b_sock2.c",0x5c);
      ERR_put_error(0x20,0x8a,0x89,"crypto/bio/b_sock2.c",0x5d);
      return 0;
    }
    if ((param_3 << 0x1b < 0) && (iVar1 = setsockopt(param_1,6,1,local_1c,4), iVar1 != 0)) {
      piVar2 = __errno_location();
      ERR_put_error(2,0xe,*piVar2,"crypto/bio/b_sock2.c",0x65);
      ERR_put_error(0x20,0x8a,0x8a,"crypto/bio/b_sock2.c",0x66);
      return 0;
    }
    __addr = (sockaddr *)BIO_ADDR_sockaddr(param_2);
    __len = BIO_ADDR_sockaddr_size(param_2);
    iVar1 = connect(param_1,__addr,__len);
    if (iVar1 != -1) {
      return 1;
    }
    iVar1 = BIO_sock_should_retry(-1);
    if (iVar1 == 0) {
      piVar2 = __errno_location();
      ERR_put_error(2,2,*piVar2,"crypto/bio/b_sock2.c",0x6e);
      ERR_put_error(0x20,0x8a,0x67,"crypto/bio/b_sock2.c",0x6f);
      return 0;
    }
  }
  return 0;
}


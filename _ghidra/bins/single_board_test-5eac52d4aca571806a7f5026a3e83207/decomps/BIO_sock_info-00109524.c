
undefined4 BIO_sock_info(int param_1,int param_2,undefined4 *param_3)

{
  sockaddr *__addr;
  int iVar1;
  int *piVar2;
  socklen_t local_14 [2];
  
  if (param_2 == 0) {
    local_14[0] = 0x70;
    __addr = (sockaddr *)BIO_ADDR_sockaddr_noconst(*param_3);
    iVar1 = getsockname(param_1,__addr,local_14);
    if (iVar1 == -1) {
      piVar2 = __errno_location();
      ERR_put_error(2,0x10,*piVar2,"crypto/bio/b_sock.c",0x160);
      ERR_put_error(0x20,0x8d,0x84,"crypto/bio/b_sock.c",0x161);
    }
    else {
      if (local_14[0] < 0x71) {
        return 1;
      }
      ERR_put_error(0x20,0x8d,0x85,"crypto/bio/b_sock.c",0x165);
    }
  }
  else {
    ERR_put_error(0x20,0x8d,0x8c,"crypto/bio/b_sock.c",0x16b);
  }
  return 0;
}


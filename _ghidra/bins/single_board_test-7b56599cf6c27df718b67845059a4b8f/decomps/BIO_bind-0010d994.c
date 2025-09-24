
undefined4 BIO_bind(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  sockaddr *__addr;
  socklen_t __len;
  undefined4 uVar2;
  int *piVar3;
  undefined4 local_14;
  
  local_14 = 1;
  if (param_1 == -1) {
    ERR_put_error(0x20,0x93,0x87,"crypto/bio/b_sock2.c",0x8d);
    uVar2 = 0;
  }
  else {
    if ((param_3 << 0x1f < 0) && (iVar1 = setsockopt(param_1,1,2,&local_14,4), iVar1 != 0)) {
      piVar3 = __errno_location();
      ERR_put_error(2,0xe,*piVar3,"crypto/bio/b_sock2.c",0x99);
      ERR_put_error(0x20,0x93,0x8b,"crypto/bio/b_sock2.c",0x9a);
      return 0;
    }
    __addr = (sockaddr *)BIO_ADDR_sockaddr(param_2);
    __len = BIO_ADDR_sockaddr_size(param_2);
    iVar1 = bind(param_1,__addr,__len);
    if (iVar1 != 0) {
      piVar3 = __errno_location();
      ERR_put_error(2,6,*piVar3,"crypto/bio/b_sock2.c",0xa1);
      ERR_put_error(0x20,0x93,0x75,"crypto/bio/b_sock2.c",0xa2);
      return 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}


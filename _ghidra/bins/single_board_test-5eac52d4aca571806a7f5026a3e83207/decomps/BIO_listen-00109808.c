
undefined4 BIO_listen(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint local_2c;
  int local_28;
  socklen_t local_24 [2];
  
  local_2c = 1;
  local_24[0] = 4;
  if (param_1 == -1) {
    ERR_put_error(0x20,0x8b,0x87,"crypto/bio/b_sock2.c",0xd5);
    return 0;
  }
  iVar1 = getsockopt(param_1,1,3,&local_28,local_24);
  if ((iVar1 == 0) && (local_24[0] == 4)) {
    iVar1 = BIO_socket_nbio(param_1,(uint)(param_3 << 0x1c) >> 0x1f);
    uVar3 = 0;
    if (iVar1 != 0) {
      if ((param_3 << 0x1d < 0) && (iVar1 = setsockopt(param_1,1,9,&local_2c,4), iVar1 != 0)) {
        piVar2 = __errno_location();
        ERR_put_error(2,0xe,*piVar2,"crypto/bio/b_sock2.c",0xe7);
        ERR_put_error(0x20,0x8b,0x89,"crypto/bio/b_sock2.c",0xe8);
        return 0;
      }
      if ((param_3 << 0x1b < 0) && (iVar1 = setsockopt(param_1,6,1,&local_2c,4), iVar1 != 0)) {
        piVar2 = __errno_location();
        ERR_put_error(2,0xe,*piVar2,"crypto/bio/b_sock2.c",0xf0);
        ERR_put_error(0x20,0x8b,0x8a,"crypto/bio/b_sock2.c",0xf1);
        return 0;
      }
      iVar1 = BIO_ADDR_family(param_2);
      if (iVar1 == 10) {
        local_2c = (uint)(param_3 << 0x1e) >> 0x1f;
        iVar1 = setsockopt(param_1,0x29,0x1a,&local_2c,4);
        if (iVar1 != 0) {
          piVar2 = __errno_location();
          ERR_put_error(2,0xe,*piVar2,"crypto/bio/b_sock2.c",0x100);
          ERR_put_error(0x20,0x8b,0x88,"crypto/bio/b_sock2.c",0x101);
          return 0;
        }
      }
      iVar1 = BIO_bind(param_1,param_2,param_3);
      if (iVar1 != 0) {
        if ((local_28 == 2) || (iVar1 = listen(param_1,0x80), iVar1 != -1)) {
          uVar3 = 1;
        }
        else {
          piVar2 = __errno_location();
          ERR_put_error(2,7,*piVar2,"crypto/bio/b_sock2.c",0x10b);
          ERR_put_error(0x20,0x8b,0x77,"crypto/bio/b_sock2.c",0x10c);
        }
      }
    }
  }
  else {
    uVar3 = 0;
    piVar2 = __errno_location();
    ERR_put_error(2,0xf,*piVar2,"crypto/bio/b_sock2.c",0xdc);
    ERR_put_error(0x20,0x8b,0x86,"crypto/bio/b_sock2.c",0xdd);
  }
  return uVar3;
}


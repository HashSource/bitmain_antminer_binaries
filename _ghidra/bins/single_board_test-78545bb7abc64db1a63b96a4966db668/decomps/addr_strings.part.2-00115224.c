
undefined4 addr_strings_part_2(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

{
  sockaddr *__sa;
  socklen_t __salen;
  int __ecode;
  char *pcVar1;
  int *piVar2;
  uint uVar3;
  uint local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  undefined4 local_42c;
  undefined1 auStack_428 [1028];
  
  local_42c = 0;
  memset(auStack_428,0,0x3fd);
  if (param_2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 3;
  }
  local_44c = 0;
  local_448 = 0;
  local_444 = 0;
  local_440 = 0;
  local_43c = 0;
  local_438 = 0;
  local_434 = 0;
  local_430 = 0;
  __sa = (sockaddr *)BIO_ADDR_sockaddr(param_1);
  __salen = BIO_ADDR_sockaddr_size(param_1);
  __ecode = getnameinfo(__sa,__salen,(char *)&local_42c,0x401,(char *)&local_44c,0x20,uVar3);
  if (__ecode == 0) {
    if ((local_44c & 0xff) == 0) {
      uVar3 = BIO_ADDR_rawport(param_1);
      BIO_snprintf((char *)&local_44c,0x20,"%d",(uVar3 & 0xff) << 8 | uVar3 >> 8 & 0xff);
    }
    if (param_3 != (int *)0x0) {
      pcVar1 = CRYPTO_strdup((char *)&local_42c,"crypto/bio/b_addr.c",0xed);
      *param_3 = (int)pcVar1;
    }
    if (param_4 == (undefined4 *)0x0) {
      if ((param_3 == (int *)0x0) || (*param_3 != 0)) {
        return 1;
      }
      CRYPTO_free((void *)0x0);
      *param_3 = 0;
    }
    else {
      pcVar1 = CRYPTO_strdup((char *)&local_44c,"crypto/bio/b_addr.c",0xef);
      *param_4 = pcVar1;
      if (param_3 == (int *)0x0) {
        if (pcVar1 != (char *)0x0) {
          return 1;
        }
      }
      else {
        if ((void *)*param_3 == (void *)0x0) {
          CRYPTO_free((void *)0x0);
          *param_3 = 0;
        }
        else {
          if (pcVar1 != (char *)0x0) {
            return 1;
          }
          CRYPTO_free((void *)*param_3);
          *param_3 = 0;
        }
        pcVar1 = (char *)*param_4;
      }
      CRYPTO_free(pcVar1);
      *param_4 = 0;
    }
    ERR_put_error(0x20,0x86,0x41,"crypto/bio/b_addr.c",0x105);
  }
  else if (__ecode == -0xb) {
    piVar2 = __errno_location();
    ERR_put_error(2,0xd,*piVar2,"crypto/bio/b_addr.c",0xd6);
    ERR_put_error(0x20,0x86,2,"crypto/bio/b_addr.c",0xd7);
  }
  else {
    ERR_put_error(0x20,0x86,2,"crypto/bio/b_addr.c",0xdb);
    pcVar1 = gai_strerror(__ecode);
    ERR_add_error_data(1,pcVar1);
  }
  return 0;
}


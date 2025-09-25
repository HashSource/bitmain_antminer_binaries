
undefined4
BIO_lookup_ex(char *param_1,char *param_2,int param_3,int param_4,int param_5,int param_6,
             addrinfo **param_7)

{
  uint uVar1;
  int iVar2;
  size_t sVar3;
  addrinfo *paVar4;
  sockaddr *psVar5;
  int __ecode;
  int *piVar6;
  char *pcVar7;
  uint uVar8;
  addrinfo local_40;
  
  if (-1 < param_4) {
    if (param_4 < 3) {
      if (param_4 == 1) {
        sVar3 = strlen(param_1);
        paVar4 = (addrinfo *)CRYPTO_zalloc(0x20,"crypto/bio/b_addr.c",0x23c);
        *param_7 = paVar4;
        if (paVar4 == (addrinfo *)0x0) {
          ERR_put_error(0x20,0x94,0x41,"crypto/bio/b_addr.c",0x23d);
        }
        else {
          paVar4->ai_family = 1;
          paVar4->ai_protocol = 0;
          paVar4->ai_socktype = param_5;
          iVar2 = BIO_ADDR_new();
          if (iVar2 != 0) {
            BIO_ADDR_rawmake(iVar2,1,param_1,sVar3,0);
            paVar4 = *param_7;
            psVar5 = (sockaddr *)BIO_ADDR_sockaddr_noconst(iVar2);
            paVar4->ai_addr = psVar5;
          }
          (*param_7)->ai_next = (addrinfo *)0x0;
          if ((*param_7)->ai_addr != (sockaddr *)0x0) {
            return 1;
          }
          BIO_ADDRINFO_free();
          *param_7 = (addrinfo *)0x0;
        }
        iVar2 = 0x2a0;
LAB_0010794a:
        ERR_put_error(0x20,0x8f,0x41,"crypto/bio/b_addr.c",iVar2);
        return 0;
      }
    }
    else if (param_4 != 10) goto LAB_001078ae;
    iVar2 = BIO_sock_init();
    if (iVar2 == 1) {
      memset(&local_40,0,0x20);
      pcVar7 = param_1;
      if (param_1 != (char *)0x0) {
        pcVar7 = (char *)0x1;
      }
      if (param_4 != 0) {
        pcVar7 = (char *)0x0;
      }
      local_40.ai_socktype = param_5;
      local_40.ai_protocol = param_6;
      uVar8 = 1;
      if (pcVar7 != (char *)0x0) {
        uVar8 = 0x21;
        local_40.ai_flags = 0x20;
      }
      iVar2 = 0;
      uVar1 = local_40.ai_flags;
      local_40.ai_family = param_4;
      if (param_3 == 1) {
        uVar1 = uVar8;
      }
      do {
        local_40.ai_flags = uVar1;
        __ecode = iVar2;
        iVar2 = getaddrinfo(param_1,param_2,&local_40,param_7);
        if (iVar2 == -10) {
          iVar2 = 0x2cb;
          goto LAB_0010794a;
        }
        if (iVar2 == 0) {
          return 1;
        }
        if (iVar2 == -0xb) {
          piVar6 = __errno_location();
          ERR_put_error(2,0xc,*piVar6,"crypto/bio/b_addr.c",0x2c5);
          ERR_put_error(0x20,0x8f,2,"crypto/bio/b_addr.c",0x2c6);
          return 0;
        }
        uVar1 = local_40.ai_flags & 0xffffffdfU | 4;
      } while ((local_40.ai_flags & 0x20U) != 0);
      ERR_put_error(0x20,0x8f,2,"crypto/bio/b_addr.c",0x2da);
      if (__ecode == 0) {
        __ecode = iVar2;
      }
      pcVar7 = gai_strerror(__ecode);
      ERR_add_error_data(1,pcVar7);
    }
    return 0;
  }
LAB_001078ae:
  ERR_put_error(0x20,0x8f,0x83,"crypto/bio/b_addr.c",0x297);
  return 0;
}


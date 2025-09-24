
int BIO_get_accept_socket(char *host_port,int mode)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  void *local_24;
  void *local_20;
  undefined4 local_1c [2];
  
  local_24 = (void *)0x0;
  local_20 = (void *)0x0;
  local_1c[0] = 0;
  iVar1 = BIO_parse_hostserv(host_port,&local_24,&local_20,1);
  if ((iVar1 == 0) || (iVar1 = BIO_sock_init(), iVar1 != 1)) {
    return -1;
  }
  iVar1 = BIO_lookup(local_24,local_20,1,0,1,local_1c);
  if (iVar1 == 0) {
    uVar2 = BIO_ADDRINFO_family(local_1c[0]);
    uVar3 = BIO_ADDRINFO_socktype(local_1c[0]);
    uVar4 = BIO_ADDRINFO_protocol(local_1c[0]);
    iVar1 = BIO_socket(uVar2,uVar3,uVar4,0);
    if (iVar1 != -1) {
      uVar2 = BIO_ADDRINFO_address(local_1c[0]);
      if (mode != 0) {
        mode = 1;
      }
      iVar5 = BIO_listen(iVar1,uVar2,mode);
      iVar6 = iVar1;
      if (iVar5 == 0) {
        iVar6 = -1;
        BIO_closesocket(iVar1);
      }
      goto LAB_0010d5a0;
    }
  }
  iVar6 = -1;
LAB_0010d5a0:
  BIO_ADDRINFO_free(local_1c[0]);
  CRYPTO_free(local_24);
  CRYPTO_free(local_20);
  return iVar6;
}


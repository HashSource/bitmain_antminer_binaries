
int BIO_accept(int sock,char **ip_port)

{
  int iVar1;
  char *__s;
  char *__s_00;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  int *piVar5;
  undefined1 auStack_88 [112];
  
  iVar1 = BIO_accept_ex(sock,auStack_88,0);
  if (iVar1 == -1) {
    iVar1 = BIO_sock_should_retry(-1);
    if (iVar1 != 0) {
      return -2;
    }
    piVar5 = __errno_location();
    ERR_put_error(2,8,*piVar5,"crypto/bio/b_sock.c",0xf6);
    ERR_put_error(0x20,0x65,100,"crypto/bio/b_sock.c",0xf7);
    return -1;
  }
  if (ip_port == (char **)0x0) {
    return iVar1;
  }
  __s = (char *)BIO_ADDR_hostname_string(auStack_88,1);
  __s_00 = (char *)BIO_ADDR_service_string(auStack_88,1);
  if (__s == (char *)0x0 || __s_00 == (char *)0x0) {
    *ip_port = (char *)0x0;
  }
  else {
    sVar2 = strlen(__s);
    sVar3 = strlen(__s_00);
    pcVar4 = (char *)CRYPTO_zalloc(sVar3 + sVar2 + 2,"crypto/bio/b_sock.c",0xff);
    *ip_port = pcVar4;
    if (pcVar4 != (char *)0x0) {
      strcpy(pcVar4,__s);
      pcVar4 = *ip_port;
      sVar2 = strlen(pcVar4);
      pcVar4 = pcVar4 + sVar2;
      pcVar4[0] = ':';
      pcVar4[1] = '\0';
      strcat(*ip_port,__s_00);
      goto LAB_00109428;
    }
  }
  ERR_put_error(0x20,0x65,0x41,"crypto/bio/b_sock.c",0x104);
  BIO_closesocket(iVar1);
  iVar1 = -1;
LAB_00109428:
  CRYPTO_free(__s);
  CRYPTO_free(__s_00);
  return iVar1;
}


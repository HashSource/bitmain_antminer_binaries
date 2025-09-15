
_Bool check_connect(sockaddr_storage *cli,char **connectaddr,char *group)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  uint32_t uVar4;
  char *group_local;
  char **connectaddr_local;
  sockaddr_storage *cli_local;
  in6_addr client_ip;
  char tmp [30];
  in6_addr *__a;
  _Bool match;
  int j;
  int i;
  _Bool addrok;
  
  addrok = false;
  pcVar2 = (char *)_cgmalloc(0x2e,"api-btm.c","check_connect",0x1360);
  *connectaddr = pcVar2;
  getnameinfo((sockaddr *)cli,0x80,*connectaddr,0x2e,(char *)0x0,0,1);
  if (cli->ss_family == 2) {
    sprintf(tmp,"::ffff:%s",*connectaddr);
    inet_pton(10,tmp,&client_ip);
  }
  else {
    inet_pton(10,*connectaddr,&client_ip);
  }
  iVar3 = toupper(0x52);
  *group = (char)iVar3;
  if (opt_api_allow == (char *)0x0) {
    if (opt_api_network == false) {
      iVar3 = strcmp(*connectaddr,localaddr);
      if (iVar3 != 0) {
        if ((((client_ip.__in6_u.__u6_addr32[0] == 0) && (client_ip.__in6_u.__u6_addr32[1] == 0)) &&
            (client_ip.__in6_u.__u6_addr32[2] == 0)) &&
           (uVar4 = htonl(1), client_ip.__in6_u.__u6_addr32[3] == uVar4)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (!bVar1) {
          return false;
        }
      }
      addrok = true;
    }
    else {
      addrok = true;
    }
  }
  else {
    for (i = 0; i < ips; i = i + 1) {
      bVar1 = true;
      for (j = 0; j < 0x10; j = j + 1) {
        if ((ipaccess[i].mask.__in6_u.__u6_addr8[j] & tmp[j + -0x10]) !=
            ipaccess[i].ip.__in6_u.__u6_addr8[j]) {
          bVar1 = false;
          break;
        }
      }
      if (bVar1) {
        *group = ipaccess[i].group;
        return true;
      }
    }
  }
  return addrok;
}


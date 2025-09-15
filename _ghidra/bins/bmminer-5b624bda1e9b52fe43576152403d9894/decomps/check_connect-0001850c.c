
/* WARNING: Unknown calling convention */

_Bool check_connect(sockaddr_storage *cli,char **connectaddr,char *group)

{
  byte *pbVar1;
  char *__host;
  __int32_t **pp_Var2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  _Bool _Var7;
  byte bStack_51;
  in6_addr client_ip;
  char tmp [30];
  
  __host = (char *)malloc(0x2e);
  *connectaddr = __host;
  getnameinfo((sockaddr *)cli,0x80,__host,0x2e,(char *)0x0,0,1);
  if (cli->ss_family == 2) {
    sprintf(tmp,"::ffff:%s",*connectaddr);
    inet_pton(10,tmp,&client_ip);
  }
  else {
    inet_pton(10,*connectaddr,&client_ip);
  }
  pp_Var2 = __ctype_toupper_loc();
  *group = (char)(*pp_Var2)[0x52];
  if (opt_api_allow == (char *)0x0) {
    if ((opt_api_network == false) && (iVar6 = strcmp(*connectaddr,"127.0.0.1"), iVar6 != 0)) {
      if (client_ip.__in6_u.__u6_addr32[0] == 0) {
        _Var7 = false;
        if ((client_ip.__in6_u.__u6_addr32[1] == 0) &&
           (_Var7 = false, client_ip.__in6_u.__u6_addr32[2] == 0)) {
          _Var7 = client_ip.__in6_u.__u6_addr32[3] == 0x1000000;
        }
      }
      else {
        _Var7 = false;
      }
    }
    else {
      _Var7 = true;
    }
  }
  else {
    if (0 < ips) {
      iVar6 = 0;
      pbVar4 = &ipaccess[-1].field_0x23;
      do {
        pbVar3 = &bStack_51;
        pbVar5 = pbVar4;
        while( true ) {
          pbVar1 = pbVar5 + 0x11;
          pbVar3 = pbVar3 + 1;
          pbVar5 = pbVar5 + 1;
          if (*pbVar5 != (*pbVar3 & *pbVar1)) break;
          if (pbVar3 == (byte *)((int)&client_ip.__in6_u + 0xf)) {
            *group = pbVar4[0x21];
            return true;
          }
        }
        iVar6 = iVar6 + 1;
        pbVar4 = pbVar4 + 0x24;
      } while (iVar6 != ips);
    }
    _Var7 = false;
  }
  return _Var7;
}



/* WARNING: Unknown calling convention */

_Bool check_connect(sockaddr_storage *cli,char **connectaddr,char *group)

{
  byte *pbVar1;
  int *piVar2;
  char *__host;
  __int32_t **pp_Var3;
  byte *pbVar4;
  byte *pbVar5;
  byte *pbVar6;
  int iVar7;
  _Bool _Var8;
  byte bStack_51;
  in6_addr client_ip;
  char tmp [30];
  
  __host = (char *)malloc(0x2e);
  *connectaddr = __host;
  getnameinfo((sockaddr *)cli,0x80,__host,0x2e,(char *)0x0,0,1);
  if (cli->ss_family == 2) {
    sprintf(tmp,DAT_00018600,*connectaddr);
    inet_pton(10,tmp,&client_ip);
  }
  else {
    inet_pton(10,*connectaddr,&client_ip);
  }
  pp_Var3 = __ctype_toupper_loc();
  piVar2 = DAT_000185f8;
  *group = (char)(*pp_Var3)[0x52];
  if (*piVar2 == 0) {
    if ((*DAT_00018604 == '\0') && (iVar7 = strcmp(*connectaddr,DAT_00018608), iVar7 != 0)) {
      if (client_ip.__in6_u.__u6_addr32[0] == 0) {
        _Var8 = false;
        if ((client_ip.__in6_u.__u6_addr32[1] == 0) &&
           (_Var8 = false, client_ip.__in6_u.__u6_addr32[2] == 0)) {
          _Var8 = client_ip.__in6_u.__u6_addr32[3] == 0x1000000;
        }
      }
      else {
        _Var8 = false;
      }
    }
    else {
      _Var8 = true;
    }
  }
  else {
    if (0 < *(int *)(DAT_000185fc + 4)) {
      iVar7 = 0;
      pbVar5 = (byte *)(*(int *)(DAT_000185fc + 8) + -1);
      do {
        pbVar4 = &bStack_51;
        pbVar6 = pbVar5;
        while( true ) {
          pbVar1 = pbVar6 + 0x11;
          pbVar4 = pbVar4 + 1;
          pbVar6 = pbVar6 + 1;
          if (*pbVar6 != (*pbVar4 & *pbVar1)) break;
          if (pbVar4 == (byte *)((int)&client_ip.__in6_u + 0xf)) {
            *group = pbVar5[0x21];
            return true;
          }
        }
        iVar7 = iVar7 + 1;
        pbVar5 = pbVar5 + 0x24;
      } while (iVar7 != *(int *)(DAT_000185fc + 4));
    }
    _Var8 = false;
  }
  return _Var8;
}


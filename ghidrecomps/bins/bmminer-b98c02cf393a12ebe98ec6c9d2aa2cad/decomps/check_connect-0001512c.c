
bool check_connect(sockaddr *param_1,char **param_2,byte *param_3)

{
  bool bVar1;
  char *__host;
  __int32_t **pp_Var2;
  byte *pbVar3;
  byte *pbVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  byte bStack_51;
  int local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  char acStack_40 [36];
  
  __host = (char *)malloc(0x2e);
  *param_2 = __host;
  getnameinfo(param_1,0x80,__host,0x2e,(char *)0x0,0,1);
  if (param_1->sa_family == 2) {
    sprintf(acStack_40,"::ffff:%s",*param_2);
    inet_pton(10,acStack_40,&local_50);
  }
  else {
    inet_pton(10,*param_2,&local_50);
  }
  pp_Var2 = __ctype_toupper_loc();
  *param_3 = (byte)(*pp_Var2)[0x52];
  if (opt_api_allow == 0) {
    if ((opt_api_network == '\0') && (iVar6 = strcmp(*param_2,"127.0.0.1"), iVar6 != 0)) {
      bVar1 = false;
      if (local_50 == 0) {
        if (local_4c == 0) {
          bVar1 = false;
          if (local_48 == 0) {
            bVar1 = local_44 == 0x1000000;
          }
        }
        else {
          bVar1 = false;
        }
      }
      return bVar1;
    }
    return true;
  }
  if (0 < ips) {
    iVar6 = 0;
    pbVar7 = (byte *)(ipaccess + -1);
    do {
      pbVar5 = &bStack_51;
      pbVar3 = pbVar7 + 0x10;
      pbVar4 = pbVar7;
      while( true ) {
        pbVar5 = pbVar5 + 1;
        pbVar3 = pbVar3 + 1;
        pbVar4 = pbVar4 + 1;
        if (*pbVar4 != (*pbVar3 & *pbVar5)) break;
        if ((byte *)((int)&local_44 + 3) == pbVar5) {
          *param_3 = pbVar7[0x21];
          return true;
        }
      }
      iVar6 = iVar6 + 1;
      pbVar7 = pbVar7 + 0x24;
    } while (iVar6 != ips);
  }
  return false;
}


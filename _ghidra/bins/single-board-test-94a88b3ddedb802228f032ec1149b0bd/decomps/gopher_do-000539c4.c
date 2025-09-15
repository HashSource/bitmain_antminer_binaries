
int gopher_do(int *param_1,undefined1 *param_2)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *__s;
  undefined1 *puVar5;
  char *__s_00;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_30;
  undefined4 local_2c [2];
  
  iVar7 = *param_1;
  iVar6 = param_1[0x55];
  __s = *(char **)(iVar7 + 0x868c);
  *param_2 = 1;
  sVar1 = strlen(__s);
  if (sVar1 < 3) {
    puVar5 = &DAT_0013a6fc;
    local_2c[0] = 0;
    puVar8 = (undefined1 *)0x0;
  }
  else {
    __s_00 = __s + 2;
    sVar1 = strlen(__s_00);
    pcVar4 = __s + sVar1;
    if (sVar1 != 0) {
      do {
        if (__s[2] == '?') {
          __s[2] = '\t';
        }
        __s = __s + 1;
      } while (__s != pcVar4);
    }
    puVar5 = (undefined1 *)curl_easy_unescape(iVar7,__s_00,0,local_2c);
    puVar8 = puVar5;
    if (puVar5 == (undefined1 *)0x0) {
      return 0x1b;
    }
  }
  iVar2 = curlx_uztosz(local_2c[0]);
  while (iVar3 = Curl_write(param_1,iVar6,puVar5,iVar2,&local_30), iVar3 == 0) {
    iVar3 = Curl_client_write(param_1,2,puVar5,local_30);
    if (iVar3 != 0) goto LAB_00053a46;
    iVar2 = iVar2 - local_30;
    puVar5 = puVar5 + local_30;
    if (iVar2 < 1) {
      (*Curl_cfree)(puVar8,0xffffffff,iVar6);
      iVar6 = Curl_sendf(iVar6,param_1,&DAT_0013c1d4);
      if (iVar6 != 0) {
        Curl_failf(iVar7,"Failed sending Gopher request");
        return iVar6;
      }
      iVar6 = Curl_client_write(param_1,2,&DAT_0013c1d4,2);
      if (iVar6 != 0) {
        return iVar6;
      }
      Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,0,iVar7 + 0x70,0xffffffff,0);
      return 0;
    }
    Curl_socket_check();
  }
  Curl_failf(iVar7,"Failed sending Gopher request");
LAB_00053a46:
  (*Curl_cfree)(puVar8);
  return iVar3;
}


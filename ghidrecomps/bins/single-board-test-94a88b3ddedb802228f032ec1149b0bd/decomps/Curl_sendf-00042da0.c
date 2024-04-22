
int Curl_sendf(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  char *__s;
  size_t sVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  size_t local_38;
  undefined4 *local_34;
  undefined4 uStack_4;
  
  iVar4 = 0x1b;
  local_34 = &uStack_4;
  iVar3 = *param_2;
  uStack_4 = param_4;
  __s = (char *)curl_mvaprintf(param_3,local_34);
  if (__s != (char *)0x0) {
    local_38 = 0;
    sVar1 = strlen(__s);
    pcVar2 = __s;
    do {
      while( true ) {
        iVar4 = Curl_write(param_2,param_1,pcVar2,sVar1,&local_38);
        if (iVar4 != 0) goto LAB_00042e1c;
        if (*(char *)(iVar3 + 0x310) == '\0') break;
        Curl_debug(iVar3,4,pcVar2,local_38,param_2);
        bVar5 = local_38 == sVar1;
        pcVar2 = pcVar2 + local_38;
        sVar1 = sVar1 - local_38;
        if (bVar5) goto LAB_00042e1c;
      }
      bVar5 = local_38 != sVar1;
      pcVar2 = pcVar2 + local_38;
      sVar1 = sVar1 - local_38;
    } while (bVar5);
LAB_00042e1c:
    (**DAT_00042e30)(__s);
  }
  return iVar4;
}


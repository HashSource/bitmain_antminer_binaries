
undefined4 extract_sockaddr(char *param_1,char **param_2,undefined4 *param_3)

{
  undefined2 *__s;
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  size_t sVar8;
  undefined2 local_128;
  undefined local_126;
  char acStack_120 [256];
  
  *param_2 = param_1;
  pcVar2 = strstr(param_1,"//");
  if (pcVar2 != (char *)0x0) {
    param_1 = pcVar2 + 2;
  }
  pcVar3 = strchr(param_1,0x5b);
  pcVar4 = strchr(param_1,0x5d);
  pcVar2 = pcVar4;
  if (pcVar4 <= pcVar3 || (pcVar3 == (char *)0x0 || pcVar4 == (char *)0x0)) {
    pcVar2 = param_1;
  }
  pcVar2 = strchr(pcVar2,0x3a);
  if (pcVar2 == (char *)0x0) {
    sVar8 = strlen(param_1);
    pcVar2 = (char *)0x0;
    iVar7 = 0;
  }
  else {
    sVar8 = (int)pcVar2 - (int)param_1;
    sVar5 = strlen(param_1);
    iVar7 = ~sVar8 + sVar5;
    if (iVar7 < 1) {
      return 0;
    }
    pcVar2 = pcVar2 + 1;
  }
  if ((int)sVar8 < 1) {
    return 0;
  }
  if (pcVar4 > pcVar3 && (pcVar3 != (char *)0x0 && pcVar4 != (char *)0x0)) {
    sVar8 = sVar8 - 2;
    param_1 = param_1 + 1;
  }
  snprintf(acStack_120,0xfe,"%.*s",sVar8,param_1);
  if (iVar7 == 0) {
    local_128 = (undefined2)DAT_00067180;
    local_126 = (undefined)((uint)DAT_00067180 >> 0x10);
  }
  else {
    __s = &local_128;
    snprintf((char *)__s,6,"%.*s",iVar7,pcVar2);
    cVar1 = (char)local_128;
    while (cVar1 != '\0') {
      if (cVar1 == '/' || cVar1 == '#') {
        *(char *)__s = '\0';
        break;
      }
      __s = (undefined2 *)((int)__s + 1);
      cVar1 = *(char *)__s;
    }
  }
  uVar6 = __strdup(&local_128);
  *param_3 = uVar6;
  pcVar2 = (char *)__strdup(acStack_120);
  *param_2 = pcVar2;
  return 1;
}


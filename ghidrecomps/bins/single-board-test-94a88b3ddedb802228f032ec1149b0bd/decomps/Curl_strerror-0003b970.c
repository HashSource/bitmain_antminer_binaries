
char * Curl_strerror(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  char *__s;
  int iVar4;
  
  __s = (char *)(param_1 + 0x2b4);
  piVar1 = __errno_location();
  iVar4 = *piVar1;
  *(undefined *)(param_1 + 0x2b4) = 0;
  iVar2 = __xpg_strerror_r(param_2,__s,0xff);
  if ((iVar2 != 0) && (*(char *)(param_1 + 0x2b4) == '\0')) {
    curl_msnprintf(__s,0xff,DAT_0003b9e8,param_2);
  }
  *(undefined *)(param_1 + 0x3b3) = 0;
  pcVar3 = strrchr(__s,10);
  if ((pcVar3 != (char *)0x0) && (1 < (int)pcVar3 - (int)__s)) {
    *pcVar3 = '\0';
  }
  pcVar3 = strrchr(__s,0xd);
  if ((pcVar3 != (char *)0x0) && (0 < (int)pcVar3 - (int)__s)) {
    *pcVar3 = '\0';
  }
  if (*piVar1 != iVar4) {
    *piVar1 = iVar4;
  }
  return __s;
}


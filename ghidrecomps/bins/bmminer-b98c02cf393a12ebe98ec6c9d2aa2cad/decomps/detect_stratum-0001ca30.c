
int detect_stratum(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = extract_sockaddr(param_2,param_1 + 600,param_1 + 0x248);
  if (iVar1 != 0) {
    iVar2 = strncasecmp(param_2,"stratum+tcp://",0xe);
    if (iVar2 == 0) {
      uVar3 = __strdup(param_2);
      *(undefined4 *)(param_1 + 0xa4) = uVar3;
      *(undefined *)(param_1 + 0x280) = 1;
      *(undefined4 *)(param_1 + 0x240) = *(undefined4 *)(param_1 + 600);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}


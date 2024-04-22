
undefined4 smb_connect(int param_1)

{
  code **ppcVar1;
  int iVar2;
  char *pcVar3;
  char *__s;
  
  if (*(char *)(param_1 + 0x1f1) == '\0') {
    return 0x43;
  }
  memset((void *)(param_1 + 0x3c0),0,0x30);
  ppcVar1 = DAT_00056c14;
  *(undefined4 *)(param_1 + 0x3c0) = 1;
  iVar2 = (**ppcVar1)(0x9000);
  *(int *)(param_1 + 0x3dc) = iVar2;
  if (iVar2 != 0) {
    __s = *(char **)(param_1 + 0x120);
    *(undefined *)(param_1 + 0x1ed) = 0;
    pcVar3 = strchr(__s,0x2f);
    if ((pcVar3 == (char *)0x0) &&
       (pcVar3 = strchr(__s,0x5c), ppcVar1 = DAT_00056c18, pcVar3 == (char *)0x0)) {
      *(char **)(param_1 + 0x3c4) = __s;
      iVar2 = (**ppcVar1)(*(undefined4 *)(param_1 + 0x98));
      *(int *)(param_1 + 0x3c8) = iVar2;
      if (iVar2 != 0) {
        return 0;
      }
    }
    else {
      ppcVar1 = DAT_00056c18;
      *(char **)(param_1 + 0x3c4) = pcVar3 + 1;
      iVar2 = (**ppcVar1)(__s);
      *(int *)(param_1 + 0x3c8) = iVar2;
      if (iVar2 != 0) {
        pcVar3[iVar2 - *(int *)(param_1 + 0x120)] = '\0';
        return 0;
      }
    }
  }
  return 0x1b;
}



undefined4
sasl_digest_get_key_value(char *param_1,char *param_2,int param_3,int param_4,char param_5)

{
  char *pcVar1;
  size_t sVar2;
  char cVar3;
  int iVar4;
  
  pcVar1 = strstr(param_1,param_2);
  if (pcVar1 == (char *)0x0) {
    return 0;
  }
  sVar2 = strlen(param_2);
  cVar3 = pcVar1[sVar2];
  pcVar1 = pcVar1 + sVar2;
  if (cVar3 == '\0') {
    iVar4 = 0;
  }
  else if (cVar3 == param_5) {
    iVar4 = 0;
  }
  else if (param_4 == 1) {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    do {
      *(char *)(param_3 + iVar4) = cVar3;
      iVar4 = iVar4 + 1;
      pcVar1 = pcVar1 + 1;
      cVar3 = *pcVar1;
      if ((cVar3 == '\0') || (cVar3 == param_5)) break;
    } while (iVar4 != param_4 + -1);
  }
  *(undefined *)(param_3 + iVar4) = 0;
  return 1;
}


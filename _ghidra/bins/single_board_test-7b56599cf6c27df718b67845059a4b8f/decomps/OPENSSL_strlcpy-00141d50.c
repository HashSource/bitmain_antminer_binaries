
int OPENSSL_strlcpy(char *param_1,char *param_2,uint param_3)

{
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  
  if (param_3 < 2) {
    iVar6 = 0;
    if (param_3 == 0) {
      iVar6 = 0;
      goto LAB_00141d78;
    }
  }
  else {
    cVar5 = *param_2;
    if (cVar5 == '\0') {
      iVar6 = 0;
    }
    else {
      iVar4 = 0;
      pcVar2 = param_1;
      pcVar1 = param_2 + 1;
      do {
        param_2 = pcVar1;
        iVar4 = iVar4 + 1;
        param_1 = pcVar2 + 1;
        *pcVar2 = cVar5;
        iVar6 = param_3 - 1;
        if (iVar4 == param_3 - 1) break;
        cVar5 = *param_2;
        pcVar2 = param_1;
        pcVar1 = param_2 + 1;
        iVar6 = iVar4;
      } while (cVar5 != '\0');
    }
  }
  *param_1 = '\0';
LAB_00141d78:
  sVar3 = strlen(param_2);
  return sVar3 + iVar6;
}


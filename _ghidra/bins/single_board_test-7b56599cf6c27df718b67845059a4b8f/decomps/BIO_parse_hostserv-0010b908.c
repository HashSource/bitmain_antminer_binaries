
undefined4 BIO_parse_hostserv(char *param_1,int *param_2,int *param_3,int param_4)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  size_t sVar5;
  
  if (*param_1 == '[') {
    pcVar2 = strchr(param_1,0x5d);
    if (pcVar2 == (char *)0x0) goto LAB_0010b968;
    param_1 = param_1 + 1;
    sVar5 = (int)pcVar2 - (int)param_1;
    if (pcVar2[1] != '\0') {
      if (pcVar2[1] != ':') goto LAB_0010b968;
      pcVar2 = pcVar2 + 2;
      pcVar1 = (char *)strlen(pcVar2);
      goto LAB_0010b95c;
    }
LAB_0010b996:
    if (param_2 == (int *)0x0 || param_1 == (char *)0x0) {
      return 1;
    }
    pcVar2 = (char *)0x0;
    pcVar1 = pcVar2;
LAB_0010b9a8:
    if ((sVar5 == 0) || ((sVar5 == 1 && (*param_1 == '*')))) {
      *param_2 = 0;
    }
    else {
      iVar4 = CRYPTO_strndup(param_1,sVar5,"crypto/bio/b_addr.c",0x212);
      *param_2 = iVar4;
      if (iVar4 == 0) goto LAB_0010b9cc;
    }
  }
  else {
    pcVar1 = strrchr(param_1,0x3a);
    pcVar2 = strchr(param_1,0x3a);
    if (pcVar1 != pcVar2) {
      ERR_put_error(0x20,0x88,0x81,"crypto/bio/b_addr.c",0x224);
      return 0;
    }
    if (pcVar1 == (char *)0x0) {
      if (param_4 == 0) {
        sVar5 = strlen(param_1);
        goto LAB_0010b996;
      }
      pcVar1 = (char *)strlen(param_1);
      pcVar2 = param_1;
    }
    else {
      pcVar2 = pcVar1 + 1;
      sVar5 = (int)pcVar1 - (int)param_1;
      pcVar1 = (char *)strlen(pcVar2);
LAB_0010b95c:
      pcVar3 = strchr(pcVar2,0x3a);
      if (pcVar3 != (char *)0x0) {
LAB_0010b968:
        ERR_put_error(0x20,0x88,0x82,"crypto/bio/b_addr.c",0x227);
        return 0;
      }
      if (param_1 != (char *)0x0 && param_2 != (int *)0x0) goto LAB_0010b9a8;
    }
  }
  if (pcVar2 != (char *)0x0 && param_3 != (int *)0x0) {
    if ((pcVar1 == (char *)0x0) || ((pcVar1 == (char *)0x1 && (*pcVar2 == '*')))) {
      *param_3 = 0;
      return 1;
    }
    iVar4 = CRYPTO_strndup(pcVar2,pcVar1,"crypto/bio/b_addr.c",0x21c);
    *param_3 = iVar4;
    if (iVar4 == 0) {
LAB_0010b9cc:
      ERR_put_error(0x20,0x88,0x41,"crypto/bio/b_addr.c",0x22a);
      return 0;
    }
  }
  return 1;
}


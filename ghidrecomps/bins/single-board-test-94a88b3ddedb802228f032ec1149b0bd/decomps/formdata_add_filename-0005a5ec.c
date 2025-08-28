
undefined4
formdata_add_filename(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  char *pcVar2;
  size_t sVar3;
  undefined4 uVar4;
  char *pcVar5;
  char cVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  if (*(char **)(param_1 + 0x2c) == (char *)0x0) {
    pcVar5 = (char *)(*Curl_cstrdup)(*(undefined4 *)(param_1 + 0xc));
    pcVar1 = Curl_cstrdup;
    if (pcVar5 == (char *)0x0) {
      return 0x1b;
    }
    __xpg_basename(pcVar5);
    pcVar9 = (char *)(*pcVar1)();
    (*Curl_cfree)(pcVar5);
    pcVar5 = pcVar9;
    if (pcVar9 == (char *)0x0) {
      return 0x1b;
    }
  }
  else {
    pcVar9 = (char *)0x0;
    pcVar5 = *(char **)(param_1 + 0x2c);
  }
  pcVar2 = strchr(pcVar5,0x5c);
  if ((pcVar2 == (char *)0x0) && (pcVar2 = strchr(pcVar5,0x22), pcVar2 == (char *)0x0)) {
    pcVar2 = (char *)0x0;
  }
  else {
    sVar3 = strlen(pcVar5);
    pcVar2 = (char *)(*Curl_cmalloc)(sVar3 * 2 + 1);
    if (pcVar2 == (char *)0x0) {
      (*Curl_cfree)(pcVar9);
      return 0x1b;
    }
    cVar6 = *pcVar5;
    pcVar8 = pcVar2;
    if (cVar6 != '\0') {
      pcVar5 = pcVar5 + -1;
      do {
        pcVar7 = pcVar8;
        if (cVar6 == '\\' || cVar6 == '\"') {
          pcVar7 = pcVar8 + 1;
          *pcVar8 = '\\';
        }
        pcVar8 = pcVar7 + 1;
        *pcVar7 = pcVar5[1];
        cVar6 = pcVar5[2];
        pcVar5 = pcVar5 + 1;
      } while (cVar6 != '\0');
    }
    *pcVar8 = '\0';
    pcVar5 = pcVar2;
  }
  uVar4 = AddFormDataf(param_2,param_3,"; filename=\"%s\"",pcVar5,param_4);
  (*Curl_cfree)(pcVar2);
  (*Curl_cfree)(pcVar9);
  return uVar4;
}


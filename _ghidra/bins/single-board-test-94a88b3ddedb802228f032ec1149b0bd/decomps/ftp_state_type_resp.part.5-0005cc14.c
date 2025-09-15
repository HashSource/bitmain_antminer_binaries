
int ftp_state_type_resp_part_5(int *param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  undefined1 *puVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  byte *__s;
  
  if (param_2 == 0x13) {
    iVar1 = ftp_state_size();
    return iVar1;
  }
  if (param_2 == 0x14) {
    iVar1 = *param_1;
    if (*(int *)(iVar1 + 0x2e8) == 2) {
      __s = *(byte **)(iVar1 + 0x868c);
      if (__s == (byte *)0x0) {
        pcVar7 = (char *)0x0;
      }
      else {
        pcVar7 = (char *)(uint)*__s;
        if (pcVar7 != (char *)0x0) {
          pcVar7 = strchr((char *)__s,0x2f);
          if (pcVar7 == (char *)0x0) {
            pcVar7 = (char *)0x0;
          }
          else {
            pcVar7 = (char *)(*Curl_cstrdup)(__s);
            if (pcVar7 == (char *)0x0) {
              return 0x1b;
            }
            sVar2 = strlen(pcVar7);
            if ((pcVar7[sVar2 - 1] != '/') && (pcVar3 = strrchr(pcVar7,0x2f), pcVar3 != (char *)0x0)
               ) {
              pcVar3[1] = '\0';
            }
          }
        }
      }
    }
    else {
      pcVar7 = (char *)0x0;
    }
    pcVar3 = *(char **)(iVar1 + 0x350);
    if (pcVar3 == (char *)0x0) {
      if (*(char *)(iVar1 + 0x2fd) == '\0') {
        pcVar3 = "LIST";
      }
      else {
        pcVar3 = "NLST";
      }
    }
    if (pcVar7 == (char *)0x0) {
      puVar4 = &DAT_0013a6fc;
      pcVar5 = "";
    }
    else {
      puVar4 = &DAT_001729cc;
      pcVar5 = pcVar7;
    }
    iVar1 = curl_maprintf("%s%s%s",pcVar3,puVar4,pcVar5);
    if (iVar1 == 0) {
      iVar6 = 0x1b;
      (*Curl_cfree)(pcVar7);
    }
    else {
      iVar6 = Curl_pp_sendf(param_1 + 0xf0,"%s",iVar1);
      (*Curl_cfree)(pcVar7);
      (*Curl_cfree)(iVar1);
      if (iVar6 == 0) {
        param_1[0x10a] = 0x1f;
      }
    }
  }
  else {
    if (param_2 == 0x15) {
      iVar1 = ftp_state_quote(param_1,1,0xd);
      return iVar1;
    }
    if (param_2 == 0x16) {
      iVar1 = ftp_state_quote(param_1,1,0xe);
      return iVar1;
    }
    iVar6 = 0;
  }
  return iVar6;
}


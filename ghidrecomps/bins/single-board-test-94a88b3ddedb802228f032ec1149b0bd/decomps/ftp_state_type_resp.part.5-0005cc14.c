
int ftp_state_type_resp_part_5(int *param_1,int param_2)

{
  code **ppcVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  byte *__s;
  
  if (param_2 == 0x13) {
    iVar2 = ftp_state_size();
    return iVar2;
  }
  if (param_2 == 0x14) {
    iVar2 = *param_1;
    if (*(int *)(iVar2 + 0x2e8) == 2) {
      __s = *(byte **)(iVar2 + 0x868c);
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
            pcVar7 = (char *)(**DAT_0005cd38)(__s);
            if (pcVar7 == (char *)0x0) {
              return 0x1b;
            }
            sVar3 = strlen(pcVar7);
            if ((pcVar7[sVar3 - 1] != '/') && (pcVar4 = strrchr(pcVar7,0x2f), pcVar4 != (char *)0x0)
               ) {
              pcVar4[1] = '\0';
            }
          }
        }
      }
    }
    else {
      pcVar7 = (char *)0x0;
    }
    iVar6 = *(int *)(iVar2 + 0x350);
    if ((*(int *)(iVar2 + 0x350) == 0) && (iVar6 = DAT_0005cd30, *(char *)(iVar2 + 0x2fd) != '\0'))
    {
      iVar6 = DAT_0005cd34;
    }
    pcVar4 = DAT_0005cd40;
    pcVar5 = DAT_0005cd40;
    if (pcVar7 != (char *)0x0) {
      pcVar4 = DAT_0005cd24;
      pcVar5 = pcVar7;
    }
    iVar2 = curl_maprintf(DAT_0005cd28,iVar6,pcVar4,pcVar5);
    ppcVar1 = DAT_0005cd3c;
    if (iVar2 == 0) {
      iVar6 = 0x1b;
      (**DAT_0005cd3c)(pcVar7);
    }
    else {
      iVar6 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cd2c,iVar2);
      (**ppcVar1)(pcVar7);
      (**ppcVar1)(iVar2);
      if (iVar6 == 0) {
        param_1[0x10a] = 0x1f;
      }
    }
  }
  else {
    if (param_2 == 0x15) {
      iVar2 = ftp_state_quote(param_1,1,0xd);
      return iVar2;
    }
    if (param_2 == 0x16) {
      iVar2 = ftp_state_quote(param_1,1,0xe);
      return iVar2;
    }
    iVar6 = 0;
  }
  return iVar6;
}


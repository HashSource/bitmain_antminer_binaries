
int dict_do(int *param_1,undefined1 *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  
  iVar7 = *param_1;
  iVar9 = param_1[0x55];
  pcVar6 = *(char **)(iVar7 + 0x868c);
  *param_2 = 1;
  iVar1 = Curl_raw_nequal(pcVar6,"/MATCH:",7);
  if (((iVar1 == 0) && (iVar1 = Curl_raw_nequal(pcVar6,&DAT_00136fac,3), iVar1 == 0)) &&
     (iVar1 = Curl_raw_nequal(pcVar6,"/FIND:",6), iVar1 == 0)) {
    iVar1 = Curl_raw_nequal(pcVar6,"/DEFINE:",8);
    if (((iVar1 == 0) && (iVar1 = Curl_raw_nequal(pcVar6,&DAT_00137028,3), iVar1 == 0)) &&
       (iVar1 = Curl_raw_nequal(pcVar6,"/LOOKUP:",8), iVar1 == 0)) {
      pcVar6 = strchr(pcVar6,0x2f);
      if (pcVar6 == (char *)0x0) {
        return 0;
      }
      cVar5 = pcVar6[1];
      if (cVar5 != '\0') {
        pcVar3 = pcVar6 + 1;
        pcVar6 = pcVar6 + 2;
        do {
          if (cVar5 == ':') {
            *pcVar3 = ' ';
          }
          cVar5 = *pcVar6;
          pcVar3 = pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar5 != '\0');
      }
      iVar9 = Curl_sendf(iVar9,param_1,"CLIENT libcurl 7.48.0\r\n%s\r\nQUIT\r\n");
      goto joined_r0x00047e64;
    }
    pcVar3 = strchr(pcVar6,0x3a);
    pcVar6 = pcVar3;
    if (pcVar3 == (char *)0x0) {
LAB_00047eda:
      pcVar8 = "default";
      Curl_infof(iVar7,"lookup word is missing\n");
    }
    else {
      pcVar8 = pcVar3 + 1;
      pcVar2 = strchr(pcVar8,0x3a);
      pcVar6 = pcVar2;
      if (pcVar2 != (char *)0x0) {
        pcVar6 = pcVar2 + 1;
        *pcVar2 = '\0';
        pcVar2 = strchr(pcVar6,0x3a);
        if (pcVar2 != (char *)0x0) {
          *pcVar2 = '\0';
        }
      }
      if ((pcVar8 == (char *)0x0) || (pcVar3[1] == '\0')) goto LAB_00047eda;
    }
    if (pcVar6 == (char *)0x0) {
      pcVar6 = "!";
    }
    else if (*pcVar6 == '\0') {
      pcVar6 = "!";
    }
    iVar1 = unescape_word(iVar7,pcVar8);
    if (iVar1 == 0) {
      return 0x1b;
    }
    iVar9 = Curl_sendf(iVar9,param_1,"CLIENT libcurl 7.48.0\r\nDEFINE %s %s\r\nQUIT\r\n",pcVar6,
                       iVar1);
  }
  else {
    pcVar2 = strchr(pcVar6,0x3a);
    pcVar6 = pcVar2;
    pcVar3 = pcVar2;
    if (pcVar2 == (char *)0x0) {
LAB_00047df6:
      pcVar8 = "default";
      Curl_infof(iVar7,"lookup word is missing\n");
      if (pcVar6 != (char *)0x0) goto LAB_00047d86;
LAB_00047e04:
      pcVar6 = "!";
      if (pcVar3 != (char *)0x0) goto LAB_00047d96;
LAB_00047e0c:
      pcVar3 = ".";
    }
    else {
      pcVar8 = pcVar2 + 1;
      pcVar3 = strchr(pcVar8,0x3a);
      pcVar6 = pcVar3;
      if (pcVar3 != (char *)0x0) {
        pcVar6 = pcVar3 + 1;
        *pcVar3 = '\0';
        pcVar4 = strchr(pcVar6,0x3a);
        pcVar3 = pcVar4;
        if (pcVar4 != (char *)0x0) {
          pcVar3 = pcVar4 + 1;
          *pcVar4 = '\0';
          pcVar4 = strchr(pcVar3,0x3a);
          if (pcVar4 != (char *)0x0) {
            *pcVar4 = '\0';
          }
        }
      }
      if ((pcVar8 == (char *)0x0) || (pcVar2[1] == '\0')) goto LAB_00047df6;
      if (pcVar6 == (char *)0x0) goto LAB_00047e04;
LAB_00047d86:
      if (*pcVar6 == '\0') {
        pcVar6 = "!";
      }
      if (pcVar3 == (char *)0x0) goto LAB_00047e0c;
LAB_00047d96:
      if (*pcVar3 == '\0') {
        pcVar3 = ".";
      }
    }
    iVar1 = unescape_word(iVar7,pcVar8);
    if (iVar1 == 0) {
      return 0x1b;
    }
    iVar9 = Curl_sendf(iVar9,param_1,"CLIENT libcurl 7.48.0\r\nMATCH %s %s %s\r\nQUIT\r\n",pcVar6,
                       pcVar3,iVar1);
  }
  (*Curl_cfree)(iVar1);
joined_r0x00047e64:
  if (iVar9 == 0) {
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,0,iVar7 + 0x70,0xffffffff,0);
  }
  else {
    Curl_failf(iVar7,"Failed sending DICT request");
  }
  return iVar9;
}


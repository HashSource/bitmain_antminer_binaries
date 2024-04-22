
int dict_do(int *param_1,undefined *param_2)

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
  iVar1 = Curl_raw_nequal(pcVar6,DAT_00047f18,7);
  if (((iVar1 == 0) && (iVar1 = Curl_raw_nequal(pcVar6,DAT_00047f44,3), iVar1 == 0)) &&
     (iVar1 = Curl_raw_nequal(pcVar6,DAT_00047f48,6), iVar1 == 0)) {
    iVar1 = Curl_raw_nequal(pcVar6,DAT_00047f4c,8);
    if (((iVar1 == 0) && (iVar1 = Curl_raw_nequal(pcVar6,DAT_00047f34,3), iVar1 == 0)) &&
       (iVar1 = Curl_raw_nequal(pcVar6,DAT_00047f38,8), iVar1 == 0)) {
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
      iVar9 = Curl_sendf(iVar9,param_1,DAT_00047f3c);
      goto joined_r0x00047e64;
    }
    pcVar3 = strchr(pcVar6,0x3a);
    pcVar6 = pcVar3;
    if (pcVar3 == (char *)0x0) {
LAB_00047eda:
      pcVar2 = DAT_00047f30;
      Curl_infof(iVar7,DAT_00047f2c);
    }
    else {
      pcVar2 = pcVar3 + 1;
      pcVar8 = strchr(pcVar2,0x3a);
      pcVar6 = pcVar8;
      if (pcVar8 != (char *)0x0) {
        pcVar6 = pcVar8 + 1;
        *pcVar8 = '\0';
        pcVar8 = strchr(pcVar6,0x3a);
        if (pcVar8 != (char *)0x0) {
          *pcVar8 = '\0';
        }
      }
      if ((pcVar2 == (char *)0x0) || (pcVar3[1] == '\0')) goto LAB_00047eda;
    }
    pcVar3 = DAT_00047f1c;
    if ((pcVar6 != (char *)0x0) && (pcVar3 = pcVar6, *pcVar6 == '\0')) {
      pcVar3 = DAT_00047f1c;
    }
    iVar1 = unescape_word(iVar7,pcVar2);
    if (iVar1 == 0) {
      return 0x1b;
    }
    iVar9 = Curl_sendf(iVar9,param_1,DAT_00047f50,pcVar3,iVar1);
  }
  else {
    pcVar2 = strchr(pcVar6,0x3a);
    pcVar6 = pcVar2;
    pcVar3 = pcVar2;
    if (pcVar2 == (char *)0x0) {
LAB_00047df6:
      pcVar8 = DAT_00047f30;
      Curl_infof(iVar7,DAT_00047f2c);
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
    }
    pcVar2 = DAT_00047f1c;
    if ((pcVar6 != (char *)0x0) && (pcVar2 = pcVar6, *pcVar6 == '\0')) {
      pcVar2 = DAT_00047f1c;
    }
    pcVar6 = DAT_00047f20;
    if ((pcVar3 != (char *)0x0) && (pcVar6 = pcVar3, *pcVar3 == '\0')) {
      pcVar6 = DAT_00047f20;
    }
    iVar1 = unescape_word(iVar7,pcVar8);
    if (iVar1 == 0) {
      return 0x1b;
    }
    iVar9 = Curl_sendf(iVar9,param_1,DAT_00047f24,pcVar2,pcVar6,iVar1);
  }
  (**DAT_00047f28)(iVar1);
joined_r0x00047e64:
  if (iVar9 == 0) {
    Curl_setup_transfer(param_1,0,0xffffffff,0xffffffff,0,iVar7 + 0x70,0xffffffff,0);
  }
  else {
    Curl_failf(iVar7,DAT_00047f40);
  }
  return iVar9;
}


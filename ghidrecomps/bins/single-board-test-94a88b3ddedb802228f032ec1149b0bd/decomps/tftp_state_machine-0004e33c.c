
undefined4 tftp_state_machine(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char *__s;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  char *pcVar10;
  undefined2 local_58 [32];
  
  iVar9 = *(int *)param_1[4];
  switch(*param_1) {
  case 0:
    pcVar8 = DAT_0004e5b8;
    if (*(char *)(iVar9 + 0x2fb) == '\0') {
      pcVar8 = DAT_0004e5bc;
    }
    switch(param_2) {
    case 0:
    case 7:
      iVar6 = param_1[6];
      param_1[6] = iVar6 + 1;
      if ((int)param_1[8] < iVar6 + 1) {
        param_1[2] = 0xffffff9e;
        *param_1 = 3;
        return 0;
      }
      if (*(char *)(iVar9 + 0x309) == '\0') {
        *(undefined *)param_1[0x53] = 0;
        *(undefined *)(param_1[0x53] + 1) = 1;
        piVar5 = (int *)param_1[4];
      }
      else {
        *(undefined *)param_1[0x53] = 0;
        *(undefined *)(param_1[0x53] + 1) = 2;
        piVar5 = (int *)param_1[4];
        iVar6 = *(int *)(iVar9 + 0x86b0);
        iVar7 = *(int *)(iVar9 + 0x86b4);
        *(int *)(*piVar5 + 0x144) = param_1[0x53] + 4;
        if (iVar7 != -1 || iVar6 != -1) {
          Curl_pgrsSetUploadSize(iVar9);
          piVar5 = (int *)param_1[4];
        }
      }
      __s = (char *)curl_easy_unescape(iVar9,*(int *)(*piVar5 + 0x868c) + 1,0,0);
      if (__s == (char *)0x0) {
        return 0x1b;
      }
      iVar6 = 0;
      uVar1 = 0;
      pcVar10 = pcVar8;
      curl_msnprintf(param_1[0x53] + 2,param_1[0x50],DAT_0004e5cc,__s,0,pcVar8,0);
      sVar2 = strlen(__s);
      sVar3 = strlen(pcVar8);
      sVar2 = sVar3 + sVar2 + 4;
      if (*(char *)(iVar9 + 0x214) == '\0') {
        if (*(char *)(iVar9 + 0x309) == '\0') {
LAB_0004e5a6:
          local_58[0] = 0x30;
        }
        else {
          iVar7 = *(int *)(iVar9 + 0x86b0);
          pcVar8 = *(char **)(iVar9 + 0x86b4);
          if (pcVar8 == (char *)0xffffffff && iVar7 == -1) goto LAB_0004e5a6;
          curl_msnprintf(local_58,0x40,DAT_0004e5d0,pcVar8,iVar7,pcVar8,uVar1);
          iVar6 = iVar7;
          pcVar10 = pcVar8;
        }
        iVar7 = tftp_option_add(param_1,sVar2,param_1[0x53] + sVar2,DAT_0004e5d4);
        iVar7 = sVar2 + iVar7;
        iVar4 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,local_58);
        iVar7 = iVar7 + iVar4;
        curl_msnprintf(local_58,0x40,DAT_0004e5d8,param_1[0x51],iVar6,pcVar10);
        iVar6 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,DAT_0004e5dc);
        iVar7 = iVar7 + iVar6;
        iVar6 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,local_58);
        iVar7 = iVar7 + iVar6;
        curl_msnprintf(local_58,0x40,DAT_0004e5d8,param_1[7]);
        iVar6 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,DAT_0004e5e0);
        iVar7 = iVar7 + iVar6;
        iVar6 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,local_58);
        sVar2 = iVar7 + iVar6;
      }
      sVar3 = sendto(param_1[5],(void *)param_1[0x53],sVar2,0,
                     *(sockaddr **)(*(int *)(param_1[4] + 0x4c) + 0x18),
                     *(socklen_t *)(*(int *)(param_1[4] + 0x4c) + 0x10));
      if (sVar3 != sVar2) {
        piVar5 = __errno_location();
        uVar1 = Curl_strerror(param_1[4],*piVar5);
        Curl_failf(iVar9,DAT_0004e5c0,uVar1);
      }
      (**DAT_0004e5e4)(__s);
      uVar1 = 0;
      break;
    default:
      Curl_failf(iVar9,DAT_0004e5c8);
      uVar1 = 0;
      break;
    case 3:
      uVar1 = 3;
      goto LAB_0004e572;
    case 4:
      uVar1 = 4;
LAB_0004e3b8:
      uVar1 = tftp_connect_for_tx(param_1,uVar1);
      break;
    case 5:
      uVar1 = 0;
      *param_1 = 3;
      break;
    case 6:
      uVar1 = 6;
      if (*(char *)(iVar9 + 0x309) != '\0') goto LAB_0004e3b8;
LAB_0004e572:
      uVar1 = tftp_connect_for_rx(param_1,uVar1);
    }
    break;
  case 1:
    uVar1 = tftp_rx();
    break;
  case 2:
    uVar1 = tftp_tx();
    break;
  case 3:
    Curl_infof(iVar9,DAT_0004e5b0,DAT_0004e5b4);
    uVar1 = 0;
    break;
  default:
    Curl_failf(iVar9,DAT_0004e5c0,DAT_0004e5c4);
    uVar1 = 0x47;
  }
  return uVar1;
}


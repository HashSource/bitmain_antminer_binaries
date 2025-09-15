
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
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  undefined2 local_58 [32];
  
  iVar8 = *(int *)param_1[4];
  switch(*param_1) {
  case 0:
    if (*(char *)(iVar8 + 0x2fb) == '\0') {
      pcVar9 = "octet";
    }
    else {
      pcVar9 = "netascii";
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
      if (*(char *)(iVar8 + 0x309) == '\0') {
        *(undefined1 *)param_1[0x53] = 0;
        *(undefined1 *)(param_1[0x53] + 1) = 1;
        piVar5 = (int *)param_1[4];
      }
      else {
        *(undefined1 *)param_1[0x53] = 0;
        *(undefined1 *)(param_1[0x53] + 1) = 2;
        piVar5 = (int *)param_1[4];
        iVar6 = *(int *)(iVar8 + 0x86b0);
        iVar7 = *(int *)(iVar8 + 0x86b4);
        *(int *)(*piVar5 + 0x144) = param_1[0x53] + 4;
        if (iVar7 != -1 || iVar6 != -1) {
          Curl_pgrsSetUploadSize(iVar8);
          piVar5 = (int *)param_1[4];
        }
      }
      __s = (char *)curl_easy_unescape(iVar8,*(int *)(*piVar5 + 0x868c) + 1,0,0);
      if (__s == (char *)0x0) {
        return 0x1b;
      }
      iVar6 = 0;
      uVar1 = 0;
      pcVar10 = pcVar9;
      curl_msnprintf(param_1[0x53] + 2,param_1[0x50],&DAT_001386d4,__s,0,pcVar9,0);
      sVar2 = strlen(__s);
      sVar3 = strlen(pcVar9);
      sVar2 = sVar3 + sVar2 + 4;
      if (*(char *)(iVar8 + 0x214) == '\0') {
        if (*(char *)(iVar8 + 0x309) == '\0') {
LAB_0004e5a6:
          local_58[0] = 0x30;
        }
        else {
          iVar7 = *(int *)(iVar8 + 0x86b0);
          pcVar9 = *(char **)(iVar8 + 0x86b4);
          if (pcVar9 == (char *)0xffffffff && iVar7 == -1) goto LAB_0004e5a6;
          curl_msnprintf(local_58,0x40,&DAT_001386e0,pcVar9,iVar7,pcVar9,uVar1);
          iVar6 = iVar7;
          pcVar10 = pcVar9;
        }
        iVar7 = tftp_option_add(param_1,sVar2,param_1[0x53] + sVar2,"tsize");
        iVar7 = sVar2 + iVar7;
        iVar4 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,local_58);
        iVar7 = iVar7 + iVar4;
        curl_msnprintf(local_58,0x40,"%d",param_1[0x51],iVar6,pcVar10);
        iVar6 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,"blksize");
        iVar7 = iVar7 + iVar6;
        iVar6 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,local_58);
        iVar7 = iVar7 + iVar6;
        curl_msnprintf(local_58,0x40,"%d",param_1[7]);
        iVar6 = tftp_option_add(param_1,iVar7,param_1[0x53] + iVar7,"timeout");
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
        Curl_failf(iVar8,"%s",uVar1);
      }
      (*Curl_cfree)(__s);
      uVar1 = 0;
      break;
    default:
      Curl_failf(iVar8,"tftp_send_first: internal error");
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
      if (*(char *)(iVar8 + 0x309) != '\0') goto LAB_0004e3b8;
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
    Curl_infof(iVar8,"%s\n","TFTP finished");
    uVar1 = 0;
    break;
  default:
    Curl_failf(iVar8,"%s","Internal state machine error");
    uVar1 = 0x47;
  }
  return uVar1;
}


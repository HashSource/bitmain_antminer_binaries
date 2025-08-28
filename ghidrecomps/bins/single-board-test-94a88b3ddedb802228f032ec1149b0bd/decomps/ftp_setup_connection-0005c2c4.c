
undefined4 ftp_setup_connection(int *param_1)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  iVar7 = *param_1;
  if (((char)param_1[0x7c] != '\0') && (*(char *)(iVar7 + 0x2fa) == '\0')) {
    bVar9 = (undefined1 *)param_1[0x86] != Curl_handler_ftp;
    if (bVar9) {
      puVar6 = Curl_handler_ftps_proxy;
      puVar1 = puVar6;
    }
    else {
      puVar6 = Curl_handler_ftp_proxy;
      puVar1 = Curl_handler_ftp;
    }
    if (bVar9) {
      param_1[0x86] = (int)puVar1;
    }
    if (!bVar9) {
      param_1[0x86] = (int)puVar6;
    }
    uVar2 = (**(code **)(puVar6 + 4))();
    return uVar2;
  }
  piVar3 = (int *)(*Curl_cmalloc)(0x18);
  *(int **)(iVar7 + 0x14c) = piVar3;
  if (piVar3 == (int *)0x0) {
    return 0x1b;
  }
  *(undefined1 *)(iVar7 + 0x8690) = 1;
  pcVar4 = (char *)(*(int *)(iVar7 + 0x868c) + 1);
  *(char **)(iVar7 + 0x868c) = pcVar4;
  pcVar4 = strstr(pcVar4,";type=");
  if ((pcVar4 != (char *)0x0) ||
     (pcVar4 = strstr((char *)param_1[0x24],";type="), pcVar4 != (char *)0x0)) {
    *pcVar4 = '\0';
    iVar5 = Curl_raw_toupper(pcVar4[6]);
    *(undefined1 *)(param_1 + 0x81) = 1;
    if (iVar5 == 0x41) {
      *(undefined1 *)(iVar7 + 0x2fb) = 1;
    }
    else if (iVar5 == 0x44) {
      *(undefined1 *)(iVar7 + 0x2fd) = 1;
    }
    else {
      *(undefined1 *)(iVar7 + 0x2fb) = 0;
    }
  }
  iVar7 = *param_1;
  iVar5 = param_1[0x48];
  iVar8 = param_1[0x49];
  piVar3[3] = 0;
  *piVar3 = iVar7 + 0x70;
  piVar3[1] = iVar5;
  piVar3[2] = iVar8;
  piVar3[4] = 0;
  piVar3[5] = 0;
  iVar7 = isBadFtpString(iVar5);
  if ((iVar7 == 0) && (iVar7 = isBadFtpString(iVar8), iVar7 == 0)) {
    param_1[0x110] = -1;
    param_1[0x111] = -1;
    return 0;
  }
  return 3;
}


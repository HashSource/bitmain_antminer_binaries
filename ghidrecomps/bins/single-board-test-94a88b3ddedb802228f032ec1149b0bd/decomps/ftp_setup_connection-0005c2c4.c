
undefined4 ftp_setup_connection(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  char *__haystack;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar5 = *param_1;
  if ((*(char *)(param_1 + 0x7c) != '\0') && (*(char *)(iVar5 + 0x2fa) == '\0')) {
    bVar7 = param_1[0x86] != DAT_0005c3b0;
    if (bVar7) {
      iVar4 = DAT_0005c3b0 + -0x44;
      iVar5 = iVar4;
    }
    else {
      iVar4 = param_1[0x86] + -0x88;
      iVar5 = DAT_0005c3b0;
    }
    if (bVar7) {
      param_1[0x86] = iVar5;
    }
    if (!bVar7) {
      param_1[0x86] = iVar4;
    }
    uVar1 = (**(code **)(iVar4 + 4))();
    return uVar1;
  }
  piVar2 = (int *)(**DAT_0005c3b4)(0x18);
  *(int **)(iVar5 + 0x14c) = piVar2;
  if (piVar2 == (int *)0x0) {
    return 0x1b;
  }
  *(undefined *)(iVar5 + 0x8690) = 1;
  pcVar3 = DAT_0005c3b8;
  __haystack = (char *)(*(int *)(iVar5 + 0x868c) + 1);
  *(char **)(iVar5 + 0x868c) = __haystack;
  pcVar3 = strstr(__haystack,pcVar3);
  if ((pcVar3 != (char *)0x0) ||
     (pcVar3 = strstr((char *)param_1[0x24],DAT_0005c3b8), pcVar3 != (char *)0x0)) {
    *pcVar3 = '\0';
    iVar4 = Curl_raw_toupper(pcVar3[6]);
    *(undefined *)(param_1 + 0x81) = 1;
    if (iVar4 == 0x41) {
      *(undefined *)(iVar5 + 0x2fb) = 1;
    }
    else if (iVar4 == 0x44) {
      *(undefined *)(iVar5 + 0x2fd) = 1;
    }
    else {
      *(undefined *)(iVar5 + 0x2fb) = 0;
    }
  }
  iVar5 = *param_1;
  iVar4 = param_1[0x48];
  iVar6 = param_1[0x49];
  piVar2[3] = 0;
  *piVar2 = iVar5 + 0x70;
  piVar2[1] = iVar4;
  piVar2[2] = iVar6;
  piVar2[4] = 0;
  piVar2[5] = 0;
  iVar5 = isBadFtpString(iVar4);
  if ((iVar5 == 0) && (iVar5 = isBadFtpString(iVar6), iVar5 == 0)) {
    param_1[0x110] = -1;
    param_1[0x111] = -1;
    return 0;
  }
  return 3;
}


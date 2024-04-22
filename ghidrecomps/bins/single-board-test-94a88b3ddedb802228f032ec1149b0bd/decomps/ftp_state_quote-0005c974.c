
int ftp_state_quote(int *param_1,int param_2,uint param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r1;
  int iVar5;
  char *pcVar6;
  char **ppcVar7;
  
  iVar3 = *param_1;
  iVar5 = *(int *)(iVar3 + 0x14c);
  if (param_3 < 0xd) {
LAB_0005c984:
    ppcVar7 = *(char ***)(iVar3 + 0x250);
  }
  else if (param_3 < 0xf) {
    ppcVar7 = *(char ***)(iVar3 + 600);
  }
  else {
    if (param_3 != 0xf) goto LAB_0005c984;
    ppcVar7 = *(char ***)(iVar3 + 0x254);
  }
  if (param_2 == 0) {
    param_1[0x107] = param_1[0x107] + 1;
  }
  else {
    param_1[0x107] = 0;
  }
  uVar2 = DAT_0005cae4;
  if (ppcVar7 != (char **)0x0) {
    if (param_1[0x107] < 1) {
LAB_0005c9ac:
      pcVar6 = *ppcVar7;
      cVar1 = *pcVar6;
      if (cVar1 == '*') {
        pcVar6 = pcVar6 + 1;
      }
      param_1[0x108] = (uint)(cVar1 == '*');
      iVar3 = Curl_pp_sendf(param_1 + 0xf0,uVar2,pcVar6);
      if (iVar3 != 0) {
        return iVar3;
      }
      param_1[0x10a] = param_3;
      return 0;
    }
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      ppcVar7 = (char **)ppcVar7[1];
      if (iVar4 == param_1[0x107]) {
        if (ppcVar7 != (char **)0x0) goto LAB_0005c9ac;
        break;
      }
    } while (ppcVar7 != (char **)0x0);
  }
  if (param_3 == 0xe) {
    iVar3 = ftp_state_ul_setup(param_1,0);
    return iVar3;
  }
  if (param_3 == 0xf) {
    return 0;
  }
  if (param_3 == 0xd) {
    if (*(int *)(iVar5 + 0xc) != 0) {
      param_1[0x10a] = 0;
      return 0;
    }
    if (param_1[0x111] != -1 || param_1[0x110] != -1) {
      Curl_pgrsSetDownloadSize();
      iVar3 = ftp_state_retr(param_1,extraout_r1,param_1[0x110],param_1[0x111]);
      return iVar3;
    }
    if (*(char *)(iVar3 + 0x327) == '\0') {
      iVar3 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005caf0,param_1[0x102]);
      if (iVar3 == 0) {
        param_1[0x10a] = 0x18;
        return 0;
      }
    }
    else {
      iVar3 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005caec,param_1[0x102]);
      if (iVar3 == 0) {
        param_1[0x10a] = 0x20;
        return 0;
      }
    }
  }
  else {
    if (*(char *)((int)param_1 + 0x40e) != '\0') {
LAB_0005caa4:
      iVar3 = ftp_state_mdtm(param_1);
      return iVar3;
    }
    iVar3 = *(int *)(iVar3 + 0x2ec);
    param_1[0x108] = 0;
    param_1[0x109] = (uint)(iVar3 == 2);
    if ((*(char *)((int)param_1 + 0x1ee) == '\0') || (param_1[0xfe] == 0)) {
      if (param_1[0x100] == 0) goto LAB_0005caa4;
      param_1[0x107] = 1;
      iVar3 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cae8,*(undefined4 *)param_1[0xff]);
    }
    else {
      param_1[0x107] = 0;
      iVar3 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cae8);
    }
    if (iVar3 == 0) {
      param_1[0x10a] = 0x10;
      return 0;
    }
  }
  return iVar3;
}


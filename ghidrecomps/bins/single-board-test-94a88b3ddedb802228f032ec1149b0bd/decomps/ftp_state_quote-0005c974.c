
int ftp_state_quote(int *param_1,int param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_r1;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  
  iVar2 = *param_1;
  iVar4 = *(int *)(iVar2 + 0x14c);
  if (param_3 < 0xd) {
LAB_0005c984:
    puVar6 = *(undefined4 **)(iVar2 + 0x250);
  }
  else if (param_3 < 0xf) {
    puVar6 = *(undefined4 **)(iVar2 + 600);
  }
  else {
    if (param_3 != 0xf) goto LAB_0005c984;
    puVar6 = *(undefined4 **)(iVar2 + 0x254);
  }
  if (param_2 == 0) {
    param_1[0x107] = param_1[0x107] + 1;
  }
  else {
    param_1[0x107] = 0;
  }
  if (puVar6 != (undefined4 *)0x0) {
    if (param_1[0x107] < 1) {
LAB_0005c9ac:
      pcVar5 = (char *)*puVar6;
      cVar1 = *pcVar5;
      if (cVar1 == '*') {
        pcVar5 = pcVar5 + 1;
      }
      param_1[0x108] = (uint)(cVar1 == '*');
      iVar2 = Curl_pp_sendf(param_1 + 0xf0,"%s",pcVar5);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_1[0x10a] = param_3;
      return 0;
    }
    iVar3 = 0;
    do {
      iVar3 = iVar3 + 1;
      puVar6 = (undefined4 *)puVar6[1];
      if (iVar3 == param_1[0x107]) {
        if (puVar6 != (undefined4 *)0x0) goto LAB_0005c9ac;
        break;
      }
    } while (puVar6 != (undefined4 *)0x0);
  }
  if (param_3 == 0xe) {
    iVar2 = ftp_state_ul_setup(param_1,0);
    return iVar2;
  }
  if (param_3 == 0xf) {
    return 0;
  }
  if (param_3 == 0xd) {
    if (*(int *)(iVar4 + 0xc) != 0) {
      param_1[0x10a] = 0;
      return 0;
    }
    if (param_1[0x111] != -1 || param_1[0x110] != -1) {
      Curl_pgrsSetDownloadSize();
      iVar2 = ftp_state_retr(param_1,extraout_r1,param_1[0x110],param_1[0x111]);
      return iVar2;
    }
    if (*(char *)(iVar2 + 0x327) == '\0') {
      iVar2 = Curl_pp_sendf(param_1 + 0xf0,"SIZE %s",param_1[0x102]);
      if (iVar2 == 0) {
        param_1[0x10a] = 0x18;
        return 0;
      }
    }
    else {
      iVar2 = Curl_pp_sendf(param_1 + 0xf0,"RETR %s",param_1[0x102]);
      if (iVar2 == 0) {
        param_1[0x10a] = 0x20;
        return 0;
      }
    }
  }
  else {
    if (*(char *)((int)param_1 + 0x40e) != '\0') {
LAB_0005caa4:
      iVar2 = ftp_state_mdtm(param_1);
      return iVar2;
    }
    iVar2 = *(int *)(iVar2 + 0x2ec);
    param_1[0x108] = 0;
    param_1[0x109] = (uint)(iVar2 == 2);
    if ((*(char *)((int)param_1 + 0x1ee) == '\0') || (param_1[0xfe] == 0)) {
      if (param_1[0x100] == 0) goto LAB_0005caa4;
      param_1[0x107] = 1;
      iVar2 = Curl_pp_sendf(param_1 + 0xf0,"CWD %s",*(undefined4 *)param_1[0xff]);
    }
    else {
      param_1[0x107] = 0;
      iVar2 = Curl_pp_sendf(param_1 + 0xf0,"CWD %s");
    }
    if (iVar2 == 0) {
      param_1[0x10a] = 0x10;
      return 0;
    }
  }
  return iVar2;
}


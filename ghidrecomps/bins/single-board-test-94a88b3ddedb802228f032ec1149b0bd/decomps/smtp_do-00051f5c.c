
int smtp_do(int *param_1,char *param_2)

{
  char cVar1;
  code **ppcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  char *pcVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  undefined8 uVar11;
  longlong lVar12;
  
  iVar8 = *param_1;
  *param_2 = '\0';
  iVar4 = *(int *)(iVar8 + 0x350);
  if (iVar4 != 0) {
    uVar11 = Curl_urldecode(iVar8,iVar4,0,*(int *)(iVar8 + 0x14c) + 4,0,1);
    iVar4 = (int)((ulonglong)uVar11 >> 0x20);
    if ((int)uVar11 != 0) {
      return (int)uVar11;
    }
    iVar8 = *param_1;
  }
  *(undefined4 *)(iVar8 + 0x50) = 0xffffffff;
  *(undefined4 *)(iVar8 + 0x54) = 0xffffffff;
  Curl_pgrsSetUploadCounter(iVar8,iVar4,0,0);
  Curl_pgrsSetDownloadCounter(iVar8,extraout_r1,0,0);
  Curl_pgrsSetUploadSize(iVar8,extraout_r1_00,0xffffffff,0xffffffff);
  Curl_pgrsSetDownloadSize(iVar8,extraout_r1_01,0xffffffff,0xffffffff);
  iVar4 = *param_1;
  puVar6 = *(undefined4 **)(iVar4 + 0x14c);
  if (*(char *)(iVar4 + 0x307) != '\0') {
    *puVar6 = 1;
  }
  iVar8 = *(int *)(iVar4 + 0x404);
  *param_2 = '\0';
  cVar1 = *(char *)(iVar4 + 0x309);
  puVar6[2] = iVar8;
  if ((cVar1 == '\0') || (iVar8 == 0)) {
    iVar4 = smtp_perform_command(param_1);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  else {
    if (*(char **)(iVar4 + 0x3d8) == (char *)0x0) {
      iVar8 = (**DAT_00052164)(DAT_00052168);
    }
    else {
      uVar3 = DAT_0005214c;
      if (**(char **)(iVar4 + 0x3d8) != '<') {
        uVar3 = DAT_00052150;
      }
      iVar8 = curl_maprintf(uVar3);
    }
    if (iVar8 == 0) {
      return 0x1b;
    }
    pcVar5 = *(char **)(iVar4 + 0x3dc);
    if (pcVar5 == (char *)0x0) {
      lVar12 = 0;
    }
    else if (param_1[0x105] == 0) {
      lVar12 = ZEXT48(pcVar5) << 0x20;
    }
    else {
      if (*pcVar5 == '\0') {
        lVar12 = (**DAT_00052164)(DAT_00052168);
      }
      else {
        lVar12 = curl_maprintf(DAT_0005214c);
      }
      if ((int)lVar12 == 0) {
        (**DAT_00052154)(iVar8);
        return 0x1b;
      }
    }
    iVar9 = (int)lVar12;
    if ((*(char *)((int)param_1 + 0x41d) == '\0') ||
       (iVar7 = *(int *)(*param_1 + 0x86b4), bVar10 = *(int *)(*param_1 + 0x86b0) == 0,
       (int)(iVar7 - (uint)bVar10) < 0 != (SBORROW4(iVar7,(uint)bVar10) != false))) {
      if (iVar9 == 0) {
        iVar7 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005216c,iVar8);
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        iVar7 = Curl_pp_sendf(param_1 + 0xf0,DAT_00052160,iVar8,iVar9);
      }
    }
    else {
      iVar4 = curl_maprintf(DAT_00052158,(int)((ulonglong)lVar12 >> 0x20),
                            *(undefined4 *)(iVar4 + 0x86b0),*(undefined4 *)(iVar4 + 0x86b4));
      ppcVar2 = DAT_00052154;
      if (iVar4 == 0) {
        (**DAT_00052154)(iVar8);
        (**ppcVar2)(iVar9);
        return 0x1b;
      }
      if (iVar9 == 0) {
        iVar7 = Curl_pp_sendf(param_1 + 0xf0,DAT_00052170,iVar8,iVar4);
      }
      else {
        iVar7 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005215c,iVar8,iVar9,iVar4);
      }
    }
    ppcVar2 = DAT_00052154;
    (**DAT_00052154)(iVar8);
    (**ppcVar2)(iVar9);
    (**ppcVar2)(iVar4);
    if (iVar7 != 0) {
      return iVar7;
    }
    param_1[0xfe] = 8;
  }
  iVar4 = smtp_multi_statemach(param_1,param_2);
  if (((iVar4 == 0) && (*param_2 != '\0')) && (**(int **)(*param_1 + 0x14c) != 0)) {
    smtp_dophase_done_isra_3_part_4(param_1);
  }
  return iVar4;
}


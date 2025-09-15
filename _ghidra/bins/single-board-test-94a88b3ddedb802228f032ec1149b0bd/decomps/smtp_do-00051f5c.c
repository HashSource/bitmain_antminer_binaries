
int smtp_do(int *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  longlong lVar9;
  
  iVar6 = *param_1;
  *param_2 = '\0';
  iVar4 = *(int *)(iVar6 + 0x350);
  if (iVar4 != 0) {
    uVar8 = Curl_urldecode(iVar6,iVar4,0,*(int *)(iVar6 + 0x14c) + 4,0,1);
    iVar4 = (int)((ulonglong)uVar8 >> 0x20);
    if ((int)uVar8 != 0) {
      return (int)uVar8;
    }
    iVar6 = *param_1;
  }
  *(undefined4 *)(iVar6 + 0x50) = 0xffffffff;
  *(undefined4 *)(iVar6 + 0x54) = 0xffffffff;
  Curl_pgrsSetUploadCounter(iVar6,iVar4,0,0);
  Curl_pgrsSetDownloadCounter(iVar6,extraout_r1,0,0);
  Curl_pgrsSetUploadSize(iVar6,extraout_r1_00,0xffffffff,0xffffffff);
  Curl_pgrsSetDownloadSize(iVar6,extraout_r1_01,0xffffffff,0xffffffff);
  iVar4 = *param_1;
  puVar5 = *(undefined4 **)(iVar4 + 0x14c);
  if (*(char *)(iVar4 + 0x307) != '\0') {
    *puVar5 = 1;
  }
  iVar6 = *(int *)(iVar4 + 0x404);
  *param_2 = '\0';
  cVar1 = *(char *)(iVar4 + 0x309);
  puVar5[2] = iVar6;
  if ((cVar1 == '\0') || (iVar6 == 0)) {
    iVar4 = smtp_perform_command(param_1);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  else {
    if (*(char **)(iVar4 + 0x3d8) == (char *)0x0) {
      iVar6 = (*Curl_cstrdup)(&DAT_001399b0);
    }
    else {
      if (**(char **)(iVar4 + 0x3d8) == '<') {
        pcVar2 = "%s";
      }
      else {
        pcVar2 = "<%s>";
      }
      iVar6 = curl_maprintf(pcVar2);
    }
    if (iVar6 == 0) {
      return 0x1b;
    }
    pcVar2 = *(char **)(iVar4 + 0x3dc);
    if (pcVar2 == (char *)0x0) {
      lVar9 = 0;
    }
    else if (param_1[0x105] == 0) {
      lVar9 = ZEXT48(pcVar2) << 0x20;
    }
    else {
      if (*pcVar2 == '\0') {
        lVar9 = (*Curl_cstrdup)(&DAT_001399b0);
      }
      else {
        lVar9 = curl_maprintf("%s");
      }
      if ((int)lVar9 == 0) {
        (*Curl_cfree)(iVar6);
        return 0x1b;
      }
    }
    iVar7 = (int)lVar9;
    if ((*(char *)((int)param_1 + 0x41d) == '\0') ||
       (*(int *)(*param_1 + 0x86b4) < (int)(uint)(*(int *)(*param_1 + 0x86b0) == 0))) {
      if (iVar7 == 0) {
        iVar3 = Curl_pp_sendf(param_1 + 0xf0,"MAIL FROM:%s",iVar6);
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        iVar3 = Curl_pp_sendf(param_1 + 0xf0,"MAIL FROM:%s AUTH=%s",iVar6,iVar7);
      }
    }
    else {
      iVar4 = curl_maprintf(&DAT_001386e0,(int)((ulonglong)lVar9 >> 0x20),
                            *(undefined4 *)(iVar4 + 0x86b0),*(undefined4 *)(iVar4 + 0x86b4));
      if (iVar4 == 0) {
        (*Curl_cfree)(iVar6);
        (*Curl_cfree)(iVar7);
        return 0x1b;
      }
      if (iVar7 == 0) {
        iVar3 = Curl_pp_sendf(param_1 + 0xf0,"MAIL FROM:%s SIZE=%s",iVar6,iVar4);
      }
      else {
        iVar3 = Curl_pp_sendf(param_1 + 0xf0,"MAIL FROM:%s AUTH=%s SIZE=%s",iVar6,iVar7,iVar4);
      }
    }
    (*Curl_cfree)(iVar6);
    (*Curl_cfree)(iVar7);
    (*Curl_cfree)(iVar4);
    if (iVar3 != 0) {
      return iVar3;
    }
    param_1[0xfe] = 8;
  }
  iVar4 = smtp_multi_statemach(param_1,param_2);
  if (((iVar4 == 0) && (*param_2 != '\0')) && (**(int **)(*param_1 + 0x14c) != 0)) {
    smtp_dophase_done_isra_3_part_4(param_1);
  }
  return iVar4;
}


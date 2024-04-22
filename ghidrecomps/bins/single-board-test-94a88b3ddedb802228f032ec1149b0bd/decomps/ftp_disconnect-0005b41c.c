
undefined4 ftp_disconnect(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  code **ppcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  int *piVar6;
  bool bVar7;
  
  piVar6 = param_1 + 0xf0;
  if (param_2 == 0) {
    if (*(char *)((int)param_1 + 0x40d) != '\0') {
      iVar2 = Curl_pp_sendf(piVar6,DAT_0005b4cc,DAT_0005b4d0,*(char *)((int)param_1 + 0x40d),param_4
                           );
      if (iVar2 == 0) {
        param_1[0x10a] = 0x22;
        do {
          iVar2 = Curl_pp_statemach(piVar6,1);
          if (iVar2 != 0) break;
        } while (param_1[0x10a] != 0);
      }
      else {
        iVar2 = *param_1;
        uVar3 = curl_easy_strerror();
        Curl_failf(iVar2,DAT_0005b4d8,uVar3);
        *(undefined *)((int)param_1 + 0x40d) = 0;
        param_1[0x10a] = 0;
        *(undefined *)((int)param_1 + 0x1ed) = 1;
      }
    }
  }
  else {
    *(undefined *)((int)param_1 + 0x40d) = 0;
  }
  ppcVar1 = DAT_0005b4d4;
  iVar2 = param_1[0xfe];
  if (iVar2 != 0) {
    iVar4 = *(int *)(*param_1 + 0x8670);
    bVar7 = iVar2 == iVar4;
    if (bVar7) {
      iVar4 = 0;
    }
    if (bVar7) {
      *(int *)(*param_1 + 0x8670) = iVar4;
    }
    (**ppcVar1)();
    param_1[0xfe] = 0;
  }
  freedirs(piVar6);
  (**ppcVar1)(param_1[0x105]);
  pcVar5 = *ppcVar1;
  param_1[0x105] = 0;
  (*pcVar5)(param_1[0x10e]);
  param_1[0x10e] = 0;
  Curl_pp_disconnect(piVar6);
  return 0;
}


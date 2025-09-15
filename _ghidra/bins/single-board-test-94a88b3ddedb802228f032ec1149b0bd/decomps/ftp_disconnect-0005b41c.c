
undefined4 ftp_disconnect(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  bool bVar6;
  
  piVar5 = param_1 + 0xf0;
  if (param_2 == 0) {
    if (*(char *)((int)param_1 + 0x40d) != '\0') {
      iVar2 = Curl_pp_sendf(piVar5,"%s",&DAT_00139768,*(char *)((int)param_1 + 0x40d),param_4);
      if (iVar2 == 0) {
        param_1[0x10a] = 0x22;
        do {
          iVar2 = Curl_pp_statemach(piVar5,1);
          if (iVar2 != 0) break;
        } while (param_1[0x10a] != 0);
      }
      else {
        iVar2 = *param_1;
        uVar3 = curl_easy_strerror();
        Curl_failf(iVar2,"Failure sending QUIT command: %s",uVar3);
        *(undefined1 *)((int)param_1 + 0x40d) = 0;
        param_1[0x10a] = 0;
        *(undefined1 *)((int)param_1 + 0x1ed) = 1;
      }
    }
  }
  else {
    *(undefined1 *)((int)param_1 + 0x40d) = 0;
  }
  iVar2 = param_1[0xfe];
  if (iVar2 != 0) {
    iVar4 = *(int *)(*param_1 + 0x8670);
    bVar6 = iVar2 == iVar4;
    if (bVar6) {
      iVar4 = 0;
    }
    if (bVar6) {
      *(int *)(*param_1 + 0x8670) = iVar4;
    }
    (*Curl_cfree)();
    param_1[0xfe] = 0;
  }
  freedirs(piVar5);
  (*Curl_cfree)(param_1[0x105]);
  pcVar1 = Curl_cfree;
  param_1[0x105] = 0;
  (*pcVar1)(param_1[0x10e]);
  param_1[0x10e] = 0;
  Curl_pp_disconnect(piVar5);
  return 0;
}


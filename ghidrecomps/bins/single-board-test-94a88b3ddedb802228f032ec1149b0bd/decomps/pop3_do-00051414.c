
int pop3_do(int *param_1,undefined *param_2)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar1 = *param_1;
  *param_2 = 0;
  iVar1 = Curl_urldecode(iVar1,*(undefined4 *)(iVar1 + 0x868c),0,*(int *)(iVar1 + 0x14c) + 4,0,1);
  if (iVar1 == 0) {
    iVar5 = *param_1;
    iVar1 = *(int *)(iVar5 + 0x350);
    if (iVar1 != 0) {
      uVar6 = Curl_urldecode(iVar5,iVar1,0,*(int *)(iVar5 + 0x14c) + 8,0,1);
      iVar1 = (int)((ulonglong)uVar6 >> 0x20);
      if ((int)uVar6 != 0) {
        return (int)uVar6;
      }
      iVar5 = *param_1;
    }
    *(undefined4 *)(iVar5 + 0x50) = 0xffffffff;
    *(undefined4 *)(iVar5 + 0x54) = 0xffffffff;
    Curl_pgrsSetUploadCounter(iVar5,iVar1,0,0);
    Curl_pgrsSetDownloadCounter(iVar5,extraout_r1,0,0);
    Curl_pgrsSetUploadSize(iVar5,extraout_r1_00,0xffffffff,0xffffffff);
    Curl_pgrsSetDownloadSize(iVar5,extraout_r1_01,0xffffffff,0xffffffff);
    iVar1 = *param_1;
    puVar2 = *(undefined4 **)(iVar1 + 0x14c);
    if (*(char *)(iVar1 + 0x307) != '\0') {
      *puVar2 = 1;
    }
    pcVar4 = (char *)puVar2[1];
    *param_2 = 0;
    if ((*pcVar4 == '\0') ||
       ((pcVar3 = DAT_00051534, *(char *)(iVar1 + 0x2fd) != '\0' &&
        (*puVar2 = 1, pcVar3 = DAT_00051528, *pcVar4 == '\0')))) {
      pcVar3 = (char *)puVar2[2];
      pcVar4 = DAT_00051528;
      if ((pcVar3 != (char *)0x0) && (pcVar4 = pcVar3, *pcVar3 == '\0')) {
        pcVar4 = DAT_00051528;
      }
      iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_00051530,pcVar4);
    }
    else {
      pcVar4 = (char *)puVar2[2];
      if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
        pcVar3 = pcVar4;
      }
      iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005152c,pcVar3);
    }
    if (iVar1 == 0) {
      param_1[0xfe] = 9;
      iVar1 = pop3_multi_statemach(param_1,param_2);
      return iVar1;
    }
  }
  return iVar1;
}


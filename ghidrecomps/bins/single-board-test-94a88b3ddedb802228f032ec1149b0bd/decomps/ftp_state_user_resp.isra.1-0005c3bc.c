
int ftp_state_user_resp_isra_1(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 == 0x14b) {
    if (param_1[0x10a] == 3) {
      iVar1 = *(int *)(*(int *)(iVar1 + 0x14c) + 8);
      if (iVar1 == 0) {
        iVar1 = DAT_0005c47c;
      }
      iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005c480,iVar1);
      if (iVar1 != 0) {
        return iVar1;
      }
      param_1[0x10a] = 4;
      return 0;
    }
  }
  else {
    if (param_2 - 200U < 100) {
      iVar1 = ftp_state_loggedin();
      return iVar1;
    }
    if (param_2 == 0x14c) {
      if (*(int *)(iVar1 + 0x360) == 0) {
        Curl_failf(iVar1,DAT_0005c48c,0,iVar1,param_4);
        return 0x43;
      }
      iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005c484);
      if (iVar1 != 0) {
        return iVar1;
      }
      param_1[0x10a] = 5;
      return 0;
    }
  }
  if ((*(int *)(iVar1 + 0x364) == 0) || (*(char *)(iVar1 + 0x8674) != '\0')) {
    Curl_failf(iVar1,DAT_0005c478,param_2,iVar1,param_4);
    iVar1 = 0x43;
  }
  else {
    iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005c488);
    if (iVar1 == 0) {
      *(undefined *)(*param_1 + 0x8674) = 1;
      param_1[0x10a] = 3;
      return 0;
    }
  }
  return iVar1;
}


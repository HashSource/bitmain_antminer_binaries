
int ftp_state_user_resp_isra_1(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (param_2 == 0x14b) {
    if (param_1[0x10a] == 3) {
      puVar1 = *(undefined1 **)(*(int *)(iVar2 + 0x14c) + 8);
      if (puVar1 == (undefined1 *)0x0) {
        puVar1 = &DAT_0013a6fc;
      }
      iVar2 = Curl_pp_sendf(param_1 + 0xf0,"PASS %s",puVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_1[0x10a] = 4;
      return 0;
    }
  }
  else {
    if (param_2 - 200U < 100) {
      iVar2 = ftp_state_loggedin();
      return iVar2;
    }
    if (param_2 == 0x14c) {
      if (*(int *)(iVar2 + 0x360) == 0) {
        Curl_failf(iVar2,"ACCT requested but none available",0,iVar2,param_4);
        return 0x43;
      }
      iVar2 = Curl_pp_sendf(param_1 + 0xf0,"ACCT %s");
      if (iVar2 != 0) {
        return iVar2;
      }
      param_1[0x10a] = 5;
      return 0;
    }
  }
  if ((*(int *)(iVar2 + 0x364) == 0) || (*(char *)(iVar2 + 0x8674) != '\0')) {
    Curl_failf(iVar2,"Access denied: %03d",param_2,iVar2,param_4);
    iVar2 = 0x43;
  }
  else {
    iVar2 = Curl_pp_sendf(param_1 + 0xf0,"%s");
    if (iVar2 == 0) {
      *(undefined1 *)(*param_1 + 0x8674) = 1;
      param_1[0x10a] = 3;
      return 0;
    }
  }
  return iVar2;
}


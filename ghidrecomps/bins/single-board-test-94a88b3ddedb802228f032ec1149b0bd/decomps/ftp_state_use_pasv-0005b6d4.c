
int ftp_state_use_pasv(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)((int)param_1 + 0x1fd) == '\0') {
    if (*(char *)(param_1 + 0x7d) == '\0') {
      iVar2 = 1;
    }
    else {
      *(undefined *)((int)param_1 + 0x1fd) = 1;
      iVar2 = 0;
    }
  }
  else {
    iVar2 = 0;
  }
  iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005b724,DAT_0005b720 + iVar2 * 5);
  if (iVar1 == 0) {
    param_1[0x107] = iVar2;
    param_1[0x10a] = 0x1e;
    Curl_infof(*param_1,DAT_0005b728);
  }
  return iVar1;
}


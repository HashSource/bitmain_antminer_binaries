
void ftp_state_user(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*param_1 + 0x14c) + 4);
  if (iVar1 == 0) {
    iVar1 = DAT_0005b3c0;
  }
  iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005b3c4,iVar1,*(int *)(*param_1 + 0x14c),param_4);
  if (iVar1 == 0) {
    param_1[0x10a] = 3;
    *(undefined *)(*param_1 + 0x8674) = 0;
  }
  return;
}


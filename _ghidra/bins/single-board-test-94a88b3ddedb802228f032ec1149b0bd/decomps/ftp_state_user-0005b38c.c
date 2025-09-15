
void ftp_state_user(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(*(int *)(*param_1 + 0x14c) + 4);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_0013a6fc;
  }
  iVar1 = Curl_pp_sendf(param_1 + 0xf0,"USER %s",puVar2,*(int *)(*param_1 + 0x14c),param_4);
  if (iVar1 == 0) {
    param_1[0x10a] = 3;
    *(undefined1 *)(*param_1 + 0x8674) = 0;
  }
  return;
}



void ftp_state_rest(int *param_1)

{
  int iVar1;
  
  if ((*(int *)(*(int *)(*param_1 + 0x14c) + 0xc) != 0) && (param_1[0x102] != 0)) {
    iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cbd4,0);
    if (iVar1 == 0) {
      param_1[0x10a] = 0x1a;
      return;
    }
    return;
  }
  ftp_state_prepare_transfer(param_1);
  return;
}


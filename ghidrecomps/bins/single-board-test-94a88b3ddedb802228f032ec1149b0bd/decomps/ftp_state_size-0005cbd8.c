
void ftp_state_size(int *param_1)

{
  int iVar1;
  
  if ((*(int *)(*(int *)(*param_1 + 0x14c) + 0xc) == 1) && (param_1[0x102] != 0)) {
    iVar1 = Curl_pp_sendf(param_1 + 0xf0,DAT_0005cc10);
    if (iVar1 == 0) {
      param_1[0x10a] = 0x17;
      return;
    }
    return;
  }
  ftp_state_rest(param_1);
  return;
}


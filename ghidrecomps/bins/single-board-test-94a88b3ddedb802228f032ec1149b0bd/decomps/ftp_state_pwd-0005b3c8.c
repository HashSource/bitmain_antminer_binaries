
void ftp_state_pwd(int param_1)

{
  int iVar1;
  
  iVar1 = Curl_pp_sendf(param_1 + 0x3c0,DAT_0005b3e4,DAT_0005b3e8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x428) = 9;
  }
  return;
}


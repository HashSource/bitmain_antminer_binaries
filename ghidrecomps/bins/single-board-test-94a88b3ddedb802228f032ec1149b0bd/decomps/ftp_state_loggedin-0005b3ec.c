
void ftp_state_loggedin(int param_1)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x178) == '\0') {
    ftp_state_pwd();
    return;
  }
  iVar1 = Curl_pp_sendf(param_1 + 0x3c0,DAT_0005b418,0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x428) = 6;
    return;
  }
  return;
}


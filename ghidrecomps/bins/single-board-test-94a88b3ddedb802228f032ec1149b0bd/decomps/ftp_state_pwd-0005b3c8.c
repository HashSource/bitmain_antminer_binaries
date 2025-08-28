
void ftp_state_pwd(int param_1)

{
  int iVar1;
  
  iVar1 = Curl_pp_sendf(param_1 + 0x3c0,"%s",&DAT_0013c388);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x428) = 9;
  }
  return;
}


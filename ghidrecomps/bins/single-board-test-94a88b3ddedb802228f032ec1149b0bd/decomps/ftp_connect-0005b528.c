
void ftp_connect(int param_1,undefined1 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x218) + 0x40);
  *param_2 = 0;
  *(undefined4 *)(param_1 + 1000) = 1800000;
  *(undefined1 *)(param_1 + 0x1ed) = 0;
  *(undefined4 *)(param_1 + 0x3f0) = 0x5d3ed;
  *(int *)(param_1 + 0x3ec) = param_1;
  *(undefined4 *)(param_1 + 0x3f4) = 0x5c501;
  if ((iVar1 << 0x1f < 0) && (iVar1 = Curl_ssl_connect(param_1,0), iVar1 != 0)) {
    return;
  }
  Curl_pp_init(param_1 + 0x3c0);
  *(undefined4 *)(param_1 + 0x428) = 1;
  ftp_multi_statemach(param_1,param_2);
  return;
}


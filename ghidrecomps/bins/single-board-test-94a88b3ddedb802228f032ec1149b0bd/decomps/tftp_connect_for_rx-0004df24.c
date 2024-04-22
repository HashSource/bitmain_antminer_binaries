
void tftp_connect_for_rx(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  Curl_infof(*(undefined4 *)param_1[4],DAT_0004df54,DAT_0004df50);
  *param_1 = 1;
  iVar1 = tftp_set_timeouts(param_1);
  if (iVar1 != 0) {
    return;
  }
  tftp_rx(param_1,param_2);
  return;
}



void tftp_connect_for_tx(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  Curl_infof(*(undefined4 *)param_1[4],"%s\n","Connected for transmit");
  *param_1 = 2;
  iVar1 = tftp_set_timeouts(param_1);
  if (iVar1 != 0) {
    return;
  }
  tftp_tx(param_1,param_2);
  return;
}


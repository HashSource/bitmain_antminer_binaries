
void ftp_multi_statemach(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  
  Curl_pp_statemach(param_1 + 0x3c0,0,param_3,param_4,param_4);
  cVar1 = '\x01' - (char)*(uint *)(param_1 + 0x428);
  if (1 < *(uint *)(param_1 + 0x428)) {
    cVar1 = '\0';
  }
  *param_2 = cVar1;
  return;
}


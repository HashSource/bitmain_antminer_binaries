
void pop3_perform_auth(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    Curl_pp_sendf(param_1 + 0x3c0,DAT_00051120,param_2);
    return;
  }
  Curl_pp_sendf(param_1 + 0x3c0,DAT_00051124,param_2);
  return;
}


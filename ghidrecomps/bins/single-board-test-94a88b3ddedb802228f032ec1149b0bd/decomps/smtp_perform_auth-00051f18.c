
void smtp_perform_auth(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 != 0) {
    Curl_pp_sendf(param_1 + 0x3c0,DAT_00051f30,param_2);
    return;
  }
  Curl_pp_sendf(param_1 + 0x3c0,DAT_00051f34,param_2);
  return;
}


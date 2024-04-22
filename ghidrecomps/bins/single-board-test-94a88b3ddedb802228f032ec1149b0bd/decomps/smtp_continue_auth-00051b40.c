
void smtp_continue_auth(int param_1,undefined4 param_2)

{
  Curl_pp_sendf(param_1 + 0x3c0,"%s",param_2);
  return;
}


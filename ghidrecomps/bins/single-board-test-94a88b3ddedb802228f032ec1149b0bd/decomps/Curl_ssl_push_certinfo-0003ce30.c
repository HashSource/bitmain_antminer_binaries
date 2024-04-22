
void Curl_ssl_push_certinfo(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  size_t sVar1;
  
  sVar1 = strlen(param_4);
  Curl_ssl_push_certinfo_len(param_1,param_2,param_3,param_4,sVar1);
  return;
}


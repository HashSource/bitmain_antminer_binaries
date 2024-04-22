
void Curl_sasl_create_ntlm_type1_message
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  undefined auStack_418 [1028];
  
  Curl_sasl_ntlm_cleanup(param_3);
  curl_msnprintf(auStack_418,0x400,&DAT_0013a560,0,0,0,0,6,0x82,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                 &DAT_0013a6fc,&DAT_0013a6fc);
  Curl_base64_encode(0,auStack_418,0x20,param_4,param_5);
  return;
}



void Curl_version_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r1;
  
  curl_version();
  curl_version_info(3,extraout_r1,param_3,param_4);
  return;
}


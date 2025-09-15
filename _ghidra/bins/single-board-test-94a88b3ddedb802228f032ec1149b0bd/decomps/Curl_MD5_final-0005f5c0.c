
undefined4 Curl_MD5_final(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(*param_1 + 8))(param_2,param_1[1],param_3,*(code **)(*param_1 + 8),param_4);
  (*Curl_cfree)(param_1[1]);
  (*Curl_cfree)(param_1);
  return 0;
}


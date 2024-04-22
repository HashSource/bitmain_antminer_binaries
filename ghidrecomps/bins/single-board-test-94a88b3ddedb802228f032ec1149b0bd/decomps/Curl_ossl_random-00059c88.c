
undefined4 Curl_ossl_random(int param_1,uchar *param_2,undefined4 param_3)

{
  int num;
  
  if (param_1 != 0) {
    Curl_ossl_seed();
  }
  num = curlx_uztosi(param_3);
  RAND_bytes(param_2,num);
  return 0;
}


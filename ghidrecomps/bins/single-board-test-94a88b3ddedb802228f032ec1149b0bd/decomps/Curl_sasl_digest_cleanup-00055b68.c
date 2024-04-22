
void Curl_sasl_digest_cleanup(undefined4 *param_1)

{
  code *pcVar1;
  
  (*Curl_cfree)(*param_1);
  pcVar1 = Curl_cfree;
  *param_1 = 0;
  (*pcVar1)(param_1[1]);
  pcVar1 = Curl_cfree;
  param_1[1] = 0;
  (*pcVar1)(param_1[2]);
  pcVar1 = Curl_cfree;
  param_1[2] = 0;
  (*pcVar1)(param_1[5]);
  pcVar1 = Curl_cfree;
  param_1[5] = 0;
  (*pcVar1)(param_1[6]);
  pcVar1 = Curl_cfree;
  param_1[6] = 0;
  (*pcVar1)(param_1[7]);
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[3] = 0;
  *(undefined *)(param_1 + 4) = 0;
  return;
}


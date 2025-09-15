
void Curl_sasl_ntlm_cleanup(int param_1)

{
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


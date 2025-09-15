
void Curl_free_request_state(int param_1)

{
  code *pcVar1;
  
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x14c));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0x13c));
  *(undefined4 *)(param_1 + 0x13c) = 0;
  return;
}


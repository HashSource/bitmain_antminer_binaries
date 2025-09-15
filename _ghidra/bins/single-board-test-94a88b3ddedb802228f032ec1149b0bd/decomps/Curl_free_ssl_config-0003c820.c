
void Curl_free_ssl_config(int param_1)

{
  code *pcVar1;
  
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x10));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0x10) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0xc));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0xc) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0x24));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0x24) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0x20));
  pcVar1 = Curl_cfree;
  *(undefined4 *)(param_1 + 0x20) = 0;
  (*pcVar1)(*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


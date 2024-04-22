
void freecookie(int param_1)

{
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x20));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x14));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0xc));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x10));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 4));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 8));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x2c));
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x28));
  (*Curl_cfree)(param_1);
  return;
}


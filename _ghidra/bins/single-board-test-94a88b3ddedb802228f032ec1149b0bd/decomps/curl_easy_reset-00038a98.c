
void curl_easy_reset(int param_1)

{
  (*Curl_cfree)(*(undefined4 *)(param_1 + 0x8688));
  *(undefined4 *)(param_1 + 0x8688) = 0;
  *(undefined4 *)(param_1 + 0x868c) = 0;
  Curl_free_request_state(param_1);
  Curl_freeset(param_1);
  memset((void *)(param_1 + 0x150),0,0x300);
  Curl_init_userdefined((void *)(param_1 + 0x150));
  memset((void *)(param_1 + 0x470),0,0x110);
  *(undefined4 *)(param_1 + 0x4a8) = 0x10;
  *(undefined4 *)(param_1 + 0x85a0) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x85a4) = 0xffffffff;
  return;
}


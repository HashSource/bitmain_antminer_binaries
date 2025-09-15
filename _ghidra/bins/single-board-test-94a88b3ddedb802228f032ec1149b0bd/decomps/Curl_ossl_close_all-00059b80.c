
void Curl_ossl_close_all(int param_1)

{
  if (*(ENGINE **)(param_1 + 0x8648) != (ENGINE *)0x0) {
    ENGINE_finish(*(ENGINE **)(param_1 + 0x8648));
    ENGINE_free(*(ENGINE **)(param_1 + 0x8648));
    *(undefined4 *)(param_1 + 0x8648) = 0;
  }
  return;
}


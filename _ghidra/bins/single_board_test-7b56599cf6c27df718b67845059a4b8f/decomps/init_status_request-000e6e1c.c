
undefined4 init_status_request(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 0x53c) = 0xffffffff;
    return 1;
  }
  CRYPTO_free(*(void **)(param_1 + 0x554));
  *(undefined4 *)(param_1 + 0x554) = 0;
  *(undefined4 *)(param_1 + 0x558) = 0;
  return 1;
}


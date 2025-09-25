
undefined4 init_server_name(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 0x5cc) = 0;
    CRYPTO_free(*(void **)(param_1 + 0x538));
    *(undefined4 *)(param_1 + 0x538) = 0;
  }
  return 1;
}


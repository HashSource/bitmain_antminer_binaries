
undefined4 ssl3_release_read_buffer(int param_1)

{
  CRYPTO_free(*(void **)(param_1 + 0x664));
  *(undefined4 *)(param_1 + 0x664) = 0;
  return 1;
}


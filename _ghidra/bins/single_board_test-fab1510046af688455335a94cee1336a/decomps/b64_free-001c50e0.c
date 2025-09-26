
undefined4 b64_free(int param_1)

{
  if (param_1 != 0) {
    CRYPTO_free(*(void **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
    return 1;
  }
  return 0;
}


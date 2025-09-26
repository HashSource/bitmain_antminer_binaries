
undefined4 init_srp(int param_1)

{
  CRYPTO_free(*(void **)(param_1 + 0x61c));
  *(undefined4 *)(param_1 + 0x61c) = 0;
  return 1;
}


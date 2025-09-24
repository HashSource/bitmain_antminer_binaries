
undefined4 init_ec_point_formats(int param_1)

{
  CRYPTO_free(*(void **)(param_1 + 0x56c));
  *(undefined4 *)(param_1 + 0x56c) = 0;
  *(undefined4 *)(param_1 + 0x568) = 0;
  return 1;
}


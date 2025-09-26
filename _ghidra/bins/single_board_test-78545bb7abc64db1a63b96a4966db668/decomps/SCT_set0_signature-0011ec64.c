
void SCT_set0_signature(int param_1,undefined4 param_2,undefined4 param_3)

{
  CRYPTO_free(*(void **)(param_1 + 0x2c));
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x30) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}


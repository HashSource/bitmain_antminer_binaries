
void SCT_set0_extensions(int param_1,undefined4 param_2,undefined4 param_3)

{
  CRYPTO_free(*(void **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = param_2;
  *(undefined4 *)(param_1 + 0x24) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}



undefined4
RAND_DRBG_set_callbacks
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  if (*(int *)(param_1 + 0x5c) == 0) {
    *(undefined4 *)(param_1 + 0xfc) = param_4;
    *(undefined4 *)(param_1 + 0xf4) = param_2;
    *(undefined4 *)(param_1 + 0xf8) = param_3;
    *(undefined4 *)(param_1 + 0x100) = param_5;
    return 1;
  }
  return 0;
}


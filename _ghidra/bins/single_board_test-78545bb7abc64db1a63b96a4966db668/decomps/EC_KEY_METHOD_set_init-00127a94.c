
void EC_KEY_METHOD_set_init
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_1 + 0x14) = param_5;
  *(undefined4 *)(param_1 + 0x18) = param_6;
  *(undefined4 *)(param_1 + 0x1c) = param_7;
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x10) = param_4;
  return;
}



void SCT_set_timestamp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0x18) = param_3;
  *(undefined4 *)(param_1 + 0x1c) = param_4;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}


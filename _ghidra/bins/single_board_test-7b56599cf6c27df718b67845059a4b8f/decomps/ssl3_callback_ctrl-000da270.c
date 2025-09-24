
undefined4 ssl3_callback_ctrl(int param_1,int param_2,undefined4 param_3,int param_4)

{
  if (param_2 == 0x38) {
    *(undefined4 *)(param_1 + 0x530) = param_3;
  }
  else if (param_2 == 0x4f) {
    *(undefined4 *)(param_1 + 0x64c) = param_3;
  }
  else {
    if (param_2 == 6) {
      param_4 = *(int *)(param_1 + 0x404);
    }
    if (param_2 == 6) {
      *(undefined4 *)(param_4 + 8) = param_3;
    }
  }
  return 0;
}


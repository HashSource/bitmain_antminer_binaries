
undefined4 UI_method_set_data_duplicator(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x18) = param_2;
    *(undefined4 *)(param_1 + 0x1c) = param_3;
    return 0;
  }
  return 0xffffffff;
}


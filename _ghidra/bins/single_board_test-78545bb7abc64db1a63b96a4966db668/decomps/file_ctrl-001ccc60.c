
undefined4 file_ctrl(int param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 1) {
    return 1;
  }
  if (*(int *)*param_3 != 0) {
    if (*(int *)*param_3 != 1) {
      ERR_put_error(0x2c,0x81,7,"crypto/store/loader_file.c",0x3b6);
      return 0;
    }
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 1;
    return 1;
  }
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
  return 1;
}


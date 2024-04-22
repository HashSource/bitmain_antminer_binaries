
undefined4 https_getsock(int param_1,undefined4 *param_2,int param_3)

{
  if ((*(uint *)(*(int *)(param_1 + 0x218) + 0x40) & 1) != 0) {
    if (param_3 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x180) == 3) {
      *param_2 = *(undefined4 *)(param_1 + 0x154);
      return 0x10000;
    }
    if (*(int *)(param_1 + 0x180) == 2) {
      *param_2 = *(undefined4 *)(param_1 + 0x154);
      return 1;
    }
  }
  return 0;
}


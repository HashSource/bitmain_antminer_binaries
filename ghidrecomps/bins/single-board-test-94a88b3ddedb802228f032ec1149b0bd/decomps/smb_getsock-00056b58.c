
undefined4 smb_getsock(int param_1,undefined4 *param_2,int param_3)

{
  if (param_3 == 0) {
    return 0;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x154);
  if ((*(int *)(param_1 + 0x3e4) == 0) && (*(int *)(param_1 + 0x3e0) == 0)) {
    return 1;
  }
  return 0x10000;
}


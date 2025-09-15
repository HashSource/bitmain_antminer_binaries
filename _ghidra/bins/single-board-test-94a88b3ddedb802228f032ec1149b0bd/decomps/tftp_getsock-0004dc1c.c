
undefined4 tftp_getsock(int param_1,undefined4 *param_2,int param_3)

{
  if (param_3 != 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x154);
    return 1;
  }
  return 0;
}


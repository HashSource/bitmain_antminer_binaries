
undefined4 init_srtp(int param_1)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    *(undefined4 *)(param_1 + 0x5e8) = 0;
  }
  return 1;
}


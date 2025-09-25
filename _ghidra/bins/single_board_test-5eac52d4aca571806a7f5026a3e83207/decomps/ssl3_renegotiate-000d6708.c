
undefined4 ssl3_renegotiate(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xf0) = 1;
  }
  return 1;
}


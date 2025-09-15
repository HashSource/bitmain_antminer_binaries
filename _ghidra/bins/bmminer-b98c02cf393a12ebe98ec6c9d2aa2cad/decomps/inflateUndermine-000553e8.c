
undefined4 inflateUndermine(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x1c) != 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x1bc0) = 1;
    return 0xfffffffd;
  }
  return 0xfffffffe;
}


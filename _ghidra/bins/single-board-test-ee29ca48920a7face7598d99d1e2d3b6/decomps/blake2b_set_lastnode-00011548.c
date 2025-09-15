
undefined4 blake2b_set_lastnode(int param_1)

{
  *(undefined4 *)(param_1 + 0x58) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5c) = 0xffffffff;
  return 0;
}


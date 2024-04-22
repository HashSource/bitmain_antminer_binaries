
undefined4 blake2b_set_lastblock(int param_1)

{
  if (*(char *)(param_1 + 0x164) != '\0') {
    blake2b_set_lastnode(param_1);
  }
  *(undefined4 *)(param_1 + 0x50) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  return 0;
}



bool test_nonce(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x4c) = param_2;
  regen_hash();
  return *(int *)(param_1 + 0xdc) == 0;
}



uint DH_test_flags(int param_1,uint param_2)

{
  return *(uint *)(param_1 + 0x1c) & param_2;
}


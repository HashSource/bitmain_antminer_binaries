
uint RSA_test_flags(int param_1,uint param_2)

{
  return *(uint *)(param_1 + 0x40) & param_2;
}


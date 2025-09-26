
void ECDSA_METHOD_set_flags(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x10) = param_2 | 2;
  return;
}


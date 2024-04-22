
void dsa_init(int param_1)

{
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 1;
  return;
}


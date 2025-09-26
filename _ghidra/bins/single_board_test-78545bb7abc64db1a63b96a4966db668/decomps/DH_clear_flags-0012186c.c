
void DH_clear_flags(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) & ~param_2;
  return;
}


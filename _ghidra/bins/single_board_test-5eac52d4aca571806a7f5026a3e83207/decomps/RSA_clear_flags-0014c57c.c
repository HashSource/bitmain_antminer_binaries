
void RSA_clear_flags(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x40) = *(uint *)(param_1 + 0x40) & ~param_2;
  return;
}


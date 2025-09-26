
void SSL_CTX_dane_clear_flags(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0x20c) = *(uint *)(param_1 + 0x20c) & ~param_2;
  return;
}


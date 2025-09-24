
void SSL_dane_set_flags(int param_1,uint param_2)

{
  *(uint *)(param_1 + 0xb4) = param_2 | *(uint *)(param_1 + 0xb4);
  return;
}


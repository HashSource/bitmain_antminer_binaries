
uint SSL_CTX_clear_options(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xac) & ~param_2;
  *(uint *)(param_1 + 0xac) = uVar1;
  return uVar1;
}



uint SSL_clear_options(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x4ec) & ~param_2;
  *(uint *)(param_1 + 0x4ec) = uVar1;
  return uVar1;
}


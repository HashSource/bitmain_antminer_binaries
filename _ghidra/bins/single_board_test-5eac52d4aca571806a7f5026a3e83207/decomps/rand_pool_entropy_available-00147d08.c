
uint rand_pool_entropy_available(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x1c);
  if (uVar1 < *(uint *)(param_1 + 0x20)) {
    uVar1 = 0;
  }
  else if (*(uint *)(param_1 + 4) < *(uint *)(param_1 + 0x10)) {
    uVar1 = 0;
  }
  return uVar1;
}


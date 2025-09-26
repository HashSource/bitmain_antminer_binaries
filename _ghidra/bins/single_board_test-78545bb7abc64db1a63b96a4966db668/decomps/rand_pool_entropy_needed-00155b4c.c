
int rand_pool_entropy_needed(int param_1)

{
  int iVar1;
  
  if (*(uint *)(param_1 + 0x1c) < *(uint *)(param_1 + 0x20)) {
    iVar1 = *(uint *)(param_1 + 0x20) - *(uint *)(param_1 + 0x1c);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}


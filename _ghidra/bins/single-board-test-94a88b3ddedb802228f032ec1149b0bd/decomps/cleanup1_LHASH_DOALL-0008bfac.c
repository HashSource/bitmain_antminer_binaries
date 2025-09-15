
void cleanup1_LHASH_DOALL(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 8) = 0;
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) | 0xd;
  return;
}


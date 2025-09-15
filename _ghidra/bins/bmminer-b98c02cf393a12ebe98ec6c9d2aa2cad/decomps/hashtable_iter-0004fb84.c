
int hashtable_iter(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 == param_1 + 0x14) {
    iVar1 = 0;
  }
  return iVar1;
}


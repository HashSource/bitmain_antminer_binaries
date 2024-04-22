
int hashtable_iter_next(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == param_1 + 0x14) {
    iVar1 = 0;
  }
  return iVar1;
}



int BN_is_negative(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


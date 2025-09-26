
int ec_wNAF_have_precompute_mult(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x60) != 5) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


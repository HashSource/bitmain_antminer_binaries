
int pbe_cmp(undefined4 *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)*param_1 - *(int *)*param_2;
  if (iVar1 == 0) {
    iVar1 = ((int *)*param_1)[1] - ((int *)*param_2)[1];
  }
  return iVar1;
}


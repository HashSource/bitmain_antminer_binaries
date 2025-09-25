
int bn_secure_new(int *param_1)

{
  int iVar1;
  
  iVar1 = BN_secure_new();
  *param_1 = iVar1;
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


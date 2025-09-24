
int X509_get0_reject_objects(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc4);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  return iVar1;
}


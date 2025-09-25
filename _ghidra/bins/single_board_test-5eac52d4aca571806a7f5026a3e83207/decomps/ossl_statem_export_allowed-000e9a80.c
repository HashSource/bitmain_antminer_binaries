
int ossl_statem_export_allowed(int param_1)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0x334) != 0) {
    iVar1 = *(int *)(param_1 + 0x40) + -0x24;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}


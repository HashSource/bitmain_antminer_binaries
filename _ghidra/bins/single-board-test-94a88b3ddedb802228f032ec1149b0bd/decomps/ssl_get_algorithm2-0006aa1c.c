
int ssl_get_algorithm2(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x58) + 0x344) + 0x24);
  if ((*(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x38) << 0x1d < 0) && (iVar1 == 0xc030)) {
    iVar1 = 0x20080;
  }
  return iVar1;
}


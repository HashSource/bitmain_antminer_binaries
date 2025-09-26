
bool dh_missing_parameters(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
    return *(int *)(iVar1 + 0xc) == 0;
  }
  return true;
}


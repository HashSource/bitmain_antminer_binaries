
int dsa_missing_parameters(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if ((*(int *)(iVar2 + 0xc) != 0) && (*(int *)(iVar2 + 0x10) != 0)) {
    iVar1 = 1 - *(uint *)(iVar2 + 0x14);
    if (1 < *(uint *)(iVar2 + 0x14)) {
      iVar1 = 0;
    }
    return iVar1;
  }
  return 1;
}


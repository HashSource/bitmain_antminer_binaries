
int RECORD_LAYER_write_pending(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    iVar1 = *(int *)(param_1 + (*(int *)(param_1 + 0x10) + -1) * 0x14 + 0x38);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 0;
}


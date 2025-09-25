
int RECORD_LAYER_read_pending(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


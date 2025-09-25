
int SSL_SESSION_is_resumable(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x198) != 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x148) == 0) {
    iVar1 = *(int *)(param_1 + 0x1d4);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  return 1;
}


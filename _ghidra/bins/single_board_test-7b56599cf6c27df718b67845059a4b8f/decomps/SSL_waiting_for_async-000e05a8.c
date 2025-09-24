
int SSL_waiting_for_async(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xf44);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


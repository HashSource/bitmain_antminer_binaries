
int SSL_SESSION_has_ticket(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1d4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}


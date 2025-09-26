
int SSL_client_hello_get0_random(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x5c8);
  if (iVar1 != 0) {
    if (param_2 != (int *)0x0) {
      *param_2 = iVar1 + 8;
      return 0x20;
    }
    iVar1 = 0x20;
  }
  return iVar1;
}


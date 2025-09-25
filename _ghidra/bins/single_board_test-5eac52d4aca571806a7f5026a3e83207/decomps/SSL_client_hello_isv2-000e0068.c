
int SSL_client_hello_isv2(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x5c8);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)*piVar1;
  }
  return (int)piVar1;
}


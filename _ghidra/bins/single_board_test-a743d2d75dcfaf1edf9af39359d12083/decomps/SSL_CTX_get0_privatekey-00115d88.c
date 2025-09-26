
int * SSL_CTX_get0_privatekey(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xb0);
  if (piVar1 != (int *)0x0) {
    piVar1 = *(int **)(*piVar1 + 4);
  }
  return piVar1;
}



int ** SSL_CTX_get0_certificate(int param_1)

{
  int **ppiVar1;
  
  ppiVar1 = *(int ***)(param_1 + 0xb0);
  if (ppiVar1 != (int **)0x0) {
    ppiVar1 = (int **)**ppiVar1;
  }
  return ppiVar1;
}


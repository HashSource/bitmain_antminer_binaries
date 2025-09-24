
int X509_get0_trust_objects(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc4);
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)*piVar1;
  }
  return (int)piVar1;
}


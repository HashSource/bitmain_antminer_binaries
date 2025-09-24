
int * OPENSSL_sk_pop(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 != (int *)0x0) {
    if (*param_1 != 0) {
      iVar1 = *param_1 + -1;
      piVar2 = *(int **)(param_1[1] + iVar1 * 4);
      *param_1 = iVar1;
      return piVar2;
    }
    param_1 = (int *)0x0;
  }
  return param_1;
}


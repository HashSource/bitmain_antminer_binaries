
int tls1_clear(int *param_1)

{
  int iVar1;
  
  iVar1 = ssl3_clear();
  if (iVar1 != 0) {
    if (*(int *)param_1[1] == 0x10000) {
      *param_1 = 0x304;
      return 1;
    }
    iVar1 = 1;
    *param_1 = *(int *)param_1[1];
  }
  return iVar1;
}


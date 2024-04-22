
void EC_EX_DATA_clear_free_data(int **param_1,int param_2,int param_3,code *param_4)

{
  int **ppiVar1;
  int **ppiVar2;
  void *pvVar3;
  
  if (param_1 != (int **)0x0) {
    ppiVar2 = (int **)*param_1;
    while (ppiVar1 = ppiVar2, ppiVar1 != (int **)0x0) {
      if (((ppiVar1[2] == (int *)param_2) && (ppiVar1[3] == (int *)param_3)) &&
         (ppiVar1[4] == (int *)param_4)) {
        pvVar3 = *ppiVar1;
        (*param_4)(ppiVar1[1]);
        CRYPTO_free(*param_1);
        *param_1 = (int *)pvVar3;
        return;
      }
      param_1 = ppiVar1;
      ppiVar2 = (int **)*ppiVar1;
    }
  }
  return;
}


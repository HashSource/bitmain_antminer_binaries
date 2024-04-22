
void __left_rotate(int **param_1,int **param_2)

{
  int **ppiVar1;
  
  ppiVar1 = (int **)param_2[1];
  param_2[1] = *ppiVar1;
  if ((int **)*ppiVar1 != param_1 + 1) {
    (*ppiVar1)[2] = (int)param_2;
  }
  if (param_1 + 1 != ppiVar1) {
    ppiVar1[2] = param_2[2];
  }
  if (param_2[2] == (int *)0x0) {
    *param_1 = (int *)ppiVar1;
  }
  else if ((int **)*param_2[2] == param_2) {
    *param_2[2] = (int)ppiVar1;
  }
  else {
    param_2[2][1] = (int)ppiVar1;
  }
  *ppiVar1 = (int *)param_2;
  if (param_1 + 1 != param_2) {
    param_2[2] = (int *)ppiVar1;
  }
  return;
}

